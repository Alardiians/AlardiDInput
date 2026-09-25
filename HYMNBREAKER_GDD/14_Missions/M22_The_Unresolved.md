# M22 — THE UNRESOLVED

| | |
|---|---|
| **Act** | V — The Unsung |
| **Location** | **The Unresolved** — Locris's domain: a district of Aubade that never resolves. Streets loop, stairs return to their own beginnings, rooms rotate whenever the chord changes |
| **Kit** | `OREN` (reassembled impossibly) + `HARM` (golden void visible through gaps) + `CHOIR` (cracked, flickering gold — Locris's unstable growth) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M22_1 → BEAT_M22_3 |
| **New** | **Heartbeat navigation** ("follow your heart"), chord-change rotating rooms, **Requiem Gate #7**; enemy **Gilded Canon**; **Boss: Locris, the Unresolved** |
| **Landmark** | **Locris's broken halo** — a colossal ring of cracked light with a gap in it, hanging in the sky over the district, flickering irregularly |

---

## 1. Overview

Locris leads the Unsung through their domain, speaking in fragments as the player fights: the truth of the First Unison, of Veyl, of the Unsung. The district's architecture reflects its master: nothing resolves. Paths change on **chord changes** (every 30 s, the music changes chord and the district's geometry rotates or rearranges).

**The mission's navigation idea — "follow your heartbeat":** in the Unresolved, the correct way forward is where **the Unsung's own heartbeat** (the Arrhythm) sounds loudest. The player navigates partly by ear. (Accessibility: the compass shows a pulsing heart icon in the correct direction; option "Visual Heartbeat Guide" on by default on Lullaby/Unplugged.)

**Experience goals:** a mind-bending but fair level; revelation through dialogue during play (not cutscenes); an emotional boss fight against a friend that ends in mercy.

---

## 2. Level Flow

```
[A01 The Returning Street] (heartbeat navigation tutorial)
   → [A02 The Stair That Returns] (break the loop with Downbeat)
   → [A03 The Rotating Plaza] ENC_01 (chord-change rotations; Gilded Canon intro)   (+CM_M22_01)
   → [A04 The Garden of Old Wars] (Locris's memories) ENC_02   (+CM_M22_02)
   → [A05 The Unresolved Plaza] BOSS: LOCRIS → CIN_M22_Halo → (return to Earth: M23)
   Optional: [Requiem Gate #7] in A04
```

### A01 — The Returning Street
* **Space:** a street of pale Oreth houses that curves back into itself (walk forward long enough and you return to the start). Side alleys branch off; only one is "real" at a time — the one where the Arrhythm heartbeat grows louder. Every 30 s, a chord change: the street's houses rotate on their foundations (a grinding stone sound), changing which alleys are open.
* Locris's voice (V.O., throughout the mission; lines trigger on progress): "*You never could walk in a straight line, Shieldwarden. Neither can this place.*"

### A02 — The Stair That Returns
* **Space:** a Penrose-like staircase: climbing it forever returns to the same landing. The way out: a cracked landing (orange fissures) — **Downbeat** through it to break the loop and fall into the district below. (A prompt appears after 60 s: "*Some things can only be resolved by breaking them.*" — Locris.)

### A03 — The Rotating Plaza, ENC_M22_01
* **Space:** a circular plaza (70 m) divided into **4 rotating quadrants** (each quadrant is a raised platform section with houses, 3–8 m high); on each chord change (every 30 s, telegraphed 3 s ahead by a rising chord + dust falling), the quadrants rotate 90° around the plaza center, changing sightlines, cover and routes. Enemies ride the rotations too.
* **Gilded Canon intro** (echo shells that echo *twice*).
* **Optional:** `CM_M22_01` in a house that only exists in one rotation state.

### A04 — The Garden of Old Wars, ENC_M22_02
* **Space:** a terraced garden where Locris keeps **memories** as statues: scenes from the Oreth wars — two Shieldwardens back to back (the Unsung and Veyl); a shield raised over a child; a camp at night. Lore stones reveal their history. The arena is the garden's lower terraces (60 × 50 m, 3 levels).
* **Requiem Gate #7** is hidden in the garden's grotto.
* Locris (V.O.): "*I held your shield for three hundred years. Do you remember the Siege of the Nine Bells? You carried me out on your back. You were so loud that night. I've never heard anything so loud.*"
* **Optional:** `CM_M22_02` in the grotto antechamber.

### A05 — The Unresolved Plaza: BOSS LOCRIS
* `10_Bosses.md` §11. Three shifting configurations (Open Plaza / Pillar Maze / Stair Tower), phases Shieldwarden → Unresolved Strikes (parry only the **ringing** strikes — silent strikes are illusions) → Two Voices.
* Ends in `CIN_M22_Halo`: Locris breaks their halo (the seventh Aureole band dies), gives the Unsung the **Key of the Unresolved**, and the sky flares white — Aurelia is singing the Octave alone. Vire: "*Get back here. NOW.*"

---

## 3. Encounters

```
ENC_M22_01  "Rotating Plaza"         Arena: A03 (70 m circle; 4 rotating quadrants 3-8 m; chord change every 30 s)   Seals: n/a (streets rotate shut)
  Music: MUS_M22_Combat_A (chord changes are the rotation telegraphs)   Reward: 2 Brass + loot fountain
  W1 OnStart:             Chorister x6, Bulwark x3, Thrall x8
  W2 AliveBelow(5):       Gilded Canon x1, Cantor x1                                           [Gilded Canon intro]
  W3 AliveBelow(4):       Fugue x2, Siren x2, Echo x1
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Gilded Profundo x1, Maestro x1, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Grudge x1, Harrow Spool x3
```

