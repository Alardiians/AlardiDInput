# M06 — FORT OBDURATE

| | |
|---|---|
| **Act** | II — The Tuned Earth |
| **Location** | **Fort Obdurate**, the Concord Defense Force's command fortress carved into the Varn Massif (alpine) |
| **Kit** | `BRU` (military, snow variant) + `CHOIR` 30% → 70% (Dorian's martial growth: bone ramparts, banner-like skin sheets, spear-forests) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M06_1 → BEAT_M06_5 |
| **New** | Arc Coil, Hot Rivets & Tri-Spin mods, **Requiem Gate #1**, funicular ride; enemies **Bellwether**, **Tuned Marksman** |
| **Landmark** | **The Obdurate Gun** — a colossal Concord artillery piece (a 120 m barrel) jutting from the mountain's face, now grown over with Choir bone like a pipe-organ pipe, humming |

---

## 1. Overview

Dorian's army has taken the CDF's most fortified mountain base and tuned its garrison into a disciplined force. Lund needs the fort's **deep archive** (intelligence on the Consonance's leadership and the Spires). Wren wants the **Arc Coil** prototype from the weapons lab and eyes the hangars' **Anvil Siege Frames**.

**Experience goals:** a vertical fortress assault from the snowy valley to the summit; the first **Bellwether** (jumping shockwave rings); long-range threats (Marksmen) that punish standing still; the first **Requiem Gate** (optional elite arena); a "hold the vault" objective while Lund downloads data.

---

## 2. Level Flow

```
[A01 Valley Drop (snowfield)] → [A02 Outer Wall & Gatehouse] ENC_01 (Marksman intro)
   → [A03 Funicular Station] → [A04 Funicular Ride] (moving, light combat)
   → [A05 Gun Galleries (inside the cliff)] ENC_02
   → [A06 Weapons Lab] (Arc Coil, mods) ENC_03
   → [A07 Hangar Deck] ENC_04 (Bellwether intro)   (+CM_M06_01, CM_M06_02)
   → [A08 Command Spine (vertical)] → [A09 Deep Archive] ENC_05 "Hold the Vault" (timed objective)
   → [A10 Summit Battery — the Obdurate Gun] ENC_06 FINALE → exit
   Optional: [Requiem Gate #1] off A07 (key in A05)
```

### A01 — Valley Drop
* The Drop Coffin lands in a snowfield at the base of the massif. Blizzard-light snow; pine trees gilded with porcelain frost; the fortress face towers 800 m above with the **Obdurate Gun** jutting out. Dead CDF tanks half-buried in snow.
* Short traversal up a switchback road to the outer wall.

### A02 — Outer Wall & Gatehouse, ENC_M06_01
* **Space:** a massive concrete curtain wall (20 m tall) with a gatehouse, a killing ground before it (70 × 40 m, tank traps, trenches), and wall-top walkways reached by Grip Walls (maintenance ladders fenced in chain mesh with orange trim) and Kick Pads (Static left behind from a failed assault).
* **Marksman intro:** a **Tuned Marksman** on the gatehouse tower, visible cyan laser line sweeping the snow. Prompt: `MARKSMEN — break line of sight, or COUNTER the gold shot`. The arena features two Marksman perches.

### A03 — Funicular Station & A04 — Ride
* A cliff-base station; the funicular car (a 20 m long, two-deck inclined rail car) climbs 500 m up the cliff face inside a tunnel with open-air galleries.
* **Ride (3 min):** light combat: Vespers attack through the open gallery windows; Thralls leap onto the car roof from maintenance ledges (the roof is accessible by a ladder); two Choristers ride the cables. Snowstorm vistas; the Gun passes overhead.

### A05 — Gun Galleries, ENC_M06_02
* **Space:** tunnels carved into the rock with firing embrasures (open to the valley) — a long gallery (120 m × 12 m) connecting to a **casemate hall** (40 × 30 m, 10 m tall, old coastal-style guns on rails) — the arena.
* **Requiem Key #1** is hidden here (see secrets).

