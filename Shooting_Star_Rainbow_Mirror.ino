// void shooting_star_rainbow()
// {
//   // a colored dot sweeping back and forth, with fading trails
//   fadeToBlackBy(leds, NUM_LEDS, 15);
//   int pos = beatsin16(15, 0, NUM_LEDS);
//   static int prevpos = 0;
//   // int start_index;
//   int rate = 5;
//   int start_hue;
//   int delta_hue = 10;
//   start_hue = -1 * millis() / rate;
//   // start_index = -1 * millis() / 20;
//   // CRGB color = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
//   CRGB color = CHSV(start_hue, 255, 255);
//   if (pos < prevpos)
//   {
//     fill_solid(leds + pos, (prevpos - pos) + 1, color);
//   }
//   else
//   {
//     fill_solid(leds + prevpos, (pos - prevpos) + 1, color);
//   }
//   // start_index += 1;
//   start_hue += delta_hue;
//   prevpos = pos;
// }

// void shooting_star_rainbow()
// {
//   int strobe = 30;
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 5;
//   start_hue = -1 * millis() / rate;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] += CHSV(start_hue, 255, 255);
//     hold(strobe);
//     fadeToBlackBy(leds, NUM_LEDS, 30);
//     FastLED.show();
//     start_hue += delta_hue;
//   }
// }

void shooting_star_rainbow_mirror()
{
  Serial.println("pattern_3");
  for (int i = 0; i < NUM_LEDS; i++)
  {

    //    int pos = beatsin16(10,0,NUM_LEDS);
    int start_hue;
    int delta_hue = 5;
    start_hue = -1 * millis() / 10;
    leds[i] += CHSV(start_hue, 255, 255);
    leds[NUM_LEDS - i] += CHSV(start_hue, 255, 255);
    //    leds[i + 72] += CHSV( 255, 0, 255);

    FastLED.show();
    delay(30);
    fadeToBlackBy(leds, NUM_LEDS, 30);
    FastLED.show();
    start_hue += delta_hue;
  }
}

// void shooting_star_rainbow()
// {
//   int strobe = 10;
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 5;
//   start_hue = -1 * millis() / rate;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] += CHSV(start_hue, 255, 255);
//     hold(strobe);
//     fadeToBlackBy(leds, NUM_LEDS, 30);
//     leds[NUM_LEDS - i] += CHSV(start_hue, 255, 255);
//     hold(strobe);
//     fadeToBlackBy(leds, NUM_LEDS, 30);
//     FastLED.show();
//     start_hue += delta_hue;
//   }
// }