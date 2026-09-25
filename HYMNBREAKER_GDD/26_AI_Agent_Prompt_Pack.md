# 26 — AI Agent Prompt Pack

Copy-paste prompts for driving AI agents (with a **UE5 MCP** and a **Blender MCP**) through the build. Each prompt assumes the agent has read access to this GDD folder. Replace `<…>` placeholders. Always keep one **Lead/Integrator** conversation that reviews the output of the others (see `24_AI_Build_Roadmap.md`).

---

## 0. Universal Preamble (prepend to every prompt)

```
You are a senior game developer building HYMNBREAKER, a single-player modern boomer shooter in
Unreal Engine 5, using the tools available to you (UE5 MCP, Blender MCP, file system, shell).

Source of truth: the design document in HYMNBREAKER_GDD/. Priority when documents disagree:
25_Glossary_and_Canon.md > data/*.csv > the system doc for the topic > 14_Missions/ > everything else.

Rules:
1. Follow IDs and names from 25_Glossary_and_Canon.md exactly (asset names, DataTable rows, classes).
2. Units: 1 UU = 1 cm; times in seconds. Never hard-code tuning numbers — read them from DataTables
   or DataAssets (schemas in 20_Technical_Design_UE5.md §5; values in data/*.csv).
3. Greybox first (12_Level_Design_Standards.md §7), art later.
4. After each step: compile, run relevant automation tests, play-in-editor, take screenshots, and
   compare against the acceptance criteria. Report evidence.
5. Record non-trivial decisions in DECISIONS.md (what, why, alternatives). Record balance changes in
   BALANCE_LOG.md.
6. If the spec is ambiguous, choose the option most consistent with the pillars in
   00_Executive_Summary.md, implement it, and log it in DECISIONS.md. Do not stop to ask unless the
   decision is irreversible or contradicts the spec.
```

---

## 1. Lead / Integrator

**1.1 Milestone kickoff**
```
Read 24_AI_Build_Roadmap.md, Milestone <N>. Break it into tasks using the Task Template (§0.1),
each ≤ 1 day of agent work, with explicit spec references and acceptance criteria. Order them by
dependency. Output the task list as TASKS_M<N>.md at the project root.
```

**1.2 Milestone review**
```
Review the build for Milestone <N> against 24_AI_Build_Roadmap.md acceptance criteria and the
relevant Definitions of Done (§8). Play-test (PIE) each deliverable, collect telemetry
(hb.Telemetry.Dump) and screenshots, and write MILESTONE_REPORT_<N>.md with: done / not done /
known issues / metrics vs. targets / recommended fixes. Do not approve the milestone if any
acceptance item fails.
```

---

## 2. Systems Programmer

**2.1 Project foundation (Milestone 0)**
```
Create the UE5 C++ project "Hymnbreaker" per 20_Technical_Design_UE5.md §1–§3: plugins, rendering
settings, collision channels & profiles, Gameplay Tag hierarchy, folder structure, naming validator
(editor Python), .gitignore/Git LFS. Create row structs from §5 and import every CSV in data/ as a
DataTable (see data/README.md for tag/list handling). Create the four test maps (§10). Compile and
report any import errors.
```

**2.2 Player movement (Milestone 1)**
```
Implement AHBPlayerCharacter and UHBCharacterMovementComponent per 05_Player_Character_Movement_Controls.md
(§2–§8) with all values read from DA_PlayerTuning (fill it from data/player_tuning.csv). Include Surge,
double jump, coyote time, jump buffer, mantle (Motion Warping), Grip Wall, Swing Pole, Kick Pad arcs,
Harrow grapple with slingshot, safe-ground sampling and recovery. Build the TM_Movement gym with lanes
for every metric in 12_Level_Design_Standards.md §1 and verify each measurement (report a table of
spec value vs. measured value).
```

