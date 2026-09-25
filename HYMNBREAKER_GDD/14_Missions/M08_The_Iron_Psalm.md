# M08 — THE IRON PSALM

| | |
|---|---|
| **Act** | II — The Tuned Earth |
| **Location** | The plains below the Varn Massif, where the CDF's Third Army was tuned: **the Iron Psalm**, Dorian's war-cathedral grown from the army's wreckage |
| **Kit** | `CHOIR` (martial variant: bone ramparts, spear-forests, skin-banners) heavy + `BRU` military wreckage |
| **Target duration** | 80 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M08_1 → BEAT_M08_5 |
| **New** | Deflector Spin mod, *Reverb* pedal, **Requiem Gate #2**; enemies **Requiem Knight**, **Hymnal**; phalanx formations; **Boss: Dorian, the Martial Psalm** |
| **Landmark** | **The Dorian Spire** — a colossal bone citadel-spire shaped like a sword planted point-down in the plain, with a crown-halo, rising from the center of the Iron Psalm; war-drums audible across the plain |

---

## 1. Overview

A war-cathedral on a battlefield. Two hundred thousand soldiers were sung into statues here; now they drill in perfect lockstep inside Dorian's fortress, a nightmare of discipline. The mission is a siege, and the player is the whole army.

**Experience goals:** scale (fields of gilded soldiers standing in ranks to the horizon), discipline as horror (marching formations, synchronized drums), the first duel with a **Requiem Knight** (parry mastery), and the Dorian boss with its beat-synced shockwaves. The first hint of the Unsung's true identity ("*Shieldwarden*").

---

## 2. Level Flow

```
[A01 The Plain of Ranks] → [A02 Trench Line] ENC_01
   → [A03 The Breach (rampart climb)] ENC_02 (Hymnal intro)
   → [A04 Drill Yard] ENC_03 (phalanx formations)
   → [A05 Armory of Bones] (Deflector Spin; Requiem Gate #2; CM_M08_01, CM_M08_02)
   → [A06 Knight's Court] ENC_04 (Requiem Knight duel)
   → [A07 Rampart Walk] ENC_05
   → [A08 Parade Ground] BOSS: DORIAN → end
```

### A01 — The Plain of Ranks
* The Drop Coffin lands among the **ranks**: thousands of gilded CDF soldiers standing at attention in perfect grids across the plain (instanced statues — non-hostile scenery; they are dead-still, porcelain-crusted, facing the Spire). Wrecked tanks and dropships between them. War drums echo in the distance, in perfect time. The Radio intro (`RAD_M08`) is somber.
* A walk (3 min) through the ranks toward the trench line. The drums sync to the music's tempo — the level's heartbeat.

### A02 — Trench Line, ENC_M08_01
* **Space:** a network of CDF trenches (3 m deep, 3–4 m wide) zig-zagging across 100 × 60 m, with dugouts, wire, sandbags, and wrecked tanks bridging trenches. The trenches are overgrown with bone and filled with standing gilded soldiers — some of whom come alive (Thralls/Troopers `SPN_Emerge` from the ranks).
* Combat is both in the trenches (tight) and on the surface between them (open, exposed to Marksmen on distant rampart towers).

### A03 — The Breach, ENC_M08_02
* **Space:** a gap blown in the 40 m bone ramparts by the Third Army's last push: a slope of rubble and bone, a collapsed CDF siege tower (climbable: Grip Walls on its frame), and a wrecked Anvil Siege Frame half-buried in the breach (a Harrow Anchor on its shoulder).
* **Hymnal intro:** a **Hymnal** floats over the breach birthing Wailers. Prompt: `HYMNALS birth WAILERS — kill the HYMNAL and its children die with it`.

