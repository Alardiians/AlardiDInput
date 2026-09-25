# 19 — UI / UX & HUD

## 1. UI Style

**Theme: "Road-case & Rig."** Player-side UI looks like **touring gear and the Unsung's Rig**: black iron frames, scuffed stencil type, VU meters, amp knobs, stompbox switches, gaffer-tape labels, ember-orange backlights. Choir-side UI (boss bars, Choir text) uses **gold serif lettering on thin white rings**.

| Element | Style |
|---|---|
| Primary font (HUD numbers, labels) | Condensed industrial grotesque, stencil variant for headers (e.g., a free font like *Oswald* / *Big Shoulders Stencil* — confirm licenses) |
| Secondary font (body text, Archive) | Clean humanist sans (e.g., *Inter*) |
| Choir font (boss names, Choir inscriptions) | High-contrast gold serif (e.g., *Cormorant*) |
| Oreth glyphs | Custom atlas `T_OrethGlyphs_Atlas` |
| Colors | Tokens from `17_Art_Direction.md` §2 — UI never uses cyan |

---

## 2. HUD Layout (16:9; safe zones 5%)

```
┌─────────────────────────────────────────────────────────────────────────────────┐
│                     [ COMPASS RIBBON: objective ◆, collectibles ◇, SS ⌖ ]        │
│  [BOSS BAR: ━━━━━━━━┃━━━━━━━━┃━━━━━━━━  IONIAN — THE RAPTURE ]  (bosses only)      │
│                                                                                 │
│ [Rig boot text / objective]                                   [Comms portrait]  │
│                                                                                 │
│                                    ╭─╮                                          │
│                     Harrow ⛓⛓⛓   ─( + )─   ▮▮ Surge                              │
│                                    ╰─╯   (crosshair + Gain arc + Power Chord ◉)  │
│                                                                                 │
│                                                                                 │
│ ┌──────────────┐                                            ┌──────────────────┐│
│ │ ♥ 145  ▓▓▓▓▓░│  (Health, red, with Arrhythm pulse)        │ ▣ SHELLS  18/32 ││
│ │ ⛨  80  ▓▓▓░░░│  (Plating, green)                           │ [weapon icon]    ││
│ │ GAIN ▮▮▮▮▮▯▯ │  (VU meter strip)                           │ Mod: FRAG SLUG ● ││
│ │ [Frag ●][Hush ○] [Distort ◔ 12s]                           │ Null ◆◆◇ Grudge ▲││
│ └──────────────┘                                            └──────────────────┘│
└─────────────────────────────────────────────────────────────────────────────────┘
```

### 2.1 Elements
| Element | Spec |
|---|---|
| **Crosshair** | Weapon-specific (small, orange-white). Hit marker ticks; kill = a brief "X" flash. |
| **Gain arc** | Lower-half ember arc around the crosshair; fills with Gain; pulses at 100 ("[V] OVERDRIVE" text flashes above it once). |
| **Power Chord** | Small fist icon under the crosshair, glows when charged (1 or 2 pips). |
| **Harrow pips** | 3 chain-link pips left of the crosshair; the regenerating one shows a radial fill. Predicted Harrow outcome icon (SHRED / REEL / GRAPPLE) appears when aiming at a valid target. |
| **Surge pips** | 2 bars right of the crosshair. |
| **Health / Plating** | Bottom-left: numbers + bars; Health bar's frame carries the **Arrhythm** pulse (irregular); Plating green. Low Health: frame cracks, red vignette. |
| **Gain VU strip** | Bottom-left under Health/Plating — a VU meter (redundant with the arc, readable at a glance). |
| **Equipment** | Frag and Hush icons (active one large) with radial cooldowns; Distort cooldown. |
| **Ammo** | Bottom-right: current weapon ammo / pool max, weapon icon, active mod name + mod cooldown dot; super weapon ammo (Null Cells ◆, Grudges ▲). |
| **Compass ribbon** | Top: objective marker, Sounding Station, nearby collectibles (with *Resonance Sense*), Fuse doors, arena status. |
| **Boss bar** | Top-center: gold serif name + title, segmented by phase thresholds. |
| **Rig boot / objective text** | Top-left: typewriter-style orange monospace for Rig unlocks; objective lines in stencil. |
| **Comms portrait** | Top-right: speaker portrait (Vire, Lund, Wren, Harlan…) with a waveform animation while speaking; Tamsin shows a ✋ icon. |
| **Damage direction** | Screen-edge arcs (red), stronger for Piercing. |
| **Off-screen threat** | Orange chevrons at the screen edge for incoming off-screen attacks (with direction); gold chevron for off-screen parryables. |
| **Enemy UI** | No floating health bars (DOOM-style clean screen). Weak points glow gold; Faltering enemies glow ember; optional "last enemies" outline. Bosses/titans use the boss bar. |
| **Pickup toasts** | Right side, stacked, 2 s: "+25 PLATING", "BRASS +2", "HEART SHARD". |
| **Power-up timer** | Under the crosshair as a draining ring in the power-up's color, with icon. |
| **Overdrive** | HUD shifts to ember/red; screen-edge static; a draining bar replaces the Gain arc. |
| **Mech HUD** | Separate cockpit-diegetic HUD (amber CRT style): structure, weapon heat, rocket locks, Blast Horn cooldown, repair crate markers. |

### 2.2 HUD Options
Full / Minimal (hides ammo & equipment when full/ready) / Off (cinematic). HUD scale 75–125%. HUD color presets (colorblind-safe). Crosshair picker. Each element toggleable.

