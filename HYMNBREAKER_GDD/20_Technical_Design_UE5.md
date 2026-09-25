# 20 — Technical Design (Unreal Engine 5)

This document tells AI builders **how to build** HYMNBREAKER in UE5: project setup, architecture, classes, data schemas, performance budgets and MCP workflow guidance. Where this document conflicts with personal preference, follow this document; log justified deviations in `DECISIONS.md`.

---

## 1. Engine & Project Setup

| Item | Decision |
|---|---|
| Engine | **Unreal Engine 5.4+** (use the newest stable 5.x your UE MCP supports; keep the whole project on one version) |
| Project type | **C++ project** named `Hymnbreaker` (module `Hymnbreaker`), plus an editor module `HymnbreakerEditor` for tools |
| Language split | **C++** for systems (movement, combat, damage, AI base, encounters, progression, music sync, save). **Blueprints** for content (per-enemy/weapon subclasses setting assets & data), level scripting, UI layout. **Data** (DataTables/DataAssets) for all tuning. |
| Rendering | Deferred; **Nanite** on for static environment meshes; **Lumen** GI + reflections (hardware RT if available, software fallback); **Virtual Shadow Maps**; **TSR** default (DLSS/FSR/XeSS plugins optional); Forward shading **off** |
| Target RHI | DX12 (SM6) on Windows |
| Frame rate | Uncapped with options (60/120/144/uncapped); **all gameplay timers in seconds**, never frames |
| Physics | Chaos; substepping on (max 4 substeps) for fast projectiles/Harrow; CCD on projectiles |

### 1.1 Plugins
Enable: **Enhanced Input**, **CommonUI**, **Niagara**, **MetaSound**, **Audio Synesthesia** (optional, for music analysis), **Motion Warping**, **Chaos Destruction** (Geometry Collections), **Gameplay Tags** (core), **ModelViewViewModel** (UI binding), **Level Sequence**, **Control Rig** + **IK Rig/Retargeter**, **Data Validation**, **Editor Scripting Utilities** / **Python Editor Script Plugin** (for MCP automation), **Procedural Content Generation (PCG)** (optional, for set-dressing scatter), **Water** (not needed — custom water planes).
Avoid unless justified: Gameplay Ability System (GAS) — a lighter custom ability layer is specified below; GAS is acceptable only if the team is fluent with it (log the decision).

### 1.2 Collision Channels & Profiles
| Channel | Type | Purpose |
|---|---|---|
| `Projectile` | Object | Player & enemy projectiles |
| `EnemyBody` | Object | Enemy capsules/physics assets |
| `WeakPoint` | Object | Weak point hit volumes (overlap for traces) |
| `Pickup` | Object | Pickups (overlap with the player) |
| `Interact` | Trace | Interaction traces |
| `WeaponTrace` | Trace | Hitscan traces (Riveter, Lance, Shredder, Breacher pellets) |
| `HarrowTrace` | Trace | Harrow targeting (anchors + enemies) |
| `VisibilityAI` | Trace | AI line-of-sight |

Profiles: `PlayerCapsule`, `EnemyCapsule`, `EnemyMesh_Hit` (physics asset hit bodies respond to `WeaponTrace`), `WeakPoint_Hit`, `Projectile_Player`, `Projectile_Enemy`, `Pickup_Overlap`, `Anchor_Harrow`, `Breakable`, `Hazard_Overlap`, `Crowd_Soft` (passive crowds: block Pawn softly, ignore traces).

