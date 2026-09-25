# 03 — Story & Campaign Narrative

This document tells the whole story, act by act and mission by mission. Mission documents (`14_Missions/`) reference these beats by ID (`BEAT_Mxx_n`). Cutscene scripts and radio segments are in `03b_Cutscenes_Dialogue_and_Radio.md`.

**Narrative delivery philosophy (DOOM-style restraint):**
* ≤ 25 minutes of total cutscenes in a 34-hour game. Most cutscenes are **first-person, in-engine, skippable**, and ≤ 90 seconds.
* Story is mostly carried by **radio chatter during play** (never forcing the player to stop), **Radio Free Static intros** on mission load, **environmental storytelling**, **the Archive** (codex), and **hub conversations** (optional, player-initiated).
* The Unsung's impatience is a narrative device: when the player moves on during a long radio transmission, the speaker notices ("...and you're already gone. Right.").

---

## THE SHAPE OF THE STORY

| Act | Title | Missions | Question the Act answers | Aureole |
|---|---|---|---|---|
| I | **FIRST NOISE** | M01–M04 | What is the Unsung, and can it fight the Choir? | 60% → first band broken |
| II | **THE TUNED EARTH** | M05–M09 | Who is behind this, and why did the Choir come here? | 2 of 8 voices silenced |
| III | **IRON AND FIRE** | M10–M14 | What does the war cost? | 4 of 8 silenced; the Quietus is boarded |
| IV | **DEEP WATER, HIGH AIR** | M15–M19 | Can we save Lund, and what does he know? | 6 of 8 silenced |
| V | **THE UNSUNG** | M20–M24 | Who is the Unsung, really? | 7 then 8 of 8 — Aureole shattered |
| VI | **THE LAST BROADCAST** | M25–M27 | Can individuality defeat unity? | The Unison itself |

**The Aureole as a progress bar:** the Aureole is an 8-band ring (7 Archon bands + 1 Octave band). Each defeated Archon permanently removes one colored band from the sky in all Earth and orbital missions and in the Quietus bridge window. Band colors, in order of removal: Ionian (pale gold), Dorian (steel white), Mixolydian (brass), Phrygian (solar white-orange), Aeolian (sea cyan), Lydian (lilac), Locrian (cracked grey), Octave (pure white).

---

## ACT I — FIRST NOISE

### M01 — Tranquility Deep
*Lunar subsurface. The awakening.*

* **BEAT_M01_1 (Cold open):** Black screen. Absolute silence (the audio mix is literally silent for 6 seconds). Caption: *TRANQUILITY DEEP — CONCORD XENOACOUSTIC RESEARCH SITE — 11 JUNE 2204.* A muffled old man's voice through the dark: "...forgive me. I don't know what you are. But they're afraid of you, and that's all I have left." A shriek of ultrasonic feedback. The black material around the player **cracks like glass**; light spills in; a single, massive, down-tuned guitar chord rings out — and the Unsung's visor ignites.
* **BEAT_M01_2:** The Unsung breaks out of the Vault into its containment chamber. The Hymn floods in — faint, beautiful choir. The Unsung touches their visor (`GST_HelmetTouch`) — hearing *that song* again after four billion years — and slowly clenches a fist. Two Tuned researchers stagger in, singing. The player's first kills are bare-handed (tutorial: punch, Faltering, Breakdown).
* **BEAT_M01_3:** Dr. Lund on the PA/radio: he's sealed in the Control Annex above; the base's 400 staff were tuned when the Selene Relay on the surface began to sing. He guides the Unsung upward. The Unsung takes a **Breacher** shotgun from a dead CDF guard.
* **BEAT_M01_4:** The Rig's systems wake after aeons in stasis — the **Harrow** comes online (tutorial: Shred for ammo, grapple across the collapsed Containment Ring).
* **BEAT_M01_5:** The labs: evidence of seventy years of failed Vault research and Lund's 26 years of notes (Archive entries). The first **Choristers** appear — true Choir-forms descending through Hymnfall — and the music goes full metal for the first time.
* **BEAT_M01_6:** The **Riveter** from the CDF armory. A final arena in the pump hall under the surface lift.
* **BEAT_M01_7 (End):** The Unsung rides the lift into the **Observation Dome**. Through the glass: Earth — wearing a luminous, half-complete ring of gold and white light. **The Aureole.** Every screen in the dome shows the same broadcast: Precentor Aurelia Voss, serene: "Children of Earth, do not be afraid. The pain is almost over." The Unsung punches the nearest screen (`GST_ScreenSmash`). Lund, quietly: "That's the Aureole. When it closes, there won't be anyone left to hear it."

