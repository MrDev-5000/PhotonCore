/**
 * @brief Examples sketch for blinking a LED with irregular time intervals
 * @param onDuration represents how long LED stays on in the desired unit.
 * @param offDuration represents how long LED stays off in the desired unit.
 * 
 * This example sketch demonstrates how to use the PhotonCore library to blink 
 * a LED with different on and off durations.
 * 
 * The duration can be specified in minutes, seconds, milliseconds or microseconds
 * Uncomment the desired line in the loop() function to use a specific time unit.
 * 
 * Note: For now `blink()` works on any digital pin.
 * However, to ensure compatibility with future versions it is recommended to 
 * use a PWM-capable pin.
 */

#include <PhotonCore.h>

constexpr int myLedPin = 5;

PhotonCore MyLed;

// On duration: 200 ms in different formats
const double onDurationInMins = 200/60000;
const double onDurationInSec = 200/1000;
const long onDurationInMillisec = 200;   
const long onDurationInMicrosec = 200000;

// Off duration: 2 sec in different formats
const double offDurationInMins = 2.0/60.0;
const long offDurationInSec = 2;
const long offDurationInMillisec = 2000;   
const long offDurationInMicrosec = 2000000;

void setup() {
  MyLed.setPin(myLedPin);     ///< Set pin 5 as MyLed Output (Choose a PWM pin for future compatibility).

}

void loop() {
  /**
  * @brief toggle LED state with specified on/off durations.
  * You can use any of the following formats.
  * Only one of the following formats should be used at a time, Uncomment the desired line.
  */ 

  // MyLed.blink(onDurationInMins, offDurationInMins, MINUTE, MINUTE);                     ///< Toggle LED (on for 1/300 sec (200 ms), off for 1/30 mi (2 sec))

  // MyLed.blink(onDurationInSec, offDurationInSec, SECOND, SECOND);                       ///< Toggle LED (on for 1/5 sec (200 ms), off for 2 sec)
 
  MyLed.blink(onDurationInMillisec, offDurationInMillisec);                                ///< Toggle LED (on for 200 ms, off for 2000 ms (2 sec))

  // MyLed.blink(onDurationInMicrosec, offDurationInMicrosec, MICROSECOND, MICROSECOND);   ///< Toggle LED (on for 20,00,00 us (200 ms), off for 2,000,000 us (2 sec))

}