# 09a — Bestiary, Part 1: Tier 1 (Fodder)

## 0. How to Read an Enemy Entry

Each entry follows the same template so AI builders can create `DA_Enemy_<Name>` DataAssets and Behavior Trees directly.

* **Tier** determines Falter thresholds, Harrow cost, Breakdown Health drop and Gain value (see `04_Core_Gameplay_Loop.md`).
* **Stats are for Amplified (Normal).** Difficulty multipliers are applied at runtime (`23_Difficulty_Balance_Accessibility.md`).
* **Speeds in cm/s, ranges in cm, damage per hit, times in seconds.**
* **Telegraph** = the minimum readable warning before damage. No attack may deal damage with less telegraph than listed.
* **Tokens** = attack tokens the enemy must hold to perform the attack (see `11_AI_and_Encounter_Design.md`).
* **Breakdowns** = synchronized execution animations (`AM_BRK_<Enemy>_<Variant>`).
* **Skeleton classes** (for animation sharing & Breakdown fallbacks): `SKC_Humanoid` (UE5 Manny-compatible), `SKC_Chorister`, `SKC_Quadruped_L` (large quadruped), `SKC_Brute` (large biped), `SKC_Flyer_S` (small flyer), `SKC_Ring` (Ophan), `SKC_Serpent`, `SKC_Arachnid`, `SKC_Tome`, `SKC_Titan`.

**Universal Choir visual language:** porcelain-white calcified skin with fine craquelure, gold seams and filigree, exposed throat/chest resonating structures (vocal-cord strings, organ-pipe clusters, bell shapes), sealed or gold-covered eyes, a **halo** (a thin ring of cyan-white light, 1–3 rings, rotating) behind or above the head. Damage reveals red flesh and golden inner light under cracks.

---

## 1. THRALL — `ENM_Thrall`

| | |
|---|---|
| **Tier / Faction** | T1 Fodder / The Tuned (converted human) |
| **First appears** | M01 |
| **Role** | Shambling melee swarm; the game's "health and ammo piñata" |
| **Size** | 180 cm tall; capsule r 38 / hh 90 |
| **HP** | 60 · Falter at 35% |
| **Speed** | Shamble 180 · Pursuit 320 · Lunge 900 (burst) |
| **Perception** | Sight 3000 cm, 120° FOV; hearing 2000 cm |
| **Harrow** | Shred (1 charge) |

**Visual design:** A converted civilian still wearing tattered clothing (lab coats in M01, work clothes, suits, stadium fan gear in M04 — use 6 clothing variants + 4 head variants). Skin crusted with patchy porcelain gilding, most heavily on the face and hands. The jaw has split vertically into a two-petal singing mouth with vocal cords visible inside. Eyes sealed with gold. Head tilted back as if listening to the sky. A faint single halo ring, flickering. Posture: arms slack, shoulders hunched, swaying to an unheard rhythm.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Tokens | Notes |
|---|---|---|---|---|---|---|
| Claw | 12 | 180 | 0.5 s (arm raise + choking inhale) | 1.2 | Melee×1 | 2-swipe combo max |
| Lunge Bite | 18 | 400–600 | 0.6 s (crouch + rising "ahh") | 4.0 | Melee×1 | Leap at the player; if it connects, a 0.4 s grapple shake (no input lock) |

**Behavior:** Wanders toward the Hymn source when idle (sways in place near Choir growths). On alert, pursues directly with slight path noise (±150 cm lateral) so crowds spread out. Uses the Lunge when the player is at medium range and not moving toward it. Thralls do **not** use cover.

**Weaknesses / answers:** Everything. One Breacher shot at close range, 2–3 Riveter hits, 2 punches + Breakdown. Ideal Shred and Breakdown fodder.

**Breakdowns:** `Front_JawRip` (tear the singing jaw apart), `Front_Headcrush`, `Back_SpineSnap`, `Air_Stomp` (player above), `Side_WallSlam` (if a wall is within 150 cm), `Low_Curbstomp` (enemy crawling).

**Variants**
* **Tuned Worker skin set** (hard hats, hi-vis) for industrial missions; **Tuned Fan** (stadium gear) for M04; **Tuned Crew** (CDF jumpsuits) for military bases. Same stats.
* **Crawler state:** if a leg is severed, it crawls at 150 cm/s and can still bite (10 dmg).

