# 16 — Optional Content & Modes

## 1. REQUIEM GATES (7)

**Concept:** ossuary doors of bone, each with a hanging bronze bell. A **Requiem Key** (a small bell-shaped key of black iron, hidden in the same mission) opens it. Inside: a brutal, hand-tuned elite arena with a special modifier. Completing one grants a **Reliquary Shard** (7 → **The Larynx**), **3 Brass** and a **Mastery Pick**.

**Rules:**
* Entering is optional and can be done any time the player has the key (also on replays).
* Difficulty is fixed at **one step above** the player's current difficulty (max Unsung-level stats; no permadeath inside unless already on Unsung).
* No checkpoints inside; failure returns the player to the gate (key kept).
* Each gate's interior is a unique arena built in the mission's kit (reusing assets).

| # | ID | Name | Mission | Arena | Modifier | Waves (summary) |
|---|---|---|---|---|---|---|
| 1 | `RQG_01` | **The Ossuary Toll** | M06 | A frozen ossuary chapel (40 × 40 m, 3 tiers) | **Tolling Bell:** every 20 s, a bell tolls and all enemies gain Anthem for 5 s | 4 waves; 2 Bellwethers + Crescendos + Marksmen |
| 2 | `RQG_02` | **The March Eternal** | M08 | A bone parade ground (50 × 50 m) | **Lockstep:** phalanx formations every wave; the drum can't be destroyed | 5 waves; phalanxes + Requiem Knight + Hymnals |
| 3 | `RQG_03` | **The Iron Choir** | M11 | A kiln hall (45 × 35 m) with pistons | **Assembly Line:** Organ Grinders assemble every 30 s until 4 are alive | 4 waves; Organ Grinders + Canons + Choristers |
| 4 | `RQG_04` | **Sunward** | M13 | An open mirror platform (60 m) | **Full Exposure:** only 30% of the floor is shaded, and the shade moves | 4 waves; Profundos + Seraphs + Ophans |
| 5 | `RQG_05` | **Drowned Hymns** | M16 | A flooding cistern dome | **Rising Tide:** the floor floods in 3 stages over the fight (platforms only at the end) | 5 waves; Sirens + Gilded Bellwether + Carillon |
| 6 | `RQG_06` | **Lucid Dread** | M18 | A floating dream island cluster | **Doubt:** 50% of all enemies are illusions (no shadows, no halos) — and illusions *do* deal 50% damage here | 5 waves; mixed + Maestro |
| 7 | `RQG_07` | **The Last Warden** | M22 | A shifting Oreth plaza (3 configs) | **Unresolved:** the arena reconfigures every 30 s | 6 waves; everything, ending with 2 Requiem Knights + a Gilded Profundo |

**The Larynx:** after the 7th Reliquary Shard, Wren assembles it in the Armory (`BRK_Wren_Larynx`: "*We tore it out of a Maestro's throat. It still sings. It hates us. It works.*").

---

## 2. CHOIR MASSES (35)

**Concept:** optional encounter triggers (the Gore-Nest equivalent). A **Choir Mass** is a wall-sized organic mass of fused, singing Tuned bodies with a pulsing gold **heart**. Punching the heart (melee interact) starts a 2–3 wave encounter in the surrounding space; completion destroys the Mass.

**Rules:**
* Always in a side-space off the critical path (never blocking progress).
* 2–3 waves, 90–150 s total; composition = the mission's current enemy palette at +10% intensity.
* Reward: **1 Brass** + a resource burst (Health/Plating/ammo) + (sometimes) access to a secret behind the Mass.
* Mass IDs: `CM_Mxx_nn` — locations are listed in each mission document.

| Mission | Count | Mission | Count |
|---|---|---|---|
| M03 | 1 | M15 | 2 |
| M04 | 1 | M16 | 1 |
| M05 | 1 | M17 | 2 |
| M06 | 2 | M18 | 1 |
| M07 | 1 | M19 | 2 |
| M08 | 2 | M20 | 2 |
| M09 | 2 | M21 | 1 |
| M10 | 1 | M22 | 2 |
| M11 | 1 | M23 | 2 |
| M12 | 2 | M24 | 1 |
| M13 | 1 | M25 | 2 |
| | | M26 | 2 |
| | | **Total** | **35** |

---

## 3. THE PIT — Trials

**Concept:** The Pit is the Quietus's training arena (ex-Cargo Hold 2): a 60 × 60 × 25 m modular arena whose layout can reconfigure (floor sections rise/fall, platforms slide out — `BP_PitArena` with 6 layouts). Trials are unlocked by **Bootleg Tapes** (cassettes found in missions) — slotting a tape into the Pit's boombox starts that trial.

