# M13 — CORONA

| | |
|---|---|
| **Act** | III — Iron and Fire |
| **Location** | **The Corona Array**'s mirror fields and its central **Focal Tower**, on Mercury's day side |
| **Kit** | `ORB` (solar structures) + `BRU` + `CHOIR` 50% → 100% (fire-veined porcelain) |
| **Target duration** | 80 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M13_1 → BEAT_M13_3 |
| **New** | Recall mod, *Tremolo* pedal, **Requiem Gate #4**, reflected-beam hazards; **Boss: Phrygian, the Burning Cantor** |
| **Landmark** | **The Phrygian Spire** — the Focal Tower, 3 km tall, wrapped in a helix of white fire, the Sun's focused light pouring into its crown and a beam of gold light shooting from it *into the Sun* |

---

## 1. Overview

The mirror fields stretch to every horizon: millions of panels, all turned toward one tower. Phrygian has turned the Corona Array into a lens pointed at the Sun, and the Sun has begun to **hum** — a tone that everyone in the solar system can now hear in quiet rooms. The Unsung crosses the fields, climbs the Focal Tower and faces the Archon who loves their rage.

**Experience goals:** a gauntlet across blinding terrain with **reflected sun-beams** as moving hazards; a vertical tower climb; one of the most aggressive, spectacular boss fights in the game; and a cliffhanger — the Quietus goes silent.

---

## 2. Level Flow

```
[A01 Array Service Road] → [A02 Mirror Fields — Sector 7] ENC_01 (reflected beams)
   → [A03 Relay Substation] (lore; Requiem Key #4 hidden; Requiem Gate #4 here)
   → [A04 The Beam Line (conduit catwalks, Grind Rails)] ENC_02
   → [A05 Focal Tower Base] ENC_03   (+CM_M13_01 in the maintenance hangar)
   → [A06 Tower Ascent] ENC_04 (mid-tower)
   → [A07 Focal Platform] BOSS: PHRYGIAN → CIN_M13_Distress
```

### A01 — Array Service Road
* A straight service road cutting through the mirror fields toward the tower; shaded by a tall conduit on one side (safe lane); the Sun humming louder. Wrecked service vehicles; dead Tuned technicians stand in the fields *staring into the Sun* (porcelain faces melted smooth).

### A02 — Mirror Fields, Sector 7, ENC_M13_01
* **Space:** a field of mirror panels on 3 m posts (panels 6 × 4 m) in a grid, with service lanes, a junction hut, and relay pylons. **Reflected beams:** the Choir has angled some mirrors to bounce concentrated sunlight across the field as **beam lines** (bright white lines at chest height, 60 dmg/s on contact, sweeping slowly as mirrors track) — telegraphed by a shimmering line that thickens before it becomes lethal (1.0 s).
* **Counterplay:** shoot a mirror panel (100 HP) to shatter it → its beam stops (and enemies caught in a beam's sweep take the damage too).

### A03 — Relay Substation
* **Space:** a shaded substation complex (transformers, a control building, a cable vault). Breather + lore; **Requiem Gate #4** is in the cable vault; **Requiem Key #4** hidden in A02 (see secrets).
* Lund's comms: the Sun's hum is rising a semitone an hour.

### A04 — The Beam Line, ENC_M13_02
* **Space:** a 400 m long elevated power conduit (a massive pipe, 10 m diameter) carrying energy to the tower, with catwalks along both sides and **Grind Rails** along its top; periodically, focused beams sweep across the conduit (hazard). A pumping station platform midway (40 × 30 m) hosts the arena.
* **Mod Crate: Ripsaw — Recall** at the pumping station.

### A05 — Focal Tower Base, ENC_M13_03
* **Space:** the tower's base fortress (90 × 70 m): the tower's foot (a massive porcelain-and-steel root system wrapped in fire), terraces of Choir growth, a maintenance hangar (optional Choir Mass), two ramps up to the tower's lift doors. Shade from the tower itself sweeps slowly (the tower's shadow is a huge moving safe zone).

