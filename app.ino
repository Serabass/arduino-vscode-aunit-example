#line 2 "basic.ino"

// #define TESTING 1

// Adapted from:
// https://github.com/mmurdoch/arduinounit/blob/master/examples/basic/basic.ino

#ifdef TESTING
#include <AUnit.h>

test(correct)
{
  int x = 1;
  assertEqual(x, 1);
}

test(incorrect)
{
  int x = 1;
  assertNotEqual(x, 1);
}

#endif

//----------------------------------------------------------------------------
// setup() and loop()
//----------------------------------------------------------------------------

void setup()
{
  delay(1000);          // wait for stability on some boards to prevent garbage Serial
  Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
  while (!Serial)
    ; // for the Arduino Leonardo/Micro only

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
#ifdef TESTING
  aunit::TestRunner::run();
#endif

  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
}