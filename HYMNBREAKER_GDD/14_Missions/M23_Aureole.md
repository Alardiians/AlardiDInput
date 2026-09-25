# M23 — AUREOLE

| | |
|---|---|
| **Act** | V — The Unsung |
| **Location** | **Halcyon**, again — the city's center consumed by the **Cathedral of the Final Chord**; the ruined districts around it; the Broadcast Tower under siege |
| **Kit** | `CITY` (ruined, burning) + `CHOIR` 60% → 100% + `CULT` (the Cathedral's exterior) |
| **Target duration** | 85 min (incl. ~15 min mech segment) |
| **Priority** | P1 |
| **Story beats** | BEAT_M23_1 → BEAT_M23_4 |
| **New** | Mech segment #2 with an **allied Static army**, *Wall of Amps* pedal; titan **Choir Colossus**; siege-breaking objectives |
| **Landmark** | **The Cathedral of the Final Chord** — a white-gold megastructure kilometers tall grown over the city center, and above it the **Aureole**: now a single blinding white band (the Octave), pulsing faster and faster |

---

## 1. Overview

The last stand of Halcyon — and of humanity. Aurelia is singing the Octave alone; the Aureole's final band pulses like a failing heart; collars are overheating all over the planet. The Static throws everything it has at the Cathedral: every vehicle blasting music, every soldier screaming. The Unsung leads the charge in the Anvil, then on foot breaks the siege of Harlan's tower — because the **Last Broadcast** will need it.

**Experience goals:** full-scale war (allies everywhere, noise everywhere); the Anvil against a 30 m **Choir Colossus**; the return to familiar places (the Stack, the Decibel District, the Broadcast Tower) now in ruins; and reaching the Cathedral's gate with the whole Static army behind you.

---

## 2. Level Flow

```
[A01 Harbor Staging (Static army)] → CIN (boarding the repaired Anvil — new arm, Wren's "upgrade")
   → [A02 The Stack — MECH] MECH_01 (convoy escort)
   → [A03 The Megablock Canyons — MECH] MECH_02 (Vesper Cloud + Organ Walkers)
   → [A04 Plaza of Communion Ruins — MECH] MECH_03 (CHOIR COLOSSUS)
   → [A05 Decibel District (on foot)] ENC_01 (allies; the clubs still blasting)   (+CM_M23_01)
   → [A06 Broadcast Tower Base] ENC_02 (break the siege)
   → [A07 The Crown (again)] ENC_03 (save Harlan's transmitter)   (+CM_M23_02)
   → [A08 The Cathedral Approach] ENC_04 FINALE → Cathedral gate → (M24)
```

### A01 — Harbor Staging
* The harbor (from M04's anchor platform area) is now the Static's staging ground: hundreds of soldiers, trucks with speaker stacks, jury-rigged tanks with amplifiers welded on, Okafor bellowing orders, **Vire in person** on a command truck (first time on the ground with the Unsung). The Anvil stands repaired — with a **new left arm**: Wren's "upgrade", a Blast Horn twice the size ("*I made it LOUDER*").
* Radio intro (`RAD_M23`, "EVERYBODY WAKE UP").
* Vire (in person): "*Every soldier I have left is behind you. Every speaker on the planet is on. Open the door, Breaker.*"

### A02 — The Stack (Mech), MECH_M23_01
* The highway interchange from M04, collapsed and burning. **Convoy escort:** 6 Static trucks (music blaring) follow the Anvil; Choir forces attack the convoy (the trucks are damageable but can't be destroyed — if a truck's HP hits zero it stalls and must be "protected" for 10 s while it restarts — no fail state, but a Gain/score bonus for zero stalls).

### A03 — Megablock Canyons (Mech), MECH_M23_02
* Streets between megablocks turned into canyons of Choir growth; a **Vesper Cloud** and two **Organ Walkers**; Static gunships make strafing runs (scripted spectacle).

### A04 — Plaza of Communion Ruins (Mech), MECH_M23_03
* The plaza from M04 — now a crater-field before the Cathedral's outer wall. The **Choir Colossus** (30 m humanoid of fused bodies) rises from the rubble. Titan fight: Colossal Slam, Hymn Breath, Grab (mash melee to punch free), debris throws; weak point: the glowing throat-core in its chest (opened by staggering it with the Blast Horn). **Titan Breakdown:** the Anvil's Pile Driver into the throat-core; the Colossus falls onto the Cathedral's outer wall, **breaching it**.
* The Anvil is too damaged to continue (its cockpit alarms scream; it collapses to one knee). The Unsung climbs out.

### A05 — Decibel District, ENC_M23_01
* The nightclub quarter from M05 — half-ruined, but **every club is still blasting music** from walls of amps (the Static's holdouts refused to leave). Civilians cheer from windows. The arena is the main street and two club interiors (The Last Encore among them). Allies: Okafor's squad + club defenders.
* **Optional:** `CM_M23_01` in a collapsed record store.

### A06 — Broadcast Tower Base, ENC_M23_02
* The construction yard from M05: the Choir has encircled the Broadcast Tower with **three Resonance Organs** jamming Harlan's signal (the "siege"). Destroying them (objective) lifts the jamming: Harlan's voice returns full-strength on every channel.

### A07 — The Crown (again), ENC_M23_03
* Up the tower (fast: the lift works this time — a 30 s ride with Harlan's commentary) to the antenna deck. The Choir is trying to **tune the transmitter** itself (a Choir growth wrapping the antenna mast). Destroy the growth's 4 nodes while fighting. Harlan (in person, shotgun in hand — he *fires* it this time): "*They can take the tower. They can't take the FREQUENCY.*"
* Harlan and Vire discuss the **Last Broadcast** over comms for the first time (seeds `CIN_HUB_LastPlan`).
* **Optional:** `CM_M23_02` on the lower ring-deck.

### A08 — The Cathedral Approach, ENC_M23_04 (FINALE)
* A Static dropship carries the Unsung from the tower to the **breach** the Colossus made in the Cathedral's outer wall. The approach: a grand processional ramp of white stone (150 × 50 m) rising to the Cathedral's gate, lined with Consonance statues of Aurelia, under the pulsing Aureole. **The whole Static army** charges up the ramp beside the Unsung (allies: dozens of soldiers, trucks at the ramp's base blasting music).
* After the arena, the gate — 100 m tall — opens by itself. Aurelia's voice: "*Come in. I've been waiting for you.*"

---

## 3. Encounters

```
MECH_M23_01  "Convoy"           (mech)  Route 500 m of collapsed highway
  Infantry swarms: Thrall x40, Chorister x12, Acolyte x12 (Consonance dropships)
  Organ Grinder x6, mech-scale Chime Turret x4, Seraph x6 (strafing the convoy)
  Repair crates: 2
MECH_M23_02  "Canyons"          (mech)  Street canyons 600 m
  TTN_VesperCloud x1, TTN_OrganWalker x2, infantry trickle
  Repair crates: 3 (Static gunship drops)
MECH_M23_03  "The Colossus"     (mech)  Crater-field 400 x 400 m
  TTN_ChoirColossus x1 (20000 HP vs. Anvil), infantry trickle, Organ Grinder x4
  Repair crates: 3
  Titan Breakdown: Pile Driver into the throat-core → the Colossus falls and breaches the Cathedral wall
```

```
ENC_M23_01  "Decibel District"       Arena: A05 (main street 120 x 25 m + 2 club interiors 30 x 25 m)   Seals: rubble barricades
  Music: MUS_M23_Combat_A (diegetic club music layered on top)   Reward: 2 Brass + loot fountain
  Allies: Okafor + 10 soldiers + club defenders
  W1 OnStart:             Acolyte x8, Zealot x6, Thrall x8
  W2 AliveBelow(6):       Carillon x1, Bulwark x3
  W3 AliveBelow(5):       Maestro x1, Gilded Crescendo x1, Chorister x4
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(5): Gilded Profundo x1, Siren x2, Seraph x2, Acolyte x6
  Pickups: Health M x3, Plating M x3, ammo L each, Grudge x1, Harrow Spool x3
  Power-up: AMP (The Last Encore's stage)
```

```
ENC_M23_02  "Break the Siege"         Arena: A06 (yard 70 x 50 m + parking structure 4 levels)   Seals: 3
  Music: MUS_M23_Combat_B             Reward: 2 Brass + loot fountain
  Objective: 3 Resonance Organs (tag `ResonanceOrgan`; 2500 HP each) jamming the signal
  W1 OnStart:             Organ Grinder x2, Chorister x6, Thrall x8
  W2 AliveBelow(5):       Gilded Canon x1, Cantor x2, Bulwark x3
  W3 AliveBelow(5):       Requiem Knight x1, Fugue x2, Echo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 ObjectiveDestroyed(ResonanceOrgan, 3) AND AliveBelow(5): Carillon x1, Gilded Bellwether x1, Chorister x4
  Pickups: Health M x3, Plating M x2, ammo L each, Null Cell x1, Harrow Spool x3
```

```
ENC_M23_03  "The Crown, Again"        Arena: A07 (45 m deck + lower ring + mast platforms)   Seals: stair doors
  Music: MUS_M23_Combat_B (Harlan's jingle sampled)   Reward: 2 Brass + loot fountain
  Objective: destroy 4 growth-nodes on the antenna mast (tag `GrowthNode`; 1500 HP each)
  Allies: Harlan (on the studio balcony, shotgun — invulnerable)
  W1 OnStart:             Seraph x3, Vesper x10, Chorister x4
  W2 AliveBelow(5):       Gilded Crescendo x1, Siren x2
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 ObjectiveDestroyed(GrowthNode, 4) AND AliveBelow(4): Maestro x1, Ophan x2, Thrall x8
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
```

```
ENC_M23_04  "The Approach" (FINALE)   Arena: A08 (processional ramp 150 x 50 m; statue plinths as cover; side terraces 6 m)   Seals: n/a
  Music: MUS_M23_Combat_C ("One More Day" — the biggest track since Act I; crowd of soldiers chanting)
  Reward: 3 Brass + big loot fountain
  Allies: the Static army (30+ soldiers, invulnerable, advancing behind the player)
  W1 OnStart:             Acolyte x10, Zealot x8, Thrall x10
  W2 AliveBelow(8):       Carillon x1, Gilded Profundo x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  W3 AliveBelow(6):       Maestro x2, Requiem Knight x1, Chorister x6
  W3b TimeElapsed(25s):   Thrall x10, Zealot x4
  Final W4 AliveBelow(6): Gilded Canon x1, Gilded Bellwether x1, Seraph x3, Chorister x6
  Pickups: Health M x4, Plating M x4, ammo L each, Null Cell x1, Grudge x1, Harrow Spool x4
  Power-up: OVERDRIVE SURGE (mid-ramp) + DEAD SILENCE (top of the ramp)
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M23_Staging` | The Static army at the harbor; Vire in person; the upgraded Anvil |
| `EVT_M23_Convoy` | Mech convoy escort with music trucks |
| `EVT_M23_Colossus` | Choir Colossus rises; Titan Breakdown breaches the Cathedral wall |
| `EVT_M23_AnvilFalls` | The Anvil kneels, spent; the Unsung climbs out; Wren: "*...she did good.*" |
| `EVT_M23_SiegeBroken` | Harlan's signal returns full strength |
| `EVT_M23_HarlanFires` | Harlan finally fires his shotgun |
| `EVT_M23_Charge` | The whole army charges the ramp with the player |
| `EVT_M23_Gate` | The Cathedral gate opens by itself |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #18** (the last one) | A05: The Last Encore's rafters (Harrow Anchor on the lighting rig) | Violet glow among the stage lights |
| S2 | **Bootleg Tape #11** (Pit Trial: *"Army of One"* — endless waves, allies cheer your kill count) | A06: the parking structure's top level (after the arena) | — |
| S3 | **Pedal: Wall of Amps** | A05: a club's amp wall — one amp is a stash (Harrow-yank its grille) | A violet-lit amp |
| S4 | **Effigy: Choir Colossus** | A04 (mech): the Anvil auto-collects it from the Colossus's wreck | — |
| S5 | **Effigy: Harlan** | A07: Harlan's studio desk (he gives it to you: "*Somebody carved me. Handsome devil.*") | — |
| S6 | **Master: *"One More Day"* by RADIO FREE STATIC ALL-STARS** | A07: Harlan's turntable | Music |
| S7 | **Reprise** | A03 (mech): a rooftop cache the Anvil can punch open | — |
| S8 | **Rig Core** | A08: behind the tallest Aurelia statue's plinth (Power Chord the plinth) | Orange fissures |
| S9 | **Brass Cache #1** | A05 (after `CM_M23_01`) | — |
| S10 | **Brass Cache #2** | A07 (after `CM_M23_02`) | — |
| S11 | **Sounding Station #1** | A01 (Vire's command truck) | — |
| S12 | **Sounding Station #2** | A06 (tower base security booth) | — |
| S13–S17 | **Archive Stones** | A01, A05, A06, A07, A08 | — |

**Archive entries:** `ARC_Loc_CathedralFinalChord`, `ARC_Titan_ChoirColossus`, `ARC_Hist_LastStandOfHalcyon`, `ARC_Tech_AnvilMk2`, `ARC_Obj_LastBroadcast` (stub: Harlan's first notes — completed in M25), `ARC_Obj_OctaveBand`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Complete the convoy escort with no truck stalled |
| 2 | Destroy all 3 siege Organs within 90 seconds of the arena starting |
| 3 | Kill 100 enemies in the Approach arena |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M23_Mech` — "**Siege Engine**" | Mech | The Anvil theme (from M11), bigger, with the Static army's trucks' music as diegetic layers |
| `MUS_BOSS_Colossus` — "**Titan**" | MECH_03 | Colossal, slow, choir of thousands vs. drop-G riffs |
| `MUS_M23_Combat_A` — "**Last Call**" | ENC_01 | Club-metal: layered with 3 diegetic club tracks (the cacophony preview) |
| `MUS_M23_Combat_B` — "**Frequency**" | ENC_02–03 | Harlan's jingle sampled; the jamming = a filter sweep that opens as Organs fall |
| `MUS_M23_Combat_C` — "**One More Day**" | ENC_04 | The anthem: a crowd of soldiers chanting the hook |
| The Aureole | Global | A high, pulsing white tone that speeds up across the mission |

---

## 8. Art & Lighting

* **Palette:** blinding white Aureole light from above (hard, pulsing), burning orange ruins, black smoke, Static orange everywhere (banners, trucks, paint), the Cathedral's white-gold.
* **Key props:** Static army (soldier crowd — mix of full AI allies near the player and VAT crowds further away), music trucks with speaker stacks, jury-rigged tanks, Static gunships (flyby splines), ruined versions of M04/M05 locations (reuse + damage dressing), the Cathedral exterior (hero), processional ramp, the Choir Colossus (hero titan).

---

## 9. New Assets Required (P1)

`TTN_ChoirColossus`, Anvil Mk2 (new left arm), Static army assets (truck with speaker stack, jury-rigged tank, gunship), ruined-city dressing for CITY kit, `SK_Vire` (in person), `SK_Harlan` (combat pose), Cathedral exterior & ramp, convoy AI (`BP_ConvoyTruck` on splines with stall/restart states).
