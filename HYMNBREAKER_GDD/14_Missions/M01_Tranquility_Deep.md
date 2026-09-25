# M01 — TRANQUILITY DEEP

| | |
|---|---|
| **Act** | I — First Noise |
| **Location** | Tranquility Deep, Concord Xenoacoustic Research Site, 400 m beneath Mare Tranquillitatis |
| **Kit** | `BRU` (Concord Brutalist) + light `CHOIR` overlay (0% → 30%) |
| **Target duration** | 55 min (critical path ~32 min) |
| **Priority** | **P0 — Vertical Slice** |
| **Story beats** | BEAT_M01_1 → BEAT_M01_7 |
| **New** | Movement, Surge, melee, Breakdown, Harrow (Shred + Grapple), Breacher, Riveter, Red Fuse; enemies Thrall, Trooper, Chorister; Harrow Anchors, Grip Walls |
| **Landmark** | The Surface Lift shaft — a 300 m vertical shaft with a pale light at the top, visible through windows in several areas |

---

## 1. Overview

The tutorial mission and the game's first impression. Its job: **teach the resource loop without ever stopping the action**, establish the tone (silence → metal; human brutalism → Choir beauty), and end on the image of Earth wearing the Aureole.

**Player experience goals:**
1. The first 60 seconds — silence, awakening, the first chord — must give chills.
2. By minute 10, the player has punched, executed, shotgunned, Shredded and grappled.
3. By minute 25, the first true Choir-forms (Choristers) arrive in a pillar of light and the music explodes.
4. The final arena (Pump Hall) is a genuine test of the loop.

**Rules for this mission:** No mission challenges gated behind unavailable tools. Deaths should be rare (tutorial). Lullaby/Unplugged tutorial prompts are more verbose.

---

## 2. Level Flow

```
[A01 Silent Vault] → [A02 Containment Ring] ─grapple gap─→ [A03 Observation Gallery]
                                                              │
                                                     [ENC_01 Sensor Hall]
                                                              │
                             ┌──────────── [A04 Research Labs, Wing B] ──(Red Fuse)──┐
                             │   (ENC_02 Acoustics Lab)                              │
                        [secret: Archive]                                     [A05 Central Atrium]
                                                                              (ENC_03 First Hymnfall)
                                                                                      │
                                                                         [A06 Maglev Station + ride]
                                                                                      │
                                                                         [A07 Security & Armory]
                                                                              (ENC_04 Checkpoint)
                                                                                      │
                                                                         [A08 Pump Hall] (ENC_05)
                                                                                      │
                                                                         [A09 Surface Lift → Dome] (CIN)
```

### A01 — The Silent Vault (Containment Chamber)
* **Space:** circular chamber, 20 m diameter, 15 m tall. Walls lined with grey acoustic foam tiles (human imitation of anechoic wedges) and sensor arrays. Eight enormous **Resonance Hammer** emitters (horn-shaped ultrasonic projectors, 3 m long) point at the center, some still glowing white-hot, some cracked.
* **The Vault:** a black monolith 400 × 250 × 200 cm on a steel cradle, now shattered open like an egg; its material is perfectly matte black (`M_VaultBlack` — absorbs light; subtle iridescence at grazing angles). Shards of it litter the floor; they "suck" sound (local audio low-pass volume around each shard).
* **Script:** `CIN_M01_Awakening` → control. Two Tuned researchers attack. **Prompts:** `[F] MELEE` → after 2 punches the first Thrall **Falters** (ember glow) → `[F] BREAKDOWN — Execute FALTERING enemies to gain HEALTH`. The second Thrall repeats the lesson without prompts.
* **Player starts at 50 Health, 0 Plating** so the Breakdown's Health drop is felt (red orbs fill the bar).
* **Exit:** the chamber's blast door is jammed half-open (Surge prompt: `[Shift] SURGE` to dash under the falling door as it slams — a scripted, fail-safe dash moment: if the player doesn't dash, the door stops halfway and waits).