### M02 — Selene Relay
*Lunar surface. Meet the Static.*

* **BEAT_M02_1:** Lund patches in **Commander Solenne Vire** of the Static: the Quietus is inbound to evacuate Tranquility Deep's few survivors, but the Selene Relay's Hymn is so strong their collars will fail on approach. The Relay has three **resonator cores**. Vire: "Lund says you're some kind of ancient weapon. I say prove it."
* **BEAT_M02_2:** A crashed Static dropship: the strike team sent to destroy the Relay was tuned; the Unsung faces the **Tuned Troopers** they became, and takes their **Static Rifle**. Juno Reyes, the only survivor, hides in the wreck and is rescued (she becomes a recurring voice).
* **BEAT_M02_3:** Rig subsystems come online in sequence (**Distort**, **Frag Charge**). Choristers begin throwing **gold notes**: Lund notices ("Those golden ones... they're *resonant*. If you hit them at the right moment, you could send them back!") — Counter tutorial.
* **BEAT_M02_4:** Core by core, the Relay's song weakens. After the second core, Aurelia's hologram appears and addresses the Unsung *directly* for the first time: "So you're what Kasimir was hiding under the Moon. You poor thing. How long have you been alone?"
* **BEAT_M02_5:** Final core guarded by the first **Cantor** and a heavy wave. The Relay collapses in a slow-motion avalanche of white stone.
* **BEAT_M02_6 (End):** The **Quietus** descends — a vast, black, brutalist ship lined with anechoic wedges, landing in perfect silence. Tamsin at the helm. The Unsung walks up the ramp. Vire waits at the top, looks up at them, and says: "We opened the box. Now I guess we find out what was in it." **Hub unlocked.**

### M03 — The Meridian Tether
*Orbit to Earth. The string.*

* **BEAT_M03_1 (Briefing in hub):** The Quietus can't descend through the Aureole's choral field — its anechoic hull would shake apart. The only way to Earth is the **Meridian Tether**, the space elevator. But the Choir has taken **Apex Station** and is using the Tether's 36,000-km ribbon as a **string** — plucking it to sing the Hymn straight down into Halcyon. Lund: "They've turned the largest structure humans ever built into a *harp*."
* **BEAT_M03_2:** The Unsung drops onto Apex Station. Zero-g exterior views, Earth below, the ribbon humming with visible light-pulses. The **Gravedigger** is recovered from a Static sergeant's locker ("For emergencies — Sgt. D. Ruiz" scratched on the stock).
* **BEAT_M03_3:** Rig subsystems: **Hush Charge**; then **Overdrive** comes online after the first big arena — Wren (first time on comms): "Whoa — what did your suit just *do*? My meters just clipped!"
* **BEAT_M03_4:** A climber car ride down to **Waystation Nine** (moving-arena set piece).
* **BEAT_M03_5:** At Waystation Nine the Choir has grown a **Bridge** — an organ-bone structure clamped around the ribbon. Destroying it "detunes" the Tether. The Hymn over Halcyon falters for the first time in months: on the radio, faintly, the player hears **Radio Free Static** break through: "...is this thing — *hello?* Halcyon, the sky just went *quiet* — somebody up there is *fighting*!"
* **BEAT_M03_6 (End):** Final descent in a damaged climber car through the atmosphere, fighting Vespers, Wailers and an Ophan on the car's roof; the brakes fail; the car slams into the ocean anchor platform off Halcyon. The Unsung stands up out of the wreckage and looks at the city — and the colossal gold Spire rising from its center.
* **Post-mission hub:** Tamsin signs "Can you understand me?" The Unsung pauses, then signs a clumsy "Yes." (`GST_Sign_Yes`). Tamsin grins.

### M04 — Rapture
*Halcyon. The first Archon.*

