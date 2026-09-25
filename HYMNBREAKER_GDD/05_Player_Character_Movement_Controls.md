# 05 — Player Character, Movement & Controls

All values are **Amplified (Normal)** defaults and live in `DA_PlayerTuning` (a `UHBPlayerTuningData` DataAsset). Designers tune there, never in code.

---

## 1. Body & Camera

| Property | Value | UE mapping |
|---|---|---|
| Capsule radius | 40 cm | `UCapsuleComponent::CapsuleRadius` |
| Capsule half-height | 96 cm (192 cm total) | `CapsuleHalfHeight` |
| Eye height | 172 cm above floor (76 cm above capsule center) | `BaseEyeHeight = 76` |
| Crouch | **None** (by design — keeps players moving and levels readable) | `bCanCrouch = false` |
| Default FOV | 100° horizontal (option range 80–130) | Camera FOV |
| FP weapon FOV | Separate viewmodel FOV 75° (option 60–90) to avoid distortion at high world FOV | Material/`FOV` via panini projection or separate scene capture — see tech doc |
| Full-body awareness | Legs and torso visible when looking down; body casts a shadow | Separate `SK_Unsung_Body` hidden from owner except legs; shadow-only mesh for the full body |

---

## 2. Ground Movement

| Parameter | Value | UE `UCharacterMovementComponent` |
|---|---|---|
| Max speed | **950 cm/s** (no sprint key — always fast) | `MaxWalkSpeed = 950` |
| Acceleration | 6000 cm/s² (0 → max in ~0.16 s) | `MaxAcceleration = 6000` |
| Braking | 4500 cm/s² | `BrakingDecelerationWalking = 4500` |
| Ground friction | 8.0 | `GroundFriction = 8` |
| Step height | 45 cm | `MaxStepHeight = 45` |
| Walkable slope | 46° | `SetWalkableFloorAngle(46)` |
| Speed while firing | 100% (no penalty) except Shredder *Tri-Spin* (−30%), Shredder *Deflector Spin* (−30%), Lance *Overcharge* charging (−30%) and Riveter *Tack Scope* (−30%; 0% with the *Light Frame* upgrade) | — |
| Backpedal | 100% speed (DOOM-style) | — |

---

## 3. Air Movement

| Parameter | Value |
|---|---|
| Gravity scale | **2.2** (−2156 cm/s²) — `GravityScale = 2.2` |
| Jump velocity | **810 cm/s** → apex ≈ **152 cm**, time to apex ≈ 0.38 s |
| Double jump | Resets vertical velocity to **760 cm/s** → +134 cm; horizontal velocity keeps 100% magnitude and re-aims **70%** toward current input direction |
| Max air height (double jump at apex) | ≈ **286 cm** |
| Air control | 0.85 (`AirControl = 0.85`, `AirControlBoostMultiplier = 2`, threshold 25) |
| Terminal fall speed | 4000 cm/s |
| Coyote time | 0.12 s after leaving a ledge, first jump still counts as a ground jump |
| Jump buffer | 0.15 s: jump pressed just before landing triggers on landing |
| Landing | No fall damage. Landings from > 600 cm play a heavy landing (camera dip 6 cm, 0.1 s, dust ring VFX) with **no** movement penalty. |

---

## 4. Surge (Dash)

| Parameter | Value |
|---|---|
| Charges | **2** |
| Recharge | 1.25 s per charge, sequential (Rig upgrade: 1.0 s) |
| Distance | 600 cm over **0.15 s** (burst speed 4000 cm/s) |
| Direction | Current movement input direction (2D); if no input, forward along the camera yaw. **No vertical component**; gravity is suspended during the dash. |
| Exit velocity | 1250 cm/s in dash direction, then normal deceleration |
| Air dash | Allowed, same as ground; does not consume jumps |
| I-frames | **None** by default (Pedal *Phaser* grants 0.15 s) |
| VFX/SFX | Radial blur 0.1 s, FOV kick +6°, exhaust burst particles from the back stacks, a "tape-stop whoosh" SFX |
| UI | Two small pips below the crosshair (right side) |

Dash-cancel rules: dash can be triggered during weapon fire, reload (does not cancel reload), weapon switch, Harrow reel (cancels the reel), and mantle (cancels the mantle). It cannot be used during Breakdowns.

---

## 5. Mantle (Ledge Climb)

Automatic. When the player is **airborne or moving into a wall** and:
* a ledge top exists between **60 cm and 130 cm above the capsule bottom** at the moment of contact,
* the ledge has at least 80 cm × 80 cm of standable surface,
* input is pressing toward the wall,

→ the Unsung vaults up in **0.25 s** (hands plant, pull up). Mantle preserves 50% of horizontal speed on exit.

