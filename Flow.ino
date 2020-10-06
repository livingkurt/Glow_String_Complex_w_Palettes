

// Number of tweens between palettes.

void flow()
{
  // CRGBPalette16 currentPalette = jet_gp;
  int scale = 10; // Don't change this programmatically or everything shakes.

  for (int i = 0; i < HALF_LEDS; i++)
  {                                                                                     // Just ONE loop to fill up the LED array as all of the pixels change.
    uint8_t index = inoise8(i * scale, millis() / 5 + i * scale);                       // Get a value from the noise function. I'm using both x and y axis.
    leds[i] = ColorFromPalette(currentPalette, index, 255, LINEARBLEND);                // With that value, look up the 8 bit colour palette value and assign it to the current LED.       // Get a value from the noise function. I'm using both x and y axis.
    leds[NUM_LEDS - 1 - i] = ColorFromPalette(currentPalette, index, 255, LINEARBLEND); // With that value, look up the 8 bit colour palette value and assign it to the current LED.
  }
  // for (int i = NUM_LEDS; i > 0; i--)
  // {                                                                      // Just ONE loop to fill up the LED array as all of the pixels change.
  //   uint8_t index = inoise8(i * scale, millis() / 5 + i * scale);        // Get a value from the noise function. I'm using both x and y axis.
  //   leds[i] = ColorFromPalette(currentPalette, index, 255, LINEARBLEND); // With that value, look up the 8 bit colour palette value and assign it to the current LED.
  // }
}
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 10; // no x/y shifting but scrolling along

//   uint8_t scale = 1000; // the "zoom factor" for the noise
//   start_hue = -1 * millis() / rate;
//   for (uint16_t i = 0; i < NUM_LEDS; i++)
//   {

//     uint16_t shift_x = 4223; // no movement along x and y
//     uint16_t shift_y = 1234;

//     // uint16_t shift_x = 2000;                                  // no movement along x and y
//     // uint16_t shift_y = 1000;

//     uint32_t real_x = (i + shift_x) * scale; // calculate the coordinates within the noise field
//     uint32_t real_y = (i + shift_y) * scale; // based on the precalculated positions
//     uint32_t real_z = millis() * 2;          // increment z linear

//     uint8_t noise = inoise16(real_x, real_y, real_z) >> 7; // get the noise data and scale it down

//     uint8_t index = sin8(noise * 10); // map led color based on noise data
//     uint8_t bri = noise;

//     leds[i] = ColorFromPalette(currentPalette, index, BRIGHTNESS, LINEARBLEND); // With that value, look up the 8 bit colour palette value and assign it to the current LED.
//     // leds[i] = CHSV(index, 255, 255);
//     // start_hue += delta_hue;
//   }
//   // FastLED.show();

// } // noise16_3()