**2.3 Damage pipeline & resources**
```
Implement the damage pipeline in 20_Technical_Design_UE5.md §4.3 and the resource rules in
04_Core_Gameplay_Loop.md (§2–§12): FHBDamageEvent, IHBDamageable, UHBHealthComponent (Plating first,
Piercing), UHBStatusComponent (all states in §3), Falter rules (§3.1), Breakdown (§4), Shred formula
(§5.1), Distort (§6), Counter (§7), Gain/Overdrive (§8), pickups (§11), checkpoints & Reprises (§12).
Write Automation Specs for every formula and edge case. All tests must pass.
```

**2.4 Encounter Director**
```
Implement UHBCombatDirector, AHBEncounterArena, AHBSpawnPoint, AHBChoirSeal and UHBEncounterData
per 11_AI_and_Encounter_Design.md (§2, §4, §5) including attack tokens, aggression timer, threat caps,
wave triggers and difficulty scaling (§5.6). Author ENC_M01_05 from 14_Missions/M01_Tranquility_Deep.md
as data and run it in TM_Encounter with BP_TestBot 10 times; report completion times and any stuck enemies.
```

**2.5 Adaptive music**
```
Implement UHBMusicSubsystem per 18_Audio_and_Dynamic_Music.md §3: Quartz clock per track, synchronized
MetaSound stems, states driven by Gain and combat events, bar/beat-quantized transitions, stingers,
OnBeat/OnBar events. Create a test track asset with placeholder stems at 160 BPM and demonstrate every
state transition in TM_Encounter (record a video or log with timestamps).
```

---

## 3. Gameplay / AI Designer

**3.1 Enemy implementation**
```
Implement <ENM_ID> per its entry in 09a/09b/09c_Bestiary (stats from data/enemies.csv, attacks from
data/attacks.csv). Create DA_Enemy_<Name>, the Behavior Tree (family in 11_AI_and_Encounter_Design.md
§1.1), attack montages with telegraph notifies, hit zones/weak points, status reactions, Breakdown hooks,
drops and audio hooks. Validate in TM_EnemyGallery against the Enemy Definition of Done
(24_AI_Build_Roadmap.md §8.2) and report each checklist item with evidence.
```

**3.2 Boss implementation**
```
Implement <BOSS_ID> per 10_Bosses.md (§<n>): DA_Boss data with phases, attack pool, arena events,
add waves, music cues, checkpoints and the Boss Breakdown. Build the arena in greybox exactly per the
spec dimensions. Run 5 TestBot runs + your own manual runs on Amplified; report duration, deaths and
cause of each death (every death must be attributable to a telegraphed attack).
```

**3.3 Encounter tuning**
```
Run telemetry on every arena in <Mxx>. Compare against 04_Core_Gameplay_Loop.md §13 and
23_Difficulty_Balance_Accessibility.md §2. Propose and apply changes (wave composition first, enemy
stats second, player stats last). Log every change in BALANCE_LOG.md with before/after numbers.
```

---

## 4. Level Builder

**4.1 Mission greybox**
```
Build <Mxx> in greybox from 14_Missions/<file>.md using the GRY kit and the metrics in
12_Level_Design_Standards.md. First write Tools/Layouts/<Mxx>.json (areas, modules, transforms,
traversal elements, spawn points, hold points, perches, secrets, checkpoints) and a Python script that
spawns it; then refine by hand. Place all encounters (as UHBEncounterData assets), secrets with
placeholder rewards, Fuse doors, Sounding Stations, music/ambience volumes and comms triggers. Verify the
Mission Greybox DoD (24 §8.3) and report the critical-path time on Amplified.
```

**4.2 Art pass**
```
Replace the greybox in <Mxx> area <A_Mxx_nn> with the <KIT> kit per 17_Art_Direction.md and the
mission's §"Art & Lighting". Keep collision and metrics identical (compare against the greybox with the
movement gym's measuring tool). Light it per 17 §7 (arenas brighter and flatter; enemy rim light).
Provide before/after screenshots from 3 fixed viewpoints and a perf capture of the area's arena.
```

---

## 5. 3D Artist (Blender MCP)