Resulting **traversable heights** (these are the level-design metrics — see `12_Level_Design_Standards.md`):

| Obstacle height | How |
|---|---|
| ≤ 45 cm | Step (walk) |
| ≤ 140 cm | Single jump |
| ≤ 270 cm | Double jump (land on top) or single jump + mantle (≤ 280) |
| ≤ 400 cm | Double jump + mantle |
| > 420 cm | Requires a traversal element (Kick Pad, Harrow Anchor, Grip Wall, Swing Pole) |

---

## 6. Traversal Elements (player side)

| Element | ID | Behavior |
|---|---|---|
| **Harrow Anchor** | `BP_HarrowAnchor` | A rusted iron ring-bolt (or a Choir bone-knot) with an ember marker when in range. Harrow fire → pull to anchor at 3000 cm/s; at arrival, the Unsung is flung past it with +500 cm/s upward bias ("slingshot"), letting players chain anchors. Max range 3000 cm. Aim-assist cone 6°. |
| **Swing Pole** | `BP_SwingPole` | Horizontal bar. Contact while airborne → auto-grab, 1 full swing (0.45 s), release launches forward at 1400 cm/s + 700 cm/s up. Jump during swing = early release. |
| **Kick Pad** | `BP_KickPad` | Static-built speaker-cone launch pad. On contact, launches the player on an authored arc to a target (`TargetPoint` + apex height). Air control is reduced to 0.3 during the arc. Choir equivalent: **Updraft Throat** (same behavior, organic visuals). |
| **Grip Wall** | `BP_GripWall` (volume + material) | Climbable surface (rusted chain-link mesh / bone lattice, always with the **orange-painted grip trim** at edges). Jump into it → the Unsung grabs and climbs at 450 cm/s up while holding forward; can move laterally at 300 cm/s; jump to leap off (700 cm/s outward, 600 up). Mounting refreshes the double jump and 1 dash charge. |
| **Grind Rail** | `BP_GrindRail` (spline) | *(P1, used from M10 on)* Industrial rails / Choir staff-lines. Landing on one attaches the player, who slides along the spline at 1600 cm/s; jump to detach. Player can shoot while grinding. |
| **Choir Note-Platforms** | `BP_NotePlatform` | *(Harmonium only)* Luminous ring platforms that exist on a musical timer (visible countdown: the ring shrinks and dims). See M20. |
| **Breakable Floor** | `BP_BreakableFloor` | Cracked concrete/porcelain; breaks under Downbeat or explosives. Used for secrets and shortcuts. |
| **Monkey/Hanging Chain** | — | **Not used** (Swing Poles cover this). |

---

## 7. Downbeat (Ground Slam)

| Parameter | Value |
|---|---|
| Unlock | M03 |
| Requirement | Airborne and ≥ 250 cm above the ground below |
| Descent speed | 4500 cm/s straight down (small forward drift from current momentum, max 300 cm/s) |
| Shockwave | Radius = lerp(300, 700) over fall height 250→1500 cm; damage lerp(80, 250) |
| Effects | T1 knocked airborne (juggle window 0.8 s); T2 stunned 0.3 s; breaks `BP_BreakableFloor` |
| Bounce | Pressing jump within 0.1 s of impact → **Slam Jump** (jump velocity 1000 cm/s) |
| Cooldown | None (limited by the height requirement) |
| Power Downbeat | If a Power Chord charge is held and the player holds the Downbeat key for 0.2 s during the slam: consumes the charge; radius 800, 900 damage, T2 stagger |

---

## 8. Hazards & Out of Bounds

| Hazard | Behavior |
|---|---|
| Bottomless pit / void / deep water / lava-steel | Player is returned to the last safe ground (sampled every 0.5 s while grounded on `SafeGround`-flagged surfaces) after a 0.4 s fade. −10 Health (0 on Lullaby/Unplugged; 20 on Deafening/Unsung). Enemies falling in die instantly (+4 Gain, "Environmental kill"). |
| Hymn Saturation (bright white Choir mist, Act V–VI) | 5 dmg/s to Plating first, then Health; a Hush Charge clears it for 6 s |
| Solar exposure (M12–M13) | Standing in direct sunlight: Plating drains 10/s, then Health 10/s; shade is safe. Clear visual: bright white light with heat shimmer, a "sizzle" SFX |
| Fire/molten steel splash | 10 dmg/s while in contact |
| Electrified water | 15 dmg/s, stuns T1 enemies inside it |
| Crushers / presses | Instant kill for enemies; for the player, 40 dmg + knockback (never instant death) |
| Explosive barrels ("**Kickback Canisters**") | 300 Explosive dmg, 450 cm radius; shootable; hurt everyone |

