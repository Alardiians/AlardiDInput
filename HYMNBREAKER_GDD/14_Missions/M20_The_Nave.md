# M20 — THE NAVE

| | |
|---|---|
| **Act** | V — The Unsung |
| **Location** | **The Harmonium** — the Choir's home dimension. **The Nave**: the cathedral-hall entry region inside a Resonance Gate, miles long, lined with pillar-choirs of tuned beings from thousands of worlds |
| **Kit** | `HARM` (first full use) + `CHOIR_ARCH` |
| **Target duration** | 70 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M20_1 → BEAT_M20_4 |
| **New** | *Sustain* pedal; **Note-Platforms** (beat-timed traversal), **Hymn Saturation** hazard; enemy **Gilded Profundo**; alien-species Tuned (cosmetic variants) |
| **Landmark** | Through the Nave's colossal windows: **the Staves** (five kilometer-wide bridges across a golden void) and, at their head, **the Clef** — a spiral citadel kilometers tall |

---

## 1. Overview

The Unsung enters the enemy's home. The Harmonium is the most beautiful and most alien place in the game: light without sources, sound made visible (notes drift through the air as luminous rings), architecture of bone and gold and porcelain on an impossible scale, and pillars made of **billions** of tuned beings from every species the Choir has ever taken — not just humans and Oreth, but beings no human has ever seen, all gilded, all singing one note.

**Experience goals:** awe and dread; a new traversal verb tied to the music's rhythm (Note-Platforms); a new environmental pressure (Hymn Saturation); and the realization of the Choir's true scale — Earth is one note among millions.

---

## 2. New Mechanics

### 2.1 Note-Platforms (`BP_NotePlatform`)
* Luminous gold ring-platforms (diameter 400–600 cm) that **exist on a musical timer**, synchronized to the music via Quartz:
  * **Appear** on a beat (fade in over 0.1 s with a chime), **exist** for N beats (authored: typically 4 or 8), then **fade** (the ring shrinks and dims for the last beat — clear warning), then vanish.
  * Chains of Note-Platforms form "melodies": platforms appear in sequence, like notes on a staff.
* The music's tempo in Note-Platform sections is fixed (120 BPM) so the timing is learnable; an **accessibility option** doubles platform duration and adds a visual beat counter.

### 2.2 Hymn Saturation (`HAZ_HymnSaturation`)
* White-gold luminous mist pooling in low areas and some chambers: **5 dmg/s** (Plating first) and enemies inside get +10% damage. A **Hush Charge** clears a 500 cm bubble for 6 s; the Silencer clears the zone for 20 s; *Hazard Plating* halves the damage.
* Visual: bright volumetric fog with drifting ring particles; the edges are soft but clearly marked by a brighter "surface".

---

## 3. Level Flow

```
[CIN_M20_Crossing] → [A01 The Threshold] → [A02 The Narthex] (Note-Platform tutorial, Saturation intro) ENC_01
   → [A03 Aisle of the Pillar-Choirs] ENC_02   (+CM_M20_01)
   → [A04 The Note Bridges (rhythm traversal)]
   → [A05 Chapels of the Taken Worlds] ENC_03 (Gilded Profundo intro)   (+CM_M20_02)
   → [A06 The Great Windows] (vista) 
   → [A07 The Rood Screen] ENC_04 FINALE → the Gate to Solace
```

### A01 — The Threshold
* `CIN_M20_Crossing`: the Quietus jumps; the hull groans; the crew clutch their chests (the Hymn through the hull); Lund, sedated in the med-bay, hums the gate open. The Drop Coffin fires into gold light and lands on **the Threshold**: a vast platform of white stone floating before the Nave's doors (each door 300 m tall, bronze with reliefs of worlds being sung into the Choir).
* The Hymn is **loud** here. The UI's Arrhythm pulse beats harder.

### A02 — The Narthex, ENC_M20_01
* **Space:** the entry hall (120 × 60 m, 80 m tall), its floor partly flooded with **Hymn Saturation** mist (low areas) and crossed by **Note-Platform** sequences (tutorial: first a slow 8-beat chain over a small gap, then a real one over the mist).
* Prompts: `NOTE-PLATFORMS exist in time with the music — watch them SHRINK before they vanish.` / `HYMN SATURATION burns — HUSH clears it.`

