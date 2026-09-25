# M04 — RAPTURE

| | |
|---|---|
| **Act** | I — First Noise (finale) |
| **Location** | **Halcyon**, coastal megacity: Harbor Bridge, the elevated highway interchange ("the Stack"), Tower 9 megablock, the Plaza of Communion, **the Halcyon Bowl** |
| **Kit** | `CITY` + `CHOIR` 20% → 90% |
| **Target duration** | 80 min |
| **Priority** | **P0 — Act I Alpha finale** |
| **Story beats** | BEAT_M04_1 → BEAT_M04_5 |
| **New** | Hammerfall, Power Chord, Arc Beam mod, Hymn Pylons, power-ups (Amp), allied Static soldiers; enemies Seraph, Canon; **Boss: Ionian, the Rapture** |
| **Landmark** | **The Ionian Spire** — a 2 km spire of gold and white growing from the Halcyon Bowl, crowned with a sun-halo; beams of warm light sweep the city like searchlights |

---

## 1. Overview

Earth, at last. The first time the player sees what the Hymn does to a whole city. Halcyon is **beautiful and wrong**: a warm, golden, euphoric light bathes everything; the ambient Hymn is in a *major key*; hundreds of thousands of Tuned people stand in the streets smiling up at the Spire. The Static are clinging on in pockets, blasting music from vehicles.

**Experience goals:** scale (the city, the crowds, the Spire); first allies fighting beside the player; the Hammerfall's power; learning to snipe weak points (Seraphs, Canons); the first Archon — a spectacular, readable boss; and an emotional payoff: the crowd waking up.

**Crowd rule (important):** passive Tuned civilians (`NPC_TunedCivilian`, instanced crowd agents) are **non-damageable scenery**. Bullets pass through them with a soft porcelain "tick" VFX and no gore; explosions do not affect them; they sway and sing. They are sad, not targets. The player can walk through dense crowds (they part slowly, soft collision). No mechanic ever asks the player to hurt them.

---

## 2. Level Flow

```
[A01 Anchor Platform] → [A02 Harbor Bridge] ENC_01
   → [A03 The Stack (highway interchange)] ENC_02 (Okafor + allies)
   → [A04 CDF Checkpoint] (Hammerfall; Seraph intro) ENC_03
   → [A05 Tower 9 megablock] (Arc Beam mod) ENC_04 (atrium)
   → [A06 Plaza of Communion] (Power Chord boot, Hymn Pylon, Canon intro) ENC_05
   → [A07 Bowl Concourses] (+CM_M04_01 in the players' tunnel) ENC_06 "Upper Concourse"
   → [A08 The Pitch] BOSS: IONIAN → CIN_M04_Waking
```

### A01 — Anchor Platform
* The smoking wreck of the climber car. The ocean platform: cranes, cargo stacks, the Tether's anchor housing (now silent). Across the water: Halcyon's skyline, the Ionian Spire, the Aureole spanning the sky like an arch. A 90-second exploration walk to the bridge (Radio Free Static intro plays here).

### A02 — Harbor Bridge, ENC_M04_01
* **Space:** a 2 km suspension bridge (playable section 250 m) with 8 lanes, abandoned cars and buses, a collapsed central span (Harrow Anchors on the suspension cables to cross), and a toll plaza at the city end (arena).
* **Arena:** the toll plaza (50 × 40 m): toll booths, jersey barriers, an overturned bus, a Static roadblock with a sound truck still blaring music (environmental story: a Static squad was here; their truck still plays).

### A03 — The Stack, ENC_M04_02
* **Space:** a four-level highway interchange: ramps curve over each other at 8–10 m intervals. Kick Pads (Static-installed) and dropped ramps connect levels.
* **Allies:** Sergeant **Bo Okafor** and 6 Static soldiers (`NPC_StaticSoldier`) are pinned down behind a barricade of buses on Level 2. The arena begins when the Unsung arrives above them.
* **Ally rules:** allies are **invulnerable**, stay behind their barricade, shoot at 25% damage effectiveness, and bark constantly ("*Breaker's here!*"). They never steal kills of Faltering enemies (they stop shooting Faltering targets). After the arena, Okafor delivers `COM_M04_05`: "*Breaker! You are exactly as scary as advertised. The Bowl's two klicks north. There's a CDF checkpoint on the way — they had heavy weapons.*"

