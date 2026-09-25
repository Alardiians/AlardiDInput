# 09b — Bestiary, Part 2: Tier 2 (Heavy)

All Tier 2 enemies: Falter at 20% HP (3.0 s), Heavy Shred with 3 Harrow charges (full ammo refill), otherwise Reel-In. Breakdown drops 40 Health. Kill = +8 Gain.

---

## 1. CRESCENDO — `ENM_Crescendo`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M03 |
| **Role** | Charger that punishes standing still; teaches side-dodging and back-attacks |
| **Size** | 300 cm tall at the shoulder, 450 long; capsule r 120 / hh 150 |
| **HP** | 1000 · **Front plate** (face-shield): damage from the front 60° ×0.3 · **Back bellows** (weak point): ×2.5 |
| **Speed** | Walk 300 · Charge 400 → 1600 over 2.0 s |
| **Skeleton** | `SKC_Quadruped_L` |

**Visual design:** A massive, hunched quadruped. Its entire front is a curved shield-plate of fused porcelain faces, all mouths open, the whole plate like a choir frozen mid-scream. Front limbs are thick pillars ending in gold-shod hooves. Its back is exposed: raw red flesh with a double row of brass-and-bone **organ pipes** ("bellows") that pump and wheeze, glowing brighter as it charges. Halo: a spinning ring around its neck.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Crescendo Charge** | 45 + knockback 1200 | up to 3000 | 1.0 s: stamps, bellows inhale, a swelling bellow that grows louder through the charge | 6.0 | Turn rate drops from 180°/s to 30°/s as speed rises. Hitting a wall = **Crash**: stunned 2.0 s (back exposed, takes ×1.25 everywhere) |
| Gore Swipe | 30 | 350 | 0.6 s head-toss | 2.5 | When the player is close |
| Trample | 20 | contact | — | — | During the charge, T1 enemies in its path are killed (friendly fire) |

**Answers:** Dash sideways at the last moment (≥ 400 cm lateral), then shoot the bellows; Gravedigger to the back; Hush Charge freezes it mid-charge (perfect back-shot window); make it Crash into walls.

**Breakdowns:** `Back_PipeRip` (tear out a pipe and ram it through), `Front_PlateSplit` (from front: pry the face-plate apart), `Crash_Headstomp` (while crashed).

**Audio:** Deep grinding drone; the charge is a literal **crescendo** (volume and pitch ramp). Players must learn: the louder it gets, the faster it is.

---

## 2. BELLWETHER — `ENM_Bellwether`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M06 |
| **Role** | Heavy melee bruiser with area shockwaves; teaches jumping over rings and Counter on heavies |
| **Size** | 350 cm; capsule r 110 / hh 175 |
| **HP** | 1500 · **Bell body** weak point (only while ringing): ×2 |
| **Speed** | Walk 300 · Run 550 · Leap up to 1500 |
| **Skeleton** | `SKC_Brute` |

**Visual design:** A towering humanoid whose entire torso is a great **bronze-and-porcelain bell** (mouth of the bell facing down around its hips); thick arms like pillars ending in fists fused with bell-clappers; a small head set into the bell's crown, face serene with sealed gold eyes. Legs digitigrade and heavy. Gold engraved bands of sheet-music glyphs around the bell.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Toll Slam** | 25 per ring | Two expanding ring shockwaves (0.3 s apart), radius up to 1200, height 60 cm | 0.9 s: raises both fists, the bell glows | 7.0 | **Jump over the rings.** After the slam the bell **rings** (glows gold) for 1.5 s: bell weak point active; a Power Chord to the bell = instant Falter |
| Leap Slam | 35, radius 400 | up to 1500 | 0.8 s crouch + gong swell; shadow marker on landing spot | 9.0 | — |
| Clapper Swing | 30 | 350 | 0.5 s | 2.0 | 2-hit combo |
| **Gold Toll** | 40 | 350 | 0.6 s: gold flash + chime (overhead smash) | 12.0 | **Parryable** → Guard Break 1.5 s |

**Answers:** Jump the rings, punish the ringing bell, Counter the Gold Toll, Hammerfall/Gravedigger.

**Breakdowns:** `Front_BellCrack` (punch through the bell, rip out the clapper), `Back_HeadTwist` (climb the bell, twist the head off), `Air_BellDive` (drop onto the crown).

