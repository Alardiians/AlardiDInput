# M16 — THE SINGING SEA

| | |
|---|---|
| **Act** | IV — Deep Water, High Air |
| **Location** | Europa's ocean floor, 20 km beneath the ice: habitat domes, pressure-tube tunnels, a Choir-reef, and the **Reef Cathedral** |
| **Kit** | `ICE` (underwater habitat variant) + `CHOIR` 50% → 100% (Aeolian: coral-like organ pipes, translucent porcelain, drifting gold lights) |
| **Target duration** | 85 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M16_1 → BEAT_M16_4 |
| **New** | *Octaver* pedal, **Requiem Gate #5**, drain-the-room pump puzzles, flooding arenas, ride-the-boss; standard **Maestro**; mini-boss **The Leviathan**; **Boss: Aeolian, the Grieving Tide** |
| **Landmark** | Through every viewport and tube: the **dark sea** full of drifting golden lights and, far away, the pale glow of the **Reef Cathedral** dome |

---

## 1. Overview

The bottom of an alien ocean. Nobody but the Cryobore crew ever saw it — and now it sings. Every window shows the black water, the drifting lights, the silhouettes of vast Choir-forms. The Aeolian Archon mourns here in a cathedral grown from reef.

**Experience goals:** claustrophobic beauty (transparent tubes with the abyss around you), the horror of flooding (rising water as a timer), the **Leviathan** chase and eye-shooting set piece, a boss you *ride*, and emotional weight — Aeolian's grief mirrors the crew's grief for Juno and Lund.

**Water rule (reminder):** no swimming. Flooded rooms are **barriers** (void rules if entered) until drained; rising water in arenas shrinks the floor.

---

## 2. Level Flow

```
[A01 Ocean Habitat (Bore bottom)] → [A02 Pressure Tube Network] 
   → [A03 Research Dome "Thalassa"] ENC_01 (standard Maestro)
   → [A04 Flooded Sector (pump puzzles)] ENC_02   (+CM_M16_01 in the dive locker)
   → [A05 Tunnel Junction] MINI-BOSS: THE LEVIATHAN (eyes, rising water)
   → [A06 Reef Gardens (reef-grown dome)] ENC_03
   → [A07 Reef Cathedral] BOSS: AEOLIAN → end
   Optional: [Requiem Gate #5] off A04
```

### A01 — Ocean Habitat
* The dome at the Bore's bottom: a moon-pool (a circular opening to the sea in the floor — the sea surface ripples inside the dome; void), diving equipment, research posters, a mess, a crew memorial (the Cryobore crew wrote their names on a wall before they were tuned). Lore; no combat. The drifting lights outside pulse in time with the music.

### A02 — Pressure Tube Network
* Transparent tubes (5 m diameter) running along the ocean floor between domes; the player walks *through the sea*. Outside: Choir-reef formations, the drifting lights, a school of porcelain "fish" (Choir-tuned Europan microfauna — tiny, harmless, beautiful). Light combat inside tubes (Sirens slithering along them, Choristers). Some tube sections have cracked, leaking panels (cosmetic sprays).

### A03 — Research Dome "Thalassa", ENC_M16_01
* **Space:** a large research dome (60 m diameter, 20 m tall): lab benches, a huge central aquarium tank (empty, cracked — its water became part of the reef), catwalks around the dome's rim (8 m), observation windows onto the sea.
* **Maestro (standard):** first killable Maestro in an arena (with its Score). Prompt reminder: `MAESTRO — destroy the SCORE; interrupt its RESURRECTION`.

