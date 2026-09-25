# 11 — AI & Encounter Design

## 1. AI Architecture

| Layer | Implementation | Notes |
|---|---|---|
| Controller | `AHBAIController` (C++) | Owns Perception, Blackboard, runs the BT from the enemy's DataAsset |
| Decision | **Behavior Trees** (`BT_<Family>`) + Blackboards (`BB_Enemy`) | One BT per behavior family, parameterized by `DA_Enemy_*` |
| Queries | **EQS** (`EQS_*`) | Positioning, flanking, perch selection, retreat |
| Perception | `UAIPerceptionComponent`: Sight, Hearing, Damage | Choir enemies "hear" gunfire at 2500 cm |
| Navigation | NavMesh with **3 agent sizes** + NavLinks + custom flight | See §6 |
| Combat coordination | `UHBCombatDirector` (World Subsystem) | Attack tokens, aggression, spawning budget |
| Encounters | `AHBEncounterArena` + `UHBEncounterData` | Waves, seals, triggers, rewards |
| Abilities/attacks | `UHBAttackComponent` + `UHBAttackData` rows | Telegraph, damage window, hitboxes/projectiles, cooldowns |

### 1.1 Behavior Families (Behavior Trees)

| BT | Used by | Core loop |
|---|---|---|
| `BT_MeleeSwarm` | Thrall, Bloated Thrall, Zealot | Pursue → request Melee token → attack → reposition slightly |
| `BT_RangedSoldier` | Trooper, Bulwark, Marksman, Acolyte | Pick hold point (EQS) → request Ranged token → fire → relocate after N attacks or when threatened |
| `BT_Agile` | Chorister, Fugue | Perch-hop → attack → dodge → perch-hop (never idle > 3 s) |
| `BT_Flyer` | Vesper, Wailer, Ophan, Hymnal | Boids/orbit steering → attack runs |
| `BT_Charger` | Crescendo | Line up → charge → recover |
| `BT_Brute` | Bellwether, Profundo, Canon, Organ Grinder | Advance → choose attack by range → recover |
| `BT_Support` | Cantor, Maestro | Keep distance → cast support abilities by priority → blink away when threatened |
| `BT_Duelist` | Requiem Knight, Siren | Circle → combo → guard |
| `BT_Titan` | Carillon | Slow advance → barrage/laser/peal by timers |
| `BT_Possessor` | Echo | Seek host → possess → on release seek again |
| Boss BTs | `BT_Boss_<Name>` | Phase-driven (see `10_Bosses.md`) |

### 1.2 Blackboard Keys (`BB_Enemy`)
`TargetActor`, `TargetLocation`, `HasLOS` (bool), `DistanceToTarget` (float), `CurrentHoldPoint`, `CurrentPerch`, `HasMeleeToken`, `HasRangedToken`, `HasHeavyToken`, `IsFaltering`, `IsHushed`, `IsStunned`, `IsLinked`, `IsAnthem`, `IsEchoed`, `AttackCooldownReady` (per attack via component), `AggressionLevel` (0–1), `LastDamageTime`, `SpawnState`, `ChargeDirection` (Crescendo), `PossessTarget` (Echo), `SquadID`.

### 1.3 Perception Defaults
| Sense | T1 | T2 | T3 |
|---|---|---|---|
| Sight radius / lose | 3000 / 3500 | 4000 / 4500 | 5000 / 6000 |
| FOV | 120° | 140° | 160° |
| Hearing | 2000 | 2500 | 3000 |
| Alert propagation | Alerted enemies alert others within 1500 cm (with an audible call) | same | same |

In combat arenas, all spawned enemies start **already alerted** to the player (no stealth game). Perception matters for pre-placed enemies in exploration spaces (ambush setups, patrols).

---

## 2. Attack Tokens (the anti-cheap-shot system)

`UHBCombatDirector` holds token pools per player. An enemy must hold the right token to execute an attack. Tokens return on attack completion (or on death/stagger/Hush). This keeps fights readable: the player is never shot by 12 things at once.