### A02 — Containment Ring
* **Space:** a ring corridor (8 m wide, 6 m tall) circling the Vault chamber, with windows into it. Emergency red lighting, flickering fluorescents, water on the floor from burst cooling pipes. Dead CDF guards and researchers; a Static Collar on a corpse still quietly playing music (environmental storytelling, and a lesson: noise = protection).
* **Beat:** the **Breacher** lies in a dead guard's hands at a barricade (`PKP_Weapon_Breacher`). Prompt `[LMB] FIRE`. 3 Thralls stagger around the corner — shotgun practice.
* **Harrow unlock:** further on, the Rig boots its Harrow (`RIG SUBSYSTEM RESTORED: HARROW`). A Thrall shambles in alone → prompt `[E] HARROW — SHRED fodder for AMMO`. The player's Breacher is set to 2/24 Shells at this moment (scripted) so the ammo burst matters.
* **Collapsed section:** the ring's floor has fallen into the **Cooling Pit** (18 m gap, 12 m drop into water — void rules). Two **Harrow Anchors** (overhead crane hooks with ember cores) span the gap. Prompt `[E] HARROW — GRAPPLE to anchors`. Second anchor slingshots the player onto a ledge.
* **Grip Wall:** a 6 m tall wall of rusted chain-link maintenance mesh with orange trim leads up to the Observation Gallery. Prompt: `Jump into GRIP WALLS to climb`.
* **Secret S1 (Archive + Brass):** see §5.

### A03 — Observation Gallery & ENC_M01_01 "Sensor Hall"
* **Space:** a long gallery overlooking the Vault chamber through 6 m tall armored glass. At the end, the **Control Annex** window: Dr. Lund is visible behind thick glass, sealed inside, waving, talking over the PA (`COM_M01_01`–`_04`). He can't open his door until power is restored to Wing B. "*Please — the labs. Wing B. There's a power junction. And a Red Fuse for the maglev door, in the stores.*"
* **Sensor Hall (arena):** a 20 × 24 m hall of sensor racks and server towers (cover), 7 m ceiling, a mezzanine catwalk on one side (3 m up, reachable by stairs and by a jump+mantle). First locked arena — the **Choir Seals** grow over both doors (tutorial prompt: `The CHOIR has SEALED the exits. Kill everything.`).

### A04 — Research Labs, Wing B
* **Space:** a two-floor lab wing: offices, acoustics labs, anechoic test rooms (small rooms with grey foam wedges — foreshadowing the Quietus), a server room, a cafeteria with overturned tables, a stores room.
* **Story:** spectrograms of the 2194 Ringing on whiteboards; a whiteboard with "IT'S A HEARTBEAT???" circled; Lund's office with 26 years of notes; a child's drawing on a desk. Archive Stones here explain the Vault.
* **Power Junction:** a wall panel; interact → lights come up across the wing (ambient hum returns) and alarms start: Thralls pour out of the dormitories → `ENC_M01_02`.
* **Red Fuse:** in the stores room, locked behind a mesh cage opened by the power restoration; a short Harrow-anchor climb to reach it on a high shelf-rack (teaches vertical grapple).

### A05 — Central Atrium & ENC_M01_03 "First Hymnfall"
* **Space:** the facility's heart — a 30 × 30 m, 18 m tall atrium with 3 tiers of balconies, a central dead fountain, a huge **skylight** far above (a light-well to the lunar surface, 400 m up) through which faint white-gold light falls — the Hymn is louder here. Concrete "CONCORD XENOACOUSTICS" relief lettering.
* **Script:** entering triggers the first **Hymnfall**: the light from the skylight intensifies into a pillar; a choral swell; **2 Choristers** descend and land in crouches, petals opening — and the combat music detonates into full metal for the first time (`MUS_M01_Combat_B` intro stinger). Lund: "*Those aren't— those were never human. God. They're coming down from the surface.*"

### A06 — Maglev Station & Ride
* **Space:** a platform (40 m long), a maglev pod (3-car, open interior). Red Fuse door. Enter pod → a **70-second ride** through the lunar rock tunnels and a vast natural cavern (where Choir growth — pale organ-pipe clusters — is spreading on the rock like frost). **No combat** (breather). Lund talks: who he is, the Vault, "*they're afraid of you, and that's all I have left*". Player can walk around inside the moving pod; a Static Collar and an Archive Stone are on a seat.
* Mid-ride: the pod passes the **Surface Lift shaft** (landmark) — a glimpse up to the pale light.

