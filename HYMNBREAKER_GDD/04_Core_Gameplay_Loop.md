# 04 — Core Gameplay Loop

This is the most important system document. If a mechanic elsewhere contradicts this file, this file wins (except for numbers in `data/*.csv`, which are the tuned source of truth once balancing begins).

---

## 1. The Loop in One Diagram

```
                    ┌──────────────── MOVE (dash, jump, Harrow, Kick Pads) ────────────────┐
                    │                                                                      │
   SHOOT ──damage──▶ ENEMY ──HP ≤ falter threshold──▶ FALTERING (ember glow) ──melee──▶ BREAKDOWN ──▶ HEALTH (+Power Chord charge)
     ▲                │                                                                      │
     │                ├──Harrow (fodder)──▶ SHRED ──▶ AMMO burst                              │
     │                ├──Distort cone──▶ DISTORTED ──any damage──▶ PLATING shards            │
     │                ├──gold note / gold strike──▶ COUNTER ──▶ reflect + PLATING + GAIN     │
     │                └──Hush Charge──▶ HUSHED (frozen) ──damage──▶ (upgrade) HEALTH chips    │
     │                                                                                       │
     └──────────── GAIN meter fills from kills, variety, Counters, Breakdowns ──▶ OVERDRIVE ◀┘
```

**Design intent:** every resource the player needs is inside the enemy. Walking away from a fight to find a health pack is always the *worse* choice. Placed pickups exist, but arena layouts deliberately put them in exposed positions.

---

## 2. The Resource Triangle

| Resource | Primary source | Secondary sources | UI color |
|---|---|---|---|
| **Health** | **Breakdown** (execution of a Faltering enemy) | Placed Health pickups; Hushed-enemy chips (upgrade); Pedal effects; Bloodrush | Red |
| **Ammo** | **Harrow Shred** (rip a fodder enemy apart) | Placed ammo; kills with specific Pedals; Heavy Shred (full refill) | White pickups with type-colored cores |
| **Plating** (armor) | **Distort** (Distorted enemies shed Plating when damaged) | **Counter** (+10 per parry); placed Plating pickups; Overdrive kills | Acid green |

Supporting resources:

| Resource | Source | Spent on |
|---|---|---|
| **Power Chord charge** | +1 per Breakdown (max 1; 2 with upgrade) | Power Chord (charged punch) |
| **Harrow charges** | Charge 1 regenerates (12 s); charges 2–3 from **Harrow Spools** (pickup) & Overdrive kills | Shred (1 fodder / 3 heavy) |
| **Gain** | Aggressive, varied, stylish play | Overdrive |
| **Null Cells** | Rare placed pickups; hub vault rewards | The Silencer |
| **Grudges** | Rare placed pickups; Breakdowns on super-heavies (1 per 3, upgrade) | The Axe |

---

## 3. Enemy States

All enemies implement these states via the shared `UHBStatusComponent` (see `20_Technical_Design_UE5.md`). States can stack unless noted.