### A06 — Tower Ascent, ENC_M13_04
* **Space:** the tower's hollow interior — a 400 m vertical shaft with a spiral Grind Rail climbing the walls, lift platforms (moving, 15 × 15 m), Harrow Anchors on the concentric support rings, and fire geysers (hazards venting through wall cracks on a rhythm). A mid-tower arena on a support ring (a circular walkway 50 m diameter, 12 m wide).
* Phrygian's voice echoes up the shaft (harmonized, fiery): "*I can hear you climbing. You sound like a war. Come up, come up — let me hear you properly.*"

### A07 — Focal Platform: BOSS PHRYGIAN
* `10_Bosses.md` §6. `CIN_M13_Phrygian`. The platform: 60 m, 8 pylons, 12 heliostat panels on motorized arms around the rim, the Sun filling a third of the sky.
* After the Boss Breakdown: the Sun's hum **stops** (the audio's long-running hum layer cuts out — the silence is palpable); the fourth Aureole band dies.
* `CIN_M13_Distress`: the Quietus goes silent; Vire's broken transmission.

---

## 3. Encounters

```
ENC_M13_01  "Sector 7"               Arena: A02 (120 x 100 m mirror grid; panels 3 m high; junction hut; pylons)   Seals: bone growth on lanes
  Music: MUS_M13_Combat_A             Reward: 1 Brass + loot fountain
  Hazards: 4 reflected beam lines (shatter mirrors to disable)
  W1 OnStart:             Chorister x6 (panel tops), Thrall x8
  W2 AliveBelow(5):       Seraph x2, Marksman x2 (pylons), Thrall x4
  W3 AliveBelow(4):       Profundo x1, Crescendo x1, Thrall x6
  Final W4 AliveBelow(4): Ophan x2, Canon x1, Chorister x4
  Pickups: Health S x8, Plating M x2, ammo L x1 (Rounds, Ordnance), Harrow Spool x2
```

```
ENC_M13_02  "Pumping Station"        Arena: A04 platform (40 x 30 m) + conduit catwalks (both sides, 60 m) + conduit-top Grind Rail   Seals: 2
  Music: MUS_M13_Combat_B             Reward: 1 Brass + loot fountain
  W1 OnStart:             Vesper x10, Trooper x4
  W2 AliveBelow(5):       Siren x2, Chorister x3
  W3 AliveBelow(4):       Bellwether x1, Echo x1, Hymnal x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(3): Seraph x2, Crescendo x2, Thrall x6
  Pickups: Health M x1, Health S x6, Plating M x1, Ordnance L x1, Charge L x1
  Notes: the conduit's sides drop 30 m (void: knockback kills).
```

```
ENC_M13_03  "Tower Foot"             Arena: A05 (90 x 70 m, root terraces 4-10 m, moving tower shadow)   Seals: 3
  Music: MUS_M13_Combat_C             Reward: 2 Brass + big loot fountain
  W1 OnStart:             Profundo x1, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Canon x2, Cantor x1, Bulwark x3
  W3 AliveBelow(5):       Requiem Knight x1, Fugue x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Profundo x1, Seraph x2, Hymnal x1, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
  Power-up: AMP (in the tower's shadow when the arena starts; it moves into sunlight over time!)
```

```
ENC_M13_04  "Support Ring"           Arena: A06 (circular walkway 50 m dia, 12 m wide; fire geysers; shaft void inside)   Seals: n/a
  Music: MUS_M13_Combat_B             Reward: 1 Brass + loot fountain
  W1 OnStart:             Ophan x2, Vesper x8
  W2 AliveBelow(5):       Chorister x6 (walls), Seraph x1
  Final W3 AliveBelow(4): Bellwether x1, Siren x1, Thrall x8
  Pickups: Health S x6, Plating S x4, Ordnance S x2, Shells S x2
```

