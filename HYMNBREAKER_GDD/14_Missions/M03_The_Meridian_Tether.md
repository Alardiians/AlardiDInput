# M03 — THE MERIDIAN TETHER

| | |
|---|---|
| **Act** | I — First Noise |
| **Location** | Earth's space elevator: **Apex Station** (orbital terminus), the ribbon, a climber car, **Waystation Nine**, the ocean anchor platform off Halcyon |
| **Kit** | `ORB` (space station), `BRU` interiors, `CHOIR` 30–70% |
| **Target duration** | 70 min |
| **Priority** | **P0 — Act I Alpha** (see `24_AI_Build_Roadmap.md` Milestone 4) |
| **Story beats** | BEAT_M03_1 → BEAT_M03_6 |
| **New** | Gravedigger, Hush Charge, Overdrive (+ Gain meter), Downbeat, Swing Poles, Choir Masses, moving arena; Tack Scope & Heat Burst mods; enemies Crescendo, Ophan, Wailer |
| **Landmark** | **The ribbon** — a 1 m wide, impossibly long band of carbon-nanotube weave running from space down to Earth, pulsing with visible gold light-waves as the Choir plucks it |

---

## 1. Overview

**The fiction:** the Choir has turned the space elevator into an instrument. At Apex Station, a colossal bone structure — the **Plectrum** — plucks the ribbon; the vibration runs down to **Waystation Nine**, where the **Bridge** (a bone-and-gold clamp) couples it into a Hymn broadcast over Halcyon. The Unsung must silence both, then ride the string down to Earth. Lund: "*They've turned the largest structure humans ever built into a harp.*"

**Experience goals:** first mission launched from the hub (the **Drop Coffin**), dramatic space vistas, the first "god-mode" moment (Overdrive), the first Crescendo's roar, a moving-arena descent through the sky, and an explosive crash-landing on Earth.

---

## 2. Level Flow

```
[Hub: Drop Coffin launch] → [A01 Docking Ring] → [A02 Ring Concourse] ENC_01 (Gravedigger)
   → [A03 Hydroponic Garden] ENC_02 (Hush, Crescendo intro)
   → [A04 Spoke Shaft] (Downbeat, Swing Poles)
   → [A05 Hub Core — Plectrum Chamber] ENC_03 (Overdrive boot) — destroy the PLECTRUM
   → [A06 Climber Terminal] → [A07 Climber Descent] ENC_04 (moving arena; Ophan, Wailer)
   → [A08 Waystation Nine] ENC_05 (+ Choir Mass CM_01 optional) — destroy the BRIDGE
   → [A09 Roof Ride] ENC_06 (survival, 90 s) → [A10 Anchor Platform crash] CIN
```

