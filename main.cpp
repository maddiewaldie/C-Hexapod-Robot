#include "pico/stdlib.h"
#include "leg.hpp"
#include "constants.h"
#include "drivers/servo/servo.hpp"
#include "drivers/servo/servo.hpp"

#include "libraries/servo2040/servo2040.hpp"
#include "libraries/plasma2040/plasma2040.hpp"
#include "drivers/button/button.hpp"

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

    // test that a servo & servo cluster run independently
    // Leg *leg1 = new Leg(LEFT_FRONT_DISTAL, LEFT_FRONT_MID, LEFT_FRONT_PROXIMAL, LEFT_FRONT);
    // leg1-> enableServos();
    // leg1->moveLegToHome();
    // sleep_ms(2000);
    // leg1->moveJoint(leg1->distalServo, 90);
    // sleep_ms(2000);
    // leg1->moveJoint(leg1->midServo, 45);

    // ServoCluster servo18 = ServoCluster(pio0, 0, servo2040::SERVO_17, 1);
    // servo18.init();
    // servo18.enable_all();
    // sleep_ms(2000);
    // servo18.all_to_value(90);
    // servo18.disable_all();

    led_bar.clear();
}