**Audio:** Deep bronze bell tones; each footstep has a faint tuned "bong".

### Variant — Gilded Bellwether (`ENM_BellwetherGilded`) — see `09c` §5.

---

## 3. SERAPH — `ENM_Seraph`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M04 |
| **Role** | Hovering missile platform with destructible wing-pipes; teaches weak-point sniping |
| **Size** | 300 cm; capsule r 60 / hh 150; wingspan 500 |
| **HP** | 800 · **Wing-pipes** ×2 (left/right), 150 HP each, ×2 damage |
| **Speed** | Walk 350 · Hover (vertical 600, horizontal 400) |
| **Skeleton** | `SKC_Humanoid` (tall) + wing-pipe bones |

**Visual design:** A tall, skeletal, elegant porcelain figure — a gaunt humanoid with elongated limbs, ribs exposed like a birdcage around a glowing heart-bell. From its back sprout **six "wings" made of brass organ pipes** (three per side) that fire jets of pale light for flight. Shoulders carry two horn-shaped **chime launchers**. Head: a narrow, smooth mask with a single vertical slit mouth. A large triple halo.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Chime Missiles** | 2 × 20 (Explosive, r 150) | 4000 | 0.7 s: shoulder horns glow, a two-bell toll | 4.0 | Homing (turn rate 90°/s, speed 1400); can be shot down (10 HP each) |
| Seraph Lance | 25 dps × 1.2 s | 2500 | 0.8 s: slit mouth glows, beam line preview | 8.0 | Cyan beam sweep |
| Talon Kick | 25 | 250 | 0.4 s | 2.0 | Grounded only |
| Hover | — | — | Pipes fire | — | Hovers up to 800 above ground for ≤ 6 s, then lands for ≥ 3 s |

**Weak points:** Each wing-pipe cluster destroyed: −1 missile per volley, stagger 0.6 s; both destroyed: **grounded permanently**, no missiles, and it Falters once immediately.

**Answers:** Riveter Tack Scope / Lance on the wing-pipes; Hammerfall when grounded.

**Breakdowns:** `Front_RibcageRip` (tear the heart-bell out through the ribs), `Back_WingTear`, `Air_Grapple` (Harrow-reel onto a hovering Seraph and drag it down).

---

## 4. OPHAN — `ENM_Ophan`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M03 |
| **Role** | Flying heavy; teaches "grenade in the mouth" |
| **Size** | Ring diameter 300; capsule sphere r 150 |
| **HP** | 1300 · **Maw** (only when open): ×2; **Frag / Frag Slug / Hush into open maw → instant Falter** |
| **Speed** | Float 350 · Lunge 900 |
| **Skeleton** | `SKC_Ring` |

**Visual design:** "Wheels within wheels." Two interlocking porcelain rings (like a gyroscope), each ring covered in **dozens of eyes** (gold irises) that blink independently; at the center, a spherical **maw** — a closed porcelain bud that opens into a four-petal mouth with a glowing throat. The rings rotate slowly around each other. Gold filigree, a faint hum.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Drone Beam** | 30 dps for 2 s | 3000 | 1.0 s: rings stop spinning, **maw opens**, charge sound (the open-maw window) | 8.0 | Tracks the player at 25°/s |
| Eye Bolts | 4 × 10 | 2500 | 0.5 s: eyes flash cyan | 3.0 | Volley of orbs from the rings |
| Bite | 30 | 250 | 0.6 s maw snap | 3.0 | — |

**Answers:** When the maw opens for the Drone Beam, put a Frag Charge, Frag Slug or Hush Charge in it → it drops out of the air (Falter, lands on the ground). Hammerfall splash; Lock Salvo.

**Breakdowns (grounded only):** `Front_MawTear` (grab the petals, tear the maw inside out), `Ring_Snap` (break the rings apart).

---

## 5. CANON — `ENM_Canon`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M04 |
| **Role** | Slow artillery; area denial with "echo" explosions; destructible arms |
| **Size** | 400 cm; capsule r 170 / hh 200 |
| **HP** | 1800 · **Bell-mouths** ×2 (arm cannons), 250 HP each, ×2 damage |
| **Speed** | Walk 200 (stomps) |
| **Skeleton** | `SKC_Brute` (wide) |

