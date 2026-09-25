# M12 — HELIOS STATION

| | |
|---|---|
| **Act** | III — Iron and Fire |
| **Location** | **Helios Station**, a solar-power and mining complex on Mercury's terminator line, feeding the **Corona Array** mirror fields |
| **Kit** | `BRU` (solar industrial: white heat-reflective panels, black radiator fins) + `ORB` (exterior plating) + `CHOIR` 30% → 60% (Phrygian growth: cracked porcelain veined with fire) |
| **Target duration** | 75 min |
| **Priority** | P1 |
| **Story beats** | BEAT_M12_1 → BEAT_M12_6 |
| **New** | **Ripsaw**, Grinder & Arc Scythe mods, *Whammy* pedal, **solar exposure hazard**, shadow-timing traversal; enemy **Profundo**; mini-boss **The Antiphon** |
| **Landmark** | **The Sun** — enormous, filling a quarter of the sky on the horizon, and humming; and the **Phrygian Spire** at the far focal point of the mirror fields — a spire of white fire |

---

## 1. Overview

Mercury: the hottest, brightest place humans ever built on. Helios Station harvests sunlight with kilometers of mirrors (the **Corona Array**) and beams the power to Earth. The **Phrygian Archon** is using the mirrors to focus the Hymn *into the Sun*. Lund: "*If the Sun sings, every world in the system hears it. There is no collar loud enough.*"

**The signature mechanic — Solar Exposure:** direct sunlight is lethal (drains Plating, then Health: 10/s each; Rig *Hazard Plating* halves it). **Shade is safe.** Arenas mix sunlit zones and shade; traversal sections require moving between shadows that sweep as mirror arrays turn.

**Experience goals:** a harsh, blinding environment that changes how you move; the **Ripsaw**'s ricochet chaos in tight industrial spaces; the first **Profundo** (a super-heavy that makes the ground shake); a clever twin mini-boss; and the first glimpse of **Locris**.

---

## 2. Level Flow

```
[A01 Terminator Landing (shade side)] → [A02 Habitat Crater (shade dome)] (lore)
   → [A03 Open-Pit Mine] ENC_01 (sun/shade arena)   (+CM_M12_01 in the ore processing shed)
   → [A04 Foreman's Workshop] (RIPSAW; Grinder & Arc Scythe mods)
   → [A05 Heat Exchanger Hall] ENC_02 (Profundo intro)
   → [A06 The Shadow Walk] (timed shadow traversal)   (+CM_M12_02 in a relay bunker)
   → [A07 Reactor Atrium] MINI-BOSS: THE ANTIPHON
   → [A08 Collector Station 3] ENC_03 FINALE → Locris glimpse → end
```

### A01 — Terminator Landing
* The Drop Coffin lands on the **night side** of the terminator line — black sky, stars, cold. Ahead, a line of blinding light across the landscape: the day side. Station structures straddle the line. The Sun peeks over the horizon, colossal. A low, ceaseless **hum** comes from it (a new ambient layer).
* Prompt on the first sunlit patch: `SOLAR EXPOSURE — direct sunlight burns. Stay in the SHADE.` A small safe demo patch.

### A02 — Habitat Crater
* **Space:** the crew's living quarters under a huge shade dome (a crater roofed with reflective panels): prefab housing blocks, a hydroponics bay, a canteen, a chapel converted into a Consonance shrine (half the miners joined the Consonance), a Static cell's last stand (barricades, dead soldiers, a mural "WE HEARD THE SUN SING").
* Lore-rich breather; a few Thralls; Archive entries on Phrygian and the Array.

### A03 — Open-Pit Mine, ENC_M12_01
* **Space:** a terraced open-pit mine (100 × 80 m, 5 benches 6 m apart) half in sunlight, half in the shadow of the pit wall; the shadow line creeps slowly across the benches during the arena (over 4 minutes, the sunlit area grows by ~20%). Haul trucks (cover), an ore crusher (environmental kill), conveyor lines (Grind Rails) up the pit wall.
* **Optional:** `CM_M12_01` in the ore processing shed.

### A04 — Foreman's Workshop
* A cramped workshop full of homemade gadgets, a "WORLD'S OKAYEST FOREMAN" mug, and **the Ripsaw** on a workbench with a note ("*This is Dennis. Dennis is not a toy. — J. Okonjo*"). `PKP_Weapon_Ripsaw`. Wren: "*A saw-blade launcher. From a MINING FOREMAN. I love Mercury.*"
* **Mod Crates:** Ripsaw — **Grinder Blade**; Lance — **Arc Scythe**.
* A tight test corridor beyond (concrete, metal walls — ricochet playground) with Thralls.

### A05 — Heat Exchanger Hall, ENC_M12_02
* **Space:** a massive hall (80 × 60 m, 30 m tall) of vertical radiator fins (black, 20 m tall, in parallel rows 6 m apart — corridors between them), coolant pipes, a central pump island, catwalks along the fin tops (Grip Walls on fin ends). The fins glow orange where they're hottest (touching them: 10 dmg/s).
* **Profundo intro:** the far wall bursts and a **Profundo** knuckle-walks in (with Thralls only). Prompt: `PROFUNDO — jump the SUB-BASS STOMP; when its CHEST OPENS, hit it hard`.

