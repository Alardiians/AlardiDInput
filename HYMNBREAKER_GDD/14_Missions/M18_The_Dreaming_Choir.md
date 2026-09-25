# M18 — THE DREAMING CHOIR

| | |
|---|---|
| **Act** | IV — Deep Water, High Air |
| **Location** | **Inside Lydian's dream** — a lilac-gold cloudscape made of fragments of memories: places Lydian has "dreamed" from everyone it has touched, and places from the player's own journey |
| **Kit** | `AERO` + remixed pieces of **every previous kit** (BRU, CITY, SHIP, IND, CULT, ICE) reassembled impossibly + `CHOIR` (Lydian) |
| **Target duration** | 80 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M18_1 → BEAT_M18_4 |
| **New** | *Bitcrusher* pedal, **Requiem Gate #6**, looping space, piano-staircase easter egg, "Greatest Hits" dream arena, memory flash; **Boss: Lydian, the Dreaming Choir** |
| **Landmark** | **Lydian** itself — a vast, faint, translucent figure with a mobile of masks for a head, visible in the sky from everywhere, watching, amused |

---

## 1. Overview

The player walks through a dream built from memories — a looping Halcyon street, a Quietus corridor made of clouds, a CDF bunker upside-down in the sky, a staircase of floating grand pianos. This is the game's **"remix" mission**: it reuses assets from every previous kit, recombined surreally (efficient for production, delightful for players). Then the dream shows the Unsung something *they* remember: a pale stone city and a figure with a shield.

**Experience goals:** surreal wonder and playful creativity; a sense of the journey so far (familiar places, twisted); the first crack in the Unsung's armor (the memory flash); and a spectacular boss on floating islands.

**Illusions** (from M17) are everywhere here, and **gravity seams** return. The dream sky is a void (falls = recovery, no damage in this mission — dream logic, and to reduce frustration).

---

## 2. Level Flow

```
[A01 The Loop Street (a Halcyon block that repeats)] ENC_01 (break the loop)
   → [A02 The Cloud Corridor (a Quietus Spine made of cloud)] (emotional traversal)
   → [A03 The Upside-Down Bunker] ENC_02   (+CM_M18_01)
   → [A04 The Piano Staircase] (traversal; melody easter egg) → [A05 Memory Flash] CIN_M18_Memory
   → [A06 The Stadium of Dreams] ENC_03 "Greatest Hits"
   → [A07 The Dream Archipelago] BOSS: LYDIAN → end
   Optional: [Requiem Gate #6] floating off A04
```

### A01 — The Loop Street, ENC_M18_01
* **Space:** a Halcyon street block (from M04/M05 assets, 120 m long): storefronts, a bus stop, a Static barricade, neon signs. Walking off either end brings the player back to the other end (seamless loop via level-instance teleport). Each loop, small details change (the neon signs spell different words: "WAKE UP", "YOU'RE DREAMING", "STAY", "SLEEP").
* **Breaking the loop:** three **Memory Anchors** (lilac Dream Wells shaped like streetlamps, 600 HP) sit along the street; destroying all three during the arena breaks the loop — the street's far end tears open onto the sky.
* The arena happens *in the loop*: enemies that leave one end come back the other.

### A02 — The Cloud Corridor
* **Space:** a remembered **Quietus Spine Corridor** — but its walls are soft cloud; the black wedges float slowly like drifting birds; Juno's collar song plays faintly from somewhere; ghostly figures of the crew (translucent, dreaming versions) walk past and wave. No combat. The corridor ends in open sky with a Kick Pad made of cloud.
* A soft emotional beat: at the corridor's midpoint, a translucent **Juno** stands by bulkhead 4 and salutes. The Unsung can salute back (interact, `GST_Nod`). She fades.

### A03 — The Upside-Down Bunker, ENC_M18_02
* **Space:** a Fort Obdurate-style bunker complex hanging upside-down in the sky: the player walks on its ceilings; furniture hangs "up"; exterior walkways loop around its outer walls with gravity seams. Arena: the bunker's inverted command hall (40 × 30 m).
* **Optional:** `CM_M18_01` in the inverted armory.

### A04 — The Piano Staircase
* **Space:** a spiral staircase of **floating grand pianos** (20 pianos) rising 150 m through clouds. Each piano plays a note when landed on. Landing on them **in the intended order** (the natural route) plays the first phrase of the main theme; a secret shortcut order plays Harlan's radio jingle and spawns a Reprise (easter egg). Traversal: jumps, dashes, Harrow Anchors on piano lids, Swing Poles on music stands.
* **Requiem Gate #6** floats off the staircase (reachable by a Kick Pad made of a timpani drum).

