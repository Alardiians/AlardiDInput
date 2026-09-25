# 09c — Bestiary, Part 3: Tier 3 (Super-Heavy), Gilded Variants, Hazards & Titans

All Tier 3 enemies: Falter at 12% HP (2.5 s); cannot be Shredded (Reel-In stops at 350 cm); Breakdown drops 60 Health; kill = +15 Gain; each has a unique **Guard Break** state (1.0–2.0 s, +50% damage taken) triggered by its specific weakness. Arenas with T3 enemies must be ≥ 30 × 30 m with ≥ 6 m clear ceiling.

---

## 1. PROFUNDO — `ENM_Profundo`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M12 |
| **Role** | Super-heavy melee juggernaut; area control through sub-bass |
| **Size** | 450 cm; capsule r 160 / hh 225 |
| **HP** | 4500 · **Chest cavity** (only open during Roar wind-up): ×3 |
| **Speed** | Walk 250 · Run 500 · Leap 1200 |
| **Skeleton** | `SKC_Brute` (large) |

**Visual design:** A hulking giant with a tiny head sunk between massive shoulders, knuckle-walking on gorilla-like arms. Its chest is a huge vertical **resonating cavity** — ribs like the slats of a speaker cabinet — that opens like a pair of doors to reveal a deep, glowing, pulsing throat-organ. Porcelain skin thick as plate armor, veined with dark gold. Its halo is a heavy ring that sits on its shoulders like a yoke. Every step shakes the camera.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Sub-bass Stomp** | 30 (ground wave, height 60) | radius 800 | 0.8 s: rears up, sub-bass swell (felt in rumble) | 6.0 | Jump it |
| **Profundo Roar** | 40 + **Slowed** (−50% move, 3 s) | cone 60°, 1500 | **1.2 s**: chest doors open, glowing cavity, deep inhale | 10.0 | **Weak window:** chest ×3; a Frag/Power Chord into the chest during wind-up = interrupt + **Guard Break** 2 s |
| **Gold Hammerfist** | 50 | 400 | 0.7 s: both fists raised overhead, gold flash + chime | 9.0 | **Parryable** → Guard Break 1.5 s |
| Grab & Throw | 60 **Piercing** | 250 | 0.5 s: lunging grab (dash out) | 12.0 | If caught: thrown 1500 cm |
| Slab Toss | 50 (r 300) | 1000–3500 | 0.9 s: tears a chunk of floor | 8.0 | Only on `BreakableGround` surfaces or when out of reach |

**Answers:** Keep mid-range, jump stomps, punish the Roar wind-up (Frag into chest, Gravedigger, Lance), Counter the Hammerfist; Shredder DPS during Guard Break.

**Breakdowns:** `Front_ChestRip` (climb, pull the cavity doors apart and tear out the organ), `Back_SpineCrack`, `Air_CrownSmash`.

### Variant — Gilded Profundo (`ENM_ProfundoGilded`) — §5.

---

## 2. CARILLON — `ENM_Carillon`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M15 |
| **Role** | Walking bell-tower titan; ranged barrage and summoner; "arena boss" enemy |
| **Size** | 650 cm; capsule r 220 / hh 325 |
| **HP** | 8000 · **4 Bells** (in its tower-torso), 500 HP each, ×2 |
| **Speed** | Walk 180 |
| **Skeleton** | `SKC_Titan` |

**Visual design:** A colossal, slow, walking **bell tower**: its torso is a gothic-brutalist tower of porcelain and bone with four open arched "windows", each housing a great bronze bell. Two enormous pillar-legs; two long arms of fused organ pipes ending in claws. At the tower's crown, a **"window-eye"** — a round rose-window of stained porcelain that glows and fires the Chime Laser. A great halo of multiple rings spins above the crown. Ropes of sinew hang from the bells.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Bell Barrage** | Per intact bell: 4 homing bell-shells × 25 (r 200) | 5000 | Bells ring **in sequence** (one tone per bell), 1.2 s total | 7.0 | Shells shootable (15 HP) |
| **Chime Laser** | 50 dps, 2.5 s sweep | 4000 | 1.0 s: rose-window glows, rising chord; floor line preview | 12.0 | Horizontal sweep at 80 cm height — jump over or dash through the gap it leaves |
| Stomp Quake | 40 (r 600) | — | 0.8 s | 6.0 | — |
| **Peal** (summon) | Spawns 2 T1 per intact bell (Hymnfall) | — | All bells ring together (2.0 s) — very loud | 30.0 | Max summons alive: 8 |

**Weak points:** Each destroyed bell removes its barrage volley and summons; **all 4 destroyed → Enraged**: +30% speed, Chime Laser fires twice in a cross pattern, and it Falters once immediately.

