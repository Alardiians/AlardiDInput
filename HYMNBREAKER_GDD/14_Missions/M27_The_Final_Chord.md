# M27 — THE FINAL CHORD

| | |
|---|---|
| **Act** | VI — The Last Broadcast (finale) |
| **Location** | **The heart of the Clef** — the Unison's chamber: a spherical void of light, kilometers across |
| **Kit** | `HARM` (core variant: pure light architecture) |
| **Target duration** | 60 min (≈ 45 min boss across 3 phases incl. retries, + approach, + epilogue) |
| **Priority** | P1 |
| **Story beats** | BEAT_M27_1 → BEAT_M27_6, EPILOGUE |
| **New** | **Last Overdrive** (permanent Overdrive in Phase 3), the BROADCAST meter, orbit-ring traversal, the Last Broadcast audio event; **Final Boss: The Unison** |
| **Landmark** | The Unison itself |

---

## 1. Overview

The end. The Unsung — with Lund on his drone, humming — walks into the heart of the Unison. The Unison speaks gently; it asks its lost sibling to rest; it fights with the weight of every world it has ever taken. And when it seems unbeatable, Harlan counts to three and **five billion people make noise at once**.

**Experience goals:** the most spectacular fight in the game, a boss that *talks back*, a finale where the player feels the whole of humanity behind them — then a quiet, earned ending.

**Load screen:** silent except for the Arrhythm heartbeat (no Radio intro — it plays live in Phase 3).

---

## 2. Flow

```
[A01 The Stair of Light (approach)] → CIN_M27_Unison
   → PHASE 1: THE VOICE (Orbit Rings)
   → PHASE 2: THE FIRST FACE (inside the sphere)
   → CIN_M27_Broadcast (in-play) → PHASE 3: THE LAST BROADCAST
   → CIN_M27_Finale → CIN_EPILOGUE → credits → CIN_POSTCREDITS
```

### A01 — The Stair of Light
* A slow, 90-second walk up a stair of light into a spherical void. No enemies. Lund on the drone, humming the main theme off-key. The Unsung's heartbeat. Echoes of every voice in the game drift past as light-motes (Aurelia's "*It's so loud*", Dorian's "*Shieldwarden*", Locris's "*Be loud for both of us*", Juno's collar song, Harlan's jingle) — memory as sound.
* Collectibles on the stair: the Rig Core and 2 Brass Caches (last chance), the final Archive Stones.
* `CIN_M27_Unison`: the sphere of the Unison fills the view. Its voice (billions): "*Little Wrong Note. You came home. Aren't you tired?*"

### PHASE 1 — THE VOICE
* `10_Bosses.md` §13 Phase 1. **Orbit Rings:** 3 concentric ring-platforms (12 m wide) orbiting the sphere at different speeds and tilts; Kick Pads and Harrow Anchors link them.
* **Objective:** destroy **8 Voice Nodes** (2500 HP each). Every enemy type arrives via Hymnfall on the rings as resource adds (weighted toward fodder for resources + 1 heavy every 40 s).
* Unison lines (between attacks): "*Every voice you have silenced is here with us. None of them are in pain.*" / "*We remember your name. Would you like to hear it?*"
* Phase end: the sphere cracks open; the rings dock into the crack; the Unsung walks inside.

### PHASE 2 — THE FIRST FACE
* `10_Bosses.md` §13 Phase 2. The inner chamber; the colossal **Oreth face** and hands made of millions of faces; the floor is its open palm (it tilts and closes — telegraphed).
* Statues of the Oreth rise and sing (Pylon behavior — Axe/Power Chord them). Hymn Saturation pours from its mouth.
* Damage windows: the eyes, during **Weeping** (it weeps gold every 45 s for 8 s).
* Unison lines: "*This was our face. This was yours, once.*" / "*You screamed, and it hurt us. It still hurts. Why do you want it to hurt?*"
* At 0% phase HP: the face does not break. It looks down at the Unsung — and **the Unison wins**: a wave of Hymn saturates everything; the screen whitens; the HUD fails; the Unsung sinks to one knee; the heartbeat slows... slows...