| State | Trigger | Visual | Audio | Effect |
|---|---|---|---|---|
| **Alert** | Perceives player | Halo brightens cyan | Alert call (signature chord) | Enters combat behavior |
| **Faltering** | HP ≤ Falter Threshold, or a Stagger event | Body glows **ember orange**, halo flickers and wobbles out of tune, enemy staggers in place | Detuned, wavering version of its chord (pitch wobble ±40 cents) | Cannot attack; can be Breakdown'd. Lasts **Falter Duration**; then recovers (keeps its low HP). |
| **Distorted** | Hit by Distort cone | Silhouette jitters with orange-white static noise (screen-space dither shader), crackling particles | Crackling static loop | Sheds Plating shards when damaged (see §6). 8 s. |
| **Hushed** | Inside a Hush Charge sphere | Body greys out, frost-like white rime, motion frozen mid-pose; halo goes dark | Its chord cuts to silence (a sharp "vacuum" duck) | Frozen, cannot act. +25% damage taken (upgrade). Health chips on damage (upgrade). 4 s. |
| **Stunned** | Distort on T1; Power Chord; certain weapon mods; Downbeat shockwave (T1) | Head snaps back, sparks of orange | Short stun sting | Cannot act for the stun duration (0.4–1.5 s). No Breakdown unless also Faltering. |
| **Linked** | Cantor's Harmony Link | Gold beam from Cantor's lantern to the enemy; enemy has a gold hex-sheen | Sustained harmony | −75% damage taken. Broken by: killing/staggering the Cantor, shooting the lantern, Distort hitting the linked enemy, Arc Beam mod. |
| **Anthem** (buffed) | Near a Hymn Pylon, or Maestro's Accelerando | Gold particle aura, eyes flare | Faster, higher chord | +30% move speed, +25% attack speed, +20% damage. |
| **Echoed** (possessed) | Echo enters an enemy | Translucent ghost double trails the host by 0.3 s | Reverb-drenched copy of its chord | Every attack repeats once 0.5 s later (the "echo"). +50% HP. On host death, the Echo is freed (must be Hushed). |
| **Burning** | Hot Rivets, Phrygian hazards, Silencer? (no) — environmental fire | Orange flames | Crackle | 10 dmg/s for 4 s. T1 panic-run for 1 s. |
| **Airborne / Knocked** | Downbeat, Power Chord, explosions (T1 only) | Ragdoll-blend knockback | — | Can be juggled; Breakdown in air if Faltering. |

### 3.1 Falter Rules

| Tier | Falter Threshold (HP %) | Falter Duration | Stagger events (instant Falter regardless of HP) |
|---|---|---|---|
| T1 Fodder | ≤ 35% | 4.0 s | Power Chord; Counter reflect hit; Downbeat (full-height); Gravedigger point-blank; destroying its weak point |
| T2 Heavy | ≤ 20% | 3.0 s | Power Chord (if HP ≤ 50%); specific weakness hits (e.g. Frag into Ophan maw → Falter at any HP) |
| T3 Super-heavy | ≤ 12% | 2.5 s | Only its specific weakness stagger (per enemy) |
| Boss | Scripted per phase | — | Boss-specific |

* Faltering enemies **do not regenerate**; if the Falter expires they resume at their current HP.
* A Faltering enemy that takes damage past 0 HP simply dies (no Breakdown drop — the player *chose* ammo over health). Some Pedals modify this.
* **Falter Lock:** at most **4** enemies can be Faltering at once (older ones recover early). Prevents degenerate stun-lock farms.

---

## 4. BREAKDOWN (Executions → Health)

**Input:** Melee while aiming at a Faltering enemy within **Breakdown Reach** (400 cm; 600 cm with the *Lunge* Rig upgrade). The Unsung lunges to it (lunge speed 3500 cm/s, max 0.12 s), then plays a contextual execution animation.

| Property | Value |
|---|---|
| Player invulnerability | Full, for the animation duration + 0.25 s after |
| Animation duration | T1: 0.8–1.0 s · T2: 1.1–1.4 s · T3: 1.5–1.9 s. (During Overdrive: ×0.6 speed-up) |
| Camera | Scripted camera within the FP view, max ±30° off the player's aim, returns in 0.2 s |
| Context selection | Direction (front/back/left/right), vertical (enemy above/below/same, player airborne), enemy-specific. Each enemy has 2–6 unique Breakdowns + a generic fallback for its skeleton class. |
| Health drop | T1: **20** · T2: **40** · T3: **60** (as 5-HP red orbs that burst out and magnetize) |
| Low-health bonus | If player Health < 30% of max: drops ×1.5 ("**Desperate Pulse**") |
| Power Chord | +1 charge per Breakdown |
| Gain | +6 (+3 if performed in the air) |
| Chain | After a Breakdown, if another Faltering enemy is within reach and the player presses melee within 0.3 s of the animation end, the lunge is instant (**Chain Breakdown**, +2 Gain) |