* **BEAT_M04_1:** The **Ionian Spire** grows out of the **Halcyon Bowl**, a 120,000-seat stadium where the Consonance held its largest "Communion". The crowd has been standing in rapture for three weeks, slowly tuning. Sgt. **Bo Okafor**'s Static cell is pinned down on the elevated highways.
* **BEAT_M04_2:** Fight across the elevated highways; relieve Okafor's position; the **Hammerfall** rocket launcher recovered from a CDF checkpoint armory.
* **BEAT_M04_3:** Through the Bowl's concourses — halls full of rapturous, swaying Tuned civilians who do not attack unless the Choir commands (horrifying, sad set dressing; the player cannot hurt passive civilians — they are non-damageable props in this space).
* **BEAT_M04_4 (Boss):** **IONIAN, THE RAPTURE** on the Bowl's field. Its joy is a weapon; the crowd's song empowers it.
* **BEAT_M04_5 (End):** Ionian shatters. The crowd collapses — and some of them **wake up**, confused, crying, alive. The first band of the Aureole flickers and dies in the sky. On the radio, Harlan is weeping openly on air. On the Quietus bridge, Vire watches the feed, and slowly salutes the screen.

---

## ACT II — THE TUNED EARTH

### M05 — Radio Free Static
*Halcyon Undercity. Save the voice of humanity.*

* **BEAT_M05_1:** The Choir has figured out what keeps millions of humans untuned: **Radio Free Static**. A Hymnfall is converging on the **Halcyon Broadcast Tower**. Harlan is still on air.
* **BEAT_M05_2:** Metro tunnels and flooded districts. The **Decibel District** — Halcyon's old nightclub quarter — where Static fighters have turned every venue into a fortress with walls of amps. Okafor's squad gives the Unsung a CDF **Shredder** rotary cannon.
* **BEAT_M05_3:** The Choir's converted construction machines — **Organ Grinders** — batter the tower's base.
* **BEAT_M05_4:** Up the tower. Harlan broadcasts the fight live ("I am looking at a seven-foot war god in a tin can tearing a walking pipe organ in half, folks, and I have never been happier").
* **BEAT_M05_5 (End):** At the top, Harlan meets the Unsung. "You're taller than on the posters." He gives them his "lucky pedal" — an old stompbox — the first **Pedal** (Pedalboard unlocked). "For luck. Not that you need it."

### M06 — Fort Obdurate
*Alpine fortress. Intelligence and iron.*

* **BEAT_M06_1:** Dorian's legions have taken **Fort Obdurate**, the CDF's alpine command fortress, and tuned its garrison. Its deep archives contain the CDF's intelligence on the Consonance leadership. Its hangars contain the prototype **Arc Coil** and several **Anvil Siege Frames**.
* **BEAT_M06_2:** Infiltration across snowfields, funicular, gun galleries. **Bellwethers** and **Tuned Marksmen** introduced.
* **BEAT_M06_3:** The Arc Coil recovered from the weapons lab.
* **BEAT_M06_4:** The archive: Lund extracts the data remotely while the Unsung holds the vault against waves.
* **BEAT_M06_5 (End):** The data points to **Mount Canticle** — the Consonance's seminary — where the Precentor coordinates the Spires. Wren flags the Anvil frames for later ("I'm gonna need, like, a month. Or three missions. Whichever comes first.").

### M07 — Mount Canticle
*The cult's heart. Meet the Herald.*

* **BEAT_M07_1:** The seminary's terraces: white marble, reflecting pools, thousands of **Acolytes** and **Zealots**. Human enemies who talk, pray and scream — an unsettling change.
* **BEAT_M07_2:** **Sirens** introduced in the flooded catacombs.
* **BEAT_M07_3 (Mini-boss):** **The Tenebrae** — the Consonance war-machine — piloted by Choirmaster **Idris Thale**, blocks the amphitheater. Heavily damaged, it retreats.
* **BEAT_M07_4:** The Precentor's sanctum. **Aurelia Voss is there in person.** She does not flee at first. She talks — gently. She reveals the **Seven Voices** and the **Octave**: "Eight voices. Seven of them are ancient and patient. The eighth is me. When the chord is complete, humanity will never be lonely again." The Unsung raises the Breacher. She smiles sadly and steps backward into a Resonance Gate.
* **BEAT_M07_5 (End):** The Unsung smashes the sanctum's broadcast console. Lund recovers the Consonance's star-charts: the locations of all seven **Cantor Spires**.

### M08 — The Iron Psalm
*Dorian's war-cathedral. The duel.*

