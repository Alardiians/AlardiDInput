# M26 — THE CLEF

| | |
|---|---|
| **Act** | VI — The Last Broadcast |
| **Location** | **The Clef** — the Unison's spiral citadel at the head of the Staves |
| **Kit** | `HARM` + `CHOIR_ARCH` (100%, most elaborate) + `SHIP` (the rammed Quietus embedded in the wall) |
| **Target duration** | 80 min (incl. ~12 min mech segment) |
| **Priority** | P1 |
| **Story beats** | BEAT_M26_1 → BEAT_M26_5 |
| **New** | Mech segment #3 (Anvil Mk2 inside the Clef), **the Gauntlet** (chained arenas), Lund's stretcher-drone escort (from here to the end), Locris's last stand (ally) |
| **Landmark** | **The Quietus**, rammed into the Clef's wall, its hull-speakers still blasting music into the citadel — visible from much of the level; and the Clef's spiral rising inward toward a blinding core |

---

## 1. Overview

Breach and gauntlet. The Key of the Unresolved opened the Clef's outer gate, but its inner walls are sealed. Tamsin signs "*Hold on*" — and rams the 400 m Quietus into the Clef's wall. The ship tears a hole and embeds itself, becoming a burning, singing landmark inside the enemy's citadel. From there: the last Anvil ride through the Clef's outer rings, Locris holding the inner gate, and a gauntlet of every enemy the Choir has left.

**Experience goals:** maximum momentum; emotional beats between fights (Tamsin, Locris, Lund); every enemy type in escalating combinations — a final exam before the final boss.

---

## 2. Level Flow

```
[CIN_M26_Ram] → [A01 The Wreck-Bridge (the Quietus's bow)] ENC_01 (crew defending; Lund's drone joins)
   → [A02 The Outer Rings — MECH] MECH_01 (spiral ramp), MECH_02 (the Ring Plaza: Colossus + Walkers)
   → [A03 The Inner Gate] CIN_M26_Veyl (Locris holds the gate)
   → [A04 The Gauntlet: Line I] ENC_02 → [Line II] ENC_03 → [Line III] ENC_04 → [Line IV] ENC_05   (+CM_M26_01, CM_M26_02 as side-branches)
   → [A05 The Core Door] (breather; final loot) → (M27)
```

### CIN_M26_Ram
* `CIN_M26_Ram` (FP, from the Unsung's position on the Quietus's bridge beside Tamsin): the Clef's inner wall rushes toward the window; Tamsin signs "✋ *Hold on*"; impact; darkness; alarms; the ship is embedded. Tamsin, bleeding, grins and signs: "✋ *Nailed the landing.*" Vire: "*Everybody who can hold a gun, on me. Breaker — go.*"