| # | Tape (mission) | Trial | Rules | Reward |
|---|---|---|---|---|
| 1 | M03 | **Gravedigger Only** | Gravedigger + melee only; 5 waves | 1 Rig Core |
| 2 | M05 | **Riff Machine** | Damage only counts if it's a Riff (within 0.75 s of switching); kill 60 enemies | 2 Brass |
| 3 | M07 | **No Shooting** | Melee, Harrow, equipment, abilities only | 1 Rig Core |
| 4 | M09 | **Echo Chamber** | Every enemy is Echoed | 2 Brass + helmet "Headphones" |
| 5 | M11 | **Big Iron** | Anvil Siege Frame vs. titans (mech-scale Pit layout) | 1 Rig Core |
| 6 | M13 | **Blinded** | Constant glare filter; enemies only visible by halos and rim light | 2 Brass |
| 7 | M15 | **Cold Open** | Start at 1 HP, no Plating; only Breakdowns heal | 1 Rig Core |
| 8 | M17 | **Lucid** | Illusions everywhere; only 3 real enemies per wave | 2 Brass + helmet "Sleep Mask" |
| 9 | M19 | **Liberation** | Protect 12 captive-props from waves | 1 Rig Core |
| 10 | M21 | **Axe to Grind** | Axe only; Grudges regenerate every 10 s | 2 Brass + helmet "Warden" |
| 11 | M23 | **Army of One** | Endless waves; score attack (leaderboard is local) | 1 Rig Core |
| 12 | M25 | **Staves** | Note-Platform gauntlet with waves | 2 Brass + helmet "Clef" |
| V8 | Vault 8 | **Mute Engine Gauntlet** | 10 waves of everything, no pickups except from enemies | Mastery Pick + Rig Finish "Gauntlet Gold" |

*(6 Trials award Rig Cores — matching the economy in `08`.)*

**Free Practice:** the Pit also offers a sandbox spawner (any enemy the player has encountered, any count), invulnerability toggle, and damage dummies showing DPS.

---

## 4. ENCORE MISSIONS (post-game "Master Levels")

**Concept:** remixed versions of six missions with new enemy placements, altered layouts (new routes opened/closed), new modifiers and a harder composition, unlocked after completing the campaign. Each Encore is a single continuous run (checkpoints only at arena starts).

| Encore | Base | Remix concept |
|---|---|---|
| **Encore: Rapture (Stadium Mix)** | M04 | Night; the crowd is hostile from the start; Ionian returns with Gilded hands |
| **Encore: The Iron Psalm (Dirge Mix)** | M08 | Twice the phalanxes; Requiem Knights everywhere; Dorian gains a 4th phase |
| **Encore: The Assembly (Overtime Mix)** | M11 | The factory runs at double speed (hazard cycles ×2); two Engine Hymns |
| **Encore: Corona (Solar Flare Mix)** | M13 | Solar flares periodically flood the whole level with exposure (hide in shelters on a timer) |
| **Encore: The Dreaming Choir (Nightmare Mix)** | M18 | Lydian's dream becomes a nightmare: illusions deal damage; gravity flips randomly (telegraphed) |
| **Encore: The Octave (Requiem Mix)** | M24 | Aurelia's memories are hostile; the Octave sings the scale *backwards* (new pattern) |

**Rewards:** completing 2 / 4 / 6 Encores unlocks Rig Finishes "**Live at Halcyon**", "**Bootleg**", "**Platinum**".

---

## 5. TABS (Cheat Codes)

Tabs are guitar-tablature sheets found in secrets. They can be toggled from the pause menu in **Mission Replay and Encore** only (never in a first playthrough of a mission).

| # | Tab | Found | Effect | Affects progress? |
|---|---|---|---|---|
| 1 | **Big Head** | M04 | Enemies' heads ×3 size | No (cosmetic) |
| 2 | **Iron Lungs** | M06 | Infinite Harrow charges | **Yes** — disables challenge/mastery progress |
| 3 | **Confetti** | M08 | Enemies burst into confetti and party horns | No |
| 4 | **Heavy Metal** | M10 | ×2 recoil and screen shake | No |
| 5 | **Sunburn** | M12 | Enemies may burst into flames on death | No |
| 6 | **Mixtape** | M14 | Replace the soundtrack with a playlist of unlocked Masters | No |
| 7 | **Deep Sea** | M16 | Underwater tint; corpses float | No |
| 8 | **Dream Logic** | M18 | Low gravity for everyone | **Yes** |
| 9 | **Unison** | M20 | Kills build a choir chord across the arena | No |
| 10 | **Resolved** | M22 | All enemy telegraphs 50% longer | **Yes** |
| 11 | **Choir Boy** | M24 | The Unsung's heartbeat replaced by an angelic "ah"; Choir voices pitched up | No |
| 12 | **Loudest** | M26 | All SFX ×2 louder; footsteps shake the camera | No |

