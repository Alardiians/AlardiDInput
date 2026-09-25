# 08 — Progression & Economy

## 0. Progression Layers

| Layer | Currency / Item | Spent at | What it improves | Total available | Needed to max |
|---|---|---|---|---|---|
| Weapon mods | **Brass** | Armory (Quietus) or pause menu *Field Upgrade* | Weapon mod upgrades | ~140 | 105 |
| Weapon masteries | Challenges / **Mastery Picks** | Automatic / Armory | Mastery perks | 8 Picks | — |
| Rig | **Rig Cores** | Rig Bay (Quietus) or pause menu | Harrow, Frag, Hush, Distort, Mobility, Survival | 63 | 44 |
| Core stats | **Heart Shards** | Heart Chamber (Quietus only) | Max Health, Plating, Ammo + 6 perks | 18 | 18 |
| Perks | **Pedals** | Pedalboard (pause menu, any time outside combat) | Equippable modifiers (2 → 4 slots) | 16 | — |
| Hub vaults | **Mute Cells** | Vault Deck (Quietus) | Rewards (see §7) | 9 | 9 |
| Secret weapon | **Reliquary Shards** | Requiem Gates → Armory | The Larynx | 7 | 7 |
| Cosmetics | Milestones, vaults, challenges | Wardrobe (Quietus) | Rig & weapon finishes | — | — |
| Lives | **Reprises** | Automatic | Extra life | ~20 placed | carry max 3 |

**Design goals:**
* A **main-path-only** player finishes the game with ~50% of upgrades and is comfortable on Unplugged/Amplified.
* A **~70% explorer** (the target) is fully comfortable on Amplified and Overdriven.
* A **completionist** maxes everything by the end of Act V, with Act VI as a victory lap.

---

## 1. BRASS (Weapon Upgrade Points)

| Source | Amount | Count | Total |
|---|---|---|---|
| **Brass Caches** (hidden: a Static ammo crate stenciled with a brass-knuckle icon, violet light) | 1–2 | 54 (2 per mission) | ~81 |
| **Choir Masses** (optional encounters) completed | 1 | ~35 | 35 |
| **Requiem Gates** completed | 3 | 7 | 21 |
| Pit Trials (first completion) | 1 | 12 | 12 (some Trials give Rig Cores instead) |
| **Total** | | | **~140** |

Costs per weapon: each mod's 3 upgrades cost **1 / 2 / 3** Brass (6 per mod, 12 per weapon); Gravedigger path costs 2 / 3 / 4 (9). **Total to max all: 8 × 12 + 9 = 105.**

**Field Upgrades:** Brass can be spent from the pause menu anywhere (not only in the hub), so players can use new upgrades immediately.

---

## 2. MASTERIES & MASTERY PICKS

* A mod's Mastery challenge activates after its 3 Brass upgrades are owned.
* **Mastery Picks** (a guitar pick made of black iron) instantly complete one active Mastery challenge. Sources: one per Requiem Gate (7) + final Pit Trial (1) = **8**.

---

## 3. RIG CORES (Suit Upgrades)

### 3.1 Sources
| Source | Count |
|---|---|
| Hidden Rig Core per mission (a rusted Oreth-glyph cylinder in a small secret alcove, violet light) | 27 |
| Completing all 3 **Mission Challenges** of a mission | 27 |
| Pit Trials (6 of the 12) | 6 |
| Mute Cell vaults | 3 |
| **Total** | **63** |

### 3.2 The Rig Tree (costs 1 / 1 / 2 / 2 / 2 per branch tier)

| Branch | Tier 1 (1) | Tier 2 (1) | Tier 3 (2) | Tier 4 (2) | Tier 5 (2) | Branch cost |
|---|---|---|---|---|---|---|
| **Harrow** | Fast Winch | Magnetized | Barbed Rip | Whiplash | Second Spool | 8 |
| **Frag** | Twin Charges | Quick Fuse | Cluster | Concussive | — | 6 |
| **Hush** | Brittle | Life in Silence | Deep Hush | Quick Hush | — | 6 |
| **Distort** | Quick Recovery | Wider Cone | Feedback Loop | Overdriven Signal | Fast Recovery | 8 |
| **Mobility** | Quick Surge | Surge Strike | Heavy Beat | Lunge | Air Brakes | 8 |
| **Survival** | Hazard Plating | Resonance Sense | Power Player | Scavenger | Grudge-Bearer* | 8 |
| **Total** | | | | | | **44** |

