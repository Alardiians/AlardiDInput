# 10 — Bosses & Mini-Bosses

## 0. Boss Framework (applies to every boss)

* **Class:** `BP_BossBase` (C++ `AHBBossBase`) driven by `DA_Boss_<Name>` (`UHBBossData`): list of **Phases**, each with an HP threshold, an **attack pool** (attack IDs + weights + cooldowns + min/max range), **arena events** (Level Sequence or actor-state changes), **add waves** (encounter wave IDs), a **music cue**, and a **Guard Break/Falter rule**.
* **Health bar:** top-center, boss name + title in the Choir's gold serif, bar segmented by phase thresholds.
* **Checkpoints:** at the start of the boss and at the start of every phase ≥ 2. On reload, player resources are restored to the "phase-start minimum" (Health 100%, Plating 75%, ammo 60%).
* **Resources in boss arenas:** every boss spawns **resource adds** (T1 fodder) on a timer (default every 25 s, 3–5 fodder) so the push-forward loop keeps working. This is mandatory — never make a boss fight a pure resource drain.
* **Telegraphs:** every boss attack has ≥ 0.6 s telegraph (≥ 1.0 s for attacks dealing > 50 damage), a unique audio cue, and uses the enemy color language (cyan = dodge, gold = parry).
* **Boss Breakdown:** the final blow of every Archon is a **Boss Breakdown** — a 4–8 s first-person synchronized execution (player invulnerable) triggered by a melee prompt when the boss's final phase HP reaches 0 and it Falters.
* **Difficulty:** boss HP ×(0.7 / 0.85 / 1.0 / 1.15 / 1.3 / 1.3) across Lullaby → Unsung; attack cooldowns ×(1.3 / 1.15 / 1.0 / 0.9 / 0.8 / 0.8).
* **Target lengths (Amplified, first attempt):** Archons 6–10 min; Octave 10–12 min; Unison 15–20 min; mini-bosses 3–5 min.

### Boss Roster

| # | Boss | Type | Mission | Arena |
|---|---|---|---|---|
| 1 | **Ionian, the Rapture** | Archon | M04 | Halcyon Bowl (stadium field) |
| 2 | **The Tenebrae** (Choirmaster Thale) | Mini-boss ×2 | M07, M09 | Seminary amphitheater; Array dish field |
| 3 | **Dorian, the Martial Psalm** | Archon | M08 | Iron Psalm parade ground |
| 4 | **Mixolydian, the Engine Hymn** | Archon (on foot + mech) | M11 | Assembly engine hall + yard |
| 5 | **The Antiphon** | Mini-boss | M12 | Helios reactor atrium |
| 6 | **Phrygian, the Burning Cantor** | Archon | M13 | Corona focal platform |
| 7 | **Maestro Primus** | Mini-boss ×2 | M14, M19 | Quietus Launch Bay; Chancel Tuning Font |
| 8 | **The Leviathan** | Mini-boss / chase | M16 | Europa tunnel junction |
| 9 | **Aeolian, the Grieving Tide** | Archon | M16 | Reef Cathedral dome |
| 10 | **Lydian, the Dreaming Choir** | Archon | M18 | Dream archipelago |
| 11 | **Locris, the Unresolved** | Archon | M22 | Unresolved Plaza |
| 12 | **Aurelia Voss, the Octave** | Herald | M24 | Cathedral summit |
| 13 | **The Unison** | Final | M27 | The Clef's heart |

---

## 1. IONIAN, THE RAPTURE (M04)

**Concept:** Joy as a weapon. A colossal figure of fused ecstatic bodies rising from the stage of a 120,000-seat stadium, fed by the rapturous crowd's song.

**Visual:** 12 m tall from the waist up; its lower body merges into the stage and the base of the Ionian Spire. A torso of dozens of fused, smiling, gilded bodies; **six arms** raised in rapture; the head is a giant **smiling porcelain mask** with blank gold eyes, framed by a **sun-halo** of radiating gold spikes. Palette: pale gold, ivory, warm white light. The stands are filled with swaying Tuned civilians (non-hostile props — `SM/SK_CrowdAgent` via instanced animation) singing along.

