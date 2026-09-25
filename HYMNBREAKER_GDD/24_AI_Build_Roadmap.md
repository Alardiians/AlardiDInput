# 24 — AI Build Roadmap

A step-by-step production plan for AI agents building HYMNBREAKER with a **UE5 MCP** and a **Blender MCP**. The plan is **milestone-driven**: every milestone ends with a playable build, measurable acceptance criteria, and a review before the next milestone starts.

**Golden rules**
1. **Playable first, pretty later.** Greybox → systems → encounters → art → audio → polish.
2. **Vertical before horizontal.** Make one slice feel great before building 27 missions.
3. **Data, not constants.** All tuning in DataTables/DataAssets (`data/*.csv`).
4. **Test everything you build** (automation specs + a PIE play session + screenshots).
5. **Write it down.** Every non-trivial decision → `DECISIONS.md`; every balance change → `BALANCE_LOG.md`; every milestone → `MILESTONE_REPORT_<n>.md` (what's done, what's not, known issues, metrics).

---

## 0. Agent Roles (suggested)

| Role | Tools | Owns |
|---|---|---|
| **Lead / Integrator** | Both MCPs, repo | Milestone planning, task breakdown, reviews, merges, `DECISIONS.md` |
| **Systems Programmer** | UE (C++), editor Python | Framework, movement, weapons, abilities, damage, AI base, encounters, save, music sync |
| **Gameplay/AI Designer** | UE (BP, data) | Enemy BTs, attack data, encounter data, tuning, boss phases |
| **Level Builder** | UE MCP (+ layout scripts) | Greybox layouts, traversal, secrets, set dressing, lighting |
| **3D Artist** | Blender MCP | Kits, props, characters, weapons (models, UVs, textures) |
| **Rigger/Animator** | Blender MCP, UE | Rigs, animation sets, Breakdown pairs, retargeting |
| **VFX Artist** | UE (Niagara, materials) | VFX and master materials |
| **Audio Designer** | Audio tools, UE (MetaSound) | Music stems, SFX, VO pipeline, mix |
| **UI Developer** | UE (UMG/CommonUI) | HUD, menus, hub UIs |
| **QA Agent** | UE (automation, PIE) | Test plans, bug reports, perf captures, regression checks |

A single agent may play several roles; the **Lead** always reviews milestone acceptance.

### 0.1 Task Template (use for every task)
```
TASK-ID: <Milestone>-<Area>-<nn>        e.g., M2-AI-04
Title: Implement Chorister perch-hopping behavior
Spec refs: 09a §6, 11 §3, 20 §4.4
Inputs: SK_Chorister (placeholder ok), DT_Enemies row ENM_Chorister, DT_Attacks rows
Deliverables: BT_Agile, BTTask_LeapToPerch, EQS_PickPerch, BP_ENM_Chorister config
Acceptance: In TM_EnemyGallery, a Chorister (a) never idles > 3 s, (b) leaps between ≥ 3 perches,
            (c) throws cyan notes (cooldown 1.8 s) and gold notes (6 s) with correct telegraphs,
            (d) dodges when aimed at for 0.8 s, (e) automation spec AI_Chorister passes
Evidence: screenshots/video, test log, perf stat
```

---

## MILESTONE 0 — Foundation (Target: 1–2 weeks)

**Tasks**
1. Create C++ project `Hymnbreaker` on the chosen UE 5.x; enable plugins (`20` §1.1); set rendering settings.
2. Folder structure (`20` §2), naming validator (editor Python) and Data Validation rules.
3. Collision channels/profiles, Gameplay Tag hierarchy (`20` §1.2–1.3).
4. Import `data/*.csv` as DataTables with row structs (`20` §5).
5. Greybox kit `GRY` (blocks, ramps, stairs, grid materials `M_GRY_*`).
6. Test maps: `TM_Movement`, `TM_Weapons`, `TM_EnemyGallery`, `TM_Encounter` (empty shells).
7. Repo hygiene: `.gitignore` for UE (Binaries, Intermediate, Saved, DerivedDataCache), Git LFS for binaries, `DECISIONS.md`, `BALANCE_LOG.md`.
8. Blender: template `.blend` (units, grid, collections, validation + export scripts from `21`); the **axis arrow test** round-trip.

