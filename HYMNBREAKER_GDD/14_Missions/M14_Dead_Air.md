# M14 — DEAD AIR

| | |
|---|---|
| **Act** | III — Iron and Fire (finale) |
| **Location** | **The Quietus** — the hub ship, boarded by the Choir |
| **Kit** | `SHIP` (hub assets, darkened and damaged) + `CHOIR` 10% → 60% (boarding growth spreading through corridors) |
| **Target duration** | 60 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M14_1 → BEAT_M14_6 |
| **New** | Hub-as-level; **Maestro** introduced (Maestro Primus mini-boss); allied crew defenses; named enemy **Deacon Marrow** |
| **Landmark** | **The Mute Engine** — the ship's anechoic heart, a 25 m black sphere visible through interior windows from many decks, its wedge-plates cracked and leaking gold light |

---

## 1. Overview

The player's home is under attack. A harmonized saboteur — **Deacon Marrow**, hiding among refugees as a medic — disabled the **Mute Engine**. Without its anechoic field, the Choir *heard* the Quietus, and boarded it. Every familiar space is dark, overrun and — worst of all — **quiet**: the ship's constant background music is gone.

**Experience goals:** violation of a safe space (every hub room the player knows, turned into a battlefield); fighting alongside the crew the player has grown fond of; loss (Juno Reyes dies); a mini-boss in the Launch Bay; a desperate last stand at the engine; and the abduction of Lund.

**Hub rules during M14:** hub stations are inoperable (dark screens); Field Upgrades still work via the pause menu. After M14, the hub enters **State 4 — Scarred**.

---

## 2. Level Flow

```
[A01 Hull Breach — Refugee Deck] ENC_01 (allies: refugees with makeshift noise)
   → [A02 Mess Hall] ENC_02 (crew barricade; allies)
   → [A03 Spine Corridor] (Juno's last stand — scripted) 
   → [A04 Listening Room & Effigy Gallery] ENC_03
   → [A05 The Armory] (Wren's workshop, overrun) → [A06 Launch Bay] MINI-BOSS: MAESTRO PRIMUS (teleports at 25%)
   → [A07 Engine Room] ENC_05 (Wren holds the line; Deacon Marrow)
   → [A08 Mute Engine Chamber] ENC_06 FINALE "Restart" → CIN_M14_Abduction
```

### A01 — Hull Breach: Refugee Deck, ENC_M14_01
* The Unsung's Drop Coffin is fired *at the Quietus* by a Static dropship and punches through the hull into the **Refugee Deck** (family quarters: bunks, laundry lines, kids' drawings of the Unsung on the walls, a makeshift school corner). Emergency red lighting; porcelain growth creeping from the Choir's breach point (a torn hole in the hull filled with a membrane of bone and gold).
* **Allies:** refugees banging pots, playing phones at full volume, a teenager with an electric guitar and a tiny amp — they're "noise defense", not combatants (they huddle in a barricaded room; enemies try to reach them — the arena's objective is to keep enemies away from the barricade (soft objective; no fail state, but a Gain bonus if the barricade is never touched)).