### A04 — Drill Yard, ENC_M08_03
* **Space:** a vast parade yard (90 × 70 m) where formations of Tuned soldiers drill in lockstep to war-drums. Viewing stands on two sides (6 m), a central obelisk-drum (a huge bone drum on a pillar — destructible: destroying it (1500 HP) breaks the formations' synchronization, making them slower and disorganized for the rest of the arena — optional tactic, +Gain).
* **Phalanx behavior:** formations of Bulwarks (front line) + Troopers (behind) advance in lockstep to the drum's beat (they step on every beat; their shields form a wall). The phalanx's flanks are weak; Power Chord breaks the front; Hammerfall over the wall hits the Troopers.

### A05 — Armory of Bones
* **Space:** a "weapon-forest": a field of spears and swords grown from the ground in perfect rows (hazard: walking into a spear-cluster deals 10 dmg/s — don't), leading to an armory hall of bone racks holding Choir-grown weapons (set dressing) and a barracks (optional Choir Mass `CM_M08_02`); a smithy courtyard (optional `CM_M08_01`).
* **Mod Crate: Shredder — Deflector Spin** in the armory hall.
* **Requiem Gate #2** in the armory's crypt.

### A06 — Knight's Court, ENC_M08_04
* **Space:** a circular dueling court (35 m) with a sand floor, a low wall, tiered stands, banners. A **Requiem Knight** stands at its center, sword planted, and turns to face the Unsung as the seals close.
* **Duel:** the Requiem Knight fights **alone** (resource adds: Thralls enter only every 30 s from the stands). Prompts: `REQUIEM KNIGHTS block everything from the front — COUNTER the GOLD strike to break their guard`. Lund: "*It's... it's fighting like a person. Like a soldier.*"

### A07 — Rampart Walk, ENC_M08_05
* **Space:** the top of the inner ramparts (a 15 m wide walkway, 200 m long, 40 m up) with towers every 50 m, organ-pipe "siege horns" (Choir artillery emplacements — scenery that fires at distant targets), and bridges to the Spire's base. The arena is a 60 m section between two towers plus the towers' tops.
* Canons on the next tower shell the walkway; the player must push forward through them.

### A08 — Parade Ground: BOSS DORIAN
* `10_Bosses.md` §3. `CIN_M08_Dorian` ("*Shieldwarden. I sealed you in the dark once...*"). Phase 2's Martial Hymn syncs to the war-drums heard throughout the mission.
* After the Boss Breakdown, the drums stop — for the first time in the mission, silence falls across the plain. Then, one by one, the standing soldiers of the Third Army crumble to dust. (Not saved — too long tuned. A sad image.) The second Aureole band dies.

---

## 3. Encounters

```
ENC_M08_01  "Trench Line"          Arena: A02 (100 x 60 m trench network)   Seals: bone walls at trench exits
  Music: MUS_M08_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Emerge from ranks), Trooper x4 (trench firing steps)
  W2 AliveBelow(4):       Marksman x2 (rampart towers, 60 m away), Bulwark x2, Thrall x6
  W3 AliveBelow(4):       Crescendo x2 (surface, charging across trenches), Chorister x3
  Final W4 AliveBelow(3): Bellwether x1, Trooper x4, Thrall x8
  Pickups: Health S x8, Plating M x1, Shells L x1, Rounds L x1, Harrow Spool x2
```

```
ENC_M08_02  "The Breach"           Arena: A03 (rubble slope 60 x 50 m, siege tower 20 m, rampart lip 40 m)   Seals: 2
  Music: MUS_M08_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Hymnal x1, Thrall x8                                               [Hymnal intro]
  W2 KilledTag(Hymnal) OR AliveBelow(3): Seraph x2, Trooper x4
  W3 AliveBelow(4):       Hymnal x1, Cantor x1, Bulwark x2, Chorister x2
  Final W4 AliveBelow(3): Canon x1, Ophan x1, Thrall x8
  Pickups: Health M x1, Health S x4, Plating S x4, Ordnance L x1, Charge S x2
```

```
ENC_M08_03  "Drill Yard"           Arena: A04 (90 x 70 m; stands 6 m; central drum obelisk)   Seals: 4
  Music: MUS_M08_Combat_B (tempo-locked to the drum)   Reward: 2 Brass + loot fountain
  W1 OnStart:             Phalanx A: Bulwark x4 + Trooper x6 (advancing in lockstep), Thrall x6
  W2 AliveBelow(6):       Phalanx B: Bulwark x3 + Trooper x4, Marksman x2 (stands)
  W3 AliveBelow(5):       Bellwether x1, Crescendo x1, Chorister x3
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Phalanx C: Bulwark x4 + Trooper x4, Canon x1, Cantor x1
  Pickups: Health M x2, Plating M x2, Shells L x1, Rounds L x2, Ordnance L x1, Harrow Spool x3
  Power-up: AMP (on the viewing stand, west)
  Notes: destroying the drum obelisk (1500 HP) desynchronizes phalanxes: they break formation and act as normal soldiers with −20% attack speed.
```

```
ENC_M08_04  "Knight's Court"       Arena: A06 (35 m circle + stands)   Seals: 2
  Music: MUS_M08_Duel               Reward: 1 Brass + loot fountain
  W1 OnStart:             Requiem Knight x1                                                  [Requiem Knight intro — alone]
  Trickle: Thrall x3 every 30 s (from the stands) — resource adds only
  Pickups: Health S x6 (around the wall), Plating S x4
```

```
ENC_M08_05  "Rampart Walk"         Arena: A07 (60 x 15 m walkway section, 2 towers 10 m tall, bridges)   Seals: 2
  Music: MUS_M08_Combat_C           Reward: 1 Brass + loot fountain
  W1 OnStart:             Canon x2 (next tower top), Trooper x6, Thrall x6
  W2 AliveBelow(5):       Seraph x2, Hymnal x1, Chorister x2
  W3 AliveBelow(4):       Requiem Knight x1, Bulwark x3, Thrall x6
  Final W4 AliveBelow(3): Bellwether x2, Ophan x1, Chorister x3, Thrall x6
  Pickups: Health M x2, Plating M x1, Ordnance L x1, Rounds L x1, Charge L x1, Harrow Spool x2
  Notes: the rampart edge is a 40 m void (knockback kills allowed).
```

**Boss:** `BOSS_Dorian` (`10_Bosses.md` §3).
**Optional:** `CM_M08_01` (smithy courtyard), `CM_M08_02` (barracks). **Requiem Gate #2** (`RQG_02`, "**The March Eternal**") in the armory crypt.

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M08_Ranks` | Walking through the ranks of gilded soldiers; war drums in tempo |
| `EVT_M08_Phalanx` | Phalanx formations stepping on the beat |
| `EVT_M08_DrumObelisk` | Destroying the drum desynchronizes the army |
| `EVT_M08_Knight` | The Requiem Knight turns and draws its sword as the seals close |
| `EVT_M08_Dorian` | `CIN_M08_Dorian` |
| `EVT_M08_Silence` | After Dorian: the drums stop; the Third Army crumbles to dust |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #2** | A02: in a collapsed dugout — the only one without a gilded soldier standing guard — Downbeat through its roof from the surface | A dugout roof with orange fissures and a faint bell sound |
| S2 | **Heart Shard #6** | A03: the wrecked Anvil's cockpit (Harrow Anchor on its shoulder, then Grip Wall up its chest) | Violet glow in the cockpit |
| S3 | **Tab #3: "Confetti"** (enemies burst into confetti and party horns instead of gore) | A04: inside the central drum obelisk after it's destroyed | Violet glow within the drum |
| S4 | **Pedal: Reverb** | A05: the smithy's forge (after `CM_M08_01`) | — |
| S5 | **Effigy: Requiem Knight** | A06: on the highest banner pole above the court's stands (Harrow Anchor after the duel) | — |
| S6 | **Effigy: Hymnal** | A07: tower 3 interior, a sealed room (breakable bone wall) | Violet cracks |
| S7 | **Master: *"Two Hundred Thousand"* by THIRD ARMY** | A01: in a wrecked CDF command tank (the tank's radio still playing) | Music from the tank |
| S8 | **Reprise** | A07: under the bridge to the Spire — drop onto a buttress | Violet glow below the bridge |
| S9 | **Rig Core** | A05: in the weapon-forest, on a pedestal surrounded by spear-clusters — Kick Pad hidden in the smithy wall launches you onto it | Pedestal glowing violet |
| S10 | **Brass Cache #1** | A02: trench dugout | — |
| S11 | **Brass Cache #2** | A04: under the west viewing stand | — |
| S12 | **Sounding Station #1** | A02: CDF command dugout | — |
| S13 | **Sounding Station #2** | A05: armory hall office | — |
| S14–S18 | **Archive Stones** | A01, A02, A04, A06, A08 | — |

**Archive entries:** `ARC_Loc_IronPsalm`, `ARC_Hist_ThirdArmy`, `ARC_Enemy_RequiemKnight`, `ARC_Enemy_Hymnal`, `ARC_Archon_Dorian`, `ARC_Obj_Shieldwarden` (Lund's first note: "a title in the Vault's glyphs"), `ARC_Opt_RequiemGate2`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Break a phalanx's shield wall with a single Power Chord (2+ Bulwark shields broken) |
| 2 | Defeat the Requiem Knight in the Knight's Court using only Counters to open its guard (no damage to it while its guard is up) |
| 3 | During Dorian's Phalanx phase, jump over 10 Martial Hymn rings in a row without being hit |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M08_Explore` — "**The Ranks**" | Plain, walkways | Military snare + funeral drums locked to 120 BPM; distant male choir; the drums continue diegetically |
| `MUS_M08_Combat_A` — "**No Man's Land**" | ENC_01–02 | 160 BPM, war-metal |
| `MUS_M08_Combat_B` — "**Lockstep**" | ENC_03 | 120 BPM half-time heavy; the phalanx steps on beats |
| `MUS_M08_Duel` — "**Guard Break**" | ENC_04 | Tense; the gold strike tell is harmonized with the music's accents |
| `MUS_M08_Combat_C` — "**Ramparts**" | ENC_05 | 175 BPM |
| `MUS_BOSS_Dorian` — "**The Martial Psalm**" | Boss | See boss doc |
| After Dorian | — | 8 s of silence broken only by wind and crumbling porcelain |

---

## 8. Art & Lighting

* **Palette:** overcast steel-grey sky, bone-white ramparts, black-and-gold war-banners (skin), olive-drab CDF wreckage, gilded soldiers; the Dorian Spire lit from within in steel-white.
* **Key props:** gilded soldier statues (instanced, 10 poses, 20,000+ instances with HLOD/impostors), trench kit, bone rampart kit (walls, towers, bridges, breach rubble), spear-forest clusters, bone weapon racks, war drum obelisk, dueling court, siege horns, wrecked CDF vehicles (tanks, APCs, dropships, an Anvil).

---

## 9. New Assets Required (P1)

`SK_RequiemKnight`, `SK_Hymnal`, `BOSS_Dorian` (`SK_Dorian`, Psalm Blade (split-able), Aegis shield), gilded soldier statue set, martial CHOIR kit, trench kit, `BP_DrumObelisk` (destructible), phalanx formation controller (`BP_PhalanxController`, beat-synced via Quartz), spear-forest hazard volume.
