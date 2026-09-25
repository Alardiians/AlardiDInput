# M15 — CRYOBORE

| | |
|---|---|
| **Act** | IV — Deep Water, High Air |
| **Location** | **Cryobore Station**, Europa (moon of Jupiter): a drilling complex above a 20 km borehole through the ice shell, down to the subsurface ocean |
| **Kit** | `ICE` (ice caverns, drill machinery, pressure habitats) + `BRU` (station interiors) + `CHOIR` 20% → 60% (Aeolian growth: translucent blue-white porcelain like frozen tears, coral-like organ pipes) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M15_1 → BEAT_M15_5 |
| **New** | *Looper* pedal; enemies **Carillon**, **Gilded Bellwether**; non-slippery ice (visual only — see §1), pressure doors, descending elevator arena; Leviathan foreshadow |
| **Landmark** | **Jupiter** filling half the sky above the ice; and **the Bore** — a 60 m wide vertical shaft into the ice, glowing blue from below, with a faint whale-song rising from its depths |

---

## 1. Overview

A new Act, a new world. The Quietus returns from Mercury scarred and grieving; Lund is gone; his collar's tracker pinged last from Jupiter space before going dark. Vire's call: strike the **Aeolian Spire** under Europa's ice while Wren refines the trace.

**Experience goals:** alien beauty — Jupiter looming, ice cathedrals, a singing ocean below; a **descent** mission (from the surface down 20 km); the first **Carillon** (a walking bell-tower titan — the "arena boss" enemy); the first **Gilded** armored enemy; and the dread of something enormous moving behind the ice.

**Ice rule:** ice floors are **not slippery** (keeps movement consistent); ice is visual only. Some ice walls are **breakable** (Downbeat/explosives) and some are **Grip Walls** (with the standard orange trim — climbing spikes hammered in by the station crew).

---

## 2. Level Flow

```
[A01 Surface Landing — Ice Plain] → [A02 Cryobore Station Topside] ENC_01
   → [A03 Drill Hall (top of the Bore)] ENC_02 (Gilded Bellwether intro)
   → [A04 The Descent — Bore Elevator (moving arena)] ENC_03
   → [A05 Mid-Bore Camp (ice caverns, km 8)] ENC_04 (Carillon intro)   (+CM_M15_01, CM_M15_02)
   → [A06 Ice Cathedral (natural cavern, km 14)] (traversal; Leviathan shape behind the ice)
   → [A07 Pressure Locks & Lower Pump Station (km 19)] ENC_05 FINALE
   → [A08 Ocean Habitat Arrival] (end: viewports onto the dark sea)
```

