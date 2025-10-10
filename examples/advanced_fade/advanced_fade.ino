/**
 * @brief Examples sketch for fading a LED on and off with irregular intervals
 * @param onDuration represents how long it takes for the LED to fade on to max brightness in the desired unit.
 * @param offDuration represents how long it takes for the LED to fade off in the desired unit.
 * 
 * This example sketch demonstrates how to use the PhotonCore library to fade 
 * a LED on and off with differnt time durations.
 * 
 * The duration can be specified in minutes, seconds, milliseconds or microseconds
 * Uncomment the desired line in the loop() function to use a specific time unit.
 * 
 * Ensure that the Chosen pin supports PWM.
 */

#include <PhotonCore.h>

constexpr int myLedPin = 5;

PhotonCore MyLed;

// fade on duration: 200 ms in different formats
const double onDurationInMins = 200/60000;
const double onDurationInSec = 200/1000;
const long onDurationInMillisec = 200;   
const long onDurationInMicrosec = 200000;

// fade off duration: 2 sec in different formats
const double offDurationInMins = 2.0/60.0;
const long offDurationInSec = 2;
const long offDurationInMillisec = 2000;   
const long offDurationInMicrosec = 2000000;

void setup() {
  MyLed.setPin(myLedPin);     ///< Set pin 5 as MyLed Output (pin must support PWM).

}

void loop() {
  /**
  * @brief fade the LED on and off at specified on/off durations.
  * You can use any of the following formats.
  * Only one of the following formats should be used at a time, Uncomment the desired line.
  */ 

  MyLed.fade(onDurationInMins, offDurationInMins, MINUTE, MINUTE);                     ///< fade LED on and off, (fade on for 1/300 sec (200 ms), fade off for 1/30 mi (2 sec))

  MyLed.fade(onDurationInSec, offDurationInSec, SECOND, SECOND);                       ///< fade LED on and off, (fade on for 1/5 sec (200 ms), fade off for 2 sec)
 
  MyLed.fade(onDurationInMillisec, offDurationInMillisec);                             ///< fade LED on and off, (fade on for 200 ms, fade off for 2000 ms (2 sec))

  MyLed.fade(onDurationInMicrosec, offDurationInMicrosec, MICROSECOND, MICROSECOND);   ///< fade LED on and off, (fade on for 20,00,00 us (200 ms), fade off for 2,000,000 us (2 sec))

}