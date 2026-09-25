# M24 — THE OCTAVE

| | |
|---|---|
| **Act** | V — The Unsung (finale) |
| **Location** | **The Cathedral of the Final Chord** — interior ascent to its summit, where Aurelia Voss sings the last note |
| **Kit** | `CULT` (white marble & gold, taken to its extreme) + `CHOIR` 100% + gold "memory" rooms (familiar human spaces rendered in gold) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M24_1 → BEAT_M24_4 |
| **New** | Memory floors (environmental storytelling of the villain), rest-window combat (boss); **Boss: Aurelia Voss, the Octave** |
| **Landmark** | **The Aureole's last band**, visible through the Cathedral's open vaults — a white ring pulsing faster and faster, directly overhead |

---

## 1. Overview

The ascent through Aurelia's grief. Each floor of the Cathedral is a **memory** of her life, rebuilt in gold: her Listening Array control room; her daughter's bedroom; her wedding; the night the Signal arrived. The last Consonance faithful make their stand. At the summit, the Herald becomes **the Octave**.

**Experience goals:** understanding the villain completely — without excusing her; the tension of the Aureole's accelerating pulse; one quiet room where the Unsung stops (and so does the music); an enormous, musical final boss of Act V; and the tragic, human end.

**Pacing:** 4 arenas + boss; one no-combat memory room (A03).

---

## 2. Level Flow

```
[A01 The Narthex of Light] ENC_01
   → [A02 Memory: The Control Room (2196)] (lore; the Signal's first night in gold)
   → [A03 Memory: Clara's Room] (NO combat; the music box)
   → [A04 Memory: The Wedding Hall] ENC_02   (+CM_M24_01)
   → [A05 The Stair of Years] ENC_03 (landing arena)
   → [A06 The Congregation Hall] ENC_04 (last faithful)
   → [A07 The Summit] BOSS: THE OCTAVE → CIN_M24_Death
```

### A01 — The Narthex of Light, ENC_M24_01
* **Space:** the Cathedral's entry hall (100 × 60 m, 70 m tall): white marble floors inlaid with gold staff-lines, colonnades of porcelain pillars, the faithful (Acolytes) kneeling in rows singing — they rise to fight as the Unsung enters. Light pours from the vaults (the Aureole overhead).
* Aurelia's voice, calm: "*Floor by floor. Take your time. I want you to see.*"

### A02 — Memory: The Control Room (2196)
* A perfect gold replica of the Listening Array's control room on the night of the First Reception — consoles, tape reels, a coffee cup, the chair — at 1:1 scale, everything gilded. A faint recording plays: young Aurelia's voice on the night: "*...is anyone else hearing this? Oh my God. Oh my God, it's beautiful.*" Lore stones. A few Choristers perched silently on consoles (a small fight).

### A03 — Memory: Clara's Room (no combat)
* A child's bedroom, rendered entirely in gold: a bed, stuffed animals, drawings on the walls (drawings of the family — gold), a window with a gold view of the sea, **a music box** on the dresser. The level's music and the Hymn **cut out** entirely on entering. The music box plays a simple lullaby.
* The Unsung stops. The player can move, but the Unsung's walk slows to 50% in this room (scripted). Interacting with the music box: the Unsung closes its lid gently (`GST`). Or leaves it playing. Either is fine.
* Archive: `ARC_Char_Clara` — a child's drawing of "MOMMY LISTENING TO THE STARS."

### A04 — Memory: The Wedding Hall, ENC_M24_02
* **Space:** a golden wedding reception hall (60 × 40 m): tables with gold place settings, a dance floor, a band stage with gold instruments (a gold drum kit!), a balcony (6 m). The Choir attacks amid the frozen celebration (gold guests stand frozen mid-dance — scenery).
* **Optional:** `CM_M24_01` in the kitchen.

### A05 — The Stair of Years, ENC_M24_03
* **Space:** a spiral ascent through **floating memory-rooms** (a school classroom, a university lecture hall, a hospital corridor, a funeral — each 10–20 m rooms suspended in a vast shaft, connected by white stairs, Kick Pads, Harrow Anchors and Note-Platforms). The arena is a large landing (40 × 40 m) halfway: the **funeral** memory (gold coffins — two of them; one small).

