# 07 — Equipment & Abilities

The Unsung's **Rig** carries a set of built-in tools. Most "wake up" over Act I as the Rig recovers from four billion years of dormancy (diegetic tutorial pacing). Their upgrades are bought with **Rig Cores** (see `08_Progression_and_Economy.md`, Rig Tree IDs `RIG_*`).

| Tool | ID | Unlocked | Input | Purpose |
|---|---|---|---|---|
| Harrow | `ABL_Harrow` | M01 (Area 2) | Harrow | Ammo (Shred), traversal (grapple), gap-closing (Reel-In) |
| Breakdown | `ABL_Breakdown` | M01 (Area 1) | Melee on Faltering | Health |
| Counter | `ABL_Counter` | M01 (passive), taught M02 | Melee, timed | Plating, reflect |
| Frag Charge | `ABL_FragCharge` | M02 | Equipment | Burst AoE damage |
| Distort | `ABL_Distort` | M02 | Distort | Plating, crowd stun, link break |
| Hush Charge | `ABL_HushCharge` | M03 | Equipment (swap) | Freeze; kill Echoes |
| Overdrive | `ABL_Overdrive` | M03 | Overdrive | Berserk super-state |
| Downbeat | `ABL_Downbeat` | M03 | Downbeat (air) | Slam AoE, secrets, mobility |
| Power Chord | `ABL_PowerChord` | M04 | Melee with charge | Armor/shield/pylon breaker |
| Surge | `ABL_Surge` | M01 (start) | Surge | Dash |
| Broadside | `ABL_Broadside` | M25 (M25–M26 only) | Broadside | Quietus fire-support call-in (see `14_Missions/M25_The_Staves.md` §2) |

---

## 1. THE HARROW

**Fiction:** A barbed harpoon on 40 m of self-retracting chain, launched from a spool on the Unsung's left forearm. Salvaged from a whaling-hunter civilization eons ago; the barb is a jagged hook of black iron that glows ember-red when it bites.

**Visual/Audio:** The chain is visible as a physical cable (spline mesh `SM_Harrow_ChainLink` instanced along a Cable/spline component, 40 links/m). Fire SFX: pneumatic *CHUNK* + chain rattle; bite SFX: meat-and-porcelain crunch; reel SFX: ratcheting winch.

### 1.1 Targeting
* Aim cone: 6° (Harrow Anchors and enemies), range 3000 cm.
* **Target priority:** Harrow Anchor under crosshair > Faltering enemy > T1 enemy > T2 > T3.
* When a valid target is under the crosshair, a small chain-link icon appears on the crosshair with the predicted outcome: **SHRED** (orange), **HEAVY SHRED** (orange, larger), **REEL** (white), **GRAPPLE** (white).

### 1.2 Outcomes (full rules in `04_Core_Gameplay_Loop.md` §5)
| Outcome | Timing | Notes |
|---|---|---|
| **Shred** (T1) | Harpoon travel (9000 cm/s) + 0.5 s rip | The enemy is yanked 150 cm toward the player then torn apart. Player can keep moving and shooting during the rip (left arm is busy; right-hand weapon usable). |
| **Heavy Shred** (T2, 3 charges) | 1.2 s synced animation, invulnerable | The Unsung is pulled to the enemy, harpoons it through the chest, braces a boot on it and rips the chain back. |
| **Reel-In** | Pull at 3000 cm/s, stop 200 cm short, free punch | Cancels on dash. Cannot Reel into super-heavies' faces — you're stopped at 350 cm. |
| **Grapple** | Pull at 3000 cm/s, slingshot +500 up on arrival | Chains with other anchors. |

### 1.3 Harrow Rig Upgrades (`RIG_Harrow_*`)
| ID | Name | Effect |
|---|---|---|
| `RIG_Harrow_1` | Fast Winch | Charge #1 regen 12 → 8 s |
| `RIG_Harrow_2` | Magnetized | Resource magnet radius 600 → 900 cm |
| `RIG_Harrow_3` | Barbed Rip | Shreds also drop 5 Plating |
| `RIG_Harrow_4` | Whiplash | Reel-In arrival punch staggers T2 for 0.8 s and is a Power Chord if a charge is held (consumes it) |
| `RIG_Harrow_5` | Second Spool | Charge #2 also regenerates (20 s) |