### A02 — Mess Hall, ENC_M14_02
* **Space:** the crew mess (40 × 25 m, two levels: dining floor + galley balcony) — the tables flipped into barricades; 6 Static soldiers and cooks with shotguns defending the galley. Pots, pans, trays everywhere. A jukebox (Pops' pride) smashed.

### A03 — Spine Corridor: Juno's Last Stand
* **Space:** the ship's main corridor (10 m wide, 200 m long, black anechoic wedges on every wall — cracked and gilding), with bulkhead doors every 40 m.
* **Script (`EVT_M14_Juno`):** over comms, **Juno Reyes** holds bulkhead 4 alone ("*I've got it, I've got it — go help Wren, I'm fine—*"). The player fights down the corridor (light combat) and reaches bulkhead 4 too late: Juno is dead, surrounded by dead Choir-forms; **her Static Collar is still playing music**. The player can interact (optional): the Unsung kneels and switches the collar off — no: **turns it up** (`GST`). The music swells briefly into the next arena's track.

### A04 — Listening Room & Effigy Gallery, ENC_M14_03
* **Space:** Pops' record room (shelves of vinyl, the turntable, listening chairs) opening into the Effigy Gallery (display cases with the player's collected Effigies — **the cases hold whatever Effigies the player has actually collected**). Choir growth on the record shelves. Pops is barricaded in the booth (safe, alive; he cheers the Unsung: "*Mind the records!*").
* **Arena rule:** records/Effigy cases are indestructible (the player's collection is safe — this matters!).

### A05 — The Armory
* Wren's workshop, overrun: half-built weapons, her workbench, band posters. Short fight (pre-placed enemies). Wren on comms from the Engine Room: "*Is my workshop okay? Don't answer that. Get to the launch bay — something big just walked in.*"

### A06 — Launch Bay: MINI-BOSS MAESTRO PRIMUS
* `10_Bosses.md` §7. **Space:** the Drop Coffin launch bay (60 × 40 m, 20 m tall): the launch rail (a 60 m trench with the coffin cradle), cargo containers (cover), a crane gantry (Harrow Anchors, Grip Walls), the Armory's viewing windows above (8 m), the bay's outer door (sealed) showing space.
* **Maestro introduction:** Maestro Primus conducts the boarding from the crane gantry; prompt: `MAESTROS summon and revive — destroy the SCORE, kill it FIRST`.
* At 25% HP it teleports away (a ring-gate closing). The bay's seals open.

### A07 — Engine Room, ENC_M14_05
* **Space:** the fusion drive room (50 × 40 m, 25 m tall): two massive drive cores, coolant pipes, catwalks at 6 m and 12 m, Wren's barricade on the control deck. **Wren** fights with a welding torch and a Static Rifle (invulnerable ally).
* **Deacon Marrow:** the saboteur appears on a catwalk — a human in medic's scrubs, half-gilded, singing, holding a Cantor lantern he ripped from a dead Cantor; he functions as a **named Cantor** (`ENM_Cantor` stats ×1.5 HP, human model) linking enemies. Killing him: Wren: "*...He did my stitches. Two weeks ago. He did my stitches.*"

### A08 — Mute Engine Chamber, ENC_M14_06 (FINALE) "Restart"
* **Space:** the Mute Engine: a 25 m black sphere suspended in a spherical chamber (50 m) by six massive struts; catwalk rings at the sphere's equator (floor level), and at ±10 m; three **breaker stations** (big lever panels) at 120° intervals on the rings.
* **Objective:** throw the 3 breakers (each needs 3 s of interact; the player is vulnerable; enemies swarm). Each breaker thrown: the engine's hum rises and ambient sound dims a notch. After the third, the spin-up takes 30 s — survive.
* `CIN_M14_Abduction`: Maestro Primus on the gantry with Lund; the Harrow strikes the closing gate; the Mute Engine reaches full spin; the Choir aboard crumbles to dust; Vire: "*Find him.*"

---

## 3. Encounters

```
ENC_M14_01  "Refugee Deck"          Arena: A01 (bunk halls 40 x 30 m, corridor loop, laundry mezzanine 4 m)   Seals: bulkheads
  Music: MUS_M14_Combat_A (the ship's music is OFF — the combat track plays thin, muffled at first; see audio)
  Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Emerge from the breach membrane), Chorister x3
  W2 AliveBelow(4):       Bloated Thrall x2, Trooper x4
  Final W3 AliveBelow(3): Crescendo x1, Siren x1, Thrall x8
  Pickups: Health S x8 (medkits), Plating S x4, ammo S x2 each
```

```
ENC_M14_02  "Mess Hall"             Arena: A02 (40 x 25 m + galley balcony 5 m)   Seals: 2
  Music: MUS_M14_Combat_A            Reward: 1 Brass + loot fountain
  Allies: 6 Static soldiers + 2 cooks (galley)
  W1 OnStart:             Chorister x6, Thrall x8
  W2 AliveBelow(5):       Bellwether x1, Echo x1, Thrall x6
  W3 AliveBelow(4):       Fugue x2, Bulwark x2, Trooper x2
  Final W4 AliveBelow(3): Profundo x1, Chorister x4
  Pickups: Health M x2 (galley), Plating M x1, Shells L x1, Rounds L x1, Harrow Spool x2
```

```
ENC_M14_03  "Listening Room"        Arena: A04 (record room 25 x 20 m + gallery 30 x 15 m)   Seals: 2
  Music: MUS_M14_Combat_B            Reward: 1 Brass + loot fountain
  W1 OnStart:             Fugue x2, Thrall x6
  W2 AliveBelow(4):       Siren x2, Chorister x3
  Final W3 AliveBelow(3): Seraph x1, Hymnal x1, Bloated Thrall x2, Thrall x6
  Pickups: Health S x6, Plating S x4, Charge L x1, Ordnance S x2
```

```
BOSS_MaestroPrimus  "Launch Bay"   Arena: A06   (10_Bosses.md §7) — ends at 25% HP (teleport)
  Music: MUS_BOSS_Maestro
  Boarding Hymnfall every 20 s: 5 T1 + 1 T2 (rotating: Crescendo, Bellwether, Seraph, Siren)
  Reward: 2 Brass + loot fountain
```

```
ENC_M14_05  "Engine Room"           Arena: A07 (50 x 40 m, 25 m; catwalks 6 & 12 m; drive cores)   Seals: 2
  Music: MUS_M14_Combat_C            Reward: 1 Brass + loot fountain
  Allies: Wren (control deck)
  W1 OnStart:             Deacon Marrow (named Cantor), Bulwark x3 (linked), Thrall x8
  W2 KilledTag(Marrow) OR AliveBelow(4): Requiem Knight x1, Chorister x4
  W3 AliveBelow(4):       Canon x1, Ophan x1, Thrall x6
  Final W4 AliveBelow(3): Crescendo x2, Echo x2, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
```

```
ENC_M14_06  "Restart" (FINALE)      Arena: A08 (50 m spherical chamber; 3 catwalk rings; 3 breakers)   Seals: 3
  Music: MUS_M14_Combat_C (finale)   Reward: 2 Brass + big loot fountain
  Objective: throw 3 breakers (3 s interact each), then survive 30 s spin-up
  Continuous (until objective done): Thrall x6 every 20 s; Chorister x3 every 30 s
  Per breaker thrown: +1 heavy spawn (1st: Bellwether; 2nd: Profundo; 3rd: Maestro x1 — a standard Maestro, killable)
  Spin-up 30 s: Hymnfall of Seraph x2, Vesper x10, Thrall x8
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x3
  Power-up: OVERDRIVE SURGE (appears when the 3rd breaker is thrown)
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M14_Breach` | Drop Coffin fired into the Quietus's hull |
| `EVT_M14_NoiseDefense` | Refugees making noise with pots, phones, a guitar |
| `EVT_M14_Juno` | Juno's last stand; the collar still playing; optional "turn it up" interaction |
| `EVT_M14_Collection` | The Effigy Gallery reflects the player's real collection |
| `EVT_M14_Marrow` | Deacon Marrow revealed and killed |
| `EVT_M14_Breakers` | Breakers: each dims the ambient sound; the engine hum rises |
| `EVT_M14_Abduction` | `CIN_M14_Abduction` |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Tab #6: "Mixtape"** (replaces the soundtrack with a player-selected playlist of unlocked Masters) | A04: inside Pops' booth — he hands it over after the arena ("*You've earned this, big fella.*") | Pops waves you over |
| S2 | **Effigy: Maestro** | A06: on the crane gantry's highest beam (after the fight) | — |
| S3 | **Master: *"Dead Air"* by HARLAN PRICE & THE LATE SHIFT** (Harlan's old band!) | A02: the smashed jukebox's record crate | — |
| S4 | **Reprise** | A03: behind bulkhead 2's maintenance panel (Harrow-yank) | Violet tag |
| S5 | **Rig Core** | A05: Wren's locked "DO NOT TOUCH" cabinet (she tells you on comms: "*...okay, you can touch it. There's a present in there.*") | — |
| S6 | **Brass Cache #1** | A01: the school corner's supply box | — |
| S7 | **Brass Cache #2** | A07: engine room, top catwalk | — |
| S8 | **Sounding Station** | A03: the Spine's security booth (maps the whole ship — also the hub map from now on) | — |
| S9–S12 | **Archive Stones** | A01, A02, A05, A07 | — |

**Archive entries:** `ARC_Loc_Quietus_Full`, `ARC_Tech_MuteEngine`, `ARC_Char_Juno_Memorial`, `ARC_Char_DeaconMarrow`, `ARC_Enemy_Maestro`, `ARC_Boss_MaestroPrimus`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Complete the Refugee Deck arena without any enemy touching the refugees' barricade |
| 2 | Destroy Maestro Primus's Score before it summons twice |
| 3 | Throw all three breakers without dying |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| **The silence** | Whole mission | The hub's ever-present background music (crew radios, the mess jukebox) is **gone**. Ambience: creaking hull, alarms, distant choir. Horrible. |
| `MUS_M14_Combat_A` — "**Intruders**" | ENC_01–02 | Plays thin and muffled (as if from a single broken speaker) and gets fuller as allies turn their speakers on during the fight |
| `MUS_M14_Combat_B` — "**Wax**" | ENC_03 | Vinyl crackle intro, heavy |
| `MUS_BOSS_Maestro` — "**Conductor**" | Mini-boss | Orchestral choir vs. band |
| `MUS_M14_Combat_C` — "**Nobody Goes Quiet**" | ENC_05–06 | The biggest track of Act III; Vire's "*Nobody goes quiet on my ship!*" line is sampled into the breakdown |
| Juno's collar | A03 | A tinny punk song from the collar speaker — then it becomes the next arena's intro |

---

## 8. Art & Lighting

* The hub's usual warm, cluttered, lived-in lighting (string lights, work lamps, screens) is **off**: red emergency lighting, sparking panels, gold Choir glow from boarding membranes. The black anechoic wedges gilding over is the key visual violation.
* After M14, the hub permanently shows scars: burn marks, scraped-off gold residue on the wedges, patched hull, a **memorial wall** of Static Collars with Juno's collar at the center (interactable: plays her song).

---

## 9. New Assets Required (P1)

Hub damaged-state variants (`SHIP` kit: red emergency lighting scenario, damaged props, gilded wedge material variant, boarding membranes), `SK_Maestro`, `BOSS_MaestroPrimus` (Maestro + larger Score), `NPC_Refugee` (non-combat), Juno corpse scene + collar prop, `SK_DeaconMarrow` (human medic, half-gilded), breaker stations (`BP_Breaker`), Mute Engine chamber (hero space, also used in the hub's lore tour).