### 1.3 Gameplay Tags (root hierarchy)
```
Damage.Type.{Kinetic, Explosive, Energy, Blade, Melee, Silence, Sonic}
Damage.Flag.{Piercing, Splash, Headshot, WeakPoint, Environmental, SelfDamage, Reflected}
Status.{Faltering, Distorted, Hushed, Stunned, Linked, Anthem, Echoed, Burning, Airborne, GuardBreak, Slowed}
Enemy.Tier.{T1, T2, T3, Boss, Titan}
Enemy.Faction.{Tuned, Host, Instrument, Consonance}
Enemy.Type.<Name>                       (e.g., Enemy.Type.Chorister)
Attack.Telegraph.{Cyan, Gold}
Ability.{Harrow, Frag, Hush, Distort, PowerChord, Downbeat, Counter, Surge, Overdrive, Broadside}
Weapon.<Name> / Weapon.Mod.<Name>
Pickup.{Health, Plating, Ammo.Shells, Ammo.Rounds, Ammo.Charge, Ammo.Ordnance, NullCell, Grudge, HarrowSpool, PowerUp.*}
Collectible.{Master, Effigy, Archive, Tab, Tape, MuteCell, HeartShard, RigCore, Pedal, RequiemKey, Reprise, BrassCache}
Mission.Mxx
Music.State.{Explore, Tension, Low, Mid, High, Overdrive, Boss}
```

---

## 2. Content Folder Structure

```
/Game/HB/
  Core/            (GameModes, PlayerController, HUD base, subsystems' BP configs)
  Data/
    Tables/        (DT_Weapons, DT_WeaponMods, DT_Enemies, DT_Attacks, DT_Pickups, DT_Missions, DT_RigUpgrades, DT_Pedals, DT_Collectibles, DT_Difficulty, DT_HeartTracks)
    Assets/        (DA_PlayerTuning, DA_Enemy_*, DA_Weapon_*, DA_Boss_*, DA_Mission_*, DA_MusicTrack_*)
    Encounters/    (DA_ENC_Mxx_nn, DA_CM_Mxx_nn, DA_RQG_nn)
  Player/          (BP_Unsung, ABP_Unsung_Arms, AM_*, SK_Unsung_*)
  Weapons/<Weapon>/ (BP_WPN_*, SK_WPN_*, M_*, T_*, NS_*, SFX_*)
  Abilities/       (Harrow, Frag, Hush, Distort, …)
  Enemies/<Enemy>/ (BP_ENM_*, SK_*, ABP_*, AM_*, BT_*, M_*, T_*, NS_*, SFX_*)
  Bosses/<Boss>/
  Titans/<Titan>/
  Mech/            (Anvil)
  Environment/
    Kits/<KIT>/    (SM_KIT_*, M_*, T_*)
    Props/<Category>/
    Choir/         (overlay kit)
    Sky/           (skyboxes, planets, Aureole)
  Pickups/
  Gameplay/        (Anchors, KickPads, SwingPoles, GripWalls, GrindRails, NotePlatforms, Hazards, Doors, SoundingStation, ChoirSeal, ChoirMass, RequiemGate)
  VFX/Shared/
  Audio/{Music, SFX, VO, Radio, Ambience, Mixes}
  UI/{HUD, Menus, Hub, Common, Fonts, Icons}
  Cinematics/      (LS_CIN_*)
  Maps/
    Missions/Mxx_<Name>/ (Mxx_<Name>_P (persistent), _Geo_*, _Light, _Enc, _Audio, _FX)
    Hub/             (Hub_P + state layers)
    Dev/             (test maps: TM_Movement, TM_Weapons, TM_EnemyGallery, TM_Encounter)
    Frontend/
  Dev/               (greybox materials M_GRY_*, test assets — excluded from shipping)
```

---

## 3. Naming Conventions

| Prefix | Asset | Prefix | Asset |
|---|---|---|---|
| `BP_` | Blueprint class | `SM_` | Static mesh |
| `SK_` | Skeletal mesh | `SKEL_` | Skeleton |
| `PHYS_` | Physics asset | `ABP_` | Anim Blueprint |
| `AM_` | Anim Montage | `A_` | Anim Sequence |
| `BS_` | Blend Space | `M_` / `MI_` | Material / Material Instance |
| `MF_` | Material Function | `T_` | Texture (suffix `_D` base color, `_N` normal, `_ORM`, `_E` emissive, `_M` mask) |
| `NS_` / `NE_` | Niagara System / Emitter | `DA_` / `DT_` | Data Asset / Data Table |
| `BT_` / `BB_` / `EQS_` | Behavior Tree / Blackboard / EQS | `WBP_` | Widget Blueprint |
| `LS_` | Level Sequence | `MS_` | MetaSound Source |
| `SFX_` `MUS_` `VO_` `AMB_` `STG_` | Audio | `IA_` / `IMC_` | Input Action / Mapping Context |
| `GC_` | Geometry Collection | `PP_` | Post-process material/volume |

