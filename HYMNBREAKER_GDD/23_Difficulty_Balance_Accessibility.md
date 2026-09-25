# 23 — Difficulty, Balance & Accessibility

## 1. Difficulty Modes

| Setting | Lullaby | Unplugged | **Amplified** | Overdriven | Deafening | Unsung |
|---|---|---|---|---|---|---|
| Intended player | Story-first | New to the genre | **Default** | Genre veterans | Masochists | Permadeath masochists |
| Enemy damage to player | ×0.35 | ×0.6 | ×1.0 | ×1.35 | ×1.7 | ×1.7 |
| Enemy HP | ×0.8 | ×0.9 | ×1.0 | ×1.0 | ×1.1 | ×1.1 |
| Boss HP | ×0.7 | ×0.85 | ×1.0 | ×1.15 | ×1.3 | ×1.3 |
| Boss attack cooldowns | ×1.3 | ×1.15 | ×1.0 | ×0.9 | ×0.8 | ×0.8 |
| T1 count / T2+ count | ×0.6 / ×0.7 | ×0.8 / ×0.85 | ×1.0 / ×1.0 | ×1.15 / ×1.0 | ×1.3 / ×1.0 | ×1.3 / ×1.0 |
| Elite substitution | 0% | 0% | 0% | 10% | 20% | 20% |
| Attack tokens (Melee/Ranged/Heavy) | 1/2/1 | 2/3/1 | 3/4/2 | 3/5/2 | 4/6/3 | 4/6/3 |
| Enemy decision delay | ×1.5 | ×1.25 | ×1.0 | ×0.9 | ×0.8 | ×0.8 |
| Counter window | 350 ms | 280 ms | 180 ms | 160 ms | 130 ms | 130 ms |
| Breakdown Health drops | ×2.0 | ×1.5 | ×1.0 | ×1.0 | ×0.85 | ×0.85 |
| Self-damage (explosives) | Off | Off | 25% | 25% | 35% | 35% |
| Fall recovery penalty | 0 | 0 | 10 HP | 10 HP | 20 HP | 20 HP |
| Aim-assist bullet bending | 2.0° | 2.0° | 1.2° | 1.0° | 0.6° | 0.6° |
| Slow-mo weapon wheel | 20% | 20% | 20% | 20% | 50% | 50% |
| Permadeath | — | — | — | — | — | **Yes** (Reprises allowed) |
| Tutorial prompts | Verbose | Standard | Standard | Minimal | Minimal | Minimal |

* Difficulty can be changed **any time** (pause menu) except Unsung (locked; switching away converts the save to Deafening permanently, with a warning).
* **Lullaby** also enables: auto-Breakdown on melee near Faltering enemies from 600 cm, aim assist "High", visual telegraph assist.

---

## 2. Balance Targets

### 2.1 Time-to-Kill (Amplified, base weapons, no upgrades, no weak points)
| Enemy | Target TTK (focused, optimal weapon) | Sanity check |
|---|---|---|
| Thrall (60) | ≤ 0.5 s | 1 Breacher shot at ≤ 8 m (140 dmg) |
| Trooper (90) | ≤ 0.5 s | 1 Breacher shot close / 2 Riveter rivets |
| Chorister (140) | 0.5–1.0 s | 1 Gravedigger shot / 3 Riveter rivets / 1 Breacher + punch |
| Vesper (50) | ≤ 0.3 s | Arc Coil chain / any hit |
| Crescendo (1000) | 3–5 s | Gravedigger to the back ×2 (400 × 2.5 ×2 = 2000) |
| Bellwether (1500) | 5–7 s | Mixed weapons + ringing-bell windows |
| Canon (1800) | 6–8 s | Snipe bell-mouths first (2 × 250 ×2) |
| Profundo (4500) | 12–18 s | Guard Breaks + Shredder/Lance/Gravedigger |
| Carillon (8000) | 20–30 s | Bells first; Lance/Hammerfall |
| Requiem Knight (3500) | 15–25 s | Counter-driven windows |

### 2.2 Weapon DPS (Amplified, base, sustained, optimal range)
| Weapon | Base DPS | Role check |
|---|---|---|
| Breacher | ~165 | Reliable; mods add burst/utility |
| Gravedigger | ~350 (burst 400 per shot) | Highest close burst |
| Riveter | ~240 (×1.5 head) | Precision mid-range |
| Static Rifle | ~250 (×3 vs. shields) | Shield/link breaker |
| Hammerfall | ~355 (AoE) | Crowds/flyers |
| Shredder | ~440 (after spin-up) | Sustained vs. heavies; ammo-hungry |
| Arc Coil | ~300 single + chain (vs. T3 ×0.7) | Swarms |
| Lance | ~440 (pierce) | Long-range, super-heavies |
| Ripsaw | ~340 + ricochets | Tight spaces, dismemberment |