* **BEAT_M08_1:** On the plains below the Alps, the CDF's last field army was tuned en masse. From its wreckage, **Dorian** has grown **the Iron Psalm**: a fortress of bone ramparts and parade grounds, where thousands of Tuned soldiers drill in perfect lockstep.
* **BEAT_M08_2:** The first **Requiem Knight** duel: a Choir knight who fights with perfect discipline.
* **BEAT_M08_3:** **Hymnals** introduced.
* **BEAT_M08_4 (Boss):** **DORIAN, THE MARTIAL PSALM.** Before the fight, Dorian recognizes the Unsung: "**Shieldwarden.** I sealed you in the dark once. I will do it again, and this time I will stay to listen to the silence." (The player does not yet know what "Shieldwarden" means.)
* **BEAT_M08_5 (End):** Dorian falls; the second band dies. Lund, in the hub: "It called you *Shieldwarden*. That's... that's a title in the glyphs on the Vault. I thought it was the *name of the prison*."

### M09 — The Listening Array
*The high desert. The truth about the Choir's arrival. The Silencer.*

* **BEAT_M09_1:** Lund believes the Signal's original recordings at the **Listening Array** can teach him how the Hymn is structured — enough to build the anti-Hymn weapon he and Wren have been designing: the **Silencer**. The Array's 60 dishes have grown into colossal bone ears.
* **BEAT_M09_2:** **Echoes** (Hush-killable spirits) and **Fugues** introduced.
* **BEAT_M09_3 (Mini-boss):** The Tenebrae returns. Thale dies in its wreck.
* **BEAT_M09_4:** In the Voss Institute's anechoic chamber, Wren and Lund assemble the Silencer while the Unsung holds the line. First Silencer shot on a colossal horde.
* **BEAT_M09_5 (Twist):** Aurelia hijacks every frequency: she plays Lund's classified 2194 recording — the Vault ringing — and explains to the whole solar system that the Choir came to Earth **because it heard the Unsung**. "They did not come for you, children. They came for *it*. Kasimir Lund woke the thing in the Moon, and it called them here."
* **BEAT_M09_6 (End, hub cutscene):** Lund confesses to the crew. Silence on the bridge. Vire: "Doesn't matter why they came. Matters that they *leave*." The Unsung puts a hand on Lund's shoulder.

---

## ACT III — IRON AND FIRE

### M10 — The Forge-Belt
*Industry turned hymn.*

* **BEAT_M10_1:** **Mixolydian, the Engine Hymn**, has tuned the **Kessler Forge-Belt** — a continent-spanning industrial corridor — into a machine-cathedral that births **Instruments** by the thousand.
* **BEAT_M10_2:** Foundries, rolling mills, conveyor rivers of molten steel. A derailed CDF armored train yields the **Lance** railgun.
* **BEAT_M10_3:** The first **Organ Walker** (mech-scale enemy) seen striding across the horizon — a warning.
* **BEAT_M10_4 (End):** The Unsung reaches the CDF heavy-armor depot where Wren has remotely restored an **Anvil Siege Frame**: "She's old, she's ugly and she's *mine*. Well. Yours. Don't scratch her."

### M11 — The Assembly
*The machine-cathedral. The first mech.*

* **BEAT_M11_1:** **Anvil Siege Frame** segment: stride through the Assembly's outer yards destroying Organ Walkers and factories.
* **BEAT_M11_2:** On foot into the Assembly's heart.
* **BEAT_M11_3 (Boss):** **MIXOLYDIAN, THE ENGINE HYMN** — phase 1 on foot inside the singing machine; phase 2 in the Anvil against its colossal assembled form.
* **BEAT_M11_4 (End):** The Forge-Belt's machines grind to a halt. Third band dies. Wren, sobbing with joy about the Anvil's survival.

### M12 — Helios Station
*Mercury. Heat and light.*

* **BEAT_M12_1:** **Phrygian, the Burning Cantor**, is using the **Corona Array**'s mirror fields on Mercury to focus the Hymn into the Sun. Lund, horrified: "If the Sun sings, every world in the system hears it. *There is no collar loud enough.*"
* **BEAT_M12_2:** Solar exposure hazards: move from shade to shade.
* **BEAT_M12_3:** The **Ripsaw** recovered from a mining foreman's workshop.
* **BEAT_M12_4:** **Profundo** introduced.
* **BEAT_M12_5 (Mini-boss):** **The Antiphon** — two Cantors singing call-and-response.
* **BEAT_M12_6 (End):** A cracked figure with a broken halo watches from a distant ridge. When the Unsung looks, it's gone. (First glimpse of **Locris**.)

### M13 — Corona
*The Burning Cantor.*

