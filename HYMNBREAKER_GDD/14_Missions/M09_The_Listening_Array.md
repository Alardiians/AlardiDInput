# M09 — THE LISTENING ARRAY

| | |
|---|---|
| **Act** | II — The Tuned Earth (finale) |
| **Location** | **The Listening Array** — a high-desert radio observatory of 60 dish antennas and the **Voss Institute for Xenoacoustics**, where the Signal was first received |
| **Kit** | `BRU` (desert/observatory variant) + `CHOIR` 40% → 80% (dishes grown into colossal bone ears) |
| **Target duration** | 85 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M09_1 → BEAT_M09_6 |
| **New** | **The Silencer**, Tether Coil mod, *Fuzz* pedal, Dead Silence power-up; enemies **Echo**, **Fugue**; mini-boss **The Tenebrae (2)** (Thale dies); defense objective |
| **Landmark** | **The Great Ear** — Dish 1, a 300 m radio telescope grown into a titanic bone-and-porcelain ear, its inner canal glowing gold, turned toward the sky |

---

## 1. Overview

Night in the desert. Stars, a thin moon, the Aureole's five remaining bands arching over the plateau. Sixty dishes point at the sky — most of them now *ears*. This is where humanity first heard the Hymn and fell in love with it.

Lund believes the original Signal recordings in the Institute's archive can reveal the Hymn's structure well enough to finish the weapon he and Wren have been designing: the **Silencer**. The Unsung must secure the Institute, defend its anechoic chamber while they build it, and then use it.

**Experience goals:** eerie exploration of the place where it all began; the Echo's "silence kills it" lesson; the thrill of the first Silencer shot against a colossal horde; a satisfying end to Thale; and the gut-punch twist: *they came because of you*.

---

## 2. Level Flow

```
[A01 Desert Highway] → [A02 Dish Field North] ENC_01 (Echo intro)   (+CM_M09_01)
   → [A03 Voss Institute — Main Building] (lore; Aurelia's office; the First Reception Room) ENC_02 (Fugue intro)
   → [A04 The Anechoic Chamber] ENC_03 "Assembly" (defense, 240 s) → SILENCER
   → [A05 The Great Ear] ENC_04 (Silencer horde) 
   → [A06 Dish Field South] MINI-BOSS: THE TENEBRAE (2) — Thale dies   (+CM_M09_02)
   → [A07 Correlator Hall] CIN_M09_Exposed (in-play) → ENC_05 FINALE → exfil
```

