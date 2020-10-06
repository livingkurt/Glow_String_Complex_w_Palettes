void sparkle_rainbow_saturation()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy(leds, NUM_LEDS, 300);
  int pos = random(0, NUM_LEDS);
  int start_index;
  start_index = -1 * millis() / 10;
  // leds[pos] += CHSV( gHue + random8(64), 200, 255);
  leds[pos] += CHSV(start_index, random(127, 255), random(0, 255));
  // leds[NUM_LEDS - 1 - pos] += ColorFromPalette(palettes[currentPaletteIndex], start_index, 255, blendMode == 0 ? NOBLEND : LINEARBLEND);
  start_index += 5;
  hold(10);
}