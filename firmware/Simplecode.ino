#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h> 

// Pin declarations: giving our micro-chip pins some spicy custom identities
#define SPICY_CLOCK_BOI 0   // SCL: Ticks faster than your cpu clock
#define DATA_FORCE_FEEDER     1   // SDA: Force feeding bit for the screen
#define SCREEN_REBOOT   2   // RST: Shi for the screen to refresh
#define DATA_OR_DRAMA   3   // DC: What do we send ? Dw we have DC
#define CHIP_CHAPERONE  4   // CS: keeps this specific chip on its best behavior
#define GLOW_STICK      5   // BL: Ts is for the screen to light up fot people who cant see in the dark

// Button definitions: the plastic nubs of ultimate power
#define NUDGE_NORTH     6   // Up: pushes things toward the heavens
#define NUDGE_SOUTH     7   // Down: sends things straight down to Hell
#define SMASH_THAT_OK   8   // Select: the button of zero regrets
#define NOPE_ABORT      9   // Back: emergency escape hatch

// A frankenstein display class to fix this display's bizarre identity crisis
class FrankensteinScreen : public Adafruit_ST7789 {
public:
  FrankensteinScreen(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst)
    : Adafruit_ST7789(cs, dc, mosi, sclk, rst) {}
  void nudgeThePixels(uint8_t col, uint8_t row) {
    // Slapping the internal pixel offsets because this screen has spatial issues
    _colstart = _colstart2 = col;
    _rowstart = _rowstart2 = row;
  }
};

FrankensteinScreen magicalGlass(CHIP_CHAPERONE, DATA_OR_DRAMA, DATA_YEETER, SPICY_CLOCK_BOI, SCREEN_REBOOT);

void setup() {
  // Telling the micro-controller that these pins need to listen for finger punches
  pinMode(NUDGE_NORTH, INPUT_PULLUP);
  pinMode(NUDGE_SOUTH, INPUT_PULLUP);
  pinMode(SMASH_THAT_OK, INPUT_PULLUP);
  pinMode(NOPE_ABORT, INPUT_PULLUP);

  // Turn on the backlight (LOW means ON because logic is upside-down today)
  pinMode(GLOW_STICK, OUTPUT);
  digitalWrite(GLOW_STICK, LOW); 

  // Awaken the screen deity
  magicalGlass.init(76, 284);
  magicalGlass.nudgeThePixels(82, 18); // Apply special magic numbers so text isn't cut off
  magicalGlass.invertDisplay(false);   // Stop colors from looking like a bad trip
  magicalGlass.setRotation(1);        // Tilt screen sideways so humans can read it

  // Paint the void black and scream into it
  magicalGlass.fillScreen(ST77XX_BLACK);
  magicalGlass.setTextColor(ST77XX_WHITE);
  magicalGlass.setTextSize(3);
  magicalGlass.setCursor(10, 20);
  magicalGlass.print("READY 2 RUMBLE");
}

void loop() {
  // Continuously stalking the buttons to see who gets poked first
  if (digitalRead(NUDGE_NORTH) == LOW) {
    magicalGlass.fillScreen(ST77XX_BLACK);
    magicalGlass.setCursor(10, 20);
    magicalGlass.print("GOING UP!");
    delay(200); // Chill out for 0.2s so it doesn't spam 9000 times per click
  }

  if (digitalRead(NUDGE_SOUTH) == LOW) {
    magicalGlass.fillScreen(ST77XX_BLACK);
    magicalGlass.setCursor(10, 20);
    magicalGlass.print("GOING DOWN!");
    delay(200);
  }

  if (digitalRead(SMASH_THAT_OK) == LOW) {
    magicalGlass.fillScreen(ST77XX_BLACK);
    magicalGlass.setCursor(10, 20);
    magicalGlass.print("YEAH BOI!");
    delay(200);
  }

  if (digitalRead(NOPE_ABORT) == LOW) {
    magicalGlass.fillScreen(ST77XX_BLACK);
    magicalGlass.setCursor(10, 20);
    magicalGlass.print("GET OUT!");
    delay(200);
  }
}
