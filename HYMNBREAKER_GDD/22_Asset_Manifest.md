# 22 — Asset Manifest

Master list of production assets. **Priority:** **P0** = Act I Alpha (M01–M04 + hub States 1–2; the Vertical Slice milestone covers M01–M02 first), **P1** = full game, **P2** = polish/optional. Each mission document's §"New Assets Required" lists mission-specific extras; this manifest is the consolidated backbone. Builders: create a tracking sheet from this file (one row per ID) and mark status `Greybox → Model → Rig → Anim → Tex → UE Import → Integrated → Polished`.

---

## A. Player

| ID | Description | Priority |
|---|---|---|
| `SK_Unsung_Arms` | FP arms + upper chest, Harrow on left forearm, Arrhythm cage visible when looking down | P0 |
| `SK_Unsung_Body` | Full body (legs visible in FP, shadow, 3P cutscenes) | P0 |
| `SK_Unsung_BareHand` | Bare Oreth hand (M21) | P1 |
| `SM_Harrow_Barb`, `SM_Harrow_ChainLink` | Harpoon head + chain link (instanced along spline) | P0 |
| `NS_Unsung_*` | Exhaust flare, Overdrive aura, dash burst, Downbeat ring, Distort cone, Power Chord charge/strike, Arrhythm pulse | P0 |
| Animation set (arms) | ~140 anims: base, per-weapon (draw/holster/fire/mod/reload/inspect ×12), melee (6), Harrow (6), equipment (4), movement (12), Overdrive, gestures (8), damage (6) | P0 (for P0 weapons), P1 rest |
| Breakdown pairs | ~70 synchronized pairs (2–6 per enemy) | P0 for P0 enemies |
| Rig Finishes | 15 material/texture variants | P1–P2 |

---

## B. Weapons (FP skeletal + world pickup static)

| ID | Priority | Mods (VFX/SFX) |
|---|---|---|
| `SK_WPN_Breacher` / `SM_PKP_Breacher` | P0 | Frag Slug, Drum Fire |
| `SK_WPN_Riveter` | P0 | Tack Scope (scope overlay), Hot Rivets |
| `SK_WPN_StaticRifle` | P0 | Heat Burst, Arc Beam |
| `SK_WPN_Gravedigger` | P0 | Upgrades only |
| `SK_WPN_Hammerfall` | P0 | Cluster Bell, Lock Salvo |
| `SK_WPN_Shredder` | P1 | Tri-Spin, Deflector Spin |
| `SK_WPN_ArcCoil` | P1 | Storm Node, Tether Coil |
| `SK_WPN_Lance` | P1 | Overcharge, Arc Scythe |
| `SK_WPN_Ripsaw` (+ `SM_RipsawBlade`) | P1 | Grinder, Recall |
| `SK_WPN_Silencer` (+ `NS_SilencerSphere`, `NS_SilenceTendril`) | P1 | — |
| `SK_WPN_Axe` (+ `NS_AxeScream`) | P1 | Ruin Sweep |
| `SK_WPN_Larynx` (+ `NS_Inhale`, `NS_Aria`) | P2 | — |
| `SM_FragCharge`, `SM_HushCharge` | P0 | — |
| Weapon finishes | P2 | 1 per mastered mod + Tour Poster set |

Per weapon also: projectiles/tracers, muzzle flashes, shell ejects, impact sets (7 surfaces), HUD icons, wheel icons, SFX sets (see audio doc).

---

## C. Enemies

