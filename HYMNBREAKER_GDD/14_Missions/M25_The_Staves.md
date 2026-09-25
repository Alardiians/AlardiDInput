# M25 — THE STAVES

| | |
|---|---|
| **Act** | VI — The Last Broadcast |
| **Location** | **The Staves** of the Harmonium — five colossal parallel bridges (each a kilometer wide) stretching across a golden void toward the Clef, with **Note-Worlds** (spherical citadels) resting on and between them |
| **Kit** | `HARM` + `CHOIR_ARCH` + `SHIP` (the Quietus as a flying ally, exterior) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M25_1 → BEAT_M25_3 |
| **New** | **Broadside** (call-in Quietus fire support), stave-to-stave Kick Pad chains, a Note-World interior; titan **Seraphim Gunship**; no hub after this point |
| **Landmark** | **The Clef** — a spiral citadel kilometers tall at the head of the Staves, growing larger as you advance; a vast eye of light opening at its center |

---

## 1. Overview

The final charge. After `CIN_HUB_LastPlan`, the Quietus — its entire hull rigged by Wren as a giant speaker, its crew's messages chalked on every shell — jumps into the Harmonium. The Unsung runs the Staves toward the Clef with the Quietus flying alongside, its broadside guns and speaker-arrays roaring. Lund lies in the med-bay, humming, getting weaker.

**Experience goals:** epic scale and momentum; the Quietus as a character (you're finally fighting *with* your home); the Harmonium's full grandeur (Note-Worlds the size of moons); the last traversal set pieces; and a finale on the fifth Stave under the Clef's opening eye.

---

## 2. New Mechanic — Broadside (M25–M26 only)

* **Input:** `IA_Broadside` (default: **B** / gamepad **D-pad Up hold**). Aim at a point within 5000 cm; a gold-orange target marker appears (Tamsin's reticle); after **3.0 s**, the Quietus fires a **broadside** along a line through the marker (a 3000 cm long, 800 cm wide strip): 3000 damage to everything in it (bosses/titans: 1500), plus a colossal wall of noise (the ship's speakers) that **Hushes nothing** but **Distorts** everything hit.
* **Cooldown:** 60 s. Disabled in interiors (the Note-World) and when the Quietus is out of line of sight (the HUD icon greys out with "NO LINE").
* Tamsin's confirmation: a signed "✋ *On it.*" subtitle + a ship-horn blast.

---

## 3. Level Flow

```
[CIN: The Quietus jumps (hull-speaker, messages on shells)] → [A01 Drop onto Stave One]
   → [A02 Stave One — The First Line] ENC_01 (Broadside tutorial)   (+CM_M25_01)
   → [A03 The Leap (Kick Pad chains across the void to Stave Two)]
   → [A04 Stave Two — The Rest Monument] ENC_02
   → [A05 Air Defense (Seraphim Gunships vs. the Quietus)] ENC_03
   → [A06 The Note-World (interior of a golden conquered city)] ENC_04   (+CM_M25_02)
   → [A07 Stave Five — Before the Clef] ENC_05 FINALE → the Clef, sealed
```

### A01 — Drop onto Stave One
* The Drop Coffin launches from the Quietus (the launch sequence now shows the hull's speaker arrays and crew messages as the coffin passes: "*KEEP IT LOUD*", "*FOR JUNO*", "*BREAK THE HYMN*", a child's drawing of the Unsung). It lands on **Stave One**: a kilometer-wide bridge of white-gold stone, humming underfoot (camera micro-vibration). Its surface has periodic **ledger ridges** (raised lines 2 m high every 60 m — cover and ramps). The void below and above is golden; other Staves run parallel at 400 m intervals (visible above/below — the Staves are stacked vertically like a musical staff!). Note-Worlds loom like moons.

### A02 — Stave One: The First Line, ENC_M25_01
* **Space:** a 200 × 150 m section of the Stave between ledger ridges, with fallen Note-fragments (spheres of gold 10–20 m, half-sunk into the Stave — cover), Hymn Saturation pools, and the Quietus flying alongside at 300 m.
* **Broadside tutorial** (Vire: "*Tamsin's got guns on you. Point, and she'll put a broadside wherever you want it.*").

### A03 — The Leap
* Traversal from Stave One up to Stave Two (400 m above): a chain of **Kick Pads** mounted on floating note-heads, **Note-Platform** melodies, and Harrow Anchors on the Quietus's own hull (!): the player grapples onto the flying Quietus, runs along its dorsal ridge (a short on-ship traversal with crew cheering from open hatches and a huge speaker array blasting music) and leaps from its bow to Stave Two.

### A04 — Stave Two: The Rest Monument, ENC_M25_02
* **Space:** on Stave Two stands a colossal **rest symbol** (a quarter-rest-shaped monument, a 60 m zig-zag tower of bone), around which the Choir is massed. Arena 180 × 120 m around the monument's base; the monument's zig-zag ledges are climbable (Grip Walls) for high ground.

### A05 — Air Defense, ENC_M25_03
* **Space:** the edge of Stave Two, overlooking the void where the Quietus flies. **Seraphim Gunships** (15 m flying Seraphs) attack the Quietus — the player must shoot them down from the Stave (Lance, Hammerfall Lock Salvo, Riveter scope on wing-pipes) while ground enemies attack the player. The Quietus's HP is shown (it can't be destroyed — at low HP it retreats and the wave continues until the gunships are dead; Tamsin: "✋ *Taking hits. Kill them. Please.*").