### A01 — Desert Highway
* The Drop Coffin lands on a desert highway leading to the plateau: a Consonance pilgrim checkpoint (abandoned), billboard ("THE SIGNAL: WE ARE NOT ALONE" — faded, pre-invasion tourism), a gas station diner (lore: a jukebox, posters of the Signal's first broadcast night). Joshua-tree-like desert plants gilded with porcelain.

### A02 — Dish Field North, ENC_M09_01
* **Space:** a grid of 20 dishes (each 25 m diameter on 20 m pedestals; many grown into bone ears) across 150 × 100 m of flat plateau with service roads, cable trenches and equipment huts. Dishes rotate slowly (Choir-driven) — their shadows sweep the ground under the Aureole's light. Dish pedestals have Grip Walls; the dish rims are high ground; Harrow Anchors on feed-horn struts.
* **Echo intro:** an **Echo** drifts among Troopers and possesses one (the Trooper's attacks begin repeating as ghost copies). Prompt when the host dies and the Echo emerges: `ECHOES can only be destroyed by SILENCE — [Q] HUSH CHARGE`. The player has had Hush since M03; a **Hush recharge crate** (`PKP_HushRefill`) sits near the intro spot.
* **Optional:** `CM_M09_01` at the dish-field maintenance depot.

### A03 — Voss Institute, ENC_M09_02
* **Space:** a low brutalist research building (3 floors) with glass atria, labs, offices, the **First Reception Room** (the control room where the Signal was first heard on 14 March 2196 — preserved by the Consonance as a shrine: velvet ropes, a plaque, gold flowers, the original tape reels in a glass case, Aurelia's chair).
* **Aurelia's office:** photos of her husband and daughter; a child's drawing; a crumpled note ("*It stopped hurting. For the first time in twenty years, it stopped.*"). Archive entries.
* **Fugue intro:** in the darkened **east lab wing** (power out; the Unsung's visor light only), a **Fugue** ambushes — splitting into illusions. Prompt: `FUGUES split into illusions — DISTORT or ARC COIL reveals them. The real one has a HALO and a SHADOW.`
* **Mod Crate: Arc Coil — Tether Coil** in the physics lab.

### A04 — The Anechoic Chamber, ENC_M09_03 "Assembly"
* **Space:** the Institute's giant anechoic test chamber — a cube 30 × 30 × 30 m lined on every surface with 1.5 m black foam wedges; a suspended steel-mesh floor at mid-height (15 m above the wedge-covered bottom); two gantry walkways above; entry doors on three sides of the mesh level. **Inside the chamber, the Hymn cannot be heard** — the level's ambient choir drops out. The **Silencer rig** stands at the center of the mesh floor on a workbench.
* **Script:** a Static dropship lands outside; **Wren and Lund** run in (first time the player sees Wren in person in a mission). They start assembling (`COM_M09_*` banter: Wren: "*Hand me the— no, the OTHER— ok the big guy doesn't do hand-me's, noted.*").
* **Defense rules:** 240 s timer; the Choir attacks through the three doors and by Hymnfall *outside* the chamber (they cannot Hymnfall *inside* — it's silent!), so enemies must walk in — chokepoint defense; **Echoes struggle inside the chamber** (they flicker and weaken: take damage over time inside it). Wren & Lund are invulnerable but enemies target the workbench (4000 HP; if destroyed, the timer rolls back 60 s — never a fail).
* **Completion:** Lund slams the last component in; Wren hands the Unsung the **Silencer** with 1 Null Cell: "*One shot. Maybe two if I find more cells. Please, PLEASE do not fire it inside.*" `PKP_Weapon_Silencer`.

### A05 — The Great Ear, ENC_M09_04
* **Space:** the base and bowl of Dish 1 — a 300 m bone ear. The player enters at the dish's base (a broad apron 120 × 80 m) and must climb into the **bowl** (a vast concave surface of porcelain with ridges; the "ear canal" at the center glows gold).
* **Silencer moment (scripted):** at the apron, a **horde of ~40 enemies** pours over the dish rim and down the bowl (Thralls, Choristers, Troopers, 2 Crescendos) — a HUD prompt: `[G] THE SILENCER`. The shot clears the apron in 1.5 seconds of total silence. Then the real arena begins in the bowl.
* **Dead Silence** power-up introduced in the bowl.

### A06 — Dish Field South: MINI-BOSS THE TENEBRAE (2)
* **Space:** 12 dishes in a tighter cluster (90 × 90 m), with a central control hut; four chanter platforms on dish rims (the Choir Shield's Acolyte cantors).
* **Fight:** `10_Bosses.md` §2 (M09 version, 7000 HP, full fight). Thale: "*You don't even know what you are, do you? I read the files. You're the reason they came.*" (Seeds the twist.) **Boss Breakdown:** the cockpit tear-open; Thale pulled out; cut on impact.

### A07 — Correlator Hall, ENC_M09_05 (FINALE)
* **Space:** the Array's correlator: a vast hall (60 × 40 m, 12 m tall) of server racks and cooling towers, with a mezzanine control deck (5 m), a huge wall of screens, and a cable-trench floor.
* **Script:** entering the hall, every screen lights up: `CIN_M09_Exposed` — **Aurelia's broadcast** (in-play; the player can keep moving; screens can be shot out one by one, but the audio continues on every frequency): the 2194 recording of the Vault ringing, and "*They did not come for you, children. They came for **it**.*"
* Then the Choir attacks → finale. After it: a Static dropship extracts the Unsung, Wren and Lund. Lund doesn't speak the whole flight.

---

## 3. Encounters

```
ENC_M09_01  "Dish Field North"      Arena: A02 (150 x 100 m; dishes; pedestals 20 m; rims 25 m)   Seals: bone growths on the service roads
  Music: MUS_M09_Combat_A            Reward: 1 Brass + loot fountain
  W1 OnStart:             Trooper x6, Echo x1 (possesses a Trooper), Thrall x6                [Echo intro]
  W2 AliveBelow(4):       Chorister x4 (dish rims), Marksman x2 (feed horns), Thrall x6
  W3 AliveBelow(4):       Echo x1, Bellwether x1, Crescendo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(3): Seraph x2, Hymnal x1, Thrall x8
  Pickups: Hush refill crate x2, Health S x8, Plating M x1, Rounds L x1, Charge L x1
```

```
ENC_M09_02  "East Labs (dark)"      Arena: A03 east wing (labs 50 x 30 m, corridors loop, 2 floors)   Seals: 3
  Music: MUS_M09_Combat_B (sparse, tense)   Reward: 1 Brass + loot fountain
  W1 OnStart:             Fugue x1, Thrall x6                                                [Fugue intro]
  W2 AliveBelow(3):       Acolyte x6, Zealot x2
  W3 AliveBelow(4):       Fugue x2, Siren x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(3): Echo x1, Cantor x1, Bulwark x2, Acolyte x4
  Pickups: Health S x6, Plating S x4, Charge L x1, Shells L x1
  Notes: visibility low; enemy halos and rim lights are the main readability cue here.
```

```
ENC_M09_03  "Assembly" (defense)    Arena: A04 anechoic chamber mesh level (30 x 30 m) + 3 door approaches   Timer: 240 s
  Music: MUS_M09_Anechoic (the music is muffled/dry inside the chamber — no reverb — a deliberate, eerie mix)
  Reward: THE SILENCER + 2 Brass + loot fountain
  T+0:    Thrall x10 (all doors), Trooper x4
  T+40:   Chorister x4, Echo x1 (weakened inside), Bulwark x2
  T+80:   Crescendo x2 (through the east door), Thrall x8
  T+120:  Fugue x2, Siren x1, Acolyte x6
  T+160:  Bellwether x1, Canon x1 (at the north door, shelling in), Thrall x8
  T+200:  Echo x2, Hymnal x1, Chorister x3
  Completion: timer at 240 s AND remaining enemies killed
  Pickups: Health M x2, Plating M x2, ammo L x1 each type, Harrow Spool x3, Hush refill crate x1 (respawn at T+120)
```

```
ENC_M09_04  "The Great Ear"         Arena: A05 apron (120 x 80 m) → bowl (concave, 200 m wide, ridges)   Seals: n/a (open; the bowl rim is the boundary)
  Music: MUS_M09_Combat_C            Reward: 2 Brass + big loot fountain
  Scripted: HORDE (tag `Horde`; ~40: Thrall x20, Chorister x8, Trooper x8, Crescendo x2, Bloated Thrall x2) over the rim → Silencer prompt
  W1 KilledTag(Horde):    Seraph x2, Chorister x4, Thrall x8
  W2 AliveBelow(4):       Echo x2, Bellwether x1, Canon x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  W3 AliveBelow(4):       Ophan x2, Vesper x8, Hymnal x1
  Final W4 AliveBelow(4): Crescendo x2, Cantor x1, Fugue x1, Chorister x4, Thrall x8
  Pickups: Null Cell x1 (bowl ridge — hidden-ish, visible from the ear canal), Health M x2, Plating M x2, ammo L each, Harrow Spool x3
  Power-up: DEAD SILENCE (in the ear canal's mouth)
```

```
BOSS_Tenebrae_2  "Dish Field South"  Arena: A06   (10_Bosses.md §2, M09 version)
  Music: MUS_BOSS_Tenebrae (reprise, heavier)
  Resource adds every 25 s: Acolyte x3 / Thrall x4
  Reward: 2 Brass + big loot fountain
```

```
ENC_M09_05  "Correlator Hall" (FINALE)  Arena: A07 (60 x 40 m, 12 m; mezzanine 5 m; server aisles)   Seals: 3
  Music: MUS_M09_Combat_C (finale)    Reward: 2 Brass + big loot fountain
  W1 OnStart:             Acolyte x8, Zealot x4, Echo x1
  W2 AliveBelow(5):       Fugue x2, Siren x1, Thrall x8
  W3 AliveBelow(5):       Bellwether x1, Canon x1, Cantor x1, Chorister x3
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Requiem Knight x1, Echo x2, Seraph x1, Acolyte x6
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1 (mezzanine), Harrow Spool x3
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M09_Diner` | The gas-station diner jukebox plays the pre-invasion news broadcast of the Signal (audio log) |
| `EVT_M09_FirstReception` | The shrine room; the original reels; optional interact: play the reel — 5 s of the original Signal (the player *hears how beautiful it is*) → the Unsung shuts it off (`GST_SwitchOff`), unprompted |
| `EVT_M09_WrenLund` | Wren & Lund arrive in person |
| `EVT_M09_Silencer` | Silencer handed over; horde; first shot (hard audio duck to silence for 1.5 s) |
| `EVT_M09_Thale` | Tenebrae destroyed; Thale pulled from the cockpit |
| `EVT_M09_Exposed` | `CIN_M09_Exposed` — Aurelia's broadcast on every screen |
| `EVT_M09_Exfil` | Dropship extraction; Lund silent |
| Hub | `CIN_HUB_Confession` on return |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #7** | A02: the feed-horn cabin of the tallest dish (Grip Wall pedestal → rim → Harrow Anchor on the strut) | Violet glow in the cabin |
| S2 | **Bootleg Tape #4** (Pit Trial: *"Echo Chamber"* — Echo-heavy waves) | A01: the diner's jukebox (interact; the tape is inside) | A jukebox with a violet "??" sticker |
| S3 | **Pedal: Fuzz** | A03: Aurelia's office safe — the combination is written on the back of her daughter's drawing (interact with the drawing, then the safe) | The drawing is highlighted with a violet glint |
| S4 | **Effigy: Echo** | A04: the chamber's wedge-covered bottom (15 m below the mesh floor) — Downbeat through a loose mesh panel; a service ladder back up | Violet glow through the mesh |
| S5 | **Effigy: Fugue** | A03: east lab wing, a sealed cold-storage room (Power Chord the door) | — |
| S6 | **Master: *"Signal Lost"* by THE KUIPER BELT** | A05: inside the Great Ear's canal (after the arena) | Music echoing from the canal |
| S7 | **Rig Core** | A06: the central control hut's roof hatch (Downbeat) | — |
| S8 | **Brass Cache #1** | A01: gas station storage | — |
| S9 | **Brass Cache #2** | A07: server aisle 14, behind a rack (Harrow-yank the rack) | Violet tag on the rack |
| S10 | **Sounding Station #1** | A02: maintenance depot | — |
| S11 | **Sounding Station #2** | A03: Institute rooftop observatory | — |
| S12–S17 | **Archive Stones** | A01, A03 (×3), A05, A07 | — |

**Archive entries:** `ARC_Loc_ListeningArray`, `ARC_Hist_TheSignal`, `ARC_Hist_FirstReception`, `ARC_Char_Aurelia_Past`, `ARC_Doc_AureliaNote`, `ARC_Enemy_Echo`, `ARC_Enemy_Fugue`, `ARC_Weapon_Silencer`, `ARC_Char_Thale_Death`, `ARC_Hist_TheRinging` (unlocked by the broadcast).

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Destroy 5 Echoes with Hush Charges |
| 2 | Kill 30+ enemies with the first Silencer shot |
| 3 | Complete "Assembly" with the workbench above 50% health |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M09_Explore` — "**Deep Field**" | Desert, dishes | Spacious, starry; a theremin-like lead (the Signal's melody, detuned into menace) |
| `MUS_M09_Combat_A` — "**Radio Silence**" | ENC_01 | 160 BPM |
| `MUS_M09_Combat_B` — "**Interference**" | ENC_02 | Sparse, stabbing, dark |
| `MUS_M09_Anechoic` — "**Dead Room**" | ENC_03 | Dry, no reverb, claustrophobic |
| `MUS_M09_Combat_C` — "**The Great Ear**" | ENC_04–05 | Colossal |
| The original Signal | EVT_M09_FirstReception | A beautiful, unearthly choral-synth phrase — must sound genuinely lovely |
| Silencer | EVT_M09_Silencer | 1.5 s total silence (even UI sounds muted), then a heavy "air rushing back in" |

---

## 8. Art & Lighting

* **Palette:** night desert — deep indigo sky, silver starlight, the Aureole's five bands casting soft colored light; sodium lights at the Institute; gold glow from the ears' canals.
* **Key props:** 60 dishes (3 sizes; normal + ear variants; rotating), feed horns and cabins, equipment huts, diner & gas station, Institute building (brutalist + glass), First Reception Room shrine, anechoic chamber (wedge tiles, mesh floor — hero space), Great Ear (hero asset), correlator hall.

---

## 9. New Assets Required (P1)

`SK_Echo` (translucent/ghost material system), `SK_Fugue` (+ illusion material), `SK_WPN_Silencer` (+ projectile & tendril VFX), `PKP_NullCell`, `PKP_PU_DeadSilence`, `PKP_HushRefill`, `SK_Wren`, `SK_Lund` (in-person), dish antenna set (+ ear variants, rotation BP), diner kit, Institute kit, anechoic chamber kit, `SM_GreatEar`, correlator hall kit, Tenebrae M09 damage states.
