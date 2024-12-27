---
layout: default
---
# Quadrants

![O_CT4.1 Control Guide](images/front_panel_desc.png)

**Quadrants** is essentially a copy of Hemispheres, upgraded to host **four** applets at a time to take advantage of new 8-channel hardware shields with Teensy 4.1.

### Controls

Some controls are specific to new hardware, with 5 buttons + 2 encoders:
* Short-press Z - Start/Arm/Stop the Clock
* Short-press A/B/X/Y - switch corresponding applet into view (NW, NE, SW, SE)
* Hold X or Y + press Z - view full-screen/help
* Hold X or Y + turn encoder - switch applet on corresponding side
* Press A + X - Load Preset shortcut
* Press B + Y - Input Mapping shortcut

Other controls are identical to Hemispheres:
* Press A + B - Clock Setup
* Long-press A - Invoke Screensaver (global)
* Long-press B - Config (presets, general settings, input mapping, quantizers, etc)

### Input Mapping

Each applet still has only 2 trigger inputs, 2 CV inputs, and 2 outputs.
The output routing is hardcoded and not configurable - the "North-West" applet uses outputs A & B, "North-East" uses outputs C & D, etc.
The inputs, however, can be completely reassigned, allowing triggers to be derived from TR1..4 as well as CV1..8 or even looped back from one of the outputs. Same with CV. Complex internal feedback patterns can be achieved this way, but also simple use cases such as clocking all 4 applets from TR1, or sampling the same CV input with several instances of Squanch.
