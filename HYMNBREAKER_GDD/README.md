# HYMNBREAKER — Game Design Document (Master Index)

> **"The universe is being sung into one perfect voice. You are the wrong note."**

**HYMNBREAKER** (working title) is a single-player, first-person, high-speed "modern boomer shooter" in the tradition of *DOOM (2016)*, *DOOM Eternal* and *DOOM: The Dark Ages*: a legendary, silent warrior tearing through an otherworldly invasion with a brutal arsenal, a push-forward combat economy, huge handcrafted arenas and a heavy-metal soundtrack that reacts to how you play.

The IP is **original**. There are no demons, no Hell, no Mars corporation, no Slayer. Instead:

* The invaders are **the Choir** — beautiful, porcelain-and-gold, angel-shaped horrors created by **the Hymn**, a cosmic song that "tunes" living things into one collective voice.
* The hero is **the Unsung** — the one being the Hymn has never been able to sing. Armored in black iron and rust, powered by a heart that beats out of time, fueled by noise.
* The theme is **harmony vs. distortion**: the enemy wants perfect, silent unity; you are chaos, individuality, and the loudest thing in the universe.

Target length: **30–40 hours** (27 campaign missions + hub + optional content).
Target engine: **Unreal Engine 5** (built with AI agents using a **UE5 MCP** and a **Blender MCP**).

---

## How to use this document (for AI builders — read this first)

1. **This folder is the single source of truth.** If two files disagree, the priority order is:
   1. `25_Glossary_and_Canon.md` (names, IDs, spellings)
   2. `data/*.csv` (numeric tuning values)
   3. The system document for that topic (e.g. `06_Arsenal_Weapons.md`)
   4. Mission documents (`14_Missions/`)
   5. Everything else
2. **IDs are law.** Every enemy, weapon, mission, encounter, pickup, collectible and asset has an ID (e.g. `ENM_Chorister`, `WPN_Breacher`, `M04`, `ENC_M04_03`, `SM_KIT_BRU_Wall_400x400`). Use them verbatim for asset names, DataTable row names and Blueprint names.
3. **Units:** 1 Unreal Unit (uu) = 1 cm. All distances in this document are in **cm** unless marked `m`. Times in seconds. Angles in degrees.
4. **Build greybox first, art second.** Every level must be fully playable in greybox (BSP/modeling-tool blockout or `SM_GRY_*` blocks) before any art pass. See `24_AI_Build_Roadmap.md`.
5. **Tuning lives in data, not code.** Weapon damage, enemy HP, cooldowns, spawn waves etc. are defined in DataTables/DataAssets (schemas in `20_Technical_Design_UE5.md`, values in `data/`). Never hard-code a tuning number in a Blueprint graph or C++ function.
6. **Priorities:** content is tagged **P0** (required for the **Act I Alpha**: M01–M04 + hub States 1–2; the **Vertical Slice** milestone is its first half, M01–M02), **P1** (required for full release), **P2** (polish/stretch). Build P0 → P1 → P2 following `24_AI_Build_Roadmap.md`.
7. **When something is unspecified**, follow the pillars in `00_Executive_Summary.md` and the nearest analogous spec. Log the decision in a `DECISIONS.md` file at the project root so later agents stay consistent.

---

## Document Index

### Part A — Vision & Narrative
| File | Contents |
|---|---|
| [`00_Executive_Summary.md`](00_Executive_Summary.md) | Pitch, pillars, USPs, target audience, scope, comparable titles |
| [`01_World_and_Lore_Bible.md`](01_World_and_Lore_Bible.md) | Cosmology, the Hymn, the Oreth, timeline, factions, locations, technology |
| [`02_Characters.md`](02_Characters.md) | Full cast: bios, arcs, visual & voice direction |
| [`03_Story_and_Campaign_Narrative.md`](03_Story_and_Campaign_Narrative.md) | Act-by-act plot, story beats per mission, ending, themes |
| [`03b_Cutscenes_Dialogue_and_Radio.md`](03b_Cutscenes_Dialogue_and_Radio.md) | Cutscene list & scripts, "Radio Free Static" mission intros, barks |
| [`03c_Archive_Codex.md`](03c_Archive_Codex.md) | In-game codex ("Archive") entries |

### Part B — Gameplay Systems
| File | Contents |
|---|---|
| [`04_Core_Gameplay_Loop.md`](04_Core_Gameplay_Loop.md) | Combat loop, resource economy, enemy states, Gain/Overdrive, damage model |
| [`05_Player_Character_Movement_Controls.md`](05_Player_Character_Movement_Controls.md) | Movement metrics, traversal, camera, input maps, first-person animation |
| [`06_Arsenal_Weapons.md`](06_Arsenal_Weapons.md) | All 12 weapons, mods, stats, upgrades, masteries |
| [`07_Equipment_and_Abilities.md`](07_Equipment_and_Abilities.md) | Harrow, Frag/Hush Charges, Distort, Power Chord, Downbeat, Counter, Overdrive, power-ups |
| [`08_Progression_and_Economy.md`](08_Progression_and_Economy.md) | Brass, Rig Cores, Heart Shards, Pedals, collectibles, unlock schedule |
| [`09a_Bestiary_Fodder.md`](09a_Bestiary_Fodder.md) | Tier 1 enemies |
| [`09b_Bestiary_Heavy.md`](09b_Bestiary_Heavy.md) | Tier 2 enemies |
| [`09c_Bestiary_SuperHeavy_Hazards_Titans.md`](09c_Bestiary_SuperHeavy_Hazards_Titans.md) | Tier 3 enemies, Gilded variants, hazards, mech-scale enemies |
| [`10_Bosses.md`](10_Bosses.md) | All boss & mini-boss fights |
| [`11_AI_and_Encounter_Design.md`](11_AI_and_Encounter_Design.md) | AI architecture, attack tokens, spawning, encounter director, arena rules |
| [`12_Level_Design_Standards.md`](12_Level_Design_Standards.md) | Metrics, traversal elements, modular kits, secrets rules, readability |

