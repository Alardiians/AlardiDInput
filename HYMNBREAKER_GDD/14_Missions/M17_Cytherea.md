# M17 — CYTHEREA

| | |
|---|---|
| **Act** | IV — Deep Water, High Air |
| **Location** | **Cytherea**, a floating aerostat city 55 km above the surface of Venus: gasbag domes, hanging gardens, filigree balconies over a sea of sulfur-yellow cloud |
| **Kit** | `AERO` + `CHOIR` (Lydian variant: lilac-tinted porcelain, impossible flowers, floating masks) 20% → 70% |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M17_1 → BEAT_M17_4 |
| **New** | *Tuner* pedal; **Reverie illusions** (illusory enemies), **gravity-shift rooms**, cable-line traversal; enemy **Gilded Crescendo** |
| **Landmark** | **The Lydian Spire** — a spire of lilac light and floating stone fragments hanging *upside-down* beneath the city's central keel, slowly rotating, surrounded by drifting masks |

---

## 1. Overview

The most beautiful place humans ever built — and it's dreaming. Half a million survivors lived here; now they sleep standing up, smiling, while **Lydian**'s dream leaks into the waking city: flowers that sing, balconies that lead nowhere, gravity that leans sideways, and **illusions** — translucent copies of enemies that waste your ammo and lull you if you stand still.

**Experience goals:** wonder and vertigo; a reality-bending level that stays readable; learning to distinguish real from illusion (shadows and halos); navigating rooms where gravity turns; and a finale where the sky turns inside out.

---

## 2. Core Mechanics Introduced

