# M02 — SELENE RELAY

| | |
|---|---|
| **Act** | I — First Noise |
| **Location** | Lunar surface, rim of Sabine crater: the Consonance's **Selene Relay** complex |
| **Kit** | `BRU` (Consonance-era white variant) + `ORB` (surface domes, landing pads) + `CHOIR` 20% → 60% |
| **Target duration** | 65 min |
| **Priority** | **P0 — Vertical Slice** |
| **Story beats** | BEAT_M02_1 → BEAT_M02_6 |
| **New** | Static Rifle, Frag Charge, Distort, Counter (gold notes), Frag Slug mod, Kick Pads, Bulwark, Vesper, Cantor; **Hub unlocked after completion** |
| **Landmark** | The **Selene Relay tower** — a 600 m white spire with ring-antennae, pulsing white-gold with the Hymn, visible from everywhere on the surface; Earth + Aureole in the black sky |

---

## 1. Overview

The player steps onto the lunar surface. Big sky, black space, Earth wearing its halo. The Relay tower dominates the horizon and *sings*. The mission's objective is simple and visible: destroy the Relay's **three resonator cores** so the Quietus can land.

**Experience goals:** the first big exterior spaces; the first taste of the full resource triangle (Distort arrives); the first gold note and first successful Counter; meeting Vire; ending with the Quietus's silent landing and the hub.

**Low gravity? No.** The Relay complex has **artificial gravity plating** (Concord tech) — gameplay gravity is normal everywhere. Outside the plated zones (only cosmetic vistas) dust drifts slowly for flavor. The Unsung doesn't need air; human survivors wear suits.

---

## 2. Level Flow

```
[A01 Lift Head / Dome Exit] → [A02 Regolith Trench] → [A03 Crash Site (Static dropship)] ENC_01
        → [A04 Habitat Ring] ENC_02 (Distort)
        → [A05 Core Alpha — Mass Driver Yard] ENC_03  → CORE 1
        → [A06 Landing Pads] (Kick Pad traversal) → [A07 Core Beta — Antenna Farm] ENC_04 → CORE 2 (+Aurelia hologram)
        → [A08 Tower Base Plaza] ENC_05 (Cantor)  → [A09 Relay Ascent (exterior climb)]
        → [A10 Core Gamma — Crown Chamber] ENC_06 FINALE → CORE 3 → [A11 Crater Rim — Quietus lands] CIN
```

### A01 — Lift Head & Dome Exit
* Continuation from M01's dome. An airlock cycles (the Unsung doesn't care; the doors blow outward in a dust burst when the Unsung punches the manual release).
* **Radio:** Lund patches in **Vire** (`COM_M02_01`): "*Lund says you're some kind of ancient weapon. I say prove it. There are three resonator cores on that tower complex. Break them, and my ship can land without everyone aboard forgetting their own names.*"

### A02 — Regolith Trench
* A cut trench (12 m wide, 8 m deep) leading toward the complex, lined with Concord cargo containers and toppled survey drones. First exterior vista at the trench's end: the tower and Earth. Light combat: 4 Thralls in EVA suits (Tuned lunar workers — suit visors cracked open, porcelain faces inside).

### A03 — Crash Site, ENC_M02_01
* A crashed **Static dropship** (hull broken in two) on a slope. The strike team sent to destroy the Relay was tuned: they are now **Tuned Troopers** and the first **Bulwarks** (riot-shield troopers) wearing the Static Mark on their armor. **Private Juno Reyes** is hiding in the cockpit (voice on comms: "*Hello? Is someone— oh God, it's a— are you the thing from the Vault?*").
* The **Static Rifle** is on the dropship's weapon rack (`PKP_Weapon_StaticRifle`). Prompt: `STATIC RIFLE — ENERGY weapons melt SHIELDS`.
* After the encounter, Juno joins Lund on comms and relays the Static's plan.

### A04 — Habitat Ring, ENC_M02_02
* A ring of 6 inflatable-dome habitats linked by pressurized tubes (each dome 20 m across). Rig boot: **DISTORT** (`RIG SUBSYSTEM RESTORED: DISTORT`) → prompt `[C] DISTORT — Distorted enemies shed PLATING when damaged`. A tutorial pocket (3 Thralls) in the first dome, then the arena spans three connected domes (a circuit).
* **Mod Crate: Breacher — Frag Slug** sits in the medical dome.

