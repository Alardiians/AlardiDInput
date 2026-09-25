# M19 — THE CHANCEL

| | |
|---|---|
| **Act** | IV — Deep Water, High Air (finale) |
| **Location** | **The Chancel** — a colossal Choir conversion facility in low Earth orbit: a ribbed, cathedral-shaped structure (4 km long) where captured humans are tuned en masse |
| **Kit** | `CHOIR` (100% — the first fully Choir-built interior) + `ORB` (captured human station modules embedded in it) |
| **Target duration** | 80 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M19_1 → BEAT_M19_5 |
| **New** | Pedal slot 4 (after mission); freeing captives (optional objectives), **stretcher-drone escort**, the gold vision; **Maestro Primus** final fight (killed); crowd-rise spawns |
| **Landmark** | **Earth** below through the ribbed "windows" of the Chancel — with only one Archon band left (Locrian's cracked grey) and a dark gap where the Octave has yet to sing |

---

## 1. Overview

The rescue mission. The Chancel is a place of industrial-scale horror made beautiful: vast choir-halls where thousands of captured humans stand in rows, gilding slowly, singing. The Unsung infiltrates, frees who they can, and reaches Lund in the **Tuning Font** — half-gilded, weeping gold, alive, able to *hear the Unison*. Aurelia speaks constantly from the walls and shows the Unsung a vision of the First Unison.

**Experience goals:** dread and purpose; the most "evil" place in the game without cheap shock (the horror is in the calm); optional heroism (freeing thousands); the vision that shakes the Unsung; a tense escort-escape with Lund.

---

## 2. Level Flow

```
[A01 Waste Chute Entry] → [A02 Processing Tunnels] ENC_01
   → [A03 Choir-Hall Alpha] ENC_02 (+ optional: destroy 3 Resonance Organs → free captives)   (+CM_M19_01)
   → [A04 The Vision Wall] CIN_M19_Vision
   → [A05 Choir-Hall Beta] ENC_03 (crowd-rise; + optional Resonance Organs)   (+CM_M19_02)
   → [A06 The Tuning Font] MINI-BOSS: MAESTRO PRIMUS (final) → CIN_M19_Lund
   → [A07 The Collapse (escape with Lund on a stretcher-drone)] ENC_04 FINALE → exit
```

### A01 — Waste Chute Entry
* The Drop Coffin can't breach the Chancel's hull; Tamsin flies the Quietus close and the Unsung spacewalks (a short exterior traversal along the Chancel's ribs with Harrow Anchors, Earth vast below — no sound — only the Hymn, felt through the Rig) to a **waste chute** (an organic sphincter-like opening of porcelain petals) — the Unsung forces it open and drops inside.

### A02 — Processing Tunnels, ENC_M19_01
* **Space:** organic-architectural tunnels: ribbed walls of porcelain and bone, floors of smooth gold-veined porcelain, conveyors of light carrying unconscious humans on floating biers (non-hostile, non-damageable) deeper into the facility. The Chancel's own "workers" — Choristers and Cantors — tend them.
* Aurelia's voice begins, from the walls (soft, constant, never taunting): "*I'm glad you came. I hoped you would.*"

### A03 — Choir-Hall Alpha, ENC_M19_02
* **Space:** a vast hall (120 × 80 m, 60 m tall): rows of **captives** standing in grids (thousands; instanced crowd), at different stages of gilding, singing softly. Walkways and balconies at 8 m and 16 m between the rows; three **Resonance Organs** (colossal organ-pipe clusters, 2000 HP each) that sing the tuning Hymn into the hall.
* **Optional objective:** destroy all 3 Resonance Organs → the hall's captives (those not yet fully gilded — ~70%) **collapse, freed**; a Static rescue team (Okafor's squad, arriving by shuttle through a breach) starts evacuating them after the mission (shown in the hub later). Reward per freed hall: +3 Brass and a **Bloodrush** pickup at the hall's center, +10 Gain per Organ, and a big emotional beat.
* The arena happens on the walkways and floor aisles between the rows (captives are non-damageable; bullets pass through them with a porcelain tick).

### A04 — The Vision Wall
* A narrow gallery whose walls are pure choir — faces and gold. When the Unsung passes, the wall reaches out: `CIN_M19_Vision` (gold-rendered: the First Unison on Solace; a lone armored figure screaming; Aurelia: "*That was you. All alone. For so long.*"). The Unsung on one knee; control returns after 1 s; the Arrhythm HUD pulses wildly for 10 s (cosmetic).

### A05 — Choir-Hall Beta, ENC_M19_03
* **Space:** a second hall (100 × 100 m, a circular amphitheater of captives arranged in concentric rings), with 3 more optional Resonance Organs.
* **Crowd-rise:** mid-arena, a section of captives that were already fully tuned **turns hostile** (`SPN_CrowdRise` — they become Thralls in the gilded "captive" skin), surging toward the player. Scripted, readable (their halos flare cyan before they move).

### A06 — The Tuning Font: MINI-BOSS MAESTRO PRIMUS (final)
* **Space:** the Chancel's heart: a circular chamber (60 m) around a great **font** (a basin of liquid gold light, 20 m across) in which Lund is suspended upright in a column of light. Galleries at 10 m; four organ-pipe pillars; Harrow Anchors on the pillar crowns.
* **Fight:** **Maestro Primus** (returns from M14) — `ENM_Maestro` moveset, **7000 HP**, larger Score (800 HP), Boarding Hymnfall every 20 s. **It dies here**, dropping a big loot fountain.
* `CIN_M19_Lund`: the column of light breaks; the Unsung catches Lund. Half-gilded, golden tears: "*Solace. The path to the heart of it... goes through Solace. You... you were born there. They're all— your people are all in there.*"

### A07 — The Collapse, ENC_M19_04 (FINALE)
* **Escape:** the Chancel starts tearing itself apart (the Font's death destabilizes it). Lund is placed on a **stretcher-drone** (a Static med-drone that followed the Unsung in; it follows the player at 2 m, hovers over obstacles, **cannot be damaged** — enemies ignore it; it's an emotional escort, not a failure condition).
* **Route:** back through collapsing corridors and a final hangar-hall where the Quietus hovers outside a torn opening; the finale arena is the hangar while the Quietus's ramp lowers (timed: the ramp takes 90 s; survive and clear).
* Exit: the Unsung carries Lund up the ramp as the Chancel breaks apart behind them.

---

## 3. Encounters

```
ENC_M19_01  "Processing Tunnels"   Arena: A02 junction chamber (40 x 40 m; conveyor-of-light lanes; ribs as cover)   Seals: petal membranes
  Music: MUS_M19_Combat_A           Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6, Cantor x1, Thrall x8
  W2 AliveBelow(5):       Fugue x2, Echo x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 AliveBelow(4): Gilded Bellwether x1, Siren x2, Chorister x3
  Pickups: Health S x8, Plating S x6, ammo L x1 (Charge, Rounds)
```

```
ENC_M19_02  "Choir-Hall Alpha"     Arena: A03 (aisles between captive grids; walkways 8/16 m)   Seals: 4
  Music: MUS_M19_Combat_B           Reward: 2 Brass + loot fountain (+3 Brass + Bloodrush if all 3 Organs are destroyed)
  Optional objective: 3 Resonance Organs (2000 HP each)
  W1 OnStart:             Maestro x1, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Seraph x2, Bulwark x3, Cantor x1
  W3 AliveBelow(4):       Carillon x1, Echo x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Profundo x1, Gilded Crescendo x1, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
```

```
ENC_M19_03  "Choir-Hall Beta"      Arena: A05 (100 m circular; concentric captive rings; central dais)   Seals: 4
  Music: MUS_M19_Combat_B           Reward: 2 Brass + loot fountain (+3 Brass + Bloodrush if all 3 Organs are destroyed)
  Optional objective: 3 Resonance Organs
  W1 OnStart:             Acolyte x8 (the Consonance's wardens), Zealot x4, Chorister x3
  W2 AliveBelow(5):       CROWD RISE — Thrall x16 (captive skin, from ring 3), Bloated Thrall x2
  W3 AliveBelow(6):       Maestro x1, Requiem Knight x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(4): Carillon x1, Gilded Bellwether x1, Seraph x2, Chorister x4
  Pickups: Health M x3, Plating M x2, ammo L each, Harrow Spool x3
  Power-up: AMP (central dais)
```

```
BOSS_MaestroPrimus_Final  "The Tuning Font"   Arena: A06   (Maestro, 7000 HP, Score 800 HP)
  Music: MUS_BOSS_Maestro (reprise — "Final Movement")
  Boarding Hymnfall every 20 s: 5 T1 + 1 T2
  Reward: 3 Brass + big loot fountain
```

```
ENC_M19_04  "The Collapse" (FINALE)  Arena: A07 hangar-hall (80 x 50 m; collapsing ribs; opening to space with the Quietus)   Seals: n/a   Timer: 90 s ramp
  Music: MUS_M19_Escape             Reward: loot fountain on the ramp
  Continuous: Hymnfall waves every 15 s (T1 x6 + one T2 rotating: Crescendo, Seraph, Siren, Bellwether)
  At T+60: Profundo x1 (Hymnfall at the hangar's far end)
  Completion: timer ends AND the player reaches the ramp (remaining enemies die as the hall collapses)
  Pickups: Health M x2, Plating M x2, ammo L each
  Stretcher-drone: invulnerable, follows the player
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M19_Spacewalk` | Exterior traversal along the Chancel's ribs; silent vacuum; Earth below |
| `EVT_M19_Aurelia` | Aurelia's continuous voice from the walls (a 20-line pool; never repeats; pauses during combat) |
| `EVT_M19_Organs` | Optional: destroying Resonance Organs frees captives (they collapse; some weep; some reach out) |
| `EVT_M19_Vision` | `CIN_M19_Vision` |
| `EVT_M19_CrowdRise` | Fully tuned captives turn hostile |
| `EVT_M19_Lund` | `CIN_M19_Lund` |
| `EVT_M19_Collapse` | Escape with the stretcher-drone |
| Hub | Pedal slot 4; Lund in the med-bay (hub State 5) |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Bootleg Tape #9** (Pit Trial: *"Liberation"* — protect captive-props from waves) | A02: on a floating bier among the conveyors — the tape is in a captive's pocket (interact) | Violet glow on one bier |
| S2 | **Effigy: Maestro Primus** | A06: the Font's rim after the fight | — |
| S3 | **Effigy: The Chancel** (a tiny carving of the structure, made by a captive) | A05: in a captive's hand in ring 1 (interact — the captive lets go) | — |
| S4 | **Master: *"Free Radio"* by THE PRISONERS** | A03: a captured Static soldier's collar, still faintly playing | Music from the rows |
| S5 | **Reprise** | A01: during the spacewalk, a detached rib section (Harrow Anchor chain off the path) | — |
| S6 | **Rig Core** | A04: behind the Vision Wall's gallery, a narrow gap in the choir-wall (dash through as the faces part) | Violet light between faces |
| S7 | **Brass Cache #1** | A02: a crushed human shuttle module embedded in the wall | — |
| S8 | **Brass Cache #2** | A05 (after `CM_M19_02`) | — |
| S9 | **Sounding Station #1** | A02: a human station module's survey console | — |
| S10 | **Sounding Station #2** | A05 | — |
| S11–S16 | **Archive Stones** | A02, A03, A04, A05, A06 (×2) | — |

**Archive entries:** `ARC_Loc_Chancel`, `ARC_Hist_ConversionProcess`, `ARC_Mem_FirstUnison` (vision), `ARC_Char_Lund_Tuned`, `ARC_Boss_MaestroPrimus_Final`, `ARC_Obj_Solace` (Lund's first words about it).

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy all 6 Resonance Organs (free both halls) |
| 2 | Destroy Maestro Primus's Score before its first Resurrection Crescendo |
| 3 | Escape the Collapse without Health dropping below 50% |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M19_Explore` — "**Chancel**" | Tunnels | Sacred, serene choir — the most beautiful and most horrifying choir writing in the game; the band enters only in combat |
| `MUS_M19_Combat_A` — "**Intake**" | ENC_01 | 165 BPM |
| `MUS_M19_Combat_B` — "**Liberation**" | ENC_02–03 | Anthemic; each destroyed Organ removes a choir layer and adds a guitar layer |
| `MUS_BOSS_Maestro` — "**Final Movement**" | Mini-boss | Reprise, darker |
| `MUS_M19_Escape` — "**Carry Him Home**" | ENC_04 | Urgent, emotional, 180 BPM |
| Aurelia VO | All | Close-miked, intimate, harmonized ×4 |
| Vacuum | Spacewalk | Only the Unsung's breath, servos, and heartbeat |

---

## 8. Art & Lighting

* **Palette:** pure Choir — porcelain white, gold, soft pale light from everywhere (no shadows in the halls — unsettling) — plus Earth's blue glow through ribbed windows; the Unsung is the only dark, warm thing in the space.
* **Key props:** ribbed CHOIR architecture kit (the most complete Choir kit — reused in Acts V–VI), floating biers & light-conveyors, captive crowd (VAT, gilding stages via material parameter), Resonance Organs (destructible), Vision Wall (faces), the Tuning Font (hero), stretcher-drone, exterior ribs.

---

## 9. New Assets Required (P1)

Full Choir interior kit (`CHOIR_ARCH`: ribs, vaults, floors, walkways, membranes), captive crowd skin (gilding stages), `BP_ResonanceOrgan`, `BP_StretcherDrone`, Tuning Font set, `SK_Lund_Tuned` (half-gilded), gold-vision post-process (`PP_GoldVision`), exterior Chancel hull (for the spacewalk), `SPN_CrowdRise` controller.
