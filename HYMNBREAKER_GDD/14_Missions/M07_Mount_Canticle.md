# M07 — MOUNT CANTICLE

| | |
|---|---|
| **Act** | II — The Tuned Earth |
| **Location** | **The Seminary of Mount Canticle** — the Consonance's mountain headquarters: white marble and brutalist concrete terraces carved into a peak above the clouds |
| **Kit** | `CULT` + `CHOIR` 20% → 50% (the cult's architecture already *looks* Choir-like; growth is refined and deliberate — gold inlay, cultivated organ-pipe hedges) |
| **Target duration** | 80 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M07_1 → BEAT_M07_5 |
| **New** | Lock Salvo & Storm Node mods, *Noise Gate* pedal; human cultist enemies **Acolyte** & **Zealot**; **Siren**; mini-boss **The Tenebrae (1)**; Consonance dropship spawns |
| **Landmark** | **The Great Auditorium** — a vast white dome shaped like an ear, crowning the peak; a golden ring-gate hovering above it |

---

## 1. Overview

The player assaults the heart of the human cult. For the first time, enemies are **human, sapient and voiced**: Acolytes pray, shout warnings, beg, and die screaming hymns. The seminary is serene and beautiful — reflecting pools, cloisters, libraries full of Signal transcriptions — and the violence here should feel transgressive and weighty. At the summit, **Aurelia Voss** waits in person.

**Experience goals:** a tonal shift (human enemies, a place of faith); learning the Siren's pull; the first mini-boss; and a quiet, unsettling conversation with the villain that ends with her stepping through a gate — and the player smashing the broadcast console in frustration.

**Content sensitivity:** Consonance faith is fictional; no real-world religious symbols, clothing or texts. Its iconography is rings, waveforms, tuning forks and the Consonance Seal.

---

## 2. Level Flow

```
[A01 Pilgrim Road] → [A02 Pilgrims' Gate & Grand Stair] ENC_01 (Acolyte/Zealot intro; dropship)
   → [A03 Terraces of Contemplation] ENC_02
   → [A04 Scriptorium] (Lock Salvo, Storm Node mods; lore)
   → [A05 Resonance Cisterns (flooded catacombs)] ENC_03 (Siren intro)   (+CM_M07_01 in the ossuary)
   → [A06 The Great Auditorium] MINI-BOSS: The Tenebrae (retreats at 50%)
   → [A07 Cloister of Voices] ENC_04
   → [A08 Precentor's Sanctum] CIN_M07_Aurelia → ENC_05 FINALE "Zealots" → console smash → exit
```

### A01 — Pilgrim Road
* The Drop Coffin lands on a mountain road above the clouds; abandoned pilgrim buses and prayer-flag-like banners of gold ribbons; Consonance waystation shrines (a tuning fork on a plinth, offerings of Static Collars *surrendered* by converts — piles of them). The seminary rises in white tiers ahead.
* A few Thralls — ex-pilgrims, fully tuned — wander the road.

### A02 — Pilgrims' Gate & Grand Stair, ENC_M07_01
* **Space:** a monumental stair (60 m wide, 25 m rise over 120 m, with 3 landings) up to a gate of white stone. Statues of Aurelia line it. A **Consonance dropship** (white-and-gold VTOL) delivers Acolytes on ropes (`SPN_Dropship`).
* **Acolyte/Zealot intro:** Acolytes shout (`BRK_Acolyte_*`): "*It's here — the Wrong Note!*", "*Sing with us!*", "*Chime out!*"; the Zealots sprint down the stairs screaming. Prompt on first Chime Grenade: `CHIME GRENADES ring 3 times — COUNTER them back`.

### A03 — Terraces of Contemplation, ENC_M07_02
* **Space:** stepped garden terraces (4 levels, 5 m apart) with long reflecting pools (shallow — walkable), cultivated organ-pipe hedges, gold-leafed trees, meditation pavilions, and small bell-towers. Arena on the central terraces (60 × 50 m).

### A04 — Scriptorium
* **Space:** a three-level library with endless shelves of bound **Signal transcriptions** — musical notation copied by hand by devotees (millions of pages); reading desks; a central **Resonance Lectern** (a machine playing the Signal softly — the Unsung can destroy it: +1 Archive entry, the Hymn in the level drops in volume for the rest of the mission).
* **Mod Crates:** Hammerfall — **Lock Salvo**; Arc Coil — **Storm Node**.
* **Lore:** Archive Stones with Consonance scripture (the "Canticles"), Aurelia's early sermons, lists of converts' names being crossed out and re-written as musical notes.
* Light combat only (Acolyte patrols — can be ambushed; they're praying at desks when first seen).

### A05 — Resonance Cisterns, ENC_M07_03
* **Space:** vast flooded catacomb cisterns beneath the seminary (the cult's "tuning pools" where initiates are immersed while the Signal plays through the water). Pillared halls (columns every 8 m), walkways above black water (void), stone islands, candle-like gold light orbs floating over the water.
* **Siren intro:** a **Siren** rises from the water. Prompt: `SIRENS pull you in — SHOOT THE THROAT or HARROW it while it CALLS`. Introduced with Thralls only; the water makes the pull scary (it drags you toward a void edge — but the Siren always stands on a platform, so the pull ends on solid ground).
* **Optional:** `CM_M07_01` in the ossuary chamber (walls of neatly stacked porcelain skulls of converts).

### A06 — The Great Auditorium: MINI-BOSS THE TENEBRAE (1)
* **Space:** a 90 m wide semicircular amphitheater under the ear-shaped dome: 12 tiers of white seating descending to a stage; four chanter platforms (for the Choir Shield's Acolyte cantors) on the upper tiers; aisles and vomitories as routes; Harrow Anchors on the dome's ribs; Kick Pads on the stage.
* **Fight:** `10_Bosses.md` §2 (M07 version: 6000 HP, **retreats at 50%** — it rises through the dome's oculus). Thale's voice over its PA: "*CDF General Idris Thale, formerly. Choirmaster now. I watched you tear my soldiers apart on the Moon. You're magnificent. You're also noise.*"
* Resource adds: Acolytes & Thralls from the vomitories.

### A07 — Cloister of Voices, ENC_M07_04
* **Space:** a square cloister (50 × 50 m) around a courtyard garden: arcades on two floors, a fountain-bell at the center, four Cantors "conducting" from the arcade corners. The upper arcade is reachable via Grip Walls on the columns and a Kick Pad in the garden.

### A08 — Precentor's Sanctum
* **Space:** a circular white chamber (25 m) with a shallow reflecting pool, a gold ring-gate humming behind a dais, and a broadcast console (the Consonance's master transmitter). Surrounding it: the **Sanctum Halls** (a ring of galleries, 20 m wide, looping around the chamber — the finale arena).
* **Script:** `CIN_M07_Aurelia` (she steps into the gate). → Zealots pour in: `ENC_M07_05`. → After the fight, the console is interactable: `GST_ScreenSmash`-style destruction (the Unsung rips it from its mount and throws it into the pool). Lund recovers the Consonance star-charts: the **seven Cantor Spires**.

---

## 3. Encounters

```
ENC_M07_01  "Grand Stair"          Arena: A02 (60 m wide stair, 3 landings, gate terrace)   Seals: 2
  Music: MUS_M07_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Acolyte x6 (Dropship), Thrall x6                                  [Acolyte intro]
  W2 AliveBelow(4):       Zealot x4 (sprint down from the gate), Acolyte x4
  Final W3 AliveBelow(3): Acolyte x6 (Dropship #2), Bulwark x2, Chorister x2
  Pickups: Health S x6, Plating S x4, Shells L x1, Rounds S x2
```

```
ENC_M07_02  "Terraces"             Arena: A03 (60 x 50 m, 4 terraces 5 m apart, pools, pavilions)   Seals: 3
  Music: MUS_M07_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Acolyte x6, Zealot x3, Thrall x6
  W2 AliveBelow(4):       Seraph x1, Cantor x1, Acolyte x4
  W3 AliveBelow(4):       Bellwether x1, Zealot x4
  Final W4 AliveBelow(3): Canon x1, Acolyte x6, Chorister x3
  Pickups: Health M x1, Health S x4, Plating M x1, Ordnance L x1, Charge S x2
```

```
ENC_M07_03  "Resonance Cisterns"   Arena: A05 (pillared hall 60 x 40 m; walkways & islands over void water)   Seals: 2
  Music: MUS_M07_Combat_B           Reward: 1 Brass + loot fountain
  W1 OnStart:             Siren x1, Thrall x8                                                [Siren intro]
  W2 KilledTag(Siren) OR AliveBelow(3): Chorister x4 (pillars), Vesper x6
  Final W3 AliveBelow(4): Siren x1, Zealot x4, Acolyte x4, Ophan x1
  Pickups: Health S x6, Plating S x4, Charge L x1, Ordnance S x2, Harrow Spool x2
```

```
BOSS_Tenebrae_1  "The Great Auditorium"  Arena: A06   (see 10_Bosses.md §2)
  Music: MUS_BOSS_Tenebrae
  Resource adds every 25 s: Acolyte x3 or Thrall x4 (alternating) from vomitories
  Chanter respawns per boss rules
  Ends at 50% HP (Tenebrae retreats through the oculus) → loot fountain + 2 Brass
```

```
ENC_M07_04  "Cloister of Voices"   Arena: A07 (50 x 50 m; 2 arcade floors 5 m; courtyard)   Seals: 4
  Music: MUS_M07_Combat_C           Reward: 1 Brass + loot fountain
  W1 OnStart:             Cantor x2 (arcade corners), Bulwark x2, Acolyte x6
  W2 AliveBelow(5):       Siren x1, Zealot x4, Thrall x6
  W3 AliveBelow(4):       Cantor x2, Bellwether x1, Acolyte x4
  Final W4 AliveBelow(3): Crescendo x2, Seraph x1, Zealot x4, Acolyte x4
  Pickups: Health M x1, Health S x6, Plating M x1, Charge L x1, Shells L x1
  Power-up: TEMPO (courtyard bell-fountain top)
```

```
ENC_M07_05  "Sanctum Halls" (FINALE)  Arena: A08 ring galleries (loop, 20 m wide, 130 m circumference; inner windows to the sanctum)   Seals: 4
  Music: MUS_M07_Combat_C (finale)   Reward: 2 Brass + big loot fountain
  W1 OnStart:             Zealot x8, Acolyte x6
  W2 AliveBelow(5):       Siren x2, Chorister x4
  W3 AliveBelow(5):       Canon x1, Cantor x1, Bulwark x3, Acolyte x6
  W3b TimeElapsed(25s):   Zealot x4, Thrall x6
  Final W4 AliveBelow(4): Bellwether x2, Seraph x1, Zealot x6, Acolyte x4
  Pickups: Health M x2, Plating M x2, ammo L x1 each type, Harrow Spool x3
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M07_Dropship` | Consonance dropships deploy Acolytes on ropes |
| `EVT_M07_Lectern` | Optional: destroy the Resonance Lectern → the level's Hymn volume drops |
| `EVT_M07_Tenebrae` | Mini-boss intro (it rises from beneath the stage) and retreat (through the oculus) |
| `EVT_M07_Aurelia` | `CIN_M07_Aurelia` |
| `EVT_M07_Console` | Smash the master transmitter; star-charts recovered |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Mute Cell #3** | A01: a waystation shrine's collar-pile — Distort the Choir crust over it to reveal a floor hatch | Violet crystal among the collars |
| S2 | **Pedal: Noise Gate** | A04: top shelf of the Scriptorium's upper level — Harrow Anchor on the skylight frame | Violet glow among the books |
| S3 | **Bootleg Tape #3** (Pit Trial: *"No Shooting"* — melee & abilities only) | A05: on a stone island reachable only by a Siren's pull (let a Siren pull you across the water!) — or with an expert double-dash | A cassette player on an altar across the water |
| S4 | **Effigy: Acolyte** | A03: inside a meditation pavilion on the lowest terrace (breakable screen) | — |
| S5 | **Master: *"Sermon for the Deaf"* by THE HERETICS** | A07: the cloister bell-tower top | Faint music from above |
| S6 | **Reprise** | A06: the dome's oculus rim (Harrow Anchor chain along the dome's ribs) — reachable after the Tenebrae retreats | Violet glow on the rim |
| S7 | **Rig Core** | A05: the ossuary behind the optional Choir Mass | — |
| S8 | **Brass Cache #1** | A02: under the grand stair's first landing (Downbeat a cracked slab) | Orange fissures |
| S9 | **Brass Cache #2** | A08: the sanctum's reflecting pool — after Aurelia leaves, wade to the dais; the cache is in a hidden drawer | — |
| S10 | **Sounding Station** | A04: Scriptorium's archivist office | — |
| S11–S16 | **Archive Stones** | A01, A02, A04 (×2), A05, A08 | — |

**Archive entries:** `ARC_Loc_MountCanticle`, `ARC_Fac_Consonance_Hierarchy`, `ARC_Doc_Canticles_I–III`, `ARC_Char_Thale`, `ARC_Enemy_Acolyte`, `ARC_Enemy_Zealot`, `ARC_Enemy_Siren`, `ARC_Obj_SevenSpires`, `ARC_Obj_Octave`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Counter 5 Chime Grenades back at Acolytes |
| 2 | Interrupt a Siren's Call with the Harrow 3 times |
| 3 | Kill all four Tenebrae chanters within 10 seconds of each other at least once |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M07_Explore` — "**Vespers**" | Exterior, Scriptorium | Sacred choir (mixed voices) singing a Consonance hymn; the band slowly bleeds in as the player kills |
| `MUS_M07_Combat_A` — "**Heresy**" | ENC_01–02 | 170 BPM, blackened thrash |
| `MUS_M07_Combat_B` — "**Baptism**" | ENC_03 | Doom-heavy, drowned reverb |
| `MUS_BOSS_Tenebrae` — "**Reliquary**" | Mini-boss | Pipe organ + blast beats |
| `MUS_M07_Combat_C` — "**Excommunication**" | ENC_04–05 | Finale |
| Acolyte barks | All | Human VO, harmonized lightly (they're "harmonized" but human) |

---

## 8. Art & Lighting

* **Palette:** white marble, gold inlay, soft diffuse daylight above the clouds, deep blue sky, black-water cisterns lit by floating gold orbs; the Static orange only on the Unsung.
* **Key props:** grand stair & gate, Aurelia statues, reflecting pools (shallow planar water), organ-pipe hedges, meditation pavilions, Scriptorium shelves with transcription books (instanced), Resonance Lectern, cistern pillars, ossuary skull walls (porcelain), amphitheater tiers, cloister arcades, sanctum ring-gate & console, Consonance dropship.

---

## 9. New Assets Required (P1)

`SK_Acolyte` (+3 variants), `SK_Zealot`, `SK_Siren`, `BOSS_Tenebrae` (`SK_Tenebrae` + Thale in cockpit), `SM_Dropship_Consonance`, CULT kit (marble walls/floors/arches/stairs, gold inlay decals), Scriptorium set, cistern set, amphitheater set, cloister set, sanctum set, `SK_Aurelia` (in-person, half-gilded), `BP_RingGate`.