**Audio:** Off-key unison hum (all Thralls in an area hum the same note — creepy). Alert: breathy rising "ahh". Attack tell: choking inhale. Death: wet crack, chord cut off.

**Animations:** Idle_Sway ×3, Walk_Shamble, Run, Lunge (start/air/land), Claw_A/B, HitReact (F/B/L/R + head), Falter_Loop, Crawl, Death ×3, Spawn_Emerge (from Choir growth), Spawn_Drop (from ledge), Spawn_Hymnfall (descending in light).

---

## 2. BLOATED THRALL — `ENM_ThrallBloated`

| | |
|---|---|
| **Tier / Faction** | T1 / The Tuned |
| **First appears** | M05 |
| **Role** | Walking bomb; area denial; a tool the player can turn against enemies |
| **Size** | 190 cm; capsule r 55 / hh 95 |
| **HP** | 90 · no Falter (it bursts instead) |
| **Speed** | Walk 200 · Waddle-run 300 |
| **Harrow** | **Fling** (special, see below) |

**Visual:** A Thrall swollen with pressurized resonance — the torso is a translucent porcelain balloon with glowing cyan fluid sloshing inside, cracks leaking light, the singing mouth distended. It wheezes a rising tone.

**Attacks**
| Attack | Damage | Range | Telegraph | Notes |
|---|---|---|---|---|
| Swell & Burst | 120 (Explosive, hurts enemies too) | radius 350 | 1.2 s: body inflates, pitch rises sharply, cyan glow flashes | Triggers when within 300 cm of the player |
| Death Burst | 120 | radius 350 | — | Always bursts on death (any cause) |

**Special — Fling:** Firing the Harrow at a Bloated Thrall doesn't Shred it: the Unsung whips it through the air toward the enemy nearest the crosshair (or straight ahead), where it bursts on impact. Costs 0 charges. +4 Gain if it kills anything.

**Answers:** Shoot early from range; Fling it into crowds; Hush freezes it (it bursts when the Hush ends unless killed first — killing it while Hushed still bursts).

**Breakdowns:** None (cannot Falter).

---

## 3. TUNED TROOPER — `ENM_Trooper`

| | |
|---|---|
| **Tier / Faction** | T1 / The Tuned (converted CDF or Static soldiers) |
| **First appears** | M01 (CDF guards), M02 (Static strike team) |
| **Role** | Basic ranged fodder; pressure from mid-range |
| **Size** | 185 cm; capsule r 40 / hh 92 |
| **HP** | 90 · Falter 35% |
| **Speed** | Walk 300 · Run 450 |
| **Harrow** | Shred (1) |

**Visual:** A soldier in CDF or Static gear, helmet cracked open and fused to a porcelain skull; the Static Collar on its neck broken and gilded over, its VU lights dead. The rifle is fused into its forearm with bone growth. Singing mouth visible behind a torn gas mask.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Tokens | Notes |
|---|---|---|---|---|---|---|
| Burst Fire | 3 × 8 | 2500 | 0.6 s (raises rifle, muzzle flares cyan, a short rising chord) | 2.5 | Ranged×1 | Projectile tracers at 6000 cm/s — dodgeable at range |
| Rifle Butt | 15 | 180 | 0.4 s | 2.0 | Melee×1 | — |

**Behavior:** Moves between **hold points** (tactical positions marked in the arena, `BP_AIHoldPoint`) with line of sight, strafes while firing, never approaches closer than 600 cm unless cornered. Relocates when the player gets within 500 cm (retreats 400–800 cm). No cover system — hold points are chosen for sightlines only.

**Breakdowns:** `Front_RifleTwist` (bend its fused rifle into its face), `Back_NeckSnap`, `Side_Kneebreak`, `Air_Headspike`.

**Loss of arm:** If the rifle arm is severed, the Trooper switches to melee-only (Thrall behavior).

---

## 4. TUNED BULWARK — `ENM_TrooperBulwark`