**Answers:** Lance/Riveter on bells (the most satisfying "shoot the weak points off" enemy), Lock Salvo, Silencer.

**Breakdowns:** `Front_Toppling` (Harrow-climb the tower, rip the crown bell loose, ride it down), `Leg_Fell` (sever the leg, it collapses, stomp the rose-window).

---

## 3. MAESTRO — `ENM_Maestro`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M14 (Maestro Primus as mini-boss; standard Maestros from M16) |
| **Role** | Commander/summoner/reviver — **kill it first** |
| **Size** | 380 cm; capsule r 70 / hh 190 |
| **HP** | 2500 · **The Score** (floating book at its side) 400 HP: destroyed → cannot summon or revive |
| **Speed** | Glide 350 (floats 30 cm above ground) · Teleport 2500 |
| **Skeleton** | `SKC_Humanoid` (tall, elegant) |

**Visual design:** An elegant, very tall, slender figure in a flowing tailcoat-like robe of **sheet-music skin** that billows unnaturally; porcelain face with an expression of rapture, eyes closed; long-fingered hands, one holding a **bone baton** that trails gold light. A floating open book — **the Score** — hovers at its left, pages turning by themselves. A wide, elaborate halo of many rings like a conductor's podium of light.

**Abilities**
| Ability | Effect | Telegraph | Cooldown | Notes |
|---|---|---|---|---|
| **Conduct** | Hymnfall-summons a squad: 3–5 T1 or 1 T2 | Baton "tap-tap" + upward sweep; Score pages flip | 20 s | Summons follow encounter budget limits |
| **Accelerando** | All enemies within 2500 gain **Anthem** (10 s) | Baton flourish, tempo of the music visibly quickens (enemy anim rate +) | 25 s | — |
| **Resurrection Crescendo** | Revives up to 3 dead T1/T2 (within 12 s of their death) as **Echoed** | **2.0 s** cast, baton raised high, a swelling choir | 30 s | **Interrupt:** deal ≥ 300 damage during the cast, or Hush it |
| Note Cascade | 12 gold rings fall in a 1000 radius (15 each, parryable) | 0.8 s: gold marks on the floor | 10 s | — |
| Baton Lash | 30, arc 300 | 0.5 s | 3 s | — |
| Teleport | Blinks away when it has taken 600 damage in 3 s | 0.3 s shimmer | 8 s | — |

**Answers:** Lance/Riveter the Score; focus fire; Hush the cast; Axe (late).

**Breakdowns:** `Front_BatonThroat` (take its baton and ram it into its throat), `Score_Slam` (slam the Score shut on its head).

---

## 4. REQUIEM KNIGHT — `ENM_RequiemKnight`