**Arena:** The **Halcyon Bowl field**: 100 × 60 m pitch. Central stage (20 × 20 m, 3 m high) where Ionian stands. Four **Choir Organs** (organ-pipe clusters 8 m tall) at the corners of the pitch channel the crowd's song. Cover: toppled stage trusses, scoreboard debris, 6 concrete barriers. Harrow Anchors on the stadium light towers. Kick Pads (Static-built) at pitch sidelines launch to the lower stands ring (a walkable concourse lip 6 m up).

| Phase | HP | Behavior | Adds |
|---|---|---|---|
| **1 — Communion** | 100–66% | Ionian is shielded (**Rapture Shield**, gold bubble) while any **Choir Organ** stands. Each Organ: 800 HP, weak to Explosive. Destroying all 4 drops the shield for the rest of the fight. | Thralls (Fan skins) pour from the stands every 25 s; 2 Choristers |
| **2 — Radiance** | 66–33% | The mask cracks. New attack **Radiance**. More aggressive hand slams. | Choristers, 2 Seraphs, 1 Canon (at 50%) |
| **3 — Ascension** | 33–0% | Ionian tears free of the stage and floats (8 m up); its **six hands detach** and fly independently; its **sun-heart** in the chest is exposed | Thralls; resource adds; 1 Crescendo at 20% |

**Attacks**
| Attack | Phase | Damage | Telegraph | Notes |
|---|---|---|---|---|
| Euphoria Beams | 1–3 | 35 dps | 1.0 s: mask's eyes glow white, beam-line previews | Two beams sweep the pitch in a V |
| **Rapture Rain** | 1–3 | 12 per note | 0.8 s: arms fling upward, gold chime | Arcs of **gold notes** — parryable; parried notes damage Ionian ×3 |
| Joy Wave | 1–3 | 30 | 0.8 s: stage flares | Ring shockwave from the stage (jump) |
| Hand Slam | 1–2 | 50 | 1.0 s: a hand rises, red-orange ground marker | Slammed hand stays 2 s: **Power Chord on the hand = stagger (Ionian Falters for 2 s)** |
| **Radiance** | 2 | 60 if exposed | 2.0 s: the crowd's song swells to a scream, the sun-halo blazes, screen whitens at edges | Hide behind cover (line-of-sight check from the mask). Every 18 s. |
| Hands of Rapture | 3 | 30 per hit | Each hand glows before swiping/grabbing | 6 flying hands (600 HP each) attack independently; destroyed hands don't return |
| Sun-Heart Flare | 3 | 40 (r 600) | 1.0 s | Burst when the player is below it |

**Weak points:** Choir Organs (P1), slammed hands (P1–2), **sun-heart** ×2 (P3).
**Boss Breakdown:** The Unsung Harrows onto the mask, climbs its face, punches through the mask's smile and rips out the sun-heart; Ionian's scream turns to silence. The crowd collapses. (`AM_BRK_Ionian_Finale`, 6 s)
**Music:** "Rapture" — a major-key choral hymn fighting a down-tuned riff; the choir gets progressively overpowered by the guitars across phases.

---

## 2. THE TENEBRAE (M07, M09) — Mini-boss

**Concept:** The Consonance's war-machine, piloted by Choirmaster **Idris Thale**.

**Visual:** An 8 m hovering armored sled-mech in white enamel and gold trim, shaped like a cathedral reliquary with a cockpit dome (Thale visible inside, half-gilded). Twin **Hymn Cannons** under the wings, missile pods on the flanks, four chanting **Acolyte cantors** kneel on platforms around it projecting its shield.

| Encounter | HP | Notes |
|---|---|---|
| **M07** (amphitheater) | 6000 — retreats at 50% | Tutorial of the mechanic; the chanters are on the amphitheater terraces |
| **M09** (dish field) | 7000 — full fight | Thale dies; cockpit Breakdown |

**Mechanics:**
* **Choir Shield:** a gold dome (absorbs all damage) sustained by **4 chanter Acolytes** on platforms (each 150 HP; Harmony-linked to the shield). Kill all 4 → shield down for 20 s → chanters respawn (Hymnfall) unless the Tenebrae has taken ≥ 30% of its HP during the window (then 2 respawn).
* **Engine nacelles** (2 × 800 HP, ×2): destroying one makes it list and drop 3 m (easier to reach); both → grounded (Falter).