### A06 — Weapons Lab, ENC_M06_03
* **Space:** a clean-room research complex: test ranges (a 60 m firing range lane with targets), a prototype vault, containment glass.
* **Arc Coil:** in the prototype vault (`PKP_Weapon_ArcCoil`). Wren (`COM_M06_06`): "*Oh — oh no, it's the XW-3. They said it was a myth. It says DO NOT FIRE INDOORS. Fire it indoors.*"
* **Mod Crates:** Riveter — **Hot Rivets** (test range armory), Shredder — **Tri-Spin** (a sealed crate on the range).
* **Arena:** the test range + observation gallery — Vesper swarms pour from the ventilation (perfect Arc Coil practice).

### A07 — Hangar Deck, ENC_M06_04
* **Space:** a vast cavern hangar (90 × 60 m, 30 m tall) carved into the mountain: rows of **Anvil Siege Frames** in maintenance cradles (dormant, gilded over — set dressing, foreshadowing), overhead cranes (Harrow Anchors), gantries at 10 m and 18 m, a VTOL pad with a wrecked dropship.
* **Bellwether intro:** the first **Bellwether** drops from a crane cradle (`SPN_Drop`). Prompt: `BELLWETHERS — JUMP the rings; strike the BELL while it's RINGING`. Accompanied by Thralls only for W1.
* **Choir Masses:** `CM_M06_01` in the fuel depot annex, `CM_M06_02` in the crew barracks.
* **Requiem Gate #1** door (an ossuary gate of bone with a hanging bell) is set into the hangar's north wall.

### A08 — Command Spine
* A vertical shaft (150 m) housing elevators, cable runs and command offices on platforms. Traversal-focused: Harrow Anchor chains, Swing Poles on catwalk rails, Grip Walls; light combat (Choristers, Marksmen on distant platforms).

### A09 — Deep Archive, ENC_M06_05 "Hold the Vault"
* **Space:** a circular archive vault (45 m diameter, 3 tiers of data-stack galleries around a central terminal pit). The Unsung connects Lund's uplink at the central terminal (interact) → **Download: 180 seconds** (progress bar on HUD; Lund's commentary). Waves attack the terminal.
* **Objective rules:** the terminal has 3000 HP; enemies prioritize it when the player is > 1500 cm away; if destroyed → the download restarts from the last 33% milestone (never a fail state). The waves are paced to the timer.

### A10 — Summit Battery, ENC_M06_06 (FINALE)
* **Space:** the Obdurate Gun's breech battery — an open-air platform on the summit (70 × 50 m) around the gun's colossal breech mechanism; snow, wind, clouds below; ammunition hoists (lifts as vertical routes), a control tower (8 m), the gun barrel itself (walkable along its top — a 120 m catwalk jutting over the valley).
* **Finale:** a massive assault with Dorian's heavies. After victory, the Unsung fires the Gun (interact) — it's loaded with a Choir-grown shell; the shot obliterates a distant Consonance convoy on the valley road (spectacle). Lund confirms the data: **Mount Canticle**.

---

## 3. Encounters

```
ENC_M06_01  "Killing Ground"     Arena: A02 (70 x 40 m + wall-top 20 m high)   Seals: 2
  Music: MUS_M06_Combat_A          Reward: 1 Brass + loot fountain
  W1 OnStart:             Marksman x1 (gatehouse tower), Thrall x8, Trooper x4 (trenches)   [Marksman intro]
  W2 AliveBelow(4):       Chorister x3, Bulwark x2, Marksman x1 (wall-top east)
  Final W3 AliveBelow(3): Crescendo x1, Seraph x1, Thrall x8
  Pickups: Health S x6, Plating M x1 (wall-top), Rounds L x1, Charge S x2
```

```
ENC_M06_02  "Casemate Hall"      Arena: A05 (40 x 30 m, 10 m, gun rails, embrasure gallery)   Seals: 2
  Music: MUS_M06_Combat_A          Reward: 1 Brass + loot fountain
  W1 OnStart:             Trooper x5, Thrall x6
  W2 AliveBelow(4):       Canon x1, Chorister x2, Thrall x4
  Final W3 AliveBelow(3): Organ Grinder x1, Cantor x1, Bulwark x2, Thrall x6
  Pickups: Health M x1, Health S x4, Plating S x3, Ordnance S x2, Shells L x1
```