```
ENC_M22_02  "Garden of Old Wars"     Arena: A04 (60 x 50 m; 3 terraces 4 m apart; memory statues as cover)   Seals: 2
  Music: MUS_M22_Combat_B             Reward: 2 Brass + big loot fountain
  W1 OnStart:             Requiem Knight x2, Chorister x6
  W2 AliveBelow(5):       Carillon x1, Thrall x8
  W3 AliveBelow(5):       Gilded Canon x1, Gilded Bellwether x1, Seraph x2
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Maestro x1, Gilded Crescendo x1, Ophan x2, Chorister x4
  Pickups: Health M x3, Plating M x3, ammo L each, Null Cell x1, Grudge x1, Harrow Spool x3
  Power-up: AMP (the "back to back" memory statue's plinth)
```

**Boss:** `BOSS_Locris`. **Optional:** `CM_M22_01`, `CM_M22_02`, **Requiem Gate #7** (`RQG_07`, "**The Last Warden**").

---

## 4. Locris Dialogue (in-play V.O., by progress trigger)

| Trigger | Line |
|---|---|
| Mission start | "*You never could walk in a straight line, Shieldwarden. Neither can this place.*" |
| First chord change | "*Everything here waits for a chord that never comes. I built it that way. I didn't know I was building myself.*" |
| Stair loop 60 s | "*Some things can only be resolved by breaking them.*" |
| Enter the Rotating Plaza | "*They told us the Hymn would end the pain. It did. It ended everything else too.*" |
| After ENC_01 | "*I watched you, that day. Alone in the square, screaming at the sky. I was already singing. I could have stopped. I didn't.*" |
| Garden entry | "*I kept these. The Unison doesn't know. Memories are dissonant. They hurt. I kept them anyway.*" |
| Memory statue "Back to Back" | "*The Siege of the Nine Bells. You carried me out on your back. You were so loud that night.*" |
| After ENC_02 | "*Come, then. Let's see if you still remember how to fight me.*" |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #7** | A02: on the stair's "impossible" landing — visible from below but only reachable on the 3rd loop, when a gap appears in the railing | A faint bell; the landing flickers violet on loop 3 |
| S2 | **Heart Shard #17** | A01: in an alley that only exists during one specific chord (the 4th chord of the cycle) | The alley's doorway glows violet during that chord |
| S3 | **Tab #10: "Resolved"** (all enemy attacks telegraph 50% longer — a "practice" modifier) | A03: in the house that only exists in rotation state 3 (`CM_M22_01`'s location) | — |
| S4 | **Effigy: Locris** | A05: after the boss, where Locris knelt | — |
| S5 | **Effigy: Gilded Canon** | A04: the grotto antechamber (after `CM_M22_02`) | — |
| S6 | **Master: *"Nine Bells"*** — an Oreth war-chant transcribed by the Quietus | A04: the camp-at-night memory statue (interact: the statue hums) | Humming |
| S7 | **Reprise** | A03: atop a quadrant's highest house during a rotation (timed jump) | — |
| S8 | **Rig Core** | A02: below the stair (after breaking through, a side ledge) | — |
| S9 | **Brass Cache #1** | A03 (after `CM_M22_01`) | — |
| S10 | **Brass Cache #2** | A04 (after `CM_M22_02`) | — |
| S11 | **Sounding Station #1** | A01 (a Static probe) — reveals the *current* rotation's map | — |
| S12 | **Sounding Station #2** | A04 | — |
| S13–S18 | **Archive Stones** | A01, A03, A04 (×3), A05 | — |

**Archive entries:** `ARC_Loc_Unresolved`, `ARC_Oreth_SiegeOfNineBells`, `ARC_Oreth_VeylAndTheUnsung`, `ARC_Archon_Locrian` (full), `ARC_Obj_KeyOfUnresolved`, `ARC_Enemy_GildedCanon`, `ARC_Opt_RequiemGate7`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Navigate the Returning Street without taking a wrong alley |
| 2 | Kill 5 enemies with Downbeat while a quadrant rotates |
| 3 | Counter 10 ringing strikes in Locris's phase 2 without parrying a silent one |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M22_Explore` — "**Unresolved**" | Traversal | Locrian-mode (diminished) guitar figures that never resolve to the root; the Arrhythm heartbeat is the navigation cue (spatialized toward the correct path) |
| `MUS_M22_Combat_A` — "**Chord Change**" | ENC_01 | Each 30 s section ends on an unresolved chord that triggers the rotation |
| `MUS_M22_Combat_B` — "**Old Wars**" | ENC_02 | Epic, martial, sorrowful |
| `MUS_BOSS_Locris` — "**The Unresolved**" | Boss | Two voices: a choir and a single hoarse voice; the final phase resolves — for the first time — to the root |
| Locris V.O. | All | Harmonized ×2 (the Choir) + a single dry voice underneath, occasionally breaking through |

---

## 8. Art & Lighting

* **Palette:** Aubade's pale stone under a grey sky, but fractured: gaps in the architecture show the golden void of the Harmonium; Locris's cracked gold flickers irregularly (never in rhythm).
* **Key props:** rotating-house modules, Penrose stair (built with a teleport seam), rotating plaza quadrants (hero mechanic), memory statues (4 scenes), grotto, the broken halo sky object.

---

## 9. New Assets Required (P1)

`BOSS_Locris` (`SK_Locris`, chain-spear, broken shield, illusion-strike material, arena configuration system with 3 layouts and transitions), rotating-quadrant system (`BP_ChordRotator`, Quartz-synced), heartbeat navigation audio system (`BP_HeartbeatBeacon` spatial emitters + compass icon), Penrose stair loop, memory statue scenes ×4, `SK_CanonGilded`.
