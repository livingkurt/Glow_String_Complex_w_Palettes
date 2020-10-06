#include <FastLED.h>

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#include "GradientPalettes.h"

// Data Pin on Arduino
#define LED_PIN 5
// LED Chip Type
#define LED_TYPE WS2811
// Number of LEDs Used
// #define NUM_LEDS 50
// The Order of RGB was wired on the chip
#define COLOR_ORDER RGB
// MODE_Interval Between Mode Changes
// Development
// #define MODE_INTERVAL 10
// Production
#define MODE_INTERVAL 10
// MODE_Interval Between Mode Changes
// Development
#define PALETTE_INTERVAL 10
// Production
// #define PALETTE_INTERVAL 40
// Choose Random or Not Random Mode Changes
#define RANDOM_PATTERN false
#define RANDOM_PALETTE false

#define SYSTEM_MAX_LEDS 50

#define NUM_LEDS SYSTEM_MAX_LEDS //try to sync everything

#define HALF_LEDS NUM_LEDS / 2

#define HALF_SYSTEM_MAX_LEDS HALF_LEDS

#define MILLI_AMPS 4000 // IMPORTANT: set the max milli-Amps of your power supply (4A = 4000mA) // standard usb
//#define MILLI_AMPS            30000 // 30 Amps

#define VOLTS 5 // IMPORTANT: LED Strip
//#define VOLTS           12 // IMPORTANT: LED String

#define FRAMES_PER_SECOND 120 // here you can control the speed. With the Access Point / Web Server the animations run a bit slower.

CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255

TBlendType blendingType; //tBlendType is a type of value like int/char/uint8_t etc., use to choose LINERBLEND and NOBLEND

void setup()
{
  delay(3000); // 3 second delay for recovery
  Serial.begin(9600);
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}
// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();

SimplePatternList gPatterns = {
    // shooting_star
    cycle,
    sparkle_white,
    rainbow_sparkle,
    shooting_star_rainbow,
    juggle,
    // juggle_clouds,
    cycle_rainbow_desaturated,
    split,
    // pride,
    pulse,
    shooting_star_white,
    sparkle_rainbow_saturation,
    // colorWaves,
    pulse_white,

    // sparkle,
    bpm,
    juggle_white,

    // shooting_star_white_mirror,
    // shooting_star_rainbow_mirror,

    // flow,
    // shooting_star,

    // // cloudTwinkles,
    // // rainbowTwinkles,

    // sparkle_rainbow_saturation,

    // split_shooting_star

    // twinkles,

    // cycle_rainbow,
    // all_fade_rainbow,
    // all_fade_white,

    // cycle_color_palette,
    // cycle_rainbow,
    // cycle_rainbow_desaturated,

    // flash_rainbow,

    // shooting_star_rainbow,
    // shooting_star_rainbow_mirror,
    // shooting_star_rainbow_multi_all_fade_speed_control_bnf,
    // shooting_star_rainbow_multi_single_fade_speed_control_bnf,
    // shooting_star_rainbow_saturation,
    // shooting_star_rainbow_speed_control_bnf,

    // shooting_star_white,
    // shooting_star_white_mirror,
    // shooting_star_white_multi_speed_control_bnf,
    // shooting_star_white_speed_control_bnf,

    // sparkle_rainbow_all_fade,
    // sparkle_rainbow_no_off,
    // sparkle_rainbow_no_off_all,
    // sparkle_rainbow_random,
    // sparkle_rainbow_saturation,

    // sparkle_white,
    // sparkle_white_no_off,
    // sparkle_white_rainbow_all_fade,

    // split_color_palette_2,
    // split_color_palette_4,

    // split_rainbow,
    // split_rainbow_2,
    // split_rainbow_4,
    // split_rainbow_8,
    // split_rainbow_10,
    // split_rainbow_20,

    // split_shooting_star_rainbow,
    // split_shooting_star_rainbow_4,
    // split_shooting_star_rainbow_10,
    // split_shooting_star_white_10,

    // flow_color_palette_simple,
    // flow_rainbow_simple,
    // flow_rainbow,
    // flow_color_palette,

};
// CRGBPalette16 currentPalette(CRGB::Black);

int num_modes = (sizeof(gPatterns) / sizeof(gPatterns[0]));

const CRGBPalette16 gPalettes[] = {
    RainbowColors_p,
    es_ocean_breeze_036_gp,
    es_pinksplash_08_gp,
    es_landscape_33_gp,
    gr65_hult_gp,
    jet_gp,
    tubepreview_gp,
    es_rivendell_15_gp,
    trove_gp,
    wildwinds_gp,
    bambooblossom_gp,
    angelrepose_gp,
    cloud_gp,
    healingangel_gp,
    pinkchampagne_gp,
    pinkfairyrose_gp,
    spellbound_gp,
    tashangel_gp,
};

CRGBPalette16 currentPalette(CRGB::Black);

CRGBPalette16 targetPalette(RainbowColors_p);

// const uint8_t paletteCount = ARRAY_SIZE(gPalettes);

int num_palettes = (sizeof(currentPalette) / sizeof(currentPalette[0]));

uint8_t gCurrentPatternNumber = 0;
uint8_t gCurrentPaletteNumber = 0;
// uint8_t gHue = 0; // rotating "base color" used by many of the patterns
// int gHue;
// gHue = -1 * millis() / 10;
// int start_index;
// start_index = -1 * millis() / 10;
#include "Twinkles.h"

void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  uint8_t maxChanges = 24;
  // nblendPaletteTowardPalette(gPalettes[0], gPalettes[gCurrentPaletteNumber], maxChanges);
  nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
  gPatterns[gCurrentPatternNumber]();
  // gPalettes[gCurrentPaletteNumber];
  // gPatterns[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  // EVERY_N_MILLISECONDS(20) { gHue += 5; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS(MODE_INTERVAL)
  {
    nextPattern(); // change patterns periodically
  }
  EVERY_N_SECONDS(PALETTE_INTERVAL)
  {
    nextPalette(); // change patterns periodically
  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  if (RANDOM_PATTERN)
  {
    gCurrentPatternNumber = random(num_modes) % ARRAY_SIZE(gPatterns);
  }
  else
  {
    Serial.println(random(num_modes));
    gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
  }
}

void nextPalette()
{
  // add one to the current pattern number, and wrap around at the end
  if (RANDOM_PALETTE)
  {
    gCurrentPaletteNumber = random(num_palettes) % ARRAY_SIZE(gPalettes);
  }
  else
  {
    Serial.println(random(num_palettes));
    gCurrentPaletteNumber = (gCurrentPaletteNumber + 1) % ARRAY_SIZE(gPalettes);
  }
  targetPalette = gPalettes[gCurrentPaletteNumber];
}

int forwards(int length, int placement, int pos)
{
  return (length * placement) + pos;
}

int backwards(int length, int placement, int pos)
{
  return length * placement - 1 - pos;
}

void hold(int period)
{
  unsigned long time_now = 0;
  time_now = millis();
  while (millis() < time_now + period)
  {
    // FastLED.show();
  }
}