**Breakdown animation style guide:** fast, brutal, readable, 3 beats: *impact → rip → finish*. Porcelain cracks, gold light spills, gore sprays. Always ends with the enemy **shattering** (never a slow corpse). Every Breakdown includes the **Arrhythm pulse** audio sting (irregular double heartbeat) timed to the final beat.

---

## 5. HARROW SHRED (Ammo)

The **Harrow** is the chain-harpoon on the Unsung's left arm (full tool spec in `07_Equipment_and_Abilities.md`). Firing it at an enemy produces one of three outcomes:

| Target | Charges available | Outcome |
|---|---|---|
| T1 Fodder | ≥ 1 | **Shred** — the harpoon hooks, the chain winds, the enemy is ripped apart in 0.5 s → ammo burst. Costs 1 charge. |
| T2 Heavy | ≥ 3 | **Heavy Shred** — the Unsung is yanked in, jams the harpoon through the enemy and rips it apart in a 1.2 s animation (invulnerable) → **full ammo refill** of all types. Costs 3 charges. |
| T2 Heavy | < 3 | **Reel-In** — the Unsung is pulled to the enemy at 3000 cm/s (mobility), landing a free punch (stun T2 for 0.3 s). No cost. |
| T3 Super-heavy / Boss | any | **Reel-In** only. |
| Harrow Anchor / grapple point | — | Grapple (see equipment doc). |

### 5.1 Shred Ammo Formula

For each ammo type `T` for which the player owns at least one weapon:

```
max_T      = current max capacity of T
deficit_T  = max_T - current_T
grant_T    = ceil(0.30 * max_T)                         // base
if T == ammo type of equipped weapon: grant_T += ceil(0.15 * max_T)
grant_T    = min(grant_T, deficit_T)
```

* Heavy Shred: `grant_T = deficit_T` for all types.
* Ammo spawns as physical pickups (1 pickup per type, value = grant) that burst outward, then magnetize to the player after 0.25 s within **600 cm** (magnet speed 2200 cm/s; the *Magnetized* Rig upgrade raises radius to 900).
* Null Cells and Grudges are **never** granted by Shred.
* If all owned ammo types are full, Shred still kills and drops **+5 Plating** instead ("Overflow").

### 5.2 Charges

| Property | Value |
|---|---|
| Max charges | 3 |
| Regeneration | Only charge #1 regenerates: 12 s (Rig upgrade → 8 s) |
| Other charges | +1 from **Harrow Spool** pickups (placed in arenas, 2–4 per arena) and +1 from every 5th kill during Overdrive |
| UI | Three chain-link pips under the crosshair (left side) |

---

## 6. DISTORT (Plating)

**Input:** Distort key. A short-range cone of screaming static from the Rig's chest vents.

| Property | Value |
|---|---|
| Shape | Cone, 700 cm range, 70° |
| Damage | 30 (Energy) |
| Effect | Applies **Distorted** (8 s) to every enemy hit |
| T1 bonus | Stuns T1 for 0.6 s (interrupts attacks) |
| Harmony Link | Breaks any link on enemies hit |
| Cooldown | 22 s (Rig upgrades: 18 s → 15 s) |
| Plating shed | Each damage instance ≥ 10 dmg on a Distorted enemy spawns one **Plating shard** (5 Plating). Per-enemy shard cooldown 0.25 s. |
| Kill bonus | Killing a Distorted enemy bursts T1: +10 · T2: +25 · T3: +40 Plating |

Design note: Distort is deliberately usable on crowds. The best play is to Distort a pack, then shotgun them for a shower of green.

---

## 7. COUNTER (Parry)

**Input:** Melee, timed. There is no separate parry button.