### CIN_M27_Broadcast (in-play, no control loss except 2 s)
* Silence. Then, faintly, through Lund — who stands up from the drone, gilded, glowing — **Harlan's voice**: `RAD_M27` ("*This is Radio Free Static. This is the Last Broadcast...*"). "*One. Two.*" — "***Make it loud.***"
* **The Last Broadcast arrives:** a wall of human sound — thousands of distinct voices singing, screaming, laughing, cursing, crying; drums, pots, car horns, big bronze bells, a kid's recorder, a thrash band in a garage, a choir of children singing a nursery rhyme badly, a stadium chant, an opera singer, a baby crying, someone just yelling "*GET UP!*" — everyone different. Lund is the antenna; it pours out of him into the Harmonium.
* The Unsung's heartbeat **surges** — the HUD re-ignites, the Gain meter is replaced by the **BROADCAST** meter (full, pulsing with humanity's signal) — **LAST OVERDRIVE**.

### PHASE 3 — THE LAST BROADCAST
* `10_Bosses.md` §13 Phase 3. **Last Overdrive** for the whole phase (all Overdrive effects, infinite).
* The Unison **fractures into 4 Dissenting Choirs** — faction-forms singing different notes, fighting each other and the player. The **Core** flickers between them; knock it loose 4 times.
* Unison lines: "*What— what is this? So many. They are all— different—*" / "*STOP— STOP SINGING— SO MANY—*" / (a single small voice, from deep within) "*...I remember. I remember my name.*"
* **Finale:** the Core falls; a melee prompt; the Axe; `CIN_M27_Finale`.

---

## 3. Encounters (resource adds and phase data)

```
BOSS_Unison
  Phase 1 (THE VOICE) — Orbit Rings
    Voice Nodes: 8 x 2500 HP (open in pairs; 2 open at a time)
    Adds: every 20 s: Thrall x6 or Chorister x4 (alternating) on the player's ring
          every 40 s: one heavy (rotation: Crescendo, Seraph, Bellwether, Siren, Canon, Ophan, Fugue, Gilded Bellwether)
    Pickups (respawning every 60 s on each ring): Health M x2, Plating M x2, ammo L (rotating type), Harrow Spool x2
    Null Cells: 2 (ring 2, ring 3), Grudges: 2
  Phase 2 (THE FIRST FACE) — Palm arena (100 m)
    Face eyes: 2 x 6000 HP (vulnerable during Weeping windows only)
    Oreth statue-pylons: 3 at a time (1500 HP; Axe/Power Chord instant)
    Adds: every 25 s: Thrall x8 (Oreth "Silent Ones"); every 50 s: Requiem Knight x1 or Maestro x1
    Pickups: respawning every 60 s: Health M x3, Plating M x3, ammo L each
  Phase 3 (THE LAST BROADCAST) — the Fractured Chamber (circular 150 m, floating debris platforms)
    Dissenting Choirs: 4 x 10 m faction-forms (each 8000 HP; they also damage each other)
    Core knocks: 4 (each knock requires dealing 3000 damage to the faction holding the Core)
    Adds: every 15 s: mixed T1 x8 (they fight each other too — factions); heavies every 30 s
    Player: Last Overdrive (infinite); Axe Grudges regenerate every 20 s during this phase
  Checkpoints: start of each phase; Phase 3 checkpoint begins right after CIN_M27_Broadcast
```

---

## 4. The Ending (full shot list)

### CIN_M27_Finale (see `03b`)
The Axe into the Core → white-out → billions of sparks, each singing its own note → one spark lingers near the Unsung → Lund: "*Listen. That's... everyone.*" → Lund dies smiling → the Unsung kneels, hand to chest.

### CIN_EPILOGUE (180 s, mixed FP/3P)
| # | Shot | Duration | Audio |
|---|---|---|---|
| 1 | **Halcyon, dawn.** The Aureole's remnants fall like gold snow over the ruined city. People on rooftops tear off their Static Collars and *laugh*. A child catches a flake on her tongue. | 20 s | Harlan's final segment begins (V.O.) |
| 2 | **A hospital hall.** Rows of the **Quiet** — long-tuned people, gilding flaking, sitting peacefully, still, eyes open, not singing. Families sit with them, holding hands. One old man hums to his wife; she doesn't respond; he keeps humming. | 20 s | Harlan: "*...not everybody's coming back. I won't lie to you.*" |
| 3 | **The Quietus**, towed through space by a dozen Static ships, a jagged scar in its bow, its hull-speakers silent. | 15 s | — |
| 4 | **The Quietus memorial wall**: Juno's collar; a new photo of Lund pinned beside it; Wren touching it. | 10 s | — |
| 5 | **Harlan's tower.** "*So I'm going to do something I haven't done in a long, long time.*" He lifts the needle off the record. **6.0 s of total silence.** "*...Yeah. That's the good kind.*" | 25 s | Silence |
| 6 | `[3P]` **The Quietus hull** in orbit over Earth. Tamsin sits beside the Unsung. She signs: "✋ *What will you do now?*" The Unsung looks at their hands. Then signs, carefully: **"Thank you."** Tamsin laughs silently and leans her shoulder against their armor. The Arrhythm pulses — irregular, alive. | 45 s | A single acoustic guitar begins the main theme |
| 7 | Title card: **HYMNBREAKER**. Credits roll over the main theme — first on a single acoustic guitar, then a crowd of human voices singing it, badly and gloriously. | — | Credits song |