* **BEAT_M13_1:** Across the mirror fields to the Phrygian Spire as the Sun begins to *hum*.
* **BEAT_M13_2 (Boss):** **PHRYGIAN, THE BURNING CANTOR.** Phrygian admires the Unsung: "Your rage is the most beautiful sound I have ever heard. Sing it *with* us. Imagine it — fury, eternal, perfect." The Unsung answers with the Gravedigger.
* **BEAT_M13_3 (End):** Fourth band dies. The Sun stops humming. Then a distress call: the **Quietus** has gone silent. Vire's voice, broken by interference: "...boarded... the Mute Engine is down... *they're inside*—"

### M14 — Dead Air
*The hub, invaded.*

* **BEAT_M14_1:** A saboteur — **Deacon Marrow**, a harmonized Consonance agent hiding among the refugees as a medic — disabled the Mute Engine. Without its anechoic field, the Choir could hear the Quietus — and came.
* **BEAT_M14_2:** The Unsung rides a Drop Coffin back aboard. Every familiar hub space — the Armory, the Listening Room, the mess — is dark, overrun, and *quiet*. Crew fight with whatever makes noise.
* **BEAT_M14_3:** Private **Juno Reyes** dies holding a corridor; her collar is still playing music when the Unsung finds her.
* **BEAT_M14_4:** The **Maestro** is introduced — conducting the boarding.
* **BEAT_M14_5:** Wren holds the engine room; the Unsung restores the Mute Engine in a desperate defense.
* **BEAT_M14_6 (End):** The Maestro — **Maestro Primus** — seizes **Lund** and drags him through a Resonance Gate. The Mute Engine roars back to life, the ship goes silent again — and the Choir aboard seizes up and crumbles. Vire, bleeding, on the bridge: "Find him."
* **Hub state change:** the Quietus is scarred (burn marks, Choir-growth remnants, memorials to the dead) for the rest of the game, slowly repaired.

---

## ACT IV — DEEP WATER, HIGH AIR

### M15 — Cryobore
*Europa. Twenty kilometers of ice.*

* **BEAT_M15_1:** Lund's Static Collar carries a tracker. Its last ping came from Jupiter space before it went dark. Vire's call: while Wren refines the trace, strike the nearest Spire — **Aeolian**, singing beneath the ice of **Europa**.
* **BEAT_M15_2:** **Cryobore Station**: a drilling complex above a 20-km borehole. The descent: service elevators, ice caverns, pressure habitats.
* **BEAT_M15_3:** **Carillon** introduced (walking bell-tower titan). **Gilded Bellwether** introduced.
* **BEAT_M15_4:** Deep in the bore, the ice *sings* — a whale-like choir rising from below. A colossal shape passes behind the ice walls (**the Leviathan**).
* **BEAT_M15_5 (End):** The Unsung reaches the ocean habitat at the bottom of the bore. The dark water outside the viewports is full of slowly drifting lights.

### M16 — The Singing Sea
*Europa's ocean. Grief.*

* **BEAT_M16_1:** Habitat domes on the ocean floor linked by pressure tunnels; flooded sections force detours (no swimming — flooded rooms are barriers or instant-recovery hazards).
* **BEAT_M16_2 (Mini-boss / set piece):** **The Leviathan** — a Choir-whale the size of a building — attacks a tunnel; chase sequence through collapsing tubes.
* **BEAT_M16_3 (Boss):** **AEOLIAN, THE GRIEVING TIDE**, in the drowned choir-reef. Aeolian mourns everything: "Every song ends. I am only trying to make the ending gentle." Arena floods and drains in phases.
* **BEAT_M16_4 (End):** Fifth band dies. Wren's trace resolves — but there's nothing there; the location is being *hidden*. Vire: "Something's hiding him." Wren: "A dream. Venus. The Lydian Spire." The only Archon who can hide something from the whole solar system is **Lydian**, on Venus.

### M17 — Cytherea
*Venus. The city in the clouds.*

* **BEAT_M17_1:** **Cytherea**, a floating aerostat city 55 km above Venus's surface: gasbag domes, hanging gardens, sulfur-yellow skies. Half a million survivors lived here. Tamsin docks the Quietus against a drifting district.
* **BEAT_M17_2:** Lydian's dream is leaking into reality: **illusory enemies** (translucent, shimmering — harmless if ignored, dangerous only if you stand in their "song"), gardens growing impossibly, gravity leaning sideways in some rooms.
* **BEAT_M17_3:** The Unsung reaches the city's central keel, where the dream is thickest. Lydian tries to put the Unsung to sleep, but the Arrhythm won't allow it — so Lydian pulls the whole district into the dream instead.
* **BEAT_M17_4 (End):** The sky turns inside out. The next mission takes place *inside* the dream.