---

## 9. Game Feel ("Juice") Specification

| Element | Spec |
|---|---|
| Camera bob | Minimal: 0.6 cm vertical at 2.2 Hz while moving. Option: Off / Low / Full (Full = 1.5 cm) |
| Landing dip | 2–6 cm, 0.1 s, spring back |
| Weapon sway | Lag of 1.5° per 90°/s turn, max 4°; viewmodel bobs with the step cadence |
| Recoil | Visual kick on the viewmodel + small camera pitch kick (weapon-specific, auto-recovers in 0.1–0.25 s). **No** random aim drift. |
| Screen shake | Uses camera shake assets with a global multiplier (option 0–100%). Big hits: 0.25 s, low-freq. |
| Hit feedback | Hitmarker (tiny orange tick), hit SFX layered with enemy "crack" SFX, enemy flinch animations (additive), porcelain chip particles |
| Kill feedback | Shatter + gold motes, kill SFX "sting" (short, pitched to the current music key), +Gain popup on the arc |
| Hit-stop | 0.03 s on super-heavy weak-point destruction and Power Chord impact; 0.06 s on Counter |
| Speed lines | Subtle screen-space streaks above 1500 cm/s (Harrow reels, Kick Pads, dashes) |
| Low health | Heartbeat, desaturation, vignette (see core loop doc) |
| Controller rumble | Per weapon/impact; adaptive triggers on supporting pads (P2) |

---

## 10. Controls

### 10.1 Enhanced Input Actions

| Input Action | Type | Description |
|---|---|---|
| `IA_Move` | Axis2D | Move |
| `IA_Look` | Axis2D | Look |
| `IA_Jump` | Digital | Jump / double jump / release Swing Pole / jump off Grip Wall |
| `IA_Surge` | Digital | Dash |
| `IA_Fire` | Digital (hold) | Primary fire |
| `IA_ModFire` | Digital (hold) | Weapon mod (alt-fire) |
| `IA_SwapMod` | Digital | Switch active mod on the current weapon |
| `IA_Melee` | Digital | Punch / Breakdown / Counter / Power Chord |
| `IA_Harrow` | Digital | Fire Harrow (Shred / grapple / reel) |
| `IA_Equipment` | Digital | Throw current Charge (Frag / Hush) |
| `IA_SwapEquipment` | Digital | Toggle Frag ↔ Hush |
| `IA_Distort` | Digital | Distort |
| `IA_Downbeat` | Digital (hold) | Downbeat slam (air) |
| `IA_Overdrive` | Digital | Activate Overdrive |
| `IA_SuperWeapon` | Digital | Quick-select Silencer (tap) / The Axe (hold) / Larynx (double-tap) |
| `IA_WeaponNext` / `IA_WeaponPrev` | Digital | Cycle weapons |
| `IA_WeaponSlot1..9` | Digital | Direct weapon slots |
| `IA_WeaponWheel` | Digital (hold) | Weapon wheel (time slows to 20%) |
| `IA_LastWeapon` | Digital | Quick-switch to previous weapon |
| `IA_Map` | Digital | Map screen |
| `IA_Pause` | Digital | Pause menu |
| `IA_Interact` | Digital | Interact (doors, collectibles, terminals, hub NPCs) — most interactions are automatic on touch; this is for terminals/NPCs only |
| `IA_Broadside` | Digital (hold) | Mark a Broadside target for the Quietus's guns (M25–M26 only; see `14_Missions/M25_The_Staves.md` §2) |

**Mapping contexts:** `IMC_OnFoot` (default), `IMC_Mech` (Anvil Siege Frame), `IMC_Menu`, `IMC_Hub` (on-foot + interact emphasis, weapons holstered), `IMC_Cutscene` (look-only).

### 10.2 Default Keyboard & Mouse

| Action | Key |
|---|---|
| Move | W A S D |
| Jump | Space |
| Surge (dash) | Left Shift |
| Fire / Mod fire | LMB / RMB |
| Swap mod | R |
| Melee | F |
| Harrow | E |
| Equipment (throw) | Q |
| Swap equipment | Left Alt |
| Distort | C |
| Downbeat | Left Ctrl |
| Overdrive | V |
| Super weapon | G (tap Silencer / hold Axe / double-tap Larynx) |
| Weapon slots | 1–9, mouse wheel cycles |
| Weapon wheel | Hold Tab |
| Last weapon | X |
| Map | M |
| Interact | Mouse 4 / T |
| Broadside (M25–M26) | B (hold to aim, release to confirm) |
| Pause | Esc |

### 10.3 Default Gamepad (Xbox layout)