### A04 — CDF Checkpoint, ENC_M04_03
* **Space:** a fortified highway checkpoint (sandbags, gun emplacements, a two-story command post, an armory container).
* **Hammerfall:** in the armory container (`PKP_Weapon_Hammerfall`). Prompt: `HAMMERFALL — rockets devastate groups and flyers`.
* **Seraph intro:** after the pickup, a **Seraph** descends and hovers over the checkpoint (with Thralls only). Prompt: `Shoot a SERAPH's WING-PIPES to bring it down` (the Tack Scope highlight appears on the pipes).

### A05 — Tower 9 Megablock, ENC_M04_04
* **Space:** a 60-story brutalist residential block. The path enters on floor 12 from the highway, cuts through apartments and corridors, and descends through the block's central **atrium** (a 40 × 40 m void, 10 stories tall, with balconies on every floor) to street level.
* **Storytelling:** families' belongings arranged in neat symmetrical piles in every apartment; Tuned residents standing motionless at windows facing the Spire (non-hostile); a child's bedroom with drawings of the "Breaker" (the Static's legend is spreading); a Static safehouse apartment with mattresses on the windows and a turntable.
* **Mod Crate: Static Rifle — Arc Beam** in the Static safehouse. Prompt: `ARC BEAM breaks HARMONY LINKS instantly`.
* **Atrium arena:** fight across the balconies (floors 8–12) and down to the lobby.

### A06 — Plaza of Communion, ENC_M04_05
* **Space:** a vast plaza (120 × 80 m) before the Bowl's main gates: Consonance banners 30 m tall, food trucks, merch stands, a giant screen showing Aurelia's face (smashable), **thousands of passive Tuned** standing in rows facing the stadium. The combat space is the plaza's raised **processional avenue** (a 25 m wide elevated walkway, 3 m above the crowd, with side platforms) and the stadium's grand staircase.
* **Power Chord boot:** an entrance skirmish with 4 Thralls around a **Hymn Pylon**; after the player's next Breakdown: `RIG SUBSYSTEM RESTORED: POWER CHORD` → prompt: `Breakdowns charge a POWER CHORD — [F] with a charge to punch through PYLONS, SHIELDS and ARMOR`. The Pylon is the target.
* **Canon intro:** the first **Canon** stands at the top of the grand staircase. Prompt: `CANON — destroy its BELL-MOUTHS to silence its artillery`.
* **Power-up introduction:** an **Amp** on a pedestal on the avenue (visible from the arena entrance).

### A07 — Bowl Concourses, ENC_M04_06 "Upper Concourse"
* **Space:** the stadium's circular concourses (3 levels), filled with swaying crowds. The player's route climbs to the **VIP level**, where the Choir has sealed the lounges → arena (40 × 30 m lounge + terrace overlooking the pitch; the boss is visible, dormant, from here).
* **Optional:** `CM_M04_01` Choir Mass in the **players' tunnel** (reachable from the lower concourse).
* **Breather before the boss:** a quiet corridor (the stadium's trophy hall) with the loot fountain, a Sounding Station, and Lund on comms: "*Whatever that thing is, the crowd is feeding it. Their song. Break whatever's channeling it.*"

### A08 — The Pitch: BOSS
* Full boss spec: `10_Bosses.md` §1 (Ionian, the Rapture). Arena summary: 100 × 60 m pitch, central stage 20 × 20 × 3 m, 4 Choir Organs at the corners, cover debris, Kick Pads to the lower-stand lip (6 m), Harrow Anchors on the light towers.
* `CIN_M04_Ionian` on entering the pitch; fight; Boss Breakdown; `CIN_M04_Waking`.

---

## 3. Encounters

```
ENC_M04_01  "Toll Plaza"            Arena: A02 (50 x 40 m, booths, overturned bus 3 m)   Seals: 2
  Music: MUS_M04_Combat_A            Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Tuned commuters), Trooper x3
  W2 AliveBelow(4):       Crescendo x1, Chorister x2, Thrall x4
  Final W3 AliveBelow(3): Ophan x1, Vesper x5, Thrall x6
  Pickups: Health S x6, Plating S x3, Shells L x1, Charge S x2
```

```
ENC_M04_02  "The Stack"             Arena: A03 (3 highway levels, 70 x 50 m footprint, levels 8-10 m apart)   Seals: 3
  Music: MUS_M04_Combat_A            Reward: 1 Brass + loot fountain
  Allies: Okafor + 6 Static soldiers (Level 2 barricade)
  W1 OnStart:             Trooper x5 (Level 3 overpass), Thrall x8 (Level 2)
  W2 AliveBelow(5):       Chorister x4 (Hymnfall on Levels 1 & 3), Bulwark x2
  W3 AliveBelow(4):       Crescendo x2 (Level 1 ramp — charge up the ramp), Thrall x6
  Final W4 AliveBelow(3): Ophan x1, Cantor x1, Trooper x3, Thrall x6
  Pickups: Health M x1, Health S x6, Plating M x1, Shells L x1, Rounds L x1, Harrow Spool x2
```

```
ENC_M04_03  "Checkpoint"            Arena: A04 (45 x 35 m, command post 6 m, gun pits)   Seals: 2
  Music: MUS_M04_Combat_B            Reward: 1 Brass + loot fountain
  W1 OnStart (after Hammerfall pickup): Seraph x1 (Hymnfall above), Thrall x6          [Seraph intro]
  W2 KilledTag(Seraph):   Vesper x6, Trooper x3, Thrall x4
  Final W3 AliveBelow(3): Seraph x1, Crescendo x1, Chorister x2, Thrall x4
  Pickups: Ordnance L x1, Health S x4, Plating S x2, Rounds S x2
```

```
ENC_M04_04  "Tower 9 Atrium"        Arena: A05 (40 x 40 m void, balconies floors 8-12, lobby)   Seals: 4
  Music: MUS_M04_Combat_B            Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x4 (balconies), Thrall x8 (lobby + balconies)
  W2 AliveBelow(4):       Cantor x1 (floor 11), Bulwark x2, Trooper x2
  W3 KilledTag(Cantor) OR TimeElapsed(40s): Seraph x1, Vesper x6
  Final W4 AliveBelow(3): Crescendo x1 (lobby), Chorister x3, Thrall x6
  Pickups: Health M x1 (lobby fountain), Health S x6, Plating S x4, Ordnance S x2, Charge S x2
```

```
ENC_M04_05  "Plaza of Communion"    Arena: A06 avenue + grand staircase (100 x 25 m + 40 x 30 m stairs, 3 tiers)   Seals: 3
  Music: MUS_M04_Combat_C            Reward: 2 Brass + big loot fountain
  Pre-arena: Hymn Pylon + Thrall x4 (Power Chord tutorial)
  W1 OnStart:             Canon x1 (top of the stairs)                                      [Canon intro]
                          Thrall x8, Trooper x2
  W2 KilledTag(Canon) OR AliveBelow(3): Seraph x2, Chorister x3, Hymn Pylon x1 (activates mid-avenue)
  W3 AliveBelow(4):       Crescendo x1, Bulwark x2, Cantor x1, Thrall x6
  W3b TimeElapsed(25s):   Thrall x6
  Final W4 AliveBelow(4): Canon x1, Ophan x1, Chorister x3, Thrall x8
  Pickups: Health M x2, Plating M x2, Ordnance L x1, Shells L x1, Harrow Spool x2
  Power-up: AMP (avenue center)
```

```
ENC_M04_06  "Upper Concourse"       Arena: A07 VIP lounge + terrace (40 x 30 m, bar counters, glass walls)   Seals: 3
  Music: MUS_M04_Combat_C            Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Tuned VIPs in formalwear), Chorister x3
  W2 AliveBelow(4):       Seraph x1, Bulwark x2, Trooper x3
  Final W3 AliveBelow(3): Crescendo x1, Cantor x1, Chorister x3, Thrall x6
  Pickups: Health M x1, Health S x4, Plating M x1, Ordnance S x2, Shells S x2
```

**Boss:** `BOSS_Ionian` — see `10_Bosses.md` §1. Resource adds every 25 s (Thralls in fan gear from the stands).

**Optional:** `CM_M04_01` (players' tunnel): Thrall x12, Chorister x4, Seraph x1, Crescendo x1 over 3 waves.

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M04_Skyline` | First city vista from the anchor platform; the Spire's light beams sweep the water |
| `EVT_M04_Okafor` | Allies pinned; rescue; Okafor's line |
| `EVT_M04_ScreenSmash` | The giant plaza screen showing Aurelia can be destroyed (any weapon) — Aurelia's voice cuts out mid-word; optional, +2 Gain, Static soldiers cheer |
| `EVT_M04_Ionian` | `CIN_M04_Ionian` |
| `EVT_M04_Waking` | `CIN_M04_Waking` — the crowd collapses and wakes; the first Aureole band dies; Harlan weeps on air; Vire salutes |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Tab #1: "Big Head"** (enemies' heads ×3 size) | A02: inside the overturned bus at the toll plaza — Harrow-yank the bus door off (Harrow Anchor on the door handle) | Violet tag on the bus |
| S2 | **Heart Shard #3** | A03: top of a highway sign gantry above Level 4, reached by a Kick Pad hidden behind a jackknifed truck | Violet glow above the sign; the Kick Pad's orange ring visible between the trailer's wheels |
| S3 | **Effigy: Crescendo** | A04: command post roof, in a sniper nest | — |
| S4 | **Effigy: Ophan** | A05: an apartment on floor 12 whose door is barricaded — go around via the exterior window ledge (Grip Wall on the balcony) | Violet light through the barricade gaps |
| S5 | **Master: *"Halcyon Days"* by BRUTALIST** | A05: the Static safehouse's turntable (interact) | Music playing |
| S6 | **Reprise** | A06: under the processional avenue (Downbeat through a cracked grate in the side platform) | Orange-fissured grate |
| S7 | **Rig Core** | A07: the commentary box high above the lower concourse, via a Harrow Anchor on the stadium roof truss | Violet glow in the box window |
| S8 | **Brass Cache #1** | A03: a Static stash in a road maintenance van | — |
| S9 | **Brass Cache #2** | A07: players' tunnel, after the optional Choir Mass | — |
| S10 | **Sounding Station #1** | A03 Level 4 | — |
| S11 | **Sounding Station #2** | A07 trophy hall | — |
| S12–S16 | **Archive Stones** | A01, A03, A05 (×2), A07 | — |

**Archive entries:** `ARC_Loc_Halcyon`, `ARC_Loc_HalcyonBowl`, `ARC_Hist_Communion`, `ARC_Char_Okafor`, `ARC_Enemy_Seraph`, `ARC_Enemy_Canon`, `ARC_Haz_HymnPylon`, `ARC_Weapon_Hammerfall`, `ARC_Rig_PowerChord`, `ARC_Archon_Ionian`, `ARC_Obj_Aureole`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Ground 3 Seraphs by destroying both wing-pipes |
| 2 | Destroy a Hymn Pylon with a Power Chord while an enemy is Anthem-buffed nearby |
| 3 | Defeat Ionian without any Choir Organ surviving longer than 3 minutes into the fight |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M04_Explore` — "**Golden Hour**" | City traversal | Major-key choir (unsettlingly happy) under minor-key down-tuned guitar drones — the two fight each other |
| `MUS_M04_Combat_A` — "**Traffic**" | ENC_01–02 | 160 BPM, punk-metal energy |
| `MUS_M04_Combat_B` — "**High Rise**" | ENC_03–04 | 150 BPM groove |
| `MUS_M04_Combat_C` — "**Communion**" | ENC_05–06 | 170 BPM |
| `MUS_BOSS_Ionian` — "**Rapture**" | Boss | See boss doc |
| Crowd singing | Plaza, concourses, stands | Spatialized crowd-choir beds (major key, gently swaying tempo), ducked in combat |
| Allies | A03 | Static soldiers' portable speakers (diegetic music tracks, low-fi) |

---

## 8. Art & Lighting

* **Palette:** golden-hour warm light everywhere (the Spire's glow) — sickly, too-perfect warmth; brutalist grey concrete; Static orange; Consonance white-and-gold banners; the Aureole spanning the sky (7 bands).
* **Crowd tech:** instanced static-mesh crowds with vertex-animation swaying (Vertex Animation Textures) — up to 20,000 agents in the Bowl's stands; 2,000 in the plaza. LOD to impostor cards beyond 60 m.
* **Key props:** cars/buses/trucks (6 vehicle types + wrecked variants), highway modular kit (ramps, barriers, sign gantries), megablock facade & apartment interiors, stadium kit (seating tiers, concourse, VIP lounge, pitch, light towers, stage), food trucks, Consonance banners, giant screen.
* **Choir overlay:** 20% at the bridge rising to 90% in the Bowl (the stands are grown over with gold filigree and organ pipes).

---

## 9. New Assets Required (P0)

`SK_WPN_Hammerfall`, `SK_Seraph`, `SK_Canon`, `BP_HymnPylon`, `PKP_PU_Amp`, `NPC_StaticSoldier` (+Okafor `SK_Okafor`), `NPC_TunedCivilian` crowd system (VAT), `BOSS_Ionian` (`SK_Ionian`, Choir Organs ×4, stage), CITY kit (highway, bridge, megablock, plaza, stadium), vehicles set, Consonance banners/screens, Thrall variants (commuter, fan, formalwear), `BP_AllyBarricade`.