### A06 — The Congregation Hall, ENC_M24_04
* **Space:** the Consonance's final gathering hall (80 × 60 m, tiered like an amphitheater facing an altar-door to the summit): the last Consonance faithful — Acolytes, Zealots, Choirmasters (Maestros in Consonance robes) — make their stand. Aurelia (V.O.): "*They chose this. Every one of them. Please remember that.*"

### A07 — The Summit: BOSS THE OCTAVE
* `10_Bosses.md` §12. `CIN_M24_Octave`: Aurelia stands barefoot at the center of the summit under the Aureole; she lifts her arms; she *sings*; her body unfolds into the 15 m eight-armed Octave.
* Phases: **The Scale** (eight notes in order + rests) → **The Congregation** (links heal her) → **The Octave** (staff-line platforms; strike in the rests). Final: the Axe into her heart.
* `CIN_M24_Death`: "*It's so loud. I'd forgotten.*" — the Aureole **shatters**, falling across Earth like snow; cheering on every channel — and then the stars begin to hum. Lund: "*It's coming.*"

---

## 3. Encounters

```
ENC_M24_01  "Narthex of Light"       Arena: A01 (100 x 60 m; colonnades; kneeling rows)   Seals: 2
  Music: MUS_M24_Combat_A             Reward: 2 Brass + loot fountain
  W1 OnStart:             Acolyte x10, Zealot x6
  W2 AliveBelow(6):       Maestro x1 (Consonance robes), Chorister x6
  W3 AliveBelow(5):       Gilded Bellwether x1, Cantor x2, Bulwark x3
  Final W4 AliveBelow(5): Carillon x1, Seraph x2, Acolyte x6
  Pickups: Health M x3, Plating M x2, ammo L each, Harrow Spool x3
```

```
ENC_M24_02  "Wedding Hall"           Arena: A04 (60 x 40 m; tables; dance floor; stage 1.5 m; balcony 6 m)   Seals: 2
  Music: MUS_M24_Combat_B (a waltz that the band "breaks" into metal)   Reward: 2 Brass + loot fountain
  W1 OnStart:             Fugue x3, Siren x2, Thrall x8 (gold-gilded "guests")
  W2 AliveBelow(5):       Gilded Profundo x1, Chorister x4
  W3 AliveBelow(4):       Maestro x1, Echo x2
  Final W4 AliveBelow(4): Gilded Canon x1, Gilded Crescendo x1, Zealot x6
  Pickups: Health M x2, Plating M x2, ammo L each, Grudge x1, Harrow Spool x3
  Power-up: TEMPO (on the band stage — "the band plays faster")
```

```
ENC_M24_03  "The Funeral Landing"    Arena: A05 (40 x 40 m landing; floating memory-rooms around; void)   Seals: n/a
  Music: MUS_M24_Combat_B             Reward: 1 Brass + loot fountain
  W1 OnStart:             Seraph x3, Ophan x2, Vesper x10
  W2 AliveBelow(5):       Requiem Knight x2
  Final W3 AliveBelow(4): Hymnal x2, Chorister x6
  Pickups: Health M x2, Plating M x1, Ordnance L x1, Charge L x1
```

```
ENC_M24_04  "The Congregation"       Arena: A06 (80 x 60 m amphitheater; tiers 1.5 m each; altar-door)   Seals: 3
  Music: MUS_M24_Combat_C             Reward: 3 Brass + big loot fountain
  W1 OnStart:             Acolyte x12, Zealot x8, Cantor x2
  W2 AliveBelow(8):       Maestro x2, Bulwark x4
  W3 AliveBelow(6):       Carillon x1, Gilded Profundo x1
  W3b TimeElapsed(25s):   Zealot x6, Acolyte x6
  Final W4 AliveBelow(6): Requiem Knight x2, Gilded Bellwether x1, Seraph x2, Chorister x6
  Pickups: Health M x4, Plating M x3, ammo L each, Null Cell x1, Grudge x1, Harrow Spool x4
  Power-up: AMP (altar)
```