| Property | Value |
|---|---|
| Parryable attacks | **Gold** projectiles ("Resonant Notes") and **gold-flashing** melee strikes. Enemies telegraph them with a gold flare + a rising two-note chime 0.4 s before impact. |
| Parry window | Melee pressed ≤ **180 ms** before impact on Amplified (see difficulty table: 350 / 280 / 180 / 160 / 130 / 130 ms) |
| Projectile Counter | The note is reflected at 2× speed toward its source (auto-aimed), dealing **3×** its original damage; T1/T2 sources are staggered (instant Falter for T1) |
| Melee Counter | Attacker is thrown back; T1/T2 instantly Falter; T3 enters **Guard Break** (1.5 s, takes +50% damage) |
| Reward | **+10 Plating**, **+6 Gain**, brief time-dilation (0.1 s at 20% speed) and a bright bell-crack "CLANG" |
| Mistimed | Normal punch (25 dmg — see §9.1). No penalty. |
| Multiple notes | One press can reflect up to 3 notes arriving within the same window |

---

## 8. GAIN & OVERDRIVE

### 8.1 Gain Meter (0–100)
Displayed as an ember arc around the lower half of the crosshair and as a VU-meter strip on the HUD's left gauge.

| Event | Gain |
|---|---|
| Kill T1 / T2 / T3 | +3 / +8 / +15 |
| Breakdown (air) | +6 (+3) |
| Chain Breakdown | +2 bonus |
| Counter | +6 |
| Weak point destroyed | +5 |
| Multi-kill (≥3 kills within 1.0 s) | +5 |
| **Riff** — damaging an enemy within 0.75 s of switching weapons (the previous weapon must have dealt damage in the last 1.5 s) | +1 per Riff (max +4/s) |
| Environmental kill (hazard, fall, barrel) | +4 |
| Kill with each *different* weapon within 10 s (variety chain, counted per new weapon) | +2 |
| Damage taken to Health (not Plating) | −1 per 10 damage |
| Inactivity | After 4 s without any Gain event: −4/s decay |

### 8.2 Overdrive

**Input:** Overdrive key (when Gain = 100). Activation plays a 0.4 s "amp kick" animation (exhaust stacks flare, grille glows, invulnerable during the animation).

| Effect | Value |
|---|---|
| Duration | 12 s (Rig/Heart upgrades → 16 s). Gain drains to 0 over the duration. |
| Melee | Kills T1/T2 instantly; 800 dmg to T3; bosses 400 |
| Breakdowns | ×0.6 animation time; ×2 Health drop |
| Weapons | +25% fire rate; **no ammo consumed** (standard weapons only) |
| Defense | −40% damage taken |
| Mobility | Dash recharge ×2; +10% move speed |
| Harrow | Fodder Shreds cost 0 charges; every 5th kill restores 1 charge |
| Encore | Killing a T3 during Overdrive extends it by +2 s (max +6 s per activation) |
| Music | Switches to the **Overdrive stem** (guitar-solo layer) bar-synced via Quartz — see audio doc |
| VFX | Screen-edge orange static vignette, exhaust flames, chromatic aberration pulses on every kill |

Overdrive cannot be activated during Breakdowns, cutscenes, or mech segments. Gain cannot be earned during Overdrive.

---

## 9. POWER CHORD & DOWNBEAT (summary; full spec in equipment doc)

* **Power Chord:** melee while holding a charge = a massive shockwave punch. 600 dmg in a 300 cm frontal cone. Instantly breaks Bulwark shields, Harmony Walls, Gilded armor plates, and Hymn Pylons' cores. Staggers T2 (≤ 50% HP → Falter). Charges from Breakdowns.
* **Downbeat:** from the air (≥ 250 cm above ground), press the Downbeat key to slam down. Shockwave radius scales with fall height (300–700 cm), 80–250 dmg, knocks T1 airborne, stuns T2 0.3 s. With a Power Chord charge held: **Power Downbeat** (consumes the charge) — 900 dmg in 800 cm, stagger T2.