**Acceptance**
- [ ] Project compiles; opens without errors/warnings in the log (except engine noise).
- [ ] DataTables import with no errors; spot-check 5 rows.
- [ ] Arrow test passes (Blender −Y → UE +Y); documented in `DECISIONS.md`.
- [ ] Greybox kit placed in `TM_Movement` with measurement markers (1 m grid visible).

---

## MILESTONE 1 — Player Core (Target: 2–3 weeks)

**Tasks**
1. `AHBPlayerCharacter` + `UHBCharacterMovementComponent`: ground/air values, double jump, coyote time, jump buffer, **Surge**, **mantle** (Motion Warping), no fall damage, safe-ground sampling & recovery volumes (`05`).
2. Camera: FOV (world & viewmodel), bob, landing dip, shakes, FOV kicks, hit-stop.
3. Enhanced Input: all actions & contexts (`05` §10) with default KBM/gamepad bindings; rebinding UI stub.
4. Placeholder FP arms + **Breacher** (hitscan pellets, falloff, pump cycle), punch (3-hit), hit markers.
5. Damage pipeline (`20` §4.3): `FHBDamageEvent`, `IHBDamageable`, health/plating component, damage types, difficulty multipliers.
6. `TM_Movement` gym: every metric in `12` §1 built as labeled test lanes (ledges 45/140/270/400 cm, gaps 500/900/1400/2000 cm, Harrow anchor spacing lanes, Kick Pad targets).
7. Traversal actors: Harrow Anchor + Harrow grapple, Grip Wall, Swing Pole, Kick Pad.

**Acceptance (measured in `TM_Movement`)**
- [ ] Max ground speed 950 ±10 cm/s; single-jump apex 152 ±5 cm; double-jump apex 286 ±8 cm.
- [ ] Surge: 600 ±25 cm in 0.15 s; 2 charges; 1.25 s recharge.
- [ ] All labeled ledges/gaps are passable/impassable exactly as `12` §1 specifies.
- [ ] Harrow grapple: 3000 cm/s, slingshot exit; chains across the anchor lane.
- [ ] Breacher: 140 dmg at ≤ 800 cm on a dummy; falloff matches the table.
- [ ] 60 FPS in the gym at 1440p; no frame-rate-dependent behavior (test at 30 and 144 FPS caps).

---

## MILESTONE 2 — Combat Loop Core (Target: 3–4 weeks)

**Tasks**
1. `AHBEnemyBase`, `AHBAIController`, perception, BTs `BT_MeleeSwarm`, `BT_RangedSoldier`, `BT_Agile`; attack component with telegraphs (cyan & gold).
2. Enemies (placeholder meshes OK): **Thrall, Trooper, Chorister** with stats from `DT_Enemies`.
3. Status component: **Faltering** (ember glow placeholder), Stunned, Distorted, Hushed.
4. **Breakdown** (placeholder synced animations; invulnerability; Health drops; Power Chord charge).
5. **Harrow Shred** (ammo formula `04` §5.1), **Distort** (Plating shards), **Counter** (parry window; reflect projectiles), **Gain/Overdrive**.
6. Resource drops with magnet; placed pickups.
7. `UHBCombatDirector`: tokens, aggression, threat cap.
8. Encounter system: `AHBEncounterArena`, spawn points (Hymnfall/Emerge/Drop), Choir Seals, waves from `UHBEncounterData`, loot fountain, checkpoint.
9. Debug console commands (`11` §8); `BP_TestBot` v1.
10. Automation specs: damage math, Falter thresholds, Shred formula, Gain, Counter windows, tokens.

