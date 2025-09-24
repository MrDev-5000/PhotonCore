/**
 * @brief Examples sketch for blinking a LED with regular intervals
 * @param duration in desired unit
 * 
 * This example sketch demonstrates how to use the PhotonCore library to blink 
 * a LED with regular on/off intervals.
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

// 1 sec duration in different formats
const double durationInMins = 1.0/60.0;
const long durationInSec = 1;
const long durationInMillisec = 1000;   
const long durationInMicrosec = 1000000;

void setup() {
  MyLed.setPin(myLedPin);     ///< Set pin 5 as MyLed Output (Choose a PWM pin for future compatibility)

}

void loop() {
  /**
  * @brief change the state of LED every second
  * You can use any of the following formats
  * Only one of the following formats should be used at a time, Uncomment the desired line
  */ 

  //MyLed.blink(durationInMins, MINUTE);     ///< Toggle LED state every 1/60 minuteo (1 second)

  //MyLed.blink(durationInSec, SECOND);     ///< Toggle LED state of led every 1 second

  MyLed.blink(durationInMillisec);     ///< Toggle LED state every 1000 ms (1 second)

  //MyLed.blink(durationInMicrosec, MICROSECOND);     ///< Toggle LED state every 1,000,000 us (1 second)

}