Upgrades must be bought in tier order within a branch. (Full effects of the first five branches: `07_Equipment_and_Abilities.md`.)

**Survival branch effects:**
| ID | Name | Effect |
|---|---|---|
| `RIG_Survival_1` | Hazard Plating | Environmental hazard damage −50% (solar exposure, fire, electrified water, Hymn Saturation) |
| `RIG_Survival_2` | Resonance Sense | Secrets within 20 m emit a faint violet chime and appear on the compass ribbon |
| `RIG_Survival_3` | Power Player | Power-up durations +25% |
| `RIG_Survival_4` | Scavenger | Placed pickups (Health/Plating/ammo) give +25% |
| `RIG_Survival_5` | **Grudge-Bearer** | *Unlocks after M21.* Breakdowns on T3 enemies grant 1/3 of a Grudge |

---

## 4. HEART SHARDS (Core Stats)

**Fiction:** Fragments of a crystallized ember-red substance found where the Hymn has "burned out" — calcified dissonance. When the Unsung presses one to the Arrhythm's cage, the heart absorbs it. Only possible in the **Heart Chamber** on the Quietus (a quiet place), so shards are banked until the next hub visit.

**18 Heart Shards** exist: 1 in each of 18 missions (listed in `13_Campaign_Structure.md`). Each shard buys **one step** in any of three tracks (6 steps each; 18 steps total — completionists max all three).

| Step | Vitality (max Health) | Plating (max Plating) | Arsenal (ammo capacity) |
|---|---|---|---|
| 1 | +15 (115) | +15 (65) | Shells +4, Rounds +20, Charge +25, Ordnance +2 |
| 2 | +15 (130) | +15 (80) | same again |
| 3 | +15 (145) → **Perk: Second Pulse** | +15 (95) → **Perk: Iron Skin** | same → **Perk: Double Chord** |
| 4 | +15 (160) | +15 (110) | same |
| 5 | +20 (180) | +20 (130) | same |
| 6 | +20 (200) → **Perk: Heart of the Storm** | +20 (150) → **Perk: Resonant Shell** | same (Shells 48, Rounds 300, Charge 350, Ordnance 24) → **Perk: Deep Pockets** |

| Perk | Effect |
|---|---|
| **Second Pulse** | Breakdown Health drops +25% |
| **Heart of the Storm** | Overdrive duration +4 s |
| **Iron Skin** | Plating pickups and shards +25% |
| **Resonant Shell** | While Plating ≥ 50, Counter window +40 ms and parried notes deal ×4 instead of ×3 |
| **Double Chord** | Power Chord max charges 1 → 2 |
| **Deep Pockets** | Holstered-weapon Pocket Reload is as fast as a normal reload; ammo pickups +25% |

---

## 5. PEDALS (Perks)

**Fiction:** Guitar-effects stompboxes. Harlan gives the Unsung his lucky pedal and a battered **Pedalboard** in M05; Wren wires it into the Rig. Other pedals are found in the wreckage of clubs, studios, bunkers and Static outposts — or, stranger, as Choir-grown "fossils" of human pedals (porcelain-crusted, still working).

**Slots:** 2 (M05) → 3 (end of M11, Wren builds a bigger board) → 4 (end of M19). Swapping is free outside combat.

Each Pedal has a **Boutique** upgrade unlocked by a challenge (the pedal gets a hand-painted finish in the UI).

