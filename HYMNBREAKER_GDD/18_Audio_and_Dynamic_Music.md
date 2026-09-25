# 18 — Audio & Dynamic Music

## 1. Audio Pillars

1. **Sound is the war.** The Choir *is* music; the Unsung *is* noise. Every sound decision serves that duality.
2. **Readable by ear.** Every enemy has a signature chord; every dangerous attack has a unique, spatialized tell; gold (parryable) attacks share one universal chime.
3. **The player plays the soundtrack.** The adaptive music follows the Gain meter and combat state; Overdrive triggers a guitar solo; arenas end on a quantized outro.
4. **Silence is sacred.** True silence is used only a handful of times (cold open, Silencer shots, Clara's room, Harlan's epilogue, Aubade's exploration). It must be *real* digital silence to land.

---

## 2. Musical Identity

| Voice | Represents | Instrumentation |
|---|---|---|
| **The Band** | The Unsung, humanity, noise, freedom | Down-tuned 7/8-string guitars (Drop A / Drop G / Drop F#), bass with heavy fuzz, acoustic drums (blast beats to groove), industrial percussion (anvils, chains, pistons), noise synths, amp feedback |
| **The Choir** | The Hymn, the Unison, harmony, oblivion | SATB choir (large), boys' choir (sparingly), solo sopranos, pipe organ, bells/carillon, glass harmonica, strings (sustained), sub drones |
| **The Radio** | Harlan, Static culture | Lo-fi rock, punk, blues, lounge (diegetic Masters) |

**Choir lyrics:** an invented phonetic language ("Oreth-sung") built from open vowels and soft consonants (*ah, oh, eh, ahn, veh, lo, sae, ul, mira*). Never Latin, never real liturgical texts.

### 2.1 Leitmotifs
| Motif | Description | Uses |
|---|---|---|
| **"Break the Hymn"** (main theme) | The cold-open chord (a Drop A power chord) followed by a 7-note riff in Phrygian dominant: aggressive, memorable, hummable | Title, M01, Overdrive stems, finale, credits (acoustic & crowd versions) |
| **"The Hymn"** | A 4-note rising major-arpeggio phrase that *resolves* perfectly (1-3-5-8) — beautiful, comforting, wrong | Every Choir cue; bosses quote it in their mode |
| **"Home Is Loud"** | Warm mid-tempo rock arrangement of the main theme | Hub |
| **"Aubade"** | The Oreth morning song: a slow, modal melody over 7 notes (the Wind Towers) | M21, M22, the Unison phase 2 |
| **"Clara's Lullaby"** | A music-box lullaby | M24, Aurelia's theme fragments |
| **"The Arrhythm"** | The Unsung's heartbeat pattern used rhythmically (see §5.3) | Breakdowns, silence moments, Stair of Light |

### 2.2 Archon Modes
Each Archon's boss track is written **in its mode**: Ionian (major, euphoric), Dorian (martial minor, 120 BPM march), Mixolydian (bluesy-industrial, 7/8), Phrygian (flamenco-inflected metal), Aeolian (funeral doom → blast), Lydian (dreamy #4, shoegaze-metal), Locrian (diminished, never resolving — until the end). The Octave uses all seven modes across its scale attack.

---

## 3. Adaptive Music System

### 3.1 Structure
Each mission has: **1 Explore track** (+ variants), **2–3 Combat tracks** (A/B/C), optional **set-piece tracks**, and **boss tracks**. Combat tracks are authored as **synchronized stems** at a fixed BPM:

| Stem | Content |
|---|---|
| `DRM` | Drums |
| `BAS` | Bass |
| `RGT` | Rhythm guitars |
| `LEAD` | Lead guitar / melody |
| `CHR` | Choir (the Hymn fighting back) |
| `SYN` | Synth / noise / FX layer |
| `OVD` | **Overdrive solo** (guitar solo over the loop) |
| `BRK` | "Breakdown" section (a half-time heavy variation used between waves) |

### 3.2 States & Layering
| State | Trigger | Active stems |
|---|---|---|
| **Explore** | No combat | Explore track (separate composition) |
| **Tension** | Enemies alerted, pre-arena | Explore track + low `SYN` pulse |
| **Arena Start** | Seals close | **Intro stinger** (1 bar) quantized to the next bar, then Combat Low |
| **Combat Low** | Gain 0–33 | `DRM` `BAS` `RGT` |
| **Combat Mid** | Gain 34–66 | + `LEAD` + `CHR` |
| **Combat High** | Gain 67–99 | + `SYN`, drums switch to the double-time variation |
| **Overdrive** | Overdrive active | + `OVD`; `CHR` ducks −12 dB (the Choir is being drowned out) |
| **Wave Clear** | A wave ends with no enemies alive and next wave pending | `BRK` section for 2 bars (a heavy breakdown riff), then resume |
| **Heavy Spawn** | T3 or boss add spawn | **Heavy stinger** quantized to the beat (a brass/choir hit + guitar accent) |
| **Low Health** | Health < 25% | High-pass on music + the Arrhythm heartbeat layer rises |
| **Arena End** | Final enemy dies | **Outro** (2 bars) quantized to the next bar; seals dissolve on the downbeat |
| **Post-Combat** | After outro | Explore track fades in over 4 s |

Gain thresholds use hysteresis (±5) to prevent flapping. Transitions between stem sets fade in/out over **1 beat**, quantized to beats; state changes that add **drums variations** quantize to **bars**.

### 3.3 Implementation (UE5)
* **Quartz** clock per music track (BPM, time signature) owned by `UHBMusicSubsystem`.
* Stems as **MetaSound** sources started sample-accurately on the same Quartz tick; stem volumes driven by MetaSound parameters (`Layer_LEAD`, …).
* **Beat events:** `UHBMusicSubsystem` broadcasts `OnBeat(int BarIndex, int Beat)` and `OnBar` to gameplay systems — used by: Dorian's Martial Hymn, phalanx marching, Note-Platforms, halos/seams pulsing, Hymn Pylon pulses, Choir Seal close/dissolve timing, the M22 chord rotations.
* **Stinger scheduler:** queue stingers to the next beat/bar (`PlayQuantized`).
* **Diegetic override:** some arenas use diegetic playback (club PA, Quietus hull-speakers) — same stems, routed through a "space" submix with room reverb/EQ.
* **Music data:** `DA_MusicTrack` assets (stems, BPM, meter, sections, intro/outro/stinger assets, per-state stem masks).

### 3.4 Tempo & Tuning Guidelines
* Combat tracks 140–190 BPM (Note-Platform sections locked to 120; Dorian 120).
* Explore tracks 60–110 BPM or free time (ambient).
* Keys: stay within a few "home" tunings so stingers and kill stings (pitched to the current key — see §5.2) fit; each `DA_MusicTrack` declares its root key so pitched SFX can follow.

---

## 4. Track List (summary)

| Mission | Explore | Combat | Boss / Special |
|---|---|---|---|
| M01 | Room Tone | First Blood in the Vacuum · Hymnfall · Pump Hall | Maglev (clean guitar theme) |
| M02 | Sea of Tranquility | Crash and Burn · Resonator · Crown of the Moon | — |
| M03 | Spin Gravity | Concourse · Plectrum | The Long Way Down · Terminal Velocity |
| M04 | Golden Hour | Traffic · High Rise · Communion | **Rapture** (Ionian) |
| M05 | Undercity | Third Rail · Heavy Machinery · On Air | Last Encore (diegetic) |
| M06 | Whiteout | Obdurate · Hangar Queen · Hold the Line | — |
| M07 | Vespers | Heresy · Baptism · Excommunication | Reliquary (Tenebrae) |
| M08 | The Ranks | No Man's Land · Lockstep · Ramparts | Guard Break (duel) · **The Martial Psalm** (Dorian) |
| M09 | Deep Field | Radio Silence · Interference · The Great Ear | Dead Room (anechoic) |
| M10 | Shift Change | Molten · Production Line · Heavy Armor | — |
| M11 | The Machine Cathedral | Casting · Flywheel | Nine Meters Tall (mech) · **Engine Hymn** (Mixolydian) |
| M12 | Terminator | Open Pit · Heat Sink · Solar Maximum | Call and Response (Antiphon) |
| M13 | Glare | Mirror Maze · Conduit · Root of the Fire | **The Burning Cantor** (Phrygian) |
| M14 | (silence) | Intruders · Wax · Nobody Goes Quiet | Conductor (Maestro) |
| M15 | Jovian | Cryo · Carillon · Pressure | Twenty Kilometers |
| M16 | Hadal | Pressure Hull · Reef of Tears | Breach (Leviathan) · **The Grieving Tide** (Aeolian) |
| M17 | Sulfur Sky | Promenade · Vertigo · Keel | — |
| M18 | REM | Groundhog · Upside Down · Greatest Hits | **The Dreaming Choir** (Lydian) |
| M19 | Chancel | Intake · Liberation | Final Movement (Maestro) · Carry Him Home |
| M20 | Nave | Threshold · Pillars · Rood Screen | — |
| M21 | (wind) | Homecoming · The Axe · Aubade (Reprise) | — |
| M22 | Unresolved | Chord Change · Old Wars | **The Unresolved** (Locris) |
| M23 | — | Last Call · Frequency · One More Day | Siege Engine (mech) · Titan (Colossus) |
| M24 | Floor by Floor | Faithful · Last Dance · Congregation | **The Octave** |
| M25 | The Staves | First Line · Rest Is Not an Option · Taken Worlds · Almost Time | — |
| M26 | — | Wreck · Five Lines (gauntlet) | Last Ride (mech) |
| M27 | (Stair of Light) | — | **The Voice** · **The First Face** · **The Last Broadcast** |
| Hub | Home Is Loud (7 state variants) | — | — |
| Menus | Title: "Break the Hymn" (main theme) | — | Credits: acoustic + crowd versions |

**Masters** (27 collectible tracks) are separate diegetic songs by fictional human bands (SIGNAL LOSS, THE PERIGEE, ORBITAL DECAY, BRUTALIST, OBDURATE, THE HERETICS, THIRD ARMY, THE KUIPER BELT, KESSLER WORKS, THE PISTONS, DAYBREAKER, SOLAR FLARE, HARLAN PRICE & THE LATE SHIFT, THE DEEP SIX, ABYSSAL, THE CLOUD CITY SWINGERS, SLEEPWALKERS, THE PRISONERS, NAVE, the Oreth Aubade, Nine Bells, Clara's Lullaby, RADIO FREE STATIC ALL-STARS, THE QUIETUS CREW CHOIR, TAMSIN HALE, THE LAST ENCORE HOUSE BAND, The Last Broadcast) — varied genres: punk, blues-rock, lounge, post-rock, thrash, doom, folk.

---

## 5. Sound Design

### 5.1 Weapons
* 3+ layers per shot: **mechanical** (action, pump, rivet hopper), **body** (the punch — low-end transient), **tail** (environment-dependent: indoor/outdoor/space/underwater/anechoic variants via reverb sends).
* 4–8 round-robin variations; pitch/volume randomization ±3%.
* The **Static Rifle** and **Arc Coil** sound like overdriven amplifiers (snare-crack + fuzz + feedback); the **Silencer** removes sound; the **Axe** screams (tritone chord, per-swing howl through its holes); the **Larynx** sings in the Choir's voices (stolen).

### 5.2 Hits & Kills
* **Porcelain** impact library: tick (light), crack (medium), shatter (death) — layered with wet flesh and a faint pitched **chime** from the gold light.
* **Kill sting:** a short pitched metallic accent **tuned to the current music key** (from `DA_MusicTrack.RootKey`) so rapid kills create musical accents.
* **Breakdown finisher:** the **Arrhythm double-beat** (see below) on the final impact.

### 5.3 The Arrhythm (heartbeat)
* An irregular pattern (never 4/4): e.g., intervals in seconds `0.62, 0.41, 0.95, 0.38, 0.71, 1.02, 0.44…` generated by a seeded stochastic pattern with rules (no two intervals within 5% of each other; average ~70 BPM; spikes to ~140 BPM at low Health/Overdrive).
* Used: HUD heart pulse, low-health layer, silence moments, Breakdown finisher sting, the Heart Chamber, the Stair of Light.

### 5.4 Enemy Voices (signature chords)
Every enemy has a **signature** (its idle/alert/attack/death sounds are variations of it). The universal tells:
* **Cyan attack** = its own signature swell (dodge).
* **Gold attack** = a universal **rising perfect-fifth chime** (A4→E5) layered on its signature, 0.4 s before impact. *This chime is used for nothing else in the game.*
* **Heavy/T3 alert** = the signature plus a low bell/brass hit.
Full table in `03b` §5.3; extend it for every enemy in `DA_Enemy_*` (`SND_Signature`, `SND_Alert`, `SND_Tell_*`, `SND_Death`).

### 5.5 Silence Mechanics
* **Hush field:** sounds originating inside the field are low-passed (400 Hz) and −18 dB; if the player is inside, the whole mix is low-passed and a "pressure" tinnitus-like tone plays softly. Choir voices inside cut to silence instantly (the "vacuum duck").
* **Silencer:** the global mix (all buses, including music and UI) drops to −∞ for 1.5 s, then an "air rushing back" swell.
* **Designated silences:** cold open (6 s), Clara's room, Harlan's epilogue (6 s), Aubade exploration (wind only). Use a dedicated `SilenceController` that mutes buses cleanly (no tails bleeding).

### 5.6 UI Sounds
Themed as **guitar gear**: menu navigation = amp knob clicks; confirm = a stompbox click + a clean chord; back = a muted string scrape; upgrade purchase = a power-chord sting; Pedal equip = a stomp; Mastery complete = a harmonic squeal + crowd cheer.

---

## 6. Voice Over

| Character | Est. lines | Processing |
|---|---|---|
| Vire | ~350 | Radio (field) / dry (hub, cutscenes) |
| Lund | ~450 | Radio / dry; half-tuned (M19+): harmonized ×2 subtle |
| Wren | ~400 | Radio / dry |
| Harlan | ~250 (+27 radio intros) | Broadcast chain (compressed, warm, light saturation); in-person dry |
| Tamsin | 0 VO — signed (motion capture of a Deaf performer) + effort sounds | — |
| Aurelia | ~220 | Harmonized ×2 → ×8 across the game; close-mic intimacy |
| Locris | ~80 | Choir ×2 + dry voice underneath |
| Archons (6) | ~40 each | Choir-processed, each with a distinct vocal color |
| Unison | ~60 | 30-voice stack (see `02_Characters.md` §11) |
| Okafor, Juno, Thale, Pops, Marrow | ~40–120 each | Standard |
| Static soldiers (bark set) | ~600 (10 voices) | Radio/dry |
| Acolytes/Zealots (bark set) | ~300 (8 voices) | Light harmonizing |

**Subtitles** for all VO and important non-verbal audio (see UI doc). **Tamsin's** signed lines are subtitled with a ✋ icon and distinct color.

---

## 7. Mix

* **Priority (high → low):** gold chime & critical enemy tells → player weapon transients → player VO/comms (critical) → enemy tells (cyan) → music → enemy idle voices → ambience.
* **Sidechain:** enemy attack tells duck the music by 3–6 dB for 0.3 s (only for tells within 2500 cm and in the attack's direction relevance).
* **HDR audio / voice limiting:** max 48 simultaneous enemy voices; virtualize distant sounds; per-enemy-type voice caps.
* **Loudness:** target −16 LUFS integrated for the full mix at default settings; true peak ≤ −1 dBTP.
* **Options:** Master, Music, SFX, Voice, Radio (Harlan) sliders; **Telegraph Emphasis** (boosts enemy tells +6 dB and adds haptics); **Mono audio**; **Reduce sudden loud sounds** (compresses stingers & Overdrive activation); **Subtitles for sound cues** (see UI).

---

## 8. The Last Broadcast — Production Note

The emotional climax depends on this audio. Requirements:
* **Hundreds of distinct human voices** (ideally 300+ individual recordings): singing (any song — each different), screaming, laughing, crying, shouting encouragement ("*GET UP!*", "*COME ON!*", names of loved ones), playing instruments badly (recorder, trumpet, drums, pots and pans, car horns, a kazoo), a garage thrash band, a children's choir singing a nursery rhyme, an opera singer, a crowd at a stadium chanting, an old man whistling.
* **Sources:** community recording sessions, crowd-sourced submissions (with consent/releases), or — if AI-generated — **each voice must be generated individually with distinct parameters** (age, gender, accent, pitch, emotion, content) and never cloned from real people without consent.
* **Mix:** chaotic but not muddy — spatialized as a 360° surround wall, with the band's main-theme performance cutting through the middle. Across the 6-minute phase the crowd slowly *converges* onto the main theme's hook — not in unison, but in joyful, messy, overlapping approximation.

---

## 9. Asset Naming

`MUS_<Mission>_<Explore|Combat_A|B|C|Boss>_<Stem>` (e.g., `MUS_M04_Combat_B_LEAD`) · `STG_<Type>` (stingers) · `SFX_WPN_<Weapon>_<Action>_<Var>` · `SFX_ENM_<Enemy>_<Event>_<Var>` · `SFX_ABL_<Ability>_<Event>` · `SFX_UI_<Event>` · `VO_<Char>_<Mission>_<LineID>` · `RAD_Mxx` · `AMB_<Kit>_<Zone>`.
