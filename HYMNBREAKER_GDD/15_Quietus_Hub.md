# 15 — The Quietus (Hub)

## 1. Overview

**The Quietus** is a 400 m Concord **anechoic transport** — built in secret to carry the Silent Vault to Earth, seized by the Static, and now humanity's last mobile fortress and home to ~300 crew and refugees. Its **Mute Engine** makes it the only place in the solar system where the Hymn cannot be heard.

The hub is where the player: upgrades (Brass, Rig Cores, Heart Shards, Pedals), launches missions, replays missions, views collectibles (Masters, Effigies, Archive), takes on Pit Trials, opens Vaults, and — optionally — spends quiet time with the crew. It evolves through **7 states** that mirror the story.

**Design goals:**
* **Warmth after war.** The hub is the one warm, human, noisy place in the game — string lights, music from every doorway, laundry lines, kids' drawings, jokes on whiteboards.
* **Everything in ≤ 30 s of walking.** Compact layout; fast travel via the Spine's elevators.
* **Optional depth.** No mandatory conversations; every NPC talk is ≤ 45 s and skippable.

**Movement in the hub:** full movement (jump, dash, Harrow on hub anchors — the crew installed a few "for the Breaker"); weapons holstered (`IMC_Hub`); interact prompts.

---

## 2. Layout

The Quietus's interior is a long **Spine Corridor** (10 m wide, walls lined with black anechoic wedges) running bow to stern, with decks branching off. Three levels (Upper, Main, Lower) connected by two freight elevators (bow and stern) and stairwells.

```
BOW ───────────────────────────────────── SPINE (Main Deck) ─────────────────────────────── STERN
 UPPER:  [BRIDGE]──[Tamsin's Cockpit]            [ARCHIVE (Lund)]    [MED-BAY]            [VAULT DECK]
                                                                                            (9 vault doors)
 MAIN:   [LAUNCH BAY / Drop Coffin]──[ARMORY (Wren)]──[RIG BAY]──[HEART CHAMBER]──[MESS HALL]──[MEMORIAL]
                                                                        │
                                                        [LISTENING ROOM (Pops)]──[EFFIGY GALLERY]
 LOWER:  [THE PIT (training/trials, ex-Cargo Hold 2)]    [REFUGEE DECK]      [ENGINE ROOM]──[MUTE ENGINE]
                                                                                     [WARDROBE (crew lockers)]
```

Approximate sizes: Launch Bay 60 × 40 × 20 m · Armory 30 × 20 m · Rig Bay 20 × 20 m · Heart Chamber 10 × 10 m (anechoic) · Bridge 40 × 25 m (huge window) · Listening Room 20 × 15 m · Effigy Gallery 30 × 10 m · Archive 25 × 20 m · The Pit 60 × 60 × 25 m · Mess Hall 40 × 25 m · Med-Bay 20 × 15 m · Vault Deck 50 × 12 m · Mute Engine chamber 50 m sphere.

---

## 3. Stations

| Station | Location | NPC | Function |
|---|---|---|---|
| **Launch Bay / Drop Coffin** | Main, bow | Deck crew | Mission launch (next mission), **Mission Select** (replay), Encore missions (post-game). The Drop Coffin is a black coffin-shaped pod on a launch rail; interact → the launch sequence. |
| **The Bridge** | Upper, bow | Vire, Tamsin (cockpit) | Story scenes; the **Solar Map** (a holographic solar system table showing the Aureole bands, Spire locations, mission status); the great window (Earth + Aureole, reflecting progress) |
| **Tamsin's Cockpit** | Upper, bow | Tamsin | Sign-language conversations (optional, after M03; one new exchange per hub state) |
| **The Armory** | Main | Wren | **Weapon mod upgrades** (Brass), weapon inspection (3D model viewer), **Larynx** assembly (after 7 Reliquary Shards), Mastery tracking |
| **Rig Bay** | Main | (Wren, remote) | **Rig tree** upgrades (Rig Cores). The Unsung steps into a gantry; arms lower tools onto the armor (short animation per purchase). |
| **Heart Chamber** | Main (anechoic) | — | **Heart Shards** (Vitality/Plating/Arsenal tracks). A small black wedge-lined room with a pedestal; the Unsung kneels and presses a shard to the Arrhythm's cage; the heart flares. The only place with total silence in the hub. |
| **Pedalboard** | Armory bench (also pause menu) | Wren | Equip Pedals; view Boutique challenges |
| **Listening Room** | Main | Pops | **Masters** on a turntable (play any unlocked track; Pops tells a 20 s story about each fictional band); radio intros archive |
| **Effigy Gallery** | Main | — | Display cases with collected **Effigies** (inspectable, rotatable; each with a 2-line description + a joke) |
| **The Archive** | Upper | Lund (until M14), then Wren's notes, then Lund in the Med-Bay (State 5) | Codex browser (also in pause menu); Lund's research boards evolve with the story |
| **The Pit** | Lower | Okafor (visits), a Static drill sergeant | **Pit Trials** (from Bootleg Tapes), free practice arena with enemy spawner (any encountered enemy), damage dummies |
| **Mess Hall** | Main | Crew, refugees, kids | Ambient life; barks; the kids' drawing wall (updates each state) |
| **Med-Bay** | Upper | Medics; Lund (State 5) | Story (Lund's half-tuned conversations — the Oreth history, optional) |
| **Vault Deck** | Upper, stern | — | 9 **Mute Cell** vaults (see `08_Progression_and_Economy.md` §7) |
| **Wardrobe** | Lower | — | Rig Finishes, weapon finishes, helmets |
| **Memorial Wall** | Main (after M14) | — | Static Collars of the dead; Juno's collar (interact: plays her song); Lund's photo (after M27) |
| **Engine Room & Mute Engine** | Lower, stern | Engineers | Lore tour (optional); the Mute Engine's hum; M14 location |
| **Refugee Deck** | Lower | Refugee families | Ambient life; after M19, freed Chancel captives recovering here |

---

## 4. Hub States

| State | After | Look & feel | Crew attitude to the Unsung | New / changed |
|---|---|---|---|---|
| **1 — Arrival** | M02 | Damaged from the lunar evac; tired crew; fewer lights; tense quiet music | Fear, whispering, stepping aside | Armory, Rig Bay, Bridge, Archive, Launch Bay; Heart Chamber opens with first shard |
| **2 — Hope** | M04 | String lights; music everywhere; a hand-painted "BREAKER" banner in the Spine; soldiers cheering | Curiosity, awe, fist-bumps from the bold | Listening Room, Effigy Gallery, The Pit; Harlan on the bridge screen after M05 |
| **3 — Arsenal** | M09 | Silencer lab in the Armory annex; weapon racks; Wren's workshop expanded | Respect; soldiers mimic the Unsung's gestures | Lund's confession (`CIN_HUB_Confession`) on first arrival; Anvil repair visible (M10–M11) |
| **4 — Scarred** | M14 | Burn marks, scraped gold residue on wedges, patched hull, the Memorial Wall; slowly repaired over M15–M18 | Grief and loyalty; quieter; someone always sitting by the Memorial | Memorial; Lund's station empty (Wren's notes appear) |
| **5 — The Med-Bay** | M19 | Lund half-gilded in the Med-Bay under anechoic sheeting; freed captives on the Refugee Deck | Protective; crew bring Lund records | Med-Bay conversations (Oreth history); after M22, children leave drawings for the Unsung ("*welcome home*") |
| **6 — Last Night** | M24 | Crew rigging the hull as a speaker; messages chalked on shells and walls; everyone awake; music loud; a party atmosphere mixed with dread | Family | `CIN_HUB_LastPlan`; last chance for upgrades before M25–M27 (no hub after) |
| **7 — Home** | Post-game | Docked above a clean Earth; calm; the Memorial with Lund's photo | Peace | All post-game unlocks |

