# 06 — The Arsenal (Weapons)

## 0. Overview

| Slot | ID | Name | Class | Ammo | Acquired | Role |
|---|---|---|---|---|---|---|
| 1 | `WPN_Breacher` | **Breacher** | Pump combat shotgun | Shells | M01 | Close-range all-rounder; Ophan answer |
| 2 | `WPN_Riveter` | **Riveter** | Heavy semi-auto rivet rifle | Rounds | M01 | Mid-range precision; weak-point sniping |
| 3 | `WPN_StaticRifle` | **Static Rifle** | Rapid-fire energy rifle | Charge | M02 | Shield/Harmony breaker; sustained DPS |
| 4 | `WPN_Gravedigger` | **Gravedigger** | Double-barrel super shotgun | Shells | M03 | Close burst king |
| 5 | `WPN_Hammerfall` | **Hammerfall** | Rocket launcher | Ordnance | M04 | AoE, crowds, flyers |
| 6 | `WPN_Shredder` | **Shredder** | Rotary cannon | Rounds | M05 | Sustained high DPS vs. heavies |
| 7 | `WPN_ArcCoil` | **Arc Coil** | Chain-lightning projector | Charge | M06 | Swarm control (Vespers, Wailers, Thralls) |
| 8 | `WPN_Lance` | **Lance** | Rail-lance | Charge | M10 | Long-range pierce; super-heavy damage |
| 9 | `WPN_Ripsaw` | **Ripsaw** | Saw-blade launcher | Ordnance | M12 | Ricochets in tight spaces; dismemberment; DoT |
| S1 | `WPN_Silencer` | **The Silencer** | Anechoic super-weapon | Null Cells | M09 | Screen-clear panic button |
| S2 | `WPN_Axe` | **The Axe** | Relic melee super-weapon | Grudges | M21 | One-hit kills on anything but bosses |
| S3 | `WPN_Larynx` | **The Larynx** | Captured Choir organ-weapon | Voice | Optional (7 Requiem Gates) | Steals enemy projectiles and fires them back |

### Ammo Pools (base → max upgraded)
| Ammo | Weapons | Base max | Upgraded max (Heart Shards — Arsenal track) |
|---|---|---|---|
| **Shells** | Breacher, Gravedigger | 24 | 48 |
| **Rounds** | Riveter, Shredder | 180 | 300 |
| **Charge** | Static Rifle, Arc Coil, Lance | 200 | 350 |
| **Ordnance** | Hammerfall, Ripsaw | 12 | 24 |
| **Null Cells** | Silencer | 3 | 3 |
| **Grudges** | Axe | 3 | 3 |
| **Voice** | Larynx | 100 | 100 |

### Weapon Design Rules
1. **Magazines are mostly absent.** Like modern DOOM, weapons draw straight from the ammo pool (no reload), except the Gravedigger (reload after every shot — its rhythm) and the Hammerfall (4-rocket drum, fast reload). This keeps the pace up.
2. **Every weapon has exactly 2 mods** (except Gravedigger: an upgrade path; super weapons: none). Mods are swapped with `IA_SwapMod` (0.3 s). Mod fire is `IA_ModFire`.
3. **Every mod has 3 upgrades (Brass) + 1 Mastery** (challenge-unlocked).
4. **Silhouettes must be readable in 0.2 s.** Every weapon has a unique silhouette, unique sound, unique muzzle flash color accent (all ember/orange family except the Static Rifle, Arc Coil and Lance, which have *white-hot orange* energy — never cyan, which is reserved for enemies).
5. **Human weapons look human** (Concord/Static: stenciled steel, tape, stickers, band decals). Relic/Choir-derived weapons look alien (Axe: Oreth; Larynx: Choir flesh-and-brass in a Static frame).

---

## 1. BREACHER — Pump Combat Shotgun

*"CDF M-40 'Breacher', 10-gauge. Door-kicker, room-clearer. The Static's most common weapon." — Archive*

**Visual:** Chunky pump shotgun, tan-and-black polymer with a steel receiver, tube magazine, heat-shield with Static waveform stickers, a strip of duct tape on the pump labeled "KEEP IT LOUD". Viewmodel held low-right.