| Attack | Damage | Telegraph |
|---|---|---|
| Hymn Cannons | 2 × 25 bolts, bursts of 6 | 0.7 s: cannons spin up |
| Censer Missiles | 6 × 20 homing | 0.8 s: pod doors open, a toll |
| Sanctify (strafing run) | 40 line | 1.2 s: ground line of gold glyphs where it'll strafe |
| Gold Chime Mines | 25 (r 300) | Drops 5 chimes (Counter-able back at it: 150 dmg each) |

**Boss Breakdown (M09):** The Unsung leaps onto the grounded Tenebrae, tears the cockpit dome open and pulls Thale out. Cut to black on the impact.

---

## 3. DORIAN, THE MARTIAL PSALM (M08)

**Concept:** Discipline and war. A duel of parries with the Archon who sealed the Unsung four billion years ago.

**Visual:** A 6 m armored knight-Archon. Black-and-bone armor inlaid with gold, a helm shaped like a stern bell with a crown-halo, a cape of ragged war-banners bearing the Consonance Seal and the insignia of tuned human armies. Wields the **Psalm Blade** (a 5 m greatsword whose blade is a two-tined tuning fork that splits into two swords in phase 3) and the **Aegis of Choirs** (a tower shield of porcelain faces).

**Arena:** The **Parade Ground**: a circular plaza 70 m across of bone-paved flagstones, raised dais in the center (15 m wide, 1.5 m high), ringed by bone ramparts 8 m high with walkways (reachable via 4 Kick Pads and Grip Walls). Ranks of motionless Tuned soldiers line the ramparts (props, then some come to life as adds).

| Phase | HP | Behavior | Adds |
|---|---|---|---|
| **1 — The Duel** | 100–60% | Pure duel. Dorian fights with sword + shield (Requiem Knight moveset scaled up). | Resource adds only (Thralls, every 25 s) |
| **2 — The Phalanx** | 60–30% | Dorian plants the sword on the dais and conducts. A **drum-march** begins: **Martial Hymn** shockwaves ripple from the dais **on every 2nd beat of the music**. A phalanx of Bulwarks + Troopers marches in lockstep. 2 Requiem Knights. Dorian re-engages when both knights die. | Phalanx, 2 Requiem Knights |
| **3 — Twin Psalms** | 30–0% | Shield discarded, blade splits into **two swords**; much faster; **Parry Chains** | Resource adds |

**Attacks**
| Attack | Phase | Damage | Telegraph | Notes |
|---|---|---|---|---|
| Psalm Combo | 1, 3 | 3 × 30 (last gold) | 0.5 s per swing; last = gold + chime | Counter the gold strike → **Guard Break 2.5 s** |
| Aegis Charge | 1 | 40 + knockback | 1.0 s: shield lowered, war-horn | Dash sideways |
| Psalm Wave | 1–3 | 35 | 0.8 s: overhead raise | Vertical cyan wave — dodge sideways |
| **Martial Hymn** | 2 | 25 | Beat-synced: rings leave the dais on beats 2 and 4 (visible gold pulse on beats 1 and 3) | Jump on the beat. The player can literally play in rhythm. |
| **Parry Chain** | 3 | 5 × 25 | All 5 strikes gold, rhythmic (0.45 s apart) | Parry all 5 → **Guard Break 4 s** + Dorian Falters |
| Judgement | 3 | 60 **Piercing** | 1.5 s: both swords raised, sky-beam | Leaps and crashes down (r 500) |

**Boss Breakdown:** The Unsung catches both swords, snaps the tuning-fork blade in half, and drives the halves through the bell-helm; Dorian's final toll rings and fades. Before dying, Dorian whispers (harmonized): "*...Shieldwarden. You are still... so loud.*"
**Music:** "The Martial Psalm" — a march in 4/4 at 120 BPM (the Martial Hymn syncs to this), male choir chanting vs. blast beats in phase 3.

---

## 4. MIXOLYDIAN, THE ENGINE HYMN (M11)