### A01 — Docking Ring (Apex Station)
* **Launch:** in the hub, the player enters the **Drop Coffin** (a black, coffin-shaped launch pod in the Quietus's Launch Bay). First-person launch sequence (8 s): the coffin is fired; through its narrow slit window the player sees the Quietus recede, Earth and its Aureole swing past, and Apex Station approach; the coffin punches through a docking-ring window and skids across the floor. (This sequence is reused, with variations, for every mission start from the hub.)
* **Space:** Apex Station is a huge rotating ring (1 km diameter) — interiors have spin gravity, so **long corridors curve upward** in the distance (a signature visual). The docking ring is a 20 m wide hall of airlocks and cargo cranes.
* Light combat: 3 Thralls (station crew).

### A02 — Ring Concourse, ENC_M03_01
* **Space:** a curving 25 m wide shopping-and-transit concourse (the station's "main street") with shuttered shops, a transit tram line down the middle (dead tram car as cover), and a **Security Office**.
* **Gravedigger:** in Sgt. Ruiz's locker in the Security Office, found before the arena: a locker labelled "D. RUIZ — FOR EMERGENCIES" with the Gravedigger and a note ("If you're reading this I'm either dead or singing. Either way: shoot them for me."). `PKP_Weapon_Gravedigger`. Prompt: `GRAVEDIGGER — devastating at close range`.
* The arena runs along 80 m of curving concourse — the curvature means enemies appear "above" the horizon ahead.

### A03 — Hydroponic Garden, ENC_M03_02
* **Space:** a 60 × 40 m agricultural ring section: terraced planters, fruit trees, irrigation canals, a greenhouse ceiling with Earth visible beyond it. Choir growth has turned the trees into pale organ-pipe trees that hum.
* **Hush Charge boot** at the garden entrance (`RIG SUBSYSTEM RESTORED: HUSH`), with a tutorial pocket (4 Thralls clustered at a pump house).
* **Crescendo intro:** mid-arena, the garden's far wall bursts (`SPN_WallBurst`) and the first Crescendo charges through with only Thralls around it. Prompt: `CRESCENDOS can't turn while charging — DASH SIDEWAYS, then shoot the BACK`. Second prompt when it's charging: `HUSH freezes it mid-charge`.

### A04 — Spoke Shaft
* **Space:** a 200 m vertical shaft connecting the ring to the station's hub core — a tall cylinder with maintenance platforms, cable bundles and service lifts (dead).
* **Downbeat boot** at the shaft's base: `RIG SUBSYSTEM RESTORED: DOWNBEAT` — first use: a **Breakable Floor** grate over a flooded maintenance pit holding an ammo cache (and the way forward is *up*, so this is a tiny side-lesson). Then the ascent:
* **Swing Poles** introduced: a chain of 3 horizontal handrails across a gap (prompt `SWING POLES launch you forward`), then Harrow Anchors, Grip Walls, and a final Kick Pad to the hub-core door. Light enemies (2 Choristers on the walls, 3 Vespers).

### A05 — Hub Core: The Plectrum Chamber, ENC_M03_03
* **Space:** a spherical chamber (50 m diameter) at the station's center where the **ribbon** enters through a massive collar and runs straight down through the floor. Growing from the chamber wall: **the Plectrum** — a colossal bone arm (30 m) ending in a porcelain nail that strikes the ribbon every 4 seconds (visible light-wave travels down the ribbon each time; a deep "BWONNNG" that shakes the camera slightly).
* Platforms: a ring walkway around the collar (floor level), three floating maintenance platforms (6 m, 10 m, 14 m) linked by Kick Pads and Harrow Anchors.
* **Mod Crate: Riveter — Tack Scope** on the entry platform. Prompt: `[RMB] TACK SCOPE — weak points take massive damage`.
* **Objective:** destroy the Plectrum's **3 tendon joints** (glowing gold knots along the arm, 1500 HP each, ×2 from the Tack Scope's weak-point multiplier) during the fight. Each destroyed joint: the Plectrum's strike weakens (lower pitch). All three → the arm tears loose and falls onto the collar in a huge slow-motion collapse.
* **Overdrive boot:** after W1, the Rig surges: `RIG SUBSYSTEM RESTORED: OVERDRIVE`. The **Gain meter** appears; prompt: `Fill GAIN with aggressive, varied kills — then [V] OVERDRIVE`. An **Overdrive Surge** power-up spawns immediately on the central platform so every player experiences it once. Wren, first time on comms: "*Whoa — what did your suit just DO? My meters just clipped! Do it again! Wait — not near the ship!*"

### A06 — Climber Terminal
* A breather: the terminal hall (a departure lounge with seats and windows looking straight down the ribbon at Earth). Lund explains Waystation Nine and the Bridge. Board a **climber car**: the car's control room has a lever; pull it → the car releases.

### A07 — Climber Descent, ENC_M03_04 (moving arena)
* **Space:** the climber car's **open cargo deck** (30 × 20 m, cargo containers as cover, a 6 m crane tower in one corner) plus narrow **exterior catwalks** around the car (4 m wide) with Harrow Anchors on the ribbon clamps above. The car slides down the ribbon; the sky shifts from black to deep blue as the descent continues; the Aureole's bands pass by *overhead* like vast rainbows of light.
* **New enemies:** the first **Ophan** (flying heavy) circles the car; prompt when its maw opens: `Throw a FRAG into an OPHAN's open MAW`. **Wailers** appear from Hymnal-less "tear-drops" of light on the ribbon (scripted spawn: Wailers peel off the ribbon's gold waves).
* **Moving arena rules:** the arena is attached to the car (moving platform). Flyers use a `FlightVolume` parented to the car. The car's descent speed ramps visually but is *gated*: it arrives at Waystation Nine only when the Final wave dies (the skybox animation holds on a loop segment until then).

### A08 — Waystation Nine, ENC_M03_05
* **Space:** a ring-shaped station (200 m diameter) around the ribbon, with an inner **Bridge plaza** (60 × 60 m) where the Choir's **Bridge** clamps the ribbon: a 25 m tall structure of bone "saddle" and gold strings. Around it: hangar bays, a control tower, observation lounges (the optional Choir Mass is in the lounge wing).
* **Mod Crate: Static Rifle — Heat Burst** in the hangar before the plaza.
* **Objective:** the Bridge has **4 Saddle Nodes** (1200 HP each) that only become vulnerable when their gold strings are *plucked* (each string glows before vibrating — a 3 s window every 10 s). Destroying all 4 → the Bridge collapses; the ribbon falls silent; the Hymn over Halcyon **falters**; Radio Free Static breaks through for the first time (BEAT_M03_5).

### A09 — Roof Ride, ENC_M03_06
* The collapse damages Waystation Nine; the only way down is a damaged climber car. The Unsung leaps onto its **roof** (a 20 × 20 m platform with machinery, antenna masts and railings; wind; Earth rushing up; clouds). The brakes fail. **Survival encounter** (90 s): Vespers and Wailers attack in the howling wind; an Ophan at the end. When the timer ends, the car hits the clouds, then the ocean anchor platform.
* Clouds whip past; the sea and Halcyon appear through the clouds for the last 20 s.

### A10 — Anchor Platform
* `CIN_M03_Fall`: the car slams into the anchor platform's receiving dock; fire, twisted metal; the Unsung climbs out of the wreckage and looks at Halcyon across the water — the gold Ionian Spire towering from its center. Mission complete.

---

## 3. Encounters

```
ENC_M03_01  "Concourse"            Arena: A02 (80 m curving concourse, 25 m wide, 2 levels: street + shop mezzanines)   Seals: 2
  Music: MUS_M03_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x8, Trooper x3 (mezzanines)
  W2 AliveBelow(4):       Chorister x3 (Hymnfall), Bulwark x2
  Final W3 AliveBelow(3): Trooper x3, Thrall x8, Vesper x4
  Pickups: Shells L x1 (Gravedigger just acquired), Health S x4, Plating S x3
```

```
ENC_M03_02  "Hydroponic Garden"    Arena: A03 (60 x 40 m, 3 terraces, canals, trees as perches)   Seals: 2
  Music: MUS_M03_Combat_A → B       Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x8, Chorister x2
  W2 AliveBelow(3):       Crescendo x1 (Wall Burst, far wall), Thrall x6                  [Crescendo intro]
  Final W3 KilledTag(Crescendo): Chorister x3, Trooper x3, Thrall x6
  Pickups: Health M x1, Health S x4, Plating S x3, Shells S x2, Charge S x2
```

```
ENC_M03_03  "Plectrum Chamber"     Arena: A05 (sphere 50 m; ring walkway + 3 platforms)   Seals: 2
  Music: MUS_M03_Combat_B → C       Reward: 2 Brass + loot fountain
  Objective: destroy 3 tendon joints (tag `TendonJoint`; parallel to waves; waves continue until joints are destroyed AND final wave dies)
  W1 OnStart:             Chorister x4, Thrall x6
  -- Overdrive boot + Overdrive Surge power-up after W1 --
  W2 AliveBelow(3):       Crescendo x1, Vesper x6, Thrall x4
  W3 AliveBelow(4):       Bulwark x2, Cantor x1, Chorister x2
  W3b TimeElapsed(20s):   Thrall x6                                                           [resource trickle]
  Final W4 ObjectiveDestroyed(TendonJoint, 3) AND AliveBelow(4): Crescendo x1, Chorister x3, Thrall x6
  Pickups: Health M x2, Plating M x1, Rounds L x1, Shells L x1, Harrow Spool x3
  Power-up: Overdrive Surge (scripted, once)
```

```
ENC_M03_04  "Climber Descent"      Arena: A07 (moving: 30 x 20 m deck + catwalks)   Seals: n/a (moving platform)
  Music: MUS_M03_Descent            Reward: 1 Brass + loot fountain
  W1 OnStart:             Vesper x6, Thrall x4 (climb up from the car's lower decks)
  W2 AliveBelow(3):       Ophan x1 (Hymnfall from above)                                     [Ophan intro, with fodder only]
  W2b TimeElapsed(15s, W2): Thrall x4
  W3 KilledTag(Ophan):    Wailer x6 (peel off the ribbon), Chorister x2
  Final W4 AliveBelow(3): Vesper x8, Ophan x1, Thrall x4
  Pickups: Health S x6 (containers), Plating M x1 (crane top), Shells S x2, Charge L x1, Frag refill crate (resets Frag cooldown when touched)
```

```
ENC_M03_05  "The Bridge"           Arena: A08 Bridge plaza (60 x 60 m; raised saddle base 5 m; hangar balconies 8 m)   Seals: 4
  Music: MUS_M03_Combat_C           Reward: 2 Brass + big loot fountain
  Objective: 4 Saddle Nodes (tag `SaddleNode`) vulnerable during string-pluck windows
  W1 OnStart:             Trooper x4, Bulwark x2, Thrall x8
  W2 AliveBelow(4):       Crescendo x1, Chorister x3
  W3 AliveBelow(4):       Ophan x1, Vesper x6, Thrall x6
  W3b TimeElapsed(25s):   Thrall x6
  Final W4 ObjectiveDestroyed(SaddleNode, 4) AND AliveBelow(4): Crescendo x2, Cantor x1, Chorister x3, Thrall x6
  Pickups: Health M x2, Plating M x2, Shells L x1, Rounds L x1, Charge L x1, Harrow Spool x2
  Power-up: none
```

```
ENC_M03_06  "Roof Ride" (survival)  Arena: A09 (moving: 20 x 20 m roof)   Duration: 90 s timer
  Music: MUS_M03_Freefall           Reward: loot on landing
  Continuous: Vesper packs of 4 every 12 s; Wailer pairs every 8 s; at T-30 s: Ophan x1
  Pickups: Health S x4, Plating S x2, Charge S x2; Harrow Anchors on antenna masts for repositioning
  Notes: Enemies alive when the timer ends are destroyed in the crash (count as kills, no Gain).
```

**Optional:** `CM_M03_01` Choir Mass in the Observation Lounge wing of Waystation Nine (see `16_Optional_Content_and_Modes.md`): Chorister x6, Crescendo x1, Thrall x10 over 3 waves. Reward: 1 Brass + Heart-rate bonus (a Bloodrush pickup).

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M03_DropCoffin` | First Drop Coffin launch (reusable sequence) |
| `EVT_M03_RuizLocker` | Gravedigger reveal |
| `EVT_M03_CrescendoWall` | First Crescendo bursts through the garden wall |
| `EVT_M03_OverdriveBoot` | Overdrive unlock + guaranteed Surge |
| `EVT_M03_PlectrumFall` | The Plectrum tears loose and falls |
| `EVT_M03_Descent` | Climber car moving arena with skybox transition (space → upper atmosphere) |
| `EVT_M03_BridgeCollapse` | The Bridge collapses; Radio Free Static breaks through |
| `EVT_M03_RoofRide` | Brakes fail; 90 s survival; clouds; ocean |
| `EVT_M03_Crash` | `CIN_M03_Fall` |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Master: *"Geostationary"* by ORBITAL DECAY** | A02: a record shop on the concourse mezzanine, shutters jammed — the shop's back door is reached from A04 by backtracking along a Swing Pole secret route | A neon record sign flickering violet |
| S2 | **Heart Shard #2** | A03: top of the tallest organ-pipe tree; Harrow Anchor on a greenhouse strut above it | Violet glow in the canopy |
| S3 | **Effigy: Chorister** | A04: on a maintenance platform off the main ascent, reached by a hidden Swing Pole behind a cable bundle | Orange grip trim visible behind the cables |
| S4 | **Bootleg Tape #1** (Pit Trial: *"Gravedigger Only"*) | A06: under a seat in the departure lounge | A cassette player on the seat playing muffled music |
| S5 | **Rig Core** | A07: on the climber car's *underside* catwalk — during W1, drop over the rail onto a lower ledge (the car's service deck) | Violet light visible when looking over the railing |
| S6 | **Brass Cache #1** | A05: inside the ribbon collar's maintenance hatch (Downbeat the hatch) | Cracked hatch with orange fissures |
| S7 | **Brass Cache #2** | A08: control tower roof, via Grip Wall | — |
| S8 | **Sounding Station** | A08: hangar 3 mezzanine | Beeping |
| S9–S13 | **Archive Stones** | A01, A03, A05, A06, A08 | — |

**Archive entries:** `ARC_Loc_MeridianTether`, `ARC_Loc_ApexStation`, `ARC_Loc_WaystationNine`, `ARC_Obj_Plectrum`, `ARC_Char_Ruiz`, `ARC_Char_Wren`, `ARC_Enemy_Crescendo`, `ARC_Enemy_Ophan`, `ARC_Enemy_Wailer`, `ARC_Weapon_Gravedigger`, `ARC_Rig_Hush`, `ARC_Rig_Overdrive`, `ARC_Rig_Downbeat`, `ARC_Tech_DropCoffin`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Freeze a charging Crescendo with a Hush Charge and kill it before the Hush ends |
| 2 | Drop an Ophan with a Frag Charge in its maw |
| 3 | Kill 10 enemies during a single Overdrive |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M03_Explore` — "**Spin Gravity**" | Station interiors | Hypnotic 7/8 riff, clean + distorted guitars, the ribbon's "BWONNNG" as a rhythmic element |
| `MUS_M03_Combat_A` — "**Concourse**" | ENC_01–02 | 155 BPM |
| `MUS_M03_Combat_B/C` — "**Plectrum**" | ENC_03, ENC_05 | Heavy; the Plectrum strike is quantized to the downbeat |
| `MUS_M03_Descent` — "**The Long Way Down**" | ENC_04 | Soaring, post-metal |
| `MUS_M03_Freefall` — "**Terminal Velocity**" | ENC_06 | Fastest track so far (190 BPM), wind noise layered |
| First **Overdrive stem** | ENC_03 | The first guitar solo the player "triggers" |

---

## 8. Art & Lighting

* **Palette:** station interiors in Concord off-white, grey and safety orange; the garden in sickly green overtaken by pale Choir growth; the Plectrum chamber in bone-white with gold light pulsing down the ribbon; exteriors: black space → deep blue → cloud white → ocean blue-grey.
* **Signature visuals:** corridors curving up into the distance (spin gravity), the ribbon's pulses of gold light, the Aureole's bands passing overhead during the descent, Earth growing larger.
* **Performance note:** the descent skybox is a sphere with animated layers; do not stream heavy geometry during the moving arena.

---

## 9. New Assets Required (P0/P1)

`SK_WPN_Gravedigger`, `SM_HushCharge`, `SK_Crescendo`, `SK_Ophan`, `SK_Wailer`, `BP_DropCoffin` (+ launch sequence `LS_DropCoffin_Launch`), `BP_SwingPole`, `BP_BreakableFloor`, Apex Station ring kit (curved corridor modules — curvature radius 500 m), hydroponic garden set, organ-pipe tree, spoke shaft kit, `SM_Plectrum` (destructible hero asset with 3 joints), ribbon mesh (`SM_TetherRibbon` + pulse material), climber car (`SM_ClimberCar` — deck, catwalks, roof variants), Waystation Nine ring kit, `SM_Bridge_Saddle` (destructible hero asset), `BP_ChoirMass`, descent sky system (`BP_Sky_Descent`), Mod Crate (`BP_ModCrate`).