**Boss:** `BOSS_Aurelia_Octave` (`10_Bosses.md` §12). **Optional:** `CM_M24_01`.

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M24_Floors` | Memory floors of Aurelia's life, in gold |
| `EVT_M24_FirstNight` | Young Aurelia's recorded voice on the night of the Signal |
| `EVT_M24_ClaraRoom` | Silence; the music box; the Unsung slows |
| `EVT_M24_Funeral` | Two gold coffins, one small |
| `EVT_M24_Octave` | `CIN_M24_Octave` |
| `EVT_M24_Death` | `CIN_M24_Death` — the Aureole shatters; the stars hum |
| Hub | State 6 — "Last Night"; `CIN_HUB_LastPlan` on arrival |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Mute Cell #9** | A02: inside the gold replica's tape machine (interact the reels) | — |
| S2 | **Tab #11: "Choir Boy"** (the Unsung's heartbeat is replaced by a tiny angelic "ah" — a joke; also all Choir enemies' voices pitched up) | A04: under the wedding cake (gold) | — |
| S3 | **Effigy: Aurelia** | A07: after the boss, among the rubble where she died | — |
| S4 | **Master: *"Clara's Lullaby"*** (the music box melody, arranged for the band — the most gentle track in the game) | A03: the music box (interact) | — |
| S5 | **Reprise** | A05: the hospital-corridor memory room (off the main stair path) | — |
| S6 | **Rig Core** | A06: behind the altar-door's relief (Power Chord a cracked panel) | Orange fissures |
| S7 | **Brass Cache #1** | A01: a collection plate on the narthex's side altar | — |
| S8 | **Brass Cache #2** | A04 (after `CM_M24_01`) | — |
| S9 | **Sounding Station** | A02: in the gold control room (still functional — the Unsung's Rig syncs to it) | — |
| S10–S15 | **Archive Stones** | A01, A02, A03, A04, A05, A06 | — |

**Archive entries:** `ARC_Char_Aurelia_Full`, `ARC_Char_Clara`, `ARC_Char_AureliaHusband` (Tomas Voss), `ARC_Hist_WaterWars`, `ARC_Boss_Octave`, `ARC_Hist_AureoleShattered`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | In Phase 1 of the Octave, Counter every gold ring from note 3 of the scale in one cycle |
| 2 | Break all Congregation links in Phase 2 within 30 seconds |
| 3 | Deal 50% of the Octave's Phase 3 damage during rests |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M24_Explore` — "**Floor by Floor**" | Traversal | Solemn requiem choir + a sparse piano; the band enters in combat |
| `MUS_M24_Combat_A` — "**Faithful**" | ENC_01 | 170 BPM |
| `MUS_M24_Combat_B` — "**Last Dance**" | ENC_02–03 | A waltz (3/4) that breaks into a 4/4 metal assault |
| `MUS_M24_Combat_C` — "**Congregation**" | ENC_04 | Massive, choral |
| Clara's Room | A03 | Total silence except the music box and the Unsung's heartbeat |
| `MUS_BOSS_Octave` — "**The Octave**" | Boss | Full orchestra + choir + band; literal rests in phase 3 (the whole mix drops to the heartbeat) |

---

## 8. Art & Lighting

* **Palette:** white and gold at maximum intensity, soft and glowing; the memory rooms: human spaces in gold (every object recognizable, all one material); the summit under the white Aureole. The Unsung is the only dark shape.
* **Key props:** gold-material versions of human props (reuse props from BRU/CITY/SHIP kits with the `MI_Gold_Memory` material), Clara's room set (bed, toys, drawings, music box — hero), wedding hall set, floating memory-rooms, amphitheater, summit with staff-line floor (hero boss arena).

---

## 9. New Assets Required (P1)

`BOSS_Aurelia_Octave` (`SK_Octave`, 8 arms, gown of bodies, phase states), `MI_Gold_Memory` master material, Clara's room set, music box (animated), wedding hall set, Stair of Years shaft with floating rooms, Congregation amphitheater, summit arena with moving staff-line platforms (`BP_StaffLinePlatform`), Aureole-shatter sky sequence.