### 2.1 Reverie Illusions (`ENM_Reverie_<Base>`)
* Translucent, shimmering **lilac** copies of known enemies (Choristers, Troopers, Crescendos, Seraphs…).
* **Tells:** illusions **cast no shadow**, have **no halo**, shimmer lilac at the edges; real enemies keep their cyan halos and shadows. The *Tuner* pedal (found in this mission) outlines real enemies in gold.
* **Behavior:** they "attack" with harmless lilac projectiles (0 damage — they pass through with a chime). They **pop** when hit by anything (1 HP) — wasting ammo.
* **Lullaby field:** each illusion emits a 400 cm aura. Standing **still** for > 1 s inside any aura: vision blurs, music slows, the player is **Slowed** (−40%) until they dash. Keep moving.
* **Distort** pops all illusions in its cone instantly (and doesn't waste Plating shards — illusions give nothing).
* Illusions don't count toward threat budgets or wave triggers; they are spawned by **Dream Wells** (`HAZ_DreamWell`: lilac fountains that emit 1 illusion every 6 s, max 6; destroyable, 400 HP).

### 2.2 Gravity-Shift Rooms (`BP_GravityRoom`)
* Rooms in the "Leaning Quarter" where gravity rotates 90° when the player crosses a **gravity seam** (a shimmering lilac line on the floor/wall). The camera rotates smoothly over 0.5 s; the player's "down" becomes a wall. Enemies inside follow the same gravity.
* Rules: only 90° rotations; rotations only at seams; always telegraphed; never mid-arena except the final set piece in M18.

---

## 3. Level Flow

```
[A01 Docking District] → [A02 Promenade of Balconies] ENC_01
   → [A03 Hanging Gardens] ENC_02 (Reverie intro; Dream Wells; Gilded Crescendo intro)   (+CM_M17_01)
   → [A04 The Leaning Quarter (gravity rooms)] ENC_03 (in a gravity room)
   → [A05 The Gondola Line (cable traversal)]   (+CM_M17_02 at the gondola station)
   → [A06 The Keel] ENC_04 FINALE → CIN_M17_InsideOut
```

### A01 — Docking District
* Tamsin docks the Quietus against a drifting district (the ship's hull visible through arches — a first). Gasbag domes (80 m diameter, white fabric over filigree ribs), terraced streets, trees in planters, flower markets. Sleeping people stand in the streets smiling, eyes closed, **dreaming** (not gilded — Lydian's dreamers are unconverted but "held"; non-hostile, non-damageable). The sky: sulfur yellow above, a sea of cloud below; lightning deep in the clouds.
* Radio intro (`RAD_M17`, Harlan's honeymoon).

### A02 — Promenade of Balconies, ENC_M17_01
* **Space:** a long promenade (200 m) of filigree balconies cantilevered over the cloud-void, with cafés, fountains, a bandstand; the arena is a wide plaza section (60 × 40 m) with balconies stepping down in 3 levels (4 m apart). The void is everywhere — knockback kills.

### A03 — Hanging Gardens, ENC_M17_02
* **Space:** a garden dome: terraced planters descending in a bowl (5 levels), waterfalls, flowering trees that sing, a glass conservatory at the bottom. The dream is strong: flowers bloom as you pass, petals float *upward*.
* **Reverie intro:** Dream Wells in the garden spawn illusions among real enemies. Prompt: `ILLUSIONS have NO SHADOW and NO HALO — don't waste ammo. DISTORT pops them. Keep MOVING.`
* **Gilded Crescendo intro** (plated back — must break plates before the bellows are exposed).
* **Optional:** `CM_M17_01` in the conservatory.

### A04 — The Leaning Quarter, ENC_M17_03
* **Space:** a residential quarter where gravity leans: streets that curve up walls, a staircase that becomes a ceiling, apartments turned sideways. Traversal through 4 gravity rooms, then an arena **inside a gravity room** (the **Leaning Library**, 30 × 30 × 30 m cube: bookshelves on every surface, gravity seams on two walls — the player can re-orient the fight by crossing a seam; enemies re-orient with you).

### A05 — The Gondola Line
* **Space:** a cable-car line between districts: 400 m of cables strung across the void with gondolas (some moving, some stuck). Traversal: Harrow Anchors on cable pylons, Swing Poles on gondola roofs, Grind Rails on the cables themselves (grinding along a cable over the void — spectacular), Kick Pads on pylon platforms. Light harassment by Vespers and Seraphs; illusions on pylon platforms.
* **Optional:** `CM_M17_02` in the gondola station's engine house.

### A06 — The Keel, ENC_M17_04 (FINALE)
* **Space:** the city's central keel: a vast structural spine (a hall 120 × 40 m, 50 m tall) of girders, ballast tanks, lift-gas pumps and machinery, with the **Lydian Spire** hanging below it (visible through a floor opening — a 40 m hole in the keel floor looking down onto the upside-down spire and the clouds).
* After the arena: `CIN_M17_InsideOut`: the Unsung stands at the edge of the opening; Lydian's voice — soft, delighted, many-voiced: "*Oh — you don't sleep. How wonderful. Then I'll have to bring the dream to you.*" The sky turns inside out (the clouds rise, the city flips, the world becomes lilac) — cut to black.

---

## 4. Encounters

```
ENC_M17_01  "Promenade"              Arena: A02 (60 x 40 m plaza, 3 balcony levels 4 m apart; void)   Seals: 2
  Music: MUS_M17_Combat_A             Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6, Thrall x8 (Tuned — the few truly gilded here)
  W2 AliveBelow(5):       Seraph x2, Vesper x8
  W3 AliveBelow(4):       Siren x2, Bulwark x2, Thrall x4
  Final W4 AliveBelow(3): Ophan x2, Canon x1, Thrall x6
  Pickups: Health S x8, Plating M x1, Ordnance L x1, Charge S x2
```

```
ENC_M17_02  "Hanging Gardens"        Arena: A03 (bowl dome 70 m; 5 terraces; conservatory)   Seals: 3
  Music: MUS_M17_Combat_A → B         Reward: 2 Brass + loot fountain
  Dream Wells: 3 (terraces 2, 3, 5)
  W1 OnStart:             Chorister x4, Thrall x8 (+ illusions)                              [Reverie intro]
  W2 AliveBelow(4):       Gilded Crescendo x1, Thrall x6                                     [Gilded Crescendo intro]
  W3 AliveBelow(4):       Maestro x1, Fugue x2
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(4): Gilded Bellwether x1, Seraph x2, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
  Power-up: TEMPO (conservatory roof)
```

```
ENC_M17_03  "Leaning Library"        Arena: A04 (30 m cube; 6 shelf-lined faces; 2 gravity seams)   Seals: 2
  Music: MUS_M17_Combat_B             Reward: 1 Brass + loot fountain
  Dream Wells: 1
  W1 OnStart:             Chorister x6 (every surface), Thrall x6
  W2 AliveBelow(4):       Siren x2, Echo x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 AliveBelow(3): Profundo x1, Chorister x4
  Pickups: Health S x6, Plating S x6, Shells L x1, Charge L x1
  Notes: enemies re-orient with the player's gravity; the Profundo's Stomp follows the current "floor".
```

```
ENC_M17_04  "The Keel" (FINALE)       Arena: A06 (120 x 40 m hall, 50 m; girder levels at 10/20/30 m; floor opening 40 m)   Seals: 3
  Music: MUS_M17_Combat_C             Reward: 2 Brass + big loot fountain
  Dream Wells: 2
  W1 OnStart:             Gilded Crescendo x1, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Carillon x1, Bulwark x3
  W3 AliveBelow(5):       Maestro x1, Seraph x2, Siren x1
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Gilded Bellwether x1, Profundo x1, Ophan x2, Chorister x3
  Pickups: Health M x3, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
  Power-up: AMP (girder level 30 m)
  Notes: the floor opening is a void (knockback kills).
```

---

## 5. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M17_Docking` | The Quietus docked against the city (visible through arches) |
| `EVT_M17_Dreamers` | Sleeping, smiling survivors in the streets (non-hostile) |
| `EVT_M17_FirstSeam` | First gravity rotation (tutorialized in a safe room) |
| `EVT_M17_CableGrind` | Grinding along a cable over the void |
| `EVT_M17_InsideOut` | `CIN_M17_InsideOut` |

---

## 6. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #13** | A02: under the promenade — a maintenance catwalk beneath the balconies (drop from a café terrace's broken railing onto a strut) | Violet glow below the railing |
| S2 | **Bootleg Tape #8** (Pit Trial: *"Lucid"* — illusions everywhere, only 3 real enemies per wave) | A04: an apartment whose door is on the ceiling (gravity seam) | — |
| S3 | **Pedal: Tuner** | A03: the conservatory's central flower (after `CM_M17_01`) | Violet bloom |
| S4 | **Effigy: Gilded Crescendo** | A05: inside a stuck gondola (Harrow Anchor on its roof) | — |
| S5 | **Master: *"Honeymoon on Venus"* by THE CLOUD CITY SWINGERS** (a lounge band — Harlan's honeymoon song) | A01: a café's gramophone | Music |
| S6 | **Reprise** | A05: a pylon's top platform off the main cable route | — |
| S7 | **Rig Core** | A04: on the *outside* of the Leaning Quarter — a gravity seam on an exterior wall leads to a sideways rooftop garden | Lilac seam with a violet glow |
| S8 | **Brass Cache #1** | A03: a waterfall grotto | — |
| S9 | **Brass Cache #2** | A05: gondola station engine house (after `CM_M17_02`) | — |
| S10 | **Sounding Station** | A01: harbor master's office | — |
| S11–S15 | **Archive Stones** | A01, A02, A03, A04, A06 | — |

**Archive entries:** `ARC_Loc_Venus_Cytherea`, `ARC_Archon_Lydian` (partial), `ARC_Enemy_Reverie`, `ARC_Haz_DreamWell`, `ARC_Enemy_GildedCrescendo`, `ARC_Hist_CythereaDreamers`.

---

## 7. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Pop 20 illusions with Distort |
| 2 | Destroy all 3 Dream Wells in the Hanging Gardens before the Gilded Crescendo arrives |
| 3 | Kill 10 enemies while grinding along a cable |

---

## 8. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M17_Explore` — "**Sulfur Sky**" | Traversal | Dreamy shoegaze-metal: wall-of-sound guitars, Lydian-mode (#4) melodies, soft female choir |
| `MUS_M17_Combat_A` — "**Promenade**" | ENC_01–02 | 165 BPM, bright and airy |
| `MUS_M17_Combat_B` — "**Vertigo**" | ENC_03 | Disorienting panning; tempo feels like it tilts |
| `MUS_M17_Combat_C` — "**Keel**" | ENC_04 | Big, soaring |
| Lullaby | Illusion auras | Music-box lullaby bleeding over the mix; slowed & pitched down when the player is lulled |

---

## 9. Art & Lighting

* **Palette:** sulfur yellow sky, cream-white gasbags, verdigris filigree, flower colors (magenta, amber, white), Lydian lilac for dream effects; lightning flashes deep in the clouds below.
* **Key props:** gasbag dome kit, filigree balcony kit, café/plaza props, hanging gardens (terraces, waterfalls, singing trees), gondolas & cables, the Keel's girders and ballast tanks, the upside-down Lydian Spire (hero), floating masks, illusion material (lilac shimmer, no shadow casting).

---

## 10. New Assets Required (P1)

`AERO` kit, `ENM_Reverie_*` (material variant system for any enemy mesh: translucent, no shadows), `HAZ_DreamWell`, `BP_GravityRoom` + seams (gravity-direction system in the character movement component), `SK_CrescendoGilded`, gondola + cable Grind Rails, Venus skybox (sulfur clouds, lightning), dreamer crowd (non-gilded variant of the crowd system).
