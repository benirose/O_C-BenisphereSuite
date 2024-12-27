---
layout: default
---
# Setup / About

![Setup/About Screenshot](images/Setup_About.png)

* Press the LEFT encoder to enter the Calibration routine
* Press the RIGHT encoder to reset calibration / settings to defaults - press RIGHT again to confirm (LEFT to cancel)

### Flipped Screen / Controls
_(new in v1.8.3)_
Next to "Setup/About" you'll see two arrows in the title bar. Up/Down indicates screen flip; Left/Right indicates controls & IO reversal. If you need to change either, dual-press the UP+DOWN buttons to cycle through. Return to main menu and it will save; power cycle to take effect.

_Notice:_ The calibration routine is agnostic of screen or I/O flip... DAC A and CV1 are addressed as if in normal module orientation.

### Encoder Orientation
Depending on your hardware variant (and your personal preference), one or both encoders may need to be reversed.
On the calibration confirmation page OR last page, press either of the UP or DOWN buttons to select encoder reversal for L, R, both (LR), or neither (normal).

As of v1.8.3, if you change the encoder setting on the first page, you can still cancel and the setting will be saved when you return to the main menu.

## Calibration Routine

![Setup: Calibrate](images/cal_start.png)

On the initial calibration screen, you can choose to start fresh or edit existing settings:
* Rotate RIGHT encoder to change ("Yes"/"No")
* To **edit calibration**, select "No", and press the RIGHT encoder (OK)
* To **reset calibration** to the defaults, select "Yes", and press the RIGHT encoder (OK)
    - Recommended for fresh builds
    - _Note: the displayed encoder reversal setting will not be disturbed_
    - App settings are also preserved when resetting calibration.
* To cancel, press the LEFT encoder (Cancel)

### Pages

To change pages:
* Rotate the LEFT encoder to paginate, or
* Press the RIGHT encoder to go to the next page
* Press the LEFT encoder to go the previous page

To edit the current page parameter:
* Rotate the RIGHT encoder

![Center Display](images/cal_screen.png)

Horizontal pixel offset for centering the display.

![DAC Calibration minimum](images/cal_dac1.png)
![DAC Calibration maximum](images/cal_dac2.png)

DAC calibration tends to be very linear. You only need to calibrate the minimum and maximum values and the firmware can interpolate in between. For each output:
* Measure the voltage with a precision multimeter
* Use the right encoder to make the multimeter agree with the value in the title bar
* Long-press DOWN where prompted to interpolate the intermediate values. A checkmark will appear.

![ADC Offset](images/cal_adc1.png)

ADC offset for 0v - _All values should be around zero (-1 < > +1)_

![ADC Scaling 1v](images/cal_adc2.png)
![ADC Scaling 3v](images/cal_adc3.png)

Scaling for the CV inputs:
* connect DAC A to CV1
* on OCP hardware, make sure the attenuator is fully open (CW)
* long-press DOWN button to set each point (1v and 3v)

![Screen Blank](images/cal_screenblank.png)

Timeout for the screensaver or blank screen

![Calibration complete](images/cal_complete.png)

Final step - save and adjust encoder direction
* Press UP or DOWN buttons to select encoder reversal for L, R, both (LR), or neither (normal)
* Select "Yes" to save and "No" to cancel; press the RIGHT encoder to exit