| | |
|---|---|
| **Faction** | The Host (Dorian's elite) |
| **First appears** | M08 |
| **Role** | Duelist; teaches parry mastery; "mini-boss" encounter anchor |
| **Size** | 300 cm; capsule r 80 / hh 150 |
| **HP** | 3500 |
| **Speed** | Walk 300 · Run 550 · Dash-step 600 |
| **Skeleton** | `SKC_Humanoid` (armored knight) |

**Visual design:** A towering knight in **black lacquered armor inlaid with gold** staff-lines, its helm shaped like a closed bell with a vertical slit; a tattered white tabard. Wields a **greatsword** whose blade is a long tuning fork (two parallel blades that hum) and a tall **tower shield** of porcelain faces behind a gold ring. Halo: a thin crown-ring hovering above the helm.

**Shield:** The shield blocks **100%** of frontal (150°) damage and bounces the Harrow. The knight turns at 150°/s. **Power Chord** on the shield → knocks it aside: Guard Break 1.5 s.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Requiem Combo** | 3 hits: 25 / 25 / **35** | 400 | Hits 1–2: 0.4 s; **hit 3 flashes gold** + chime | 3.0 | **Counter hit 3** → Guard Break **2.0 s** |
| **Lunge Thrust** | 40 | 900 | 0.6 s: gold flash, crouch | 6.0 | Parryable → Guard Break 2.0 s |
| Requiem Wave | 30 (vertical cyan blade projectile) | 3000 | 0.7 s: sword raised overhead, shield lowered | 5.0 | Unparryable — dodge sideways; **the shield is down during the wind-up** (shoot it) |
| Shield Bash | 15 + knockback 800 | 250 | 0.3 s | 4.0 | Used when the player hugs it |
| **Dirge Stance** | — | — | At ≤ 50% HP: sword glows | — | Combos become 4 hits (4th gold); +20% attack speed |

**Answers:** Counter the gold strikes; punish Guard Breaks with Gravedigger/Shredder/Lance; shoot during Requiem Wave wind-ups; flank with dashes (it's slower to turn than the player can dash).

**Breakdowns:** `Front_Unhelm` (tear the bell-helm off and ring it on its skull), `Sword_Turn` (turn its own sword on it).

---

## 5. GILDED VARIANTS

Late-game armored versions. **Gilded plates** are separate HP pools covering most of the body (weak points remain exposed). While any plate remains: **immune to Falter**, **Harrow bounces**. Plates take: Kinetic ×1, Explosive ×1.5, **Energy ×2**, **Hot Rivets ×3**, **Power Chord: breaks every plate within its cone instantly**. Visual: thick burnished gold armor plates bolted onto the porcelain with bone rivets; plates crack, glow and fall off (physics debris) when broken.

| ID | Base | Plates | First appears | Extra behavior |
|---|---|---|---|---|
| `ENM_BellwetherGilded` | Bellwether | 1200 (4 plates × 300) | M15 | Toll Slam emits **3** rings |
| `ENM_CrescendoGilded` | Crescendo | 1000 (back plates cover the bellows until broken) | M17 | Charge max speed 1900 |
| `ENM_ProfundoGilded` | Profundo | 2000 (5 plates × 400) | M20 | Roar also pulls the player 300 cm toward it |
| `ENM_CanonGilded` | Canon | 1400 (bell-mouths plated) | M22 | Echo shells echo **twice** |

---

## 6. HAZARDS & STRUCTURES

### 6.1 Hymn Pylon — `HAZ_HymnPylon`
* **Visual:** A 5 m spire of white bone and porcelain with a slowly rotating gold ring-cage at the top around a glowing **core crystal**; hums a chord; its light pulses in time with the music.
* **Effect:** All enemies within 1500 cm gain **Anthem** (+30% move, +25% attack speed, +20% damage), shown by gold beams to each buffed enemy.
* **Destruction:** Invulnerable except the **core** (exposed for 3 s every 8 s when the cage opens — telegraphed by a rising chord), which takes Explosive ×1 and anything else ×0.5; core HP 400. **Power Chord** or Power Downbeat destroys it instantly at any time.
* **Reward:** +5 Gain; buffed enemies are stunned 0.5 s.

### 6.2 Choir Mass — `HAZ_ChoirMass`
* **Visual:** A wall-sized, organic mass of fused, singing Tuned bodies (6–8 m wide), faces and arms protruding, a pulsing gold **heart** at its center, halo-ringed.
* **Function:** **Optional encounter trigger** (the Gore-Nest equivalent). The player punches the heart (interact on melee) → a scripted optional encounter starts (see `16_Optional_Content_and_Modes.md`). Completing it destroys the Mass and rewards Brass + a resource bundle.
* Some Masses (marked `Active`) passively spawn 1 Thrall every 10 s (max 4) until destroyed by 1500 damage.

### 6.3 Chime Turret — `HAZ_ChimeTurret`
* **Visual:** A stationary bone pillar topped with a rotating bell that fires notes.
* **Attack:** Cyan note bursts (4 × 8, 2500 range, 0.6 s telegraph: bell swings back); every 3rd burst is a **gold** note (parryable — Counter destroys the turret).
* **HP:** 400 (the bell; ×2 from behind).

### 6.4 Resonance Mine — `HAZ_ResonanceMine`
* **Visual:** A fist-sized porcelain bulb on the floor with a gold filament, humming faintly.
* **Trigger:** Player within 250 cm → 0.6 s chime → burst 40 dmg (r 350). Shootable (1 HP). Enemies don't trigger them.

### 6.5 Hymn Saturation — `HAZ_HymnSaturation`
* **Visual:** Bright white-gold luminous mist/volumetric fog in Choir-heavy zones (Acts V–VI), with drifting ring particles.
* **Effect:** 5 dmg/s (Plating first); enemies inside gain +10% damage. A Hush Charge clears a 500-radius bubble for 6 s; the Silencer clears the zone for 20 s. Rig *Hazard Plating* halves the damage.

---

## 7. TITANS (Mech-Scale Enemies — Anvil Siege Frame segments)

Mech segments use their own scale. All titans are designed against the **Anvil Siege Frame** (see `07_Equipment_and_Abilities.md` addendum in `10_Bosses.md` §Mech and `14_Missions/M11`). They never appear in on-foot combat except as distant set-dressing (M10 foreshadowing).

| ID | Name | Size | HP (vs. Anvil) | Attacks | Weak point | Appears |
|---|---|---|---|---|---|---|
| `TTN_OrganWalker` | **Organ Walker** | 25 m tall, six legs | 12000 | Pipe Salvo (homing mortar bursts), Sweeping Staccato beam, Leg Stomp | Belly-organ (exposed when it rears up for the Stomp) | M11, M23, M26 |
| `TTN_ChoirColossus` | **Choir Colossus** | 30 m humanoid of fused bodies | 20000 | Colossal Slam (shockwave), Hymn Breath (beam), Grab (QTE-free: Anvil must punch free — mash melee), Throw debris | Glowing throat-core in the chest | M23, M26 |
| `TTN_VesperCloud` | **Vesper Cloud** | A swarm of 200+ Vespers acting as one entity | 6000 (swarm "mass") | Engulf (DoT), Stinger Rain | None — Anvil flamethrower-noise "Blast Horn" deals ×3 | M11, M23 |
| `TTN_Seraphim` | **Seraphim Gunship** | 15 m flying Seraph | 8000 | Chime-missile barrages, strafing beam | Wing-pipes ×4 | M26 |

**Anvil Siege Frame (player mech) quick reference** (full spec in `10_Bosses.md` §10):
* 9 m bipedal mech; first-person cockpit; speed 1200 cm/s (world-scale relative), dash 2 charges.
* Weapons: **Rotary Autocannon** (right arm, sustained), **Rocket Pods** (shoulders, lock-on), **Blast Horn** (left arm: a massive speaker-cannon that fires a cone of noise — the mech's "Distort"), **Pile Driver** melee (right arm, executes staggered titans → repairs the mech).
* Health: 5000 structure; repairs via Pile Driver executions and repair crates dropped by Static dropships.

---

## 8. MASTER ENEMY TABLE (all tiers)

| ID | Tier | HP | Size (cm) | Speed | First | Acts present |
|---|---|---|---|---|---|---|
| ENM_Thrall | T1 | 60 | 180 | 320 | M01 | I–VI |
| ENM_ThrallBloated | T1 | 90 | 190 | 300 | M05 | II–VI |
| ENM_Trooper | T1 | 90 | 185 | 450 | M01 | I–V |
| ENM_TrooperBulwark | T1 | 110+300 | 195 | 400 | M02 | I–V |
| ENM_TrooperMarksman | T1 | 80 | 185 | 450 | M06 | II–V |
| ENM_Chorister | T1 | 140 | 200 | 500 | M01 | I–VI |
| ENM_Vesper | T1 | 50 | 90 | 700 | M02 | I–VI |
| ENM_Wailer | T1 | 30 | 60 | 900 | M03 | I–VI |
| ENM_Acolyte | T1 | 100 | 180 | 500 | M07 | II, IV, V |
| ENM_Zealot | T1 | 120 | 180 | 700 | M07 | II, IV, V |
| ENM_Crescendo | T2 | 1000 | 300 | 1600 | M03 | I–VI |
| ENM_Bellwether | T2 | 1500 | 350 | 550 | M06 | II–VI |
| ENM_Seraph | T2 | 800 | 300 | 400 | M04 | I–VI |
| ENM_Ophan | T2 | 1300 | 300 | 350 | M03 | I–VI |
| ENM_Canon | T2 | 1800 | 400 | 200 | M04 | I–VI |
| ENM_OrganGrinder | T2 | 1100 | 250 | 550 | M05 | II–IV, VI |
| ENM_Cantor | T2 | 600 | 280 | 250 | M02 | I–VI |
| ENM_Siren | T2 | 800 | 250 | 600 | M07 | II–VI |
| ENM_Fugue | T2 | 650 | 220 | 600 | M09 | II–VI |
| ENM_Hymnal | T2 | 900 | 250 | 250 | M08 | II–VI |
| ENM_Echo | T2* | — | 180 | 400 | M09 | II–VI |
| ENM_Profundo | T3 | 4500 | 450 | 500 | M12 | III–VI |
| ENM_Carillon | T3 | 8000 | 650 | 180 | M15 | IV–VI |
| ENM_Maestro | T3 | 2500 | 380 | 350 | M14/M16 | III–VI |
| ENM_RequiemKnight | T3 | 3500 | 300 | 550 | M08 | II–VI |
| ENM_BellwetherGilded | T2+ | 1500+1200 | 350 | 550 | M15 | IV–VI |
| ENM_CrescendoGilded | T2+ | 1000+1000 | 300 | 1900 | M17 | IV–VI |
| ENM_ProfundoGilded | T3+ | 4500+2000 | 450 | 500 | M20 | V–VI |
| ENM_CanonGilded | T2+ | 1800+1400 | 400 | 200 | M22 | V–VI |