**Acceptance**
- [ ] `TM_Encounter` runs `ENC_M01_05` (Pump Hall composition) end-to-end in greybox.
- [ ] A tester can finish the arena using only aggression: telemetry shows ≥ 65% of Health from Breakdowns, ≥ 55% ammo from Shreds, ≥ 60% Plating from Distort/Counter.
- [ ] Tokens: never more than the configured number of simultaneous attackers (verified with `hb.AI.ShowTokens`).
- [ ] `BP_TestBot` clears the arena in < 10 min with no soft-locks (10 consecutive runs).
- [ ] All automation specs pass.

---

## MILESTONE 3 — Vertical Slice (Greybox → Final) : M01 + M02 + Hub State 1 (Target: 6–8 weeks)

**3A — Greybox (2–3 weeks)**
1. Build **M01** and **M02** fully in greybox from their mission docs (layouts, encounters, secrets with placeholder rewards, set pieces as blockout sequences).
2. Riveter, Static Rifle, Frag Charge; Bulwark, Vesper, Cantor (placeholder art).
3. HUD v1 (all P0 elements), pause menu, map v1 (Sounding Station reveal), save/checkpoints.
4. Music system v1 (`UHBMusicSubsystem`, Quartz, stems with placeholder loops at the correct BPMs, state changes, stingers, beat events).
5. Hub State 1 greybox: Launch Bay (Drop Coffin launch), Armory (Brass upgrades), Rig Bay, Heart Chamber, Bridge.
6. Progression v1: Brass, Rig Cores, Heart Shards, Mod Crates, collectibles tracking.

**3B — Art & Audio (4–5 weeks)**
1. Kits: `BRU`, `ORB` (lunar variant), `CHOIR` overlay starter, `SHIP` (hub subset).
2. Characters: Unsung arms/body, Thrall (lab & EVA sets), Trooper, Bulwark, Chorister, Vesper, Cantor; Lund, Vire, Wren, Tamsin, Juno, Aurelia (hologram).
3. Weapons final: Breacher, Riveter, Static Rifle (+ Frag Slug mod); equipment VFX.
4. Animations: arms set for these weapons & abilities; Breakdown pairs (Thrall ×4, Trooper ×3, Chorister ×4, Bulwark ×2, Vesper ×2, Cantor ×2).
5. VFX: Hymnfall, seals, halos, shatter, resource orbs, Distort, Counter, projectiles.
6. Audio: M01–M02 music (full stems), weapon/enemy SFX, VO for M01–M02 & hub (placeholder TTS acceptable until final VO), `CIN_M01_*`, `CIN_M02_*`.
7. Lighting passes; performance pass.

**Acceptance (Vertical Slice)**
- [ ] M01 + M02 playable start-to-finish on all 6 difficulties; durations within ±15% of targets.
- [ ] Cold open delivers: 6 s silence → chord → visor boot (reviewed by the Lead).
- [ ] All mission-doc secrets present & functional; Sounding Station reveals them.
- [ ] 60 FPS on target hardware in the heaviest arena (M02 Crown Chamber).
- [ ] Blind playtest (if humans available) or scripted evaluation: first-time players understand Breakdown/Shred/Distort by the end of M02 (post-session quiz ≥ 80%).
- [ ] `MILESTONE_REPORT_3.md` with metrics & known issues.

---

## MILESTONE 4 — Act I Complete (M03, M04, Hub State 2) (Target: 6–8 weeks)

**Tasks**
1. M03 (moving arenas: climber car descent & roof ride; spin-gravity visual corridors; Plectrum & Bridge objectives), M04 (city, crowds VAT, allies, **Ionian** boss).
2. Gravedigger, Hammerfall (+ mods Tack Scope, Heat Burst, Arc Beam); Hush Charge, Overdrive (full music Overdrive stem), Downbeat, Power Chord; power-ups (Amp, Overdrive Surge).
3. Enemies: Crescendo, Ophan, Wailer, Seraph, Canon; Hymn Pylon; Choir Masses.
4. Boss framework (`AHBBossBase`, phases, boss bar, boss Breakdown) + **Ionian**.
5. Hub State 2: Listening Room, Effigy Gallery, The Pit (free practice).
6. Kits: `CITY` (M04 subset), `ORB` (Apex/Tether), sky system with the 8-band Aureole.

