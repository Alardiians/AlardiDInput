# 03b — Cutscenes, Dialogue & Radio

## 0. Conventions

* **Cutscene IDs:** `CIN_Mxx_Name`. **Radio IDs:** `RAD_Mxx`. **Comms lines during play:** `COM_Mxx_nn`. **Barks:** `BRK_<Speaker>_<Context>_nn`.
* **Camera:** All cutscenes are **first-person** unless marked `[3P]`. 3rd-person shots are reserved for exactly four moments: M02 end (the Quietus landing, from outside), M21 (the Unsung at Veyl's statue), M24 end (Aurelia's death), M27 epilogue (the hull). This rarity makes them land.
* **Skippable:** all cutscenes, after first view on any save or immediately on replay. Hold-to-skip (1.0 s).
* **Implementation:** Level Sequences (`LS_CIN_Mxx_Name`). First-person cutscenes use the gameplay camera with animation-driven control (player input locked except look ±15° "soft look" where marked `[SOFT LOOK]`).
* **Speaker tags:** VIRE, LUND, WREN, HARLAN, TAMSIN (signed; subtitle in italics with ✋ icon), AURELIA, LOCRIS, UNISON, OKAFOR, JUNO, THALE, POPS, and Archons by name.
* **Radio intros** play over the mission loading screen and continue for up to 20 s into the mission's opening walk if unfinished. Exceptions: `RAD_M20` and `RAD_M26` play *after* their opening cutscenes (they describe those events), and `RAD_M27` plays live in the final boss's Phase 3. They are **never** mixed over combat music — if combat starts, the radio ducks to 20% and finishes under it or is cut.

---

## 1. CUTSCENE LIST

| ID | Mission | Length | Type | Summary |
|---|---|---|---|---|
| `CIN_M01_Awakening` | M01 | 75 s | FP | Silence → Vault cracks → chord → visor ignites → hears the Hymn |
| `CIN_M01_Aureole` | M01 end | 60 s | FP [SOFT LOOK] | Earth wearing the Aureole; Aurelia's broadcast; screen smash |
| `CIN_M02_Hologram` | M02 mid | 45 s | FP in-play (no lock) | Aurelia addresses the Unsung |
| `CIN_M02_Quietus` | M02 end | 70 s | 3P → FP | The Quietus lands; Vire meets the Unsung |
| `CIN_HUB_FirstTour` | Hub 1 | 50 s | FP | Wren meets the Unsung |
| `CIN_M03_Harp` | M03 start | 30 s | FP | Drop onto Apex Station, the ribbon singing |
| `CIN_M03_Fall` | M03 end | 55 s | FP | Climber car crash into the anchor platform |
| `CIN_HUB_Sign` | Hub after M03 | 25 s | FP | Tamsin: "Can you understand me?" |
| `CIN_M04_Ionian` | M04 boss intro | 40 s | FP | Ionian rises over the rapturous crowd |
| `CIN_M04_Waking` | M04 end | 60 s | FP | The crowd wakes; the first band dies; Vire's salute |
| `CIN_M05_Harlan` | M05 end | 70 s | FP | Harlan meets the Unsung; the lucky pedal |
| `CIN_M07_Aurelia` | M07 | 110 s | FP [SOFT LOOK] | Aurelia in person; the Seven Voices; she escapes |
| `CIN_M08_Dorian` | M08 boss intro | 45 s | FP | "Shieldwarden." |
| `CIN_M09_Exposed` | M09 mid | 60 s | FP in-play | Aurelia's broadcast: "They came for *it*." |
| `CIN_HUB_Confession` | Hub after M09 | 90 s | FP | Lund confesses |
| `CIN_M11_Anvil` | M11 start | 30 s | FP | Boarding the Anvil Siege Frame |
| `CIN_M13_Phrygian` | M13 boss intro | 45 s | FP | "Sing it *with* us." |
| `CIN_M13_Distress` | M13 end | 30 s | FP | The Quietus goes silent |
| `CIN_M14_Abduction` | M14 end | 75 s | FP | Maestro Primus takes Lund; the Mute Engine restarts |
| `CIN_M16_Aeolian` | M16 boss intro | 40 s | FP | "I am only trying to make the ending gentle." |
| `CIN_M17_InsideOut` | M17 end | 40 s | FP | The sky turns inside out |
| `CIN_M18_Memory` | M18 mid | 12 s | FP (in-play freeze) | Memory flash: the stone city, the shield |
| `CIN_M19_Vision` | M19 mid | 60 s | FP (gold-rendered) | The First Unison; the lone screaming figure |
| `CIN_M19_Lund` | M19 | 55 s | FP | Lund in the Tuning Font: "You were *born* there." |
| `CIN_M20_Crossing` | M20 start | 45 s | FP | The Quietus enters the Harmonium |
| `CIN_M21_Statue` | M21 | 50 s | 3P | The Unsung touches Veyl's hand |
| `CIN_M21_Axe` | M21 | 40 s | FP | The Axe screams; statues crack |
| `CIN_M21_Locris` | M21 end | 35 s | FP | "Hello, Shieldwarden." |
| `CIN_M22_Halo` | M22 end | 90 s | FP | Locris breaks their halo; the Octave begins |
| `CIN_M24_Octave` | M24 boss intro | 50 s | FP | Aurelia transfigures |
| `CIN_M24_Death` | M24 end | 90 s | 3P → FP | "It's so *loud*." The Aureole shatters; the stars hum |
| `CIN_HUB_LastPlan` | Hub before M25 | 120 s | FP | The Last Broadcast plan |
| `CIN_M26_Ram` | M26 | 40 s | FP | Tamsin rams the Clef |
| `CIN_M26_Veyl` | M26 | 35 s | FP | "Be loud for both of us." |
| `CIN_M27_Unison` | M27 intro | 60 s | FP | The Unison speaks |
| `CIN_M27_Broadcast` | M27 P3 start | 45 s | FP in-play | The Last Broadcast arrives |
| `CIN_M27_Finale` | M27 end | 90 s | FP | The Unison shatters; Lund's death |
| `CIN_EPILOGUE` | End | 180 s | Mixed | Earth, the Quiet, Harlan's silence, the hull, "Thank you" |
| `CIN_POSTCREDITS` | After credits | 30 s | 3P | Another choir begins; the visor ignites |