| # | Pedal | ID | Found | Effect | Boutique challenge → Boutique effect |
|---|---|---|---|---|---|
| 1 | **Boost** | `PDL_Boost` | M05 (story, Harlan) | Surge recharge −25% | *Kill 50 enemies within 1 s after a dash* → dash kills refund a dash charge |
| 2 | **Delay** | `PDL_Delay` | M06 | Breakdowns trigger a delayed echo blast 0.5 s later (100 dmg, 350 radius) | *Kill 40 enemies with echo blasts* → echo repeats twice |
| 3 | **Noise Gate** | `PDL_NoiseGate` | M07 | Falter thresholds raised: T1 45%, T2 25%, T3 15% | *Perform 150 Breakdowns* → Falter duration +1 s |
| 4 | **Reverb** | `PDL_Reverb` | M08 | Counter window +60 ms; reflected notes home in | *Counter 100 notes* → reflected notes explode (80 dmg, 250 radius) |
| 5 | **Fuzz** | `PDL_Fuzz` | M09 | Punches deal ×3 damage and build Gain ×2 | *Kill 60 enemies with punches* → punches instantly stagger T1 |
| 6 | **Phaser** | `PDL_Phaser` | M10 | Surge grants 0.15 s of invulnerability | *Phase through 150 attacks* → a phased attack grants +3 Gain and +5 Plating |
| 7 | **Compressor** | `PDL_Compressor` | M11 | No explosive self-damage; incoming Explosive damage −30% | *Deal 20,000 Explosive damage* → self-knockback +50% (better rocket jumps) |
| 8 | **Whammy** | `PDL_Whammy` | M12 | While airborne: fire rate +15%, and holding Mod Fire slows your fall by 50% | *Kill 100 enemies while airborne* → air kills refund your double jump |
| 9 | **Tremolo** | `PDL_Tremolo` | M13 | Once per checkpoint: lethal damage instead leaves 1 HP and slows time to 25% for 2 s | *Trigger Tremolo and survive the arena, 5 times* → also grants +50 Plating |
| 10 | **Looper** | `PDL_Looper` | M15 | Fodder Shreds have a 30% chance to consume no charge | *Shred 200 enemies* → Heavy Shred refunds 1 charge |
| 11 | **Octaver** | `PDL_Octaver` | M16 | +1 air jump (triple jump) | *Kill 30 enemies with Downbeat* → the extra jump emits a downward pulse (60 dmg, 300 radius) |
| 12 | **Tuner** | `PDL_Tuner` | M17 | Weak points glow brighter and show through walls within 20 m; weak-point hits +1 Gain | *Destroy 150 weak points* → destroying a weak point staggers T2 enemies |
| 13 | **Bitcrusher** | `PDL_Bitcrusher` | M18 | Enemies killed by Energy damage burst into shrapnel (40 dmg, 300 radius) | *Kill 200 enemies with Energy weapons* → shrapnel applies Distorted |
| 14 | **Sustain** | `PDL_Sustain` | M20 | Overdrive +3 s; kills during Overdrive heal 5 HP | *Activate Overdrive 30 times* → Encore cap +6 → +10 s |
| 15 | **Kill Switch** | `PDL_KillSwitch` | M21 | Headshot / weak-point kills reset Surge charges | *Get 100 precision kills* → precision kills refund 2 ammo of that weapon |
| 16 | **Wall of Amps** | `PDL_WallOfAmps` | M23 | While Health < 30%: damage taken −25%, Gain earned ×1.5 | *Survive 20 arenas after dropping below 30% Health* → dropping below 30% grants +20 Plating (once per arena) |

---

## 6. COLLECTIBLES