| ID | Skeleton | Priority | Variants / extras |
|---|---|---|---|
| `SK_Thrall` | Humanoid | P0 | 6 clothing sets (lab, EVA, commuter, fan, worker, formal) + parka, captive, Oreth "Silent One"; crawler state |
| `SK_ThrallBloated` | Humanoid | P1 | — |
| `SK_Trooper` | Humanoid | P0 | CDF & Static variants |
| `SK_TrooperBulwark` | Humanoid | P0 | Fused shield mesh |
| `SK_TrooperMarksman` | Humanoid | P1 | Lance-rifle, gold lens |
| `SK_Chorister` | Chorister | P0 | Oreth-shaped skin (M21), alien skins (M20+) |
| `SK_Vesper` | Flyer_S | P0 | — |
| `SK_Wailer` | Flyer_S | P0 | — |
| `SK_Acolyte` | Humanoid | P1 | 3 variants + Deacon Marrow (named) |
| `SK_Zealot` | Humanoid | P1 | — |
| `SK_Crescendo` | Quadruped_L | P0 | Gilded plates (P1) |
| `SK_Bellwether` | Brute | P1 | Gilded plates |
| `SK_Seraph` | Humanoid (tall) | P0 | — |
| `SK_Ophan` | Ring | P0 | — |
| `SK_Canon` | Brute | P0 | Gilded plates (P1) |
| `SK_OrganGrinder` | Arachnid | P1 | Assembly-line states |
| `SK_Cantor` | Humanoid | P0 | Antiphon giant gold/silver (P1) |
| `SK_Siren` | Serpent | P1 | — |
| `SK_Fugue` | Chorister | P1 | Illusion material |
| `SK_Hymnal` | Tome | P1 | — |
| `SK_Echo` | Humanoid (ghost) | P1 | Possession VFX |
| `SK_Profundo` | Brute (large) | P1 | Gilded plates |
| `SK_Carillon` | Titan | P1 | 4 destructible bells |
| `SK_Maestro` | Humanoid (tall) | P1 | Score (book) prop; Primus scale-up |
| `SK_RequiemKnight` | Humanoid (armored) | P1 | Sword, shield |
| `ENM_Reverie_*` | (material variant) | P1 | Illusion material for any enemy |
| Gib kits | per skeleton class | P0 (P0 classes) | 6–10 chunks each |
| Halo system | `NS_Halo_T1/T2/T3` | P0 | Falter wobble, Hushed dark, shatter |

---

## D. Bosses, Mini-bosses & Titans

| ID | Mission | Priority |
|---|---|---|
| `BOSS_Ionian` (+ 4 Choir Organs, stage, 6 detachable hands, sun-heart) | M04 | P0 |
| `BOSS_Tenebrae` (+ Thale, chanter platforms) | M07, M09 | P1 |
| `BOSS_Dorian` (split-able Psalm Blade, Aegis shield) | M08 | P1 |
| `BOSS_Mixolydian_A` (cradle, cage, flywheels, turntable arena) + `SK_EngineHymn` (40 m) | M11 | P1 |
| `BOSS_Antiphon` (2 giant Cantors) | M12 | P1 |
| `BOSS_Phrygian` (+ heliostat arms & motors) | M13 | P1 |
| `BOSS_MaestroPrimus` | M14, M19 | P1 |
| `TTN_Leviathan` | M15–M16 | P1 |
| `BOSS_Aeolian` (ride-able back) | M16 | P1 |
| `BOSS_Lydian` (mask mobile, true form) | M18 | P1 |
| `BOSS_Locris` (chain-spear, broken shield, 3-config arena) | M22 | P1 |
| `BOSS_Octave` (8 arms, gown of bodies) | M24 | P1 |
| `BOSS_Unison` (sphere + 8 Voice Nodes, First Face & hands, 4 Dissenting Choirs, Core) | M27 | P1 |
| `TTN_OrganWalker` | M10–M11, M23, M26 | P1 |
| `TTN_VesperCloud` (Niagara swarm entity) | M11, M23 | P1 |
| `TTN_ChoirColossus` | M23, M26 | P1 |
| `TTN_Seraphim` | M25–M26 | P1 |
| `SK_Anvil` (cockpit + exterior; Mk2 arm) | M11, M23, M26 | P1 |

---

## E. Characters (NPCs)