| Stat | Value |
|---|---|
| Damage | 10 pellets × 14 = **140** (Kinetic) |
| Spread | 7° cone |
| Falloff | Full to 800 cm, 50% at 1600 cm, 20% at 2500 cm |
| Fire rate | 1 shot / 0.85 s (pump cycle) |
| Ammo per shot | 1 Shell |
| Headshot | ×1.25 per pellet |
| Stagger | Point-blank (≤ 250 cm) all 10 pellets on a T1 → knockback |

### Mod A — Frag Slug (`MOD_Breacher_FragSlug`)
Fires a sticky explosive slug. Hold Mod Fire to arm (0.35 s), release to fire.
* Slug: 120 impact + 180 Explosive splash (radius 350) after 0.6 s fuse (on sticking) or on impact with a flyer.
* **Ophan weakness:** a Frag Slug into an Ophan's open maw causes instant **Falter**.
* Cooldown: 2.0 s between slugs; costs 2 Shells.
| Upgrade | Cost (Brass) | Effect |
|---|---|---|
| Quick Arm | 2 | Arm time 0.35 → 0.2 s |
| Double Slug | 5 | Fires 2 slugs in quick succession (costs 3 Shells) |
| Shrapnel Bloom | 8 | Explosion releases 8 fragments (40 dmg each, 600 cm) |
| **Mastery: Cluster Slug** | Challenge: *Stagger 25 Ophans with a Frag Slug in the maw* | Slug detonation spawns 3 mini-slugs that seek nearby enemies |

### Mod B — Drum Fire (`MOD_Breacher_DrumFire`)
Hold Mod Fire to spin up a mechanical drum (0.4 s), then the Breacher fires full-auto at 5 shots/s. Uses 1 Shell per shot. Pellet spread +20%.
| Upgrade | Cost | Effect |
|---|---|---|
| Fast Spin | 2 | Spin-up 0.4 → 0.2 s |
| Heavy Drum | 5 | +2 shots per second |
| Cool Barrel | 8 | Every 4th shot costs no ammo |
| **Mastery: Stampede** | *Kill 150 enemies while Drum Fire is active* | Movement speed +15% while firing Drum Fire; each kill during Drum Fire refunds 1 Shell |

---

## 2. RIVETER — Heavy Rivet Rifle

*"Concord Heavy Industries RVT-9. Designed to fire hot structural rivets into orbital hull plates. The Static found other uses." — Archive*

**Visual:** An industrial tool turned rifle: yellow-and-black hazard striping, a big rivet hopper on top glowing orange-hot, a folding stock, a heat-coil barrel. Fires glowing hot rivets (visible tracer).

| Stat | Value |
|---|---|
| Damage | **48** per rivet (Kinetic) |
| Fire rate | 5 shots/s (semi-auto held = auto) |
| Projectile | Near-hitscan tracer (speed 30000 cm/s) |
| Spread | 0.8° hip, ramping to 2.5° after 1 s continuous fire |
| Headshot | ×1.5 |
| Ammo | 1 Round per shot |

### Mod A — Tack Scope (`MOD_Riveter_TackScope`)
Hold Mod Fire to aim down a 3× scope (zoom 0.18 s). Scoped shots: 90 dmg, headshots and weak points **×2.5**, 0 spread, 2 shots/s.
| Upgrade | Cost | Effect |
|---|---|---|
| Light Frame | 2 | Move at 100% while scoped (base 70%) |
| Superheated | 5 | Scoped rivets pierce one extra target |
| Weakpoint Coil | 8 | Destroying a weak point refunds 3 Rounds and +2 Gain |
| **Mastery: Deadeye** | *Destroy 100 weak points while scoped* | Scoped headshot kills on T1 cause the body to explode (60 dmg, 300 radius) |

### Mod B — Hot Rivets (`MOD_Riveter_HotRivets`)
Mod Fire fires a 5-rivet burst (0.3 s) of glowing rivets that embed, then detonate after 1.0 s (40 Explosive each, 150 radius) and apply **Burning**. Costs 5 Rounds. Cooldown 1.5 s.
| Upgrade | Cost | Effect |
|---|---|---|
| Quick Fuse | 2 | Fuse 1.0 → 0.6 s |
| Plate Cracker | 5 | Hot Rivet explosions deal ×3 to armor plates and Bulwark shields |
| Full Clip | 8 | Burst 5 → 7 rivets |
| **Mastery: Chain Reaction** | *Kill 40 enemies with Hot Rivet detonations* | Killed enemies with embedded rivets explode in a secondary blast (100 dmg) |

