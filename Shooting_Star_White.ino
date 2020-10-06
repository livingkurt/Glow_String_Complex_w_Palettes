// void shooting_star_white()
// {
//   // a colored dot sweeping back and forth, with fading trails
//   fadeToBlackBy(leds, NUM_LEDS, 15);
//   int pos = beatsin16(15, 1, NUM_LEDS);
//   static int prevpos = 0;
//   int start_index;
//   start_index = -1 * millis() / 20;
//   // CRGB color = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
//   CRGB color = CHSV(255, 0, 255);

//   if (pos < prevpos)
//   {
//     fill_solid(leds + pos, (prevpos - pos) + 1, color);
//   }
//   else
//   {
//     fill_solid(leds + prevpos, (pos - prevpos) + 1, color);
//   }
//   start_index += 1;
//   prevpos = pos;
// }

// void shooting_star_white()
// {
//   int strobe = 10;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] += CHSV(255, 0, 255);
//     hold(strobe);
//     fadeToBlackBy(leds, NUM_LEDS, 30);

//     leds[NUM_LEDS - i] += CHSV(255, 0, 255);
//     hold(strobe);
//     fadeToBlackBy(leds, NUM_LEDS, 30);
//     FastLED.show();
//   }
// }

void shooting_star_white()
{
  Serial.println("pattern_3");
  for (int i = 0; i < NUM_LEDS; i++)
  {

    //    int pos = beatsin16(10,0,NUM_LEDS);
    leds[i] += CHSV(255, 0, 255);
    //    leds[i + 72] += CHSV( 255, 0, 255);

    FastLED.show();
    delay(30);
    fadeToBlackBy(leds, NUM_LEDS, 30);
    FastLED.show();
  }
}