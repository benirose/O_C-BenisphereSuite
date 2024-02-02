#pragma once

// misc. utility functions extracted from Hemisphere
// -NJM

//////////////// Calculation methods
////////////////////////////////////////////////////////////////////////////////

/* Proportion method using simfloat, useful for calculating scaled values given
 * a fractional value.
 *
 * Solves this:  numerator        ???
 *              ----------- = -----------
 *              denominator       max
 *
 * For example, to convert a parameter with a range of 1 to 100 into value scaled
 * to HEMISPHERE_MAX_CV, to be sent to the DAC:
 *
 * Out(ch, Proportion(value, 100, HEMISPHERE_MAX_CV));
 *
 */
int Proportion(int numerator, int denominator, int max_value) {
    simfloat proportion = int2simfloat((int32_t)numerator) / (int32_t)denominator;
    int scaled = simfloat2int(proportion * max_value);
    return scaled;
}

/* Proportion CV values into pixels for display purposes.
 *
 * Solves this:     cv_value           ???
 *              ----------------- = ----------
 *              HEMISPHERE_MAX_CV   max_pixels
 */
int ProportionCV(int cv_value, int max_pixels) {
    // TODO: variable scaling for VOR?
    int prop = constrain(Proportion(cv_value, HEMISPHERE_MAX_INPUT_CV, max_pixels), -max_pixels, max_pixels);
    return prop;
}

// Specifies where data goes in flash storage for each selcted applet, and how big it is
typedef struct PackLocation {
    size_t location;
    size_t size;
} PackLocation;

/* Add value to a 64-bit storage unit at the specified location */
void Pack(uint64_t &data, PackLocation p, uint64_t value) {
    data |= (value << p.location);
}

/* Retrieve value from a 64-bit storage unit at the specified location and of the specified bit size */
int Unpack(uint64_t data, PackLocation p) {
    uint64_t mask = 1;
    for (size_t i = 1; i < p.size; i++) mask |= (0x01 << i);
    return (data >> p.location) & mask;
}

//////////////// Hemisphere-like graphics methods for easy porting
////////////////////////////////////////////////////////////////////////////////
void gfxPos(int x, int y) {
    graphics.setPrintPos(x, y);
}

void gfxPrint(int x, int y, const char *str) {
    graphics.setPrintPos(x, y);
    graphics.print(str);
}

void gfxPrint(int x, int y, int num) {
    graphics.setPrintPos(x, y);
    graphics.print(num);
}

void gfxPrint(const char *str) {
    graphics.print(str);
}

void gfxPrint(int num) {
    graphics.print(num);
}

void gfxPrint(int x_adv, int num) { // Print number with character padding
    for (int c = 0; c < (x_adv / 6); c++) gfxPrint(" ");
    gfxPrint(num);
}

/* Convert CV value to voltage level and print  to two decimal places */
void gfxPrintVoltage(int cv) {
    int v = (cv * 100) / (12 << 7);
    bool neg = v < 0 ? 1 : 0;
    if (v < 0) v = -v;
    int wv = v / 100; // whole volts
    int dv = v - (wv * 100); // decimal
    gfxPrint(neg ? "-" : "+");
    gfxPrint(wv);
    gfxPrint(".");
    if (dv < 10) gfxPrint("0");
    gfxPrint(dv);
    gfxPrint("V");
}

void gfxPixel(int x, int y) {
    graphics.setPixel(x, y);
}

void gfxFrame(int x, int y, int w, int h) {
    graphics.drawFrame(x, y, w, h);
}

void gfxRect(int x, int y, int w, int h) {
    graphics.drawRect(x, y, w, h);
}

void gfxInvert(int x, int y, int w, int h) {
    graphics.invertRect(x, y, w, h);
}

void gfxLine(int x, int y, int x2, int y2) {
    graphics.drawLine(x, y, x2, y2);
}

void gfxDottedLine(int x, int y, int x2, int y2, uint8_t p = 2) {
#ifdef HS_GFX_MOD
    graphics.drawLine(x, y, x2, y2, p);
#else
    graphics.drawLine(x, y, x2, y2);
#endif
}

void gfxCircle(int x, int y, int r) {
    graphics.drawCircle(x, y, r);
}

void gfxBitmap(int x, int y, int w, const uint8_t *data) {
    graphics.drawBitmap8(x, y, w, data);
}

// Like gfxBitmap, but always 8x8
void gfxIcon(int x, int y, const uint8_t *data) {
    gfxBitmap(x, y, 8, data);
}

uint8_t pad(int range, int number) {
    uint8_t padding = 0;
    while (range > 1)
    {
        if (abs(number) < range) padding += 6;
        range = range / 10;
    }
    if (number < 0 && padding > 0) padding -= 6; // Compensate for minus sign
    return padding;
}

