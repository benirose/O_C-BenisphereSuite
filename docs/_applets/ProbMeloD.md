---
layout: default
---
# ProbMeloD

![Screenshot 2024-06-13 15-19-37](https://github.com/djphazer/O_C-Phazerville/assets/109086194/8deab434-e06f-4b83-8ca6-730358004a5a)

**ProbMeloD** is a stochastic melody generator inspired by the [Melodicer](https://www.modulargrid.net/e/vermona-melodicer) and [Stochastic Inspiration Generator](https://www.modulargrid.net/e/stochastic-instruments-stochastic-inspiration-generator). It allows you to assign probability to each note in a chromatic scale, as well as set the range of octaves to pick notes from. It can be used by itself or with [ProbDiv](ProbDiv), which it will automatically link to.

ProbMeloD has 2 channels, which can output independently clocked pitch values based on the same note ranges and probabilities. 

[See it in action!](https://www.youtube.com/watch?v=uR8pLUVNDjI)

### I/O

|        | 1/3 | 2/4 |
| ------ | :-: | :-: |
| TRIG   |  Clock A   |  Clock B   |
| CV INs |   Low range |  High range   |
| OUTs   |  Pitch A  |  Pitch B   |

### UI Parameters
 - Low range
 - High range
 - Probability per note

## Probabilities

Probabilities are defined as weights from 0-10 for choosing a specific note. For example, if you only have a probability set for C it will always be selected no matter the probability. Or if you have a probability 10 for both C and D, it will be a 50/50 chance of either note being selected. Probability value can be thought of as the number of raffle tickets entered for each note when it’s time to pick a new one, which is any time a trigger is received on Digital 1.

## Range

ProbMeloD has a range of 5 octaves. Lower and upper range are displays in an _octave_._semitone_ notation, so a range of `1.1` to `1.12` will cover the entire first octave, or C through B if your oscillator is tuned to C.

## Pairing with ProbDiv and Looping

ProbMeloD does not have any looping functionality on its own, but can loop when paired with [ProbDiv](ProbDiv). Like ProbDiv, a new loop is generated in both applets when any parameter in ProbDiv or ProbMeloD are changed. If ProbDiv and ProbMeloD are loaded in each hemisphere, they will automatically link. Clock division outputs from ProbDiv will automatically trigger ProbMeloD, and ProbMeloD will capture a loop when ProbDiv is looping as well. When used together they can be treated as a whole probabilistic sequencer!

### Credits
Copied/Adapted from [ProbMeloD](https://github.com/benirose/O_C-BenisphereSuite/wiki/ProbMeloD) by benirose