| ID | Priority |
|---|---|
| `SK_Lund` (+ `SK_Lund_Tuned`) | P0 / P1 |
| `SK_Vire` | P0 (hub) |
| `SK_Wren` | P0 (hub) |
| `SK_Tamsin` (sign-language mocap set) | P0 (hub) |
| `SK_Harlan` | P1 |
| `SK_Aurelia` (+ hologram material) | P0 |
| `SK_Okafor` | P0 |
| `SK_Juno` | P0 |
| `SK_Thale` | P1 |
| `SK_Pops` | P1 |
| `SK_DeaconMarrow` | P1 |
| `SK_Locris` (cutscene + boss) | P1 |
| `SK_Veyl_Statue` | P1 |
| Crew (25), refugees (10), children (6), Static soldiers (10 variants) | P0 (subset) / P1 |
| Crowd agents (VAT): Tuned civilians, dreamers, captives, gilded soldiers, Oreth statues | P0 (civilians) / P1 |

---

## F. Environment Kits

| Kit | Module families (approx. count) | Priority |
|---|---|---|
| `GRY` Greybox | Blocks 50–800 cm, ramps, stairs, cylinders, arches; 8 materials | **P0 (first)** |
| `BRU` Concord Brutalist | Walls (20), floors (8), ceilings (6), doors & frames (8), stairs/ramps (6), pillars (6), catwalks & railings (12), pipes & ducts (15), windows (6), trims; props: lab (30), military (40), industrial (25), signage (40 decals) | P0 |
| `ORB` Orbital | Hull panels (15), trusses (10), airlocks (4), curved ring corridor set (12), climber car (3 variants), ribbon, domes (4) | P0 |
| `CITY` Halcyon | Megablock facades (12), street kit (20), highway kit (15), bridge (6), stadium kit (25), plaza (15), metro (20), nightclub (25), rooftop props (30), vehicles (8 + wrecks) | P0 (M04 subset), P1 |
| `CHOIR` overlay | Organ-pipe clusters (8), bone lattices (6), bell blooms (4), porcelain crust decals (10), filigree decals (10), membranes (4), singing walls (3), Choir Seal | P0 |
| `CHOIR_ARCH` | Ribs, vaults, floors, walkways, pillar-choirs (6), rood screen, Nave doors | P1 |
| `CULT` Consonance | Marble walls/floors/arches (25), gold inlay decals, statues (4), pools, pavilions, amphitheater, cloister | P1 |
| `IND` Forge-Belt | Foundry halls (15), furnace (hero), conveyors (12), cranes (4), rolling mill (6), robotic arms (skeletal), slag terrain | P1 |
| `ICE` Europa | Ice cavern pieces (20), drill derrick (hero), Bore rings, habitats (underwater & surface), tubes (8), pressure doors | P1 |
| `AERO` Cytherea | Gasbag domes (4), filigree balconies (12), gardens (15), gondolas & cables, keel girders | P1 |
| `OREN` Aubade | Towers (7 Wind Towers hero + 10 generic), terraces, arches, statues (20 poses), glyph walls, citadel | P1 |
| `HARM` Harmonium | Staves surface, note-fragments, Note-Platforms, floating bells, Note-World city, Clef exterior/interior | P1 |
| `SHIP` Quietus | Spine modules (anechoic wedge walls), all hub rooms, damaged state set, wreck set | P0 |
| Skies | `BP_Sky_EarthAureole` (8-band Aureole with per-band toggles), Moon, descent sky, Halcyon (per state), Alps, desert night, smog, Mercury (Sun), Europa (Jupiter), Venus, Harmonium void, Solace grey | P0 (first 3), P1 |

---

## G. Gameplay Actors

