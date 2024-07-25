#include "constants.h"
#include "drivers/button/button.hpp"
#include "drivers/servo/servo.hpp"
#include "hexapod.hpp"
#include "leg.hpp"
#include "libraries/servo2040/servo2040.hpp"
#include "libraries/plasma2040/plasma2040.hpp"
#include "pico/stdlib.h"

using namespace plasma;
using namespace servo;

WS2812 led_bar(servo2040::NUM_LEDS, pio1, 0, servo2040::LED_DATA);
Button user_sw(servo2040::USER_SW);

void setUpLEDs() {
    led_bar.start();
    float offset = 0.0f;
    for(auto i = 0u; i < servo2040::NUM_LEDS; i++) {
      float hue = (float)i / (float)servo2040::NUM_LEDS;
      led_bar.set_hsv(i, hue + offset, 1.0f, BRIGHTNESS);
    }
}

int main() {
    stdio_init_all();
    setUpLEDs();
    
    Hexapod *hexapod = new Hexapod();
    hexapod->enableServos();
    hexapod->moveAllToHome();
    hexapod->moveLeftSideForward();
    sleep_ms(2000);
    hexapod->moveRightSideForward();

    while(!user_sw.raw()) {

    }

    led_bar.clear();
    delete hexapod;
}