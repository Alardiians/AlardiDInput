# M10 — THE FORGE-BELT

| | |
|---|---|
| **Act** | III — Iron and Fire |
| **Location** | **The Kessler Forge-Belt** — a continent-spanning industrial corridor of steelworks, rolling mills and robotic assembly plants, tuned by the Mixolydian Archon into a machine-cathedral |
| **Kit** | `IND` + `CHOIR` (machine variant: brass pipes fused with conveyor belts, porcelain-crusted robots) 30% → 70% |
| **Target duration** | 70 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M10_1 → BEAT_M10_4 |
| **New** | **Lance**, Overcharge mod, *Phaser* pedal, **Grind Rails**, molten-steel hazards, crushers; Organ Walker (distant titan) foreshadowing |
| **Landmark** | **The Assembly** — the Mixolydian Spire: a colossal machine-cathedral on the horizon, belching gold smoke, with its own heartbeat of hammer strikes; Organ Walkers stride around it |

---

## 1. Overview

Industry has become liturgy. The Forge-Belt's machines never stop: robotic arms move in perfect choreography, furnaces breathe in rhythm, conveyor belts carry porcelain limbs and brass pipes to assembly lines that build **Instruments** — Organ Grinders, Chime Turrets, and the colossal **Organ Walkers**. Every hammer strike in the Belt lands on the same beat.

**Experience goals:** a fast, kinetic, industrial level with the new **Grind Rails** traversal; the **Lance**'s punch-through power; environmental kills in crushers and molten steel; seeing an Organ Walker stride across the horizon (a promise of the mech mission to come).

---

## 2. Level Flow

```
[A01 Rail Yard] → [A02 Derailed Armored Train] (LANCE) ENC_01
   → [A03 Blast Furnace No. 4] ENC_02 (molten hazards, crushers)   (+CM_M10_01)
   → [A04 Conveyor Rivers] (Grind Rail traversal)
   → [A05 Rolling Mill] ENC_03 (Overcharge mod)
   → [A06 Robotic Assembly Line] ENC_04 (robots as hazards; Organ Grinders born on the line)
   → [A07 Slag Heaps & Walker Crossing] (set piece: an Organ Walker steps over the player)
   → [A08 CDF Heavy-Armor Depot] ENC_05 FINALE → Wren restores the Anvil → end
```

