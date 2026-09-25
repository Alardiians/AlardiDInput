# 17 — Art Direction

## 1. Visual Pillars

1. **Brutal Human, Beautiful Horror.** Human spaces are raw, heavy, scarred and loud (brutalist concrete, steel, tape, graffiti). Choir spaces are clean, symmetrical, radiant and wrong (porcelain, gold, light, bone). The contrast is the story.
2. **Readable at 200 BPM.** Every enemy, attack, pickup and traversal element is identifiable in a quarter-second by **silhouette + color + motion**. Beauty never beats readability.
3. **Awe of Scale.** Spires kilometers tall, pillar-choirs of billions, titans, the Sun filling the sky. Every mission has at least one "stop and stare" vista.
4. **Material Honesty.** Things look like what they're made of: concrete is heavy and stained; porcelain is glossy, brittle and cracks; gold is soft and warm; the Unsung's iron is old, dented, rusted and repaired.

**Style:** high-fidelity stylized realism (the modern DOOM target): realistic PBR materials and lighting, with exaggerated proportions for weapons, the hero and enemies (chunkier, bolder, more graphic silhouettes than reality).

---

## 2. Global Color Language (non-negotiable)

| Token | Hex | Use |
|---|---|---|
| `C_EnemyCyan` | `#5FE3FF` | Enemy projectiles, enemy attack telegraphs, halos (dodge!) |
| `C_ParryGold` | `#FFC83D` | Parryable attacks (torus-shaped notes), gold flashes (Counter!) |
| `C_WeakGold` | `#FFB000` (pulsing) | Weak points |
| `C_PlayerEmber` | `#FF5A1F` | The Unsung's glow, player ability VFX, **Faltering** enemies |
| `C_StaticOrange` | `#FF7A00` | Human/Static paint, critical-path work lights, traversal trim |
| `C_HealthRed` | `#E0243A` | Health pickups & Breakdown orbs |
| `C_PlatingGreen` | `#8CFF3C` | Plating pickups & shards |
| `C_SecretViolet` | `#A45CFF` | Secrets & collectibles |
| `C_ChoirWhite` | `#F4F1EA` | Porcelain, Choir architecture |
| `C_ChoirGold` | `#D9A441` | Filigree, seams, Choir metal |
| `C_LydianLilac` | `#B9A2FF` | Dream/illusion effects (M17–M18 only) |
| `C_ConcreteGrey` | `#8A8A86` | Brutalist concrete |
| `C_IronBlack` | `#1B1B1D` | The Unsung's armor |
| `C_Rust` | `#7A3B1C` | The Unsung's edges, human decay |

**Rules:**
* **Cyan is reserved for enemy threats.** No cyan neon, cyan UI accents or cyan pickups. Environments use desaturated ice-blue at most (Europa), never saturated cyan near combat spaces.
* **Gold** appears in Choir architecture a lot — so **parryable gold must be brighter, emissive, torus-shaped and accompanied by the chime**; architecture gold is matte-to-satin, never emissive above 2 nits-equivalent in arenas.
* **Ember orange** is the player's color; enemies never use it except when **Faltering** (communicating "this one is yours now").
* **Colorblind modes** remap tokens (see `19_UI_UX_and_HUD.md`), and **shape language** (sphere = dodge, ring = parry) always backs up color.

---

## 3. The Unsung — Character Art Brief

**Proportions:** 205 cm, broad-shouldered, heavy, slightly hunched forward like a bull; long arms; massive gauntlets (hands read large in first person). Silhouette: tall narrow helmet, wide pauldrons, two exhaust stacks rising behind the shoulders, heavy boots.

