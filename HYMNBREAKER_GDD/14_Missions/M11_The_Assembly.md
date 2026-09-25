# M11 — THE ASSEMBLY

| | |
|---|---|
| **Act** | III — Iron and Fire |
| **Location** | **The Assembly** — the Mixolydian Spire: a machine-cathedral at the heart of the Forge-Belt, and its outer yards |
| **Kit** | `IND` + `CHOIR` (machine-cathedral: 80–100%) |
| **Target duration** | 85 min (incl. ~12 min mech segment) |
| **Priority** | P1 |
| **Story beats** | BEAT_M11_1 → BEAT_M11_4 |
| **New** | **Anvil Siege Frame** (first mech segment), *Compressor* pedal, **Requiem Gate #3**, Pedal slot 3 (after mission); titans **Organ Walker**, **Vesper Cloud**; **Boss: Mixolydian, the Engine Hymn** (on foot + mech) |
| **Landmark** | The Assembly itself — a mountain of brass pipes, furnaces and bone buttresses, 1.5 km tall, with a crown of smokestacks that exhale gold smoke on every beat |

---

## 1. Overview

The first mech mission. The player climbs into Wren's restored **Anvil Siege Frame** and wades through the Assembly's outer yards, trading blows with 25-meter Organ Walkers. Then, on foot, into the singing machine-cathedral to face Mixolydian in its engine heart — and finally back into the Anvil for a titanic duel with the Archon's assembled colossus.

**Experience goals:** scale shift (mech vs. titans), mechanical spectacle, a boss that changes scale mid-fight, Wren's emotional investment in "her" Anvil.

---

## 2. Level Flow

```
[A01 Depot] CIN_M11_Anvil → [A02 Outer Yards — MECH] MECH_01..03
   → [A03 The Gate (disembark)] → [A04 Pipe-Organ Nave] ENC_01
   → [A05 Foundry of Voices] ENC_02 (Requiem Gate #3; Compressor)   (+CM_M11_01)
   → [A06 The Crankshaft (vertical traversal)] ENC_03 (mid-climb arena)
   → [A07 Engine Hall] BOSS PHASE A (on foot)
   → [A08 Assembly Yard] BOSS PHASE B (Anvil) → end
```

### A01 — Depot
* Continuation from M10's depot (same art, dawn light). `CIN_M11_Anvil`: the Unsung climbs the gantry, drops into the cockpit (taped Static decals, a dangling pine-tree air freshener, a photo of Wren's crew taped to the dash); the canopy slams shut; HUD boots in amber; Wren: "*Controls are the same as your suit, basically. Big gun, bigger gun, loud horn, punch. Try not to fall over.*"
* Input context switches to `IMC_Mech`.