### A01 — Rail Yard
* Drop Coffin landing among freight rail yards under a smog-orange sky; railcars full of porcelain limbs; gantry cranes; the Assembly on the horizon with Organ Walkers moving around it like giants in fog. Radio intro (`RAD_M10`, Harlan's burglar speech).

### A02 — Derailed Armored Train, ENC_M10_01
* **Space:** a CDF armored train derailed across the yard: 8 cars zig-zagged and toppled, forming a maze of steel walls and ramps (cars as climbable platforms, 4–6 m), an overturned locomotive, a turret car.
* **Lance:** in the train's command car (`PKP_Weapon_Lance`). Wren: "*Oh, that's a Concord rail-lance. Those things punch through tanks. Please punch through something big.*" Prompt: `LANCE — pierces everything in a line`.

### A03 — Blast Furnace No. 4, ENC_M10_02
* **Space:** an enormous furnace hall (70 × 50 m, 35 m tall): the furnace tower in the center, **molten-steel channels** (runners) crossing the floor (hazard: 10 dmg/s + instant death volume in the deep runner pools — void rules), ladle cranes carrying brimming steel ladles overhead (a ladle pour can be triggered by shooting its latch: pours molten steel over an area — environmental kill), charging platforms at 8 m and 16 m.
* **Crushers:** hydraulic slag-crushers on one side (instant kill for enemies knocked in).
* **Optional:** `CM_M10_01` in the casting house.

### A04 — Conveyor Rivers (Grind Rails)
* **Space:** a sprawling network of conveyor belts and overhead rails between factory halls, 10–30 m above the ground.
* **Grind Rails introduced:** prompt `GRIND RAILS — land on them to slide; you can shoot while grinding`. A 3-minute traversal run: grind rails, jumps between them, Harrow Anchors on crane hooks, Swing Poles on pipe bridges, Kick Pads (Static-installed on factory roofs). Light enemies shoot from the belts (Troopers, Choristers); Vespers chase.

### A05 — Rolling Mill, ENC_M10_03
* **Space:** a 150 m long mill hall: a line of massive **rolling stands** (rollers glowing hot) running down the center; red-hot steel slabs shoot along the roller table periodically (hazard: 40 dmg + knockback, telegraphed by a siren and a glow at the table's start — also kills enemies); operator pulpits (glass booths, 6 m) on both sides; overhead crane rails (Grind Rails!).
* **Mod Crate: Lance — Overcharge** in an operator pulpit.

### A06 — Robotic Assembly Line, ENC_M10_04
* **Space:** a clean, white-lit robotic plant (80 × 50 m): rows of robotic arms (now porcelain-crusted) performing a synchronized "dance", assembling Organ Grinders on a moving line. **Robot arms are hazards**: they sweep on a rhythm (visible cycle, telegraphed by a warning light) dealing 30 dmg + knockback; enemies caught are knocked around.
* The arena's enemies include **Organ Grinders "born" on the line** (`SPN_Assembly`: a half-assembled Organ Grinder activates and climbs off the conveyor).

### A07 — Slag Heaps & Walker Crossing
* **Space:** an outdoor wasteland of black slag hills and tailings ponds (void) between factory complexes.
* **Set piece:** an **Organ Walker** (25 m titan) strides across the slag field; the Unsung must dodge its footfalls (shadow markers, 1.5 s telegraph, 80 dmg) while traversing to the depot; the Walker ignores the player otherwise (it's heading to the Assembly). The camera shakes with every step. Lund: "*That is— that is not something you can shoot, is it?*" Wren: "*Not with a gun. With a nine-meter robot? Maybe.*"

### A08 — CDF Heavy-Armor Depot, ENC_M10_05 (FINALE)
* **Space:** a fortified CDF vehicle depot: a maintenance hangar (60 × 40 m, 20 m tall) with a gantry-cradled **Anvil Siege Frame** (the one Wren has been remote-restoring via a drone team), vehicle bays (APCs, tanks — cover), fuel depot (explosive canisters), outside yard (40 × 60 m).
* **Objective:** defend the hangar while Wren's drones finish the Anvil's reactivation (the arena is wave-based, not timed; the Anvil's lights come on in stages as waves are cleared).
* After the arena: the Anvil powers up (`COM_M10_12`, Wren: "*She's old, she's ugly and she's MINE. Well. Yours. Don't scratch her.*"). Mission ends with the Unsung looking up at the Anvil.

---

## 3. Encounters

```
ENC_M10_01  "Derailed"             Arena: A02 (train maze 80 x 40 m; cars 4-6 m high)   Seals: 2
  Music: MUS_M10_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Organ Grinder x1, Trooper x4, Thrall x8
  W2 AliveBelow(4):       Seraph x2, Marksman x2 (locomotive roof), Thrall x6
  Final W3 AliveBelow(3): Canon x1, Bellwether x1, Chorister x3, Thrall x6
  Pickups: Charge L x1 (Lance), Health S x6, Plating M x1, Rounds L x1, Harrow Spool x2
  Notes: Lance piercing lines are designed down the train corridors.
```

```
ENC_M10_02  "Blast Furnace No. 4"  Arena: A03 (70 x 50 m, 35 m; platforms 8 & 16 m; runners; crushers)   Seals: 3
  Music: MUS_M10_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Tuned workers), Organ Grinder x1
  W2 AliveBelow(4):       Chorister x4, Bloated Thrall x2, Trooper x3
  W3 AliveBelow(4):       Crescendo x2 (charge along the runners — make them crash into the furnace!), Cantor x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(3): Bellwether x1, Seraph x1, Hymnal x1, Thrall x8
  Pickups: Health M x1, Health S x6, Plating M x1, Ordnance L x1, Shells L x1, Harrow Spool x2
  Hazards: 2 pourable ladles (shoot latch), 2 slag crushers, molten runners
```

```
ENC_M10_03  "Rolling Mill"         Arena: A05 (150 x 30 m hall; roller table center; pulpits 6 m; crane Grind Rails 12 m)   Seals: 2
  Music: MUS_M10_Combat_B           Reward: 1 Brass + loot fountain
  W1 OnStart:             Trooper x6 (pulpits), Thrall x8
  W2 AliveBelow(4):       Organ Grinder x2, Chorister x2, Thrall x4
  W3 AliveBelow(4):       Canon x1, Bulwark x3, Echo x1
  Final W4 AliveBelow(3): Crescendo x2, Seraph x2, Thrall x8
  Pickups: Health S x8, Plating M x2, Charge L x1, Rounds L x1, Ordnance S x2
  Hazards: hot-slab runs every 20 s (siren 2 s before)
```

```
ENC_M10_04  "Assembly Line"        Arena: A06 (80 x 50 m; robot rows; moving line; mezzanine 6 m)   Seals: 3
  Music: MUS_M10_Combat_B           Reward: 1 Brass + loot fountain
  W1 OnStart:             Organ Grinder x2 (SPN_Assembly), Thrall x8
  W2 AliveBelow(4):       Chorister x4, Vesper x8
  W3 AliveBelow(4):       Organ Grinder x1 (SPN_Assembly), Fugue x2, Trooper x3
  Final W4 AliveBelow(3): Bellwether x1, Canon x1, Cantor x1, Thrall x8
  Pickups: Health M x1, Health S x6, Plating S x4, ammo L x1 (Rounds, Charge), Harrow Spool x2
  Power-up: TEMPO (mezzanine control booth)
```

```
ENC_M10_05  "Heavy-Armor Depot" (FINALE)  Arena: A08 (hangar 60 x 40 m + yard 40 x 60 m; gantries 8 m)   Seals: 3
  Music: MUS_M10_Combat_C           Reward: 2 Brass + big loot fountain
  W1 OnStart:             Trooper x6, Bulwark x3, Thrall x8                      (Anvil 25%)
  W2 AliveBelow(5):       Organ Grinder x2, Chorister x4                         (Anvil 50%)
  W3 AliveBelow(5):       Bellwether x1, Crescendo x2, Echo x1, Thrall x6        (Anvil 75%)
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Canon x2, Seraph x2, Cantor x1, Chorister x3            (Anvil 100%)
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3, explosive canisters x6 (fuel depot)
  Power-up: AMP (yard, atop a tank)
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M10_Horizon` | Organ Walkers striding around the Assembly on the horizon |
| `EVT_M10_LadlePour` | Shootable ladle latches (environmental kills) |
| `EVT_M10_GrindRails` | Grind-rail tutorial run |
| `EVT_M10_WalkerCrossing` | A Walker steps over the slag field |
| `EVT_M10_AnvilWake` | The Anvil powers up in stages as waves fall |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Mute Cell #4** | A02: inside the turret car — Harrow-yank the jammed hatch | Violet glow in the hatch gap |
| S2 | **Heart Shard #8** | A04: a grind-rail branch that splits off near the end (jump to it at the fork) leads to a crane cab | The alternate rail glows faintly violet at its start |
| S3 | **Tab #4: "Heavy Metal"** (all weapons fire with ×2 recoil and ×2 screen shake; cosmetic chaos) | A03: top of the furnace tower (Kick Pad on the 16 m platform) | Violet glow at the furnace crown |
| S4 | **Pedal: Phaser** | A05: behind the last rolling stand — cross the roller table between slab runs | Violet glow behind the stand |
| S5 | **Effigy: Organ Grinder** | A06: the plant manager's office above the mezzanine | — |
| S6 | **Master: *"Iron and Rust"* by KESSLER WORKS** | A01: a railcar's break room (a radio playing) | Music |
| S7 | **Reprise** | A07: on a slag heap summit, reachable only by jumping from the Walker's *foot* as it lifts (!) or by an expert double-dash from a conveyor | Violet glow on the summit |
| S8 | **Rig Core** | A08: fuel depot's pump house roof | — |
| S9 | **Brass Cache #1** | A03: casting house (after optional Choir Mass) | — |
| S10 | **Brass Cache #2** | A06: robot maintenance bay (time your pass between two robot arms) | — |
| S11 | **Sounding Station** | A04: a foreman's hut on a conveyor bridge | — |
| S12–S16 | **Archive Stones** | A01, A02, A03, A06, A08 | — |

**Archive entries:** `ARC_Loc_ForgeBelt`, `ARC_Hist_IndustryHymn`, `ARC_Archon_Mixolydian`, `ARC_Enemy_Instruments`, `ARC_Titan_OrganWalker`, `ARC_Weapon_Lance`, `ARC_Tech_GrindRail`, `ARC_Tech_AnvilRestoration`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Kill 4+ enemies with a single Lance shot |
| 2 | Kill 10 enemies with environmental hazards (ladles, crushers, slabs, runners, robot arms) |
| 3 | Kill 5 enemies while grinding on a rail |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M10_Explore` — "**Shift Change**" | Traversal | Industrial: hammer strikes on the beat (diegetic factory rhythm quantized to the music), clanking percussion |
| `MUS_M10_Combat_A` — "**Molten**" | ENC_01–02 | 150 BPM, industrial metal |
| `MUS_M10_Combat_B` — "**Production Line**" | ENC_03–04 | 7/8 machine groove |
| `MUS_M10_Combat_C` — "**Heavy Armor**" | ENC_05 | Big finish; brass stabs |
| Walker footsteps | A07 | Sub-bass impacts; rumble |

---

## 8. Art & Lighting

* **Palette:** smog-orange sky, black iron, molten orange-white steel, sodium lights, brass and porcelain Choir growth on machines, the Assembly's gold smoke.
* **Key props:** rail yard & railcars, armored train (8 car types, derailed variants), blast furnace (hero), ladle cranes & hanging ladles, molten runner material (emissive flow), slag crushers, conveyor network with Grind Rail splines, rolling mill stands, robotic arms (skeletal, animated cycles), assembly-line Organ Grinder states, slag heaps, CDF depot, the Anvil in its gantry.

---

## 9. New Assets Required (P1)

`SK_WPN_Lance`, `BP_GrindRail`, IND kit (walls, catwalks, stairs, pipes, conveyors, cranes), blast furnace hero set, ladle pour VFX & kill volume, rolling mill set, `SK_RobotArm` (crusted), `SPN_Assembly` Organ Grinder states, `TTN_OrganWalker` (distant & crossing variant), slag terrain, CDF depot kit, `SM_AnvilSiegeFrame` (active version, rigged `SK_Anvil`).