---

## 3. STATIC RIFLE — Energy Rifle

*"A Static field-build: a CDF plasma carbine whose containment was deliberately 'detuned' by engineers until it fired raw, screaming noise instead of plasma." — Archive*

**Visual:** A carbine with an exposed coil chamber full of crackling orange-white arcs, a hand-wired amplifier box strapped to the side with a VU meter, speaker grille muzzle. Each shot sounds like a tape-saturated snare hit.

| Stat | Value |
|---|---|
| Damage | **18** per bolt (Energy) |
| Fire rate | 14 bolts/s |
| Projectile | Fast bolt 12000 cm/s, slight spread 1.2° |
| vs. Shields / Harmony Walls / Bulwark shields | ×3 |
| Ammo | 1 Charge per 2 bolts |
| Heat | Firing builds **Heat** (0–100, +4/bolt, −40/s when not firing). At 100: 0.8 s forced vent. |

### Mod A — Heat Burst (`MOD_Static_HeatBurst`)
Mod Fire vents all current Heat as a shockwave around the Unsung: radius 300–600 (scales with Heat), damage 50–300 Energy. Stuns T1. Cooldown 4 s.
| Upgrade | Cost | Effect |
|---|---|---|
| Quick Vent | 2 | Cooldown 4 → 2.5 s |
| Wide Burst | 5 | +30% radius |
| Hot Hands | 8 | Heat builds 25% faster (bigger bursts sooner) |
| **Mastery: Supernova** | *Kill 60 enemies with Heat Burst* | A full-Heat burst also applies Distorted to everything it hits |