**Concept:** Industry, labor, the rhythm of machines. The only Archon fought both on foot and in the **Anvil Siege Frame**.

### Phase A (on foot) — "The Governor" — Engine Hall
**Visual:** The Archon — a porcelain torso with four arms, head replaced by a spinning brass governor (flyball regulator) — is fused into a **conductor's cradle** at the center of a colossal engine: crankshafts, flywheels, pistons, pipe-organ banks, conveyor belts. A rotating **cage** of iron bars spins around the cradle.

**Arena:** Circular engine hall 60 m across with a **turntable floor** (4 ring sections rotating at different speeds and directions), conveyor lanes, piston rows, and molten-steel channels between rings (void rules).

| Sub-phase | Mechanic |
|---|---|
| A1 | The cage protects the Archon. **3 Governor flywheels** (1000 HP each, high on the walls; Lance/Riveter) must be destroyed to jam the cage. While the cage is jammed (15 s), the torso is exposed. |
| A2 (at 50% of phase A HP) | Pistons slam in sequence (rhythmic hazard lanes); **Assembly Line** spawns Organ Grinders on conveyors; the cage restarts faster (flywheels respawn at 60% HP). |
| A-end | At 0%, the Archon tears free and rises through the opening roof. |

| Attack | Damage | Telegraph |
|---|---|---|
| Rivet Storm (gantry turrets) | 8 per rivet | 0.6 s: turret spin-up (turrets destroyable, 400 HP) |
| Piston Slam | 60 | 1.0 s: piston glows, steam hiss (lane markers) |
| Steam Vent | 15 dps | 0.8 s: rumble + whistle |
| Arm Swipe (4 arms) | 35 | 0.7 s |

### Phase B (Anvil Siege Frame) — "The Engine Hymn" — Assembly Yard
**Visual:** The Archon assembles a **40 m colossus** out of factory parts: furnace chest, crane arms, a conveyor-belt spine, smokestack horns, the governor-head glowing gold.

| Attack | Damage (vs. Anvil) | Telegraph |
|---|---|---|
| Crane Swipe | 600 | 1.2 s: crane arm swings back |
| **Furnace Breath** | 300 dps | 1.5 s: furnace doors open (weak point ×3 while open) |
| Scrap Throw | 400 (r 800) | 1.0 s |
| Walker Birth | Spawns 2 Organ Walkers | Smokestacks bellow |

**Weak points:** Furnace door (during Breath), crane joints (2 × 3000). HP (vs. Anvil): 40000.
**Boss Breakdown:** The Anvil's Pile Driver punches through the furnace; the Anvil's arm is torn off in the explosion (Wren: "MY *BABY*—").
**Music:** "Engine Hymn" — industrial metal with a machine-rhythm (anvils, pistons) in 7/8; the choir sings in mechanical, clipped syllables.

---

## 5. THE ANTIPHON (M12) — Mini-boss

**Concept:** Call and response. Two giant Cantors (6 m) that sing to each other.

**Visual:** Mirror-image robed giants with lantern-halos; one gold (**Call**), one silver (**Response**).
**Mechanic:** They alternate: one **sings** (invulnerable, glowing, attacking) while the other **listens** (vulnerable, weaker attacks). They switch every 6 s. If one dies, the other **resurrects** it after 10 s by singing — kill both within 10 s of each other. HP 3000 each.
**Attacks:** Call: Harmony Beam (40 dps), Chant Orbs (5 × 12). Response: repeats the Call's last attack from its own position 1 s later (**echo**). Both: Harmony Walls to block the player.
**Arena:** The Helios reactor atrium: a circular hall with a central reactor column, two opposing balconies (each Cantor on one), Harrow Anchors between balconies.

---

## 6. PHRYGIAN, THE BURNING CANTOR (M13)

**Concept:** Fury and pride — the Archon who loves the Unsung's rage.

**Visual:** A 7 m Archon of cracked porcelain with **white-hot solar fire** blazing through every crack, robes of flowing plasma, wings of burning organ pipes (6), a face like a screaming, beautiful mask with fire for eyes, a halo of solar flares.

