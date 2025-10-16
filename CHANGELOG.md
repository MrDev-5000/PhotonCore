# Change log

## v2.0.3

- Fix: Add checks to ensure the board supports setting `analogWriteResolution`.
- Fix: Resolve incorrect PWM behavior on unsupported boards.

---

## v2.0.2

- Fix: Add `double stepDuration = offDuration / static_cast<double>(pwmResolution);` to both `fadeOff()` and `fadeOn()`.
- Fix: Replace `onDuration`/`offDuration` in `fadeOn()`/`fadeOff()` with `stepDuration`.

---

## v2.0.1

>### ⚠️ BREAKING CHANGES

- Refactor: replaced both function parameters (`onDuration, offDuration, unit`) for both `blink()` and `fade()` with new parameters(`onDuration, offDuration, onUnit, offUnit`).

---
 
## v1.0.1

- Fix: Add `if (brightness == -1) brightness = maxBrightness;` to `turnOn()`.
- Fix: Removed redundant `if (brightness == -1) brightness = maxBrightness;` from `isOn()`.
