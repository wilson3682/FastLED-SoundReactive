#ifndef PIXELBLEND_H
#define PIXELBLEND_H

void pixelblend() {

// Local definitions

// Persistent local variables
  static uint16_t currLED;                                                      // Persistent local value to count the current LED location.

// Temporary local variables


  currLED = (currLED+1)	% (NUM_LEDS);                                           // Cycle through all the LED's. By Andrew Tuline.

  CRGB newcolour = ColorFromPalette(currentPalette, sin8(sample), sampleAgc, currentBlending);   // Colour of the LED will be based on the sample, while brightness is based on sampleavg.
  nblend(leds[currLED], newcolour, 192);                                        // Blend the old value and the new value for a gradual transitioning.

//  leds[(millis() % (NUM_LEDS-1)) +1] = ColorFromPalette(currentPalette, sampleAgc, sampleAgc, currentBlending);

} // pixelblend()

#endif
