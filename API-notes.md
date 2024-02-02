API Notes
===

### Basics

The o_C firmware operates with several "concurrent" threads.
(really they interrupt each other I guess)

There is a main _loop_ as well as an _ISR_ that fires from a timer.
The _loop_ acts as a watchdog while the _ISR_ does all the work.
UI events are on a seperate _ISR_ timer.
The display driver and input polling are also on independent interrupts.
So that's at least 4? separate processes happening in a cascade
for every cycle, which is 60us (nanoseconds) or 16.666khz

That's the general idea.

Anyway, we have top-level *Apps* and then there are *Applets* as implemented
in the _Hemisphere_ *App*. An *Applet* inherits the base class _HemisphereApplet_
and gains the superpowers necessary to live on half of your module's screen.

### Base Classes

The two primary interfaces in the Hemisphere API are _HSApplication_ and _HemisphereApplet_.
They both have many similarly named methods for I/O and graphics, with 
_HemisphereApplet_ taking extra considerations for offsetting both in the right side.

All of the hardware details are neatly abstracted under these two interfaces. If you
simply want to make an applet that does some stuff, these APIs are your starting point.

### Applets

There are a few different things an Applet must do:
* Controller - the main logic computed every tick (every time the ISR fires)
* View - draw the pixels on the screen (there are many helpful _gfx*_ functions)
* UI Event Handling:
  * OnButtonPress - what to do when the encoder button is pressed
  * OnEncoderMove - what to do when the encoder rotated
* OnDataRequest / OnDataReceive - how to save / load state

There is also a `Start()` function for initializing things at runtime,
plus some Help text. That's about it.

You can easily try it out by copying the `HEM_Boilerplate.ino.txt` file into place,
and then adding your computations to its skeleton.

### Applet Functions

Function? or Method? Either way, this is how you do the things.

#### I/O Functions
The main argument of each is the channel to operate on - each half of the
screen gets 2 channels. So _n_ is typically either 0 or 1.

**Input**:
* Clock(n) - has the digital input received a new clock pulse?
* Gate(n) - is the digital input held high?
* In(n) - Raw value of the CV input
* DetentedIn(n) - this one reads 0 until it's past a threshold ~ a quartertone

**Output**:
* ClockOut(n) - hold the output high for a pulse length
* GateOut(n, on_off) - set the output high or low
* Out(n, raw) - set the output to an explicit value

I've added a standard case function for modulating a parameter with a certain input.
* Modulate(param, n, min, max) - automatically scales the input and modifies param

#### gfx Functions
There are many strategies for drawing things on the screen, and therefore, many
graphics related functions. You can see them for yourself in `HemisphereApplet.h`
All of them typically take _x_ and _y_ coordinates for the first two arguments,
followed by _width_ and _height_, or another _x,y_ pair.
_x_ is how many pixels from the left edge of the screen.
_y_ is how many pixels from the top edge of the screen.

Some essentials: *gfxPrint*, *gfxPixel*, *gfxLine*, *gfxCursor*,
                *gfxFrame*, *gfxBitmap*, *gfxInvert*

