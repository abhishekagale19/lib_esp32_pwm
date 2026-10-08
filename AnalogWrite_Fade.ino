/*
 * AnalogWrite_Fade.ino - Task 1, step 3
 * Uses the ESP32PWM library: Arduino-style analogWrite on any pin.
 * GPIO2 = onboard LED. Optionally wire an LED (+220R) to GPIO4 to see
 * a second channel running at the same time.
 */
#include <ESP32PWM.h>

const int LED_PIN = 2;
const int LED2_PIN = 4;

void setup() {
  Serial.begin(115200);
  PWM32.setFrequency(5000);          // optional, default is 5 kHz / 8-bit
}

void loop() {
  for (int v = 0; v <= 255; v += 5) {
    PWM32.analogWrite(LED_PIN, v);           // fades up
    PWM32.analogWrite(LED2_PIN, 255 - v);    // fades down
    delay(20);
  }
  for (int v = 255; v >= 0; v -= 5) {
    PWM32.analogWrite(LED_PIN, v);
    PWM32.analogWrite(LED2_PIN, 255 - v);
    delay(20);
  }
  Serial.println("cycle done");
}