### 9.1 Basic Melee (Punch)
* **Damage:** 25 (Melee). 3-hit alternating cycle (R, L, R) at 0.35 s per punch.
* **Effects:** T1 flinch; small knockback (150 cm); +1 Gain per hit that lands on a Choir-form.
* **Tuned for the tutorial:** 2 punches take a Thrall (60 HP) to 10 HP → Faltering (≤ 35%) → Breakdown. Designers must keep this relationship if Thrall HP or punch damage changes.
* Punches are the fallback when weapons are dry — never the primary DPS (except with the *Fuzz* Pedal or during Overdrive).

---

## 10. DAMAGE MODEL

### 10.1 Player Damage Intake
1. Damage is multiplied by the difficulty's `EnemyDamageMult` and any status (Overdrive −40%, Dead Silence −100%).
2. **Plating absorbs damage 1:1 first.** When Plating reaches 0, the remainder goes to Health.
3. **Piercing** attacks (marked in the bestiary; only some T3/boss attacks) apply **50%** of their damage directly to Health, bypassing Plating.
4. At Health 0 → death (or a **Reprise** triggers).
5. **Low Health state (< 25%)**: the Arrhythm heartbeat SFX intensifies; screen-edge desaturates to red; Breakdown drops get the Desperate Pulse bonus.
6. **No fall damage.** Out-of-bounds falls return the player to the last safe ground point with 10 damage (0 on Lullaby/Unplugged).

### 10.2 Damage Types

| Type | Sources | Notes |
|---|---|---|
| **Kinetic** | Breacher, Gravedigger, Riveter, Shredder | Baseline |
| **Explosive** | Hammerfall, Frag Charge, Frag Slug, Hot Rivets, Cluster Bell, barrels | Splash; self-damage 25% (no self-damage on Lullaby/Unplugged); self-knockback allowed (rocket-jumping is a valid trick) |
| **Energy** | Static Rifle, Arc Coil, Lance, Distort | ×3 vs. shields and Harmony Walls |
| **Blade** | Ripsaw, The Axe | Severs limbs readily (dismemberment bias) |
| **Melee** | Punch, Power Chord, Downbeat, Breakdown | Staggers |
| **Silence** | Hush Charge, The Silencer | Kills Echoes; freezes Choir |
| **Sonic** | The Larynx, reflected notes | ×1.5 vs. Choir "pure" forms (Host) |

### 10.3 Enemy Damage Modifiers
* **Headshots:** enemies with a defined `Head` hit zone take ×1.5 from all bullet/energy/blade hits (Riveter *Tack Scope* ×2.5; Lance ×2.0; shotgun pellets ×1.25).
* **Weak points:** destructible hit zones with their own HP and multiplier (×2–×3). Destroying one triggers a behavior change (defined per enemy) + Gain +5.
* **Armor plates** (Gilded variants, Bulwark shields): separate HP pools that block damage to the body until broken; Power Chord breaks instantly; Energy ×2.
* **Resistances** per enemy per damage type are in `data/enemies.csv` (`Res_Kinetic`, `Res_Explosive`, …) as multipliers.
* **Splash vs. flyers:** flying enemies take ×1.25 from Explosive splash (encourages rockets vs. Vespers packs).

### 10.4 Dismemberment & Progressive Damage
* Every humanoid-ish enemy has **progressive damage**: its porcelain skin cracks as HP falls (material parameter `DamageAmount` 0→1 drives crack masks revealing red flesh and gold light).
* Limbs detach at thresholds when hit by Blade/Explosive/heavy Kinetic (arm off → no ranged attack for Troopers; leg off → T1 crawls).
* Death = **Shatter**: body bursts into porcelain shards, gibs and golden light motes. Corpses do not persist longer than 8 s (fade into gold dust) to keep performance budgets and visual clarity.

---

## 11. PICKUPS (placed in levels)

