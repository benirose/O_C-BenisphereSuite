---
layout: default
---
# MIDI Input

## Video
[![MIDI Mapping Video Demo](http://img.youtube.com/vi/SpgH4tNvikc/0.jpg)](http://www.youtube.com/watch?v=SpgH4tNvikc "MIDI Input Mapping")

## Advanced MIDI-to-CV For Hemisphere
![Screenshot 2024-06-13 15-11-54](https://github.com/djphazer/O_C-Phazerville/assets/109086194/514ddea9-59e6-43e4-9880-857e4a729da2)

Phazerville greatly expands on the capabilities of the original [**MIDI In** applet](https://github.com/Chysn/O_C-HemisphereSuite/wiki/MIDI-In). MIDI messages coming in via USB are parsed and handled at a high level; the applet acts as a configuration UI, and also passes signals to the outputs.

If you switch to a different applet, the configured incoming MIDI messages are rerouted to the _inputs_ of the selected applet and are _combined with the physical CV or trigger input_. This allows things like modulating parameters via MIDI CC or Pitch Bend, quantizing MIDI Notes to a scale, or triggering sequencer applets with MIDI Note-On. You can use **AttenOff** to scale and offset MIDI CC values. You can transpose **TB-3PO** patterns via MIDI Note and modulate Density with the Velocity, or Aftertouch, etc.

MIDI _Clock_, _Start_, and _Stop_ messages are also handled automatically by the internal **[Clock Setup](https://github.com/djphazer/O_C-Phazerville/wiki/Clock-Setup)** applet. Incoming MIDI Clock is divided from 24 PPQN to 2 PPQN internally.

### Channel Settings

By default, all channels are set to "None". A pair of the MIDI In applets can be [saved as a Preset](https://github.com/djphazer/O_C-Phazerville/wiki/Hemisphere-Config) to quickly recall settings.

Each channel filters and translates incoming MIDI messages as output CV from **MIDI In** applet, or to a corresponding logical input for other applets.
- **MIDI Channel** (independent for all 4 slots)
- **Mode**

The available modes are:
- **None** - disabled
- **Note#** - semitone-quantized pitch CV
- **Trig** - standard trigger pulse from _NoteOn_
  - generates Clock pulses at corresponding trigger input
- **Gate** - held high at _NoteOn_, respecting polyphony; goes low when all Notes are Off
  - holds trigger input high, but does not generate a Clock pulse
- **Veloc** - Positive CV from the _Velocity_ of the most recent _NoteOn_
- **CC#** (auto-learn) - Positive CV from assigned _CC#_
  - when selected, it will display `CC#-1` until a MIDI CC message on the selected MIDI Channel is received, at which point it latches onto the CC# of the message. Basically, select CC mode and wiggle a knob to auto-learn!
- **Aft** - Positive CV from _Aftertouch_
- **Bend** - Bipolar CV from _Pitch Bend_
- **Clock** - standard trigger pulse from _MIDI Clock_ (divided internally to 2 PPQN)
- **Start** - standard trigger pulse from _MIDI Start_