**Visual design:** A bloated, massive, round-bellied giant of pale porcelain skin stretched over fat, with a tiny serene head on a thick neck. Each forearm ends in a huge **brass bell-mouth cannon** (like a flared horn/bell), fused to flesh with gold rivets. Its belly is covered with vertical organ pipes that vent steam. Walks in heavy, rhythmic steps.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Echo Shells** | Impact 40 (r 350), then **echo** 30 (r 450) 1.0 s later at the same spot | 500–4500 | 0.8 s: bell-mouth raises, **two bell tolls**; ground markers (red-orange rings) appear at impact points 0.6 s before impact and stay for the echo | 3.5 | 2 shells per volley per bell-mouth; alternates arms |
| Horn Blast | 35 + knockback 1000 | cone 60°, 600 | 0.7 s: both bells lowered, deep inhale | 5.0 | Used when the player is within 600 |
| Stomp | 20 r 300 | — | 0.5 s | 4.0 | — |

**Weak points:** A destroyed bell-mouth disables that arm's shells (it waves the stump angrily). Both destroyed → Horn Blast only, and it Falters once.

**Answers:** Riveter/Lance on the bell-mouths; get close and flank (slow turn rate 70°/s); Gravedigger/Shredder at close range; avoid standing in echo rings.

**Breakdowns:** `Front_BellStuff` (rip off a bell-mouth and jam it into its mouth), `Back_BellyBurst`.

---

## 6. ORGAN GRINDER — `ENM_OrganGrinder`

| | |
|---|---|
| **Faction** | The Instruments (converted construction machinery) |
| **First appears** | M05 |
| **Role** | Turret-bearing walker; destructible turret changes behavior |
| **Size** | 250 cm tall, 500 wide; capsule r 200 / hh 125 |
| **HP** | 1100 · **Pipe Turret** 300 HP, ×2 from the rear arc |
| **Speed** | Walk 350 · Skitter 550 |
| **Skeleton** | `SKC_Arachnid` (6 legs) |

**Visual design:** A six-legged construction mech (industrial yellow paint still visible under porcelain growth) fused with Choir flesh; its cab has grown a singing face in the windshield. On its back, a rotating **pipe-organ turret**: a cluster of brass pipes that fire notes. Hydraulic legs with porcelain joints. Leaks glowing cyan fluid.

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| **Staccato Volley** | 10/s × 5 dmg (2 s burst) | 3000 | 0.6 s: turret spins up, pipes glow cyan | 4.0 | Fast small bolts |
| Pipe Mortar | 3 × 30 (r 250) | 800–3000 | 0.8 s: pipes lift, three bass notes | 7.0 | Lobbed; ground markers |
| Leg Stab | 25 | 300 | 0.5 s | 2.0 | — |
| Skitter Charge | 30 | 1200 | 0.7 s | 8.0 | Only after the turret is destroyed |

**Weak points:** Turret destroyed → no ranged attacks; it switches to aggressive melee (Skitter Charge) and gains +30% speed.

**Answers:** Circle behind (the turret rotates at 90°/s); Riveter/Lance the turret; Power Chord directly on the turret breaks it.

**Breakdowns:** `Top_TurretRip` (Harrow onto its back, rip the turret off, stomp the face), `Front_CabPunch`.

---

## 7. CANTOR — `ENM_Cantor`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M02 |
| **Role** | Support/priority target: links and shields other enemies |
| **Size** | 280 cm; capsule r 45 / hh 140 |
| **HP** | 600 · **Lantern** (halo-lantern held aloft) 150 HP: destroying it breaks all links and makes it Falter instantly |
| **Speed** | Walk 250 · **Blink** 1000 (teleport) |
| **Skeleton** | `SKC_Humanoid` (tall, robed) |

**Visual design:** A tall, gaunt figure in long robes that are actually folds of pale skin inscribed with gold sheet music. It holds aloft a **lantern-halo**: a staff topped by a floating ring-cage containing a bright gold light. Its face is a smooth porcelain mask with a round singing mouth. It "conducts" with its free hand.