**Acceptance**
- [ ] Act I (M01–M04) playable end-to-end (~4.5 h on Amplified), including all secrets and challenges.
- [ ] Ionian fight: 6–10 min first attempt on Amplified (telemetry across ≥ 5 runs), no unreadable deaths (every death attributable to a telegraphed attack).
- [ ] Crowd scenes (M04) hold 60 FPS with ≥ 10,000 VAT agents visible.
- [ ] Aureole band removal persists across missions and the hub.

**→ Act I Alpha review.** Decide go/no-go on the full production scope (see §10 Scope Tiers).

---

## MILESTONE 5 — Systems Complete (Target: 6–8 weeks, can overlap M6)

1. All weapons & mods & masteries (`06`), Silencer, Axe, Larynx (P2 but systems-ready).
2. All abilities & upgrades (Rig tree, Heart tracks, **Pedalboard** + 16 Pedals & Boutiques).
3. **All enemies** in greybox/placeholder with final AI (`09a–c`), Gilded variants, Echo possession, Fugue illusions, Reverie illusions.
4. Traversal: Grind Rails, Note-Platforms (Quartz), gravity seams, loop volumes, chord rotators.
5. Hazards: solar exposure, Hymn Saturation, flooding water levels, beam lines, molten/fire/electric.
6. Mech: `AHBAnvilPawn` + titans framework; Broadside ability.
7. Collectibles & modes: Requiem Gates, Pit Trials, Tabs, Mission Select, NG+ hooks, Encore hooks.
8. Enemy Gallery complete (`TM_EnemyGallery`: every enemy spawnable with its answer weapon).

**Acceptance**
- [ ] Each enemy passes its **Enemy DoD** (§8.2).
- [ ] Each weapon passes the **Weapon Feel Checklist** (`06` §14).
- [ ] Automation specs for all systems pass.

---

## MILESTONES 6–10 — Content Production by Act

For each Act (II: M05–M09 · III: M10–M14 · IV: M15–M19 · V: M20–M24 · VI: M25–M27):

| Step | Output | Gate |
|---|---|---|
| 1. Greybox | All missions of the Act playable in greybox with final encounters | Mission Greybox DoD (§8.3) |
| 2. Encounter tuning | Telemetry-driven balancing | Targets in `04` §13 & `23` §2 |
| 3. Bosses & set pieces | Boss fights and scripted sequences | Boss DoD (§8.4) |
| 4. Art pass | Kits, characters, VFX, lighting | Art DoD (§8.5) |
| 5. Audio pass | Music stems, SFX, VO, radio intros | Audio DoD (§8.6) |
| 6. Polish & perf | Bugs, perf captures, accessibility checks | Act acceptance |

**Act acceptance:** the Act plays end-to-end on all difficulties; durations within ±15%; 60 FPS on target hardware in every arena; zero blocker/critical bugs; `MILESTONE_REPORT_<n>.md` filed.

**Suggested order inside acts:** build the **boss mission first** (hardest, most unique), then the others.

---

## MILESTONE 11 — Optional Content & Meta (Target: 3–4 weeks)

Requiem Gates (7), Choir Masses (35 — data-driven, fast), Pit Trials (13), Encore missions (6), Tabs (12), NG+ "Reissue", Unsung mode, Custom difficulty, achievements (40), Wardrobe/cosmetics.

---

## MILESTONE 12 — Final Polish & Release Candidate (Target: 4–6 weeks)

* Full-game playthroughs on every difficulty (bot + human if available).
* Performance: all missions meet `20` §9 budgets; scalability presets validated on low/mid/high hardware.
* Accessibility audit against `23` §3 (every option implemented & tested).
* Localization readiness (all strings in String Tables; pseudo-localization pass for text expansion).
* Audio final mix (loudness targets), subtitle timing.
* Save compatibility & corruption tests; Unsung permadeath edge cases (crash during death, alt-F4).
* Crash-free sessions ≥ 99.5% over automated soak tests (8 h bot runs).

---

## 8. Definitions of Done