| Collectible | ID pattern | Count | Where | Reward |
|---|---|---|---|---|
| **Masters** (vinyl records) | `COL_Master_Mxx` | 27 (1/mission) | Secrets | Unlocks a soundtrack track + liner notes in the **Listening Room** turntable |
| **Effigies** (carved figurines of enemies & characters) | `COL_Effigy_nn` | 40 | Secrets | Displayed in the Effigy Gallery; each has a 2-line description (and a joke) |
| **Archive entries** | `ARC_*` | ~160 | Story progress (auto), Archive Stones (violet-glowing data slates / Oreth glyph-stones), enemy first encounters | Codex text |
| **Tabs** (cheat codes as guitar tablature sheets) | `COL_Tab_nn` | 12 | Secrets (M04, M06, M08, M10, M12, M14, M16, M18, M20, M22, M24, M26) | Cheat modifiers for replays (see `16_Optional_Content_and_Modes.md`) |
| **Bootleg Tapes** (cassettes) | `COL_Tape_nn` | 12 | Secrets (odd missions M03–M25) | Unlock **Pit Trials** |
| **Mute Cells** | `COL_MuteCell_n` | 9 | Secrets (M02, M05, M07, M10, M13, M15, M18, M21, M24) | Open Vault Deck doors |
| **Heart Shards** | `COL_HeartShard_nn` | 18 | Secrets / challenge arenas | Core stat upgrades |
| **Rig Cores** | `COL_RigCore_Mxx` | 27 hidden (+36 other sources) | Secrets | Rig tree |
| **Pedals** | `PDL_*` | 16 | 1 story, 15 in secrets | Perks |
| **Requiem Keys** | `COL_RequiemKey_n` | 7 | Hidden in the Requiem Gate missions | Open that mission's Requiem Gate |
| **Reprises** | `PKP_Reprise` | ~20 | Secrets | Extra life |
| **Brass Caches** | `COL_BrassCache_Mxx_n` | 54 | Secrets | 1–2 Brass |

**Secret-design rules** are in `12_Level_Design_Standards.md` §8. Every secret gives *something*; empty secrets are forbidden.

---

## 7. MUTE CELL VAULTS (Quietus Vault Deck)

| Vault | Reward |
|---|---|
| V1 | 1 Rig Core |
| V2 | Rig Finish: **"Rust Bucket"** (orange-primer, patched) |
| V3 | 5 Brass |
| V4 | 1 Rig Core |
| V5 | Weapon Finish set: **"Tour Poster"** (all weapons, gig-poster print) |
| V6 | 5 Brass |
| V7 | 1 Rig Core |
| V8 | Unlocks Pit Trial **"Mute Engine Gauntlet"** |
| V9 | Rig Finish: **"Shieldwarden"** (Oreth pale-stone and silver — only obtainable after M21) |

---

## 8. COSMETICS

* **Rig Finishes** (full-body skins, visible in cutscenes, the hub, FP arms, and shadows): 15 total — unlocked by vaults (2), completing each Act (6), Encore missions (3), the Unsung difficulty (1), 100% collectibles (1), all Requiem Gates (1), the Mute Engine Gauntlet Pit Trial (1).
* **Weapon Finishes:** per-weapon, unlocked by Masteries (one per mastered mod) + vault set.
* **Helmet variants:** 4, from Pit Trials.
* All cosmetics are **earned in-game**. No microtransactions, no online store — the design assumes a premium single-player product.

---

## 9. MISSION CHALLENGES

Every mission has **3 challenges** (listed in each mission document), e.g. *"Kill 3 Crescendos by hitting their back pipes with the Gravedigger"*, *"Counter a Chorister's gold note back into a Cantor's lantern"*, *"Complete the Relay Core arena without taking Health damage"*. Completing all three awards **1 Rig Core** (on mission exit). Progress persists across replays.

---

## 10. PROGRESSION PACING (cumulative targets for a thorough explorer, ~90% collection; a 70% explorer is ~20% lower)

| After mission | Weapons | Heart Shards (Health/Plating) | Rig Cores spent | Brass spent | Pedal slots |
|---|---|---|---|---|---|
| M04 | 5 | 2 (130 / 65) | 4 | 8 | 0 |
| M09 | 7 + Silencer | 5 (145 / 80) | 11 | 26 | 2 |
| M14 | 9 + Silencer | 8 (160 / 95) | 20 | 48 | 3 |
| M19 | 9 + Silencer | 11 (180 / 110) | 28 | 68 | 4 |
| M24 | + Axe | 14 (190 / 130) | 36 | 88 | 4 |
| M27 | all | 18 (200 / 150) | 44 | 105 | 4 |

Encounter budgets in mission docs assume these values on Amplified.