**Abilities**
| Ability | Effect | Range | Telegraph | Cooldown |
|---|---|---|---|---|
| **Harmony Link** | Gold beams from the lantern to up to **3** enemies (priority: T2 > T1); linked enemies take −75% damage | 2000 | 0.6 s: lantern brightens, a tenor chant begins | Sustained; re-links 2 s after a link breaks |
| **Harmony Wall** | Summons a translucent gold-cyan hex barrier (600 w × 400 h, 8 s, 600 HP) between the player and allies; **allied fire passes through** | 1500 | 0.8 s: raises the lantern, wall "draws" itself left to right | 12 |
| Blink | Teleports 1000 away when the player is within 500 | — | 0.2 s shimmer | 6 |
| Chant Orbs | 3 × 10 (cyan) | 2000 | 0.5 s | 3 |

**Answers:** Riveter headshot the lantern; Arc Beam instantly breaks links; Distort breaks links on enemies hit; Static Rifle shreds Harmony Walls (Energy ×3); Power Chord breaks walls instantly.

**Breakdowns:** `Front_LanternCrush`, `Back_StaffThrough`.

**Audio:** The link chant is a sustained tenor note — **as long as you hear it, something is linked.**

---

## 8. SIREN — `ENM_Siren`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M07 |
| **Role** | Agile serpentine melee assassin that **pulls** the player; teaches the Harrow as a counter |
| **Size** | 250 cm upright, 500 cm long; capsule r 60 (+ tail segment collisions) |
| **HP** | 800 · **Throat** (only during Siren Call): ×2 |
| **Speed** | Slither 600 · Coil Lunge 1400 |
| **Skeleton** | `SKC_Serpent` |

**Visual design:** An inhuman serpentine body of coiled, overlapping brass pipes and porcelain scales, rising into a gaunt, eyeless upper body with long arms and a head that is almost entirely **throat**: a vertical, glowing, ribbed column crowned with a four-petal mouth. From its jaw hangs a long **whip of braided vocal cords**. Moves like a sidewinder. (Not sexualized — strictly monstrous.)

**Attacks**
| Attack | Damage | Range | Telegraph | Cooldown | Notes |
|---|---|---|---|---|---|
| Vocal Whip | 25 | 450 | 0.5 s: whip coils back, crack sound | 2.0 | 2-hit combo |
| Coil Lunge | 30 | 1000 | 0.6 s: coils tighten, hiss | 5.0 | — |
| **Siren Call** | Pull | 2000 | 0.8 s: rises upright, throat lights up, a luring wordless melody | 12.0 | For 1.5 s, pulls the player toward it at 500 cm/s (dash/jump away still work); ends with a Whip if the player arrives |

**Counters:** Shoot the glowing throat during the Call (150 damage) → cancels and **Falters** it. Or **Harrow Reel-In** during the Call → "pull back": instant Falter. ("When a Siren pulls, pull back.")

**Breakdowns:** `Front_ThroatRip`, `Coil_Strangle` (strangle it with its own whip).

---

## 9. FUGUE — `ENM_Fugue`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M09 |
| **Role** | Teleporting ambusher that splits into illusions; teaches Distort/Arc Coil to reveal |
| **Size** | 220 cm; capsule r 40 / hh 110 |
| **HP** | 650 (illusions: 1 HP) |
| **Speed** | Run 600 · Teleport up to 2000 |
| **Skeleton** | `SKC_Chorister` (shared) |

**Visual design:** A darker, smoky Chorister-like figure whose outline smears as it moves (motion echoes trail behind it). Porcelain gone grey and translucent; a single thin halo that only the **real** one has. Illusions have no halo and **cast no shadow**.

**Abilities & Attacks**
| | Damage | Telegraph | Notes |
|---|---|---|---|
| **Split** | — | Shimmer + a canon of whispers (each voice entering after the other) | Creates 2 illusions (1 HP each, deal 50% damage) when first alerted and every 15 s |
| Teleport Ambush | — | A **reversed whisper** from the destination 0.5 s before arrival | Teleports behind/beside the player |
| Claw Combo | 3 × 15 | 0.4 s | — |
| Pounce | 25 | 0.6 s | — |

**Answers:** Distort (all illusions in the cone pop instantly), Arc Coil (chains hit and pop illusions), look for the halo/shadow; Hush freezes all copies.

**Breakdowns:** `Front_ShadowRip` (tear its smeared face apart), `Back_Snap`.