**Balance rule:** no standard weapon may exceed **1.3×** the median base DPS without a compensating drawback (ammo cost, spin-up, range, movement penalty).

### 2.3 Resource Economy Targets (per arena, Amplified)
| Resource | Target |
|---|---|
| Health gained from Breakdowns vs. placed pickups | ≥ 65% from Breakdowns |
| Ammo from Shreds vs. placed | ≥ 55% from Shreds |
| Plating from Distort/Counter vs. placed | ≥ 60% from Distort/Counter |
| Time with an empty equipped weapon | < 3% of arena time |

### 2.4 Difficulty Curve
* Act I: forgiving (threat caps low; new enemies introduced alone).
* Act II–III: rising complexity; player power spikes (Silencer, Lance, Ripsaw, mech).
* Act IV–V: pressure through combinations (Gilded, Maestros, Carillons, Echoes) and hazards.
* Act VI: everything, but the player is at full power; the final boss is spectacular more than punishing (Phase 3 is a power-fantasy release).

### 2.5 Tuning Process
1. Author all numbers in `data/*.csv` → DataTables.
2. Telemetry (`hb.Telemetry.Dump`) per arena: duration, deaths, damage taken by source, resource sources, weapon usage, Gain/Overdrive frequency.
3. Compare to `04` §13 targets; adjust wave compositions first, enemy stats second, player stats last.
4. Every change logged in `BALANCE_LOG.md` with before/after telemetry.

---

## 3. Accessibility

HYMNBREAKER aims for broad accessibility without compromising the intended experience on default settings.

### 3.1 Visual
* **Colorblind modes** (Protanopia, Deuteranopia, Tritanopia) remapping all gameplay color tokens; **shape-coding** always on (sphere = dodge, ring/torus = parry, unique pickup silhouettes, Fuse shapes ■▲●).
* **High-contrast enemies** option: stronger rim light + outline on enemies; background desaturation during combat (optional).
* **Visual telegraph assist:** ground decals for all AoE attacks, a gold outline on parryable attacks, Locris's "real strike" marker, beam-line previews always on.
* **Reduce flashing** (bloom caps, no strobes, softened Hymnfall/Silencer/Radiance/Octave Nova whiteouts).
* **HUD & text scaling** (75–150%), subtitle size (S–XXL), subtitle background, speaker colors.
* **Crosshair customization** (shape, color, size, center dot).

### 3.2 Audio
* Separate volume sliders (Master, Music, SFX, Voice, Radio).
* **Subtitles** (default on) + **sound captions**: directional captions for critical sounds ("[Gold chime — left]", "[Crescendo charging — behind]", "[Profundo roar]").
* **Telegraph Emphasis:** +6 dB on enemy tells and synchronized haptics.
* **Visual Heartbeat Guide** (M22 navigation) and a visual beat counter for Note-Platforms.
* Mono audio; reduce sudden loud sounds (compressor on stingers/Overdrive).

### 3.3 Motor
* Full remapping (KBM & gamepad), including separate buttons for contextual actions (Downbeat vs. Equipment; Counter separate from Punch as an option: **"Dedicated Counter button"** — when enabled, melee never parries and the Counter key does).
* **Hold vs. toggle** for all hold actions (scope, Shredder spin, Deflector Spin, Lock Salvo, weapon wheel).
* **Auto-mantle** (on by default), **auto-Harrow-target** assist (larger aim cone), **auto-sprint** (not needed — always fast).
* Aim assist levels (Off/Low/Standard/High) with separate slowdown/magnetism/bending toggles.
* **Counter window** adjustable independently of difficulty (+0 to +200 ms).
* **Game speed** option (100% / 90% / 80% / 70%) — disables achievements tied to difficulty only.
* Weapon wheel slow-mo strength.

### 3.4 Cognitive
* **Objective reminders** (compass pulse and a short text reminder after 3 min without progress).
* **Rig Manual** (pause menu) with every mechanic explained, short clips (P2).
* **Tutorial replay** per mechanic from the Rig Manual.
* Enemy Archive entries include **"How to fight"** summaries (weakness, tells, answer).
* Option to skip puzzles-lite (Wind Towers remain optional; Note-Platform "assist" doubles durations).

### 3.5 Comfort
* FOV 80–130; head bob off/low/full; camera shake 0–100%; motion blur off by default; speed lines toggle; chromatic aberration toggle; film grain toggle; **gravity-rotation comfort** (M17–M18: rotation speed slider or instant fade transitions).

### 3.6 Content
* **Gore:** Full / Reduced / Off (dissolve).
* **Content warnings** on the front end (violence, body horror, themes of grief and loss).
* **Sign language:** Tamsin's signed lines always subtitled.

### 3.7 Testing
Accessibility features are part of the **Definition of Done** for each relevant system (e.g., a new enemy isn't done until its tells have captions and colorblind-safe visuals).