### M18 — The Dreaming Choir
*Inside Lydian's dream.*

* **BEAT_M18_1:** A surreal level built from memories and fragments of everyone Lydian has tuned: a Halcyon street that loops, a Quietus corridor made of clouds, a CDF bunker upside-down in the sky, a staircase of floating pianos.
* **BEAT_M18_2:** Brief, unsettling **memory flashes** — the Unsung's own memories bleeding into the dream: a pale stone city, a figure with a shield reaching out. The Unsung stops. The player cannot move for 2 seconds. Then the music slams back in.
* **BEAT_M18_3 (Boss):** **LYDIAN, THE DREAMING CHOIR** — a fight in shifting, floating arenas.
* **BEAT_M18_4 (End):** Lydian bursts like a soap bubble; the dream collapses; Cytherea drops 2 km into safer clouds (survivors live). Sixth band dies. With the dream gone, Wren's trace resolves at last: **the Chancel**, a Choir conversion facility in low Earth orbit.

### M19 — The Chancel
*Rescue.*

* **BEAT_M19_1:** The **Chancel** — a ribbed, cathedral-sized structure in orbit, where captured humans are brought to be tuned in vast choir-halls. Stealthy-ish opening: the Unsung enters through a waste chute. (Still combat — the "stealth" is flavor.)
* **BEAT_M19_2:** Aurelia's voice from the choir-walls, speaking gently and constantly. She offers **rest**. She shows the Unsung a vision (a short in-engine sequence rendered in gold): the **First Unison** on Solace — billions of Oreth singing — and one small, armored figure alone in a square, screaming. The Unsung stops walking.
* **BEAT_M19_3:** The conversion halls: thousands of humans standing in rows, gilding. The player frees survivors by destroying the halls' **Resonance Organs** (optional objectives, big payoff: hundreds of humans collapse, freed).
* **BEAT_M19_4:** Lund found in the central **Tuning Font** — half-gilded, golden tears, alive. He can *hear the Unison*. He grips the Unsung's gauntlet: "Solace. The path to the heart of it... goes through Solace. You... you were *born* there. They're all— your people are *all in there*."
* **BEAT_M19_5 (End):** Escape as the Chancel tears itself apart. Lund follows the Unsung through the final arena on a stretcher-drone (an escort, not a carry — there is no one-handed mode).

---

## ACT V — THE UNSUNG

### M20 — The Nave
*Into the Harmonium.*

* **BEAT_M20_1:** Lund, sedated and half-tuned, "hums" the Quietus's Gate Fork into the right key. The Quietus jumps into the **Harmonium** for the first time. Everyone aboard hears the Hymn through the hull — even through the Mute Engine — a pressure in the bones.
* **BEAT_M20_2:** The Unsung drops into **the Nave**: a cathedral hall miles long, lined with pillar-choirs of billions of tuned beings from thousands of worlds. Sound is visible here: notes drift as light rings. Some platforms are made of held notes that fade when the chord changes (timed traversal).
* **BEAT_M20_3:** First glimpse of the **Staves** and the **Clef** through the Nave's vast windows.
* **BEAT_M20_4 (End):** At the Nave's far end, a gate onto a dead grey planet. **Solace.**

### M21 — Aubade
*The Silent City.*

* **BEAT_M21_1:** **Aubade**, the Oreth capital. For the first time in the game: **no Hymn**. The city was tuned so completely it no longer needs to sing. The ambient audio is wind and nothing else. The combat music does not play until the first fight — and even then it arrives slowly.
* **BEAT_M21_2:** Exploration-heavy. Plazas full of Oreth statues frozen mid-song (the actual gilded bodies of the Oreth, as they were at the moment of the First Unison). The Archive fills with Oreth history.
* **BEAT_M21_3:** A small plaza. One statue is different: an armored Oreth with a shield — **Veyl** — reaching out toward an empty space where someone else should have stood. The Unsung stops, removes a gauntlet, and touches the statue's hand (`GST_HeartPress`, then touch).
* **BEAT_M21_4:** The **Hall of Wardens**: statues of Oreth soldiers. One plinth is empty, its name-glyphs chiseled out. The Unsung's.
* **BEAT_M21_5:** Dorian's trophy altar in the old Warden Citadel: **the Axe**, resting where it was laid four billion years ago. When the Unsung lifts it, it screams — and every statue in the city cracks.
* **BEAT_M21_6 (End):** A voice behind them. Soft, cracked, doubled. "...*I knew it would be you.*" **Locris** stands in the square — the living version of the statue. "Hello, Shieldwarden." Cut to black.