**Armor (the Rig):** assembled over eons from many civilizations — plates don't perfectly match; different eras of repair are visible (riveted patches, welded seams, bolted-on alien parts). Base material black iron with a satin sheen, worn to bare grey metal on edges, rust blooms in recesses, bone-white rivets.
* **Helmet:** tall, narrow, with a single vertical visor slit glowing ember; the jaw is a dense iron **speaker-grille** (Overdrive: glows orange from within). Scratches, a crack across the crown repaired with an iron staple.
* **Chest:** a ribcage-like iron cage over the **Arrhythm** — an ember-glowing heart-organ visible between the bars, pulsing irregularly (material-driven emissive with an irregular heartbeat curve).
* **Left forearm:** the **Harrow** — a chain spool housing, the harpoon barb seated along the forearm, chain links visible.
* **Back:** two exhaust stacks (rusted pipes, 60 cm) that vent ember static during Overdrive, dashes and Downbeats.
* **Trophies:** a snapped tuning fork on the belt; kill-tallies scratched into the right pauldron in alien script (Oreth notation — revealed later); a scrap of Oreth cloth (pale, ancient) tied at the left wrist — the only soft thing on the armor (it matches Veyl's statue's cloth in M21).
* **Hands (first person):** thick armored fingers, knuckle plates, a worn leather-like undersuit visible at joints. In M21, the bare hand: long, grey, scarred, four fingers and a thumb.

**Rig Finishes (skins, 15 — list in `08_Progression_and_Economy.md` §8):** Rust Bucket (orange primer), Shieldwarden (pale stone & silver), Unsung (pure black + single ember line), Liner Notes (hand-inked band art), Reliquary (bone & gold trophies), Live at Halcyon, Bootleg, Platinum, Gauntlet Gold, + one per Act (6). (*Tour Poster* is a **weapon** finish set, not a Rig Finish.)

---

## 4. The Choir — Design Language

### 4.1 Shape language
* **Circles, rings and radial symmetry** (halos, wheels, bells, mouths opening in 4 petals).
* **Verticality and elongation** (too-long limbs, throats, fingers; spires).
* **Instrument anatomy:** organ pipes, bells, horns, strings (vocal cords), drum-skins, tuning forks — grown from flesh and porcelain.
* **Sacred-but-fictional motifs:** concentric rings, staff-lines (5 parallel lines), waveforms at rest, tuning forks. Never real religious symbols.

### 4.2 Materials (`M_Porcelain_Master`)
Parameters every Choir enemy material exposes:
| Parameter | Range | Effect |
|---|---|---|
| `Gilding` | 0–1 | Conversion stage: 0 = human skin, 0.5 = patchy porcelain crust, 1 = full porcelain with gold seams |
| `CrackAmount` | 0–1 | Progressive damage: craquelure → deep cracks revealing flesh & inner light (driven by HP %) |
| `InnerLight` | color, intensity | The golden light seen through cracks and mouths |
| `SeamGlow` | 0–1 | Gold seam emissive (pulses with the Hymn / music beat) |
| `FalterEmber` | 0–1 | Ember glow override while Faltering (with wobble) |
| `Distorted` | 0–1 | Screen-space static dither overlay on the silhouette |
| `Hushed` | 0–1 | Desaturation + white rime frost |
| `Gilded Plates` | mask | For Gilded variants — burnished gold armor plates |

### 4.3 Faces
Sealed eyes (smooth porcelain or gold-covered), serene expressions (never snarling — the horror is serenity), mouths that split open vertically or in four petals revealing rings of teeth and glowing throats.

### 4.4 Halos (`NS_Halo`)
Thin rings of cyan-white light behind/above the head (1–3 rings, rotating slowly). Tier readability: T1 = 1 ring, T2 = 2 rings, T3 = 3 rings, Bosses = elaborate multi-ring structures. Halos flicker and wobble when Faltering, go dark when Hushed, and shatter on death.

### 4.5 Conversion stages (Tuned humans)
Stage 1: human with a broken Static Collar, gold dust on skin, head tilted up. Stage 2: porcelain crust on face/hands, split jaw beginning. Stage 3 (Thrall): full porcelain face, split singing mouth, sealed eyes, crust over clothes. Stage 4 (the "Quiet"): statue-like, still.

