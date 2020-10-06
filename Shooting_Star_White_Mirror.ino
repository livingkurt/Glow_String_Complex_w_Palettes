// void shooting_star()
// {
//   // // a colored dot sweeping back and forth, with fading trails
//   // fadeToBlackBy(leds, NUM_LEDS, 15);
//   // int pos = beatsin16(15, 0, NUM_LEDS);
//   // static int prevpos = 0;
//   // int start_index;
//   // start_index = -1 * millis() / 20;
//   // CRGB color = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
//   // if (pos < prevpos)
//   // {
//   //   fill_solid(leds + pos, (prevpos - pos) + 1, color);
//   // }
//   // else
//   // {
//   //   fill_solid(leds + prevpos, (pos - prevpos) + 1, color);
//   // }
//   // start_index += 1;
//   // prevpos = pos;
//   // cd77_sinelon_oneway(20, CRGB::Red, 5);
// }
void shooting_star_white_mirror()
{
  Serial.println("pattern_3");
  for (int i = 0; i < NUM_LEDS; i++)
  {

    //    int pos = beatsin16(10,0,NUM_LEDS);
    leds[i] += CHSV(255, 0, 255);
    leds[NUM_LEDS - i] += CHSV(255, 0, 255);
    //    leds[i + 72] += CHSV( 255, 0, 255);

    FastLED.show();
    delay(30);
    fadeToBlackBy(leds, NUM_LEDS, 30);
    FastLED.show();
  }
}

// // Modification of sinelon() in FastLED's DemoReel100 example
// void shooting_star_mirror()
// {
//   // a colored dot going in one direction with fading tail
//   fadeToBlackBy(leds, NUM_LEDS, 30); //change fadeby to smaller or larger number to adjust the length of the tail.
//   uint8_t u = beat8(40, 0);          //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS);
//   int start_index;
//   start_index = -1 * millis() / 10;
//   CRGB color = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
//   start_index += 20;
//   leds[pos] = color;
//   leds[NUM_LEDS - pos] = color;
//   // FastLED.show();
// }

// // this function is from FastLED DemoReel100 example
// void cd77_sinelon(uint8_t BPM, CRGB color)
// {
//   // a colored dot sweeping back and forth, with fading tail
//   fadeToBlackBy(leds, NUM_LEDS, 20);          //change 20 to smaller or larger number to adjust the length of the tail.
//   uint16_t pos = beatsin16(BPM, 0, NUM_LEDS); //BPM will allow you to adjust the speed the dot is moving.
//   leds[pos] = color;
//   FastLED.show();
// }

// // Modification of sinelon() in FastLED's DemoReel100 example
// void cd77_sinelon_oneway(uint8_t BPM, CRGB color, uint8_t fadeby)
// {
//   // a colored dot going in one direction with fading tail
//   fadeToBlackBy(leds, NUM_LEDS, fadeby); //change fadeby to smaller or larger number to adjust the length of the tail.
//   uint8_t u = beat8(BPM, 0);             //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS);
//   leds[pos] = color;
//   FastLED.show();
// }

// // this function is from FastLED DemoReel100 example
// void cd77_sinelon(uint8_t BPM, CRGB color)
// {
//   // a colored dot sweeping back and forth, with fading tail
//   fadeToBlackBy(leds, NUM_LEDS, 20);          //change 20 to smaller or larger number to adjust the length of the tail.
//   uint16_t pos = beatsin16(BPM, 0, NUM_LEDS); //BPM will allow you to adjust the speed the dot is moving.
//   leds[pos] = color;
//   FastLED.show();
// }