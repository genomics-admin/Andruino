/* Copyright 2012 Google Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * Project home page: http://code.google.com/p/usb-serial-for-android/
 */

// Sample Arduino sketch for use with usb-serial-for-android.
// Prints an ever-increasing counter, and writes back anything
// it receives.

const int ledPin = 2;      // the pin that the LED is attached to
String serialA;

static int counter = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(115200); //baud rate - make sure it matches that of the module you got:
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.print("Tick #");
  Serial.print(counter++, DEC);
  Serial.print('\n');

  if (Serial.peek() != -1) {
    Serial.print('\n');
    Serial.print("Read: ");
    do {
      serialA = Serial.readStringUntil('\n');
      Serial.print(serialA);
      //Based on SerialA value execute
      if (serialA == "ON") {
          Serial.print("\nCommand: " + serialA);
          digitalWrite(ledPin, HIGH);
          break;
      }
      if (serialA == "OFF") {
          Serial.print("\nCommand: " + serialA);
          digitalWrite(ledPin, LOW);
          break;
      }
    } while (Serial.peek() != -1);
    Serial.print('\n');
  }
  delay(1000);
}