---

## 3. Menus

### 3.1 Front End
* **Title screen:** the Silent Vault in darkness; a faint ember pulse; press any key → the chord, the visor ignites, the title burns in.
* **Main menu:** Continue · Campaign (new / load, difficulty) · Mission Select (after progress) · Encore (post-game) · The Pit (from the hub only) · Options · Extras (Archive, Masters, Effigies, Credits) · Quit.
* **Difficulty select:** 6 skulls → 6 "amp knobs" (Lullaby → Unsung), each with a one-line joke description:
  * **Lullaby** — "*Sing me to sleep.*" (story)
  * **Unplugged** — "*Acoustic set.*" (easy)
  * **Amplified** — "*Turn it up.*" (normal)
  * **Overdriven** — "*Past the red line.*" (hard)
  * **Deafening** — "*Your ears will bleed.*" (nightmare)
  * **Unsung** — "*One life. No encore.*" (permadeath)

### 3.2 Pause Menu
Resume · **Rig** (upgrades: Brass / Rig Cores — field upgrades) · **Pedalboard** · **Map** · **Challenges** (mission challenges + masteries) · **Archive** · **Tabs** (replays only) · Options · Restart Checkpoint · Quit to Hub/Menu.

### 3.3 Map ("Sounding Map")
* A 3D holographic map (rotatable, zoomable, per-floor slicing) rendered as a **sonar scan**: areas the player has visited appear as green-white wireframe; unvisited areas are revealed by **Sounding Stations** (a sonar sweep animation).
* Icons: objective, Fuse doors (shape-coded), collectibles (violet; ghosted if collected), Choir Masses, Requiem Gate, Sounding Stations, player position & facing.
* Legend & filters. Collectible counters per mission.

### 3.4 Hub Interfaces
| Interface | Presentation |
|---|---|
| **Armory (Wren)** | 3D weapon on a workbench; mods shown as tabs; upgrade nodes as **amp knobs** that turn when purchased; Brass counter; Mastery challenge progress bars |
| **Rig Bay** | The Unsung in the gantry (3D); 6 branches as columns of stompbox-like switches; Rig Core counter |
| **Heart Chamber** | Close-up of the Arrhythm's cage; three tracks (Vitality / Plating / Arsenal) as vertical meters with 6 segments; perks at steps 3 & 6 |
| **Pedalboard** | A literal pedalboard: 2–4 slots; pedals as physical stompboxes with hand-painted art; Boutique challenge status on each |
| **Listening Room** | A turntable + record crate UI: flip through Masters (cover art, band bio, liner notes by Pops) |
| **Effigy Gallery** | Walk the gallery; interact to rotate/zoom and read descriptions |
| **Solar Map (Bridge)** | Holographic solar system: missions as nodes on planets/moons; the Aureole bands around Earth; mission info cards (collectibles found / total, challenges, best time) |
| **Wardrobe** | Rig Finishes, weapon finishes, helmets — 3D preview |

---

## 4. Feedback & Onboarding

* **Rig boot prompts** (see `07` §11): one-line, input-glyph, non-pausing.
* **Contextual hints:** after 3 deaths to the same enemy type, a 1-line hint appears on the death screen ("*Crescendos can't turn while charging — dash SIDEWAYS.*").
* **Death screen:** quick (≤ 1 s to input), shows the killer's name and a hint; "Retry from checkpoint" is the default button.
* **Mission complete screen:** time, kills, secrets found X/Y (by type), challenges, Brass/Rig Cores earned — styled as a **setlist** taped to a stage floor.
* **Loading screens:** Radio Free Static intro plays; screen shows mission title, location, a piece of concept art, and a gameplay tip; a "sound meter" progress bar.

---

## 5. Accessibility (UI-side; full list in `23_Difficulty_Balance_Accessibility.md`)

* **Colorblind modes:** Protanopia, Deuteranopia, Tritanopia remaps for all tokens (enemy threat / parry / player / health / plating / secret), plus **shape-coding always on** (sphere vs. ring, pickup silhouettes, Fuse shapes).
* **Subtitles:** on by default; size (S–XXL), background opacity, speaker names & colors, **directional sound captions** ("[Gold chime — left]", "[Crescendo charging — behind]").
* **Visual telegraph assist:** optional ground indicators for all AoE attacks; gold-strike indicator outline; Locris "real strike" marker.
* **Reduce flashing:** caps bloom spikes, removes screen-edge strobes, softens Hymnfall and Silencer flashes, replaces Radiance/Octave Nova whiteouts with a colored overlay.
* **Motion:** FOV, head bob off, camera shake slider, motion blur off, reduce speed lines.
* **HUD & text scaling**, high-contrast HUD mode.
* **Controls:** full remapping; hold/toggle options (weapon wheel, scope, Shredder spin); adjustable hold durations for multi-use buttons; aim assist levels; auto-mantle; "Dedicated Counter button".
* **Sign language:** Tamsin's signing is always subtitled.

---

## 6. UI Tech Notes (UE5)

* **UMG** + **CommonUI** (for input routing, platform glyphs, focus navigation on gamepad).
* HUD widgets bind to gameplay via lightweight **view-model** objects (`UHBHUDViewModel`) updated by components (no Tick-polling in widgets); use MVVM plugin if available.
* Crosshair/Gain arc drawn with materials (retainer box + material parameters) for performance.
* All strings in **String Tables** (localization-ready); no hard-coded text.
* Input glyphs switch automatically between keyboard/mouse and gamepad.