| Pickup | ID | Effect |
|---|---|---|
| Health — small / medium / large | `PKP_Health_S/M/L` | +5 / +25 / +50 (cannot exceed max) |
| **Bloodrush** | `PKP_Bloodrush` | +100 Health above max (to max+100), decays 2/s back to max |
| Plating — small / medium / large | `PKP_Plating_S/M/L` | +5 / +25 / +50 |
| **Iron Mantle** | `PKP_IronMantle` | Plating to max+50 (overcharge, decays 1/s to max) |
| Ammo — Shells / Rounds / Charge / Ordnance (small / large) | `PKP_Ammo_<Type>_S/L` | Small: 25% of max · Large: 60% of max |
| Null Cell | `PKP_NullCell` | +1 Silencer ammo |
| Grudge | `PKP_Grudge` | +1 Axe charge |
| Harrow Spool | `PKP_HarrowSpool` | +1 Harrow charge |
| **Amp** (power-up) | `PKP_PU_Amp` | ×4 damage for 20 s |
| **Tempo** (power-up) | `PKP_PU_Tempo` | +35% move speed, +50% fire rate, instant reloads, dash recharge ×3, for 20 s |
| **Dead Silence** (power-up) | `PKP_PU_DeadSilence` | Invulnerability 15 s; the music drops to a muffled low-pass while the Unsung's heartbeat is loud |
| **Overdrive Surge** (power-up) | `PKP_PU_OverdriveSurge` | Instantly fills Gain to 100 |

Pickup readability: rotating, bobbing, emissive, with a colored light and a unique shape — Health = red vial-heart; Plating = green armor shard; ammo = type-shaped crates; power-ups = large spinning sigils on pedestals with a vertical light beam visible from 100 m.

---

## 12. DEATH, CHECKPOINTS & REPRISES

* **Checkpoints:** autosave at: mission start, every combat-arena start **and** completion, every major area transition, before bosses and each boss phase ≥ 2.
* **On death:** reload last checkpoint. Player resources restored to at least: Health 100%, Plating 50% of max, each ammo type 50% of max (or current value at checkpoint if higher). Arena restarts from wave 1.
* **Reprise** (extra life, `PKP_Reprise`): found in secrets (max carried: 3). On lethal damage, a Reprise is consumed automatically: time freezes for 0.8 s, a massive shockwave (1000 dmg, 1200 cm, Silence damage type) blasts out, the player revives at 100% Health and 50% Plating with 2 s invulnerability. Disabled in Unsung (permadeath) mode? **No** — Reprises are the only safety net in Unsung mode and are highly valued there.

---

## 13. COMBAT RHYTHM TARGETS (for encounter designers)

Measured by telemetry on Amplified difficulty with a mid-skill player:

| Metric | Target |
|---|---|
| Average arena duration | 2.5–4.5 min (max 7 min for "finale" arenas) |
| Breakdowns per minute in an arena | 4–8 |
| Shreds per minute | 3–5 |
| Distort uses per minute | 2–3 |
| Overdrive activations per arena (from wave 2 onward) | ~1 per 3 minutes |
| Time spent with Health < 25% | < 8% of arena time |
| Deaths per arena (first attempt) | 0.2–0.5 |
| Ammo "dry" events (equipped weapon empty) | < 1 per arena — if higher, increase Harrow Spools or fodder density |

---

## 14. "WHY WOULD I...?" SANITY TABLE

| Question | Answer (if the answer is "you wouldn't", fix the design) |
|---|---|
| ...ever use the Breacher late-game? | Frag Slug is the fastest answer to Ophan maws and Drum Fire is the best fodder-clearer per shell. |
| ...Shred instead of shooting fodder? | Because ammo. Shells run out in ~12 shots. |
| ...execute instead of killing outright? | Health, Power Chord charges, invulnerability window, +Gain. |
| ...parry instead of dodging? | Plating, Gain, reflected damage, instant T1 stagger. |
| ...weapon-switch? | Riff Gain, and every heavy has a different answer. |
| ...explore? | Upgrades: Heart Shards, Rig Cores, Brass, Pedals, Reprises — the difficulty curve assumes ~70% collection. |