### Mod B — Arc Beam (`MOD_Static_ArcBeam`)
Hold Mod Fire: continuous beam (range 2500 cm) dealing ramping damage (60 → 240 dps over 2 s). **Instantly breaks any Harmony Link** it touches (beam hitting a Cantor's lantern or a linked enemy). Costs 12 Charge/s.
| Upgrade | Cost | Effect |
|---|---|---|
| Fast Ramp | 2 | Ramp time 2 → 1.2 s |
| Arc Stun | 5 | Beam stuns T1 continuously while held on them |
| Efficient Coil | 8 | Cost 12 → 8 Charge/s |
| **Mastery: Overload** | *Break 50 Harmony Links or Harmony Walls with the Arc Beam* | Enemies killed by the beam explode (150 dmg, 350 radius, Energy) |

---

## 4. GRAVEDIGGER — Double-Barrel Super Shotgun

*"For emergencies — Sgt. D. Ruiz." — scratched into the stock.*

**Visual:** A brutal, oversized sawn-off double-barrel; blued steel barrels with engraved waveforms, a hand-carved dark-wood stock wrapped in bicycle inner-tube for grip; the Unsung breaks it open one-handed (the barrels flip down), two huge shells pop out smoking, two go in. The single most satisfying reload animation in the game.

| Stat | Value |
|---|---|
| Damage | 20 pellets × 20 = **400** (Kinetic), both barrels per shot |
| Spread | 10° horizontal × 6° vertical ellipse |
| Falloff | Full to 600 cm, 40% at 1200 cm |
| Cycle | Fire → reload: 1.15 s total |
| Ammo | 2 Shells per shot |
| Stagger | Point-blank (≤ 250 cm) full hit: T1 instant Falter (usually dies), T2 flinch (0.3 s) |
| Dismember | Very high dismember bias |

### Upgrade Path (no mods)
| Upgrade | Cost | Effect |
|---|---|---|
| Rending Shells | 4 | ×1.5 damage vs. armor plates and shields |
| Quick Load | 7 | Cycle 1.15 → 0.95 s |
| Heavy Loads | 11 | +15% damage, +2° spread |
| **Mastery: Double Grave** | *Kill 3+ enemies with a single Gravedigger shot 20 times* | Gravedigger has a **second trigger**: tap fire again within 0.2 s of the first shot to fire both barrels separately (2 × 220 dmg, independent aim), same total cycle |

---

## 5. HAMMERFALL — Rocket Launcher

*"CDF 'Hammerfall' MLRS-P: a man-portable multiple rocket system. 'Portable' was meant for vehicles. The Breaker disagrees." — Archive*

**Visual:** A massive 4-tube revolving rocket launcher: rotating cylinder of four tubes, olive-drab with stenciled warnings, a reflex sight, rockets visible in the tubes with orange-painted tips.

| Stat | Value |
|---|---|
| Damage | 180 impact + **140 splash** (radius 350, full damage within 100) (Explosive) |
| Rocket speed | 3600 cm/s |
| Fire rate | 1 rocket / 0.9 s |
| Drum | 4 rockets, then 0.8 s drum-spin reload (can be interrupted by switching) |
| Ammo | 1 Ordnance per rocket |
| Self-damage | 25% (0% Lullaby/Unplugged, 35% Deafening/Unsung — see core loop) |
| vs. flyers | Splash ×1.25 |

### Mod A — Cluster Bell (`MOD_Hammerfall_ClusterBell`)
Mod Fire launches a heavy shell that bursts at the first surface/enemy, or at max range 2500 cm, into 8 bomblets that bounce once then explode (60 dmg each, 200 radius). Costs 2 Ordnance. Cooldown 3 s.
| Upgrade | Cost | Effect |
|---|---|---|
| Air Burst | 2 | Hold Mod Fire to set the burst distance with a range readout |
| More Bomblets | 5 | 8 → 12 bomblets |
| Sticky Bomblets | 8 | Bomblets stick to enemies |
| **Mastery: Carpet** | *Kill 100 enemies with bomblets* | Cluster Bell costs 1 Ordnance |

### Mod B — Lock Salvo (`MOD_Hammerfall_LockSalvo`)
Hold Mod Fire to paint targets (up to 4 locks; 0.3 s per lock; can lock the same heavy multiple times). Release to fire homing rockets (each 150 impact + 100 splash). Costs 1 Ordnance per lock.
| Upgrade | Cost | Effect |
|---|---|---|
| Fast Lock | 2 | Lock time 0.3 → 0.18 s |
| Wide Paint | 5 | Lock cone 10° → 18° |
| Six-Pack | 8 | Max locks 4 → 6 |
| **Mastery: Barrage** | *Kill 40 flyers (Vespers, Ophans, Seraphs, Hymnals, Wailers) with Lock Salvo* | Rockets fired by Lock Salvo cost no ammo if the salvo kills at least one enemy |

---

## 6. SHREDDER — Rotary Cannon

*"The CDF called it the M-77 Area Denial Cannon. Its crews called it the Shredder. Sgt. Okafor calls it 'Linda'." — Archive*

**Visual:** A six-barrel rotary cannon with a drum-fed ammo box on the left side, carry handle, huge heat-sink fins; barrels glow orange after 3 s of fire; the Unsung carries it one-handed with the left hand on a pistol grip under it. Okafor has written "LINDA ♥" on the ammo box.

| Stat | Value |
|---|---|
| Damage | **22** per round (Kinetic) |
| Spin-up | 0.5 s (fires at 50% rate during spin-up) |
| Fire rate | 20 rounds/s at full spin |
| Spread | 1.5° → 3° after 2 s |
| Ammo | 1 Round per shot |
| Movement | 100% |

### Mod A — Tri-Spin (`MOD_Shredder_TriSpin`)
Mod Fire deploys the Shredder into a braced mode: the barrels split into three rotating barrel clusters (3× the muzzles). Fire rate 45 rounds/s, spread 2°. Movement −30% while deployed. 0.6 s to deploy.
| Upgrade | Cost | Effect |
|---|---|---|
| Quick Deploy | 2 | Deploy 0.6 → 0.3 s |
| Unbraced | 5 | Movement penalty −30% → −10% |
| Hot Barrels | 8 | Rounds in Tri-Spin apply Burning on every 10th hit |
| **Mastery: Meat Grinder** | *Deal 50,000 damage in Tri-Spin* | No ammo cost for the first 2 s of each Tri-Spin burst |

### Mod B — Deflector Spin (`MOD_Shredder_DeflectorSpin`)
Hold Mod Fire: the barrels spin without firing, projecting a frontal disc of spinning static (200 cm radius) that **blocks cyan projectiles** and **automatically Counters gold ones** (reflects them). Move at 70%. Barrel heat builds; 4 s max.
| Upgrade | Cost | Effect |
|---|---|---|
| Wider Disc | 2 | 200 → 280 cm radius |
| Charged Release | 5 | Releasing after ≥ 1.5 s of blocking fires a charged blast (300 Energy dmg cone) |
| Cool Spin | 8 | Duration 4 → 6 s |
| **Mastery: Wall of Sound** | *Block or reflect 500 projectiles* | Each blocked projectile adds +1 Plating |

---

## 7. ARC COIL — Chain-Lightning Projector

*"Fort Obdurate weapons lab prototype XW-3. 'Chain arc for swarm suppression.' The label also says 'DO NOT FIRE INDOORS'." — Archive*

**Visual:** A glass-and-copper tube weapon: a central Tesla coil in a glass cylinder, copper windings, a prong-fork muzzle (two electrodes), rubber-insulated grip, sparks crawling over it constantly.

| Stat | Value |
|---|---|
| Damage | **30** per tick to the primary target, 10 ticks/s (Energy); range 1800 cm (auto-locks within a 5° cone) |
| Chain | Arcs to up to **3** additional enemies within 700 cm of the previous, each at 60% |
| vs. flyers | ×1.25 |
| vs. T3 | ×0.7 (it's a swarm weapon) |
| Ammo | 1 Charge per 2 ticks |

### Mod A — Storm Node (`MOD_ArcCoil_StormNode`)
Mod Fire launches a sparking node (lobbed projectile) that sticks to a surface/enemy and pulses lightning at everything within 600 cm for 5 s (20 dmg every 0.25 s). Costs 15 Charge. Cooldown 6 s. Arc Coil primary fire aimed at a node **overcharges** it (radius 900, damage ×2).
| Upgrade | Cost | Effect |
|---|---|---|
| Longer Storm | 2 | 5 → 8 s |
| Magnet Node | 5 | Node pulls T1 enemies and Vespers toward itself |
| Twin Nodes | 8 | 2 nodes can exist at once |
| **Mastery: Tempest** | *Kill 150 enemies with Storm Nodes* | Nodes detonate at the end of their duration (250 dmg, 600 radius) |

### Mod B — Tether Coil (`MOD_ArcCoil_Tether`)
Mod Fire tags up to 3 enemies with a glowing coil-mark (10 s). All damage dealt to any tagged enemy is **shared at 50%** with all other tagged enemies. Costs 20 Charge.
| Upgrade | Cost | Effect |
|---|---|---|
| Wider Tag | 2 | Tag 3 → 4 enemies |
| Full Share | 5 | Share 50% → 75% |
| Mark Duration | 8 | 10 → 15 s |
| **Mastery: Circuit** | *Kill 3 tagged enemies within 1 s, 30 times* | Killing a tagged enemy refreshes the tag duration on the others and tags the nearest untagged enemy |

---

## 8. LANCE — Rail-Lance

*"Concord Armored Train Division, 'Lance' anti-armor railgun, man-portable variant. Punches through a tank, the crew, and the tank behind it." — Archive*

**Visual:** A long, slender rifle with twin parallel rails, a coil-stack spine glowing orange as it charges, a bulky capacitor pack on the stock, and a hazard-stripe muzzle. Fires a white-hot orange slug that leaves a lingering spiral trail.

| Stat | Value |
|---|---|
| Damage | **700** (Energy) |
| Fire rate | 1 shot / 1.6 s |
| Projectile | Hitscan, **pierces all enemies** in line (−15% per enemy pierced) |
| Headshot / weak point | ×2.0 |
| Ammo | 10 Charge per shot |
| Movement | 100% |

### Mod A — Overcharge (`MOD_Lance_Overcharge`)
Hold Mod Fire to charge (1.5 s) — releasing fires a 1400-dmg shot that pierces **terrain up to 100 cm thick** and applies Stagger to T2. Movement −30% while charging. Costs 25 Charge.
| Upgrade | Cost | Effect |
|---|---|---|
| Quick Charge | 2 | Charge 1.5 → 1.0 s |
| Held Charge | 5 | Can hold a full charge for up to 3 s |
| Kill Shot | 8 | Overcharged kills refund 15 Charge |
| **Mastery: Colossus Killer** | *Destroy 30 super-heavies with an Overcharged shot as the killing blow* | Overcharge deals ×1.5 damage to T3 and bosses |

### Mod B — Arc Scythe (`MOD_Lance_ArcScythe`)
Mod Fire releases a horizontal blade of energy (width 1200 cm at max range 3000, grows as it travels) that cuts through everything in a plane (350 dmg; T1 cut in half). Costs 20 Charge. Cooldown 3 s.
| Upgrade | Cost | Effect |
|---|---|---|
| Wider Scythe | 2 | +40% width |
| Twin Scythe | 5 | Fires two blades in an X |
| Reaper | 8 | Kills with the Scythe drop +10 Charge |
| **Mastery: Harvest** | *Kill 5+ enemies with a single Arc Scythe 15 times* | The Scythe returns after reaching max range (a second pass) |

---

## 9. RIPSAW — Saw-Blade Launcher

*"A Mercury mining foreman's hobby project: a pneumatic launcher that fires the diamond-toothed cutting discs of an ore-crusher. He called it 'Dennis'. We call it the Ripsaw." — Archive*

**Visual:** A crude, heavy launcher built from mining equipment: a pneumatic tank, a spring-loaded disc magazine (6 blades visible in a vertical rack), a guide barrel. Blades are 40 cm diamond-toothed saw discs glowing red-hot at the teeth.

| Stat | Value |
|---|---|
| Damage | **220** per blade hit (Blade) |
| Projectile | Blade 2800 cm/s, ricochets off hard surfaces up to **3 times** (each bounce −15% damage), passes through T1 enemies it kills |
| Fire rate | 1 blade / 0.65 s |
| Ammo | 1 Ordnance per 2 blades (blades are cheap — Ordnance counts double) |
| Retrieval | Blades that stop in a surface can be picked up by walking over them (refund 1 blade = 0.5 Ordnance) |
| Dismember | Maximum |

### Mod A — Grinder Blade (`MOD_Ripsaw_Grinder`)
Mod Fire launches a blade that embeds in the first enemy and grinds (40 dmg every 0.1 s for 2 s = 800 total), staggering T1/T2 for the duration (T2 cannot attack while being ground unless HP > 70%). Costs 1 Ordnance. Cooldown 3 s.
| Upgrade | Cost | Effect |
|---|---|---|
| Longer Grind | 2 | 2 → 3 s |
| Shrapnel Finish | 5 | Blade shatters at the end: 8 fragments × 40 |
| Chainsaw Teeth | 8 | Grinding makes the target shed ammo (Rounds/Shells) every 0.5 s |
| **Mastery: Buzzkill** | *Kill 25 T2 enemies with the Grinder Blade* | Grinder cooldown 3 → 1.5 s |

### Mod B — Recall (`MOD_Ripsaw_Recall`)
Mod Fire (tap) recalls all active blades in the world back to the Unsung along their shortest path, damaging everything they pass through (180 per hit). Recalled blades refund their ammo.
| Upgrade | Cost | Effect |
|---|---|---|
| Faster Recall | 2 | Return speed +50% |
| Sharper Return | 5 | Return damage 180 → 260 |
| Orbit | 8 | Recalled blades orbit the Unsung for 2 s (hitting anything that gets close) before being caught |
| **Mastery: Boomerang Storm** | *Hit 3+ enemies with a single Recall 40 times* | Blades that reach max ricochets auto-recall |

---

## 10. THE SILENCER — Super-Weapon

*"A sphere of perfect nothing. Lund's masterpiece and Wren's nightmare. Please, please do not fire it inside the ship." — Archive*

**Visual:** A shoulder-braced weapon the size of a small car engine: a black anechoic sphere (covered in tiny wedge-spikes like the Quietus's walls) held in a brass-and-steel frame, with vacuum tubes and warning lights. When fired, all sound in the mix **drops out** for 1.5 s — the only moment of true silence the player ever *causes*.

| Stat | Value |
|---|---|
| Charge-up | 0.8 s (orange light spirals into the sphere, sound drains) |
| Projectile | A slow (1200 cm/s) black sphere with a white corona |
| Tendrils | While traveling, fires silence tendrils at every enemy within 2500 cm (600 dmg per tendril per 0.2 s, Silence) |
| Detonation | On impact: 5000 Silence damage in 1500 cm, 1500 at edge; freezes survivors (Hushed 4 s) |
| Ammo | 1 Null Cell |
| Special | Kills all Echoes on screen; clears Hymn Saturation for 20 s; bosses take 2000 max per shot |

Upgrades: none (the Silencer is balanced by ammo scarcity). **Null Cell** capacity is fixed at 3. Typical missions place 2–4 Null Cells.

---

## 11. THE AXE — Relic Super Melee Weapon

*"Forged on a world whose name the Unsung never spoke. It does not cut. It **disagrees** with what it touches." — Archive*

**Visual:** A massive, asymmetric two-handed war axe — the head is a jagged, crescent slab of black metal riddled with irregular holes (like a speaker grille or a flute) that howl when swung. The haft is bone-white Oreth stone wrapped in iron bands. When drawn, it emits a sustained, dissonant scream (tritone chord), and its holes glow ember-red.

| Stat | Value |
|---|---|
| Draw | 0.4 s (auto-holsters after 2.5 s idle) |
| Primary (Swing) | One-hit kill on **every non-boss enemy** including T3. 1 Grudge per kill; swings that miss cost nothing. Bosses: 1500 dmg per hit (1 Grudge). |
| Swing reach | Lunge 600 cm toward the aimed enemy |
| Invulnerability | During the kill animation (0.9 s) |
| Mod-fire (**Ruin Sweep**) | Costs 1 Grudge: a 360° sweep (radius 500) killing all T1/T2 and dealing 1500 to T3 |
| Ammo | Grudges (max 3). Sources: `PKP_Grudge` placed pickups; Rig upgrade *Grudge-Bearer*: Breakdowns on T3 enemies grant +1/3 Grudge |
| Kill reward | Axe kills drop full Health + Plating chunk (T3 kill: +50 each) |

---

## 12. THE LARYNX — Captured Choir Weapon (Secret)

*"We tore it out of a Maestro's throat. It still sings. It hates us. It works." — Wren*

**Unlock:** Collect all 7 **Reliquary Shards** (one per Requiem Gate). Wren assembles the Larynx in the hub.

**Visual:** A living organ — a pale, pulsing, porcelain-and-flesh throat with brass vocal-cord pipes — clamped inside a Static steel frame with pressure gauges, hose clamps and warning tape. Its "mouth" (a four-petal Choir mouth) opens at the muzzle. It breathes when idle.

| Stat | Value |
|---|---|
| Alt-fire — **Inhale** | Hold Mod Fire: a 45° cone (1200 cm) that pulls in and **swallows all enemy projectiles** (cyan and gold) inside it; each swallowed projectile = +5 Voice (gold: +10). Also sucks T1 enemies toward the player slowly. |
| Primary — **Aria** | Fires a rapid stream of homing golden notes (12/s, 45 Sonic dmg each; the Host takes ×1.5 via its Sonic resistance). 1 Voice per note. |
| Charged primary — **Requiem** | Hold Fire 1.2 s with ≥ 50 Voice: a beam of all stored voices (duration = Voice/50 s, 1200 dps). |
| Ammo | **Voice** (max 100); cannot be picked up — only inhaled |

---

## 13. Weapon Mastery & Challenge Tracking

* Masteries unlock once **all 3 Brass upgrades** of that mod are purchased; then the challenge becomes active. Progress is tracked globally across missions.
* Mastery challenges display in the pause menu and as a small toast every 25% progress.
* In the hub, Wren celebrates each Mastery (`BRK_Wren_Mastery_*`).

## 14. Weapon Feel Checklist (per weapon, before sign-off)
1. Unique fire SFX with 3+ layers (mechanical, body, tail) and 4+ variations.
2. Muzzle flash + light, smoke, shell ejection (where applicable).
3. Viewmodel recoil animation, camera kick, rumble profile.
4. Impact effects per surface type (concrete, metal, porcelain/Choir, flesh, glass, water, ice).
5. Enemy hit reaction and dismemberment rules verified.
6. Reads clearly at 60 FPS and 144 FPS (no frame-rate-dependent timing — all timers in seconds).
7. HUD icon, weapon wheel icon, ammo counter behavior, mod icons.