Map names: `Mxx_<Name>_P` (persistent) with sublevels `Mxx_<Name>_Geo_<Area>`, `_Enc`, `_Light`, `_Audio`, `_FX`.

---

## 4. Runtime Architecture

### 4.1 Framework
| Class | Base | Responsibility |
|---|---|---|
| `UHBGameInstance` | `UGameInstance` | Owns persistent subsystems; difficulty; settings |
| `UHBProgressionSubsystem` | `UGameInstanceSubsystem` | Brass, Rig Cores, Heart Shards, Pedals, collectibles, masteries, challenges, unlocks; applies upgrades to the player on spawn |
| `UHBSaveSubsystem` | `UGameInstanceSubsystem` | Save slots, checkpoints, autosave, Unsung-mode permadeath flag |
| `UHBHubStateSubsystem` | `UGameInstanceSubsystem` | Hub state (1–7) → Data Layers |
| `AHBGameModeMission` | `AGameModeBase` | Mission flow: spawn, checkpoints, mission complete, death/respawn, Reprise handling |
| `AHBGameModeHub` | `AGameModeBase` | Hub rules (weapons holstered, stations) |
| `AHBPlayerController` | `APlayerController` | Input contexts, UI, camera manager |
| `AHBPlayerCameraManager` | `APlayerCameraManager` | FOV (world & viewmodel), shakes, FOV kicks, hit-stop time dilation |
| `UHBCombatDirector` | `UWorldSubsystem` | Attack tokens, aggression, threat caps, spawn queue |
| `UHBMusicSubsystem` | `UWorldSubsystem` | Quartz clock, stems, states, stingers, beat events |
| `UHBSilenceController` | `UWorldSubsystem` | Hush low-pass zones, Silencer global mute, designated silences |
| `UHBCheatManager` | `UCheatManager` | Console commands (`11_AI_and_Encounter_Design.md` §8) |

### 4.2 Player
| Class | Responsibility |
|---|---|
| `AHBPlayerCharacter` (`ACharacter`) | Composition root for player components; FP arms mesh + body/shadow mesh |
| `UHBCharacterMovementComponent` | Custom movement modes: **Surge** (dash), **double jump**, **mantle** (with Motion Warping), **GripWall** (climb), **Swing**, **GrindRail** (spline follow), **Harrow Reel/Grapple** (custom mode with slingshot exit), **Downbeat**, **Kick Pad arc**, **gravity direction** (M17–M18 rooms), coyote time & jump buffer, safe-ground sampling |
| `UHBHealthComponent` | Health, Plating, overheal decay, Piercing rule, Reprise trigger, low-health state |
| `UHBAmmoComponent` | 4 standard pools + Null Cells + Grudges + Voice; capacities from progression |
| `UHBWeaponInventoryComponent` | Owned weapons, current weapon, switching (0.18 s), pocket reload, weapon wheel |
| `AHBWeaponBase` (`AActor`) + subclasses by fire model: `AHBWeaponHitscan`, `AHBWeaponProjectile`, `AHBWeaponBeam`, `AHBWeaponChain` (Arc Coil), `AHBWeaponMelee` (Axe) | Fire logic driven by `UHBWeaponData` (DataAsset) + mod components |
| `UHBWeaponModComponent` (+ `UHBMod_FragSlug`, `UHBMod_DrumFire`, …) | Mod behavior; upgrades via progression tags |
| `UHBAbilityComponent` + `UHBAbility_*` (Harrow, FragCharge, HushCharge, Distort, PowerChord, Downbeat, Overdrive, Broadside) | Lightweight ability objects: activation checks, cooldowns/charges, execution; data-driven by `UHBAbilityData` |
| `UHBMeleeComponent` | Punch cycle, **Counter** detection (parry window vs. incoming `Attack.Telegraph.Gold` events), Power Chord |
| `UHBBreakdownComponent` | Target selection, Motion-Warped lunge, synchronized montage pairs, invulnerability, drops |
| `UHBGainComponent` | Gain accumulation/decay, Riff detection, variety chain, Overdrive state |
| `UHBInteractionComponent` | Interact traces & prompts |
| `UHBFeelComponent` | Recoil, sway, bob, landing dip, screen shake requests, rumble |