| Pool | Lullaby | Unplugged | Amplified | Overdriven | Deafening / Unsung |
|---|---|---|---|---|---|
| **Melee** (simultaneous melee attackers) | 1 | 2 | 3 | 3 | 4 |
| **Ranged** (simultaneous ranged attacks in flight/wind-up) | 2 | 3 | 4 | 5 | 6 |
| **Heavy** (T2/T3 major attacks) | 1 | 1 | 2 | 2 | 3 |
| **Sniper** (Marksman aims) | 1 | 1 | 2 | 2 | 2 |
| **Kamikaze** (Wailer charges, Bloated swells, Zealot martyrs) | 1 | 2 | 2 | 3 | 3 |

**Token priority score** (highest gets the next free token):
```
score = 2.0 * visibleToPlayerCamera   // enemies on screen attack first (fairness)
      + 1.5 * (1 - distance/4000)
      + 1.0 * timeSinceLastAttack/10
      + 0.5 * tierWeight(T1=0, T2=0.5, T3=1)
      - 1.0 * isBehindPlayer           // off-screen enemies wait unless score is high
```
**Off-screen attack rule:** an enemy outside the player's view cone (±70°) may only attack if it has waited ≥ 3 s with a token request, **and** its attack plays a directional audio tell + a HUD off-screen indicator (orange chevron at the screen edge).

**Aggression timer:** if the player hasn't taken damage for 8 s, `AggressionLevel` rises (+0.1/s to 1.0), shortening enemy decision delays by up to 40% — prevents fights from feeling toothless for strong players. Resets on taking damage.

---

## 3. Positioning & Movement Rules

* **Engagement bands:** Close 0–400, Mid 600–1800, Long 1800–4000. Each archetype has a preferred band in its DataAsset (`PreferredRangeMin/Max`).
* **Hold Points** (`BP_AIHoldPoint`): designer-placed tactical spots with tags (`High`, `Flank`, `Sniper`, `Cover`). Ranged soldiers use EQS `EQS_PickHoldPoint` scoring: LOS to player (+), distance in preferred band (+), not occupied (+), not within 500 of another soldier (+), elevation (+ for Marksman).
* **Perches** (`BP_Perch`): for agile enemies (Choristers, Fugues): points on walls, ledges, pillars, ceilings with an attach orientation. Agile AI moves perch-to-perch via **leaps** (arc projectile motion, 0.4–0.8 s) and short wall-crawl splines (`BP_PerchPath`). Designers place **8–16 perches per arena**.
* **Anti-bunching:** separation steering (radius 150 for T1, 300 for T2) plus EQS penalties for positions near allies.
* **Flanking:** 20% of ranged soldiers (flag `CanFlank`) choose hold points ≥ 60° from the player's facing when available.
* **Retreat:** ranged units retreat when the player is within 500 and they don't hold a melee token.
* **Leashing:** arena enemies are confined to their arena volume (`NavigationQueryFilter` with area costs).

---

## 4. Spawning

### 4.1 Spawn Methods

| Method | ID | Visual/Audio | Use |
|---|---|---|---|
| **Hymnfall** | `SPN_Hymnfall` | Pillar of white-gold light (1.2 s), choral swell rising to a chord, enemy descends and lands in a crouch | Default for Host enemies |
| Emerge | `SPN_Emerge` | Choir growth (organ-pipe cluster or flesh wall) splits; Thrall/Chorister claws out (1.0 s) | Tuned & agile enemies |
| Drop | `SPN_Drop` | Falls from a ledge/vent/ceiling hole, heavy landing | Troopers, Thralls, Crescendos |
| Wall Burst | `SPN_WallBurst` | Breakable wall section explodes outward (debris) | Surprise heavies |
| **Resonance Gate** | `SPN_Gate` | A 6 m vertical ring of light opens with a deep bell; heavy steps through (2.0 s) | T3 & special entrances |
| Crowd Rise | `SPN_CrowdRise` | Scripted: passive Tuned civilians turn hostile | M04, M19 |
| Dropship | `SPN_Dropship` | Consonance dropship deploys Acolytes via ropes | Cult missions |