### A07 — Security & Armory, ENC_M01_04 "Checkpoint"
* **Space:** a CDF security checkpoint (turnstiles, guard booths, blast shutters), then the armory. The armory's rack holds the **Riveter** (`PKP_Weapon_Riveter`) — Lund: "*Industrial rivet gun. The guards modified them. I didn't ask.*"
* Headshot tutorial prompt: `[Riveter] HEADSHOTS deal bonus damage`.
* Checkpoint arena: the Tuned garrison — Troopers on a guard tower and catwalks; Choristers on the walls.

### A08 — Pump Hall, ENC_M01_05 (mission finale arena)
* **Space:** a vast hall of water-circulation pumps (40 × 35 m, 20 m tall) with 3 tiers: **Floor** (pump housings as cover, water channels), **Mid catwalks** (6 m, ring around the hall), **Upper gantries** (12 m, two bridges crossing the hall). Harrow Anchors on the pump cranes (3). Grip Walls on two pump towers. A giant pipe spans the hall at 12 m (walkable). Choir growth covers the north wall (30% overlay).

```
          N (Choir-grown wall; Chorister perches)
   ┌─────────────────────────────────────────────┐
   │  [P1]      ══════ upper bridge ══════   [P2] │  P = pump tower (Grip Wall on P1, P3)
   │     ╔═══ mid catwalk ring (6 m) ═══╗         │  A = Harrow Anchor (crane hooks)
   │ A1  ║  [pump]   ~~~~   [pump]      ║   A2    │  ~ = water channel (shallow, no hazard)
   │     ║        ~~~~~~~~~~~~          ║         │
 W │     ║  [pump]   ~~~~   [pump]  H   ║         │ E → Surface Lift door (sealed)
   │     ╚══════════════════════════════╝         │
   │  [P3]      ══════ upper bridge ══════   [P4] │
   │                   A3                          │
   └──────────────[S] entrance (south)──────────────┘
   H = Health M pickup on the central pump top (exposed)
```

### A09 — Surface Lift & Observation Dome
* The lift (a 12 × 12 m freight platform) rises 300 m in 40 s — no combat; Lund talks; the Hymn grows louder; the lift's lights turn gold as it nears the top. The doors open into the **Observation Dome** → `CIN_M01_Aureole` → mission complete.

---

## 3. Encounters

All values Amplified. `→` = spawn method.

```
ENC_M01_01  "Sensor Hall"        Arena: A03 (20 x 24 m, mezzanine)     Seals: 2
  Music: MUS_M01_Combat_A (intro-level intensity)     Reward: loot fountain
  W1 OnStart:          Thrall x4 (Emerge from server racks overgrown with Choir growth)
  W2 AliveBelow(2):    Thrall x3 (Drop from mezzanine), Trooper x1 (mezzanine hold point)
  Final W3 AliveBelow(1): Trooper x2 (Drop from ceiling vents), Thrall x2
  Pickups: Health S x3, Shells S x2
  Notes: First Trooper. Tutorial prompt when a Trooper is on screen: "Tuned soldiers fire from range — keep moving".
```

```
ENC_M01_02  "Acoustics Lab"      Arena: A04 cafeteria + lab corridor (25 x 18 m + 30 m corridor loop)   Seals: 3
  Music: MUS_M01_Combat_A                             Reward: 1 Brass + loot fountain
  W1 OnStart:          Thrall x6 (Emerge from dormitory doors, staggered)
  W2 AliveBelow(3):    Trooper x2 (cafeteria balcony), Thrall x4
  Final W3 AliveBelow(2): Thrall x6 (both ends of the corridor loop), Trooper x1
  Pickups: Health S x4, Plating S x2, Shells L x1
  Notes: The corridor loop teaches circle-strafing and "run a circuit". Prompt if the player is low on ammo: "SHRED fodder with the HARROW for AMMO".
```