| Action | Button |
|---|---|
| Move / Look | LS / RS |
| Jump | A |
| Surge | LB |
| Fire / Mod fire | RT / LT |
| Swap mod | D-pad Up (tap) |
| Weapon inspect | D-pad Up (hold 1 s, idle; not in M25–M26) |
| Broadside (M25–M26 only) | D-pad Up (hold 0.3 s to aim, release to confirm) |
| Melee | RS click |
| Harrow | RB |
| Equipment (throw) | B (tap — on the ground or in the air) |
| Swap equipment | B (hold 0.4 s) |
| Distort | LS click |
| Downbeat | X while airborne (≥ 250 cm above ground); keep X held 0.2 s during the slam = Power Downbeat |
| Interact | X (hold 0.3 s) while grounded and a prompt is shown |
| Overdrive | D-pad Down |
| Weapon wheel | Y (hold) · tap Y = last weapon; **super weapons** sit in the wheel's center |
| Weapon cycle | D-pad Left/Right |
| Map / Pause | View / Menu |

> **Conflict rules (gamepad):** X is Downbeat only while airborne ≥ 250 cm and Interact only while grounded with a prompt visible — the two never overlap. D-pad Up resolves by duration: < 0.3 s = Swap Mod (fires on release), ≥ 0.3 s = Broadside in M25–M26, ≥ 1.0 s idle = Inspect elsewhere. B resolves by duration: tap = throw, hold 0.4 s = swap. All bindings are remappable; hold durations are adjustable in Options → Controls.

### 10.4 Aim Assist (gamepad only)
* **Slowdown:** look sensitivity ×0.55 when the crosshair passes over an enemy hitbox + 1.5° margin.
* **Magnetism:** gentle rotation toward the nearest target within 4° while the player is moving (not while stationary), strength 0.35.
* **Bullet bending:** hitscan traces within 1.2° of an enemy's weak point or head snap to it (Amplified), 2.0° (Lullaby/Unplugged), 0.6° (Deafening/Unsung).
* All values scale with the Aim Assist option (Off / Low / Standard / High).

### 10.5 Weapon Switching
* Switch time: 0.18 s for standard weapons (lower 0.08 s, raise 0.10 s). Quick-switch is a core skill (Riff Gain) — the animation must **never** exceed this budget.
* **Weapon Wheel:** 9 slots in a circle + center (super weapons). Holding it slows time to 20% (not in Unsung/Deafening: 50%).
* Switching cancels the reload of the lowered weapon, but reloads resume where they stopped on re-draw ("Pocket Reload": weapons reload in the background while holstered, 1.5× reload time).

---

## 11. First-Person Rig & Animation List (Player)

**Skeleton:** `SK_Unsung_Arms` (arms + upper torso) using a UE5-compatible hand rig (`hand_l/r`, finger chains, `weapon_r`, `weapon_l`, `harrow_socket`, `camera_bone`). Separate `SK_Unsung_Body` for legs/shadow.

| Category | Animations (`AM_` montages / `A_` sequences) |
|---|---|
| Base | Idle (per weapon), walk sway (additive), inspect (per weapon, triggered by holding Swap Mod 1 s while idle) |
| Weapons | Per weapon: Draw, Holster, Fire, Fire_Mod, Mod_Activate, Mod_Switch, Reload/Cycle (where applicable), Empty click |
| Melee | Punch_R1, Punch_L1, Punch_R2 (3-hit cycle), Power Chord (charge-glow + wind-up 0.1 s + strike), Counter (short jab with gold flash) |
| Harrow | Fire (arm thrust), Reel (chain winding), Shred (yank + rip), Heavy Shred (per T2 skeleton), Grapple (arm extended, body pulled) |
| Equipment | Throw_Frag (underhand toss from left hand), Throw_Hush (flick), Distort (both arms braced, chest vents blaze) |
| Movement | Jump, Double jump (tuck), Land_Light, Land_Heavy, Mantle, Dash (arms swept back), Grip-wall climb loop, Swing Pole grab/release, Kick Pad launch, Downbeat (fist-first dive + impact) |
| Overdrive | Activation "amp kick" (arms spread, exhaust flare, grille glow) |
| Breakdowns | Per enemy class; see bestiary. Stored as synchronized pairs: `AM_BRK_<Enemy>_<Variant>_Player` + `AM_BRK_<Enemy>_<Variant>_Victim` |
| Gestures | `GST_*` list in `02_Characters.md` |
| Damage | Hit flinch (additive, per direction), heavy hit (camera shove), death (collapse to knees → black) |

**Hands must always look huge and heavy.** Every animation should communicate mass: anticipation frames on melee, slight overshoot and settle on stops.