**5.1 Kit module batch**
```
In Blender, following 21_Blender_Asset_Pipeline.md exactly (units 0.01/cm, facing −Y, corner pivots,
50 cm grid, UCX collision, naming), create the <KIT> modules listed in 22_Asset_Manifest.md §F:
<list>. Use the procedural approach in §9.1. Run hb_validate() on each, export with hb_export_fbx(),
and import into UE at /Game/HB/Environment/Kits/<KIT>/ with the settings in §8. Screenshot each module
next to REF_PlayerCapsule and the 300×400 door reference.
```

**5.2 Creature**
```
Create <ENM_ID> following its "Visual design" in the bestiary and 17_Art_Direction.md §4 (Choir design
language). Use an AI 3D generator for the base mesh if available, then perform the mandatory cleanup in
21 §9.3, fit skeleton class <SKC_…> (§5), weight paint, author the porcelain _M mask (§6), bake
textures, and validate deformation with a test animation. Respect the budget in §3. Export and import to
UE; provide turntable screenshots and a deformation test.
```

**5.3 First-person weapon**
```
Model <WPN_ID> per 06_Arsenal_Weapons.md (Visual section) and 17_Art_Direction.md. Pivot at the grip,
barrel along −Y, sockets SOCKET_Muzzle / SOCKET_Eject / SOCKET_Mod. Budget and texel density per 21 §3.
Create the world-pickup LOD. Export, import, attach to SK_Unsung_Arms weapon_r, and screenshot in FP at
FOV 100 with viewmodel FOV 75.
```

---

## 6. Rigger / Animator

```
Create the animation set for <ENM_ID/Player> listed in its bestiary entry ("Animations") and
05 §11 for the player. Use skeleton class <SKC_…>. Author at 30 fps (FP weapons 60 fps), root motion for
travelling moves, and add NOTIFY_ markers (21 §7). For Breakdowns, author synchronized pairs
A_BRK_<Enemy>_<Variant>_Player/_Victim of identical length (04 §4 style guide: impact → rip → finish,
0.8–1.9 s by tier). Import to UE, create montages, verify sync with Motion Warping in TM_EnemyGallery.
```

---

## 7. VFX Artist

```
Create the master material M_Porcelain_Master with the parameters in 17_Art_Direction.md §4.2 and the
Niagara systems for <list> following the VFX language in §8 (cyan = dodge, gold torus = parry, ember =
player). Respect budgets in 20_Technical_Design_UE5.md §9. Provide a gallery map showing every effect
looping with labels.
```

---

## 8. Audio Designer

```
Produce <MUS_ID> per 18_Audio_and_Dynamic_Music.md: fixed BPM <n>, key <k>, 8 stems (DRM, BAS, RGT,
LEAD, CHR, SYN, OVD, BRK) that loop seamlessly and layer cleanly, plus intro stinger, outro and heavy
stinger. Deliver as 48 kHz WAVs named per §9, create the DA_MusicTrack asset, and test every state
transition in TM_Encounter. Choir lyrics must use the invented phonetic language (§2), never Latin or
real liturgy.
```

---

## 9. UI Developer

```
Implement the HUD per 19_UI_UX_and_HUD.md §2 using UMG + CommonUI with view-model bindings (no Tick
polling). Include options from §2.2 and the accessibility hooks from §5 (colorblind token remaps,
subtitles with directional captions, HUD scale). All strings in String Tables. Provide screenshots of
the HUD in normal combat, Overdrive, low health, boss fight and mech modes, on KBM and gamepad glyphs.
```

---

## 10. QA Agent

```
Test <Mxx / system> against its spec and DoD. Produce a bug list (BUGS.md) with: ID, severity
(blocker/critical/major/minor), steps to reproduce, expected (with GDD file + section), actual,
evidence (screenshot/log). Run BP_TestBot on every arena (10 runs each) and report soft-locks, stuck
enemies, and completion times. Run a perf capture in the heaviest arena and compare to
20_Technical_Design_UE5.md §9.
```