---

## 2. FRAG CHARGE

**Fiction:** A CDF fragmentation charge, modified by Wren with a "sticky" magnetic housing and a Static detonator that plays a 3-note guitar riff before exploding (0.6 s).

| Stat | Value |
|---|---|
| Throw | Lobbed, 2200 cm/s, arcs; sticks to enemies, bounces off walls once |
| Fuse | 0.6 s after landing/sticking |
| Damage | 320 center (Explosive), falloff to 80 at radius 450 |
| Ophan weakness | Thrown into an open maw → instant Falter |
| Cooldown | 12 s |
| Charges | 1 (2 with upgrade) |

### Frag Rig Upgrades (`RIG_Frag_*`)
| ID | Name | Effect |
|---|---|---|
| `RIG_Frag_1` | Twin Charges | 2 charges |
| `RIG_Frag_2` | Quick Fuse | Fuse 0.6 → 0.3 s; cooldown 12 → 10 s |
| `RIG_Frag_3` | Cluster | Explosion releases 5 mini-charges (60 dmg each) |
| `RIG_Frag_4` | Concussive | T2 enemies in the blast are stunned 0.6 s |

---

## 3. HUSH CHARGE

**Fiction:** A palm-sized black sphere of Quietus anechoic material around a miniature Mute Engine. On activation, everything within 5 m stops vibrating. Hearing one go off feels like your ears are being pulled out of your head.

| Stat | Value |
|---|---|
| Throw | Same arc as Frag; does not stick; activates on first impact |
| Field | Sphere radius **500 cm**, duration **4.0 s**, visible as a dark, still, desaturated bubble with a thin white rim; inside it the music and SFX are low-passed heavily (if the player is inside) |
| Effect | All Choir enemies inside are **Hushed** (frozen). Tuned humans (Thralls, Troopers) and cultists are also frozen (the Hymn animates them). Projectiles entering the field drop dead. **Echoes** inside are destroyed instantly. |
| Bosses | Slowed 50% for 2 s instead of frozen (unless a specific boss phase says otherwise) |
| Cooldown | 20 s |
| Charges | 1 |

### Hush Rig Upgrades (`RIG_Hush_*`)
| ID | Name | Effect |
|---|---|---|
| `RIG_Hush_1` | Brittle | Hushed enemies take +25% damage |
| `RIG_Hush_2` | Life in Silence | Damaging a Hushed enemy spawns Health chips (5 HP, per-enemy cooldown 0.4 s) |
| `RIG_Hush_3` | Deep Hush | Duration 4 → 5.5 s; radius 500 → 600 |
| `RIG_Hush_4` | Quick Hush | Cooldown 20 → 15 s |

**Swap:** `IA_SwapEquipment` toggles Frag ↔ Hush; each has an independent cooldown. The HUD shows both icons (active one large).

---

## 4. DISTORT

Full stats in `04_Core_Gameplay_Loop.md` §6. Visual: the Rig's chest cage opens its vents and screams: a cone of orange-white static "snow" and jagged waveform ribbons. SFX: harsh feedback squeal (a guitar amp at maximum gain being pointed at itself) — the loudest non-weapon sound the player makes.

### Distort Rig Upgrades (`RIG_Distort_*`)
| ID | Name | Effect |
|---|---|---|
| `RIG_Distort_1` | Quick Recovery | Cooldown 22 → 18 s |
| `RIG_Distort_2` | Wider Cone | Range 700 → 900, angle 70° → 90° |
| `RIG_Distort_3` | Feedback Loop | Kills on Distorted enemies reduce Distort cooldown by 1 s |
| `RIG_Distort_4` | Overdriven Signal | Distort also stuns T2 for 0.4 s |
| `RIG_Distort_5` | Fast Recovery | Cooldown 18 → 15 s |

---

## 5. COUNTER (Parry)

Full rules in the core-loop doc §7. Upgrades are through **Pedals** (e.g., *Reverb* — see Pedalboard) and **Heart perks**, not the Rig tree, because Counter is a skill, not a gadget.

**Telegraph standard (all parryable attacks):**
1. 0.6–0.4 s before impact: the attacker (or projectile) flares **gold**; a thin gold ring expands from it.
2. A rising two-note chime (perfect fifth, e.g., A4 → E5) plays, spatialized.
3. Parryable projectiles are **ring-shaped** (torus), never spheres (spheres = cyan, unparryable).