### M22 — The Unresolved
*Locris's domain.*

* **BEAT_M22_1:** Locris tells the truth, in fragments, as the Unsung fights through their domain — a region of Aubade that never resolves: streets that loop back, stairs that lead to their own beginnings, rooms that rotate when the chord changes. The Unsung is Oreth. The one who would not sing. Locris — Veyl — was their shield-sibling, and chose the Unison *because they could not bear to be left alone with their grief*.
* **BEAT_M22_2 (Boss):** **LOCRIAN — LOCRIS, THE UNRESOLVED.** The fight shifts between arena configurations mid-battle.
* **BEAT_M22_3 (End):** Defeated, Locris does not die. They look at the Unsung for a long time. Then they grip their own incomplete halo and **break it**. The seventh band dies. Locris's voice — now only one voice, hoarse and lonely — says: "It's so quiet. I'd forgotten what my own voice sounded like." They give the Unsung the **Key of the Unresolved**, which can open the Clef. Then, to everyone's horror, the sky of Solace flares white: on Earth, Aurelia has begun to sing the **Octave alone**, forcing the Aureole's completion early. Vire: "Get back here. *Now.*"

### M23 — Aureole
*Return to Earth. The last stand of Halcyon.*

* **BEAT_M23_1:** The **Cathedral of the Final Chord** has consumed the center of Halcyon: a white-gold megastructure kilometers tall. The Aureole — now a single, blinding white band — pulses faster and faster. Humans all over the planet feel their collars failing.
* **BEAT_M23_2:** **Anvil Siege Frame** assault across the ruins against **Choir Colossi**, with Okafor's Static cell and a hundred Static soldiers blasting music from every vehicle.
* **BEAT_M23_3:** The Broadcast Tower is under siege again. The Unsung breaks the siege. Harlan, still on air, voice cracking: "They can take the tower. They can't take the *frequency*." Harlan and Vire first discuss the idea of the **Last Broadcast** over comms.
* **BEAT_M23_4 (End):** The Unsung reaches the base of the Cathedral.

### M24 — The Octave
*The Herald.*

* **BEAT_M24_1:** Ascent through the Cathedral: every floor a different memory of Aurelia's life (her lab, her daughter's bedroom preserved in gold, the Listening Array's control room). Environmental storytelling of her grief.
* **BEAT_M24_2 (Boss):** **AURELIA VOSS, THE OCTAVE.** A colossal transfigured form of porcelain and light. Three phases.
* **BEAT_M24_3 (End):** The Octave shatters. In the wreckage, a small, ordinary, broken woman. Her gilding cracks off. "...It's so *loud*." She almost smiles. "I'd forgotten." She dies. The Aureole **shatters** — its light falls across Earth like snow. Humanity's collars stop failing. Cheering on every channel.
* **BEAT_M24_4 (Final twist):** And then every star in the sky begins, very faintly, to *hum*. Lund, in the Quietus med-bay, eyes wide: "It's not stopping. The chord was never *theirs* to finish. It's *coming*." The **Unison** has begun the **Final Chord** itself.

---

## ACT VI — THE LAST BROADCAST

### M25 — The Staves
*The plan and the charge.*

* **BEAT_M25_1 (Hub cutscene — the plan):** Lund: the Unison can't be out-sung — it can only be *disagreed with*. It has never heard more than one voice at a time. Harlan: "So we give it *all of them*." **The Last Broadcast**: every surviving human on Earth — 5 billion people — will scream, sing, play, bang pots and pans at the same moment, and Radio Free Static will carry it. Lund, half-tuned, can act as a living antenna to carry that noise into the Harmonium — if the Unsung can deliver him to the heart of the Unison. Lund knows it will kill him. Vire: "Everyone who can hear this, get loud."
* **BEAT_M25_2:** The Quietus jumps into the Harmonium. The Unsung runs **the Staves** — five kilometer-wide bridges that hum underfoot — while the Quietus flies alongside providing fire support. Massive battles, Kick Pad chains between Staves, Note-Worlds looming.
* **BEAT_M25_3 (End):** The Clef ahead: a spiral citadel kilometers tall, sealed.