### 4.2 Spawn Rules
1. Never spawn within **800 cm** of the player.
2. Never complete a spawn **behind** the player (outside ±90°) within **1500 cm** unless the spawn method has an audio tell ≥ 1.0 s (Hymnfall, Gate).
3. Heavies (T2/T3) spawn via Hymnfall/Gate/Wall Burst **only** — always announced.
4. A spawn point is invalid if occupied, if navmesh at the landing point is missing, or if it's inside a Hush field.
5. Spawn points (`BP_SpawnPoint`) have: allowed tiers, allowed methods, facing, `WaveTags`.
6. Stagger spawns within a wave by 0.15–0.35 s each so they read as a surge, not a pop.

---

## 5. The Encounter Director

### 5.1 Arena Definition (`AHBEncounterArena`)
* **Volume:** the playable combat space (defines leashing and "player is in the arena").
* **Seals:** `BP_ChoirSeal` actors on every exit (a membrane of bone lattice and gold light that grows across the doorway in 1.0 s with a slam-chord; dissolves into gold dust on completion). Seals close when the encounter starts.
* **Trigger:** `ArenaStartTrigger` volume, or an interaction (Choir Mass heart), or a script event.
* **Data:** `UHBEncounterData` (DataAsset) — waves, spawn assignments, music cues, rewards, difficulty overrides.
* **Rewards:** on completion — Brass (if flagged), a guaranteed resource burst (Health/Plating/ammo "loot fountain" at the arena center), checkpoint, music outro stinger, seals dissolve.

### 5.2 Wave Triggers
| Trigger | Parameter | Example |
|---|---|---|
| `OnStart` | — | Wave 1 |
| `AliveBelow` | N (after difficulty scaling) | "Spawn W2 when ≤ 3 alive" |
| `ThreatBelow` | threat points | "Spawn W3 when threat ≤ 6" |
| `TimeElapsed` | seconds since previous wave | Pressure waves |
| `KilledTag` | enemy tag | "When the Cantor dies" |
| `PlayerInVolume` | sub-volume | Multi-stage arenas |
| `PercentKilled` | % of previous wave | "When 70% of W2 dead" |

Waves may combine triggers (`AND`/`OR`). A wave can be **Final** (encounter completes when all Final-wave enemies and remaining enemies die).

### 5.3 Threat Points
Each enemy has a **threat** value used for budgets and pacing:

| Enemy | Threat | Enemy | Threat |
|---|---|---|---|
| Thrall | 1 | Crescendo | 6 |
| Bloated Thrall | 1.5 | Bellwether | 7 |
| Trooper | 1.5 | Seraph | 6 |
| Bulwark | 2 | Ophan | 6 |
| Marksman | 2 | Canon | 8 |
| Chorister | 2 | Organ Grinder | 7 |
| Vesper | 1 | Cantor | 5 |
| Wailer | 0.5 | Siren | 6 |
| Acolyte | 1.5 | Fugue | 5 |
| Zealot | 2 | Hymnal | 6 |
| Echo | 4 | Profundo | 15 |
| Maestro | 14 | Carillon | 20 |
| Requiem Knight | 14 | Gilded variants | base ×1.5 |

**Max simultaneous threat alive (Amplified)** — the Director blocks new spawns above this cap (they queue):
| Act | I | II | III | IV | V | VI |
|---|---|---|---|---|---|---|
| Threat cap | 14 | 18 | 22 | 26 | 30 | 34 |
| Max alive enemies (performance cap) | 16 | 18 | 20 | 22 | 24 | 26 |