### CIN_POSTCREDITS (30 s)
Deep space. A red dwarf star, a small blue world. Faintly, a choir begins to sing — a different key, a different choir. Cut to the Quietus's hull: the Unsung's visor **ignites**. Title card: **THE UNSUNG WILL RETURN.**
Post-credits Archive unlock: `ARC_Char_Locris_Gate` ("*The Last Warden held the gate until the end.*") and `ARC_Oreth_TheName` (a single line: "*Their name was a sound no Oreth throat could make without breaking. It meant: 'the one who does not agree.'*").

---

## 5. Post-Game

* **Hub State 7 — Home:** the Quietus in dock above Earth; calm; the crew at peace; Wren building something new ("*Don't ask. It's loud.*"); Vire on the bridge looking at a clean Earth; Pops playing records; Tamsin teaching sign to children in the mess; Lund's research station kept as he left it.
* **Unlocks:** Mission Select (all missions with collectibles tracking), **Encore** missions (remixed hard versions — see `16_Optional_Content_and_Modes.md`), Tabs usable, **Unsung** difficulty (if not already unlocked), the **Shieldwarden** Rig Finish (if vault opened), the Pit Trials' final challenge.
* **Credits song** and all Masters playable in the Listening Room.

---

## 6. Secrets & Collectibles

| # | Item | Location |
|---|---|---|
| S1 | **Effigy: The Unison** | Awarded on completion (placed in the Effigy Gallery with a unique pedestal) |
| S2 | **Master: *"The Last Broadcast"*** — the full Last Broadcast audio as a 6-minute track | Awarded on completion |
| S3 | **Rig Core** | The Stair of Light, a side landing |
| S4–S5 | **Brass Caches** | The Stair of Light |
| S6–S8 | **Archive Stones** | The Stair of Light (the Unison's own "confession" glyphs, translated by Lund in his last hours) |

---

## 7. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy all 8 Voice Nodes without falling from the Orbit Rings |
| 2 | Destroy 6 Oreth statue-pylons with the Axe in Phase 2 |
| 3 | Knock the Core loose 4 times in under 3 minutes |

---

## 8. Audio

| Cue | Where | Notes |
|---|---|---|
| Stair of Light | A01 | Memory motes (voice fragments from the whole game), heartbeat, Lund humming |
| `MUS_BOSS_Unison_P1` — "**The Voice**" | Phase 1 | The largest choir in the game (layers of human + Oreth + alien voices) vs. the band |
| `MUS_BOSS_Unison_P2` — "**The First Face**" | Phase 2 | Slower, grief-stricken; the Oreth Aubade melody in the choir |
| **The Last Broadcast** | Phase 3 | The main theme played by the full band + **a recorded crowd of hundreds of distinct human voices** (see the audio doc's production note: record real crowds/community sessions, or layer many individually generated voices — each must be distinct, messy, alive) |
| Finale | CIN | The Axe's scream → silence → billions of tiny different notes (granular synthesis cloud) |
| Harlan's silence | Epilogue | 6.0 s of true silence |

---

## 9. New Assets Required (P1)

`BOSS_Unison` (sphere with 8 Voice Nodes; First Face & hands; 4 Dissenting Choir faction-forms; Core), Orbit Ring platforms, palm arena (animated tilting/closing), Oreth statue-pylons, BROADCAST meter UI, Last Overdrive VFX, the Last Broadcast audio production, epilogue sets (hospital hall, rooftops at dawn, towed Quietus, memorial wall, Harlan's tower, hull at orbit), credits sequence.