### A01 — Surface Landing: Ice Plain
* The Drop Coffin skids across the ice. **Jupiter** fills half the sky, its storms slowly turning; the Sun is a small bright star; the Aureole is not visible here (we're far from Earth) — instead, faint auroras of Hymn-light ripple over the ice. Cracked ice ridges; the station ahead; plumes of vapor jetting from fissures (cosmetic).
* Radio intro (`RAD_M15`, "For Juno").

### A02 — Cryobore Station Topside, ENC_M15_01
* **Space:** a cluster of insulated modules (living quarters, garages with ice crawlers, comms tower) connected by covered walkways, around a central plaza (the landing pad, 50 × 50 m). Snow-like ice dust blowing.

### A03 — Drill Hall, ENC_M15_02
* **Space:** a huge enclosed hall (80 × 60 m, 40 m tall) over the Bore's mouth: the drill derrick (60 m tall — climbable with Grip Walls and anchors), pipe racks, mud tanks, control cabins on walls. The Bore itself (60 m wide) is in the hall's center, fenced — the void glows blue.
* **Gilded Bellwether intro:** a Bellwether with thick gold armor plates. Prompt: `GILDED enemies can't Falter until their PLATES break — POWER CHORD, ENERGY or HOT RIVETS shatter them`.

### A04 — The Descent: Bore Elevator, ENC_M15_03
* **Space:** a massive service elevator platform (30 × 30 m, with a control cabin and cargo) descending the Bore. The Bore walls (ice, with embedded drill rings and lights every 50 m) scroll past; the blue glow grows.
* **Moving arena:** enemies descend on the platform from the walls (Choristers climbing), fly in (Vespers, Ophans), and Hymnfall onto it. The descent is gated by the encounter (like M03).

### A05 — Mid-Bore Camp (km 8), ENC_M15_04
* **Space:** a camp carved into the Bore wall: a horizontal ice cavern (100 × 60 m, 25 m tall) with prefab huts, drill-bit storage, a crane over the Bore, ice pillars, and Aeolian growth (translucent blue-white porcelain "frozen tear" formations, coral-like organ pipes).
* **Carillon intro:** the far end of the cavern: a **Carillon** — a walking bell tower — steps out of an ice tunnel, its bells ringing. Prompt: `CARILLON — shoot its BELLS to silence its barrages and summons`. Lund's absence is felt: Wren does the analysis on comms ("*Okay, it's a bell tower. With legs. Doc would have a name for this. I just have swear words.*").
* **Optional:** `CM_M15_01` (drill storage), `CM_M15_02` (collapsed hab).

### A06 — Ice Cathedral (km 14)
* **Space:** a vast natural cavern (300 m long, 100 m tall) of blue ice with towering ice columns, frozen waterfalls, and **clear ice walls** through which the player sees **the Leviathan** pass (a 60 m silhouette gliding in the water beyond the ice, eyes glowing, singing — a deep whale-song choir that makes the ice resonate and crack).
* Traversal: Grip Walls on ice columns (crew spikes), Harrow Anchors on drill rigs left in the ice, Swing Poles on scaffolding, Kick Pads; light combat (Choristers, Vespers, Sirens emerging from meltwater pools).
* **Set piece (`EVT_M15_Leviathan`):** the Leviathan rams the ice wall; cracks race across it; the player must run as a section collapses behind them (chase, 20 s, non-lethal fail = restart the chase checkpoint).

### A07 — Pressure Locks & Lower Pump Station (km 19), ENC_M15_05 (FINALE)
* **Space:** the lowest station level, just above the ocean: pressure lock chambers (heavy round doors), a pump station hall (60 × 50 m) with water-intake pipes (2 m diameter) and a sump pit (void) where ocean water surges.
* The finale features **a second Carillon** alongside Gilded Bellwethers.

### A08 — Ocean Habitat Arrival
* The final pressure lock opens into the **ocean habitat** (a dome at the bottom of the Bore): viewports onto the black ocean full of slowly drifting golden lights. A distant sound — singing. Mission complete.

---

## 3. Encounters

```
ENC_M15_01  "Topside"               Arena: A02 (plaza 50 x 50 m + walkways + module roofs 5 m)   Seals: 3
  Music: MUS_M15_Combat_A            Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Tuned drill crew in parkas), Trooper x4
  W2 AliveBelow(5):       Chorister x4, Siren x1
  W3 AliveBelow(4):       Seraph x2, Bulwark x2, Thrall x6
  Final W4 AliveBelow(3): Profundo x1, Chorister x3
  Pickups: Health S x8, Plating M x1, ammo L x1 (Shells, Charge), Harrow Spool x2
```

```
ENC_M15_02  "Drill Hall"            Arena: A03 (80 x 60 m, 40 m; derrick; wall cabins 8 m; the Bore void)   Seals: 2
  Music: MUS_M15_Combat_A            Reward: 1 Brass + loot fountain
  W1 OnStart:             Gilded Bellwether x1, Thrall x8                                     [Gilded intro]
  W2 AliveBelow(4):       Chorister x4 (derrick), Marksman x2 (wall cabins)
  W3 AliveBelow(4):       Canon x1, Echo x1, Thrall x6
  Final W4 AliveBelow(3): Gilded Bellwether x1, Crescendo x1, Siren x1, Chorister x3
  Pickups: Health M x1, Health S x6, Plating M x2, Charge L x1 (plates!), Rounds L x1
  Notes: Bore void — knockback kills.
```

```
ENC_M15_03  "Bore Elevator" (moving)  Arena: A04 (30 x 30 m platform + cabin roof 4 m)
  Music: MUS_M15_Descent             Reward: 1 Brass + loot fountain
  W1 OnStart:             Chorister x6 (climbing the walls onto the platform), Vesper x6
  W2 AliveBelow(5):       Ophan x2, Wailer x6
  W3 AliveBelow(4):       Hymnal x1, Seraph x1, Thrall x6 (Hymnfall)
  Final W4 AliveBelow(3): Gilded Bellwether x1, Chorister x4
  Pickups: Health S x6, Plating S x4, Ordnance L x1, Charge S x2
```

```
ENC_M15_04  "Mid-Bore Camp"         Arena: A05 (100 x 60 m cavern, 25 m; huts; ice pillars; crane)   Seals: 3
  Music: MUS_M15_Combat_B            Reward: 2 Brass + loot fountain
  W1 OnStart:             Carillon x1 (from the ice tunnel), Thrall x8                         [Carillon intro]
  W1b TimeElapsed(20s):   Thrall x6                                                            [resource trickle]
  W2 KilledTag(Carillon) OR AliveBelow(4): Fugue x2, Chorister x4, Bulwark x2
  W3 AliveBelow(4):       Profundo x1, Siren x1, Echo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(4): Gilded Bellwether x1, Canon x1, Cantor x1, Thrall x8
  Pickups: Health M x2, Plating M x2, Rounds L x1, Charge L x2, Null Cell x1, Harrow Spool x3
  Power-up: AMP (crane cab)
```

```
ENC_M15_05  "Lower Pump Station" (FINALE)  Arena: A07 (60 x 50 m; intake pipes as cover; sump void; catwalks 6 m)   Seals: 3 (pressure doors)
  Music: MUS_M15_Combat_C            Reward: 2 Brass + big loot fountain
  W1 OnStart:             Siren x2 (from the sump), Chorister x4, Thrall x8
  W2 AliveBelow(5):       Carillon x1, Bulwark x3
  W3 AliveBelow(5):       Gilded Bellwether x1, Hymnal x1, Echo x1
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Profundo x1, Seraph x2, Crescendo x2, Chorister x3
  Pickups: Health M x2, Plating M x2, ammo L each, Harrow Spool x3
  Power-up: OVERDRIVE SURGE (catwalk above the sump)
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M15_Jupiter` | First vista of Jupiter over the ice |
| `EVT_M15_Descent` | Bore elevator moving arena |
| `EVT_M15_Carillon` | Carillon stepping out of the ice tunnel, bells pealing |
| `EVT_M15_Leviathan` | The Leviathan's silhouette; the ice-wall collapse chase |
| `EVT_M15_Ocean` | Arrival at the ocean habitat; viewports onto the singing sea |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #11** | A03: top of the drill derrick's crown block (60 m climb) | Violet glow at the derrick top |
| S2 | **Mute Cell #6** | A02: inside an ice crawler in the garage (Harrow-yank its door) | — |
| S3 | **Bootleg Tape #7** (Pit Trial: *"Cold Open"* — start with 1 HP and no Plating; Breakdowns only heal) | A05: collapsed hab (after `CM_M15_02`) | — |
| S4 | **Pedal: Looper** | A06: frozen inside an ice column — break it with explosives/Downbeat from above | Violet glow inside the ice |
| S5 | **Effigy: Carillon** | A05: on the crane's hook block over the Bore (Harrow Anchor + jump) | — |
| S6 | **Master: *"Under the Ice"* by THE DEEP SIX** | A02: the comms tower's operator room (radio playing) | Music |
| S7 | **Reprise** | A04: the elevator's control cabin roof hatch — only reachable during the ride's W1 (Grip Wall on the cabin) | — |
| S8 | **Rig Core** | A06: behind a frozen waterfall (Hammerfall/Frag shatters it) | Violet light through the ice |
| S9 | **Brass Cache #1** | A05: drill storage (after `CM_M15_01`) | — |
| S10 | **Brass Cache #2** | A07: pressure lock B's control closet | — |
| S11 | **Sounding Station** | A05: the camp's survey hut | — |
| S12–S16 | **Archive Stones** | A01, A02, A05, A06, A08 | — |

**Archive entries:** `ARC_Loc_Europa`, `ARC_Loc_Cryobore`, `ARC_Archon_Aeolian` (partial), `ARC_Enemy_Carillon`, `ARC_Enemy_Gilded`, `ARC_Titan_Leviathan` (partial), `ARC_Hist_CryoboreCrew`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy all 4 bells of a Carillon before killing it |
| 2 | Break a Gilded Bellwether's plates with a single Power Chord |
| 3 | Complete the Bore Elevator arena without falling or being knocked into the Bore |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M15_Explore` — "**Jovian**" | Surface, caverns | Glacial post-metal; low whale-song choir (Aeolian's voice) from below — melancholy |
| `MUS_M15_Combat_A` — "**Cryo**" | ENC_01–02 | 160 BPM, cold, tremolo-picked |
| `MUS_M15_Descent` — "**Twenty Kilometers**" | ENC_03 | Descending chord progression, accelerating |
| `MUS_M15_Combat_B` — "**Carillon**" | ENC_04 | Bell-tuned riffs; actual bell samples on the downbeats |
| `MUS_M15_Combat_C` — "**Pressure**" | ENC_05 | Heavy, claustrophobic |
| Leviathan song | A06 | Whale-song choir, sub-bass, ice creaks & cracks |

---

## 8. Art & Lighting

* **Palette:** blue-white ice, black space, Jupiter's ochre and cream bands, warm sodium station lights, Aeolian growth in translucent pale blue with gold veins; (avoid pure cyan for scenery near enemies — use desaturated ice blue and keep enemy cyan saturated and emissive).
* **Key props:** ice terrain & cavern kit (translucent ice material with subsurface scattering), insulated modules, drill derrick (hero), Bore shaft (modular rings), service elevator platform, mid-bore camp, ice columns & frozen waterfalls (breakable), pressure-lock doors, pump station, ocean habitat viewports; Jupiter skybox.

---

## 9. New Assets Required (P1)

`SK_Carillon`, `SK_BellwetherGilded` (plate attachments + break states), ICE kit, drill derrick, Bore shaft kit, elevator platform, `TTN_Leviathan` (silhouette/animation for behind-ice passes), breakable ice meshes, Europa skybox (Jupiter + auroras), pressure-lock door, Thrall parka variant.