### A05 — Core Alpha: Mass Driver Yard, ENC_M02_03
* The complex's mass driver (a 300 m electromagnetic launch rail aiming at the sky) has had its capacitor bank converted into **Core Alpha**: a sphere of bone and gold wedged into the capacitor housing, singing. Destroying it: interact to rip it out (after the arena) — the **core-rip animation** (the Unsung reaches into the singing sphere and tears out its heart-bell; 3 s).
* **Rig boot: FRAG CHARGE** before the arena (found as a CDF munitions locker: Wren's modified charges).
* **First Vespers** (swarm) here, emerging from the mass driver's rail vents.

### A06 — Landing Pads (traversal)
* Four landing pads (60 m apart) on elevated pylons over a 30 m drop into a crater. **Kick Pads** (Static-installed, taped-together speaker cones) launch the player between pads. First Kick Pad: prompt `KICK PADS launch you — keep moving`. A Harrow Anchor chain along a fuel gantry offers an alternate route (and a secret).

### A07 — Core Beta: Antenna Farm, ENC_M02_04
* A field of 40 dish antennae (5–15 m tall), some turned into Choir "ears" of bone. Core Beta sits in the central control bunker.
* **Gold notes introduced:** Choristers here charge **Resonant Notes**. Lund notices the first gold note: "*Those golden ones... they're resonant! If you strike them at the right moment you could send them back!*" → prompt `[F] COUNTER — Strike GOLD attacks just before impact to reflect them`. The arena opens with a single Chorister on a dish throwing a gold note at the player (tutorial beat; slow note on first throw — 1200 cm/s).
* After Core Beta: `CIN_M02_Hologram` (in-play): Aurelia's hologram flickers up from the bunker projector, 4 m tall, and addresses the Unsung. The Unsung can punch the projector mid-sentence (it cuts out: "*You poor thing. How long have you been al—*").

### A08 — Tower Base Plaza, ENC_M02_05
* A monumental plaza at the tower's foot: white stone, reflecting pools frozen solid, Consonance statues of Aurelia with arms raised. The **first Cantor** appears here, linking Bulwarks.
* Lund: "*That tall one is — conducting them. It's making them stronger. Break its lantern, or its link.*"

### A09 — Relay Ascent
* The tower exterior: a spiral maintenance gantry winding up 200 m (the Relay's lower third), interspersed with Grip Walls, Harrow Anchors on the ring-antennae and Kick Pads. Light combat on landings (Vespers, Choristers). **Earth vista** from every turn; the Hymn is deafening (the music includes more choir).
* The higher you climb, the more the `CHOIR` overlay grows (40% → 60%).

### A10 — Core Gamma: Crown Chamber, ENC_M02_06 (FINALE)
* A circular chamber at the 200 m mark inside the tower: ring-antennae visible through a glass floor, the core suspended in the center (a 4 m sphere of bone, gold and light, held by four "strings" of light to the walls). Two levels: the floor ring and a raised inner ring (4 m) around the core.
* After the arena, the core-rip; the tower begins to collapse. **Escape (60 s):** a short scripted run — the chamber tilts; jump out onto the ring-antenna; Harrow down a series of anchors to the base as the tower slowly topples behind you (non-lethal, cinematic, player-controlled).

### A11 — Crater Rim
* `CIN_M02_Quietus` → mission complete → **Hub unlocked**.

---

## 3. Encounters

```
ENC_M02_01  "Crash Site"          Arena: A03 slope around the dropship (35 x 30 m, 2 levels)   Seals: rock-and-bone growths
  Music: MUS_M02_Combat_A                    Reward: 1 Brass + loot fountain
  W1 OnStart:             Trooper x4 (crash debris hold points), Thrall x4 (EVA)
  W2 AliveBelow(3):       Bulwark x2 (Drop from the dropship's upper hull), Thrall x4
  Final W3 AliveBelow(2): Trooper x3, Bulwark x1, Thrall x4
  Pickups: Charge L x1 (for the new Static Rifle), Health S x4, Plating S x2
  Notes: Bulwark tutorial prompt: "Shields melt under ENERGY weapons — or flank them."
```

```
ENC_M02_02  "Habitat Ring"        Arena: A04 domes 2-4 + tubes (3 x 20 m domes, circuit)   Seals: 2
  Music: MUS_M02_Combat_A                    Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x6, Trooper x2
  W2 AliveBelow(3):       Chorister x2 (Hymnfall through dome skylights), Thrall x4
  Final W3 AliveBelow(3): Bulwark x2, Trooper x2, Chorister x1, Thrall x4
  Pickups: Health S x4, Shells S x2, Charge S x2
  Notes: Designed for Distort practice: fodder arrive in clumps of 3-4.
```

```
ENC_M02_03  "Mass Driver Yard"    Arena: A05 (50 x 30 m along the rail, rail 6 m up, capacitor towers)   Seals: 2
  Music: MUS_M02_Combat_B                    Reward: 1 Brass + loot fountain
  W1 OnStart:             Vesper x5 (Emerge from rail vents), Thrall x6
  W2 AliveBelow(4):       Chorister x2, Trooper x3 (rail top)
  W3 AliveBelow(3):       Vesper x5, Bulwark x2
  Final W4 AliveBelow(3): Chorister x3, Thrall x6, Trooper x2
  Pickups: Health M x1 (rail top), Plating M x1, Shells L x1, Charge L x1, Harrow Spool x2
```

```
ENC_M02_04  "Antenna Farm"        Arena: A07 (60 x 50 m dish field; dishes as cover and perches)   Seals: 3
  Music: MUS_M02_Combat_B                    Reward: 1 Brass + loot fountain
  W0 OnStart (tutorial):  Chorister x1 on a dish, throws one slow gold note
  W1 AliveBelow(0):       Chorister x3 (gold notes enabled), Thrall x6
  W2 AliveBelow(4):       Vesper x6, Trooper x2
  Final W3 AliveBelow(3): Chorister x3, Bulwark x2, Thrall x4
  Pickups: Health S x6, Plating M x1 (on a tall dish rim), Charge S x2, Rounds S x2
  Notes: Chorister gold note cooldown reduced to 4.0 s in this arena to give Counter practice.
```

```
ENC_M02_05  "Tower Base Plaza"    Arena: A08 (45 x 45 m, statues, frozen pools, a 5 m terrace)   Seals: 3
  Music: MUS_M02_Combat_C                    Reward: 1 Brass + loot fountain
  W1 OnStart:             Cantor x1 (terrace), Bulwark x2 (linked), Thrall x6
  W2 KilledTag(Cantor):   Trooper x4, Chorister x2
  Final W3 AliveBelow(3): Cantor x1 (Hymnfall), Bulwark x2, Chorister x2, Thrall x6
  Pickups: Health M x1 (statue plinth), Health S x4, Plating S x4, Charge L x1
```

```
ENC_M02_06  "Crown Chamber" (FINALE)  Arena: A10 (circular, 40 m diameter; raised inner ring 4 m)   Seals: 2
  Music: MUS_M02_Combat_C (finale arrangement)    Reward: 2 Brass + big loot fountain
  W1 OnStart:             Chorister x4, Thrall x8
  W2 AliveBelow(4):       Cantor x1, Bulwark x2, Trooper x3
  W2b TimeElapsed(20s):   Thrall x4                                  [resource trickle]
  W3 AliveBelow(4):       Vesper x8, Chorister x2
  Final W4 AliveBelow(3): Cantor x1, Chorister x4, Bulwark x2, Thrall x8
  Pickups: Health M x2, Plating M x2, Charge L x1, Shells L x1, Harrow Spool x2
  Power-up: none
```

---

## 4. Set Pieces & Scripted Events

| ID | Where | Description |
|---|---|---|
| `EVT_M02_Juno` | A03 | Juno Reyes found alive in the cockpit; she stays hidden (evacuated by the Quietus at the end) |
| `EVT_M02_CoreRip` ×3 | A05, A07, A10 | Core-rip animation; the tower's song loses a layer (music: the choir stem drops one voice each time); the Aureole flickers briefly |
| `EVT_M02_Hologram` | A07 | `CIN_M02_Hologram` — punchable projector |
| `EVT_M02_TowerFall` | A10 → A11 | Tower collapse escape (60 s player-controlled Harrow descent) |
| `EVT_M02_Quietus` | A11 | `CIN_M02_Quietus` |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Mute Cell #1** | A02: inside a half-buried cargo container at the trench's end — Downbeat not yet unlocked, so: shoot the container's jammed lock (Riveter) | Violet light through the container door gap |
| S2 | **Effigy: Tuned Trooper** | A03: on the dropship's broken tail fin (Harrow Anchor on the fin's tip) | Visible glint from the slope |
| S3 | **Heart Shard #1** | A06: under Landing Pad 3 — drop from the pad's edge onto a maintenance platform; a short Grip Wall back up | Violet glow under the pad visible while Kick-Padding over it |
| S4 | **Brass Cache #1** | A04: medical dome's supply closet (breakable plastic wall) | Violet tag "??" on the wall |
| S5 | **Master: *"Low Orbit Lullaby"* by THE PERIGEE** | A07: a dish antenna whose bowl you can land in via Kick Pad from the bunker roof | Music audibly playing from the dish (a radio) |
| S6 | **Reprise** | A08: behind the tallest Aurelia statue, a hidden stair into the plinth (Distort the statue — its porcelain crust shatters revealing a door; teaches "Distort breaks Choir crust") | Crust glowing faintly violet |
| S7 | **Rig Core** | A09: halfway up the ascent, an off-path Harrow Anchor chain leading to a ring-antenna service pod | Violet light in the pod window |
| S8 | **Brass Cache #2** | A09: top of a Grip Wall that the main path skips | Orange trim + violet glow |
| S9 | **Sounding Station** | A06: fuel gantry control booth (alternate Harrow route) | Beeping |
| S10–S13 | **Archive Stones** | A03, A05, A08, A10 | — |

**Archive entries:** `ARC_Loc_SeleneRelay`, `ARC_Fac_Consonance`, `ARC_Char_Aurelia`, `ARC_Fac_Static`, `ARC_Char_Vire`, `ARC_Enemy_Bulwark`, `ARC_Enemy_Vesper`, `ARC_Enemy_Cantor`, `ARC_Weapon_StaticRifle`, `ARC_Rig_Distort`, `ARC_Rig_FragCharge`, `ARC_Mech_Counter`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Counter 10 gold notes |
| 2 | Break a Bulwark's shield with the Static Rifle, then Breakdown it within 3 seconds, 3 times |
| 3 | Kill a Cantor within 10 seconds of it linking an enemy |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M02_Explore` — "**Sea of Tranquility**" | Surface traversal | Vast, spacious; slow doom-metal chords with long reverb; the Relay's choir as a pad |
| `MUS_M02_Combat_A` — "**Crash and Burn**" | ENC_01–02 | 150 BPM |
| `MUS_M02_Combat_B` — "**Resonator**" | ENC_03–04 | 165 BPM; choir counter-melody |
| `MUS_M02_Combat_C` — "**Crown of the Moon**" | ENC_05–06 | Finale |
| Relay "choir stem" | All | A global layer that loses a voice as each core is ripped |
| Ambience | Surface | No wind (vacuum): the soundscape is the Unsung's own body (breath, servos) + the Hymn (which carries through matter, not air — Lund explains) |

---

## 8. Art & Lighting

* **Palette:** black sky, blinding white sun, grey regolith, Consonance white-and-gold architecture, Static orange; Earth blue-white with the gold Aureole.
* **Lighting:** hard directional sunlight with deep black shadows (no atmosphere) — arenas are placed so the sun is side-lit (never directly behind enemies from the player's view); fill light from Earth-shine and Choir glow for readability.
* **Key props:** Static dropship (crashed), inflatable habitat domes, mass driver rail, dish antennae (normal + bone-ear variants), Consonance statues of Aurelia, the Relay tower (modular exterior: gantry, ring-antennae), resonator cores ×3 (variants of one asset).

---

## 9. New Assets Required (P0)

`SK_TrooperBulwark`, `SK_Vesper`, `SK_Cantor`, `SK_WPN_StaticRifle`, `SM_FragCharge`, `SM_Dropship_Static` (+crashed), habitat dome kit, mass driver kit, dish antenna (+Choir ear variant), Relay tower exterior modular kit, `BP_ResonatorCore` (3 variants), `BP_KickPad`, `SM_AureliaStatue`, `BP_Hologram_Aurelia` (hologram material + `SK_Aurelia`), Thrall EVA-suit variant, lunar terrain material set, Quietus exterior (`SM_Quietus_Exterior` — LOD-heavy hero asset for the cinematic), Juno (`SK_Juno`, EVA suit).