Total ≈ 34 minutes including epilogue; ≈ 22 minutes of mandatory, non-interactive time. (In-play scenes don't count toward the budget.)

---

## 2. KEY CUTSCENE SCRIPTS

### CIN_M01_Awakening
```
[BLACK. TOTAL SILENCE — 6.0 s. No music, no room tone.]
CAPTION (fade in/out, 3 s): TRANQUILITY DEEP
                             CONCORD XENOACOUSTIC RESEARCH SITE
                             LUNAR SUBSURFACE — 11 JUNE 2204

LUND (muffled, as if through meters of cotton):
   ...I don't know what you are. I've spent twenty-six years not knowing.
   (a breath)
   But they're afraid of you. And that's all I have left.

[A thin ultrasonic whine rises. Hairline cracks of white light appear across
 the black — the camera is INSIDE the Vault material, like being embedded in obsidian.]

LUND: Forgive me.

[CRACK. The black shatters outward like glass in slow motion. Light floods in.]
[ONE massive, down-tuned guitar chord (Drop A power chord, huge room reverb).]
[The HUD ignites piece by piece in ember orange — visor boot-up effect.]
[The Unsung is lying on a black slab. Camera sits up.]

[Faint and far away: the HYMN — a soft, perfect choral chord. Beautiful.]
[Camera looks down at its own gauntlets. Right hand rises and touches the visor
 where a mouth would be — GST_HelmetTouch. Hold 1.5 s.]
[The hand slowly clenches into a fist. Servo creak. The Arrhythm's pulse
 on the chest cage: irregular — thump... thump-thump... ...thump.]

[Two TUNED RESEARCHERS stagger through the containment doorway, heads tilted
 back, singing in harmony. They see the Unsung. Their song stops. Silence.]
[Both scream in unison and lunge.]
[CONTROL TO PLAYER. Tutorial prompt: MELEE.]
```

### CIN_M01_Aureole
```
[Observation Dome. Lunar surface visible. The lift doors open.]
[SOFT LOOK enabled. Player walks forward automatically at 50% speed toward the glass.]
[EARTH hangs in the black sky — and around it, a vast ring of light: pale gold, steel
 white, brass, white-orange, sea cyan, lilac, cracked grey — seven bands, incomplete
 on one side. THE AUREOLE.]
[The Hymn is louder here. Every monitor in the dome flickers on at once.]

AURELIA (on every screen, gentle):
   Children of Earth. Do not be afraid.
   I know it hurts. I know you're tired. I was tired too.
   The pain is almost over.

[The Unsung turns to the nearest monitor. Aurelia's serene face fills it.]
[GST_ScreenSmash. Glass, sparks. The other screens keep talking.]

LUND (radio, quiet):
   That's the Aureole. It's been growing for six months.
   When it closes... there won't be anyone left to hear it.
   (beat)
   There's a ship coming. The Static. They're... well. They're what's left.
   They'll want to meet you. I'm afraid I told them you might be on our side.

[FADE TO MISSION COMPLETE.]
```

### CIN_M02_Quietus  `[3P → FP]`
```
[3P: wide shot of the ruined Selene Relay, dust drifting in low gravity.
 The Unsung stands small on a crater rim.]
[From above: a SHADOW. The QUIETUS descends — 400 m of black brutalist hull,
 jagged with anechoic wedge-plating, no running lights, landing in total silence.
 Even the dust falls silently around it.]
[Cut to FP. A ramp lowers. Red interior light. Static soldiers with rifles
 raised — nervous. Speakers on their shoulders blasting muffled metal.]
[The Unsung walks up the ramp. The soldiers part.]
[At the top: VIRE. She has to look up. Long pause.]

VIRE: Lund says you're four billion years old.
      (beat)
      You don't look a day over three.
      (beat; no reaction)
      Tough crowd.
      (she steps aside)
      We opened the box. Now I guess we find out what was in it.
      Welcome to the Quietus.

[TAMSIN in the cockpit window above, signs (subtitled): "Ramp's up. Hold on to something."]
[The ramp closes. Silence — a *different* silence: warm, human, safe.]
[HUB UNLOCKED.]
```

### CIN_M07_Aurelia `[SOFT LOOK]`
```
[The Precentor's sanctum: a circular white chamber, reflecting pool, a single
 gold ring-gate humming behind a dais. AURELIA stands barefoot in the pool,
 half her face gilded, eyes human and kind. She doesn't run.]

AURELIA: You came all this way. Please — I'm not going to fight you.
         I don't think I could.
         (she steps closer; water ripples in perfect rings)
         Do you know how many voices there are in the Choir? Nobody does.
         Trillions. Whole worlds. And not one of them is afraid, or grieving,
         or alone.
         (beat)
         Eight voices hold the Aureole. Seven are ancient — older than
         your sun. The eighth—
         (she touches her gilded cheek)
         —is me. The Octave. When the chord is complete, humanity joins them.
         Every mother who ever lost a child. Every soldier. Every child.
         Nobody will ever be lonely again.

[The Unsung raises the Breacher. Pump rack (GST_Rack).]

AURELIA (sadly): I know. I know you can't answer me.
                 I don't think you've ever been *allowed* to.
                 When you're ready to rest... I'll be listening.

[She steps backward into the ring-gate and is gone in a ripple of gold.]
[Zealots pour in through side doors. CONTROL TO PLAYER.]
```

### CIN_HUB_Confession
```
[Quietus bridge. The crew is gathered. LUND stands by the window. The Aureole
 behind him — two bands dark. Everyone has heard the broadcast.]

LUND: It's true.
      Twenty-six years I studied it. Ten years ago... I rang it.
      I wanted to hear what was inside. For point-eight seconds, I did.
      (beat)
      Heartbeat. Irregular. *Beautiful.* I played it back a thousand times.
      Seventeen months later, the Signal came from the same direction.
      I told the Concord. They laughed. I told Aurelia. She didn't.
      (he turns to the Unsung)
      They came because they heard *you*. And they heard you because of *me*.

[Long silence. A Static soldier looks at the floor. Wren's music is off — for once.]

VIRE: You done?
LUND: ...Yes.
VIRE: Good. Here's how it goes. It doesn't matter why they came.
      It matters that they *leave*.
      (to the room)
      Anybody got a problem with that, take it up with the four-billion-year-old
      war god standing behind me.

[The Unsung steps forward and places a hand on Lund's shoulder. GST_Nod.]
[Lund breaks down, quietly. Wren turns her music back on — softly.]
```

### CIN_M14_Abduction
```
[The Mute Engine chamber: a vast black sphere of anechoic wedges, cracked open.
 The Unsung has just thrown the last breaker. Engine spin-up hum rising.]
[Across the chamber, on a gantry: MAESTRO PRIMUS — 4 m, robed in sheet-music
 skin, a baton of bone. It holds LUND by the collar like a doll.]

LUND (struggling): Don't— don't you dare come after me! Finish it! FINISH—

[Maestro Primus raises the baton. A ring-gate opens behind it.]
[The Unsung sprints. Harrow fires — the chain strikes the closing gate
 and rebounds in a shower of gold sparks. Too late. They're gone.]
[The Mute Engine reaches full spin. A DEEP WHUMP — all sound in the ship
 drops out. Every Choir-form aboard freezes mid-motion, cracks, and crumbles
 into porcelain dust. Silence.]

VIRE (radio, wounded, breathing hard): ...Breaker.
      (beat)
      Find him.
```

### CIN_M19_Vision  (rendered in gold monochrome)
```
[The Unsung touches a choir-wall. The world turns to gold light.]
[A city of pale stone towers shaped like flutes and horns. Wind moving through
 them makes music. AUBADE, four and a half billion years ago.]
[Billions of tall, slender Oreth fill every plaza, every rooftop — singing
 together. Their bodies begin to gild. It is beautiful. It is peaceful.]
[Camera finds one small square. A single armored Oreth stands alone, the only
 one not singing, staring at another Oreth with a shield (VEYL) who is
 turning gold, reaching out toward them.]
[The armored one clutches their chest. Their heart — visible as ember light —
 stutters out of rhythm.]
[They SCREAM. The gold image CRACKS.]

AURELIA (V.O., gentle): That was you. All alone. For so long.
                        You don't have to be anymore.

[Snap back to reality. The Unsung is on one knee. The player regains control
 after 1.0 s. The Arrhythm pulses wildly on the HUD.]
```

### CIN_M22_Halo
```
[LOCRIS kneels in the rubble of the Unresolved, cracks spreading across their
 porcelain. Their broken halo flickers — a ring with a gap.]

LOCRIS: You were always so *loud*.
        When they sang, I stood beside you and I thought — if I go,
        you will be alone forever. And I went anyway.
        Because I was afraid of hurting.
        (beat)
        Four billion years, and I never stopped hurting. Not really.
        Unresolved. That's what they call me. They're right.

[Locris grips the halo with both hands.]

LOCRIS: Let me resolve it now.

[CRACK. The halo shatters. The Choir's harmony drains out of their voice,
 leaving one hoarse, lonely voice.]

LOCRIS: ...It's so quiet.
        I'd forgotten what my own voice sounded like.
        (they press a glowing, jagged glyph-shard into the Unsung's gauntlet)
        The Key of the Unresolved. It opens the Clef. They built it to keep
        *us* out. Doubters. Wrong notes.
        (beat) Go on. I'll be—

[The sky over Aubade flares WHITE. A piercing, perfect note, rising.]

VIRE (radio, distorted): Breaker! Something's happening on Earth — the Aureole
      is — it's *closing*. Voss is singing it herself. Get back here. NOW.
```

### CIN_M24_Death `[3P → FP]`
```
[3P: The Octave's colossal porcelain form collapses in slow motion, fracturing
 into falling slabs of light. In the heart of the wreckage, a small figure:
 AURELIA — human-sized again, lying in rubble. Gilding cracks off her face in flakes.]
[FP: the Unsung approaches and stands over her. She opens her eyes.]

AURELIA (her own voice — no harmony, hoarse, human):
   ...Oh.
   (she listens — the battle outside, Harlan's radio somewhere, wind, screaming,
    music, the Unsung's irregular heartbeat)
   It's so *loud*.
   (a weak, almost-smile)
   I'd forgotten.

[She dies. A flake of gold drifts from her cheek.]
[Through the Cathedral's shattered roof: the Aureole SHATTERS — a planetary ring
 of light breaking into billions of pieces, falling across Earth like snow.]
[On every channel: cheering, crying, horns, gunfire into the air.]
[Then, slowly, under the cheering: a faint, pure hum. The camera looks up.
 Every star in the sky is humming.]

LUND (radio, weak, from the med-bay): No... no, no, no.
      It's not stopping. The chord was never *theirs* to finish.
      It's *coming*.
```

### CIN_HUB_LastPlan
```
[Quietus bridge. Everyone. LUND in a wheelchair, half-gilded, golden tears dried
 on his cheeks. HARLAN on the big screen from his tower.]

LUND: The Unison can't be out-sung. It's every voice it's ever taken. Trillions.
      But it has never heard two voices at once. Not in four billion years.
      It doesn't know what *disagreement* sounds like.
HARLAN: So we give it all of 'em.
VIRE: Explain it to the room.
HARLAN: Every radio, every phone, every speaker still working on Earth.
        Five billion people. At the same moment, we tell 'em: make noise.
        Sing. Scream. Bang pots. Play your kid's recorder. Cuss out the sky.
        Whatever you've got, as loud as you've got it. Everybody different.
        Radio Free Static carries it. The Last Broadcast.
WREN: And I turn the whole ship into a speaker.
      (beat) I have *always* wanted to say that.
LUND: And I carry it into the Harmonium. I'm half theirs now — I can speak
      in their key. If someone gets me to the heart of the Unison...
VIRE: It'll kill you.
LUND: (smiles) Yes. I rang the bell, Solenne. Let me be the one to answer it.

[Silence. Vire looks at the Unsung. The Unsung nods.]

VIRE (keying ship-wide comms): All hands. This is the Commander.
      Everyone who can hear this — get loud.
```

### CIN_M27_Finale
```
[The Unison's heart: a sphere of light, fracturing into warring factions of
 voices. The Unsung — in Last Overdrive, exhaust stacks roaring — drives the
 AXE into the core. The Axe SCREAMS.]
[WHITE OUT. Then: billions of sparks of light burst outward in every direction,
 each one singing its own, different note. A cacophony of freedom.]
[The sparks drift past the camera — some pause, briefly, near the Unsung,
 as if looking. One lingers longer than the others. Then goes.]
[Silence falls — the real kind.]
[LUND, on his stretcher-drone nearby, gilding flaking away, dying.]

LUND: Listen.
      (the sparks' fading, overlapping songs)
      That's... *everyone*.

[He dies smiling. The Unsung kneels beside him and presses a hand to their own
 chest (GST_HeartPress).]
```

### CIN_EPILOGUE (summary; full shot list in `14_Missions/M27_The_Final_Chord.md`)
1. Halcyon at dawn: Aureole remnants falling like snow; people tearing off their collars and *laughing*.
2. A hospital hall of the Quiet: long-tuned people sitting peacefully, still; families beside them.
3. The Quietus towed home, a jagged scar where it rammed the Clef.
4. Harlan's tower. "...So I'm going to do something I haven't done in a long, long time." **[6.0 s of silence.]** "...Yeah. That's the good kind."
5. `[3P]` The Quietus hull. Tamsin sits beside the Unsung. Earth below. She signs: *"What will you do now?"* The Unsung looks at their hands. Signs, carefully: **"Thank you."** She laughs silently and leans her shoulder against their armor.
6. Credits over the main theme, rearranged for a single acoustic guitar — and then a crowd of human voices singing it, badly and gloriously.

---

## 3. RADIO FREE STATIC — MISSION INTROS (`RAD_Mxx`)

Harlan "Dead Air" Price opens each mission. Delivery: warm, theatrical late-night DJ; 45–75 seconds; ends by introducing a **track** that becomes the mission's exploration music (track names in `18_Audio_and_Dynamic_Music.md`). M01 has no radio intro (the game opens in silence). Radio intros are also collectible in the Listening Room.

**RAD_M02 — Selene Relay** *(Harlan doesn't know about the Unsung yet)*
> "...this is Radio Free Static, broadcasting from somewhere you'll never find, on every frequency the Choir hasn't eaten yet. It's 0300 in Halcyon, the sky's still wearing that ugly crown, and I'm still talking. Rumor on the wire tonight: something happened on the Moon. Tranquility Deep went dark six hours ago, and then — get this — the Selene Relay started *stuttering*. Hiccuping. Like it heard something it didn't like. I don't know what's up there, friends. But if you're listening... keep it up. This one's for whoever is making the Moon nervous."

**RAD_M03 — The Meridian Tether**
> "Radio Free Static, still here, still loud. Big news, folks: the Selene Relay is *gone*. Dust. Rubble. And the Static's big black ship picked up a passenger — the soldiers are calling it 'the Breaker'. Seven feet of iron and bad attitude. Now, I've been around. I've heard every rumor. But I talked to a kid named Reyes who saw it pull a man-sized choir-thing apart like a Christmas cracker, and she wasn't lying. So here's to the Breaker. And to the Tether — which, word is, the Choir's been playing like a harp. Somebody go pull that string out. Here's something with strings you'll actually like."

**RAD_M04 — Rapture**
> "Good evening, Halcyon. Look up. For the first time in months, the Hymn over the city *flickered*. Something came down the Tether last night and landed hard in the harbor. I have a feeling it's heading for the Bowl. Now, I've got friends in that stadium. Friends who went to the Communion 'just to see'. They've been standing there three weeks, smiling. If there's anyone left in there who can hear me — hold on. Help's coming, and it's *really* loud. Sergeant Okafor, if you're out on the highways: give 'em noise, big man."

**RAD_M05 — Radio Free Static**
> "Well, folks, this is awkward. The Choir's figured out where I am. Big pillars of light, lots of singing, very pretty, coming right for my tower. I've got four speakers, one shotgun, and six hundred records, and I'm not going anywhere. You know why? Because if this station goes quiet, a whole lot of you go quiet too. So I'm going to keep playing until they pull the plug out of my cold, dead hands. Breaker — if you can hear me — I'd *love* some company. This one's called 'Come and Get It'."

**RAD_M06 — Fort Obdurate**
> "Still alive! Thanks to a certain someone. I have seen things, friends. I have seen a walking pipe organ get turned into *confetti*. Now: Fort Obdurate. The Concord's mountain fortress. Went quiet in the first week of the Fall, and now something with a *very* big army is sitting on it. Old soldiers say Obdurate had everything in its vaults — guns, mechs, secrets. If the Breaker's going in there, I hope they bring back souvenirs. Here's a little mountain music for the climb."

**RAD_M07 — Mount Canticle**
> "Let's talk about the Consonance. I used to have Consonance folks call in to the show. Nice people. Worried people. They'd say, 'Harlan, doesn't the Signal make you feel *peaceful*?' And I'd say, 'Nothing makes me feel peaceful, that's why I play *this*.' Now they're up on their pretty mountain with their pretty robes, singing the rest of us into the ground. And the Breaker's paying 'em a visit. I'm not saying I'm happy about what's gonna happen up there. I'm saying I'm not *sad*. Here's 'Sermon for the Deaf'."

**RAD_M08 — The Iron Psalm**
> "They marched the whole Third Army into a field and sang them into statues, folks. Two hundred thousand soldiers. Every one of 'em somebody's kid. Now there's a fortress out on the plains made of their bones, and something called Dorian drilling them like toy soldiers. I don't have a joke for this one. I've just got a request line, and a request came in from a woman whose son was in the Third. She said: 'Tell the Breaker to make it quick.' Breaker... make it quick. Here's 'Two Hundred Thousand'."

**RAD_M09 — The Listening Array**
> "The Listening Array. Where it all started. Sixty dishes in the desert, pointed at the sky, waiting for somebody to call. And somebody did. I remember the night they played the Signal on the news. My neighbor cried. I didn't — I turned it off, because it sounded like an *ad*. Too pretty. Nothing real is that pretty. The Static's brainiacs think those old recordings can help them build something. Something big. Something *quiet*, which, frankly, makes me nervous. Here's something noisy to balance it out."

**RAD_M10 — The Forge-Belt** *(after Aurelia's revelation)*
> "Let's address the elephant on every frequency. You all heard the Precentor. The Choir came because of the Breaker. Because of a scientist on the Moon. And a lot of you called in angry. I get it. Here's what I think. My house got broken into once. The burglar said he came in because my window was open. I did not apologize to the burglar. Now: the Forge-Belt. Where half the world's steel used to come from. Now it builds *them*. Let's go shut down the factory. This one's got a lot of hammers in it."

**RAD_M11 — The Assembly**
> "Reports from the Forge-Belt say the Breaker has stolen — sorry, *liberated* — a Concord Anvil Siege Frame. Nine meters of armor. For those of you too young to remember, the Anvil was the Concord's pride and joy. Cost more than this whole city. And the Static's engineer, a young woman who I'm told has a very large wrench, has put it back together with tape and spite. Folks, that is the most Static thing I have ever heard. Here's 'Big Iron'."

**RAD_M12 — Helios Station**
> "I have a question for the science people listening. Can the Sun *sing*? Because the Static says the Choir is trying to teach it. And if the Sun starts singing their song... well, you can't wear a collar big enough for the Sun. So the Breaker's going to Mercury. The hottest, brightest, least hospitable rock in the system. Wear sunscreen, Breaker. Here's something to keep you cool."

**RAD_M13 — Corona**
> "The stars are looking weird tonight, folks. Well, one star. Ours. There's a *tone* in the morning light now — you can hear it if you stand in a quiet room. So don't stand in a quiet room. The Breaker's out on the mirror fields on Mercury, heading for the thing doing this. I'm told it's made of fire. I'm told it *likes* the Breaker. Buddy, get in line. Here's a love song. Sort of."

**RAD_M14 — Dead Air** *(broadcast is interrupted)*
> "Radio Free Static, with a... hang on. I'm getting reports the Static's ship has gone off the air. The Quietus. No signal, no response. That ship's the reason half of us are still— hold on. I'm going to keep this frequency open. If anyone on the Quietus can hear me... we're here. We're loud. Come back to us. *[He doesn't introduce a track. He just leaves the channel open. Static, faint music, and his breathing.]*"

**RAD_M15 — Cryobore**
> "The Quietus is back on the air, folks. Bloodied, but loud. They lost people. One of them was Juno Reyes — you remember, the kid from the Moon who told me about the Breaker? She was nineteen. This one's for Juno. And for Doc Lund, wherever they took him. The Breaker's heading out to Europa, one of Jupiter's moons. Twenty kilometers of ice and an ocean underneath that nobody's ever seen. Something down there is singing to the water. Here's 'For Juno'."

**RAD_M16 — The Singing Sea**
> "Did you know whales used to sing? Back when there were whales. Long, sad songs you could hear across a whole ocean. There's something under Europa's ice singing like that. The Static says it's grieving. I say it can grieve somewhere else. Breaker, I've never been under the sea, and you're going to fight a god down there. I hope your suit's waterproof. Here's one about drowning — the good kind, in noise."

**RAD_M17 — Cytherea**
> "Cytherea. The city in the clouds of Venus. I went there once for my honeymoon. Gardens in the sky, balconies over a sea of yellow cloud, the most beautiful place I've ever been. My wife said it felt like a dream. Well... now it is one. The Static says something called Lydian has pulled the whole city into its sleep. Half a million people up there, dreaming whatever the Choir wants them to dream. Wake 'em up, Breaker. Here's an alarm clock."

**RAD_M18 — The Dreaming Choir**
> "No broadcast can reach inside a dream. So this one's for the rest of you. The Breaker's gone somewhere my radio can't follow. And I just want to say, to that big silent iron thing that's been saving our lives — whatever you're seeing in there, whatever it's showing you — it isn't real. *We're* real. We're right here. Waiting for you. Loud as ever. Here's the loudest thing I own."

**RAD_M19 — The Chancel**
> "They've found where they took Lund. It's a place called the Chancel, up in orbit, where they take people to be... tuned. Folks, I'm not going to describe it. I'm going to play you a song instead. It was the doc's favorite, according to his crew. He'd hum it in the lab. Off-key, apparently. Doc, if you can hear this: stay off-key. Stay *wrong*. We're coming."

**RAD_M20 — The Nave** *(plays after `CIN_M20_Crossing`, over the A01 walk — not at load)*
> "You're not gonna believe this. The Quietus just jumped *into* the Choir's home. Their dimension. The Harmonium. My signal can't reach them there, but I'm going to broadcast anyway, because I'm stubborn and because I have a feeling they can *hear* it somehow. Breaker: you're in their house now. Wipe your feet. Break everything."

**RAD_M21 — Aubade** *(signal barely reaches; heavy interference)*
> "...can you hear... this is Harlan... Radio Free Static... they say you went somewhere... old. Somewhere... *home*? I don't know what that means for you, big guy. But... wherever home was... you've got one here, too. Loud one. ...signal's going... I'll leave the light on."

**RAD_M22 — The Unresolved**
> *(No voice. Only a faint, intermittent carrier tone and 10 seconds of a single guitar playing the main theme, far away, as if heard through a wall. It is Harlan's signal, reaching the Harmonium only as music.)*

**RAD_M23 — Aureole**
> "EVERYBODY WAKE UP. The Aureole is closing. You can feel it in your teeth. Collars are overheating all over the planet. Voss is up there in her big white cathedral singing the last note herself. And the Breaker — the Breaker is *back*. Came back from the Choir's own house to finish this. So listen to me: turn your collars all the way up. Turn your *radios* all the way up. Scream if you have to. We hold on for one more day. Here's 'One More Day'."

**RAD_M24 — The Octave**
> "I knew Aurelia Voss. Did you know that? Years ago. She came on my old show to talk about the Signal. Brilliant woman. Kind. So sad you could feel it through the microphone. She told me, off air, that she hadn't slept a full night since her daughter died. And I think... I think all of this is just her trying to get one good night's sleep. I'm sorry, Aurelia. It can't be *everybody's* sleep. Breaker — end it. Gently if you can. But end it."

**RAD_M25 — The Staves**
> "This is Radio Free Static, and this is the most important thing I will ever say on the air. In a few hours, I'm going to ask every one of you to do something. When I give the word — you make noise. Everybody. The whole planet. Sing, shout, drum, cry, curse, play whatever you've got. Don't sing *together*. Sing *different*. That's the whole trick. That's the weapon. The Breaker's out there carrying Doc Lund to the heart of the Unison, and we're going to give 'em something to deliver. Rehearsal's now. Warm up those throats."

**RAD_M26 — The Clef** *(plays after `CIN_M26_Ram`, over the A01 walk — not at load)*
> "...Tamsin Hale just flew a four-hundred-meter ship into the side of the Unison's house. On purpose. I've been told she's fine, she's grinning, and she'd like everyone to know she 'nailed the landing'. The Breaker's inside. Everyone stay near your radios. It's almost time. This one's called 'Almost Time', because I'm out of clever ideas and so are you."

**RAD_M27 — The Final Chord**
> "This is Radio Free Static. This is the Last Broadcast. Five billion of you are listening right now. I can hear you breathing. When I count to three, I want every one of you to make the loudest, ugliest, most *you* sound you have ever made. Not a song. Not together. *Yours.* For everyone they took. For everyone who's still here. For Juno. For the Doc. For the Breaker, who never asked for any of this.
> One.
> Two.
> ...*Make it loud.*"
*(This intro does NOT play at mission load. It plays live at the start of the Unison's Phase 3 — `CIN_M27_Broadcast`. The M27 load screen is silent except for the Arrhythm heartbeat.)*

---

## 4. IN-PLAY COMMS (examples & rules)

Rules:
* Max **one** comms line every **20 s** during exploration, **none** during combat except critical lines (≤ 4 words, e.g. "Heavy incoming!").
* If the player walks away from a speaker or starts combat, comms **pause** and resume at the next sentence boundary, or are abandoned if no longer relevant.
* Each mission file lists its `COM_Mxx_nn` lines. Examples:

| ID | Speaker | Trigger | Line |
|---|---|---|---|
| COM_M01_03 | LUND | First Harrow Shred | "Did you just— the *ammunition* came out of— never mind. I've decided not to understand you." |
| COM_M01_07 | LUND | Player walks away mid-exposition | "...and you're already gone. Right. I'll just— I'll talk to myself. As usual." |
| COM_M02_05 | VIRE | First Relay core destroyed | "One down. Lund, your monster works." — LUND: "*Our* monster." — VIRE: "Mm." |
| COM_M03_04 | WREN | Overdrive first unlocked | "Whoa — what did your suit just *do*? My meters just clipped! Do it again! Wait— not near the ship!" |
| COM_M05_09 | HARLAN | Player enters Broadcast Tower | "I can *hear* you coming up the stairs, and friends, it sounds *wonderful*." |
| COM_M10_02 | WREN | Lance pickup | "Oh, that's a Concord rail-lance. Those things punch through tanks. Please punch through something big." |
| COM_M14_12 | VIRE | Low crew count | "Every speaker on! Rip the music out of the walls if you have to! *Nobody goes quiet!*" |
| COM_M21_01 | — | Arrival in Aubade | *(No comms. The signal can't reach. This is deliberate. The silence should be noticed.)* |

---

## 5. BARKS

### 5.1 Static Soldiers (allied NPCs in combat & hub)
| Context | Examples (pick randomly, no repeats within 60 s) |
|---|---|
| Unsung arrives | "Breaker's here!" / "Oh thank God, it's the big one." / "Make some room, it's the Breaker!" |
| Unsung kills a heavy | "Did you SEE that?!" / "Ha! Scrap metal!" / "That's how it's done!" |
| Collar warning | "My collar's running hot!" / "Turn it up, turn it UP!" / "I can hear them — I can hear them singing—" |
| Hub (early game, nervous) | "...Don't make eye contact." / "Is it true it doesn't sleep?" |
| Hub (late game, affectionate) | "Morning, Breaker." / "Hey — thanks. For the Moon. And everything." / "Kids made you a drawing. It's on the mess wall." |

### 5.2 Aurelia Voss (broadcast taunts during Act I–V missions; max 1 per mission section)
* "Every one of them you break was someone's child once. Now they're no one's. Is that better?"
* "I can hear your heart from here. It sounds like it's breaking. It's been breaking for a very long time."
* "The Static tell their children that noise will save them. Noise has never saved anyone. It just keeps them from hearing how tired they are."
* *(M10+ only — after the M09 reveal)* "Kasimir, if you're listening — I'm not angry. I'm grateful. You rang the bell."

### 5.3 The Choir (non-verbal) — vocal signature table
Every Choir enemy has a **signature chord** (its "voice"). Its idle hum, alert call, attack wind-up and death sound are variations of it. Players learn to identify threats by ear. (Full spec in `18_Audio_and_Dynamic_Music.md`.)

| Enemy | Signature | Alert | Attack tell | Death |
|---|---|---|---|---|
| Thrall | Off-key hum, unison | Breathy rising "ahh" | Choking inhale before lunge | Cracking + wet gasp, chord cut off |
| Chorister | High soprano "ah" | Two-note call | Rising glissando (gold note = higher, longer) | Shattering porcelain + note snaps |
| Crescendo | Deep grinding drone | Bellow that grows | Volume swell over 1.2 s | Collapsing organ-chord |
| Canon | Brass bell tones | Double bell toll | Two bell tolls = volley | Bells crack, discordant |
| Cantor | Tenor chant | Chant phrase | Sustained note while linking | Lantern shatters with a ringing tone |
| Maestro | Full choir + baton whoosh | Choir swell | Baton "tap-tap" before summon | Entire choir ends on an unresolved chord |
| Requiem Knight | Low male choir, solemn | Sword ring | Gold flash + bell chime | Sword rings out long |
| Carillon | Many bells | Carillon peal | Bells ring in sequence before barrage | Bells fall and crash |

### 5.4 Hub Barks (Wren, on upgrades)
* "Ooh, you're gonna *love* this one."
* "Mastered it? Show-off. I love it."
* "That's the last mod for this beauty. She's done. She's *perfect*. Don't break her."
* (idle) "You ever think about getting a hobby? No? Just murder? Cool, cool."
