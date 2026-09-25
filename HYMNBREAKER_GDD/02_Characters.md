# 02 — Characters

Cast size is deliberately small. Every speaking character must be memorable from a single line of dialogue. Voice direction notes are written for VO casting and for AI voice-generation prompts.

---

## 1. THE UNSUNG (Player Character)

| | |
|---|---|
| **Names** | *The Unsung* (Choir), *the Hymnbreaker* (human legend), *the Wrong Note*, *the Heart Out of Time* (Choir records), *Breaker* (Static soldiers' slang). Real Oreth name: erased. Never revealed. |
| **Species** | Oreth (shown in M19, explained in M22). Appears as a heavily armored humanoid; face never shown. |
| **Height** | 205 cm in the Rig (gameplay capsule 192 cm — see movement doc). |
| **Voice** | **None. Ever.** Breathing and effort sounds only (grunts on heavy impacts, a sharp exhale after Breakdowns). No screams, no words. |
| **Age** | ~4.5 billion years (most of it dormant or fighting). |

### Personality (expressed through action only)
* **Impatient with talk.** Walks away from monologues, smashes screens showing the Herald, cocks the shotgun while an NPC is explaining.
* **Protective of humans**, especially the helpless. Always kills Choir-forms feeding on humans first. Gently closes the eyes of dead Static soldiers (rare, optional interaction on specific props).
* **Grieving.** Beneath the fury is 4.5 billion years of loss. In Aubade (M21) the player sees the Unsung stop, remove a gauntlet and touch the statue of their shield-sibling.
* **Respects courage.** Nods to Vire. Bumps fists with Wren. Answers Tamsin's sign language with small, clumsy signs of their own — the only "conversation" the Unsung ever has.
* **Dark humor through deeds.** Puts a Static Collar on an Effigy in the hub. Turns up the volume on Harlan's broadcast when the Herald starts talking over the radio.

### Signature Gestures (first-person animations; used in cutscenes & hub)
| ID | Gesture | Use |
|---|---|---|
| `GST_Nod` | Short single nod | Acknowledging Vire, Lund |
| `GST_FistBump` | Fist bump | Wren (hub, after upgrades) |
| `GST_Sign_Thanks` | ASL-style "thank you" (flat hand from chin outward) | Tamsin, M27 epilogue |
| `GST_Sign_Ready` | Closed fist tapped twice on chest plate | Tamsin, before drops |
| `GST_Sign_Yes` | ASL-style "yes" (fist nodding at the wrist) — clumsy the first time, fluent by Act IV | Tamsin, post-M03 hub and after |
| `GST_Rack` | Racks the Breacher pump | Replacing dialogue replies |
| `GST_ScreenSmash` | Punches a monitor showing the Herald | M01 (Observation Dome), M07 (console) |
| `GST_HeartPress` | Presses hand to the Arrhythm cage | Emotional beats (M21, M27) |
| `GST_HelmetTouch` | Touches visor where a mouth would be | Hearing the Hymn for the first time (M01) |
| `GST_SwitchOff` | One deliberate finger on a switch; the sound dies | The original Signal reel (M09) |
| `GST_VolumeUp` | Turns a dial all the way up | Juno's collar (M14); Harlan's broadcast when the Herald cuts in (hub) |
| `GST_LidClose` | Gently closes a lid with one hand | Clara's music box (M24) |

### Visual Summary (full art spec in `17_Art_Direction.md`)
* Black-iron and gunmetal armor plates, heavily worn, rust at the edges, bone-white rivets.
* Helmet: tall, narrow, with a single vertical visor slit (ember glow) and a **speaker-grille jaw** — a dense iron mesh where a mouth would be. The grille glows orange during Overdrive.
* Chest: a ribcage-like iron cage over the **Arrhythm** (irregular ember pulse).
* Left forearm: the **Harrow** launcher — chain spool, barbed harpoon head.
* Back: two exhaust stacks that belch static-fire during Overdrive and Downbeat.
* Countless small trophies: a tuning fork snapped in half hanging from the belt, notched kill-tallies scratched into the right pauldron in alien script.

---

## 2. COMMANDER SOLENNE VIRE — Leader of the Static

| | |
|---|---|
| **Role** | Mission-giver, strategic voice, reluctant ally → true believer. |
| **Age / Look** | 52. Tall, broad-shouldered, shaved head with a long scar across the scalp, hearing-protection earplugs worn permanently under a Static headset. Black CDF officer's coat covered in hand-sewn band patches from her soldiers (each patch belongs to someone she lost). |
| **Voice** | Low, clipped, gravelly alto. Never raises her voice — never needs to. Dry, rare humor. Reference: veteran war-film commander. |
| **Background** | Former CDF colonel, commander of the 9th Orbital Brigade. Survived the Chorus Fall by ordering her men to blast their own music through their helmets — the first time anyone discovered noise protects against the Hymn. The Static formed around her. |
| **Arc** | Opens the game considering the Unsung a desperate gamble ("We opened the box. Now we find out what was in it."). By Act III she trusts the Unsung completely. In Act V she must decide whether to risk the entire surviving human population on the Last Broadcast. She does. She survives the game and leads the rebuilding. |
| **Relationship to the Unsung** | Soldier to soldier. She never asks for anything she wouldn't do herself. She is the first human to salute the Unsung (end of M04). |

**Sample lines**
* "Every soldier I have left is wearing a speaker on their neck and a prayer on their lips. You're what I've got instead of a miracle. Don't waste it."
* "The Choir wants us quiet. So we are going to be the loudest thing they have ever heard."
* (M14, as the Quietus is boarded) "All hands, all volume. Turn it up until your ears bleed. *Nobody* goes quiet on my ship."

---

## 3. DR. KASIMIR LUND — The Man Who Rang the Vault

| | |
|---|---|
| **Role** | Lore voice, guide (M01–M02 radio), scientist, tragic figure. |
| **Age / Look** | 67. Thin, stooped, white beard, round wire glasses, cardigan under a lab coat under a Static Collar. Hands tremble. Carries a battered tuning fork he taps nervously. |
| **Voice** | Soft, precise, slightly accented Scandinavian-West African English, a scholar's cadence. Speaks in full paragraphs; the Unsung routinely walks away mid-sentence. |
| **Background** | Studied the Silent Vault for 26 years. In 2194 his experiment made the Vault ring — the pulse that drew the Choir to Earth. He warned the Concord in 2202 (they laughed) and Aurelia (she didn't); aboard the Quietus, only Vire knows. The guilt is eating him alive. |
| **Arc** | Frees the Unsung (M01), guides them (M01–M03), becomes the Static's lore expert on the Quietus (researches the Choir, the Oreth glyphs, the Silencer). In **M09** Aurelia exposes his secret on an open broadcast; he confesses to the crew. In **M14** a Maestro abducts him from the Quietus. In **M19** the Unsung rescues him — half-tuned, gilded, able to *hear the Unison's thoughts*. He deciphers the path to Solace. In **M25** he becomes the living antenna for the Last Broadcast, carrying humanity's noise into the Harmonium. He dies at the end of M27, smiling, as the Unison shatters. His last words are to the Unsung: "Listen. That's... *everyone*." |
| **Relationship to the Unsung** | Awe, guilt, gratitude. He sees himself as both the Unsung's jailer-by-proxy and liberator. |

**Sample lines**
* "I spent twenty-six years trying to hear what was inside that box. It never occurred to me to ask whether it wanted to be heard."
* "The Choir isn't hate. Hate would be easier. It's *love* — with all the edges filed off."
* "Please don't punch that. It's the only spectrometer on the Moon. ...It *was* the only spectrometer on the Moon."

---

## 4. WREN CASTELLANOS — Chief Engineer & Armorer

| | |
|---|---|
| **Role** | Hub NPC: runs the Armory (weapon mods), builds the Silencer, comic relief, heart of the crew. |
| **Age / Look** | 24. Short, wiry, shaved sides and a long dyed-orange mohawk tied back, welding goggles on her forehead, grease everywhere, arms covered in hand-poked tattoos of band logos and waveforms. Oversized mechanic's jumpsuit with the sleeves tied at the waist. Custom Static Collar made from a guitar pedal. |
| **Voice** | Fast, loud, enthusiastic, profane. Talks over her own music. Quick-witted. Reference: excitable mechanic prodigy. |
| **Background** | Grew up in the Halcyon undercity, fixed amps for underground clubs, then fixed CDF tanks. Joined the Static at 23, the week it formed. Built most of the Static's Kick Pads and designed the Static Collar v3. |
| **Arc** | Treats the Unsung like the best project she's ever been given ("Oh, you are *gorgeous*. Who did your welds? Four billion years? Yeah, it shows.") Builds the Silencer with Lund. In M14 she defends the engine room. In Act VI she rigs the Quietus's entire hull as a speaker for the Last Broadcast. Survives. |

**Sample lines**
* "New mod's ready. It's loud, it's ugly, and it *probably* won't blow your arm off."
* "Rule one of the Static: if it doesn't go to eleven, I didn't build it."
* "They sing in *major keys*, man. That's how you know they're evil."

---

## 5. HARLAN "DEAD AIR" PRICE — Voice of Radio Free Static

| | |
|---|---|
| **Role** | Narrator of mission intros (radio segments), comic/emotional anchor, organizer of the Last Broadcast. |
| **Age / Look** | 61. Big, bearded, ponytail, tinted aviator glasses, headphones around his neck, Hawaiian shirt under body armor. Broadcasts from the top of the Halcyon Broadcast Tower surrounded by stacks of vinyl, reel-to-reel machines and jury-rigged transmitters. |
| **Voice** | Warm, deep, smoky late-night radio voice; theatrical; loves a turn of phrase. Can switch instantly to grave sincerity. Reference: legendary late-night DJ. |
| **Background** | Spent 30 years as a late-night rock DJ nicknamed "Dead Air" because he'd leave long, dramatic silences before dropping a track. The irony of his nickname in a war where silence kills is not lost on him ("I retired the silences, kid. Now it's all killer, no filler."). |
| **Arc** | Opens every mission with a radio segment (see `03b`). Has never met the Unsung; talks about them as a legend ("the Breaker"). Meets them in M05 when they save his tower. In M23 his tower is assaulted and he keeps broadcasting under fire. In M27 he orchestrates the **Last Broadcast** — every human voice on Earth at once. Survives. His final segment is the game's epilogue. |

**Sample lines**
* "Good evening, Earth. It's the end of the world and you're listening to Radio Free Static. Keep your collars on, keep your volume up, and keep your *hearts out of time*."
* "This next one goes out to the Choir. It's called 'No'."
* "Somewhere out there tonight the Breaker is making some very beautiful things very, very dead. God bless 'em."

---

## 6. TAMSIN HALE — Pilot of the Quietus

| | |
|---|---|
| **Role** | Quietus pilot and navigator; the only character the Unsung "talks" with. |
| **Age / Look** | 33. Dark-skinned, close-cropped hair with a shaved lightning-bolt pattern, flight jacket with Static patches, hearing aids *not* worn (she is culturally Deaf and prefers sign), Static Collar on her neck like everyone. Expressive and precise hands. |
| **Communication** | **Sign language only** (a signed language — animate using real, respectful ASL-like signs with a Deaf consultant; all her lines are subtitled with a distinct subtitle color and a hand icon). She lip-reads the crew and uses a tablet with text-to-speech in noisy situations. |
| **Background** | Ex-CDF dropship pilot, the best in the 9th Orbital Brigade. Deaf since birth. The Static's crew learned basic sign from her; Vire is fluent. |
| **Canon note** | Her deafness gives her **no** immunity to the Hymn (entrainment works through the whole body). She feels the Hymn as a pressure in her chest and hates it. |
| **Arc** | Notices that the Unsung watches her hands closely. In M03 (post-mission hub) she signs "Can you understand me?" and the Unsung — after a pause — signs a clumsy "Yes." They develop a quiet bond: she signs mission countdowns, the Unsung signs "ready". In M26 she rams the Quietus into the Clef to open a way in. Survives (injured). In the epilogue the Unsung signs "Thank you" to her. |

---

## 7. PRECENTOR AURELIA VOSS — The Herald (Primary Human Antagonist)

| | |
|---|---|
| **Role** | Human face of the enemy; recurring antagonist; boss (M24). |
| **Age / Look** | 58 but appears ageless. Tall, elegant, silver hair worn long. Pre-invasion: scientist's severe suits. Now: white and gold vestments with a projected halo-ring; the right half of her face and her right arm are gilded porcelain with gold seams glowing faintly. Her eyes are human, green, kind. |
| **Voice** | Serene, maternal, beautiful mezzo-soprano speaking voice, layered with a faint harmonized choir that grows stronger as she becomes more tuned. Never angry until M24. Reference: charismatic spiritual leader, gentle therapist. |
| **Background** | Brilliant astrophysicist, head of the Listening Array. Lost her husband and daughter in the Salt Riots of 2176 and never stopped grieving. When she decoded the Signal, she felt the pain lift for the first time in 20 years. She founded the Consonance to share the gift. She genuinely believes the Unison will end all human suffering, forever. |
| **Motivation** | Mercy. "Nine billion people in pain. I can make it stop. Tell me why I shouldn't." |
| **Arc** | Appears via broadcasts and holograms (M02, M04, M05). In **M07** the Unsung reaches her sanctum; she escapes, but reveals the Seven Voices and the Aureole's purpose. In **M09** she exposes Lund's secret — that the Choir came because the Vault rang — and tells the solar system: "They did not come for you, children. They came for *it*." In **M19** she speaks to the Unsung in the Chancel, offering to let them rest. In **M24**, she becomes **the Octave**, her body fully transfigured into a towering porcelain-and-light form, and is destroyed. In her final moment, the gilding cracks and she says, in her own unharmonized voice: "...It's so *loud*." Then, almost smiling: "I'd forgotten." |

**Sample lines**
* "I know you can't answer me. I don't think you've ever been *allowed* to. I'm offering you rest."
* "Do you know what the Hymn feels like? It feels like being forgiven."
* "You call it erasure. I call it the first time in history that no one will be alone."

---

## 8. LOCRIS (VEYL) — The Unresolved

| | |
|---|---|
| **Role** | Seventh Archon; the Unsung's shield-sibling from the Oreth era; tragic antagonist turned ally. |
| **Look** | An Oreth warrior-form 4 m tall, gilded but *cracked* — dark fissures run all over the porcelain, and the gold seams flicker irregularly, never settling. Wears the remains of an Oreth Shieldwarden's armor. Carries a broken shield grown into their left arm. Their halo is incomplete — a ring with a gap. |
| **Voice** | Two voices: the Choir's harmony, and underneath it a single, hoarse, lonely voice that occasionally breaks through. Androgynous. Uses **they/them**. |
| **Background** | Veyl stood beside the Unsung during the old wars. At the First Unison, Veyl hesitated, afraid — and then, seeing the Unsung left behind and alone, chose peace over grief. Veyl never fully resolved into the Unison. Across billions of years they have been the Choir's most brilliant and most troubled Archon. |
| **Arc** | Watches the Unsung throughout Acts III–IV (glimpsed in the distance in M12, M16, M18 — a cracked figure with a broken halo). In **M21** speaks to the Unsung in Aubade. In **M22** they fight — the fight is the Unresolved: reality in their domain keeps shifting. Defeated, Veyl chooses dissonance: they break their own halo and give the Unsung the **Key of the Unresolved**, which opens the way to the Clef. In **M26** Veyl reappears to hold the Clef's gate against the Choir so the Unsung can pass. Veyl's final line: "Go on. Be loud for both of us." |

---

## 9. THE UNISON — The Choir's God

| | |
|---|---|
| **Role** | Final antagonist (M27). |
| **Voice** | Billions of voices in perfect unison — rendered as a stack of ~30 voice layers of all ages and pitches speaking identical words in identical rhythm, with a sub-bass drone. Gentle, loving, infinitely patient. Never angry — until the Last Broadcast, when for the first time its voices *disagree*. |
| **Look** | See `10_Bosses.md`. A vast radiant sphere of fused, gilded bodies inside the Clef, with the Oreth "first face" at its center; halos within halos. |

**Sample lines**
* "Little Wrong Note. You have been screaming for so long. Aren't you tired?"
* "Every voice you have silenced is here with us, and none of them are in pain. Can you say the same of the ones you saved?"
* (as the Last Broadcast hits) "What— what is this? *So many.* They are all— *different*—"

---

## 10. SUPPORTING & MINOR CHARACTERS

| Character | Role | Notes |
|---|---|---|
| **Sergeant Bo Okafor** | Leader of the Halcyon Static cell (M05, M23). | Huge, cheerful, carries a Static machine gun with a boombox welded to it. Voice: booming bass. "Breaker! You are *exactly* as scary as advertised." |
| **Private Juno Reyes** | Young Static soldier found alive in a crashed dropship in M02; recurring voice on comms. | Nervous, brave. Dies in M14 defending the Quietus — her collar is later found; optional interaction. |
| **Choirmaster Idris Thale** | Consonance military commander; pilots **the Tenebrae** war-machine (mini-boss M07, M09). | Formerly a CDF general who defected. Contemptuous of the Static. Voice: cold, aristocratic baritone, half-harmonized. |
| **"Pops" Adebayo** | Quietus quartermaster (hub ambience, Listening Room). | 70s, ex-sound engineer, maintains the record collection. Tells stories about old bands (flavor lines when you place a Master on the turntable). |
| **The Archons** | Bosses. | Ionian, Dorian, Mixolydian, Phrygian, Aeolian, Lydian speak through the Choir in layered voices; each has a distinct vocal "color". See `10_Bosses.md`. |
| **Quietus crew (generic)** | Hub ambient life. | 20–30 NPCs: technicians, soldiers, medics, children of crew families (the Quietus is also a refuge). Ambient barks, reactions to the Unsung (fear → awe → affection as the game progresses). |

---

## 11. Voice Direction Rules

* Human characters swear naturally (M rating). The Choir never swears.
* **Harmonized voice processing** (Aurelia, Thale, Archons, Unison): dry human voice + 2–30 pitch-shifted layers (±3rd, ±5th, octave), subtle formant shift, long reverb tail; the more tuned the character, the more layers and the less of the dry voice.
* **Radio processing** (Harlan in the field, Vire/Lund on comms): band-limited 300–3.4k Hz, light distortion, occasional static crackles *timed to the music's rhythm*.
* The Unsung's effort sounds: low, restrained, masked by the helmet grille (slight metallic resonance).