### 4.3 Damage Pipeline
1. Attacker builds `FHBDamageEvent` { `Amount`, `DamageType` (tag), `Flags` (tags), `Instigator`, `Causer`, `HitResult`, `Impulse`, `StaggerPower`, `bCanCounter` }.
2. `IHBDamageable::ReceiveDamage(const FHBDamageEvent&)` on the target:
   * `UHBHitZoneComponent` resolves the hit zone (Head, WeakPoint_<Name>, Plate_<n>, Shield, Body) from the physics body / collision component → multipliers & zone HP.
   * `UHBStatusComponent` applies status modifiers (Linked −75%, Hushed +25% with upgrade, Guard Break +50%…).
   * Resistances from `DT_Enemies` (`Res_<Type>`).
   * Difficulty multipliers.
   * Plates/shields absorb first; then HP.
3. Post-damage events: Falter check, Distorted shard spawn, Gain events, hit reactions, dismemberment, UI hit markers, telemetry.
4. Death: `OnDeath` → drops (Breakdown/Shred/Distort/Axe rules), shatter VFX, Gain, encounter notification, token release.

### 4.4 Enemies & AI
| Class | Responsibility |
|---|---|
| `AHBEnemyBase` (`ACharacter`) | Ground enemies: components below; data from `UHBEnemyData` |
| `AHBFlyingEnemyBase` (`APawn`) | Flyers with `UHBFlightComponent` (steering, boids) |
| `AHBAIController` | Perception, BT run, blackboard setup, token requests |
| `UHBAttackComponent` | Executes `FHBAttackRow` attacks: telegraph (VFX/SFX/tag), windup, damage windows (hitbox sweeps, projectile spawns, beams), recovery, cooldowns |
| `UHBStatusComponent` | States from `04` §3 |
| `UHBHitZoneComponent` | Head/weak points/plates/shields with HP & multipliers |
| `UHBDismemberComponent` | Bone hiding + gib spawning at thresholds; crack material driving (`CrackAmount`) |
| `UHBDropComponent` | Resource drops by rules |
| BT nodes (C++) | Tasks: `MoveToHoldPoint`, `LeapToPerch`, `RequestToken`, `ExecuteAttack`, `Strafe`, `Retreat`, `ChargeLine` (Crescendo), `Blink` (Cantor/Maestro), `CastSupport`, `Possess` (Echo). Services: `UpdateTargetInfo`, `UpdateAggression`, `SelectAttack`. Decorators: `HasToken`, `IsInRange`, `HasLOS`, `StatusCheck`. |
| EQS | `EQS_PickHoldPoint`, `EQS_PickPerch`, `EQS_FlankPoint`, `EQS_RetreatPoint`, `EQS_ChargeLane` |

