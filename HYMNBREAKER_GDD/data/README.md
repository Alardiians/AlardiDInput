# data/ — Tuning Tables (CSV → UE5 DataTables)

These CSVs are the **numeric source of truth** for HYMNBREAKER (they win over numbers quoted in prose documents once balancing starts). Import each file as a DataTable using the matching row struct from `20_Technical_Design_UE5.md` §5.

| File | Row struct | DataTable | Rows |
|---|---|---|---|
| `weapons.csv` | `FHBWeaponRow` | `DT_Weapons` | 12 |
| `weapon_mods.csv` | `FHBWeaponModRow` | `DT_WeaponMods` | 17 (16 mods + Gravedigger path) |
| `enemies.csv` | `FHBEnemyRow` | `DT_Enemies` | 29 (incl. Gilded variants) |
| `attacks.csv` | `FHBAttackRow` | `DT_Attacks` | 73 |
| `pickups.csv` | `FHBPickupRow` | `DT_Pickups` | 32 |
| `missions.csv` | `FHBMissionRow` | `DT_Missions` | 27 |
| `rig_upgrades.csv` | `FHBRigUpgradeRow` | `DT_RigUpgrades` | 28 (total cost 44 Rig Cores) |
| `pedals.csv` | `FHBPedalRow` | `DT_Pedals` | 16 |
| `difficulty.csv` | `FHBDifficultyRow` | `DT_Difficulty` | 6 |
| `heart_tracks.csv` | `FHBHeartTrackRow` | `DT_HeartTracks` | 18 |
| `player_tuning.csv` | — (key/value reference) | Copy into `DA_PlayerTuning` | 75 |

## Import rules

1. **First column = row name** (`Name`). Keep IDs exactly as written — they are referenced across the GDD.
2. **Tag-like strings** (e.g., `Damage.Type.Kinetic`, `Ammo.Shells`): declare those struct fields as `FName` and resolve with `FGameplayTag::RequestGameplayTag()` at load time — or convert the column to UE's `(TagName="Damage.Type.Kinetic")` text format before importing as `FGameplayTag`. Pick one approach and record it in `DECISIONS.md`.
3. **List fields** use `;` as a separator (e.g., `NewEnemies = Thrall;Trooper;Chorister`). Parse into `TArray<FName>` at load, or keep as `FString` for display.
4. **Units:** cm, cm/s, seconds, degrees. Damage values are **Amplified (Normal)** difficulty; runtime multipliers come from `difficulty.csv`.
5. **Special values:** `HarrowCost` `1` = fodder Shred, `3` = Heavy Shred, `0` = special (Bloated Thrall "Fling"), `-1` = Reel-In only. `99999` distances = "no falloff". Axe `DamagePerHit 999999` = instant kill for non-bosses (bosses take 1500 — see `06` §11).
6. **Re-generating:** these files were produced from the GDD by script; if you change a value, change it here and note it in `BALANCE_LOG.md`. Prose documents may lag behind the CSVs during balancing — the CSV wins.

## Cross-checks (totals the design depends on)

* Heart Shards across missions = **18**; Mute Cells = **9**; Tabs = **12**; Bootleg Tapes = **12**; Requiem Gates = **7**; Pedals = **16**; Choir Masses = **35**; Effigies = **40**; Reprises = **20**; Sounding Stations = **38**; mission minutes = **2,010**.
* Rig tree total cost = **44** Rig Cores (63 available).
* Brass to max all weapon upgrades = **105** (~140 available).