### A05 — Memory Flash
* At the top of the staircase: `CIN_M18_Memory` (12 s, in-play freeze): the dream glitches; the Unsung's **own** memory bleeds in: a pale stone city of flute-towers; wind music; a tall armored figure with a shield reaching out; a heartbeat stuttering. The Unsung stops; the player can't move for 2 s; then the music slams back in. Lydian (V.O., curious): "*...Oh. Whose memory was that? It isn't one of mine.*"

### A06 — The Stadium of Dreams, ENC_M18_03 "Greatest Hits"
* **Space:** the Halcyon Bowl remembered as a dream: the stands float in pieces around a pitch that's an island in the sky; the stage is a piano; the crowd is made of clouds.
* **"Greatest Hits":** Lydian "replays" the Unsung's past fights: waves arrive **themed** after earlier missions' finales (Moon Choristers, Tether Ophans, Iron Psalm phalanx, Forge-Belt Organ Grinders) — real enemies mixed with illusions.

### A07 — The Dream Archipelago: BOSS LYDIAN
* `10_Bosses.md` §10. Seven floating islands; phases: Reverie (copies), Inversion (gravity flips + "Memories" of previous bosses' attacks), Waking (the true form flees across falling islands).
* After the Boss Breakdown (closing a fist on the tiny true form): the dream bursts like a soap bubble; the player wakes standing in Cytherea's Keel; the city lurches, dropping 2 km into calmer clouds (everyone survives — the sleepers wake up, confused, alive); the sixth Aureole band dies. Wren: "*GOT HIM. The trace — it's clean. Low Earth orbit. A place called... the Chancel.*"

---

## 3. Encounters

```
ENC_M18_01  "The Loop"                Arena: A01 (120 m looping street, storefront interiors, bus shelter, barricade)   Seals: n/a (loop)
  Music: MUS_M18_Combat_A (the track itself loops a 4-bar phrase until the loop breaks)
  Reward: 1 Brass + loot fountain
  Objective: destroy 3 Memory Anchors (tag `MemoryAnchor`; 600 HP each)
  W1 OnStart:             Thrall x10 (Tuned commuters — dream versions), Trooper x4, illusions
  W2 AliveBelow(5):       Chorister x4, Bloated Thrall x2
  Final W3 ObjectiveDestroyed(MemoryAnchor, 3): Crescendo x2, Seraph x1, Thrall x8
  Pickups: Health S x8, Plating S x6, ammo L x1 (Shells, Rounds)
```

```
ENC_M18_02  "Inverted Command Hall"   Arena: A03 (40 x 30 m; ceiling-floor; hanging desks as cover; exterior walkway loop with seams)   Seals: 2
  Music: MUS_M18_Combat_B             Reward: 1 Brass + loot fountain
  W1 OnStart:             Bulwark x4 + Trooper x6 (a dream phalanx), Thrall x6
  W2 AliveBelow(5):       Requiem Knight x1, Marksman x2, Thrall x4
  Final W3 AliveBelow(4): Gilded Bellwether x1, Maestro x1, Chorister x4
  Pickups: Health M x1, Health S x6, Plating M x2, Charge L x1, Ordnance L x1
```

```
ENC_M18_03  "Greatest Hits"           Arena: A06 (pitch island 90 x 60 m; floating stand-fragments 6-15 m; Kick Pads between)   Seals: n/a (island; void)
  Music: MUS_M18_Combat_C (quotes riffs from earlier missions' finale tracks)   Reward: 2 Brass + big loot fountain
  W1 OnStart:             Chorister x6, Bulwark x2, Cantor x1, Thrall x8                       ["Moon"]
  W2 AliveBelow(4):       Ophan x2, Vesper x10, Wailer x6                                     ["Tether"]
  W3 AliveBelow(4):       Bulwark x4 + Trooper x6 (phalanx), Requiem Knight x1                ["Iron Psalm"]
  W4 AliveBelow(4):       Organ Grinder x2, Canon x1, Thrall x8                               ["Forge"]
  Final W5 AliveBelow(4): Carillon x1, Gilded Crescendo x1, Maestro x1, Chorister x4, Siren x2  ["Now"]
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x4
  Power-up: OVERDRIVE SURGE (on the stage-piano)
```

**Boss:** `BOSS_Lydian`. **Optional:** `CM_M18_01`, **Requiem Gate #6** (`RQG_06`, "**Lucid Dread**").

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M18_Loop` | Looping street with changing neon messages |
| `EVT_M18_JunoSalute` | Dream-Juno salutes; optional nod |
| `EVT_M18_Pianos` | Piano staircase melody (+ jingle easter egg) |
| `EVT_M18_Memory` | `CIN_M18_Memory` — the Unsung's own memory |
| `EVT_M18_GreatestHits` | Themed remix waves |
| `EVT_M18_Wake` | Dream bursts; Cytherea drops; sleepers wake; trace resolves |
| Glimpse | Locris stands on a far floating island during Greatest Hits, watching; a cracked halo |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #6** | A01: inside the loop — a storefront ("DREAM WAX RECORDS") that only has its door open on the **third** loop | A violet-lit shop door that flickers |
| S2 | **Heart Shard #14** | A02: at the Cloud Corridor's end, behind a floating wedge (Harrow Anchor on the wedge) | Violet glow behind the wedge |
| S3 | **Mute Cell #7** | A03: the inverted armory's "floor" safe (after `CM_M18_01`) | — |
| S4 | **Tab #8: "Dream Logic"** (low gravity for the player and enemies) | A04: inside the last grand piano (Downbeat its lid) | A piano with violet keys |
| S5 | **Pedal: Bitcrusher** | A06: under the stage-piano's keyboard | — |
| S6 | **Effigy: Lydian** | A07: after the boss, on the last remaining island | — |
| S7 | **Effigy: Reverie** | A01: bus shelter's ad panel (shoot it) | — |
| S8 | **Master: *"Lucid"* by SLEEPWALKERS** | A02: a cloud-crew member's radio | Music |
| S9 | **Reprise** | A04: easter egg — play the radio jingle on the pianos (order posted as a sheet-music scrap in A01's record shop) | — |
| S10 | **Rig Core** | A03: an exterior walkway reached through a hidden gravity seam behind a filing cabinet | Lilac seam |
| S11 | **Brass Cache #1** | A01 (loop 2's back alley) | — |
| S12 | **Brass Cache #2** | A06: a floating stand-fragment's press box | — |
| S13 | **Sounding Station #1** | A01 (a Static sonar rig on the barricade) | — |
| S14 | **Sounding Station #2** | A06 (in the dream-press box) | — |
| S15–S19 | **Archive Stones** | A01, A02, A03, A06, A07 | — |

**Archive entries:** `ARC_Loc_TheDream`, `ARC_Archon_Lydian` (full), `ARC_Mem_PaleCity` (unlocked by the memory flash — Lund's analysis is missing, the entry just says "*Unknown. Not a human memory.*"), `ARC_Opt_RequiemGate6`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Break the loop within 2 loops |
| 2 | Play the main-theme phrase on the piano staircase |
| 3 | Identify the real Lydian on the first try in 3 consecutive Reverie cycles |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M18_Explore` — "**REM**" | Traversal | Dream-pop-meets-doom; reversed guitars; tape wobble |
| `MUS_M18_Combat_A` — "**Groundhog**" | ENC_01 | Loops a 4-bar phrase until the loop breaks, then explodes into the full song |
| `MUS_M18_Combat_B` — "**Upside Down**" | ENC_02 | Riffs played backwards and forwards |
| `MUS_M18_Combat_C` — "**Greatest Hits**" | ENC_03 | A medley quoting finale tracks from M02, M03, M08, M10 |
| `MUS_BOSS_Lydian` — "**The Dreaming Choir**" | Boss | Lydian-mode, ethereal choir vs. crushing guitars; phase 3 accelerates |
| Pianos | A04 | Each piano a real piano sample; the melody easter egg |

---

## 8. Art & Lighting

* **Palette:** lilac and gold sky, pastel clouds, remembered places desaturated and slightly bloomed; illusions lilac; real enemies vivid (keep cyan halos saturated for readability).
* **Production note:** this mission is intentionally **built from existing kits** (reuse ≥ 70% of meshes); new assets are mostly the pianos, cloud materials, and the archipelago islands.

---

## 9. New Assets Required (P1)

`BOSS_Lydian` (`SK_Lydian`, mask mobile, true form), floating grand piano (`SM_GrandPiano` + note trigger), cloud materials (soft volumetric walls), looping-street system (`BP_LoopVolume`), Memory Anchor (Dream Well variant), inverted-gravity bunker assembly (existing BRU kit), dream stadium fragments (existing CITY kit), archipelago islands.