### A03 — Aisle of the Pillar-Choirs, ENC_M20_02
* **Space:** the Nave proper: a raised aisle (40 m wide) running between **pillar-choirs** — columns 30 m in diameter and 200 m tall, each made of thousands of fused, gilded beings of many species (hero set dressing: modular "choir-body" relief panels combining human, Oreth and 12 alien species silhouettes), all singing. The aisle has side galleries (8 m), fallen pillar sections (cover/ramps), and pools of Saturation.
* The arena is a 150 m section of the aisle.

### A04 — The Note Bridges
* **Space:** the aisle breaks into islands over an abyss of golden void; the only way across is **Note-Platform melodies** (6 sequences, increasing complexity: 8-beat → 4-beat → branching → moving platforms that slide along a "staff line"), with Harrow Anchors on floating bells and Kick Pads made of drum-skins.
* Light combat: Vespers and Seraphs harass mid-sequence; Choristers on islands.

### A05 — Chapels of the Taken Worlds, ENC_M20_03
* **Space:** a side-nave of **chapels**, each a golden diorama of a conquered civilization frozen at the moment of its tuning (a crystalline city of insectoid beings; a water-world of whale-like beings; a machine civilization; a forest people) — lore stones in each. The arena is the **Great Chapel** (70 × 50 m) at the end, with 4 diorama alcoves as cover and routes.
* **Gilded Profundo intro.** Prompt reminder about Gilded plates.

### A06 — The Great Windows
* A quiet corridor of windows 100 m tall looking out on **the Staves** and **the Clef** — the final destination. A breather with a Sounding Station and a loot cache. Wren (comms, barely audible through the Hymn): "*...see that big... spiral? ...that's where it lives. ...Doc says... one more stop first.*"

### A07 — The Rood Screen, ENC_M20_04 (FINALE)
* **Space:** the end of the Nave: a colossal **rood screen** (a 150 m tall carved barrier of bone and gold separating the nave from the chancel) with a gate at its center; before it, a broad platform (90 × 60 m) with Note-Platform bridges to side balconies (12 m), Saturation pools, and Hymn Pylons.
* After the arena, the gate opens onto a **dead grey planet under a black sky**. Solace.

---

## 4. Encounters

```
ENC_M20_01  "Narthex"                Arena: A02 (120 x 60 m; mist lowlands; raised causeways 4 m; Note-Platform links)   Seals: n/a (Threshold/Nave doors)
  Music: MUS_M20_Combat_A (120 BPM locked — Note-Platforms)   Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6, Thrall x8 (alien-species Tuned variants)
  W2 AliveBelow(5):       Seraph x2, Ophan x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 AliveBelow(4): Gilded Bellwether x1, Siren x2, Chorister x3
  Pickups: Health S x8, Plating M x2, ammo L x1 (Charge, Ordnance), Hush refill x1
```

```
ENC_M20_02  "Pillar-Choirs"          Arena: A03 (150 x 40 m aisle; galleries 8 m; fallen pillars; mist pools)   Seals: 2
  Music: MUS_M20_Combat_B             Reward: 2 Brass + loot fountain
  W1 OnStart:             Maestro x1, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Carillon x1, Hymn Pylon x1, Bulwark x3
  W3 AliveBelow(5):       Requiem Knight x1, Echo x2, Fugue x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Gilded Crescendo x1, Profundo x1, Seraph x2, Chorister x3
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
  Power-up: AMP (atop a fallen pillar)
```

```
ENC_M20_03  "The Great Chapel"       Arena: A05 (70 x 50 m; 4 diorama alcoves; balcony 8 m)   Seals: 3
  Music: MUS_M20_Combat_B             Reward: 2 Brass + loot fountain
  W1 OnStart:             Gilded Profundo x1, Thrall x10                                      [Gilded Profundo intro]
  W1b TimeElapsed(20s):   Thrall x6
  W2 KilledTag(GildedProfundo) OR AliveBelow(4): Cantor x2, Canon x1, Bulwark x3
  W3 AliveBelow(4):       Maestro x1, Siren x2
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(4): Carillon x1, Gilded Bellwether x1, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
```