---

## 6. POWER CHORD

| Stat | Value |
|---|---|
| Charge source | +1 per Breakdown; max 1 (Heart perk → 2) |
| Visual when charged | The right gauntlet's knuckles glow ember with arcing static; a low hum loop |
| Strike | Melee with a charge: 0.1 s wind-up, then a devastating punch; frontal cone 300 cm × 60°; **600 Melee dmg** |
| Special | Instantly breaks: Bulwark shields, Harmony Walls, Gilded armor plates (all on the struck enemy), Hymn Pylon cores, Organ Grinder turrets (if hit directly), Canon bell-mouths (if hit directly) |
| Stagger | T1 obliterated; T2 at ≤ 50% HP → Falter; T3 → Guard Break (duration per enemy, 1.0–2.0 s — see the bestiary) |
| With Downbeat | See Power Downbeat |

---

## 7. DOWNBEAT
See `05_Player_Character_Movement_Controls.md` §7. Rig upgrades:

| ID | Name | Effect |
|---|---|---|
| `RIG_Mobility_3` | Heavy Beat | Downbeat damage ×1.5 and radius +20% |

---

## 8. SURGE (Dash) — Rig Upgrades (`RIG_Mobility_*`)
| ID | Name | Effect |
|---|---|---|
| `RIG_Mobility_1` | Quick Surge | Recharge 1.25 → 1.0 s |
| `RIG_Mobility_2` | Surge Strike | Dashing through a T1 enemy staggers it (0.5 s) and deals 40 dmg |
| `RIG_Mobility_3` | Heavy Beat | (see Downbeat) |
| `RIG_Mobility_4` | Lunge | Breakdown reach 400 → 600 cm |
| `RIG_Mobility_5` | Air Brakes | Holding Surge in the air stops horizontal momentum instantly (precision landing tool) |

---

## 9. OVERDRIVE
Full rules in the core-loop doc §8. Upgrades through Heart perks and Pedals.

**Visual script (0.4 s activation):**
1. Frame 0: time dilation to 10% for 0.15 s.
2. The Unsung's arms spread; exhaust stacks ignite with roaring static-fire; the grille jaw glows.
3. A shockwave ring (cosmetic + 50 dmg, knockback T1) bursts out.
4. Music transitions to the Overdrive stem at the next beat (Quartz-quantized; if the next beat is > 0.2 s away, a riser SFX bridges it).

---

## 10. POWER-UPS (placed)

| Power-up | Visual on pedestal | Player VFX while active | Music |
|---|---|---|---|
| **Amp** (×4 dmg, 20 s) | Giant spinning amplifier-knob sigil, orange-red beam | Weapons glow red-hot; muzzle flashes doubled; screen edges red | A heavy filter-sweep layer |
| **Tempo** (haste, 20 s) | Spinning metronome sigil, yellow beam | Motion trails; everything else looks slightly slower (world time unchanged) | Music tempo feels double-time (drum stem swaps to a double-time variant) |
| **Dead Silence** (invulnerable, 15 s) | Black sphere sigil with white corona | Player aura of stillness; enemy projectiles fizzle on contact | Music muffled/low-passed; heartbeat loud |
| **Overdrive Surge** (full Gain) | Spinning exhaust-stack sigil, ember beam | — | Riser |

Placement rule: max **1 power-up per arena**; must be visible from the arena's entry; used to highlight a "big moment" (a super-heavy wave, a boss add-phase).

---

## 11. Unlock Tutorials (diegetic)

Every tool unlock uses the same pattern (≤ 12 s, never pauses the game):
1. HUD glitches and a Rig boot line appears in the top-left: `RIG SUBSYSTEM RESTORED: DISTORT` (orange monospace, typewriter effect).
2. A **one-line prompt** with the input glyph: "[C] DISTORT — Distorted enemies shed PLATING when damaged."
3. A safe "tutorial pocket": a few T1 enemies appear (or were already present) so the player can try it immediately.
4. The prompt persists until the player uses the tool successfully once (or 30 s pass).
5. Further detail lives in the **Rig Manual** (pause menu → Rig), with short looping video clips (P2).