```
ENC_M06_03  "Test Range"         Arena: A06 (60 x 20 m range + 30 x 15 m observation gallery 5 m up)   Seals: 2
  Music: MUS_M06_Combat_B          Reward: 1 Brass + loot fountain
  W1 OnStart:             Vesper x10 (vents), Thrall x6
  W2 AliveBelow(5):       Wailer x6, Chorister x3, Vesper x6
  Final W3 AliveBelow(4): Ophan x2, Vesper x8, Thrall x6
  Pickups: Charge L x2, Health S x6, Plating S x4
  Notes: designed to show off chain lightning.
```

```
ENC_M06_04  "Hangar Deck"        Arena: A07 (90 x 60 m, 30 m tall; gantries 10 & 18 m; crane anchors)   Seals: 3
  Music: MUS_M06_Combat_B → C      Reward: 2 Brass + loot fountain
  W1 OnStart:             Bellwether x1 (Drop from crane cradle), Thrall x10                  [Bellwether intro]
  W2 KilledTag(Bellwether) OR AliveBelow(3): Marksman x2 (gantry 18 m), Trooper x4, Chorister x3
  W3 AliveBelow(4):       Crescendo x2, Seraph x1, Thrall x8
  W3b TimeElapsed(25s):   Thrall x6
  Final W4 AliveBelow(4): Bellwether x1, Canon x1, Cantor x1, Chorister x3, Thrall x6
  Pickups: Health M x2, Plating M x2, Shells L x1, Rounds L x1, Ordnance L x1, Harrow Spool x3
  Power-up: AMP (wrecked dropship's cockpit, on the VTOL pad)
```

```
ENC_M06_05  "Hold the Vault"     Arena: A09 (45 m circular, 3 gallery tiers, central pit)   Seals: 2   Timer: 180 s download
  Music: MUS_M06_Combat_C          Reward: 2 Brass + loot fountain
  T+0:    Thrall x10, Trooper x4
  T+30:   Chorister x4 (galleries), Bulwark x2
  T+60:   Bellwether x1, Thrall x6
  T+90:   Marksman x2, Seraph x1, Vesper x6
  T+120:  Crescendo x2, Cantor x1, Thrall x8
  T+150:  Canon x1, Chorister x3, Thrall x6
  Completion: download reaches 100% AND all alive enemies killed (remaining enemies after T+180 get the "last enemies" outline)
  Pickups: Health M x2, Plating M x2, ammo L x1 each type, Harrow Spool x3 (respawn once at T+90)
```

```
ENC_M06_06  "Summit Battery" (FINALE)  Arena: A10 (70 x 50 m platform + control tower 8 m + barrel catwalk)   Seals: 2
  Music: MUS_M06_Combat_C (finale)  Reward: 2 Brass + big loot fountain
  W1 OnStart:             Bellwether x1, Trooper x6, Thrall x8
  W2 AliveBelow(5):       Seraph x2, Marksman x2 (barrel catwalk end), Chorister x3
  W3 AliveBelow(4):       Canon x2, Bulwark x3, Cantor x1
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Bellwether x2, Crescendo x1, Ophan x1, Chorister x4, Thrall x8
  Pickups: Health M x2, Plating M x2, Rounds L x1, Charge L x1, Ordnance L x1, Harrow Spool x3
  Power-up: OVERDRIVE SURGE (control tower roof)
```