**Implementation:** one persistent hub map with **Data Layers** (or sublevels) per state: `DL_Hub_State1` … `DL_Hub_State7` plus additive detail layers (e.g., `DL_Hub_Memorial`, `DL_Hub_BreakerBanner`). A `UHBHubStateSubsystem` enables layers based on campaign progress.

---

## 5. Optional Conversations (samples)

Conversations are short, character-driven, and change per state. The Unsung "responds" with gestures (nod, fist bump, rack the shotgun, signs with Tamsin).

| NPC | State | Topic | Sample |
|---|---|---|---|
| Vire | 2 | Her patches | "*Every patch on this coat is somebody. This one's Ruiz. You've got his shotgun.*" |
| Vire | 4 | Juno | "*She was nineteen. She wanted to be a pilot. Tamsin was teaching her.*" |
| Wren | 1 | First meeting | "*Oh, you are GORGEOUS. Who did your welds? Four billion years? Yeah, it shows.*" |
| Wren | 3 | The Silencer | "*It's not a bomb. It's the opposite of a bomb. It's a bomb of NOTHING. I hate it. I love it.*" |
| Tamsin | 1 (after M03) | Sign | ✋ "*Can you understand me?*" → Unsung signs "Yes" |
| Tamsin | 2 | Flying | ✋ "*I can't hear the engines. I feel them. You too, I think. Your heart. I can see it through the armor.*" |
| Tamsin | 4 | Grief | ✋ "*Juno wanted to learn to fly. I'll finish teaching someone. Maybe you.*" |
| Lund | 1 | The Vault | "*I spent twenty-six years trying to hear what was inside that box...*" |
| Lund (tuned) | 5 | The Oreth | "*They wanted to stop hurting. I understand them now. That's the terrifying part.*" |
| Pops | 2 | Records | "*This one's by SIGNAL LOSS. Terrible band. Loudest drummer in the solar system. You'll love it.*" |
| Okafor | 2 (The Pit) | Training | "*Show me the thing where you rip them in half. Again. For the recruits.*" |
| Kid (Mess) | 5 | Drawing | "*I drew you with a cape. You should get a cape.*" (Unsung nods solemnly) |

---

## 6. Hub Audio

* **Always noise:** every room has diegetic music (crew radios, the mess jukebox, Pops's turntable, Wren's workshop speakers) — mixed so the hub feels like a living, loud home.
* **Exception:** the **Heart Chamber** — total silence except the Arrhythm.
* **Hub theme** — "**Home Is Loud**": a warm, mid-tempo rock arrangement of the main theme that plays in the Spine and on the Bridge (State 1: sparse; State 2+: full; State 4: a sad acoustic version; State 6: triumphant; State 7: gentle).

---

## 7. Hub Assets (SHIP kit)

Spine corridor modules (anechoic wedge walls — the signature material `M_AnechoicWedge`), bridge, cockpit, launch bay & Drop Coffin rail, armory (workbenches, weapon racks, tool walls), Rig Bay gantry (animated arms), Heart Chamber, Listening Room (record shelves, turntable, chairs), Effigy Gallery (display cases), Archive (research boards, screens), The Pit (arena with training props), mess hall, med-bay, vault deck (9 vault doors), wardrobe, memorial wall, engine room, Mute Engine (hero), refugee deck; state dressing sets (lights, banners, damage, memorial, chalk messages); NPCs: Vire, Wren, Tamsin, Lund, Pops, Okafor, Harlan (screen), 25 generic crew, 10 refugees, 6 children.