```
ENC_M20_04  "The Rood Screen" (FINALE)  Arena: A07 (90 x 60 m; side balconies 12 m via Note-Platforms; mist pools; 2 Hymn Pylons)   Seals: n/a
  Music: MUS_M20_Combat_C             Reward: 2 Brass + big loot fountain
  W1 OnStart:             Hymn Pylon x2, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Gilded Profundo x1, Seraph x2
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  W3 AliveBelow(5):       Maestro x1, Requiem Knight x1, Echo x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Carillon x1, Gilded Crescendo x1, Ophan x2, Chorister x4
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x4
  Power-up: OVERDRIVE SURGE (balcony, via Note-Platforms)
```

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #15** | A04: a hidden 7th Note-Platform melody (appears only on the downbeat of every 4th bar) leading to a floating bell | A faint violet note in the sequence |
| S2 | **Tab #9: "Unison"** (all enemies sing in perfect harmony when they die — a choir chord builds with every kill in an arena) | A05: the machine-civilization chapel's diorama (interact the tiny gilded machine) | — |
| S3 | **Pedal: Sustain** | A03: inside a pillar-choir (a gap between bodies, Harrow Anchor on a raised golden hand) | Violet glow within the pillar |
| S4 | **Effigy: Gilded Profundo** | A05 (after the arena) | — |
| S5 | **Master: *"Cathedral of Everything"* by NAVE** | A06: on a window ledge (a human radio — dropped here by someone taken long ago) | Music |
| S6 | **Reprise** | A02: under the Threshold's edge (drop onto a floating stone below, Kick Pad back up) | — |
| S7 | **Rig Core** | A07: behind the rood screen's carved relief (Power Chord a cracked panel) | Orange fissures |
| S8 | **Brass Cache #1** | A03 (after `CM_M20_01`) | — |
| S9 | **Brass Cache #2** | A05 (after `CM_M20_02`) | — |
| S10 | **Sounding Station** | A06 (a Static probe dropped by the Quietus) | — |
| S11–S16 | **Archive Stones** (Choir glyph-stones translated by Lund) | A01, A02, A03, A05 (×2), A07 | — |

**Archive entries:** `ARC_Loc_Harmonium`, `ARC_Loc_Nave`, `ARC_Hist_TakenWorlds_I–IV` (four alien civilizations), `ARC_Haz_HymnSaturation`, `ARC_Tech_NotePlatforms`, `ARC_Obj_Staves`, `ARC_Obj_Clef`, `ARC_Enemy_GildedProfundo`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Complete all Note Bridge sequences without falling |
| 2 | Kill 10 enemies standing in Hymn Saturation while you stand outside it |
| 3 | Break a Gilded Profundo's plates and kill it within 20 seconds |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M20_Explore` — "**Nave**" | Traversal | A monumental choir (the Choir's actual voice — full SATB + alien timbres) with the band as a small, stubborn counter-voice |
| `MUS_M20_Combat_A` — "**Threshold**" | ENC_01, Note Bridges | Locked 120 BPM so Note-Platforms are learnable |
| `MUS_M20_Combat_B` — "**Pillars**" | ENC_02–03 | 175 BPM |
| `MUS_M20_Combat_C` — "**Rood Screen**" | ENC_04 | Enormous |
| Note-Platforms | A04 | Each platform's appearance = a pitched chime forming a melody |

---

## 8. Art & Lighting

* **Palette:** white, gold, pale cyan-white light from everywhere; no sky, only luminous golden void; drifting light-rings (visible sound); the Unsung the only dark thing.
* **Scale:** everything 3–10× bigger than human architecture. Use Nanite heavily for the pillar-choirs and reliefs.
* **Key props:** Threshold platform, Nave doors (hero), pillar-choir modules, rood screen (hero), chapel dioramas ×4 (alien civilizations in gold), Note-Platform rings, floating bells, Saturation fog volumes, the Staves & Clef vista (matte-painting-grade skybox geometry).

---

## 9. New Assets Required (P1)

`HARM` kit (floors, aisles, walls, windows, doors), pillar-choir modules (multi-species relief meshes), `BP_NotePlatform` (Quartz-driven), `HAZ_HymnSaturation` (fog volume + damage), `SK_ProfundoGilded`, alien-species Tuned variants (cosmetic heads/arms for Thrall and Chorister rigs), chapel dioramas, Staves & Clef vista meshes, `CIN_M20_Crossing` sequence.