### A04 — Flooded Sector, ENC_M16_02
* **Space:** a sector of labs and storerooms partly flooded; the route requires **draining rooms**: pump control panels (interact) drain a flooded room over 20 s (the water level visibly drops, revealing floor). An arena takes place while a big room (the **Storage Hall**, 50 × 40 m) drains in stages — the floor space grows as the fight goes on (the reverse of the boss's flooding).
* **Optional:** `CM_M16_01` in the dive locker. **Requiem Gate #5** in a sealed cold-lab.

### A05 — Tunnel Junction: MINI-BOSS THE LEVIATHAN
* `10_Bosses.md` §8. **Space:** a hub where four tube-corridors meet at a central platform (40 m diameter, raised 3 m) inside a large dome. The Leviathan smashes through the tubes one by one; water floods in from each breach, raising the water level on a timer (the platform stays dry; the outer ring floods).
* **Eyes:** while its head is lodged in a breach (8 s windows), shoot its 3 eyes (1500 HP each). Its body outside thrashes (the dome shakes). After the third eye, it drags a tube section away, opening the path onward (a torn tube leads into the Reef Gardens).

### A06 — Reef Gardens, ENC_M16_03
* **Space:** a habitat dome overgrown *inside* by the Choir-reef: coral-like organ pipes, porcelain anemones that sing, pools, arches of translucent growth — a garden of grief. The Aeolian Archon's weeping is audible from the next dome.

### A07 — Reef Cathedral: BOSS AEOLIAN
* `10_Bosses.md` §9. `CIN_M16_Aeolian`. The dome floods/drains across three phases; ride its back in phase 2.
* After the Boss Breakdown: the drifting lights outside **go dark one by one**; the ocean falls silent; the fifth Aureole band dies. Wren's trace resolves — to *nothing*: something is hiding the location. Lund: absent. Vire: "*Something's hiding him. What can hide a thing from the whole system?*" Wren: "*A dream. Venus. The Lydian Spire.*"

---

## 3. Encounters

```
ENC_M16_01  "Thalassa"               Arena: A03 (60 m dome, 20 m; aquarium tank 10 m; rim catwalk 8 m)   Seals: 3 (tube hatches)
  Music: MUS_M16_Combat_A             Reward: 1 Brass + loot fountain
  W1 OnStart:             Maestro x1 (catwalk), Thrall x8, Chorister x4                       [standard Maestro]
  W2 KilledTag(Maestro) OR AliveBelow(4): Siren x2, Fugue x2
  W3 AliveBelow(4):       Gilded Bellwether x1, Hymnal x1, Thrall x6
  Final W4 AliveBelow(3): Canon x1, Seraph x2, Echo x1
  Pickups: Health M x2, Plating M x1, ammo L x1 (Charge, Ordnance), Harrow Spool x2
```

```
ENC_M16_02  "Storage Hall (draining)"  Arena: A04 (50 x 40 m; floor drains in 3 stages over the fight; shelving 6 m; gantry 8 m)   Seals: 2
  Music: MUS_M16_Combat_A             Reward: 1 Brass + loot fountain
  W1 OnStart (floor 30% dry):  Siren x2, Chorister x4 (gantry, shelves)
  W2 AliveBelow(3) (floor 60% dry): Thrall x10, Bulwark x3, Cantor x1
  W3 AliveBelow(4) (floor 100% dry): Carillon x1, Thrall x6
  Final W4 AliveBelow(4): Profundo x1, Crescendo x2, Chorister x3
  Pickups: Health S x8, Plating M x2, ammo L each (appear as the floor drains), Harrow Spool x3
```

```
BOSS_Leviathan  "Tunnel Junction"    Arena: A05   (10_Bosses.md §8)
  Music: MUS_BOSS_Leviathan
  Resource adds: Thrall x4 + Chorister x2 every 30 s (emerging from breached tubes)
  Reward: 2 Brass + loot fountain
```

```
ENC_M16_03  "Reef Gardens"           Arena: A06 (70 m dome; reef arches; pools (void); singing anemones = Hymn Pylon behavior x2)   Seals: 2
  Music: MUS_M16_Combat_B             Reward: 2 Brass + big loot fountain
  W1 OnStart:             Chorister x6, Siren x2, Thrall x8 (anemones buff them)
  W2 AliveBelow(5):       Maestro x1, Bulwark x3
  W3 AliveBelow(4):       Gilded Bellwether x1, Ophan x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Carillon x1, Echo x2, Seraph x1, Chorister x3
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
  Power-up: AMP (reef arch top)
```

**Boss:** `BOSS_Aeolian` (`10_Bosses.md` §9). **Optional:** `CM_M16_01`, **Requiem Gate #5** (`RQG_05`, "**Drowned Hymns**").

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M16_Memorial` | The Cryobore crew's names on the wall |
| `EVT_M16_Tubes` | Walking through transparent tubes on the ocean floor |
| `EVT_M16_Drain` | Pump puzzles (drain rooms to proceed) |
| `EVT_M16_Leviathan` | Leviathan breaches; eye-shooting; tube torn away |
| `EVT_M16_Aeolian` | `CIN_M16_Aeolian` |
| `EVT_M16_Ride` | Boss phase 2: riding Aeolian's back |
| `EVT_M16_LightsOut` | After the boss: the sea's lights go dark one by one |
| Glimpse | Locris seen through a far viewport, standing on the reef outside in the dark water, watching — then gone (second glimpse) |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #5** | A02: a tube section with a maintenance hatch in its floor — drop into a crawlway beneath the tube (void water visible below the grating) | A faint bell under the grating |
| S2 | **Heart Shard #12** | A03: inside the cracked aquarium tank (climb the tank's rim via Grip Wall, drop in) | Violet glow inside the tank |
| S3 | **Tab #7: "Deep Sea"** (world tinted underwater; enemies float slightly on death) | A04: a drained room that requires draining a *second*, optional pump first | — |
| S4 | **Pedal: Octaver** | A06: top of the tallest reef arch (Harrow Anchor on an organ-pipe knot) | Violet glow on the arch |
| S5 | **Effigy: Leviathan** | A05: after the fight, inside the torn tube section's wreckage | — |
| S6 | **Effigy: Siren** | A02: a tube junction's control booth | — |
| S7 | **Master: *"Whale Fall"* by ABYSSAL** | A01: the habitat mess's record player | Music |
| S8 | **Rig Core** | A04: behind the dive locker (after `CM_M16_01`) | — |
| S9 | **Brass Cache #1** | A01: moon-pool equipment rack | — |
| S10 | **Brass Cache #2** | A06: under a reef pool's drained basin | — |
| S11 | **Sounding Station #1** | A01 | — |
| S12 | **Sounding Station #2** | A04 | — |
| S13–S17 | **Archive Stones** | A01, A02, A03, A06, A07 | — |

**Archive entries:** `ARC_Loc_SingingSea`, `ARC_Archon_Aeolian` (full), `ARC_Titan_Leviathan` (full), `ARC_Hist_EuropanLife`, `ARC_Doc_CryoboreNames`, `ARC_Opt_RequiemGate5`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy all 3 Leviathan eyes within 2 minutes |
| 2 | Destroy 4 blowhole-mouths while riding Aeolian |
| 3 | Interrupt a Maestro's Resurrection Crescendo with a Hush Charge |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M16_Explore` — "**Hadal**" | Habitat, tubes | Slow, aquatic doom; whale-song choir; muffled underwater textures |
| `MUS_M16_Combat_A` — "**Pressure Hull**" | ENC_01–02 | 150 BPM, heavy, "wet" reverb |
| `MUS_BOSS_Leviathan` — "**Breach**" | Mini-boss | Sub-bass; the Leviathan's song is the lead melody |
| `MUS_M16_Combat_B` — "**Reef of Tears**" | ENC_03 | Melancholic melodic metal |
| `MUS_BOSS_Aeolian` — "**The Grieving Tide**" | Boss | Aeolian-mode (natural minor) funeral-doom → blast beats in phase 3 |
| Flooding | Arenas | Rushing water, hull groans, pressure creaks |

---

## 8. Art & Lighting

* **Palette:** black-blue water, drifting gold lights, pale translucent Aeolian growth, warm habitat interiors (amber lights, orange Static tape), bioluminescent reef accents in *warm* tones (gold, rose) to keep cyan reserved for enemies.
* **Key props:** habitat domes (modular), transparent pressure tubes (with sea visible — use a large exterior "sea volume" with volumetric fog and particle lights), moon-pool, aquarium tank, pump panels & drainable water planes (animated water level), reef formations, singing anemones, Reef Cathedral dome (hero), Leviathan (hero titan).

---

## 9. New Assets Required (P1)

`BOSS_Aeolian` (`SK_Aeolian` + ride-able back rig with anchors and blowholes), `TTN_Leviathan` (combat head & eyes, breach animations), water-level system (`BP_WaterLevelController` driving planes, kill volumes and nav modifiers), transparent tube kit, habitat dome kit (underwater), reef CHOIR variant, singing anemone (Hymn Pylon variant), drifting-lights Niagara, underwater exterior sea volume.
