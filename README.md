[![PlatformIO CI](https://github.com/djphazer/O_C-BenisphereSuite/actions/workflows/firmware.yml/badge.svg)](https://github.com/djphazer/O_C-BenisphereSuite/actions/workflows/firmware.yml)

Phazerville Suite with Relabi - an active o_C firmware fork
===
[![SynthDad's video overview](http://img.youtube.com/vi/XRGlAmz3AKM/0.jpg)](http://www.youtube.com/watch?v=XRGlAmz3AKM "Phazerville; newest firmware for Ornament and Crime. Tutorial and patch ideas")

Watch SynthDad's **video overview** (above) or check the [**Wiki**](https://github.com/djphazer/O_C-BenisphereSuite/wiki) for more info. [Download it here](https://github.com/djphazer/O_C-BenisphereSuite/releases).

## An active fork expanding upon Hemisphere Suite.

This is a fork of djphazer's Phazerville Suite which is a fork of Benisphere which is a fork of Hemisphere! The code is firmware for the Ornament & Crime, a Eurorack synth module that can act as many different modules as selected by the user. This firmware ads the Relabi app that generates chaotic but deterministic control voltage. In addition, it adds a function to the HSVectorOscillator.h file and provides a controller file that allows two Relabi apps to be linked, providing four related chaotic LFOs.

Read more about the suite [here](https://github.com/djphazer/O_C-Phazerville). Please, go there and read about all the people who have contributed code.

## What is Relabi.

Relabi is an alternative method of defining musical time. While rhythm is concerned with recurring pulses, relabi always slips the pulse. You can read all about the concept in [John Berndt's essay]((https://johnberndt.org/relabi/).




### How To Get It

Check the [Releases](https://github.com/djphazer/O_C-BenisphereSuite/releases) section for a .hex file (to be used with the Teensy loader app), or clone the repository and build it yourself! I think the beauty of this module is the fact that it's relatively easy to modify and build the source code to reprogram it. You are free to customize the firmware, similar to how you've no doubt already selected a custom set of physical modules.

### How To Change It

This firmware fork is built using Platform IO, a Python-based build toolchain, available as either a [standalone CLI](https://docs.platformio.org/en/latest/core/installation/methods/installer-script.html) or a [full-featured IDE](https://platformio.org/install/ide), as well as a plugin for VSCode and other existing IDEs.

The project lives within the `software/o_c_REV` directory. From there, you can Build the desired configuration and Upload via USB to your module:
```
pio run -e oc_stock2_flipped -t upload
```
Have a look inside `platformio.ini` for alternative build environment configurations - VOR, Buchla, flipped screen, etc. To build all the defaults consecutively, simply use `pio run`

_**Pro-tip**_: If you decide to fork the project, and enable GitHub Actions on your own repo, GitHub will build the files for you... ;)