### Part C — Content
| File | Contents |
|---|---|
| [`13_Campaign_Structure.md`](13_Campaign_Structure.md) | Mission list, pacing chart, unlock schedule, collectible distribution |
| [`14_Missions/`](14_Missions/) | One file per mission, **M01–M27** (layout, encounters, secrets, set pieces, music, assets) |
| [`15_Quietus_Hub.md`](15_Quietus_Hub.md) | The hub ship: rooms, NPCs, upgrade stations, vaults, progression |
| [`16_Optional_Content_and_Modes.md`](16_Optional_Content_and_Modes.md) | Requiem Gates, Choir Masses, Pit Trials, Encore missions, Tabs (cheats), NG+ |

### Part D — Presentation
| File | Contents |
|---|---|
| [`17_Art_Direction.md`](17_Art_Direction.md) | Visual language, palettes, materials, lighting, VFX, gore, biome kits |
| [`18_Audio_and_Dynamic_Music.md`](18_Audio_and_Dynamic_Music.md) | Adaptive music system, track list, SFX, VO, mix |
| [`19_UI_UX_and_HUD.md`](19_UI_UX_and_HUD.md) | HUD, menus, hub UIs, map, feedback, accessibility UI |

### Part E — Production (for AI builders)
| File | Contents |
|---|---|
| [`20_Technical_Design_UE5.md`](20_Technical_Design_UE5.md) | Project setup, architecture, C++/BP classes, data schemas, performance budgets |
| [`21_Blender_Asset_Pipeline.md`](21_Blender_Asset_Pipeline.md) | Modeling/rigging/texturing/export standards and MCP workflows |
| [`22_Asset_Manifest.md`](22_Asset_Manifest.md) | Master asset list with IDs and priorities |
| [`23_Difficulty_Balance_Accessibility.md`](23_Difficulty_Balance_Accessibility.md) | Difficulty modes, balance targets, accessibility options |
| [`24_AI_Build_Roadmap.md`](24_AI_Build_Roadmap.md) | Milestones, task order, acceptance criteria, QA/test plans |
| [`25_Glossary_and_Canon.md`](25_Glossary_and_Canon.md) | Canonical names, spellings, IDs, terminology |
| [`26_AI_Agent_Prompt_Pack.md`](26_AI_Agent_Prompt_Pack.md) | Copy-paste prompts for each AI builder role and milestone |
| [`data/`](data/) | CSV tuning tables ready for UE5 DataTable import (see `data/README.md`) |
| [`templates/`](templates/) | `DECISIONS.md`, `BALANCE_LOG.md`, `MILESTONE_REPORT.md`, `TASK.md`, `BUGS.md`, and an example layout-as-data JSON |

---

## The Game in One Page

| | |
|---|---|
| **Genre** | First-person action shooter, single-player campaign |
| **Feel** | *DOOM Eternal* speed + *DOOM (2016)* brutality + *The Dark Ages* parry weight |
| **Hero** | The Unsung — silent, ancient, unstoppable; a heart that cannot be synchronized |
| **Enemy** | The Choir — angelic body-horror created by a cosmic song called the Hymn |
| **Stakes** | A halo of light — the **Aureole** — is forming around Earth. When its chord is complete, every human mind will be "tuned" into the Choir. Seven **Archons** and one human **Herald** sustain it. |
| **Core loop** | Execute staggered enemies for **Health** (Breakdowns), harpoon-rip fodder for **Ammo** (Harrow Shred), blast enemies with static for **Plating** (Distort), build **Gain** to unleash **Overdrive** |
| **Arsenal** | 9 standard weapons with 2 mods each, 3 super weapons (Silencer, The Axe, The Larynx) |
| **Structure** | 6 Acts, 27 missions, hub ship (**the Quietus**), 7 optional **Requiem Gates**, Encore (remix) missions |
| **Length** | ~34 h first playthrough on Normal; 40+ h completionist |
| **Music** | Adaptive metal soundtrack; the dynamic mix follows your **Gain** meter; human choirs vs. down-tuned guitars |
| **Rating target** | Mature 17+ (intense violence, blood and gore, strong language) |

---

## Top-Level Canon Rules (never break these)

1. **The Unsung never speaks.** No voiced lines, ever. Characterization is through action, gesture and animation.
2. **Enemy language is sacred/choral** (hymn, cantor, psalm, requiem, bell). **Player language is metal/electric** (distortion, gain, overdrive, feedback, riff). Do not cross the streams when naming new content.
3. **Color language is absolute:**
   * **Cyan/white light** = enemy attacks (dodge them).
   * **Gold** = parryable enemy attacks (Counter them) and enemy weak-point glow.
   * **Ember orange/red** = the player's abilities, the Unsung's glow, "Faltering" enemies (executable).
   * **Red** = Health pickups. **Acid green** = Plating (armor) pickups. **White + type color** = ammo.
   * **Violet** = secrets and collectibles.
4. **No real-world religions, flags, brands or real people.** The Choir's iconography is concentric rings, halos, tuning forks, bells, staves and waveforms — never crosses, crescents, stars of David or scripture.
5. **Every combat space must support the push-forward loop:** at least one Harrow target class, room to dash in 2 directions, and a vertical option.