### 8.1 Global
Spec-compliant · data-driven · no errors/warnings in logs · automation specs pass · PIE-tested · perf within budget · accessibility options respected · documented (`DECISIONS.md` if applicable).

### 8.2 Enemy DoD
- [ ] Stats, attacks, telegraphs (visual + audio + caption) exactly per bestiary.
- [ ] Tokens respected; readable at 60+ m (halo tier); weak points functional; Falter/Breakdown/Shred/Distort/Hush/Counter interactions correct.
- [ ] 2–6 Breakdowns + generic fallback; dismemberment & shatter; progressive crack material.
- [ ] Signature audio set; colorblind-safe telegraphs.
- [ ] Spawns via all allowed methods; navigation robust (no stuck in 20 bot runs).
- [ ] Archive entry with "How to fight".

### 8.3 Mission Greybox DoD
See `12` §7 & §9: critical path complete; all arenas with final compositions; traversal; secrets (placeholders ok); checkpoints; timing ±20%.

### 8.4 Boss DoD
- [ ] Phases, attacks & telegraphs per `10`; resource adds functioning.
- [ ] 5 bot runs + 3 human-style runs: no unreadable deaths; duration in target range.
- [ ] Phase checkpoints; music phase changes; boss Breakdown finale.

### 8.5 Art DoD
Asset DoD (`21` §10) for every asset + lighting pass (arena readability rules `17` §7) + no visual bugs at 3 random viewpoints per area.

### 8.6 Audio DoD
All events have sounds; music states transition bar-accurately; stingers quantized; VO subtitled; loudness in range; silence moments truly silent.

---

## 9. Risk Register

| Risk | Impact | Mitigation |
|---|---|---|
| **Animation volume** (Breakdowns ×70, creature sets) | High | Share skeleton classes; retarget humanoid libraries; generic fallback Breakdowns; prioritize P0 enemies; procedural additive layers for variety |
| **AI-generated meshes need heavy cleanup** | High | Mandatory cleanup steps (`21` §9.3); budget time; prefer procedural/kitbash for hard-surface |
| **MCP limitations** (graph editing, batch ops) | Medium | C++ + editor Python for heavy lifting; layout-as-data scripts |
| **Performance** (Lumen, crowds, particles, 26 enemies) | High | Budgets from day one; perf captures every milestone; scalability presets; crowds via VAT/impostors |
| **Scope (27 missions)** | High | Scope tiers (§10); build Act I to Alpha first; reuse kits (M18 is deliberately a remix mission) |
| **Music production volume** (~70 stemmed tracks) | Medium | Shared stem templates per BPM/key; reuse motifs; diegetic variants from existing stems |
| **The Last Broadcast audio** | Medium | Start collecting voices early (M6); fallback: 60 distinct voices layered with granular processing |
| **Consistency across agents** | High | This GDD as source of truth; IDs; `DECISIONS.md`; Lead review at every milestone |
| **Readability** (gold architecture vs. gold parry cues) | Medium | Color rules in `17` §2; shape coding; playtests in every biome |

---

## 10. Scope Tiers & Cut List

| Tier | Contents | Est. length |
|---|---|---|
| **Tier A — Act I Game** | M01–M04, hub States 1–2, 5 weapons, all P0 enemies, Ionian | ~4.5 h |
| **Tier B — Core Campaign** | + Acts II–III (M05–M14), all standard weapons, Silencer | ~17 h |
| **Tier C — Full Campaign** | All 27 missions, all bosses | ~34 h |
| **Tier D — Complete** | + Requiem Gates, Larynx, Pit Trials, Encore, NG+, Unsung mode | 45–50 h |

**Cut order if needed (least → most painful):** Encore missions → Larynx → some Pit Trials → Tabs → M18 remix (merge into M17) → mech segment in M26 (make on-foot) → Choir Mass count halved → M14 hub-invasion reduced to 2 arenas → Leviathan (keep as a scripted set piece only).
**Never cut:** the core loop systems, the cold open, Ionian, Dorian, Aubade (M21), the Octave, the Last Broadcast finale.
