---
layout: default
nav_order: 4
---
# Hemisphere Gestures

Operating Hemispheres makes use of button combinations to perform various actions. See below for a complete list.

Please note that certain applet (or parameter editing) contexts may override the default behaviour of the UP and DOWN buttons &/or the LEFT and RIGHT encoders.


| Action                                          |                                             Gesture                                              |                                                                                                             Notes                                                                                                              |
| ----------------------------------------------- |:------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| **Change left Hemisphere applet**               |         Short press UP button to highlight hemisphere, scroll applets with LEFT encoder          |                                                                                                                                                                                                                                |
| **Change right Hemisphere applet**              |        Short press DOWN button to highlight hemisphere, scroll applets with RIGHT encoder        |                                                                                                                                                                                                                                |
| **Open applet help screen**                     |    Double press UP button for left hemisphere, double press DOWN button for right hemisphere     |                                                                                                                                                                                                                                |
| **[Open Clock / Trigger Setup](Clock-Setup)** |                              Press both UP + DOWN buttons together                               |                   Adjust internal BPM, swing, external sync, and per-trigger clock mult/div; remap trigger inputs (also available within the [Config](Hemisphere-Config)); and manually perform triggers.                    |
| **Cycle Internal Clock state**                  |                                     Long-press LEFT Encoder                                      |                                                                                       Stop -> Arm _(i.e. play on next input trigger)_ -> Start                                                                                        |
| **[Open Hemisphere Config menu](Hemisphere-Config)**    |    Long-press DOWN button (scroll pages with LEFT encoder, scroll options with RIGHT encoder)    |                             Load/save presets; adjust trigger length; select screensaver and cursor mode; toggle auto-MIDI out; trigger and CV input mapping; quantizer settings; applet filtering                             |
| **AuxButton**                                   | _**Highlight parameter for editing**_, press select button (UP or DOWN, depending on Hemisphere) | This gesture is only enabled in certain applets for secondary functions. Use it to mute/unmute steps in DivSeq, SequenceX, Seq32, etc.; re-randomize sequences in Shredder; and directly edit the current [Quantizer engine](Hemisphere-Quantizer-Setup) |
| **Invoke screensaver**                          |                                       Long-press UP button                                       |                                                                                                             Global                                                                                                             |
| **Return to main menu**                         |                                     Long-press RIGHT encoder                                     |                                                                                         Global, execution continues in the background.                                                                                         |
| **[Save Settings to EEPROM](Saving-State)**    |                       Long-press RIGHT encoder _again_ while on main menu                        |       Why not use [presets](Hemisphere-Config#presets-floating-menu) instead? |

### VOR Gestures
_Variable Output Range compatible hardware only (i.e. Plum Audio 4robots, OCP, and OCP x)_
* **Start/ stop clock:** press VOR button
* **Cycle VBias offset (-5V, -3V, 0V):** Press LEFT and RIGHT encoders together