### A02 — Outer Yards (Mech Segment)
* **Space (mech scale):** a 1.5 km route through the Assembly's outer industrial yards: factory halls (destructible facades — the Anvil smashes through), rail lines, cooling towers, slag fields. Built at mech scale: "corridors" are 40–60 m wide streets between factory blocks.
* **Mech encounters:**
  * `MECH_M11_01` "**Yard Gate**": Organ Grinders (tiny at this scale — the Anvil can stomp them: contact kills T1/T2), Chime Turrets on walls (mech-scale versions), infantry swarms (Thralls, Choristers) — the Anvil mows through them (Gain doesn't exist in the mech; mech kills fill **Repair** via Pile Driver executions of titans only).
  * `MECH_M11_02` "**Vesper Cloud**": a Vesper Cloud (swarm titan) engulfs the Anvil; Blast Horn clears it.
  * `MECH_M11_03` "**Walkers**": 2 Organ Walkers across a slag field with cooling towers as cover; Static dropships drop repair crates.
* Ends at the Assembly Gate, too small for the Anvil. Wren: "*Park her. I'll bring her around the back. Go.*"

### A03 — The Gate
* The Unsung climbs down (control returns to on-foot). A massive brass door (60 m) in the Assembly's base with a smaller "worker door" (6 m). A short breather.

### A04 — Pipe-Organ Nave, ENC_M11_01
* **Space:** a cathedral nave (120 × 40 m, 60 m tall) whose walls are **organ pipes** (5–50 m tall, brass and bone) — the pipes play a slow chord on each beat, venting gold steam (hazard jets from specific pipes, telegraphed by a pitch rise: 20 dmg); pews made of conveyor sections; a central aisle; side chapels (half-built Instruments).
* Arena on the central 60 m of the nave + side-chapel balconies (6 m).

### A05 — Foundry of Voices, ENC_M11_02
* **Space:** where Choir-forms are **cast**: rows of porcelain molds in the shape of Choristers, vats of liquid porcelain, kilns glowing gold, conveyor belts carrying freshly cast bodies. Enemies spawn **from molds** (`SPN_Mold`: a mold cracks open, a Chorister falls out steaming).
* **Pedal: Compressor** (secret S3). **Requiem Gate #3** is in the kiln room.
* **Optional:** `CM_M11_01` in the pattern shop.

### A06 — The Crankshaft, ENC_M11_03
* **Space:** a vertical shaft (60 m wide, 200 m tall) around a colossal rotating **crankshaft** and **flywheels** (20–40 m wheels turning slowly) — traversal on moving machinery: platforms on the flywheels' rims rotate, Grind Rails spiral up the shaft walls, Harrow Anchors on connecting rods (moving anchors!), Kick Pads on piston heads that fire on the beat.
* A mid-climb arena on a gantry platform (30 × 30 m) with flyers (Ophans, Seraphs, Vespers).

### A07 — Engine Hall: BOSS PHASE A
* `10_Bosses.md` §4, Phase A ("The Governor"). At the end, the Archon tears free and rises through the opening roof. Wren: "*Breaker! She's outside! JUMP!*" — a scripted Kick Pad launches the Unsung up through the roof opening after it.

### A08 — Assembly Yard: BOSS PHASE B
* The Unsung lands in the Anvil's open cockpit (`CIN`-lite, 3 s). `10_Bosses.md` §4, Phase B ("The Engine Hymn") — the 40 m colossus in the Assembly's rear yard (a 400 × 300 m space with factory halls, gantries, slag pits, and the Assembly's flank as backdrop).
* **Boss Breakdown:** the Anvil's Pile Driver through the furnace; the Anvil's arm is torn off (Wren: "*MY BABY—*" then, quietly, "*...worth it*").
* The Forge-Belt's machines grind to a halt across the whole horizon; the third Aureole band dies.

---

## 3. Encounters

```
MECH_M11_01  "Yard Gate"     (mech)  Route segment 400 m
  Infantry swarms: Thrall x30, Chorister x10, Trooper x10 (stomp/autocannon fodder)
  Organ Grinder x4, Chime Turret (mech-scale) x6
  Repair crates: 2
MECH_M11_02  "Vesper Cloud"  (mech)  Open yard 200 x 200 m
  TTN_VesperCloud x1 + Chime Turret x4 + infantry trickle
  Repair crates: 1
MECH_M11_03  "Walkers"       (mech)  Slag field 400 x 300 m with 6 cooling towers
  TTN_OrganWalker x2 (the second enters when the first is at 50%)
  Infantry trickle; Organ Grinder x4
  Repair crates: 3 (Static dropship drops, one every 40 s)
  Titan Breakdown on each Walker (Pile Driver into the belly-organ)
```

```
ENC_M11_01  "Pipe-Organ Nave"   Arena: A04 (60 x 40 m section; chapel balconies 6 m; steam-jet pipes)   Seals: 2
  Music: MUS_M11_Combat_A        Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6, Thrall x8
  W2 AliveBelow(5):       Organ Grinder x2, Seraph x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  W3 AliveBelow(4):       Bellwether x1, Canon x1, Echo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(3): Crescendo x2, Hymnal x1, Cantor x1, Thrall x8
  Pickups: Health M x2, Plating M x1, ammo L each, Harrow Spool x2
```

```
ENC_M11_02  "Foundry of Voices" Arena: A05 (70 x 45 m; mold rows; kilns; catwalks 7 m)   Seals: 3
  Music: MUS_M11_Combat_A        Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x8 (SPN_Mold, staggered), Thrall x6
  W2 AliveBelow(5):       Fugue x2, Siren x1, Chorister x4 (Mold)
  W3 AliveBelow(4):       Bellwether x1, Organ Grinder x1, Echo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(4): Requiem Knight x1, Chorister x6 (Mold), Thrall x6
  Pickups: Health M x1, Health S x6, Plating M x2, Charge L x1, Shells L x1, Harrow Spool x3
  Power-up: AMP (kiln room balcony)
```

```
ENC_M11_03  "Crankshaft Gantry" Arena: A06 platform (30 x 30 m) + flywheel rims; the shaft void around it   Seals: n/a (vertical; the exits are anchors up)
  Music: MUS_M11_Combat_B        Reward: 1 Brass + loot fountain
  W1 OnStart:             Vesper x10, Ophan x1
  W2 AliveBelow(5):       Seraph x2, Chorister x4 (on the shaft walls)
  Final W3 AliveBelow(4): Ophan x2, Hymnal x1, Thrall x6 (Emerge from the gantry)
  Pickups: Health S x6, Plating S x4, Ordnance L x1, Charge S x2
  Notes: the void is lethal to enemies (knockback kills)
```

**Boss:** `BOSS_Mixolydian` Phase A (on foot) + Phase B (Anvil). **Optional:** `CM_M11_01` (pattern shop), **Requiem Gate #3** (`RQG_03`, "**The Iron Choir**").

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M11_Anvil` | `CIN_M11_Anvil` — boarding, cockpit details, Wren's instructions |
| `EVT_M11_Facades` | Destructible factory facades (Chaos destruction or pre-fractured meshes) |
| `EVT_M11_Park` | Disembark at the Gate |
| `EVT_M11_Molds` | Choristers cast from molds |
| `EVT_M11_Roof` | Archon rises through the roof; Kick Pad launch to the Anvil |
| `EVT_M11_ArmTorn` | Pile Driver finale; the Anvil loses its arm |
| `EVT_M11_Halt` | All machines across the horizon stop; smoke thins; the Aureole band dies |
| Hub | Pedal slot 3 (Wren builds a bigger board "out of the Anvil's scrap") |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #3** | A04: inside the largest organ pipe (50 m) — Downbeat from its top rim (reach via Harrow Anchor on the nave's roof truss) drops you inside the pipe to a chamber at its base | A faint bell sound inside the pipe; violet glow at the rim |
| S2 | **Bootleg Tape #5** (Pit Trial: *"Big Iron"* — a mech-only trial) | A02 (mech): a small Static bunker by the rail line — the Anvil's Pile Driver cracks its roof, revealing the tape (auto-collected in the mech) | A bunker with a violet flag on the roof |
| S3 | **Pedal: Compressor** | A05: inside a mold that never opened (Power Chord it) | A mold with violet cracks |
| S4 | **Effigy: Organ Walker** | A06: on the highest flywheel's hub (a moving target — timed jump) | — |
| S5 | **Effigy: Anvil Siege Frame** | A03: a toy-sized model in the gate guard's hut (Wren's joke: "*That's MY merch!*") | — |
| S6 | **Master: *"Big Iron"* by THE PISTONS** | A05: the foundry break room | — |
| S7 | **Reprise** | A04: a side chapel's collapsed floor (Downbeat) | Orange fissures |
| S8 | **Rig Core** | A06: behind a flywheel, a maintenance alcove visible only for 2 s per rotation — Harrow Anchor inside | Violet glow sweeping into view |
| S9 | **Brass Cache #1** | A04: organ console loft | — |
| S10 | **Brass Cache #2** | A05: pattern shop (after optional Choir Mass) | — |
| S11 | **Sounding Station #1** | A03: gate guard hut | — |
| S12 | **Sounding Station #2** | A06: gantry control booth | — |
| S13–S17 | **Archive Stones** | A03, A04, A05 (×2), A07 | — |

**Archive entries:** `ARC_Loc_Assembly`, `ARC_Archon_Mixolydian` (full), `ARC_Titan_VesperCloud`, `ARC_Tech_AnvilSiegeFrame` (full), `ARC_Hist_Instruments`, `ARC_Opt_RequiemGate3`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy a Vesper Cloud with a single Blast Horn blast |
| 2 | Kill 3 Choristers before they fully leave their molds |
| 3 | Defeat Mixolydian's Phase A without being hit by a Piston Slam |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M11_Mech` — "**Nine Meters Tall**" | Mech segment | Huge, slow, stomping riffs (drop G), brass stabs; the Anvil's footsteps are on the downbeat |
| `MUS_M11_Explore` — "**The Machine Cathedral**" | Nave, Crankshaft traversal | Pipe organ + industrial percussion |
| `MUS_M11_Combat_A` — "**Casting**" | ENC_01–02 | 165 BPM |
| `MUS_M11_Combat_B` — "**Flywheel**" | ENC_03 | Driving, circular riff |
| `MUS_BOSS_Mixolydian` — "**Engine Hymn**" | Boss A/B | 7/8 machine rhythm; choir in clipped syllables |
| Anvil cockpit | Mech | Cockpit rattles, servo whine, warning beeps, Wren's radio |

---

## 8. Art & Lighting

* **Palette:** brass gold, black iron, porcelain white, furnace orange, gold smoke; dawn light outside.
* **Key props:** outer-yard mech-scale kit (factory blocks with destructible facades, cooling towers, rail lines), the Assembly exterior (hero), pipe-organ nave, porcelain molds (open/closed/cracked), kilns, vats of liquid porcelain, crankshaft & flywheels (animated), engine hall (turntable floor rings, pistons, governors, the cradle & cage), the Engine Hymn colossus (hero boss, 40 m).

---

## 9. New Assets Required (P1)

`SK_Anvil` (cockpit interior + exterior, rigged), mech HUD, `IMC_Mech`, `TTN_OrganWalker` (combat-ready), `TTN_VesperCloud` (Niagara swarm entity), mech-scale Chime Turret, destructible factory facades, `BOSS_Mixolydian_A` (cradle, cage, flywheels, turntable arena), `BOSS_Mixolydian_B` (`SK_EngineHymn`), porcelain mold set (`SPN_Mold`), crankshaft/flywheel set, organ-pipe wall kit.