### 5.4 Encounter Design Rules
1. **Resources in the room:** every wave containing T2/T3 enemies includes **≥ 3 T1** (or T1 reinforcements trickle in via a `TimeElapsed` sub-wave) — the player must always be able to Shred and Breakdown.
2. **The answer is in the room:** if a wave requires a specific answer (Ophan → Frag; Echo → Hush), the player has had that tool for ≥ 1 mission, or the arena provides it (pickups).
3. **Introduction rule:** a new enemy type's first appearance is alone or with T1 support only, in a readable space, preceded by an environmental "foreshadow" (a corpse, a sound, a glimpse). Its second appearance combines it with known enemies. Its third appearance tests it under pressure.
4. **Variety rule:** after Act I, no arena uses fewer than 3 distinct enemy types; no two consecutive arenas share the same heavy composition.
5. **Verticality rule:** every arena has ≥ 2 elevation levels (≥ 250 cm difference) and ≥ 1 Harrow Anchor or Kick Pad.
6. **Escape valves:** every arena has ≥ 2 circulation loops (the player can run a circuit without dead ends).
7. **Pickup placement:** health/plating/ammo pickups sit in exposed positions or on the far side of the arena from the start point; power-ups visible from the entrance.
8. **Length:** 2–5 waves; 2.5–4.5 min target (Amplified).
9. **Final arena of each mission** is the "chorus" — the biggest, most varied fight, often with a power-up.

### 5.5 Encounter Data Format (authoring template)
Each mission document specifies encounters in this format; builders transcribe them into `DA_ENC_Mxx_nn` assets.

```
ENC_M04_05  "Upper Concourse"
  Arena: A_M04_Concourse (40 x 30 m, 3 levels)       Seals: 3
  Music: MUS_M04_Combat_B                              Reward: 1 Brass + loot fountain
  W1 OnStart:               Thrall x8 (Emerge: SP_01-04), Chorister x2 (Hymnfall: SP_10,11)
  W2 AliveBelow(4):         Seraph x1 (Hymnfall: SP_20), Trooper x4 (Drop: SP_05-08)
  W3 AliveBelow(3):         Canon x1 (Gate: SP_30), Thrall x6 (Emerge), Chorister x2
  W3b TimeElapsed(25s, W3): Thrall x4 (Emerge)       [resource trickle]
  Final W4 AliveBelow(2):   Crescendo x1 (Hymnfall: SP_21), Chorister x3
  Pickups: Health M x2 (upper walkway), Plating M x1 (pit), Ordnance L x1, Harrow Spool x2
  Power-up: none
  Notes: Canon arrives on the opposite balcony; Kick Pads let the player reach it.
```

### 5.6 Difficulty Scaling of Encounters
Applied automatically by the Director (designers author Amplified only):

| Parameter | Lullaby | Unplugged | Amplified | Overdriven | Deafening | Unsung |
|---|---|---|---|---|---|---|
| T1 count multiplier | 0.6 | 0.8 | 1.0 | 1.15 | 1.3 | 1.3 |
| T2/T3 count multiplier | 0.7 | 0.85 | 1.0 | 1.0 | 1.0 | 1.0 |
| **Elite substitution** (chance a T1 slot upgrades to a stronger T1, a T2 slot to its Gilded/Anthem variant) | 0 | 0 | 0 | 10% | 20% | 20% |
| Threat cap multiplier | 0.6 | 0.8 | 1.0 | 1.15 | 1.3 | 1.3 |
| `AliveBelow` thresholds | +2 | +1 | 0 | 0 | −1 | −1 |
| Enemy decision delay | ×1.5 | ×1.25 | ×1.0 | ×0.9 | ×0.8 | ×0.8 |

(Rounding: counts round to nearest, minimum 1 for any authored slot.)

---

## 6. Navigation

| Agent | Radius | Height | Used by |
|---|---|---|---|
| `Nav_Small` | 45 | 200 | All T1, Cantor, Fugue, Siren (head), Maestro (r 70 → uses Medium) |
| `Nav_Medium` | 120 | 350 | Crescendo, Bellwether, Canon, Organ Grinder, Seraph (ground), Maestro, Requiem Knight |
| `Nav_Large` | 220 | 650 | Profundo, Carillon, bosses |