### M26 — The Clef
*Breach.*

* **BEAT_M26_1:** The Key of the Unresolved opens the outer gate — but the inner walls are sealed. Tamsin signs to the Unsung: "Hold on." She **rams the Quietus into the Clef's wall**. The ship tears a hole and embeds itself (the Quietus becomes a landmark inside the level).
* **BEAT_M26_2:** Final **Anvil Siege Frame** segment through the Clef's outer rings.
* **BEAT_M26_3:** **Locris returns**, one voice, holding the inner gate against the Choir so the Unsung can pass: "Go on. Be loud for both of us." (Locris's fate is left ambiguous; an Archive entry after the credits confirms they held the gate to the end.)
* **BEAT_M26_4:** Gauntlet: every enemy type in the game in escalating arenas.
* **BEAT_M26_5 (End):** The core chamber. The Unison waits.

### M27 — The Final Chord
*Unison.*

* **BEAT_M27_1:** The Unison speaks to the Unsung — its "Little Wrong Note", its **Sibling** — and asks them, gently, to finally rest.
* **BEAT_M27_2 (Boss, Phase 1):** **THE VOICE** — the Unison's radiant sphere.
* **BEAT_M27_3 (Boss, Phase 2):** **THE FIRST FACE** — the Unison takes the form of the Oreth as they were: millions of faces, one of them the Unsung's own mother (never stated — an Archive entry after the game implies it).
* **BEAT_M27_4 (Boss, Phase 3):** **THE LAST BROADCAST.** Harlan: "This is Radio Free Static. This is the Last Broadcast. *Make it loud.*" Five billion human voices — screaming, singing badly, laughing, crying, cursing, banging drums — flood into the Harmonium through Lund. The Unsung enters **Last Overdrive** (permanent Overdrive for the phase). The Unison's voices begin to **disagree**: its body fractures into factions, each singing a different note. "What— what is this? So many. They are all— *different*—"
* **BEAT_M27_5 (Finale):** The final blow with the Axe into the Unison's heart. The Unison shatters into billions of individual voices — sparks of light drifting away in every direction, each singing its *own* note. For the first time in four and a half billion years, the Oreth are free to be themselves again — and free to end.
* **BEAT_M27_6:** Lund, fading, smiling: "Listen. That's... *everyone*." He dies.

### EPILOGUE
* **Earth:** The Aureole's remnants fall like snow. People who were tuned in the last months slowly wake as their gilding cracks away. Those tuned long ago do not wake — they become **the Quiet**: peaceful, alive, still. Their families sit with them. (Bittersweet; not everyone is saved.)
* **The Quietus** limps home, embedded wreckage and all, towed by Static ships.
* **Harlan's final segment** (voice over a montage of survivors): "This is Radio Free Static. The war's over, and I don't have a single song left that's loud enough. So I'm going to do something I haven't done in a long, long time." *[Six seconds of silence.]* "...Yeah. That's the good kind."
* **Final scene:** The Quietus's hull. Tamsin sits beside the Unsung, looking at Earth. She signs: "What will you do now?" The Unsung looks at their hands. Then signs, carefully: "**Thank you.**" (`GST_Sign_Thanks`) She smiles.
* **Post-credits:** Deep space. A red dwarf star, a small blue world. Faintly, a choir begins to sing. Cut to the Quietus's hull — the Unsung's visor ignites. Title card: **THE UNSUNG WILL RETURN.**

---

## THEMES (reference for all writers)

| Theme | How it's expressed |
|---|---|
| **Individuality vs. Unity** | Choir = perfect unity and oblivion. Humans = messy, loud, individual, alive. The finale is won by *disagreement*. |
| **Pain as the price of self** | The Choir offers an end to pain. Every major villain is motivated by grief (Aurelia, Aeolian, Veyl). The game never says pain is good — only that it is *yours*. |
| **Noise as resistance** | Metal music, static, screaming — the soundtrack is thematically part of the war. |
| **Guilt and responsibility** | Lund rang the Vault. The Choir came for the Unsung. Neither excuses the Choir; both characters choose to fight anyway. |
| **Loneliness** | The Unsung has been alone for 4.5 billion years. The game slowly gives them a crew — and ends with the Unsung's first "words": *thank you*. |
