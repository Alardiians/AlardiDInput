# M05 — RADIO FREE STATIC

| | |
|---|---|
| **Act** | II — The Tuned Earth |
| **Location** | Halcyon Undercity: Metro Line 4, the flooded Low Wards, the **Decibel District** (nightclub quarter), the **Halcyon Broadcast Tower** |
| **Kit** | `CITY` (undercity, neon nightlife variant) + `BRU` (metro) + `CHOIR` 20% → 60% |
| **Target duration** | 70 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M05_1 → BEAT_M05_5 |
| **New** | Shredder, Drum Fire & Cluster Bell mods, Pedalboard (2 slots) + *Boost* pedal, Tempo power-up; enemies Organ Grinder, Bloated Thrall |
| **Landmark** | **The Broadcast Tower** — a 400 m concrete needle with a red-lit antenna crown, visible from every rooftop, pulsing orange with Harlan's signal; Hymnfall pillars converge on it |

---

## 1. Overview

After Ionian's death, Halcyon's Hymn is weaker — but the Choir has worked out what keeps millions of humans untuned: **Radio Free Static**. Pillars of Hymnfall are converging on Harlan's tower. The Unsung must cross the undercity to reach it — and the player gets a taste of **human resistance culture**: the Decibel District's clubs turned into fortresses with walls of amplifiers, punks with shotguns, graffiti everywhere, music pumping from every doorway.

**Experience goals:** tone shift to gritty, neon, human; the Shredder's power fantasy; fighting *alongside* humans defending their homes; Harlan's live commentary as the player climbs his tower; receiving the Pedalboard.

---

## 2. Level Flow

```
[A01 Drop — North Wards rooftop] → [A02 Metro Line 4: Meridian Square Station] ENC_01 (Bloated Thrall)
   → [A03 The Low Wards (flooded streets, rooftops)] ENC_02
   → [A04 Decibel District] → [The Last Encore (Static HQ club)] Shredder, mods, ENC_03 "Venue Siege" (allies)
   → [A05 Tower Yard (construction site)] ENC_04 (Organ Grinder intro)   (+CM_M05_01 in the parking structure)
   → [A06 Tower Interior: stairwells, transmitter hall] ENC_05 (Tempo)
   → [A07 The Crown (antenna deck)] ENC_06 FINALE → CIN_M05_Harlan
```

### A01 — North Wards Rooftop
* Drop Coffin landing on a rooftop garden. Vista: the tower on the southern horizon with Hymnfall pillars spiralling down around it; the Ionian Spire's corpse (a dead, grey-gold husk) in the distance; the Aureole with 6 bands. Radio intro plays; the route descends through a building into the metro.

### A02 — Metro Line 4: Meridian Square Station, ENC_M05_01
* **Space:** a large brutalist metro station (platform hall 80 × 30 m, 12 m tall), 2 tracks, a stalled train on each (cars as cover and as a raised route on their roofs), mezzanine ticket hall above (6 m), escalators.
* **Bloated Thrall intro:** a Bloated Thrall waddles among 6 Thralls on the platform. Prompt: `BLOATED THRALLS burst — use the HARROW to FLING them into enemies`. Lund: "*It's full of— I don't know what it's full of. Don't be near it.*"
* **Dark sections:** tunnels between stations are unlit except for the Unsung's visor light (a subtle ember flashlight, auto-on in dark volumes) and emergency lights.

### A03 — The Low Wards, ENC_M05_02
* **Space:** a flooded district (sea walls failed): streets under 50 cm of water (walkable, splashy, no slow), deeper canals (void) between blocks; rooftops connected by Kick Pads, Swing Poles (scaffolding bars), and Harrow Anchors on water towers.
* **Arena:** a flooded market square (50 × 45 m) with stalls, a collapsed pedestrian bridge (ramp to rooftops), and 3 rooftop platforms (5–8 m).