### 4.6 Choir Architecture (`CHOIR` overlay & `CHOIR_ARCH`)
Organ-pipe clusters, bone lattices (like cathedral tracery grown from bone), bell-shaped blooms, porcelain crust sheets, gold filigree decals, membranes of light across doorways (Choir Seals), "singing walls" of fused faces. Architecture is symmetrical, vertical and glowing from within.

---

## 5. Humanity — Design Language

### 5.1 Concord Brutalism (`BRU`, `CITY`)
Board-formed concrete (visible wood-grain imprint), massive cantilevers, repetitive window grids, exposed aggregate, raw steel, stencil typography (Concord typeface: condensed grotesque), color-coded safety stripes, sodium and fluorescent lighting. Stains, water damage, soot. Scale: monumental.

### 5.2 The Static
Everything is **hand-made and loud**: spray-painted Static Marks (a clipped waveform), band logos, duct tape, zip ties, speaker stacks bolted to everything, cables everywhere, jury-rigged lights, stickers on weapons, hand-painted slogans ("KEEP IT LOUD", "NO SILENCE ZONE", "BREAKER WAS HERE"). Static soldiers: mismatched armor, big headsets, neck-mounted collars with orange VU meters, shoulder speakers.

### 5.3 The Consonance (`CULT`)
White marble, gold inlay, perfect symmetry, reflecting pools, soft diffuse light, tuning-fork iconography, the Consonance Seal (three concentric rings crossed by a vertical line). Robes: white-and-gold over tactical armor; projected gold halo-rings.

---

## 6. The Oreth — Design Language (`OREN`)

* **Architecture:** pale warm-grey stone, tall slender towers shaped like wind and brass instruments (flutes, horns, pipes) riddled with sound-holes; arches like the bell of a horn; terraces; everything designed to be *played by the wind*.
* **People (statues/Locris):** 1.9–2.4 m (the Unsung, 205 cm in the Rig, is mid-range), slender, long-limbed, elongated skulls with layered crest-like "ear-fans," large dark eyes, four-fingered hands + thumb.
* **Glyph style ("sung notation"):** curved glyphs written on **five-line staves**, flowing left to right like sheet music; each glyph is a looping curve with dots (think musical notation merged with calligraphy). Glyph texture atlas: `T_OrethGlyphs_Atlas` (64 glyphs).
* **Shieldwarden armor:** layered plates of silver-grey metal with pale stone inlays — the Rig's oldest pieces (helmet core, left pauldron) match it (a subtle clue players can spot before M21).

---

## 7. Lighting Guidelines

| Space | Guideline |
|---|---|
| **Arenas** | Brighter, flatter key light; strong rim light on enemies (use a subtle post-process rim or light-function); avoid pure-white backdrops behind enemy sightlines; keep cyan & gold effects the most saturated things on screen |
| **Exploration** | Moodier, darker, higher contrast; critical path lit with warm orange Static work-lights; secrets hinted with violet |
| **Human spaces** | Warm practical lights (sodium, tungsten), flicker, haze |
| **Choir spaces** | Sourceless, soft, overhead; bloom; gold inner-light; shadows reduced (unsettling) — but enemies still receive a directional key for form |
| **Oreth ruins** | Grey overcast skylight, a dim red sun, long soft shadows — melancholic |
| **Harmonium** | White-gold emissive architecture, volumetric god-rays, drifting light-rings |

**Tech:** Lumen GI & reflections (hardware RT where available; software fallback), Virtual Shadow Maps, volumetric fog per level (`ExponentialHeightFog` + local fog volumes), auto-exposure clamped per kit (min/max EV in `PP_<Kit>` volumes) so arenas never blow out.

---

## 8. VFX Language