**Boss:** `BOSS_Phrygian`. **Optional:** `CM_M13_01` (maintenance hangar), **Requiem Gate #4** (`RQG_04`, "**Sunward**").

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M13_Starers` | Tuned technicians staring into the Sun (melted faces) |
| `EVT_M13_Beams` | Reflected beams; shatterable mirrors |
| `EVT_M13_HumRising` | The Sun's hum rises in pitch at each checkpoint (a semitone) |
| `EVT_M13_Phrygian` | `CIN_M13_Phrygian` |
| `EVT_M13_HumStops` | The hum cuts out after Phrygian dies |
| `EVT_M13_Distress` | `CIN_M13_Distress` → leads directly into M14 |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #4** | A02: under the junction hut's floor — the hut is shaded; Downbeat through its cracked floor into a cable tunnel | Faint bell; orange fissures |
| S2 | **Heart Shard #10** | A04: inside the conduit — a maintenance hatch on the conduit top (Grind Rail stop), drop inside, walk 50 m of dim pipe | Violet glow at the hatch |
| S3 | **Mute Cell #5** | A05: the tower's root system — a hollow root reachable by Harrow Anchor | — |
| S4 | **Bootleg Tape #6** (Pit Trial: *"Blinded"* — fight with a constant bloom/glare filter) | A03: substation control room desk | Cassette player |
| S5 | **Pedal: Tremolo** | A06: a lift platform's underside — ride the lift, drop off at the halfway support ring's hidden ledge | Violet glow as the lift passes |
| S6 | **Effigy: The Antiphon** | A01: a wrecked service truck's cab | — |
| S7 | **Effigy: Phrygian** | A07: after the boss, on a heliostat arm's tip | — |
| S8 | **Master: *"Burn It Down"* by SOLAR FLARE** | A03: cable vault antechamber | — |
| S9 | **Reprise** | A02: on top of the tallest relay pylon (Grip Wall + anchor) | — |
| S10 | **Rig Core** | A06: behind a fire geyser crack (pass during its off-cycle) | Violet glow between bursts |
| S11 | **Brass Cache #1** | A03 | — |
| S12 | **Brass Cache #2** | A05 maintenance hangar (after optional Choir Mass) | — |
| S13 | **Sounding Station #1** | A03 control room | — |
| S14 | **Sounding Station #2** | A05 hangar office | — |
| S15–S19 | **Archive Stones** | A01, A02, A03, A05, A06 | — |

**Archive entries:** `ARC_Loc_FocalTower`, `ARC_Obj_SingingSun`, `ARC_Archon_Phrygian` (full), `ARC_Hist_PhrygianAndTheUnsung` (Choir record: "*Phrygian petitioned the Unison seven times to be allowed to hunt the Wrong Note alone*"), `ARC_Opt_RequiemGate4`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Kill 5 enemies with reflected sun-beams |
| 2 | Redirect a Focus Beam onto Phrygian twice in one fight |
| 3 | Counter an entire Fury Combo (4 gold strikes) |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M13_Explore` — "**Glare**" | Fields | The Sun's hum is the key center; guitars bend toward it; tension rises with the hum's pitch |
| `MUS_M13_Combat_A` — "**Mirror Maze**" | ENC_01 | 170 BPM |
| `MUS_M13_Combat_B` — "**Conduit**" | ENC_02, ENC_04 | Fast, grinding |
| `MUS_M13_Combat_C` — "**Root of the Fire**" | ENC_03 | Heavy |
| `MUS_BOSS_Phrygian` — "**The Burning Cantor**" | Boss | Phrygian-mode, flamenco-inflected metal |
| Hum | Global | Stops dead after the boss |

---

## 8. Art & Lighting

* Same palette as M12, hotter: the sky white-gold near the Sun; fire-veined porcelain growth; the tower's fire helix; beam lines as the brightest objects on screen (but still readable against the sky — beams have a dark core outline).

---

## 9. New Assets Required (P1)

`BOSS_Phrygian` (`SK_Phrygian`, heliostat panels with motors, focal platform), mirror panel field (instanced, shatterable), reflected-beam hazard system (`BP_BeamLine` with mirror dependencies), conduit kit, tower interior (spiral rail, lift platforms, support rings, fire geysers), fire-vein CHOIR growth variant.