* **NavLinks** (`BP_NavLink_Leap`): jump-down and leap-up links for Thralls/Choristers/Troopers; T2 brutes only use **drop-downs** ≤ 400 cm and ramps.
* **Flyers** do not use NavMesh: `UHBFlightComponent` with steering behaviors (seek, orbit, separation, obstacle avoidance using 5 short sphere-traces per tick at 10 Hz), constrained to the arena's `FlightVolume`.
* **Agile climbers** use Perches + PerchPaths (see §3).
* **Stuck recovery:** if an enemy hasn't made nav progress for 8 s while not attacking and not visible to the player, it "re-Hymnfalls" at a valid spawn point. If it falls out of the world, it's killed silently (no reward) and the Director re-spawns its threat budget.

---

## 7. Special Behaviors

* **Friendly fire:** enemy Explosive attacks (Canon echoes, Bloated bursts, Crescendo trample, Wailer bursts) damage other enemies. No infighting retargeting (enemies never switch to attacking each other).
* **Faltering enemies** never hold tokens; they release them immediately.
* **Hushed enemies** freeze mid-animation (anim rate 0, physics frozen); resume on release.
* **Distorted enemies** play a jittery additive animation; T1 briefly flinch.
* **Echoed** enemies spawn an `Echo attack` actor: a translucent copy of every attack 0.5 s later from the same origin and aim.
* **Anthem** buff raises animation play rate by 25%.
* **Morale (cultists only):** see Acolyte entry.
* **Last Enemies highlight:** when ≤ 3 enemies remain in an arena and ≥ 20 s have passed without a kill, remaining enemies get a subtle orange outline and a compass ping (option: On/Off).

### 7.1 Allied NPCs (`NPC_StaticSoldier`, named allies)
* **Invulnerable** during scripted ally encounters (they duck behind their barricade when "hit", with a flinch bark). Named allies (Okafor, Vire in M23) are always invulnerable.
* Stay within an **Ally Zone** volume (barricades, hold points); never block the player's path (soft collision, they step aside).
* Deal **25%** of a Trooper's damage per shot; never damage Faltering enemies (so they never steal Breakdowns); never trigger Gain for the player.
* Occupy **no attack tokens** (enemy tokens are about fairness to the player).
* Bark constantly (see `03b` §5.1) — they are there for *mood and scale*, not DPS.
* Enemies target allies only when the player is > 3000 cm away or out of sight for > 5 s (keeps pressure on the player).

### 7.2 Passive Crowds (`NPC_TunedCivilian`)
* Instanced, vertex-animated, non-damageable scenery (no collision with projectiles; soft capsule collision with the player).
* Scripted transformations only (e.g., `SPN_CrowdRise` in M19) — never random.

---

## 8. Debug & Tooling (required for AI builders)

| Console command | Effect |
|---|---|
| `hb.God 0/1` | Player invulnerable |
| `hb.InfiniteAmmo 0/1` | — |
| `hb.GiveAll` | All weapons, mods, abilities |
| `hb.Enc.Start <ID>` / `hb.Enc.Skip` / `hb.Enc.Restart` | Encounter control |
| `hb.Enc.ShowSpawns 0/1` | Draw spawn points, hold points, perches, nav links |
| `hb.AI.ShowTokens 0/1` | Token holders labelled above enemies |
| `hb.AI.Freeze 0/1` | All AI paused |
| `hb.Spawn <EnemyID> [count]` | Spawn at crosshair |
| `hb.Mission <ID> [checkpoint]` | Load mission at checkpoint |
| `hb.Difficulty <0-5>` | Change difficulty live |
| `hb.Telemetry.Dump` | Write arena stats (time, deaths, damage, resource sources) to `Saved/Telemetry/*.csv` |

**Automated encounter test (per arena):** a bot player (`BP_TestBot`, god mode, auto-aim, cycles weapons) must be able to clear every encounter in < 10 minutes without soft-locks — run nightly (see `24_AI_Build_Roadmap.md`).