---

## 6. NEW GAME+ — "REISSUE"

* Unlocked after the campaign. Start a new campaign keeping: all weapons & mods (weapons appear in missions as normal but the player already has them), all upgrades, Pedals & slots, cosmetics, collectibles tracking.
* **Changes:** enemy HP ×1.3, Elite substitution 30%, new Gilded variants appear from Act I, some arenas get "Reissue" bonus waves, Choir Masses give 2 Brass (for the few upgrades left).
* Difficulty selectable independently.

---

## 7. UNSUNG DIFFICULTY (Permadeath)

* Unlocked from the start (warning dialog) — the true test.
* One life for the whole campaign (**Reprises** still work — they are the only safety net and extremely valuable).
* Death → the save is marked "Forgotten" (the save slot shows the mission, the time and the killer — with a tombstone-like card: "*Here the Unsung fell silent.*").
* Enemy stats as Deafening. Rig Finish "**Unsung**" (pure black, no rust, a single ember line) on completion.

---

## 8. CUSTOM DIFFICULTY

Sliders (each 0.5×–2×): enemy damage, enemy health, player damage taken, resource drop amounts, parry window, enemy aggression (token counts), Hymnfall spawn counts, elite substitution %, solar/hazard damage. Presets load the 6 standard difficulties. Custom games can't unlock difficulty-specific rewards.

---

## 9. ACHIEVEMENTS (40)

| # | Name | Condition |
|---|---|---|
| 1 | **First Noise** | Complete M01 |
| 2 | **Wrong Note** | Complete Act I |
| 3 | **The Tuned Earth** | Complete Act II |
| 4 | **Iron and Fire** | Complete Act III |
| 5 | **Deep Water, High Air** | Complete Act IV |
| 6 | **Homecoming** | Complete Act V |
| 7 | **Make It Loud** | Complete the campaign |
| 8 | **Deafening** | Complete the campaign on Deafening |
| 9 | **Unsung** | Complete the campaign on Unsung difficulty |
| 10 | **Seven Voices** | Defeat all seven Archons |
| 11 | **Back to Sender** | Counter 500 gold attacks |
| 12 | **Rip and Reload** | Shred 1,000 enemies |
| 13 | **Breakdown Artist** | Perform 1,500 Breakdowns |
| 14 | **Feedback Loop** | Gain 10,000 Plating from Distort |
| 15 | **Overdriven** | Activate Overdrive 100 times |
| 16 | **Encore!** | Extend a single Overdrive by 6 s (Encore cap) |
| 17 | **Riff Lord** | Land 2,000 Riffs |
| 18 | **Chord Change** | Kill 5 enemies with 5 different weapons within 5 seconds |
| 19 | **Hushed** | Destroy 50 Echoes with silence |
| 20 | **Fling Theory** | Kill 3 enemies with one flung Bloated Thrall |
| 21 | **Bell Ringer** | Destroy 100 Carillon bells |
| 22 | **Guard Break** | Break 100 Requiem Knight guards with Counters |
| 23 | **Big Iron** | Destroy 10 Titans in the Anvil |
| 24 | **Unplugged** | Complete a Pit Trial without taking damage |
| 25 | **Fully Loaded** | Max out every weapon mod |
| 26 | **Master Class** | Complete every Mastery |
| 27 | **Pedal to the Metal** | Collect all 16 Pedals |
| 28 | **Boutique** | Upgrade 8 Pedals to Boutique |
| 29 | **Heart Out of Time** | Collect all 18 Heart Shards |
| 30 | **Rig Complete** | Buy every Rig upgrade |
| 31 | **Crate Digger** | Collect all 27 Masters |
| 32 | **Collector's Shelf** | Collect all 40 Effigies |
| 33 | **Bootlegger** | Collect all 12 Bootleg Tapes |
| 34 | **Cheat Sheet** | Collect all 12 Tabs |
| 35 | **Requiem** | Complete all 7 Requiem Gates |
| 36 | **Stolen Voice** | Assemble the Larynx |
| 37 | **Wind Song** | Unseal all seven Wind Towers of Aubade |
| 38 | **Freedom** | Free every captive hall in the Chancel |
| 39 | **Screen Time** | Smash 25 screens showing Aurelia |
| 40 | **Thank You** | Watch the full epilogue |