**Arena:** The **Corona focal platform** atop the array's central tower: circular, 60 m across, with 8 pylons, ringed by **heliostat mirror panels** (12 large panels on motorized arms around the rim). The Sun fills a third of the sky. Shade is cast by the pylons and by the mirror panels' backs.

| Phase | HP | Behavior |
|---|---|---|
| **1 — Pride** | 100–60% | Airborne; ranged fire; flies circuits around the platform |
| **2 — Heliostat** | 60–30% | Phrygian seizes the mirrors: **Focus Beams** sweep the platform (solar exposure zones). **Player counterplay:** shoot a mirror's **motor** (12 motors, 300 HP, glowing) to swing it and **reflect a Focus Beam onto Phrygian** (2000 dmg + stagger). 2 Profundos join. |
| **3 — Fury** | 30–0% | Lands; melee frenzy mirroring the Unsung (dashes, slams, a harpoon of fire); enters **"Fury Overdrive"** twice (10 s each: +50% speed; all melee strikes gold → parry chains) |

**Attacks**
| Attack | Damage | Telegraph |
|---|---|---|
| Flare Bolts | 3 × 15 (every 3rd volley gold) | 0.6 s: hand flare |
| Solar Lance (dive) | 50 (r 400) | 1.2 s: hovers, line-marker to landing spot |
| Pyre Rings | 25 | 0.8 s: expanding fire ring (jump) |
| Focus Beam | 80 dps in the beam | 1.5 s: mirrors swivel, a bright line forms |
| Fury Combo | 4 × 25 (gold) | 0.4 s each |
| Burning Harrow | Pulls player 600 cm + 20 | 0.7 s: fire-chain drawn back |

**Dialogue (during the fight, harmonized, fiery):** "*Yes! YES! Louder!*" / "*Four billion years of rage and you spend it on these fragile little animals?*" / "*Sing it WITH us!*"
**Boss Breakdown:** The Unsung plunges both hands into Phrygian's burning chest and tears its heart out; the fire goes out of its eyes; the Sun's hum stops.
**Music:** "The Burning Cantor" — Phrygian-mode metal (flamenco-inflected, fast, fiery), the most aggressive track in Act III.

---

## 7. MAESTRO PRIMUS (M14) — Mini-boss