```
ENC_M01_03  "First Hymnfall"     Arena: A05 Atrium (30 x 30 m, 3 tiers, 18 m tall)   Seals: 3
  Music: MUS_M01_Combat_B (full metal debut)          Reward: 1 Brass + loot fountain
  W1 OnStart (scripted):  Chorister x2 (Hymnfall from skylight light-pillar, center)
                          Thrall x4 (Emerge, ground tier)
  W2 AliveBelow(3):       Chorister x1 (Hymnfall, 2nd tier balcony), Trooper x2 (3rd tier), Thrall x4
  Final W3 AliveBelow(3): Chorister x2 (Emerge from Choir growth on west wall), Thrall x6
  Pickups: Health M x1 (fountain top, exposed), Health S x3, Shells S x3, Plating S x2
  Notes: Choristers use cyan notes only (no gold notes until M02). Prompt: "CHORISTERS climb walls — use the HARROW to rip them down."
```

```
ENC_M01_04  "Checkpoint"         Arena: A07 (35 x 20 m, guard tower 5 m, catwalks 4 m)   Seals: 2
  Music: MUS_M01_Combat_B                             Reward: 1 Brass + loot fountain
  W1 OnStart:          Trooper x4 (guard tower + catwalks), Thrall x4
  W2 AliveBelow(3):    Chorister x2 (Hymnfall, center), Trooper x2 (Drop through shutters)
  Final W3 AliveBelow(2): Chorister x2, Thrall x6, Trooper x2
  Pickups: Rounds L x1 (Riveter introduced just before), Shells S x2, Health S x4, Plating M x1 (tower top)
```

```
ENC_M01_05  "Pump Hall" (FINALE) Arena: A08 (40 x 35 m, 3 tiers, 20 m tall)   Seals: 2
  Music: MUS_M01_Combat_C (finale)                    Reward: 2 Brass + big loot fountain
  W1 OnStart:             Thrall x8 (Emerge: floor, spread), Trooper x3 (mid catwalk)
  W2 AliveBelow(4):       Chorister x3 (Hymnfall: upper bridges), Thrall x4
  W2b TimeElapsed(20s):   Thrall x4 (Emerge)                                  [resource trickle]
  W3 AliveBelow(4):       Trooper x4 (Drop: upper gantry), Chorister x2 (Emerge: north wall)
  Final W4 AliveBelow(3): Chorister x4 (Hymnfall: 2 floor, 2 mid), Thrall x8, Trooper x2
  Pickups: Health M x2 (central pump top; upper bridge), Plating M x1, Shells L x2, Rounds L x1, Harrow Spool x2
  Notes: The biggest test of the loop so far. Max alive 16. Threat cap 14.
```

**Pre-placed (non-arena) enemies:** A02: 3 Thralls + 1 tutorial Thrall; A04 corridors: 2 Thralls wandering (ambient); A06: none; A07 approach: 2 Troopers patrolling (can be ambushed).

---

## 4. Set Pieces & Scripted Events

| ID | Where | Description |
|---|---|---|
| `EVT_M01_Awaken` | A01 | `CIN_M01_Awakening` |
| `EVT_M01_BlastDoor` | A01 exit | Door slams; forgiving scripted dash |
| `EVT_M01_HarrowBoot` | A02 | Rig boot text + tutorial Thrall + ammo set to 2 |
| `EVT_M01_LundWindow` | A03 | Lund waves through the Annex glass; PA dialogue |
| `EVT_M01_PowerUp` | A04 | Power restored: lights cascade on, alarm, Thralls pour out |
| `EVT_M01_Hymnfall` | A05 | First Hymnfall (skylight pillar), music debut |
| `EVT_M01_MaglevRide` | A06 | 70 s moving pod; the cavern of Choir growth; shaft glimpse |
| `EVT_M01_Lift` | A09 | 40 s lift ride; lights turn gold |
| `EVT_M01_Dome` | A09 | `CIN_M01_Aureole` |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Brass Cache #1** (1 Brass) + Archive Stone "Containment Protocol 7" | A02: under the collapsed ring, on a ledge 4 m below the grapple path — drop down from the first anchor onto a pipe, then walk into a maintenance alcove | Violet light leaking from the alcove; visible while grappling |
| S2 | **Effigy: Thrall** (`COL_Effigy_01`) | A03: on top of the Sensor Hall's tallest server tower (mantle from the mezzanine railing) | Violet glint on the tower top |
| S3 | **Master: *"Dead Frequencies"* by the band SIGNAL LOSS** (`COL_Master_M01`) | A04: Lund's office — behind a sliding bookcase (interact) | A record player on his desk with no record; a note: "Borrowed my copy of Dead Frequencies — K." |
| S4 | **Sounding Station** | A04: server room, second floor, via a Grip Wall in the lab courtyard | Orange Static sonar rig, beeping |
| S5 | **Rig Core** (`COL_RigCore_M01`) | A05: Atrium top tier — a broken balcony section: Harrow Anchor on the skylight frame reveals a hidden maintenance ledge behind the "CONCORD" relief letters | Violet light behind the letter "O" |
| S6 | **Brass Cache #2** | A07: inside the guard tower's locked booth — breakable window (shoot it) | Cracked glass, violet tag on the booth |
| S7–S10 | **Archive Stones** (auto-collected data slates) | A02 (1), A04 (2), A06 in the pod (1) | — |