---

## 10. HYMNAL — `ENM_Hymnal`

| | |
|---|---|
| **Faction** | The Host |
| **First appears** | M08 |
| **Role** | Floating spawner of Wailers |
| **Size** | 250 wide (open), 150 tall; capsule sphere r 120 |
| **HP** | 900 · **Spine** (glowing binding on its back): ×2.5 |
| **Speed** | Float 250 |
| **Skeleton** | `SKC_Tome` |

**Visual design:** A floating **tome of flesh**: a massive book whose covers are thick porcelain plates and whose pages are sheets of pale skin, each page bearing a screaming face and gold staff-lines. It floats open, pages fluttering; Wailers are born from the faces tearing free of the pages. Its spine glows gold on its back.

**Attacks**
| Attack | Damage | Telegraph | Cooldown | Notes |
|---|---|---|---|---|
| **Page Birth** | Spawns 2 Wailers (max 6 alive) | 0.8 s: pages riffle, faces bulge | 4.0 | — |
| Page Storm | 20 (cone 45°, 1200) | 0.7 s: book snaps shut, then opens violently | 6.0 | Razor pages |
| Slam | 30 r 300 | 0.6 s (drops) | 8.0 | Only if the player is below it |

**On death:** all its Wailers burst harmlessly (no damage).

**Answers:** Hammerfall/Lock Salvo; Riveter the spine; Arc Coil to clean up Wailers.

**Breakdowns (after it Falters and falls):** `Front_BookSlam` (slam the covers shut on its own faces), `Spine_Rip`.

---

## 11. ECHO — `ENM_Echo`

| | |
|---|---|
| **Faction** | The Host (free-floating voice) |
| **First appears** | M09 |
| **Role** | Possessor that empowers other enemies; killable only with silence |
| **Size** | 180 cm (immaterial) |
| **HP** | — (immune to all damage except **Silence** and the Larynx Inhale) |
| **Speed** | Drift 400 |

**Visual design:** A translucent, rippling humanoid of cyan-white light, its outline repeating in fading copies behind it (a visual reverb tail). No face — just a glowing open mouth.

**Behavior:**
1. **Possess:** drifts to the strongest nearby T1/T2 enemy (not super-heavies) and merges with it → the host becomes **Echoed**: +50% HP, and every attack **repeats once 0.5 s later** (a ghostly copy of the attack).
2. On the host's death, the Echo is **freed** and drifts toward a new host for up to 6 s (it cannot attack).
3. **Destroyed** instantly by a Hush Charge field, the Silencer, or the Larynx Inhale. If it finds a new host, repeat.

**Answers:** Keep a Hush Charge ready for when the host dies. Rig upgrade *Quick Hush* is valuable in Echo-heavy missions (M09, M16, M19).

**Audio:** Reverb-drenched copy of its host's chord; freed Echoes emit a whispering, looping phrase that gets fainter.

---

## 12. Heavy Summary Table

| ID | HP | Weak point | Primary answer | Gold (parryable) attack | First |
|---|---|---|---|---|---|
| ENM_Crescendo | 1000 | Back bellows ×2.5 | Side-dash + back shots, Hush | — | M03 |
| ENM_Bellwether | 1500 | Ringing bell ×2 | Jump rings; Counter Gold Toll | Gold Toll | M06 |
| ENM_Seraph | 800 | Wing-pipes ×2 | Snipe pipes | — | M04 |
| ENM_Ophan | 1300 | Open maw ×2 | Frag/Slug/Hush in maw | — | M03 |
| ENM_Canon | 1800 | Bell-mouths ×2 | Snipe bells; flank | — | M04 |
| ENM_OrganGrinder | 1100 | Turret | Flank; snipe/Power Chord turret | — | M05 |
| ENM_Cantor | 600 | Lantern | Snipe lantern; Arc Beam | — | M02 |
| ENM_Siren | 800 | Throat (during Call) | Shoot throat / Harrow during Call | — | M07 |
| ENM_Fugue | 650 | — | Distort/Arc Coil to reveal | — | M09 |
| ENM_Hymnal | 900 | Spine ×2.5 | Rockets, snipe spine | — | M08 |
| ENM_Echo | — | — | Hush / Silencer / Larynx | — | M09 |
