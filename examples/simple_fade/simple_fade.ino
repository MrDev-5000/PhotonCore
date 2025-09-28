/**
 * @brief Examples sketch for fading a LED with regular intervals
 * @param duration in desired unit
 * 
 * This example sketch demonstrates how to use the PhotonCore library to fade 
 * a LED on and off at regular intervals.
 * 
 * The duration can be specified in minutes, seconds, milliseconds or microseconds
 * Uncomment the desired line in the loop() function to use a specific time unit.
 * 
 * Ensure that the Chosen pin supports PWM.
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
  MyLed.setPin(myLedPin);     ///< Set pin 5 as MyLed Output (pin must support PWM)

}

void loop() {
  /**
  * @brief Fades the LED on and off at regular intervals.
  * You can use any of the following formats.
  * Only one of the following formats should be used at a time, Uncomment the desired line.
  */ 

  //MyLed.fade(durationInMins, MINUTE);            ///< fade LED on and off, every 1/60 minute (1 second)

  //MyLed.fade(durationInSec, SECOND);             ///< fade LED on and off, every 1 second

  MyLed.fade(durationInMillisec);                  ///< fade LED on and off, every 1000 ms (1 second)

  //MyLed.fade(durationInMicrosec, MICROSECOND);   ///< fade LED on and off, every 1,000,000 us (1 second)

}
