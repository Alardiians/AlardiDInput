# M21 — AUBADE

| | |
|---|---|
| **Act** | V — The Unsung |
| **Location** | **Aubade**, the capital of the Oreth, on the dead world **Solace** — embedded in the Harmonium, frozen at the moment of the First Unison 4.5 billion years ago |
| **Kit** | `OREN` (Oreth ruins: pale stone, flute-towers, glyph-staves, statues) + `CHOIR` 10% (subtle — the city was tuned so completely it needs no growth) |
| **Target duration** | 65 min (exploration-heavy: ~40% combat, 60% exploration) |
| **Priority** | P1 |
| **Story beats** | BEAT_M21_1 → BEAT_M21_6 |
| **New** | **THE AXE** (Grudges), Rig *Grudge-Bearer* unlock, *Kill Switch* pedal, **Wind Towers** (optional "unsealing" to restore the city's music) |
| **Landmark** | **The Warden Citadel** — a tall pale fortress on the city's highest hill, its towers shaped like war-horns; and the grey, starless sky with a dim, dead red sun |

---

## 1. Overview

The quietest mission in the game — by design, the "breakdown" of the whole album before the final run. Aubade was tuned so completely that it no longer needs to sing: **for the first time, there is no Hymn.** Only wind. The city's great **Wind Towers** — built so the wind would play them like flutes — were sealed with gold at the First Unison; they stand mute.

The Unsung walks home.

**Experience goals:** grief, discovery, restraint; the player *slows down*; the truth assembled from statues, glyphs and one flash of memory; reclaiming the Axe — a weapon that screams — in a city that forgot how to make a sound; and Locris, alive, saying the Unsung's old title.

**Pacing rules for this mission:**
* No radio (the signal can't reach — Harlan's intro is fragmentary static; see `03b`).
* No music in exploration. Combat music arrives **slowly** in the first arena (starting with a single guitar and building).
* Only 3 arenas (plus 1 optional Choir Mass).

---

## 2. Mechanic: Wind Towers (optional)

* Seven **Wind Towers** (30–80 m tall pale stone towers riddled with flute-holes) stand across the city; each has a **gold seal** at its base (a porcelain-gold plug, 1500 HP, Power Chord breaks it instantly).
* Breaking a seal: the wind rushes through the tower and it **plays** — a long, low, beautiful note. Each tower plays a different note of the **Oreth scale** (7 notes). The ambient soundscape gains that note permanently for the mission.
* Unsealing **all seven** makes the whole city play a slow melody together — the Oreth **Aubade** (a morning song) — and reveals a secret (see §6, S1) plus a mission challenge.
* Each tower is a small exploration puzzle (reach its base via a traversal route).

---

## 3. Level Flow

```
[A01 The Wind Gate (arrival)] → [A02 The Avenue of Singers] (statues; lore)
   → [A03 The Low Market] ENC_01 (the first sound in Aubade is gunfire)
   → [A04 Veyl's Square] CIN_M21_Statue
   → [A05 The Hall of Wardens] (the empty plinth)   (+CM_M21_01 in the Warden barracks)
   → [A06 The Warden Citadel] CIN_M21_Axe → ENC_02 "The Statues Wake" (Axe tutorial)
   → [A07 The Singing Stair] ENC_03 FINALE → [A08 The Crest Plaza] CIN_M21_Locris
   (Wind Towers: 7, scattered along A02–A07)
```

### A01 — The Wind Gate
* The gate from the Nave opens onto a hilltop above the city. Grey sky, a dead red sun (an ember in the grey), wind. Aubade below: a vast city of pale stone, towers shaped like flutes, horns and pipes; bridges; terraces; all silent. The Unsung stands for a moment (automatic 3 s pause; the camera looks out). Then walks.

### A02 — The Avenue of Singers
* **Space:** a grand avenue (400 m long, 40 m wide) lined with **Oreth statues** — the actual gilded bodies of Oreth frozen mid-song, heads raised, mouths open, some holding hands, some holding children. Their gold has dulled to bronze-grey. Glyph-staves (five-line sung notation) carved on every wall.
* **Archive:** each "Archive Stone" here is an Oreth glyph-stone translated by Lund (who, half-tuned, can read them — he sent translations to the Quietus's database; comms-free — the text simply appears).
* Wind Towers 1 and 2 along the avenue.

### A03 — The Low Market, ENC_M21_01
* **Space:** a sunken market plaza (60 × 50 m) with stone stalls, a dry fountain shaped like a horn, terraces on three sides (4 and 8 m).
* The Choir *does* guard Aubade: Choristers and Cantors emerge from the statues' shadows. The first gunshot is the first loud sound in the city — it echoes forever.

### A04 — Veyl's Square
* A small, intimate plaza. One statue is different: an armored Oreth with a shield — **Veyl** — reaching out toward an empty space beside them where another figure should stand. `CIN_M21_Statue` (3P): the Unsung stops, removes a gauntlet (the hand beneath is long-fingered, grey-skinned, scarred — the first time the player sees any part of the Unsung's body), and touches Veyl's hand.

### A05 — The Hall of Wardens
* **Space:** a long hall (100 × 30 m, 25 m tall) of **statues of Oreth soldiers** (Shieldwardens) in armor like the Unsung's (the Rig's oldest pieces match theirs — the player can notice). One plinth near the end is **empty**, its name-glyphs chiseled out. Interact → the Unsung places a hand on the empty plinth (`GST_HeartPress`). No words. The Archive entry that unlocks is titled `ARC_Mem_EmptyPlinth` and contains only a rubbing of the scratched-out glyphs.
* **Optional:** `CM_M21_01` in the Warden barracks.

### A06 — The Warden Citadel, ENC_M21_02
* **Space:** the citadel's great hall (70 × 50 m, 40 m tall) — at its center, **Dorian's trophy altar**: a black stone slab where **the Axe** lies, wrapped in gold chains, surrounded by kneeling statues.
* `CIN_M21_Axe`: the Unsung tears the chains away and lifts the Axe; it **screams** (a tritone chord, huge); every statue in the city **cracks** (a wave of cracking sound rolls out across Aubade). Prompt: `THE AXE — kills anything in one swing. Costs a GRUDGE. [G hold]`.
* **The Statues Wake:** the cracked statues in the hall come alive as Choir-forms (Oreth-shaped Choristers, Requiem Knights, a Profundo) — the Axe tutorial arena (3 Grudges provided + Grudge pickups on the altar steps).
* **Rig unlock:** `RIG_Survival_5 Grudge-Bearer` becomes purchasable.

### A07 — The Singing Stair, ENC_M21_03 (FINALE)
* **Space:** a monumental stair (80 m wide) descending from the citadel in terraces (5 landings), flanked by two Wind Towers, down to the Crest Plaza. The finale arena spans the stair's three lower landings (each 80 × 25 m, 6 m apart).
* The combat music finally arrives at full power — and if the player has unsealed Wind Towers, their notes are woven into the track.

### A08 — The Crest Plaza
* `CIN_M21_Locris`: a voice behind the Unsung — soft, cracked, doubled: "*...I knew it would be you.*" **Locris** stands in the square — the living version of Veyl's statue — gilded, cracked, broken halo. "*Hello, Shieldwarden.*" Cut to black. (Leads directly into M22.)

---

## 4. Encounters

```
ENC_M21_01  "The Low Market"        Arena: A03 (60 x 50 m sunken plaza; terraces 4/8 m)   Seals: n/a (stone growth closes the stairs)
  Music: MUS_M21_Combat_A (starts as a single clean guitar; builds over the arena)   Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6 (Oreth-shaped), Cantor x1
  W2 AliveBelow(3):       Fugue x2, Siren x1
  Final W3 AliveBelow(3): Gilded Bellwether x1, Chorister x4
  Pickups: Health S x6, Plating S x6, ammo L x1 (Shells, Charge)
```

```
ENC_M21_02  "The Statues Wake"      Arena: A06 (70 x 50 m hall, 40 m; altar dais 2 m; galleries 10 m)   Seals: 2
  Music: MUS_M21_Combat_B             Reward: 2 Brass + loot fountain
  Grudges: player starts with 3; Grudge pickups x3 on the altar steps (respawn once)
  W1 OnStart:             Chorister x8 (statue skins), Thrall x6 (Oreth-shaped "Silent Ones")
  W2 AliveBelow(5):       Requiem Knight x2
  W3 AliveBelow(3):       Profundo x1, Chorister x4
  Final W4 AliveBelow(3): Carillon x1 (a bell-tower of the citadel wakes and walks), Thrall x8
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
```

```
ENC_M21_03  "The Singing Stair" (FINALE)  Arena: A07 (3 landings 80 x 25 m, 6 m apart; Wind Towers flanking)   Seals: n/a
  Music: MUS_M21_Combat_C (weaves in any unsealed tower notes)   Reward: 2 Brass + big loot fountain
  W1 OnStart:             Chorister x6, Bulwark x3, Thrall x8
  W2 AliveBelow(5):       Maestro x1, Seraph x2
  W3 AliveBelow(5):       Gilded Profundo x1, Requiem Knight x1
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Carillon x1, Gilded Crescendo x1, Siren x2, Chorister x4
  Pickups: Health M x3, Plating M x3, ammo L each, Grudge x1, Null Cell x1, Harrow Spool x3
  Power-up: OVERDRIVE SURGE (landing 2)
```

---

## 5. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M21_Arrival` | Automatic pause on the hilltop; the silent city |
| `EVT_M21_FirstShot` | The first gunshot echoes for 4 s across the city |
| `EVT_M21_Statue` | `CIN_M21_Statue` (3P) — the Unsung's bare hand |
| `EVT_M21_Plinth` | The empty plinth |
| `EVT_M21_Axe` | `CIN_M21_Axe` — the Axe screams; the city's statues crack |
| `EVT_M21_WindTowers` | Seven towers; the Aubade melody when all are unsealed |
| `EVT_M21_Locris` | `CIN_M21_Locris` |

---

## 6. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #16** | Revealed when **all seven Wind Towers** play: a hidden door in the Wind Gate's hilltop shrine opens (the melody "unlocks" it) | The shrine's door has seven empty glyph-notches that light as towers are unsealed |
| S2 | **Mute Cell #8** | A02: inside Wind Tower 2 (climb its interior spiral after unsealing it) | — |
| S3 | **Bootleg Tape #10** (Pit Trial: *"Axe to Grind"* — Axe-only with regenerating Grudges) | A05: on the Warden barracks' weapon rack (after `CM_M21_01`) | — |
| S4 | **Pedal: Kill Switch** | A06: the citadel's armory loft (Harrow Anchor on a horn-tower's rim) | — |
| S5 | **Effigy: Veyl** (a small carved statuette of Veyl — made by Oreth hands) | A04: at the foot of Veyl's statue (after the cutscene) | — |
| S6 | **Effigy: The Unsung (Oreth)** — a carving of an armored Oreth with a scratched-out face | A05: hidden behind the empty plinth | A gap behind the plinth, violet glow |
| S7 | **Master: *"Aubade"* — the Oreth morning song**, as recorded by the Quietus from the Wind Towers (unlocks automatically when all 7 towers play; otherwise found in A07's tower-shrine as a glyph-stone the Quietus transcribes) | A07 / automatic | — |
| S8 | **Rig Core** | A03: under the dry horn-fountain (Downbeat) | — |
| S9 | **Brass Cache #1** | A02: a statue's offering bowl | — |
| S10 | **Brass Cache #2** | A05 (after `CM_M21_01`) | — |
| S11 | **Sounding Station** | A01: a Static probe the Quietus dropped | — |
| S12–S19 | **Archive Stones** (Oreth glyph-stones) | A02 (×3), A04, A05 (×2), A06, A07 | — |

**Archive entries (the truth, in fragments):** `ARC_Oreth_People`, `ARC_Oreth_Aubade`, `ARC_Oreth_Cantors`, `ARC_Oreth_FirstUnison`, `ARC_Oreth_Shieldwardens`, `ARC_Oreth_Veyl`, `ARC_Mem_EmptyPlinth`, `ARC_Weapon_Axe`, `ARC_Oreth_TheScream` ("*On the day of the One Song, one voice broke it...*").

---

## 7. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Unseal all seven Wind Towers |
| 2 | Kill a Carillon with a single Axe swing |
| 3 | Complete the Singing Stair using no more than 3 Grudges |

---

## 8. Audio

| Cue | Where | Notes |
|---|---|---|
| **Wind only** | Exploration | No music, no Hymn. Wind, footsteps, the Unsung's breathing and heartbeat, stone creaks. Each unsealed Wind Tower adds its sustained note. |
| `MUS_M21_Combat_A` — "**Homecoming**" | ENC_01 | Starts as one clean guitar; drums enter at wave 2; full band at wave 3 |
| `MUS_M21_Combat_B` — "**The Axe**" | ENC_02 | The Axe's scream (tritone) is the track's opening chord |
| `MUS_M21_Combat_C` — "**Aubade (Reprise)**" | ENC_03 | The Oreth melody played on down-tuned guitars; wind-tower notes woven in |
| The Axe | All | A living scream on draw; howling holes on swings; a dissonant bell on kills |

---

## 9. Art & Lighting

* **Palette:** pale stone (warm grey-white), dulled bronze-gold statues, grey sky, a dim red sun; the Unsung and the Axe (black, ember red) the only saturated things.
* **Key props:** Oreth architecture kit (towers shaped like wind instruments, arches, terraces, glyph-carved walls), Wind Towers ×7 (with gold seals and unsealed states), Oreth statue set (20 poses; Veyl hero statue; Warden statues), trophy altar with the Axe (hero), market stalls, horn-fountain.
* **Unsung's hand:** `SK_Unsung_BareHand` (grey, long-fingered, scarred, 4 fingers + thumb, alien but relatable).

---

## 10. New Assets Required (P1)

`OREN` kit, Wind Tower hero set (+ seal destruction + wind VFX + per-tower note audio), Oreth statue set, `SK_Veyl_Statue`, `SK_WPN_Axe` (+ scream VFX), `PKP_Grudge`, Oreth-shaped Chorister/Thrall skins, citadel hall & trophy altar, `SK_Unsung_BareHand`, `SK_Locris` (for the cutscene; full boss rig in M22).
