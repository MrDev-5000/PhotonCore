
# 🔅 PhotonCore 🔆

> PhotonCore is an powerful, non-blocking LED control library for Arduino.

---

## 🚀 Features

- Non-Blocking, No `delay()`, for best code responsiveness
- Simple and intuitive API
- Supports Floating Point durations for ease of use and percise timing
- Support for multiple time units (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`)

## 📦 Dependencies

- [TimerKernel](https://github.com/MrDev-5000/TimerKernel) - Make sure to install this library before using `PhotonCore`.

## ⚙️ Installation

To install this library:

1. **Download ZIP**  
   Click the green `Code` button on this repository page, then select "Download ZIP".

2. **Open Arduino IDE**  
   Launch the Arduino IDE on your computer.

3. **Install ZIP Library**  
   - Go to **Sketch > Include Library > Add .ZIP Library...**
   - Navigate to where you downloaded the ZIP file.
   - Select the ZIP file and click **Open**.

4. **Done!**  
   The library is now installed and ready to use. You can find examples for this library in **File > Examples > TimerKernel**.

>**Note:**
>
> - Do **not** unzip the downloaded file before installing.  
> - If you are updating an existing library, delete the old version from your `libraries` folder first.

## 🛠️ Usage

Traditionally, to blink an LED we use `delay()` and `digitalWrite()`:

```cpp
#define myLed 9

void setup() {
  pinMode(myLed, OUTPUT);
}

void loop() {
  digitalWrite(myLed, HIGH);
  delay(1000);
  digitalWrite(myled, LOW);
  delay(1000)
}
```

However, this approach is **not optimal**, especially if you want the code to perform other tasks while blinking the LED.
To fix this, you would typically use`millis()` and `digitalWrite()` Instead:

```cpp
#define myLed 9

unsigned long previousMillis = 0;
unsigned long interval = 1000;
bool state = false;

void setup() {
  pinMode(myLed, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = millis();

    state = !state;
  }
  digitalWrite(myLed, state);
}
```

However, this approach can be confusing and cumbersome to manage — especially for beginners.
With **PhotonCore** the same functionality can be achieved in a cleaner and more intuitive way:

```cpp
#include <PhotonCore.h>

constexpr myLedPin = 9;

PhotonCore myLed;

void setup() {
  myLed.setPin(myLedPin);
}

void loop() {
  myled.blink(1000);
}
```

## 📖 Examples

- [simple_blink](examples/simple_blink/simple_blink.ino) - Demonstrates how to blink an LED with regular time intervals.
- [advanced_blink](examples/advanced_blink/advanced_blink.ino) - Demonstrates how to blink an LED with different on/off intervals.

## 📚 API Reference

### `PhotonCore()`

```cpp
PhotonCore(int resolution = 255);
```

Creates a new `PhotonCore` object and initializes it.

| Parameter        | Type  | Description                  |
| :--------------- | :---- | :--------------------------- |
| `resolution`     | `int` | PWM resolution (default 255) |

**Returns:**

- Nothing.

---

### `setPin()`

```cpp
  void setPin();
```

Sets the LED pin.

| Parameter | Type  | Description       |
| :-------- | :---- | :---------------- |
| `led`     | `int` | Pin number to set |

**Returns:**

- Nothing.

---

### `turnOn()`

```cpp
  void turnOn(int brightness = maxBrightness);
```

Turns LED on at full brightness by default. if a brightness value is provided, the LED will be set to that brightness level

| Parameter    | Type  | Description                            |
| :--------    | :---- | :------------------------------------- |
| `brightness` | `int` | brightness of led (0 to maxResolution) |

**Returns:**

- Nothing.

---

### `turnOff()`

```cpp
  void turnOff();
```

Turns the LED off.

**Returns:**

- Nothing.

---

### `blink()`

```cpp
  void blink(double duration, TimeUnit unit = MILLISECOND);
```

Blinks the Led ON and OFF with regular ON/OFF intervals.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Time interval in desired unit                                |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `blink()` - Overload

```cpp
  void blink(double onDuration, double offDuration, TimeUnit onUnit = MILLISECOND, TimeUnit offUnit = MILLISECOND);
```

Blinks the led with different ON/OFF intervals.

| Parameter     | Type     | Description                                                                    |
| :------------ | :------- | :----------------------------------------------------------------------------- |
| `onDuration`  | `double` | Duration the led stays ON in desired unit                                      |
| `offDuration` | `double` | Duration the led stays OFF in desired unit                                     |
| `onUnit`      | `enum`   | Time unit for `onDuration` (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`)  |
| `offUnit`     | `enum`   | Time unit for `offDuration` (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `fadeOn()`

```cpp
  void fadeOn(double duration, TimeUnit unit = MILLISECOND);
```

Fades the LED ON over the given duration.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Fade ON Duration in desired unit                             |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `fadeOff()`

```cpp
  void fadeOff(double duration, TimeUnit unit = MILLISECOND);
```

Fades the LED OFF over the given duration.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Fade OFF Duration in desired unit                            |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `fade()`

```cpp
  void fade(double duration, TimeUnit unit = MILLISECOND);
```

Fades the led ON and OFF with regular durations.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Duration for each fade ON/OFF cycle in desired unit          |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `fade()` - Overload

```cpp
  void fade(double onDuration, double offDuration, TimeUnit onUnit = MILLISECOND, TimeUnit offUnit = MILLISECOND);
```

fades led ON and OFF with different durations.

| Parameter     | Type     | Description                                                                    |
| :------------ | :------- | :----------------------------------------------------------------------------- |
| `onDuration`  | `double` | Duration to fade ON led in desired unit                                        |
| `offDuration` | `double` | Duration to fade OFF led in desired unit                                       |
| `onUnit`      | `enum`   | Time unit for `onDuration` (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`)  |
| `offUnit`     | `enum`   | Time unit for `offDuration` (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- Nothing.

---

### `isOn()`

```cpp
  bool isOn(int brightness = 1);
```

Checks whether the LED is currently OFF.
By default, it returns `true` if the LED brightness is greater than 0.
If a brightness value is provided, it returns `true` if the LED’s brightness 
is greater than or equal to the specified value.

| Parameter    | Type     | Description                    |
| :----------- | :------- | :----------------------------- |
| `brightness` | `int`    | brightness threshold           |

**Returns:**

- `true` if LED is ON (depending on the condition), else `false`

---

### `isOff()`

```cpp
  bool isOff();
```

checks if the LED is currently OFF.

**Returns:**

- `true` if OFF, otherwise `false`

>**Note:**
>
> - By Default, all durations are interpreted in millisecond

## 📜 License

- This project is licensed under the [MIT License](LICENSE).