**Requiem Gate #1** (`RQG_01`, "**The Ossuary Toll**") — see `16_Optional_Content_and_Modes.md` §1. Key hidden in A05.

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M06_Funicular` | 3-minute ride up the cliff with gallery vistas |
| `EVT_M06_ArcCoil` | Prototype vault opens; Wren's excitement |
| `EVT_M06_Anvils` | Hangar reveal of the dormant Anvil Siege Frames (Wren: "*I'm gonna need, like, a month. Or three missions.*") |
| `EVT_M06_Download` | Lund's uplink; download timer UI |
| `EVT_M06_GunFire` | The Unsung fires the Obdurate Gun at a Consonance convoy (camera shake, valley explosion) |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Requiem Key #1** | A05: an embrasure in the long gallery opens onto the cliff face; drop to a ledge 6 m below and follow a snowy ledge path (2 Harrow Anchors) to a sealed ossuary niche | Violet glow on the cliff visible from the embrasure; a faint bell sound |
| S2 | **Heart Shard #5** | A04: during the funicular ride, jump from the car's roof onto a passing maintenance platform (it's reachable for 6 s) — a Kick Pad there returns you to the car further up | Violet glow on the platform as it approaches; Lund: "*...was that a light?*" |
| S3 | **Tab #2: "Iron Lungs"** (infinite Harrow charges) | A07: inside an Anvil Siege Frame's cockpit (Grip Wall up its leg) | Violet glow in a cockpit window |
| S4 | **Pedal: Delay** | A06: the prototype vault's back shelf — a sealed case opened by Distorting its crystallized Choir growth | Violet crystal |
| S5 | **Effigy: Bellwether** | A08: an office on a platform off the main traversal route (Swing Pole secret chain) | — |
| S6 | **Effigy: Marksman** | A02: the gatehouse tower's top (the first Marksman's perch) | — |
| S7 | **Master: *"Mountain of Iron"* by OBDURATE** | A09: an archivist's office in the top gallery | — |
| S8 | **Rig Core** | A10: under the Obdurate Gun's barrel — hang off the end of the barrel catwalk and drop onto a maintenance cradle (Harrow Anchor back up) | Violet glow at the barrel's tip |
| S9 | **Brass Cache #1** | A01: a snowed-in CDF tank (Downbeat its hatch) | — |
| S10 | **Brass Cache #2** | A07: crane cab (Harrow Anchor) | — |
| S11 | **Sounding Station #1** | A03: station master's office | — |
| S12 | **Sounding Station #2** | A08: platform 4 | — |
| S13–S17 | **Archive Stones** | A02, A05, A06, A07, A09 | — |

**Archive entries:** `ARC_Loc_FortObdurate`, `ARC_Fac_CDF`, `ARC_Tech_AnvilSiegeFrame`, `ARC_Hist_ChorusFall_CDF`, `ARC_Enemy_Bellwether`, `ARC_Enemy_Marksman`, `ARC_Weapon_ArcCoil`, `ARC_Archon_Dorian` (partial), `ARC_Opt_RequiemGates`.

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Counter a Marksman's gold shot back into it |
| 2 | Kill 5 enemies with a single Arc Coil chain (primary fire) |
| 3 | Complete "Hold the Vault" without the terminal taking damage |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M06_Explore` — "**Whiteout**" | Snow, tunnels | Wind-swept post-metal; military snare rolls; distant march drums (Dorian's army drilling) |
| `MUS_M06_Combat_A` — "**Obdurate**" | ENC_01–02 | Martial groove, 150 BPM |
| `MUS_M06_Combat_B` — "**Hangar Queen**" | ENC_03–04 | Fast thrash |
| `MUS_M06_Combat_C` — "**Hold the Line**" | ENC_05–06 | Epic; the download timer's final 30 s sync to a build-up |
| Funicular | A04 | Cable hum, wind, snow hiss |

---

## 8. Art & Lighting

* **Palette:** white snow, blue-grey shadows, sodium-orange tunnel lights, concrete; Dorian's growth: bone-white ramparts and black-gold banner-skins; the Aureole faint through cloud.
* **Key props:** curtain wall kit, gatehouse, tank traps & trenches, funicular car & track, rock-tunnel kit, casemate guns, weapons-lab clean-room kit, hangar cavern kit, Anvil Siege Frames (dormant, gilded), archive stacks, the Obdurate Gun (hero asset, 120 m), snow materials (deformable-looking snow decals, falling-snow Niagara).

---

## 9. New Assets Required (P1)

`SK_WPN_ArcCoil`, `SK_Bellwether`, `SK_TrooperMarksman`, `SM_AnvilSiegeFrame` (dormant dressing version), funicular car + track, alpine fortress kit (snow BRU variant), weapons lab kit, archive vault kit, `SM_ObdurateGun`, `BP_RequiemGate` (ossuary gate + bell), `BP_DownloadTerminal` (objective actor with HP + UI), snow/blizzard VFX.