### A01 — The Wreck-Bridge, ENC_M26_01
* **Space:** the Quietus's shattered bow section jammed into the Clef's interior: torn decks, exposed anechoic wedges, the Launch Bay open to a vast Choir chamber (the ship's familiar interior now a ruined bridgehead). The crew defend the breach with everything they have. The arena spans the ship's broken bow (3 torn decks) and the Choir chamber floor beyond (80 × 60 m).
* **Lund joins:** after the arena, Lund's **stretcher-drone** (from M19) floats out of the med-bay and follows the Unsung for the rest of the game (invulnerable; Lund hums, his gilding spreading; his lines are the emotional thread through M26–M27).

### A02 — The Outer Rings (Mech)
* Wren drops the **Anvil Mk2** from the Quietus's cargo bay ("*Last ride, big girl.*"). **MECH_M26_01:** the Clef's outer spiral ramp (a 60 m wide ramp spiraling inward for 1 km), infantry swarms, Organ Walkers, mech-scale Chime Turrets. **MECH_M26_02:** the **Ring Plaza** — a Choir Colossus and 2 Organ Walkers, a Seraphim gunship overhead.
* The Anvil's final moment: at the Inner Gate it's too big to pass; the Unsung climbs out; the Anvil, damaged, stands guard at the gate (its Blast Horn keeps blasting on auto — a beautiful image of it defending the gate as the Unsung walks on).

### A03 — The Inner Gate
* `CIN_M26_Veyl`: the Inner Gate is sealed by a Choir host; the Key of the Unresolved opens it, and the Choir pours out — and **Locris** drops from above, one voice, holding a broken shield, and plants themself in the gateway: "*Go on. Be loud for both of us.*" Locris fights the host behind the Unsung (ally; never seen again; an Archive entry after the credits confirms they held the gate to the end).

### A04 — The Gauntlet
* **Space:** four chained arenas along the Clef's inner spiral, named after the lines of a staff (Line I–IV), each opening with a seal onto the next. Each is themed around a combination the player has mastered, escalating:
  * **Line I — "Voices"**: fodder swarms + Cantors + Maestros (links and summons).
  * **Line II — "Iron"**: Gilded enemies + Requiem Knights (plates and parries).
  * **Line III — "Air"**: flyers (Ophans, Seraphs, Hymnals, Vesper swarms) over a void arena of floating platforms.
  * **Line IV — "The Choir"**: everything, including 2 Carillons and 2 Gilded Profundos.
* Side-branches off Line II and Line III hold the two optional Choir Masses.

### A05 — The Core Door
* A breather: a long, quiet approach up a stair of light toward a door of pure gold (the core chamber). Loot fountain; a Sounding Station; the last Grudge and Null Cell caches. Lund: "*It's listening. It's been listening to us the whole way. I think it's... curious.*"

---

## 3. Encounters

```
ENC_M26_01  "The Wreck-Bridge"       Arena: A01 (3 torn decks of the bow + Choir chamber 80 x 60 m)   Seals: n/a
  Music: MUS_M26_Combat_A (the Quietus's hull-speakers play it diegetically — loud, huge)   Reward: 2 Brass + loot fountain
  Allies: Vire + 12 crew (invulnerable)
  W1 OnStart:             Thrall x14, Chorister x8
  W2 AliveBelow(8):       Maestro x1, Bulwark x4, Acolyte x6 (last Consonance stragglers)
  W3 AliveBelow(6):       Carillon x1, Gilded Crescendo x1
  W3b TimeElapsed(20s, W3): Thrall x6  [resource trickle]
  Final W4 AliveBelow(6): Gilded Profundo x1, Seraph x3, Siren x2, Chorister x6
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Harrow Spool x4
  Broadside: available (the Quietus's intact dorsal guns can still fire into the chamber)
```

```
MECH_M26_01  "Outer Spiral"      (mech)  Spiral ramp 1 km, 60 m wide
  Infantry swarms (Thrall x40, Chorister x16), TTN_OrganWalker x2, mech Chime Turret x6
  Repair crates: 3 (dropped from the Quietus)
MECH_M26_02  "Ring Plaza"        (mech)  Circular plaza 400 m
  TTN_ChoirColossus x1, TTN_OrganWalker x2, TTN_Seraphim x1
  Repair crates: 3
```

```
ENC_M26_02  "Line I — Voices"        Arena: 70 x 50 m spiral segment; galleries 8 m   Seals: 2
  Music: MUS_M26_Gauntlet (one continuous track across all four Lines, intensifying)   Reward: loot fountain
  W1 OnStart: Cantor x3, Chorister x8, Thrall x10
  W2 AliveBelow(6): Maestro x2, Hymnal x2
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 AliveBelow(6): Maestro x1, Echo x3, Fugue x3, Thrall x10
  Pickups: Health M x2, Plating M x2, ammo L x1 each
```

```
ENC_M26_03  "Line II — Iron"         Arena: 80 x 50 m; pillars; dais 2 m   Seals: 2
  Reward: loot fountain
  W1 OnStart: Requiem Knight x2, Bulwark x4, Thrall x8
  W2 AliveBelow(5): Gilded Bellwether x1, Gilded Canon x1
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  Final W3 AliveBelow(5): Gilded Profundo x1, Gilded Crescendo x1, Requiem Knight x1, Thrall x8
  Pickups: Health M x2, Plating M x3, Charge L x2 (plates!), Grudge x1
  Power-up: AMP
```

```
ENC_M26_04  "Line III — Air"          Arena: void with 7 floating platforms (15-25 m) + Note-Platform links   Seals: n/a
  Reward: loot fountain
  W1 OnStart: Vesper x16, Ophan x2
  W2 AliveBelow(8): Seraph x3, Hymnal x2
  W2b TimeElapsed(20s, W2): Vesper x8  [resource trickle]
  Final W3 AliveBelow(6): Ophan x3, Seraph x2, Wailer x10, Chorister x6 (platform-hopping)
  Pickups: Health M x2, Plating M x2, Ordnance L x2, Charge L x1
```

```
ENC_M26_05  "Line IV — The Choir"    Arena: 120 x 80 m; spiral ramp edges; Saturation pools; 2 Hymn Pylons   Seals: 2
  Reward: 3 Brass + big loot fountain
  W1 OnStart: Carillon x1, Chorister x10, Thrall x14
  W2 AliveBelow(8): Maestro x2, Requiem Knight x2
  W2b TimeElapsed(20s, W2): Thrall x6  [resource trickle]
  W3 AliveBelow(8): Gilded Profundo x2, Siren x2, Echo x2
  W3b TimeElapsed(25s): Thrall x12
  Final W4 AliveBelow(8): Carillon x1, Gilded Canon x1, Gilded Bellwether x1, Seraph x3, Fugue x2, Chorister x8
  Pickups: Health M x4, Plating M x4, ammo L each x2, Null Cell x2, Grudge x2, Harrow Spool x5
  Power-up: OVERDRIVE SURGE + TEMPO
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M26_Ram` | `CIN_M26_Ram` |
| `EVT_M26_LundDrone` | Lund's stretcher-drone joins |
| `EVT_M26_AnvilLastRide` | The Anvil's last ride; it stands guard at the Inner Gate, Blast Horn firing on auto |
| `EVT_M26_Veyl` | `CIN_M26_Veyl` — Locris holds the gate |
| `EVT_M26_Gauntlet` | Four chained arenas with a continuous music track |
| `EVT_M26_CoreDoor` | The quiet stair of light |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Tab #12: "Loudest"** (every sound effect ×2 louder relative to music; the Unsung's footsteps shake the camera — pure silliness) | A01: Wren's workshop in the wrecked bow (her note: "*For the victory lap.*") | — |
| S2 | **Effigy: Tamsin** | A01: on the Quietus's bridge, by her flight seat (visit the bridge — optional path up through the wreck) | — |
| S3 | **Master: *"Nailed the Landing"* by TAMSIN HALE** (a Deaf musician's percussion piece — felt as much as heard; heavy sub-bass and rhythm) | A01: Tamsin's quarters | Strong vibration (rumble) |
| S4 | **Reprise** | A04 Line III: on the highest floating platform | — |
| S5 | **Rig Core** | A02 (mech): a cache on the spiral ramp's inner wall (the Anvil punches it open) | — |
| S6 | **Brass Cache #1** | Line II side-branch (after `CM_M26_01`) | — |
| S7 | **Brass Cache #2** | Line III side-branch (after `CM_M26_02`) | — |
| S8 | **Sounding Station** | A05 | — |
| S9–S13 | **Archive Stones** | A01, A03, A04 (×2), A05 | — |

**Archive entries:** `ARC_Loc_Clef`, `ARC_Hist_TheRam`, `ARC_Char_Tamsin_Full`, `ARC_Tech_AnvilLastRide`, `ARC_Char_Locris_Gate` (sealed until post-credits: "*The Last Warden held the gate until the end.*").

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Complete the Gauntlet without using a Reprise |
| 2 | Kill a Choir Colossus while the Anvil is below 25% structure |
| 3 | Kill 3 Maestros before they complete a single summon in Line I |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M26_Combat_A` — "**Wreck**" | ENC_01 | Played diegetically through the Quietus's hull-speakers — slapback echo inside the Clef |
| `MUS_M26_Mech` — "**Last Ride**" | Mech | The Anvil theme's final, triumphant form |
| `MUS_M26_Gauntlet` — "**Five Lines**" | Gauntlet | One continuous 12-minute piece in 4 movements (Voices → Iron → Air → The Choir), each movement layering more |
| Core Door | A05 | Silence, the Arrhythm, Lund humming the main theme (off-key) |

---

## 8. Art & Lighting

* **Palette:** the Clef's interior is the most ornate Choir space: layered gold filigree, porcelain vaults, light pouring inward toward the core; the burning Quietus wreck (black hull, orange fire, Static paint) as the only human thing — a deliberate visual clash.
* **Key props:** the Quietus bow wreck (hero, reusing SHIP kit + exterior with damage), Clef interior spiral kit, Inner Gate (hero), gauntlet arena variants, stair of light, Core Door.

---

## 9. New Assets Required (P1)

Quietus bow-wreck set, Clef interior kit, Inner Gate, Anvil "auto-guard" state, Locris ally behavior (scripted), stretcher-drone (from M19), gauntlet arena set dressing, core door.