| ID | Priority |
|---|---|
| `BP_HarrowAnchor` (variants: crane hook, ring-bolt, bone-knot, ship hull) | P0 |
| `BP_SwingPole`, `BP_KickPad` (+ Updraft Throat variant), `BP_GripWall` (mesh variants), `BP_BreakableFloor/Wall` | P0 |
| `BP_GrindRail`, `BP_NotePlatform`, `BP_GravitySeam`, `BP_LoopVolume`, `BP_ChordRotator` | P1 |
| `BP_ChoirSeal`, `AHBEncounterArena`, `BP_SpawnPoint`, `BP_AIHoldPoint`, `BP_Perch` | P0 |
| `BP_SoundingStation`, `BP_Checkpoint`, `BP_FuseDoor` + `PKP_Fuse_Red/Yellow/Blue`, Bell Keys | P0 |
| Pickups: Health S/M/L, Bloodrush, Plating S/M/L, Iron Mantle, ammo ×4 types S/L, Null Cell, Grudge, Harrow Spool, Hush refill, power-ups ×4 | P0 |
| Collectibles: Master (record), Effigy (40 unique figurines — P1/P2), Archive Stone, Tab sheet, Bootleg Tape, Mute Cell, Heart Shard, Rig Core, Pedal (16 unique meshes), Requiem Key, Reprise, Brass Cache, Mod Crate | P0 (generic), P1 |
| Hazards: Hymn Pylon, Choir Mass, Chime Turret, Resonance Mine, Hymn Saturation, solar volumes, fire/electric/molten, kill/recover volumes, Dream Well, Resonance Organ | P0 (Pylon, Mass, kill volumes) / P1 |
| Objectives: Resonator Core, Plectrum, Bridge Saddle, Download Terminal, Drum Obelisk, Breakers, Growth Nodes, Memory Anchors | per mission |
| `BP_DropCoffin` + launch sequence | P0 |
| Moving arenas: climber car, Bore elevator, funicular, maglev pod | P0 (climber, maglev) / P1 |
| `BP_StretcherDrone`, `BP_ShadeDrone`, `BP_ConvoyTruck`, `BP_Broadside` | P1 |

---

## H. VFX (Niagara)

Shared: Hymnfall pillar · Choir Seal grow/dissolve · Faltering ember glow · Distorted static dither · Hushed rime · Linked beams · Anthem aura · Echo double · shatter/porcelain burst · gold motes · blood (red-gold) · resource orbs (health, plating, ammo) with magnet trails · pickup idles · power-up auras · Note projectiles (sphere cyan / torus gold) · beams · ring shockwaves · explosions (3 sizes) · fire · electric arcs · molten splash · snow/blizzard · ice shatter · underwater particles & drifting lights · dream shimmer · Hymn Saturation fog particles · light-rings (visible sound) · Silencer sphere/tendrils · Axe scream · Overdrive screen-edge static (material) · speed lines (material).
Priority: P0 for everything used in M01–M04.

---

## I. Audio (summary counts)

| Category | Count (approx.) | Priority |
|---|---|---|
| Music: explore tracks | 27 + hub (7 states) | P0 (M01–M04, hub) |
| Music: combat tracks (stemmed, 8 stems) | ~70 | P0 subset |
| Music: boss tracks | 13 | P0 (Ionian) |
| Masters (diegetic songs) | 27 | P1 |
| Stingers | ~40 | P0 |
| Weapon SFX | 12 weapons × ~25 events × variations | P0 subset |
| Enemy SFX | 25 enemies × ~20 events | P0 subset |
| Ability/UI/ambience SFX | ~400 | P0 subset |
| VO | ~3,500 lines + 27 radio intros | P0 (M01–M04 + hub) |
| The Last Broadcast crowd | 300+ distinct voices | P1 |

---

## J. UI

HUD widget set · mech HUD · menus (front end, pause, options, difficulty) · hub interfaces (Armory, Rig Bay, Heart Chamber, Pedalboard, Listening Room, Effigy viewer, Solar Map, Wardrobe, Vault) · Sounding Map · loading screens (27 concept art pieces) · icons (weapons, mods, abilities, pickups, collectibles, Pedal art ×16, Master covers ×27, Effigy thumbnails ×40) · fonts · input glyph sets (KBM, Xbox, PlayStation).

---

## K. Cinematics

All `LS_CIN_*` listed in `03b_Cutscenes_Dialogue_and_Radio.md` §1 (38 sequences). P0: `CIN_M01_Awakening`, `CIN_M01_Aureole`, `CIN_M02_Hologram`, `CIN_M02_Quietus`, `CIN_HUB_FirstTour`, `CIN_M03_Harp`, `CIN_M03_Fall`, `CIN_HUB_Sign`, `CIN_M04_Ionian`, `CIN_M04_Waking`, and the Drop Coffin launch sequence.
