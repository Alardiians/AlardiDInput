# 12 — Level Design Standards

## 1. Metrics Cheat Sheet (derived from `05_Player_Character_Movement_Controls.md`)

### 1.1 Vertical
| Height | Player can | Level use |
|---|---|---|
| ≤ 45 cm | Step up | Curbs, debris |
| ≤ 140 cm | Single jump | Low walls, crates, cover (enemies can't see over ≥ 150) |
| ≤ 270 cm | Double jump / jump + mantle | Standard platform step between arena tiers |
| ≤ 400 cm | Double jump + mantle | **Max** unassisted ledge — use sparingly |
| 420–1500 cm | Kick Pad, Harrow Anchor, Grip Wall | Arena tier separation (typical tier gap 400–600) |
| Drop-downs | Any height (no fall damage) | Keep ≤ 1500 for readability (landing zone visible) |

### 1.2 Horizontal gaps
| Gap | Requires | Rating |
|---|---|---|
| ≤ 500 cm | Single jump | Easy (critical path OK) |
| ≤ 900 cm | Double jump | Medium (critical path OK) |
| ≤ 1400 cm | Double jump + 1 dash | Hard (critical path OK after M02) |
| ≤ 2000 cm | Double jump + 2 dashes | Expert (secrets only) |
| > 2000 cm | Harrow Anchor / Kick Pad / Swing Pole chain | Any |

### 1.3 Spaces
| Element | Minimum | Standard | Notes |
|---|---|---|---|
| Corridor width (exploration) | 400 | 500–700 | The Unsung is big and fast |
| Corridor width (combat-capable) | 800 | 1000+ | — |
| Ceiling (exploration) | 450 | 600 | Must allow double jumps in combat spaces: ≥ 800 |
| Standard door | 300 w × 400 h | — | Human-scale doors look *small* on the Unsung — intentional |
| Heavy door (T2 passable) | 500 × 600 | — | — |
| Titan door (T3 passable) | 700 × 900 | — | — |
| Small arena | 20 × 20 m | — | ≤ 8 T1 + 1 T2 |
| Medium arena | 30–40 m square | — | Standard |
| Large arena | 50–80 m | — | Finale arenas, T3 fights |
| Arena height | ≥ 12 m | 15–25 m | Flyers, tiers |
| Stairs | Rise 25, run 40, width ≥ 400 | — | Or ramps ≤ 35° |
| Cover height | 150 (full), 110 (half) | — | Half cover rarely useful (no crouch) — prefer full cover pillars |

### 1.4 Traversal Element Spacing
| Element | Spacing / Range |
|---|---|
| Harrow Anchor chains | ≤ 2500 cm between anchors; next anchor visible from the previous |
| Swing Pole chains | 900–1400 cm apart, same height or descending |
| Kick Pad | Landing zone ≥ 400 × 400 cm, visible from the pad; arc apex ≤ 1500 cm above the higher of launch/landing |
| Grip Wall | Width ≥ 300; height 400–2000; top must have a mantle ledge |
| Grind Rail | Straight segments ≥ 1000; curves radius ≥ 800 |

---

## 2. Modular Grid & Kit Standards

* **Grid:** 50 cm snap. **Primary module:** 400 cm. Every kit piece's dimensions are multiples of 50 (ideally 100/200/400).
* **Wall modules:** 400 w × 400 h × 50 d (and 400 × 800, 200 × 400, 100 × 400 fillers). Pivot at bottom-left-back corner, facing −Y in Blender (+X/Y conventions in `21_Blender_Asset_Pipeline.md`).
* **Floor modules:** 400 × 400 × 50 (and 800 × 800).
* **Door frames:** 500-wide wall piece with a 300 × 400 opening; heavy door frame 800 × 800 with a 500 × 600 opening.
* **Stairs:** 400 wide × 400 rise × 640 run (16 steps).
* **Ramps:** 400 wide, 400 rise over 800 run (26.6°).
* **Pillars:** 100 × 100 and 200 × 200 footprints.
* **Naming:** `SM_KIT_<Kit>_<Piece>_<WxH>` e.g. `SM_KIT_BRU_Wall_400x400_A`.

### 2.1 Environment Kits
| Kit ID | Name | Missions | Description |
|---|---|---|---|
| `BRU` | **Concord Brutalist** | M01, M02, M06, M09, M12, M15, M19* | Board-formed concrete, raw steel, stencil signage, sodium and fluorescent lighting |
| `CITY` | **Halcyon Megacity** | M04, M05, M23 | Megablock facades, highways, plazas, storefronts, stadium |
| `IND` | **Forge-Belt Industrial** | M10, M11 | Foundry halls, conveyors, crucibles, catwalks, cranes |
| `CULT` | **Consonance Sanctum** | M07, M24 | White marble, gold inlay, brutalist-gothic arches, reflecting pools |
| `ORB` | **Orbital/Space** | M02 (exterior), M03, M13, M19 | Hull plating, trusses, pressure doors, space-elevator ribbon & climbers |
| `ICE` | **Europa** | M15, M16 | Ice caverns, drill equipment, pressure habitats, submarine domes |
| `AERO` | **Cytherea Aerostat** | M17, M18 | Gasbag domes, gardens, filigree balconies, sulfur skies |
| `OREN` | **Oreth Ruins (Aubade)** | M21, M22 | Pale stone, wind-instrument towers, glyph-staves, statues |
| `HARM` | **Harmonium** | M20, M25–M27 | Bone, porcelain, gold, light architecture, staves, note-platforms |
| `SHIP` | **The Quietus** | Hub, M14 | Brutalist warship interior with black anechoic wedge walls |
| `CHOIR` | **Choir Growth Overlay** | All | Organ-pipe clusters, bone lattices, flesh-choir walls, bell blooms, gold filigree decals — applied **on top of** any kit to show corruption (density 0–100%) |

*M19 (the Chancel) uses `CHOIR` + `ORB` heavily.*

---

## 3. Mission Structure Template ("Song Structure")

Every mission follows a song-like structure. Mission docs list their actual beats against this template.

| Section | Content | Duration |
|---|---|---|
| **Intro** | Radio intro, arrival, establishing vista of the landmark (Spire/goal visible), light combat | 3–5 min |
| **Verse 1** | Exploration + 1–2 small/medium arenas; introduce the mission's new element | 10–15 min |
| **Chorus 1** | A big arena (the mission's first "wow") | 4–6 min |
| **Verse 2** | Traversal challenge, secrets branches, lore, a Choir Mass, Sounding Station | 10–15 min |
| **Bridge** | A set piece or twist (mech, chase, vision, collapse, moving arena) | 5–10 min |
| **Breakdown** | A quiet moment (story beat, vista, emotional environment) | 1–3 min |
| **Chorus 2 / Finale** | The biggest arena or a boss | 6–12 min |
| **Outro** | Exit, story beat, mission complete | 1–2 min |

Missions contain **6–10 arenas** (incl. optional), **1–2 Choir Masses**, **1 Sounding Station** (2 in large missions), **10–16 secret items**.

---

## 4. Readability Language (Environment)

| Signal | Visual rule |
|---|---|
| **Critical path** | Warm **orange Static work-lights**, graffiti arrows (Static waveform mark), and lit doorways. Choir areas: the path is where the gold light is *broken* (dark gaps in the harmony). |
| **Climbable (Grip Wall)** | Rusted chain-link mesh or bone lattice with **orange-painted trim** at the edges |
| **Harrow Anchor** | Rusted iron ring-bolt with an ember-glowing core (Choir version: a knot of bone with an ember core); a subtle 3D icon appears within range |
| **Kick Pad** | Speaker cone with Static paint, glowing orange ring, dust particles vibrating on it |
| **Breakable (Downbeat/explosive)** | Cracked concrete with visible rebar, or cracked porcelain with **orange** glowing fissures |
| **Secret hints** | **Violet**: a faint violet glow, violet graffiti tags ("??" in the Static mark), a violet light leaking from a vent grille, Resonance Sense chimes |
| **Locked door** | Fuse lock showing the needed **Fuse** shape + color: **Red ■ / Yellow ▲ / Blue ●** (deep blue, never cyan) |
| **Arena** | Arena spaces are lit brighter and flatter (enemy readability) than exploration spaces; Choir Seals are visible as dormant bone-lattice frames around the doorways before activation |
| **Hazard** | Heat shimmer (fire/solar), sparking water (electric), red-orange glowing floor markers (enemy AoE), white mist (Hymn Saturation) |
| **Enemy readability** | Every enemy gets a **rim light** in arenas (post-process or light function) so porcelain silhouettes pop against bright backgrounds. Backgrounds behind enemy sightlines must avoid pure white. |

### 4.1 Fuse Keys (`PKP_Fuse_Red/Yellow/Blue`)
* Human areas: heavy Concord **Fuse cartridges** (a 30 cm glass-and-steel fuse with a colored core).
* Choir areas: **Bell Keys** — small bells of colored light; same three colors & shapes.
* A mission uses 0–3 Fuses. Each Fuse is obtained through a mini-objective (an arena, a traversal challenge or a set piece), never just lying in a corridor.

---

## 5. Secrets — Rules

1. **Every secret gives something** (collectible, upgrade, Brass, Reprise, lore, or a big resource/power-up cache). Never empty.
2. **Every secret is hinted** by at least one of: violet light, violet Static tag, an out-of-place object (a pipe ending in a grille, a crack), a sound (Resonance Sense chime, a faint radio playing), a visible-but-unreachable item.
3. **Secret types to mix per mission:** hidden room (breakable wall), vent crawl-alternative (big vents — the Unsung doesn't crawl; vents are 300 cm tall "service ducts"), look-up (anchor above a doorway), traversal challenge (optional expert gap), Downbeat-breakable floor, backtracking (return to an area via a new route), timed (a switch opens a door for 10 s), arena reward (clear a Choir Mass).
4. **Map support:** the **Sounding Station** (`BP_SoundingStation` — a Static sonar rig: press interact, a sonar ping sweeps the level) reveals the full map and all collectible locations (as violet icons). Each mission has 1–2, usually off the main path.
5. **Density:** 10–16 secret items per mission (roughly: 1 Master, 1–2 Effigies, 2 Brass Caches, 1 Rig Core, 0–1 Heart Shard, 0–1 Pedal, 0–1 Mute Cell/Tab/Tape, 0–1 Reprise, 0–1 Requiem Key, 3–5 Archive Stones).
6. **Mission Replay:** after completion, missions can be replayed from Mission Select; collected items appear as **ghost** icons (translucent violet) and do not count twice.

---

## 6. Landmarks & Navigation

* Every mission has a **primary landmark** visible from most outdoor spaces and many windows (the Spire, the Aureole, the Tether ribbon, the Sun, the Clef). The landmark doubles as the "goal".
* **Compass ribbon** (top of HUD) shows objective, Sounding Station (if found), and nearby collectibles (with Resonance Sense).
* **Anti-backtracking:** one-way drops, collapsing paths and seal-locked doors keep the critical path forward; optional side areas always loop back.
* **"You are here" boards:** Concord facility maps on walls (flavor + orientation).
* **Getting lost:** if the player hasn't made objective progress for 3 minutes, a Static comms line gives a hint and the compass pulses (option: Off).

---

## 7. Greybox Standards (for AI builders)

| Material | Color | Use |
|---|---|---|
| `M_GRY_Floor` | Mid grey with a 1 m grid | Walkable floor |
| `M_GRY_Wall` | Light grey with a 1 m grid | Walls |
| `M_GRY_Traversal` | **Orange** | Grip Walls, anchors, Kick Pads, swing poles, grind rails |
| `M_GRY_Hazard` | **Red** | Hazards, kill volumes |
| `M_GRY_Secret` | **Violet** | Secret entrances & items |
| `M_GRY_Arena` | Light blue translucent volume | Arena volumes (editor only) |
| `M_GRY_Breakable` | Yellow with cracks | Breakable walls/floors |
| `M_GRY_Cover` | Dark grey | Full cover blocks |

**Greybox acceptance:** a level is "greybox complete" when (a) the critical path is completable start-to-finish, (b) all arenas are functional with final enemy compositions, (c) all traversal elements work, (d) all secrets are placed with placeholder rewards, (e) a timed playthrough lands within ±20% of the mission's target duration.

---

## 8. Environmental Storytelling Guidelines

* **Human spaces tell human stories:** a Static barricade with a mixtape taped to it; a child's drawing of the Unsung; a CDF soldier's last log on a terminal; a jukebox still playing in an abandoned bar; collars stacked in a memorial.
* **Choir spaces tell erasure:** rows of identical gilded bodies; personal belongings (photos, rings, phones) gathered in neat, meaningless symmetrical piles; human writing slowly overgrown by sheet-music glyphs.
* **Progressive corruption:** within one mission, `CHOIR` overlay density rises as you approach the Spire (0% → 100%).
* **The Aureole:** always in the sky on Earth missions, reflecting the story's progress (bands removed per Archon).

---

## 9. Per-Level Checklist (Definition of Done)

- [ ] Critical path completable; no soft-locks (tested with `BP_TestBot` + a human-like playtest).
- [ ] Every arena follows §5.4 rules of `11_AI_and_Encounter_Design.md`.
- [ ] All secrets placed, hinted, reachable; Sounding Station reveals them.
- [ ] Fuse doors correct; no Fuse obtainable in a way that can be skipped by accident.
- [ ] Checkpoints at every arena start/end and before set pieces.
- [ ] Out-of-bounds recovery volumes cover all pits; `SafeGround` tagged correctly.
- [ ] Landmark visible; compass objective set for every segment.
- [ ] Music cues and ambience zones placed; radio/comms triggers placed.
- [ ] Performance budget met (see `20_Technical_Design_UE5.md` §9) in the heaviest arena.
- [ ] Mission timing within ±15% of target on Amplified.