| Category | Language | Examples |
|---|---|---|
| **Player** | Ember orange, static/noise textures, jagged waveforms, sparks, exhaust fire | Distort cone (static "snow" + waveform ribbons), Overdrive (exhaust flames, screen-edge static), dash burst, Downbeat shockwave (dust ring + ember crackle), Power Chord (ember shock cone) |
| **Enemy attacks** | Cyan-white light, smooth spheres & beams, choral shimmer | Note projectiles (sphere + trail), beams, ring shockwaves (cyan) |
| **Parryable** | Gold, **torus** shape, chime-flash | Resonant Notes (gold rings), gold weapon flashes |
| **Hymnfall** | Pillar of white-gold light (1.2 s), descending motes, ring on the ground | Spawn |
| **Silence** | Desaturation, stillness, dark bubble with white rim, particles freeze mid-air | Hush Charge, Silencer |
| **Death (Choir)** | **Shatter**: porcelain shards + gibs + gold motes + halo shattering; body fades to gold dust within 8 s | All Choir kills |
| **Death (human cultists)** | Blood + gore (no porcelain unless gilded) | Acolytes, Zealots |
| **Hazards** | Heat shimmer, sparks, white mist, lilac shimmer (dream) | — |

Budget: see `20_Technical_Design_UE5.md` §9 (Niagara particle budgets, GPU sim preferred).

---

## 9. Gore Specification (M-rated)

* **Choir enemies:** porcelain cracks (progressive), limbs sever at joints (porcelain break + red flesh + gold light inside), heads shatter, torsos burst into shards and meat. Blood color: **deep red with gold flecks** (the Hymn in their blood). Gold motes rise from wounds.
* **Breakdowns:** brutal and fast, never lingering; the camera never stays on a mutilated body for more than 0.5 s.
* **Humans (cultists):** realistic gore consistent with modern DOOM (dismemberment, blood), never torture-like.
* **Never:** gore on passive civilians, children, the Quiet, or allies. Gore toggles: Full / Reduced (no dismemberment, less blood, porcelain-only shatter) / Off (bodies dissolve into gold dust on death).

---

## 10. Kit Briefs (short)

| Kit | Key words | Palette |
|---|---|---|
| `BRU` | Board-formed concrete, monumental, stencil signs, sodium light | Greys, sodium orange, safety yellow |
| `CITY` | Megablocks, highways, stadium, neon (magenta/amber), rain | Grey, magenta, amber, gold (Spire) |
| `IND` | Furnaces, molten steel, conveyors, cranes, robots | Black iron, orange-white molten, brass |
| `CULT` | White marble, gold inlay, pools, symmetry | White, gold, soft blue sky |
| `ORB` | Hull plating, trusses, spin-gravity rings, ribbon | White panels, black space, Earth blue |
| `ICE` | Blue ice caverns, drill rigs, pressure domes, Jupiter | Ice blue (desaturated), ochre (Jupiter), amber interiors |
| `AERO` | Gasbag domes, filigree, gardens, sulfur sky | Sulfur yellow, cream, verdigris, flowers |
| `OREN` | Pale stone, wind-instrument towers, statues, glyphs | Warm grey, dulled bronze, dim red sun |
| `HARM` | Bone, porcelain, gold, light, staves, note-worlds | White, gold, pale light |
| `SHIP` | Black anechoic wedges, brutalist warship, cluttered crew life | Black, orange string lights, warm practicals |
| `CHOIR` | Organ pipes, bone lattice, porcelain crust, filigree | White, gold, inner light |

---

## 11. Reference Keywords (for mood boards — do not copy any IP)

Brutalist housing estates and concert halls · board-formed concrete · anechoic chambers (foam wedge walls) · pipe organs and carillons · bell towers and bell foundries · porcelain dolls and kintsugi (gold-repaired ceramics) · "biblically accurate" ophanim wheels (as a *concept* of eyes-on-rings) · radio telescopes · space elevators (concept art) · steel foundries · Venus aerostat concepts · Europa ice-ocean concepts · mech/walker concept art · heavy metal album covers · gig posters · punk DIY aesthetics.