| | |
|---|---|
| **Tier** | T1 (shielded) |
| **First appears** | M02 |
| **Role** | Frontal wall; teaches flanking and Energy/Power Chord usage |
| **Size** | 195 cm; capsule r 45 / hh 97 (shield adds a frontal hitbox 150 w × 200 h) |
| **HP** | 110 body · **300 shield** |
| **Speed** | Walk 250 (shield raised) · Run 400 |
| **Harrow** | Shield up: Harrow **bounces** (0.3 s stun on player's arm) · shield broken: Shred (1) |

**Visual:** A riot trooper whose riot shield has fused into its left arm, grown over with porcelain and a lattice of gold — the shield is now a thick, faintly translucent slab with screaming faces embedded in it. Carries a sidearm.

**Shield rules:** Blocks 100% of frontal (120°) damage. Shield takes damage: Kinetic ×1, Explosive ×1.5, **Energy ×3**, **Hot Rivets ×3**. **Power Chord breaks it instantly**. When broken: the Bulwark staggers (instant Falter).

**Attacks**
| Attack | Damage | Range | Telegraph | Notes |
|---|---|---|---|---|
| Sidearm | 10 per shot, 1 shot/1.2 s | 2000 | 0.4 s cyan flare | Fires over the shield |
| Shield Bash | 20 + knockback 600 | 250 | 0.5 s (plants foot) | — |
| Shield Charge | 25 + knockback | 1000 dash | 0.8 s (roar, lowers head) | Used when the player is directly ahead and 500–1000 away |

**Behavior:** Advances slowly toward the player keeping the shield facing them (turn rate 120°/s — outpaceable with a dash). Often escorts Troopers.

**Breakdowns:** `Front_ShieldSmash` (punch through the broken shield), `Back_ShieldRip`.

---

## 5. TUNED MARKSMAN — `ENM_TrooperMarksman`

| | |
|---|---|
| **Tier** | T1 (sniper) |
| **First appears** | M06 |
| **Role** | Long-range threat that forces movement and teaches Counter vs. fast gold shots |
| **Size** | 185 cm |
| **HP** | 80 · Falter 35% |
| **Harrow** | Shred (1) |

**Visual:** A CDF sniper with a long rifle grown into a bone-and-brass lance; one eye is replaced by a gold lens.

**Attack — Hymn Shot:** Aims with a visible **cyan laser line** for 1.5 s (the line turns **gold** for the last 0.4 s + a two-note chime); fires a gold-ringed slug at 8000 cm/s, **30 dmg**. **Parryable** (Counter reflects it and kills the Marksman outright). Breaking line of sight during the aim resets it. Cooldown 4 s. Tokens: Ranged×1 (special "Sniper" token pool, max 2 active).

**Behavior:** Occupies high hold points ≥ 1500 cm from the player. Retreats along pre-placed perches when the player approaches.

**Breakdowns:** `Front_LensGouge`, `Back_RifleThrough`.

---

## 6. CHORISTER — `ENM_Chorister`

| | |
|---|---|
| **Tier / Faction** | T1 / The Host (pure Choir-form) |
| **First appears** | M01 (late), gold notes from M02 |
| **Role** | Signature agile ranged fodder (the game's "imp"); teaches Counter |
| **Size** | 200 cm standing (often crouched at 140); capsule r 38 / hh 80 (crouched) |
| **HP** | 140 · Falter 35% |
| **Speed** | Run 500 · Leap up to 900 horizontal / 500 vertical · **Wall-climb** 350 |
| **Harrow** | Shred (1) |

**Visual design:** A lean, long-limbed, emaciated figure of smooth porcelain-white skin, like a porcelain choirboy stretched too tall. Moves on all fours or upright. Its head is smooth and eyeless, and the entire face splits open into a **four-petal mouth** (upper/lower/left/right) revealing rings of teeth and a glowing throat. Long throat with visible gold vocal cords. Two thin halo rings. Fingers long with gold-tipped claws. Gold filigree traces its spine like sheet-music lines.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Tokens | Notes |
|---|---|---|---|---|---|---|
| Note Throw | 12 | 3000 | 0.45 s: petals open, throat glows cyan, high "ah" | 1.8 | Ranged×1 | Cyan sphere, 2500 cm/s, slight lead-aim on Overdriven+ |
| **Resonant Note** | 20 | 3000 | 0.8 s: petals open wide, gold ring forms, rising glissando | 6.0 | Ranged×1 | **Gold ring — parryable**; 1800 cm/s; reflected = Chorister Falters |
| Rake | 15 | 200 | 0.4 s | 1.5 | Melee×1 | 2-hit combo |
| Pounce | 20 | 500–900 | 0.6 s crouch + hiss | 5.0 | Melee×1 | Leap attack |

**Behavior:** Highly mobile. Prefers elevated positions (ledges, walls, ceilings in tall rooms). Relocates by leaping or wall-climbing after every 1–2 attacks (never stays still > 3 s). Dodges sideways (400 cm) when the player aims at it for > 0.8 s (cooldown 4 s; not while attacking). Climbs walls tagged `ChoirClimbable` (default: all walls in arenas unless opted out).

**Weaknesses / answers:** Riveter headshots; Counter its gold notes; Shred it. Arc Coil chains between groups.

**Breakdowns:** `Front_MouthSplit` (grip two petals and tear), `Back_ThroatPull` (rip the vocal cords out through the back), `Wall_Slam` (if on a wall), `Air_Spike` (catch it mid-leap), `Low_Stomp`.

**Audio:** High soprano "ah". The **gold note** has a distinct longer, higher glissando + chime — the game's most important audio tell.

**Animations:** Idle_Crouch ×2, Idle_Upright, Run_Quadruped, Run_Biped, Leap (start/air/land), WallClimb (loop, transitions floor↔wall↔ceiling), Throw_Cyan, Throw_Gold, Rake_A/B, Pounce, Dodge_L/R, HitReact ×5, Falter, Death ×3, Spawn_Hymnfall, Spawn_WallBurst.

---

## 7. VESPER — `ENM_Vesper`

| | |
|---|---|
| **Tier / Faction** | T1 / The Host |
| **First appears** | M02 |
| **Role** | Flying swarm; forces vertical aim and area weapons |
| **Size** | 90 cm wingspan, 70 cm long; capsule r 30 |
| **HP** | 50 · Falter 35% (Faltering Vespers drop to the ground, twitching — Breakdown on the ground) |
| **Speed** | Fly 700 · Dive 1400 |
| **Harrow** | Shred (1) — yanked out of the air |

**Visual:** A wasp-like porcelain creature: a slender segmented body, a small eyeless head with a tiny four-petal mouth, two pairs of translucent gold-veined wings that hum (a choir's "mmm"), and a stinger shaped like a tuning fork. A single tiny halo.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Tokens |
|---|---|---|---|---|---|
| Needle Notes | 3 × 6 | 2000 | 0.4 s: wings flare cyan, pitch up | 2.2 | Ranged×1 (pack shares 2 tokens) |
| Dive Sting | 10 | dive 1000 | 0.5 s hover-freeze + buzz | 5.0 | Melee×1 |

**Behavior:** Swarms of 3–8 using **boids** (separation 150, cohesion radius 600, alignment) around an orbit point near the player (radius 800–1200, altitude 300–700 above the ground). Individual Vespers peel off to attack.

**Answers:** Arc Coil (chain), Hammerfall splash, Lock Salvo, Storm Node, Static Rifle.

**Breakdowns:** `Ground_Crush` (fist into the twitching body), `Air_Clap` (catch between both hands, if the player is airborne).

---

## 8. WAILER — `ENM_Wailer`

| | |
|---|---|
| **Tier / Faction** | T1 / The Host (spawned) |
| **First appears** | M03 |
| **Role** | Kamikaze flyer; spawned by Hymnals and Maestros |
| **Size** | 60 cm; capsule r 30 |
| **HP** | 30 · no Falter |
| **Speed** | Drift 300 · Charge 900 |
| **Harrow** | Shred (1) — gives a reduced ammo burst (50%) |

**Visual:** A disembodied porcelain head — mouth stretched open in an endless scream — trailing a ribbon of glowing vertebrae like a comet's tail. Cyan light pours from its mouth and eyes.

**Attack — Wail Burst:** Charges the player with a rising scream (0.8 s telegraph: it stops, shudders, scream pitch rises); on contact or when within 150 cm, bursts: **20 dmg**, radius 250 (Sonic). Can be shot mid-charge. A Wailer killed mid-charge bursts where it dies (also hurts other enemies, 20 dmg).

**Behavior:** Spawns in pairs from Hymnals; drifts, then charges in sequence (never more than 2 charging simultaneously — `Kamikaze` token pool of 2).

**Breakdowns:** None.

---

## 9. CONSONANCE ACOLYTE — `ENM_Acolyte`

| | |
|---|---|
| **Tier / Faction** | T1 / The Consonance (harmonized human cultist) |
| **First appears** | M07 (also M09, M19, M23–M24) |
| **Role** | Coordinated human ranged enemy; voiced; grenadier |
| **Size** | 180 cm |
| **HP** | 100 · Falter 35% |
| **Speed** | Walk 350 · Run 500 |
| **Harrow** | Shred (1) |

**Visual:** A human in white-and-gold tactical robes over light armor, face uncovered (half-gilded on veterans), a projected gold **halo-ring** device on a collar mount, the Consonance Seal on the chest. Carries a **Hymn Rifle** (sleek white rifle with a ring-shaped emitter muzzle).

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| Hymn Rifle | 3 × 9 | 2500 | 0.5 s (emitter ring spins up, tone) | 2.0 | Cyan ring-pulses (not parryable — cyan) |
| **Chime Grenade** | 45 (Explosive) | throw 1500, radius 300 | The chime rings **3 times** over 1.5 s after landing, then detonates | 10.0 | Can be shot to detonate early; **Counter** knocks it back toward the thrower (gold chime) |
| Harmonize | heals 50 HP on self or ally | 800 | 1.5 s kneel + chant (interruptible) | 15.0 | Only when HP < 50% and no player within 600 cm |

**Behavior:** Squad-based (3–6), uses hold points like Troopers, calls out actions (voiced barks: "*Sing with us!*", "*It's here — the Wrong Note!*", "*Chime out!*", "*Forgive me—*"). Morale: when a squad loses 50%, remaining Acolytes may flee (30%) toward the nearest exit or a Choirmaster.

**Breakdowns:** `Front_HaloCrush` (smash the halo device into their face), `Back_RobeTwist`, `Side_RifleBreak`.

---

## 10. CONSONANCE ZEALOT — `ENM_Zealot`

| | |
|---|---|
| **Tier** | T1 / The Consonance |
| **First appears** | M07 |
| **Role** | Fast melee rusher and suicide threat |
| **HP** | 120 · Falter 35% |
| **Speed** | Sprint 700 |
| **Harrow** | Shred (1) |

**Visual:** Bare-chested fanatic in white wraps, skin painted with gold staff-lines, eyes bandaged with gold cloth, wielding two short **resonance blades** (curved white blades that hum).

**Attacks**
| Attack | Damage | Range | Telegraph | Notes |
|---|---|---|---|---|
| Blade Flurry | 3 × 12 | 200 | 0.4 s (blades ring) | Last hit flashes **gold** (parryable → instant Falter) |
| Leap Strike | 20 | 700 | 0.5 s crouch + scream | — |
| **Martyr Hymn** | 60 (Explosive) radius 350 | contact | At < 25% HP: drops blades, arms spread, sings a sustained note, glows white and sprints (800) straight at the player for up to 3 s, then detonates | Kill it, Breakdown it, Hush it, or dash away |

**Breakdowns:** `Front_BladeReturn` (turn its blades on it), `Back_Suplex`.

---

## 11. Fodder Summary Table

| ID | HP | Speed | Main threat | Harrow | Gold attack? | First |
|---|---|---|---|---|---|---|
| ENM_Thrall | 60 | 320 | Melee swarm | Shred | — | M01 |
| ENM_ThrallBloated | 90 | 300 | 120 AoE burst | Fling | — | M05 |
| ENM_Trooper | 90 | 450 | 3×8 bursts | Shred | — | M01 |
| ENM_TrooperBulwark | 110+300 | 400 | Shield wall | Bounce/Shred | — | M02 |
| ENM_TrooperMarksman | 80 | 450 | 30 dmg sniper | Shred | Yes (shot) | M06 |
| ENM_Chorister | 140 | 500 | Mobile ranged | Shred | Yes (note) | M01 |
| ENM_Vesper | 50 | 700 fly | Swarm needles | Shred | — | M02 |
| ENM_Wailer | 30 | 900 fly | Kamikaze 20 | Shred (½) | — | M03 |
| ENM_Acolyte | 100 | 500 | Rifle + chime grenade | Shred | Yes (chime) | M07 |
| ENM_Zealot | 120 | 700 | Rush + martyr blast | Shred | Yes (3rd slash) | M07 |