### A04 — The Decibel District & The Last Encore
* **Space:** a neon-lit nightlife quarter — clubs, bars, record shops, tattoo parlors — every building fortified by the Static with **walls of amplifiers** blasting music outward; hand-painted signs ("NO SILENCE ZONE", "KEEP IT LOUD", "BREAKER WAS HERE" — someone already painted it). Static civilians (non-combatants) peer from windows and cheer.
* **The Last Encore:** a big concert venue that is the Static's Halcyon HQ. Inside: a stage, a mosh floor turned into an armory, bunks on the balcony. Okafor is here.
* **Shredder:** Okafor hands it over (`COM_M05_04`: "*This is Linda. Linda is my baby. You bring her back with... no, keep her. She likes you better.*"). `PKP_Weapon_Shredder`.
* **Mod Crates:** Breacher — **Drum Fire** (armory table), Hammerfall — **Cluster Bell** (backstage).
* **ENC_M05_03 "Venue Siege":** the Choir attacks the club. The fight spans the **mosh floor, the stage, the balconies and the street outside** (the club's front doors are blown open). Allies (Okafor + 8 soldiers) hold the balcony.

### A05 — Tower Yard, ENC_M05_04
* **Space:** the Broadcast Tower stands in a construction yard (the tower was being reinforced): cranes, rebar stacks, concrete mixers, a half-built parking structure (4 levels, open sides — the optional Choir Mass is on level 3).
* **Organ Grinder intro:** a tuned six-legged construction mech is battering the tower's base with its legs. Prompt: `ORGAN GRINDERS — destroy the TURRET on its back`. It's introduced with Thralls only; the second Organ Grinder arrives in the final wave.

### A06 — Tower Interior, ENC_M05_05
* **Space:** the tower's core: a 15 m wide concrete stairwell spiraling around elevator shafts (vertical traversal: stairs, Harrow Anchors across the shafts, Grip Walls on cable ducts), then the **Transmitter Hall** (a 35 × 35 m, 15 m tall room of glowing vacuum-tube transmitters and cable bundles — arena).
* **Harlan's commentary:** he watches the Unsung's progress on security cameras and narrates live over the tower's PA *and* on air (`COM_M05_09`–`_15`): "*I can hear you coming up the stairs, and friends, it sounds WONDERFUL.*" / "*That was a Chorister. That WAS a Chorister.*"
* **Tempo power-up** introduced in the Transmitter Hall.

### A07 — The Crown, ENC_M05_06 (FINALE)
* **Space:** the open-air antenna deck at 380 m: a circular deck (45 m diameter) around the antenna mast, with Harlan's studio (a glass booth) on one side; a lower ring-deck (4 m below) and the mast's maintenance platforms (8 m, 14 m) reachable by Grip Walls and anchors. The city spread below; the sea; the Aureole.
* The final Hymnfall pillar lands **on the deck itself**.
* After the arena: `CIN_M05_Harlan` — Harlan emerges from his booth with a shotgun he never fired, looks up at the Unsung: "*You're taller than on the posters.*" He gives them his lucky pedal and an old pedalboard. **Pedalboard unlocked (2 slots) + Boost pedal.**

---

## 3. Encounters

```
ENC_M05_01  "Meridian Square Station"  Arena: A02 (80 x 30 m hall + mezzanine 6 m, trains)   Seals: 4 (tunnel mouths + stairs)
  Music: MUS_M05_Combat_A          Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x8, Bloated Thrall x1                                        [Bloated intro]
  W2 AliveBelow(4):       Trooper x4 (mezzanine), Bloated Thrall x1, Thrall x6
  W3 AliveBelow(4):       Chorister x3 (train roofs), Crescendo x1 (charges down the platform)
  Final W4 AliveBelow(3): Ophan x1, Bloated Thrall x2, Thrall x8
  Pickups: Health S x6, Plating S x3, Shells L x1, Ordnance S x2
```

```
ENC_M05_02  "Flooded Market"           Arena: A03 (50 x 45 m, water streets, 3 rooftops 5-8 m)   Seals: 3
  Music: MUS_M05_Combat_A          Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10, Chorister x2
  W2 AliveBelow(4):       Seraph x1, Vesper x6
  W3 AliveBelow(4):       Cantor x1, Bulwark x2, Trooper x3
  Final W4 AliveBelow(3): Crescendo x2, Chorister x2, Bloated Thrall x2, Thrall x6
  Pickups: Health M x1, Health S x4, Plating M x1, Ordnance L x1, Rounds S x2
  Notes: canals are void (enemies knocked in die — Downbeat/Power Chord knockback kills = Environmental kills)
```

```
ENC_M05_03  "Venue Siege"              Arena: A04 The Last Encore (mosh floor 30 x 25 m, stage 3 m, balconies 6 m) + street (40 x 15 m)   Seals: none (defense — the arena is the club; the street doors are open)
  Music: MUS_M05_Siege (a diegetic track the club's PA plays — the band on the album cover)   Reward: 2 Brass + loot fountain
  Allies: Okafor + 8 soldiers (balcony)
  W1 OnStart:             Thrall x12 (street), Trooper x4 (rooftops opposite)
  W2 AliveBelow(6):       Chorister x4 (Hymnfall in the street), Bloated Thrall x2, Thrall x6
  W3 AliveBelow(5):       Crescendo x2 (through the front doors), Bulwark x3
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Seraph x2, Canon x1 (street, far end), Chorister x3, Thrall x8
  Pickups: Rounds L x2 (Shredder feed), Health M x2 (bar counter, stage), Plating M x2, Shells L x1, Harrow Spool x3
```

```
ENC_M05_04  "Tower Yard"               Arena: A05 (70 x 50 m, cranes, rebar stacks, mixers)   Seals: 3
  Music: MUS_M05_Combat_B          Reward: 1 Brass + loot fountain
  W1 OnStart:             Organ Grinder x1, Thrall x8                                         [Organ Grinder intro]
  W2 KilledTag(OrganGrinder) OR AliveBelow(3): Trooper x4 (crane cabs), Chorister x3, Bloated Thrall x1
  W3 AliveBelow(4):       Ophan x1, Vesper x6, Thrall x6
  Final W4 AliveBelow(3): Organ Grinder x1, Crescendo x1, Cantor x1, Thrall x8
  Pickups: Health M x1, Health S x4, Plating M x1, Rounds L x1, Ordnance L x1, Harrow Spool x2
```

```
ENC_M05_05  "Transmitter Hall"         Arena: A06 (35 x 35 m, 15 m, transmitter banks, catwalk ring 7 m)   Seals: 2
  Music: MUS_M05_Combat_B          Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x4, Thrall x8
  W2 AliveBelow(4):       Seraph x1, Bulwark x2, Cantor x1, Thrall x4
  Final W3 AliveBelow(3): Crescendo x1, Bloated Thrall x2, Chorister x3, Trooper x3
  Pickups: Health S x6, Plating S x4, Charge L x1, Shells S x2
  Power-up: TEMPO (catwalk, opposite the entry)
```

```
ENC_M05_06  "The Crown" (FINALE)       Arena: A07 (45 m circular deck + lower ring 4 m below + mast platforms 8/14 m)   Seals: n/a (rooftop; exits are the stair doors, sealed)
  Music: MUS_M05_Combat_C          Reward: 2 Brass + big loot fountain
  W1 OnStart (Hymnfall on the deck): Chorister x5, Thrall x8
  W2 AliveBelow(4):       Seraph x2, Vesper x8
  W3 AliveBelow(4):       Canon x1 (lower ring), Organ Grinder x1 (climbs the mast!), Thrall x6
  W3b TimeElapsed(25s):   Thrall x6
  Final W4 AliveBelow(4): Crescendo x2, Cantor x1, Ophan x1, Chorister x3, Bloated Thrall x2
  Pickups: Health M x2, Plating M x2, Ordnance L x1, Rounds L x1, Harrow Spool x3
  Power-up: AMP (mast platform at 14 m)
  Notes: the deck edge is a void (knockback kills). The Organ Grinder climbing the mast is a scripted spectacle; it drops onto the deck at 50% HP.
```

**Optional:** `CM_M05_01` Choir Mass on parking level 3 (A05): Bloated Thrall x4, Thrall x12, Organ Grinder x1, Chorister x3.

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M05_Decibel` | Entering the Decibel District: walls of amps, cheering civilians, music from every door |
| `EVT_M05_Linda` | Okafor hands over the Shredder |
| `EVT_M05_HarlanLive` | Harlan's live commentary (camera-triggered lines) |
| `EVT_M05_MastClimb` | Organ Grinder climbing the antenna mast in the finale |
| `EVT_M05_Harlan` | `CIN_M05_Harlan` + Pedalboard unlock |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Mute Cell #2** | A02: a maintenance tunnel behind the stalled train's last car — Downbeat the cracked track grating | Orange-fissured grating, violet glow below |
| S2 | **Heart Shard #4** | A03: top of a water tower, via 3 Harrow Anchors on rooftop antennas | Violet glow on the tower's crown |
| S3 | **Bootleg Tape #2** (Pit Trial: *"Riff Machine"*) | A04: a record shop's back room ("DEAD WAX RECORDS"), door opened by shooting the padlock | Violet "??" tag |
| S4 | **Master: *"Keep It Loud"* by THE LAST ENCORE HOUSE BAND** | A04: on the club's stage, in the drummer's kit case | — |
| S5 | **Effigy: Bloated Thrall** | A05: inside a concrete mixer drum (Harrow-yank the hatch) | Violet light from the mixer |
| S6 | **Reprise** | A06: stairwell — jump across the elevator shaft to a service door (Harrow Anchor on the shaft's cable) | Anchor visible across the shaft |
| S7 | **Rig Core** | A03: a sunken bus in a canal — reachable by grappling onto its roof (Harrow Anchor on the roof hatch) | Violet glow under the water line |
| S8 | **Brass Cache #1** | A02: ticket office behind the mezzanine | — |
| S9 | **Brass Cache #2** | A07: Harlan's studio shelf (after the fight) | — |
| S10 | **Sounding Station** | A04: a tattoo parlor's back room (Static sonar rig) | Beeping |
| S11–S15 | **Archive Stones** | A02, A03, A04 (×2), A06 | — |

**Archive entries:** `ARC_Loc_DecibelDistrict`, `ARC_Loc_BroadcastTower`, `ARC_Char_Harlan`, `ARC_Hist_RadioFreeStatic`, `ARC_Enemy_OrganGrinder`, `ARC_Enemy_BloatedThrall`, `ARC_Weapon_Shredder`, `ARC_Sys_Pedalboard`, `ARC_Tech_NoiseWall`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Kill 3 enemies with a single flung Bloated Thrall |
| 2 | Destroy an Organ Grinder's turret with a Power Chord |
| 3 | Kill 20 enemies with the Shredder during the Venue Siege |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M05_Explore` — "**Undercity**" | Metro, Low Wards | Sludgy, bass-heavy groove; dripping water rhythm |
| Decibel District diegetic | A04 | Multiple overlapping tracks from club doorways (lo-fi versions of soundtrack songs) — a "cacophony" preview of the finale |
| `MUS_M05_Combat_A` — "**Third Rail**" | ENC_01–02 | 165 BPM |
| `MUS_M05_Siege` — "**Last Encore**" | ENC_03 | Played "live" through the club PA (room-reverb processed, slightly boomy) — crowd cheers layered |
| `MUS_M05_Combat_B` — "**Heavy Machinery**" | ENC_04–05 | Industrial groove |
| `MUS_M05_Combat_C` — "**On Air**" | ENC_06 | Harlan's radio jingle is sampled into the intro |

---

## 8. Art & Lighting

* **Palette:** wet blacks, neon pinks/oranges/reds (no cyan neon — reserved for enemies; use magenta and amber), sodium streetlights, Static orange; Choir gold light only around the tower where Hymnfall lands.
* **Key props:** metro station kit (platforms, trains, escalators, ticket hall), flooded street kit (shallow water material with ripples, floating debris), rooftop props (water towers, AC units, antennas, scaffolding), nightclub kit (stage, mosh floor, bar, balconies, amp walls, speaker stacks, neon signs), construction yard (cranes, rebar, mixers), broadcast tower (stairwell core, transmitter hall with glowing vacuum tubes, antenna deck, studio booth with records and reel-to-reels).

---

## 9. New Assets Required (P1)

`SK_WPN_Shredder`, `SK_OrganGrinder`, `SK_ThrallBloated`, `SK_Harlan`, `PKP_PU_Tempo`, Pedalboard UI + `SM_Pedal_*` (16 pedal meshes for the hub/UI), metro kit, flooded-street water material, nightclub kit, amp-wall modular set, construction yard props, broadcast tower kit, neon sign set (fictional brands/bands).