### 4.5 Encounters & World
| Class | Responsibility |
|---|---|
| `AHBEncounterArena` | Volume, seals, trigger, waves from `UHBEncounterData`, rewards, checkpoint, music state |
| `AHBSpawnPoint` | Allowed tiers/methods/tags; validation |
| `AHBChoirSeal` | Door membrane (grow/dissolve anim), blocks navigation while active |
| `AHBAIHoldPoint`, `AHBPerch`, `AHBPerchPath`, `ANavLinkProxy` subclasses | AI positioning |
| `AHBPickupBase` + subclasses | Pickups (magnet behavior for dropped ones) |
| `AHBHarrowAnchor`, `AHBSwingPole`, `AHBKickPad`, `AHBGripWallVolume`, `AHBGrindRail` (spline), `AHBNotePlatform` (Quartz-driven), `AHBGravitySeam` | Traversal |
| `AHBHazardVolume` + subclasses (Solar, Saturation, Fire, Electric, Kill/Recover) | Hazards |
| `AHBBreakable` (Chaos GC or swap-mesh) | Breakable walls/floors/seals/mirrors |
| `AHBFuseDoor`, `AHBFusePickup` | Key/door system |
| `AHBSoundingStation` | Map reveal |
| `AHBCollectible` | All collectibles (type via tag + row) |
| `AHBRequiemGate`, `AHBChoirMass` | Optional encounters |
| `AHBCheckpoint` | Checkpoint trigger |
| `AHBMovingArenaBase` | Moving platforms (climber car, elevator, funicular) with parented flight volumes & nav (use `NavModifier` + dynamic navmesh or restrict ground enemies to the platform's local navmesh via runtime generation) |
| `AHBBossBase` + `UHBBossPhaseController` | Bosses |
| `AHBAnvilPawn` (+ `UHBMechWeaponComponent`s) | The Anvil Siege Frame |

---

## 5. Data Schemas (DataTable row structs)

All CSVs in `/HYMNBREAKER_GDD/data/` map to these structs (import as DataTables; row name = first column `Name`).

### 5.1 `FHBWeaponRow` → `DT_Weapons` (`data/weapons.csv`)
| Field | Type | Notes |
|---|---|---|
| Name | FName | `WPN_Breacher` |
| DisplayName | FText | |
| Slot | int32 | 1–9, 10–12 for supers |
| FireModel | enum | Hitscan / Projectile / Beam / Chain / Melee |
| DamageType | FGameplayTag | |
| DamagePerHit | float | Per pellet/rivet/bolt/tick |
| PelletsPerShot | int32 | |
| ShotsPerSecond | float | |
| SpreadDeg | float | |
| FalloffStart / FalloffEnd | float | cm |
| FalloffMinMult | float | |
| HeadMult | float | |
| AmmoType | FGameplayTag | |
| AmmoPerShot | float | |
| ProjectileSpeed | float | cm/s (0 = hitscan) |
| SplashDamage / SplashRadius | float | |
| MagSize / ReloadTime | int32 / float | 0 = no magazine |
| SwitchTime | float | |
| Acquired | FName | Mission ID |

### 5.2 `FHBWeaponModRow` → `DT_WeaponMods` (`data/weapon_mods.csv`)
Name, Weapon, DisplayName, Description, Cost1, Cost2, Cost3, Upgrade1Text, Upgrade2Text, Upgrade3Text, MasteryName, MasteryChallenge, MasteryTarget (int), AcquiredMission.

### 5.3 `FHBEnemyRow` → `DT_Enemies` (`data/enemies.csv`)
Name, DisplayName, Tier, Faction, HP, ArmorHP, ShieldHP, FalterPct, FalterDuration, WalkSpeed, RunSpeed, CapsuleRadius, CapsuleHalfHeight, SightRange, HearingRange, Threat, HarrowCost (0/1/3/-1 = none/special), BreakdownHealth, Res_Kinetic, Res_Explosive, Res_Energy, Res_Blade, Res_Melee, Res_Silence, Res_Sonic, HeadMult, WeakPointMult, NavAgent, FirstMission.

### 5.4 `FHBAttackRow` → `DT_Attacks` (`data/attacks.csv`)
Name, Enemy, DisplayName, Damage, DamageType, bPiercing, Range, Radius, TelegraphTime, TelegraphType (Cyan/Gold), Cooldown, TokenPool (Melee/Ranged/Heavy/Sniper/Kamikaze/None), ProjectileSpeed, Count, Notes.

### 5.5 Other tables
* `FHBPickupRow` (`data/pickups.csv`): Name, Category, Value, Duration, Notes.
* `FHBMissionRow` (`data/missions.csv`): Name (Mxx), Title, Act, Location, Kits, TargetMinutes, Boss, NewWeapons, NewAbilities, NewEnemies, HeartShard, MuteCell, Tab, Tape, RequiemGate, Pedal, ChoirMasses, Effigies, Reprise, SoundingStations.
* `FHBRigUpgradeRow` (`data/rig_upgrades.csv`): Name, Branch, Tier, Cost, DisplayName, Effect.
* `FHBPedalRow` (`data/pedals.csv`): Name, DisplayName, FoundIn, Effect, BoutiqueChallenge, BoutiqueTarget, BoutiqueEffect.
* `FHBDifficultyRow` (`data/difficulty.csv`): Name, EnemyDamageMult, EnemyHPMult, BossHPMult, T1CountMult, T2CountMult, EliteChance, ThreatCapMult, ParryWindowMs, BreakdownHealthMult, TokenMelee, TokenRanged, TokenHeavy, DecisionDelayMult, SelfDamage, FallPenalty, AimAssistSnapDeg.
* `FHBHeartTrackRow` (`data/heart_tracks.csv`): Track, Step, Value(s), Perk.

### 5.6 DataAssets
* `UHBPlayerTuningData` — all movement values from `05` (one asset: `DA_PlayerTuning`).
* `UHBEnemyData` — references: mesh, anim BP, BT, attacks (row handles), hit zones, drops, audio (signature set), VFX; overrides.
* `UHBWeaponData` — mesh, anims, VFX, SFX, row handle, mods.
* `UHBEncounterData` — waves: array of `FHBWave` { Trigger (enum + params), Entries: array of `FHBSpawnEntry` { EnemyID, Count, SpawnMethod, SpawnPointTags, Delay } , bFinal }, seals, music track, rewards, pickups (placed in level; not in data).
* `UHBBossData` — phases (see `10` §0).
* `UHBMusicTrackData` — stems, BPM, meter, key, sections, stingers.
* `UHBMissionData` — map, checkpoints, objectives, radio intro, collectible manifest (for UI counts), challenges.

---

## 6. Save System

* **Profile save** (`UHBSaveGame_Profile`): settings, unlocked difficulties, cosmetics, achievements, Pit Trial records.
* **Campaign save** (`UHBSaveGame_Campaign`, 3 slots + autosave): difficulty, Unsung flag, current mission & checkpoint ID, weapons/mods/upgrades owned, currencies (Brass, Rig Cores unspent, Heart Shards unspent), Pedals & loadout, collectibles found (by ID), challenges & masteries progress, Reprises carried, hub state, per-mission stats.
* **Checkpoint snapshot:** player resources (per the minimums in `04` §12), encounter states (completed/not), picked-up placed items (by actor GUID), doors/fuses, scripted flags.
* Autosave triggers: mission start, checkpoints, hub arrival, upgrade purchase.

---

## 7. Level Construction

* **Recommended:** one **persistent level per mission** with **streaming sublevels** per area (`_Geo_A01`…), plus `_Enc` (encounter actors), `_Light`, `_Audio`, `_FX`. Stream via volumes/triggers placed 1–2 areas ahead; unload behind one-way transitions.
* **Alternative:** World Partition + Data Layers (acceptable for large exterior missions: M04, M08, M23, M25). Log the choice per mission in `DECISIONS.md`.
* **Navigation:** Navmesh with 3 agents (see AI doc); runtime generation **Dynamic Modifiers Only** (for seals, moving arenas use static local navmesh on the platform + nav links).
* **Greybox first:** `SM_GRY_*` blocks (1 m grid materials) → playable → art pass with kits (swap blocks for `SM_KIT_*` modules).

---

## 8. Animation Tech

* **Player FP:** `SK_Unsung_Arms` rendered with a separate **viewmodel FOV** (material-based FOV correction or the "FirstPerson" rendering features available in newer UE versions); weapons attached to `weapon_r`. Procedural recoil & sway via AnimBP (additive) or Control Rig.
* **Breakdowns:** synchronized montage pairs (player + victim) with **Motion Warping** to align the victim; the victim's capsule is disabled and the mesh attached to a sync point for the duration.
* **Enemies:** AnimBPs per skeleton class (`ABP_SKC_*`), shared locomotion blendspaces, montages for attacks (with AnimNotifies for telegraph start, damage window start/end, VFX, SFX).
* **Crowds:** Vertex Animation Textures (VAT) on instanced static meshes (thousands of agents).
* **Retargeting:** all humanoids use a UE5 Manny-compatible skeleton → IK Retargeter from any humanoid library (Mixamo/marketplace/mocap).
* **Optimization:** URO (Update Rate Optimization) for distant enemies, anim budget allocator, bone LODs.

---

## 9. Performance Budgets (PC High, 1440p, RTX 3070-class, 60 FPS)

| Budget | Target |
|---|---|
| Frame | ≤ 16.6 ms (GPU ≤ 14 ms, Game thread ≤ 8 ms, Render thread ≤ 10 ms) |
| Max alive enemies | 26 (Act VI peak), typical 12–18 |
| AI | BT tick: near (< 30 m) 30 Hz; mid 15 Hz; far (> 60 m or not rendered) 5 Hz; EQS max 6 queries/frame |
| Animation | ≤ 20 full-rate skeletal meshes; rest URO; crowds VAT |
| Niagara | ≤ 150k active GPU particles; ≤ 30 active systems with CPU sim; pooled systems for impacts |
| Projectiles | Pooled (≥ 200 per type pool); no per-shot actor spawning for bullets (hitscan traces) |
| Physics | Gibs: max 60 simulating, lifetime 4 s, then sleep/fade; corpses dissolve within 8 s |
| Draw calls | ≤ 3,500 (non-Nanite) in the heaviest arena |
| Textures | Streaming pool 3 GB (High); 2K standard for characters/weapons, 4K only for bosses/hero assets |
| Audio | ≤ 64 real voices, ≤ 48 enemy voices, virtualization on |
| Memory | ≤ 10 GB RAM total, ≤ 7 GB VRAM on High |
| Loading | Mission load ≤ 20 s on SSD (hidden under the radio intro) |

**Scalability:** Low/Medium/High/Epic presets; Low disables Lumen (screen-space GI + baked-ish sky light), VSM → shadow maps, reduced particle counts, crowd density ×0.3.

---

## 10. Testing & Automation

* **Test maps:** `TM_Movement` (all traversal elements + metrics gym), `TM_Weapons` (range with DPS dummies), `TM_EnemyGallery` (spawn any enemy), `TM_Encounter` (encounter data test harness), `TM_Boss_<Name>`.
* **Automation specs** (C++ `Automation Spec`): damage math (multipliers, plates, resistances, difficulty), Falter thresholds, Shred ammo formula, Gain accumulation/decay, Counter windows, token allocation, save/load round-trip.
* **Functional tests:** per arena, `BP_TestBot` (god mode, auto-aim, weapon cycling, uses Harrow/abilities on cooldown) must clear the encounter in < 10 min — nightly.
* **Perf captures:** automated `stat unit`/Insights captures at each mission's heaviest arena.

---

## 11. Working with the UE5 MCP (guidance for AI builders)

MCP servers for Unreal typically expose tools such as: spawning/transforming actors, creating/editing Blueprints (components, variables, simple node graphs), editing properties, importing assets, running Python in the editor, taking viewport screenshots, and playing-in-editor. Capabilities differ between servers — **check the server's tool list first** and adapt.

1. **Prefer code and data over node graphs.** Complex logic belongs in C++ (write `.h/.cpp` files directly; compile with UnrealBuildTool / Live Coding). Blueprint graph editing via MCP is slow and fragile; use Blueprints as thin subclasses that set assets/defaults.
2. **Use editor Python** (if the MCP can run it) for bulk operations: importing FBX batches with consistent settings, creating MaterialInstances from a master, importing CSVs into DataTables, placing greybox modules from a layout script, validating naming.
3. **Author layouts as data.** For greyboxing, have the agent write a layout description (JSON: module IDs, positions, rotations) and a Python script that spawns it — reproducible and diffable. Keep these scripts under `/Tools/Layouts/Mxx_*.json`.
4. **Verify visually.** After each build step, take viewport screenshots and PIE (play-in-editor) tests; compare against the mission doc's metrics (jump gaps, arena sizes).
5. **Small commits.** One feature per change; run automation specs before committing.
6. **Never hard-code tuning.** If a number appears in this GDD, it goes in a DataTable/DataAsset.
7. **Log decisions** in `DECISIONS.md` (what, why, alternatives) so later agents stay consistent.