### A06 — The Note-World, ENC_M25_04
* **Space:** the route passes **through** a Note-World resting on Stave Three: a hollow sphere (1 km diameter) containing a conquered civilization's city, gilded — a city of spiral towers built by a species of tall, many-armed beings; their gilded bodies stand in its streets, all facing the center where a Hymn-core pulses. The arena is the central plaza around the core (80 × 80 m).
* Broadside is unavailable inside (no line of sight).
* **Optional:** `CM_M25_02` in a gilded alien temple.

### A07 — Stave Five: Before the Clef, ENC_M25_05 (FINALE)
* **Space:** the top Stave, its head curling up into the **Clef** — a spiral citadel kilometers tall. The arena is a vast plaza (200 × 150 m) at the Clef's foot, before its great spiral gate (sealed). The Clef's central **eye** of light opens during the fight (the Unison watching).
* After the arena, the Key of the Unresolved opens the outer gate — but the inner walls stay sealed (leads into M26).

---

## 4. Encounters

```
ENC_M25_01  "The First Line"         Arena: A02 (200 x 150 m; ledger ridges 2 m; gold note-fragments; Saturation pools)   Seals: n/a
  Music: MUS_M25_Combat_A             Reward: 2 Brass + loot fountain
  W1 OnStart:             Chorister x8, Thrall x12
  W2 AliveBelow(8):       Carillon x1, Bulwark x4         (Broadside tutorial prompt on the Carillon)
  W3 AliveBelow(6):       Maestro x1, Gilded Crescendo x2
  W3b TimeElapsed(25s):   Thrall x10
  Final W4 AliveBelow(6): Gilded Profundo x1, Seraph x3, Chorister x6
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x4
```

```
ENC_M25_02  "The Rest Monument"      Arena: A04 (180 x 120 m; monument ledges up to 40 m)   Seals: n/a
  Music: MUS_M25_Combat_B             Reward: 2 Brass + loot fountain
  W1 OnStart:             Requiem Knight x2, Chorister x6, Thrall x10
  W2 AliveBelow(8):       Gilded Canon x2, Cantor x2
  W3 AliveBelow(6):       Carillon x1, Siren x2, Fugue x2
  Final W4 AliveBelow(6): Maestro x2, Gilded Bellwether x1, Ophan x2, Thrall x10
  Pickups: Health M x3, Plating M x3, ammo L each, Grudge x1, Harrow Spool x4
  Power-up: AMP (monument's highest ledge)
```

```
ENC_M25_03  "Air Defense"            Arena: A05 (Stave edge 150 x 60 m) + the void (gunships)   Seals: n/a
  Music: MUS_M25_Combat_B             Reward: 2 Brass + loot fountain
  Titans: TTN_Seraphim x3 (attack the Quietus in sequence; 8000 HP each; wing-pipes x4 weak points)
  Ground: Chorister x6 + Thrall x8 every 40 s; Seraph x2 at each gunship kill
  Pickups: Ordnance L x3, Charge L x2, Health M x2, Plating M x2
```

```
ENC_M25_04  "The Note-World"         Arena: A06 (80 x 80 m plaza around a Hymn-core; spiral-tower bases as cover; balconies 10 m)   Seals: 4 (streets)
  Music: MUS_M25_Combat_C             Reward: 2 Brass + loot fountain
  Hazard: the Hymn-core acts as a Hymn Pylon (radius 3000) until destroyed (4000 HP; Power Chord/explosives)
  W1 OnStart:             Chorister x8 (alien-species Tuned), Thrall x12
  W2 AliveBelow(8):       Gilded Profundo x1, Echo x2
  W3 AliveBelow(6):       Maestro x1, Requiem Knight x1, Seraph x2
  Final W4 AliveBelow(6): Carillon x1, Gilded Crescendo x1, Chorister x6
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x4
```