**Archive entries unlocked in M01:** `ARC_Loc_TranquilityDeep`, `ARC_Obj_SilentVault`, `ARC_Log_Lund_2194`, `ARC_Tech_ResonanceHammer`, `ARC_Tech_StaticCollar`, `ARC_Enemy_Thrall`, `ARC_Enemy_Trooper`, `ARC_Enemy_Chorister`, `ARC_Weapon_Breacher`, `ARC_Weapon_Riveter`, `ARC_Rig_Harrow`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Perform 15 Breakdowns |
| 2 | Shred 3 enemies within 10 seconds |
| 3 | Kill a Chorister with a Riveter headshot while it is climbing a wall |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| **Silence** | Cold open | 6 s of true digital silence, then the chord |
| `MUS_M01_Explore` — "**Room Tone**" | A02–A04 | Sparse: sub drones, detuned guitar harmonics, distant choir bleeding through walls |
| `MUS_M01_Combat_A` — "**First Blood in the Vacuum**" | ENC_01, ENC_02 | Mid-intensity groove, 140 BPM |
| `MUS_M01_Combat_B` — "**Hymnfall**" | ENC_03 (debut), ENC_04 | The full band; intro stinger synced to the Hymnfall pillar, 160 BPM, Drop A |
| `MUS_M01_Maglev` | A06 | Ambient; a lone clean guitar arpeggio (the main theme's first appearance) |
| `MUS_M01_Combat_C` — "**Pump Hall**" | ENC_05 | Finale intensity |
| Ambience | All | Facility hum, water drips, alarm loops (Wing B), distant choir growing louder as you ascend |

---

## 8. Art & Lighting

* **Palette:** cold concrete grey, sodium orange work-lights, red emergency strobes, fluorescent white; the Choir's pale gold-white light creeping in from above (strongest in A05 and A09).
* **Key props:** Resonance Hammer emitters, the Vault monolith & shards, sensor racks, acoustic foam tiles, lab whiteboards with spectrograms, CDF barricades, Static Collars on corpses, Concord stencil signage ("SECTOR B — XENOACOUSTICS", "HEARING PROTECTION MANDATORY").
* **Choir overlay:** 0% (A01–A02), 10% (A03–A04), 30% (A05, A08) — organ-pipe clusters growing from ceiling vents, porcelain crust on walls, a few bone lattices.
* **Landmark:** the Surface Lift shaft (visible from A03 windows, A06 ride, A08 east door).

---

## 9. New Assets Required (P0)

`SM_Vault_Monolith` (+ shatter pieces `SM_Vault_Shard_A–F`), `M_VaultBlack`, `SM_ResonanceHammer`, `SK_Thrall` (+6 clothing variants), `SK_Trooper`, `SK_Chorister`, `SK_Unsung_Arms`, `SK_Unsung_Body`, `SK_WPN_Breacher`, `SK_WPN_Riveter`, `SK_Harrow` + chain, `BP_HarrowAnchor` (crane-hook variant), `BP_GripWall` (mesh variant), `BP_ChoirSeal`, `BP_SoundingStation`, `PKP_Fuse_Red`, maglev pod (`SM_MaglevPod` + track kit), freight lift, BRU kit (walls, floors, doors, stairs, catwalks, railings, pumps, server racks, lab furniture, cafeteria props), CHOIR overlay starter set (organ-pipe cluster ×3, porcelain crust decals ×4, bone lattice ×2), Earth + Aureole skybox (`BP_Sky_EarthAureole`), Observation Dome glass set.