**Concept:** The Maestro conducting the boarding of the Quietus. An enhanced Maestro (`ENM_Maestro` moveset) with **6000 HP**, a larger Score (800 HP), and a boarding-party summon (**Boarding Hymnfall**: 5 T1 + 1 T2 every 20 s).
**Arena:** The Quietus **Launch Bay** (the hub's Drop Coffin bay, familiar to the player), with cargo containers as cover, a crane gantry, and the hub's Armory windows above.
**Scripted end:** at 25% HP it teleports away (cannot be killed here). Resolved in `CIN_M14_Abduction`. (It returns in M19 as the Chancel's warden: final fight in the Tuning Font — 7000 HP, dies.)

---

## 8. THE LEVIATHAN (M15 foreshadow, M16 fight)

**Concept:** A Choir-whale the size of a building, the Aeolian's herald.
**Visual:** 60 m long; porcelain-plated whale body with rows of singing mouths along its flanks, fins of translucent pipes, a head crowned with a halo and three enormous gold eyes.
**M16 set piece:** In the **Tunnel Junction** (a hub of four pressure-tube corridors), the Leviathan smashes through the tubes; the player fights on a central platform as water floods in from breaches (rising water on a timer = pressure). The Leviathan's **head** rams through breaches in sequence; shoot its **3 eyes** (1500 HP each) while it's lodged (8 s windows). After the third eye, it retreats, dragging a tube section away — revealing the path to the Reef Cathedral.

---

## 9. AEOLIAN, THE GRIEVING TIDE (M16)

**Concept:** Sorrow. A mourning leviathan-Archon that wants to make every ending gentle.

**Visual:** A 20 m whale-like Archon whose head carries a **weeping humanoid torso** grown from it (arms covering its face); long flowing fins of translucent organ pipes; glowing tears constantly fall from the torso's eyes; its body is covered in blowhole-mouths that sing a whale-song choir.

**Arena:** The **Reef Cathedral**: an air-filled dome (80 m diameter, 40 m high) on the ocean floor, with a central pool (30 m) open to the sea. Three water levels:
* **Low:** floor walkable (tiered reef-rock platforms).
* **Mid:** floor flooded; only raised platforms (8 islands) and a middle ring walkway remain; flooded areas = void rules.
* **High:** only the top ring walkway (8 m wide) and 4 balcony platforms.

| Phase | HP | Water | Behavior |
|---|---|---|---|
| **1 — Lament** | 100–65% | Low | Aeolian surfaces in the pool; attacks from the pool. Weak points: **4 weeping eyes** (1000 HP each) on the torso's face (when its hands lower) |
| **2 — The Deep Ride** | 65–30% | Mid | Aeolian circles the dome underwater, surfacing to attack. **Harrow Anchors on its dorsal fin** (visible gold rings) — grapple on and **ride its back**: fight on a moving arena while shooting its **blowhole-mouths** (6 × 800 HP). It dives after 20 s (auto-dismount to the nearest platform) |
| **3 — The Ending** | 30–0% | High | The torso rises fully out of the water (15 m tall), arms open; desperate barrage; resource adds on the ring |

**Attacks:** Tide Surge (floor waves, jump; P1), Lament (sonic cone 40), Tears (each tear drop spawns a Wailer; 6 per volley), Undertow (pulls the player toward the pool — dash away), Breach (leaps out of the pool across the arena, 80 dmg under its landing shadow), Grief Nova (P3: dome-wide pulse every 20 s — hide behind the balcony walls).
**Dialogue:** "*Every song ends, little one. I only wanted the ending to be gentle.*" / "*Why must you make it hurt?*"
**Boss Breakdown:** The Unsung pries the torso's hands from its face — it has no face, only a smooth porcelain surface running with tears — and punches through it.

---

## 10. LYDIAN, THE DREAMING CHOIR (M18)

**Concept:** Wonder and illusion. A fight in a collapsing dream.

**Visual:** A graceful 5 m figure of translucent lilac porcelain whose head is a **spinning mobile of floating masks** (each mask a face Lydian has "dreamed"). Long ribbon-like limbs trailing stardust. Its body flickers between solid and transparent.

**Arena:** The **Dream Archipelago**: 7 floating islands (15–25 m across) of fragments of Cytherea and remembered places (a Halcyon street corner, a Quietus corridor made of clouds, a bell-tower roof) in a lilac-gold cloudscape, connected by Kick Pads, Harrow Anchors and Swing Poles.

| Phase | HP | Behavior |
|---|---|---|
| **1 — Reverie** | 100–65% | 4 copies of Lydian; the real one's **shadow points up** (dream logic; Pedal *Tuner* also marks it). Illusions pop on hit. |
| **2 — Inversion** | 65–30% | Gravity flips (the undersides of islands become floors). Lydian summons **"Memories"**: illusory re-enactments of previous bosses' signature attacks (Ionian's Hand Slam, Dorian's Psalm Wave, Phrygian's Solar Lance, Aeolian's Tears) — real damage, translucent visuals |
| **3 — Waking** | 30–0% | The dream collapses: islands fall one by one; Lydian's **true form** (a small, fragile 2 m being of light) flees across falling islands — a pursuit fight; it shields itself with illusions |

**Signature mechanic — Lullaby:** a lilac aura around Lydian. If the player **stands still** for > 1 s inside it, their vision blurs, the music slows, and they are **Slowed** (−40%) until they dash. Keep moving.
**Attacks:** Dream Orbs (slow homing, 20), Mask Rain (masks fall and shatter, 25), Recurring Motif (a repeated pattern of 3 gold rings — parry for big damage), Memory attacks (P2).
**Boss Breakdown:** The Unsung catches the tiny fleeing true form in one hand; it looks up at them; they close their fist. The dream bursts like a soap bubble.

---

## 11. LOCRIS, THE UNRESOLVED (M22)

**Concept:** Doubt, instability, a brother/sister-in-arms. The fight never "resolves" — the arena keeps changing.

**Visual:** 4 m cracked Oreth Shieldwarden; black fissures across the porcelain, flickering gold seams, a broken shield grown into the left arm, a long **chain-spear** (the Oreth equivalent of the Harrow), an incomplete halo (a ring with a gap).

**Arena:** The **Unresolved Plaza** in Aubade that shifts between three configurations, rotating like a set changing on a stage (a 3 s transition, telegraphed by a chord change and grinding stone):
* **Config A — Open Plaza** (50 × 50 m, fountains, statues)
* **Config B — Pillar Maze** (tight columns, ideal for Locris's ambushes)
* **Config C — Stair Tower** (a vertical spiral of platforms around a central void)

Transitions happen every 45 s and at each phase change.

| Phase | HP | Behavior |
|---|---|---|
| **1 — Shieldwarden** | 100–60% | Locris fights like the Unsung: dashes, chain-spear grapples (pulls itself or the player), slams, shield blocks |
| **2 — Unresolved Strikes** | 60–25% | Every combo includes **illusory strikes** — visually identical, but **silent**. Real strikes make sound (a bell tone). **Parry only the ringing strikes.** (Accessibility: an option adds a visual marker to real strikes.) |
| **3 — Two Voices** | 25–0% | Locris alternates between the Choir voice (aggressive, gold everything) and its own lonely voice (hesitates, lowers its guard for 3 s — the damage window). Ends in `CIN_M22_Halo` — Locris is **not killed**. |

**Dialogue (fragments during the fight):** "*You didn't even look back.*" / "*I held your shield for three hundred years.*" / "*Every night in the Choir I hear one voice missing. Yours.*"

---

## 12. AURELIA VOSS, THE OCTAVE (M24)

**Concept:** The Herald completes the scale. A human who became a goddess of grief.

**Visual:** A 15 m transfigured form of porcelain and light with **Aurelia's face** (serene, eyes human and green), **eight arms**, a halo of **eight rings**, and a lower body that cascades into a gown of thousands of fused choir-bodies flowing down to the floor. Her gilding pulses with the Aureole overhead.

**Arena:** The **Cathedral summit**: a circular hall 90 m across, open to the sky where the last white band of the Aureole burns, floor inlaid as a giant **musical staff** (five glowing lines), eight **memory platforms** (raised shrines to her life: her lab, her daughter's room in gold, the Listening Array console, her wedding, etc. — also cover).

| Phase | HP | Behavior |
|---|---|---|
| **1 — The Scale** | 100–65% | Aurelia sings **eight notes in ascending order** (a scale); each note is a distinct attack, always in the same order (learnable): 1 Ground wave · 2 Beam sweep · 3 Gold-ring rain (parry) · 4 Summon Acolytes · 5 Homing notes · 6 Pull · 7 Shield (her arms close — damage her arms) · 8 **Octave Nova** (arena-wide burst — hide behind memory platforms). Then a **rest** (3 s): she draws breath — **all damage ×2 during rests** |
| **2 — The Congregation** | 65–35% | She kneels; the Congregation (Acolytes, Zealots, 2 Cantors, 1 Maestro) links to her with gold Harmony Links: **she heals 2% per second per link**. Break links (Arc Beam, Distort, kill Cantors/Maestro) |
| **3 — The Octave** | 35–0% | She rises and becomes pure sound: the floor's staff lines become **moving platforms** (the staff lines slide and tilt); notes (platforms) slide along them. She sings continuously — the only damage windows are the **rests** between phrases (announced by the choir cutting out — "strike in the rests"). |

**Boss Breakdown:** On the final Falter, the Unsung drives **the Axe** into her heart; the colossal form fractures → `CIN_M24_Death`.
**Music:** "The Octave" — a full orchestral-choral requiem vs. the band; phase 3 is structured with literal rests (the whole mix drops to the Unsung's heartbeat for 2 s) — the gameplay damage windows are **the silences**.

---

## 13. THE UNISON (M27)

**Concept:** God as a choir of trillions. The end of the war.

### Phase 1 — THE VOICE
**Visual:** A 100 m sphere of fused, gilded bodies of every species the Choir ever took, slowly rotating, radiating light, surrounded by concentric halos kilometers wide.
**Arena:** **Orbit Rings** — 3 concentric ring-platforms (widths 12 m) orbiting the sphere at different speeds and tilts, connected by Kick Pads and Harrow Anchors; the Unsung moves between rings.
**Mechanic:** 8 **Voice Nodes** (mouth clusters, 2500 HP each) across the sphere's surface open and sing; destroy all 8 to crack the sphere. Waves of every enemy type spawn on the rings via Hymnfall (resource adds).
**Attacks:** Choir Wave (ring-wide shockwave, jump), Staves of Light (5 parallel beams sweeping — dodge through gaps), Hymnfall Barrage (pillars of light striking marked spots), Voice Beam (from open Nodes).

### Phase 2 — THE FIRST FACE
**Visual:** Inside the cracked sphere: a colossal **Oreth face** (30 m) and two hands, made of millions of smaller faces, gently sad.
**Arena:** A vast inner chamber; the floor is the hand of the First Face (it moves, tilts, closes).
**Mechanic:** The Unison speaks throughout. The hands attack (Grasp, Palm Slam); the face breathes out **Hymn Saturation**; **statues of the Oreth** rise from the floor and sing (Hymn Pylon behavior — destroy with Power Chord/Axe). Weak point: the face's eyes (2 × 6000) during "Weeping" windows.

### Phase 3 — THE LAST BROADCAST
**Trigger:** `CIN_M27_Broadcast` (in-play). Harlan's countdown; the Last Broadcast floods in as audio: thousands of human voices, instruments, noise.
**Player state:** **Last Overdrive** — permanent Overdrive for the whole phase (all Overdrive effects, infinite duration, Gain meter replaced with a "BROADCAST" meter showing humanity's signal strength).
**Mechanic:** The Unison **fractures into 4 Dissenting Choirs** (each a 10 m faction-form singing a different note, fighting each other *and* the player); the **Core** (heart-light) flickers between them — whichever faction holds the Core glows gold; damage that faction to knock the Core loose. After 4 Core knocks, the Core falls to the floor, exposed.
**Finale:** Melee prompt → the Axe into the Core → `CIN_M27_Finale`.

**Unison dialogue (examples, all in the billion-voice chorus):**
* P1: "*Little Wrong Note. Aren't you tired?*"
* P2: "*Every voice you have silenced is here with us, and none of them are in pain. Can you say the same of the ones you saved?*" / "*We remember your name. Would you like to hear it?*" (it never says it)
* P3: "*What— what is this? So many. They are all— different—*" / "*STOP— STOP SINGING— SO MANY—*"

**Music:** "The Final Chord" → "Last Broadcast" (P3): the main theme played by the full band **plus** a recorded crowd of hundreds of human voices singing, shouting, off-key and gloriously messy (see audio doc: record real crowds or layer many individual AI-generated voices — each different).

---

## 14. THE ANVIL SIEGE FRAME (Player Mech) — full spec

| Property | Value |
|---|---|
| Height | 9 m; camera in a cockpit at 7.5 m (canopy frame visible, taped-on Static decals, a dangling pine-tree air freshener Wren added) |
| Speed | Walk 1100 cm/s, dash 2 charges (1500 cm, 2.5 s recharge), jump-jets (short hop, 600 cm high) |
| Structure | 5000 HP; no Plating; repairs via **Pile Driver** executions (+1000) and repair crates dropped by Static dropships (+1500) |
| Right arm | **Rotary Autocannon** (sustained, 60 dmg/round, 15 rounds/s, overheats after 6 s) |
| Shoulders | **Rocket Pods** (lock-on up to 8 targets, 400 dmg each, 8 s cooldown) |
| Left arm | **Blast Horn** — a massive speaker-cannon firing a cone of noise (3000 dmg, 60° × 4000 cm, knocks back swarms, ×3 vs. Vesper Clouds, staggers titans), 12 s cooldown |
| Melee | **Pile Driver** punch (2000 dmg); on a staggered titan → **Titan Breakdown** (execution, +1000 structure) |
| Input context | `IMC_Mech` (fire = autocannon, mod fire = rocket lock, Distort key = Blast Horn, melee = Pile Driver, Surge = dash, jump = jets) |
| Segments | M11 (~12 min), M23 (~15 min), M26 (~12 min) |