```
ENC_M25_05  "Before the Clef" (FINALE)  Arena: A07 (200 x 150 m; spiral gate; broken ledger ridges; Saturation)   Seals: n/a
  Music: MUS_M25_Combat_D ("Almost Time")   Reward: 3 Brass + big loot fountain
  W1 OnStart:             Chorister x10, Thrall x14, Hymn Pylon x2
  W2 AliveBelow(8):       Carillon x2
  W3 AliveBelow(8):       Maestro x2, Requiem Knight x2, Gilded Canon x1
  W3b TimeElapsed(25s):   Thrall x12
  W4 AliveBelow(8):       Gilded Profundo x2, TTN_Seraphim x1 (strafing the plaza)
  Final W5 AliveBelow(6): Everything: Gilded Bellwether x1, Gilded Crescendo x1, Siren x2, Fugue x2, Echo x2, Chorister x6
  Pickups: Health M x4, Plating M x4, ammo L each x2, Null Cell x2, Grudge x2, Harrow Spool x5
  Power-up: OVERDRIVE SURGE + DEAD SILENCE
```

---

## 5. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M25_Messages` | Crew messages on the hull during the coffin launch |
| `EVT_M25_StackedStaves` | Reveal of the five stacked Staves (like a musical staff seen edge-on) |
| `EVT_M25_ShipRun` | Running along the flying Quietus's dorsal ridge; crew cheering from hatches |
| `EVT_M25_Gunships` | Seraphim gunships vs. the Quietus |
| `EVT_M25_NoteWorld` | Walking through a gilded alien city inside a sphere |
| `EVT_M25_ClefEye` | The Clef's eye opens and watches |
| Harlan | His voice reaches the Harmonium in fragments (through Lund, who hums it) — rehearsals for the Last Broadcast: people on Earth warming up, practicing noise (comedic and moving) |

---

## 6. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Bootleg Tape #12** (Pit Trial: *"Staves"* — Note-Platform gauntlet with waves) | A03: on the Quietus's dorsal ridge — a crew member hands it over ("*Mixtape for the end of the world!*") | A crew member waving from a hatch |
| S2 | **Effigy: Seraphim Gunship** | A05 (after the arena), on the Stave's edge | — |
| S3 | **Effigy: The Quietus** | A03: in the Quietus's open bow hatch | — |
| S4 | **Master: *"Almost Time"* by THE QUIETUS CREW CHOIR** (the crew singing, badly) | A04: the Rest Monument's summit | Singing from above |
| S5 | **Reprise** | A06: inside a gilded alien home off the plaza | — |
| S6 | **Rig Core** | A02: inside a half-sunk gold note-fragment (Power Chord its cracked face) | Orange fissures |
| S7 | **Brass Cache #1** | A02 (after `CM_M25_01`) | — |
| S8 | **Brass Cache #2** | A06 (after `CM_M25_02`) | — |
| S9 | **Sounding Station #1** | A02 (Static probe) | — |
| S10 | **Sounding Station #2** | A06 | — |
| S11–S15 | **Archive Stones** | A01, A04, A06 (×2), A07 | — |

**Archive entries:** `ARC_Loc_Staves`, `ARC_Obj_NoteWorlds`, `ARC_Hist_TakenWorld_V` (the many-armed city), `ARC_Titan_Seraphim`, `ARC_Tech_QuietusSpeakerHull`, `ARC_Obj_LastBroadcast_Rehearsal`.

---

## 7. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Kill 25 enemies with a single Broadside |
| 2 | Shoot down all 3 Seraphim gunships without the Quietus retreating |
| 3 | Destroy the Note-World's Hymn-core within 60 seconds |

---

## 8. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M25_Explore` — "**The Staves**" | Traversal | The main theme, orchestrated huge; the Staves' hum as a drone; Harlan's rehearsal fragments |
| `MUS_M25_Combat_A` — "**First Line**" | ENC_01 | 180 BPM |
| `MUS_M25_Combat_B` — "**Rest Is Not an Option**" | ENC_02–03 | Heavy, soaring |
| `MUS_M25_Combat_C` — "**Taken Worlds**" | ENC_04 | Alien choir timbres vs. band |
| `MUS_M25_Combat_D` — "**Almost Time**" | ENC_05 | The finale build; ends on a held chord that carries into M26 |
| Quietus | Everywhere | The ship's hull-speakers blast music into the Harmonium (diegetic layer that ducks with distance) |

---

## 9. New Assets Required (P1)

Stave surface kit (ledger ridges, note-fragments), stacked-Staves vista, `TTN_Seraphim`, Quietus exterior (flying, animated hatches, speaker arrays, crew-message decals), dorsal-ridge walkable section, Note-World interior (alien spiral-tower city in gold), alien-species Tuned variants, Rest Monument, Clef exterior (hero) with the eye, `BP_Broadside` ability.