### A06 — The Shadow Walk
* **Space:** an exposed plateau (600 m route) between the station and the reactor, covered with **rotating mirror arrays** (each 20 m wide) whose shadows sweep the ground. The player moves from shadow to shadow as they sweep (clear visual: the shadow edges have a heat shimmer; a subtle UI shade indicator on the HUD's health bar shows "IN SHADE"). Kick Pads launch between shaded islands; a Harrow Anchor chain along a power-line pylon row offers a fast route.
* Light harassment: Vespers (they don't care about sunlight), a Seraph on a pylon.
* **Optional:** `CM_M12_02` in a shaded relay bunker off the route.

### A07 — Reactor Atrium: MINI-BOSS THE ANTIPHON
* `10_Bosses.md` §5. **Space:** a circular hall (50 m diameter, 40 m tall) around the fusion reactor column; two opposing balconies (12 m up) where the twin Cantors stand; Harrow Anchors across the gap; catwalk ring at 6 m; the reactor column's windows glowing. The hall is fully shaded (no solar hazard).

### A08 — Collector Station 3, ENC_M12_03 (FINALE)
* **Space:** a collector tower's top platform (60 m diameter) at the edge of the mirror fields: the collector receiver (a glowing cylinder) at the center, 8 mirror arms around it that rotate (their shadows = shade zones that move slowly in a circle), railings, a lower ring deck (6 m below), and the burning horizon.
* After the arena: **Locris glimpse** — on a distant ridge across the mirror field, a cracked figure with a broken halo stands watching. The camera's soft-lock nudges the player's view toward it (option: disable). When the player looks, it's gone. Lund: "*Did you— there was something on the ridge. It was... cracked.*"

---

## 3. Encounters

```
ENC_M12_01  "Open Pit"                Arena: A03 (100 x 80 m, 5 benches; moving shadow line)   Seals: 2
  Music: MUS_M12_Combat_A              Reward: 1 Brass + loot fountain
  W1 OnStart:             Thrall x10 (Tuned miners), Trooper x4
  W2 AliveBelow(5):       Organ Grinder x2 (converted haul trucks' crane-legs), Chorister x3
  W3 AliveBelow(4):       Seraph x2, Bellwether x1
  Final W4 AliveBelow(3): Canon x1 (top bench, in shade), Crescendo x2, Thrall x8
  Pickups: Health S x8, Plating M x2 (both in sunlit spots — risk/reward), Rounds L x1, Charge L x1
```

```
ENC_M12_02  "Heat Exchanger Hall"     Arena: A05 (80 x 60 m; fin corridors 6 m wide; fin-top catwalks 20 m)   Seals: 3
  Music: MUS_M12_Combat_B              Reward: 2 Brass + loot fountain
  W1 OnStart:             Profundo x1 (Wall Burst), Thrall x10                                 [Profundo intro]
  W2 KilledTag(Profundo) OR AliveBelow(4): Chorister x4 (fin tops), Trooper x4
  W3 AliveBelow(4):       Fugue x2, Siren x1, Thrall x6
  Final W4 AliveBelow(4): Bellwether x1, Hymnal x1, Cantor x1, Chorister x3
  Pickups: Health M x2, Plating M x1, Ordnance L x2 (Ripsaw), Shells L x1, Harrow Spool x3
  Power-up: AMP (pump island)
  Notes: fin corridors are Ripsaw heaven (ricochets).
```

```
BOSS_Antiphon  "Reactor Atrium"        Arena: A07   (10_Bosses.md §5)
  Music: MUS_BOSS_Antiphon (call-and-response: two choirs panned hard left/right)
  Resource adds every 25 s: Thrall x4 (catwalk ring)
  Reward: 2 Brass + loot fountain
```

```
ENC_M12_03  "Collector Station 3" (FINALE)  Arena: A08 (60 m platform; rotating mirror-arm shade zones; lower ring 6 m)   Seals: 2 (lift doors)
  Music: MUS_M12_Combat_C              Reward: 2 Brass + big loot fountain
  W1 OnStart:             Chorister x6, Thrall x8
  W2 AliveBelow(5):       Profundo x1, Seraph x1
  W3 AliveBelow(4):       Canon x2 (lower ring, shelling up), Echo x1, Bulwark x3
  W3b TimeElapsed(25s):   Thrall x8
  Final W4 AliveBelow(4): Profundo x1, Ophan x2, Crescendo x1, Chorister x4
  Pickups: Health M x2, Plating M x2, ammo L each, Null Cell x1 (receiver top — exposed to sun), Harrow Spool x3
  Power-up: DEAD SILENCE (lower ring — also immune to solar exposure while active)
  Notes: enemies are unaffected by sunlight (Choir-forms don't burn) — the player must juggle shade and aggression.
```

---

## 4. Set Pieces & Scripted Events

| ID | Description |
|---|---|
| `EVT_M12_TheHum` | The Sun's hum — a new ambient layer that grows through Act III until M13's boss dies |
| `EVT_M12_Dennis` | The Ripsaw's reveal |
| `EVT_M12_ProfundoWall` | Profundo's entrance through the hall wall |
| `EVT_M12_ShadowWalk` | Moving-shadow traversal |
| `EVT_M12_Antiphon` | The twins' duet intro |
| `EVT_M12_Locris` | The cracked figure on the ridge |

---

## 5. Secrets & Collectibles

| # | Item | Location | Hint |
|---|---|---|---|
| S1 | **Heart Shard #9** | A06: in full sunlight on a mirror array's hub — sprint across 40 m of sun (≈ 4 s exposure) or wait for a Dead Silence-style trick: a **shade drone** secret (Harrow-yank a Static shade-umbrella drone that follows you for 20 s) | Violet glow in the blinding light |
| S2 | **Tab #5: "Sunburn"** (enemies have a chance to burst into flames on death — cosmetic fire gore) | A02: the Consonance shrine's offering bowl (Distort the crust) | Violet crystal |
| S3 | **Pedal: Whammy** | A05: top of the tallest radiator fin (Grip Wall on the fin end, then a Swing Pole chain) | — |
| S4 | **Effigy: Profundo** | A04: the foreman's secret cabinet behind his poster (interact the "HANG IN THERE" cat poster) | — |
| S5 | **Master: *"Terminator Line"* by DAYBREAKER** | A02: canteen jukebox | Music |
| S6 | **Reprise** | A03: under the ore crusher (Downbeat its maintenance grate when it's stopped — after the arena) | — |
| S7 | **Rig Core** | A07: reactor column's upper window ledge (Harrow Anchor chain after the mini-boss) | Violet glow in a window |
| S8 | **Brass Cache #1** | A03: ore processing shed (after optional Choir Mass) | — |
| S9 | **Brass Cache #2** | A06: relay bunker (after optional Choir Mass) | — |
| S10 | **Sounding Station** | A02: the Static cell's radio room | — |
| S11–S15 | **Archive Stones** | A01, A02 (×2), A05, A07 | — |

**Archive entries:** `ARC_Loc_Mercury_Helios`, `ARC_Obj_CoronaArray`, `ARC_Archon_Phrygian`, `ARC_Hist_HeliosMiners`, `ARC_Enemy_Profundo`, `ARC_Boss_Antiphon`, `ARC_Weapon_Ripsaw`, `ARC_Haz_SolarExposure`, `ARC_Obj_CrackedFigure` (Lund's note after the glimpse).

---

## 6. Mission Challenges

| # | Challenge |
|---|---|
| 1 | Kill 3 enemies with a single Ripsaw blade (ricochets count) |
| 2 | Interrupt a Profundo's Roar with a Frag Charge into its chest |
| 3 | Kill both Antiphon Cantors within 3 seconds of each other |

---

## 7. Audio

| Cue | Where | Notes |
|---|---|---|
| `MUS_M12_Explore` — "**Terminator**" | Traversal | Heat-shimmer drones, slide guitar (desert-metal), the Sun's hum as a tonal center |
| `MUS_M12_Combat_A` — "**Open Pit**" | ENC_01 | 155 BPM, stoner-metal groove |
| `MUS_M12_Combat_B` — "**Heat Sink**" | ENC_02 | Crushing |
| `MUS_BOSS_Antiphon` — "**Call and Response**" | Mini-boss | Two choirs hard-panned L/R, trading phrases; guitars answer both |
| `MUS_M12_Combat_C` — "**Solar Maximum**" | ENC_03 | Blazing, 180 BPM |
| Solar exposure | Sunlit areas | Sizzle loop + rising high-frequency tone; shade = instant relief (low-pass lifts) |

---

## 8. Art & Lighting

* **Palette:** blinding white sunlight, pitch-black shadows, heat shimmer, white heat-reflective panels, black radiator fins, orange-hot metal; Phrygian's fire veins in the Choir growth.
* **Lighting:** extreme contrast; **exposure** clamps so sunlit areas read as dangerous (bloom + shimmer), shaded areas stay readable (fill from bounce light); the Sun as a huge emissive disc with corona.
* **Key props:** terminator landscape, shade dome, habitat prefabs, open-pit terraces, haul trucks, ore crusher, foreman's workshop, radiator fins, mirror arrays (animated rotation — their shadows are gameplay), collector towers, reactor atrium.

---

## 9. New Assets Required (P1)

`SK_WPN_Ripsaw` (+ blade projectile, ricochet VFX), `SK_Profundo`, `BOSS_Antiphon` (2× giant Cantor, gold/silver), solar exposure system (`BP_SolarVolume` + shade detection via sun-direction trace from the player's head & chest), rotating mirror arrays (gameplay shadows), heat shimmer post-process, Mercury terrain, shade dome, radiator fin kit, collector tower platform, shade drone (`BP_ShadeDrone`).
