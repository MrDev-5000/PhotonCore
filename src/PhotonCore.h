#pragma once
#ifndef PHOTONCORE_H
#define PHOTONCORE_H

#include <Arduino.h>
#include <TimerKernel.h>


class PhotonCore {
private:
    enum State {
        ACTIVE,
        INACTIVE
    };

    int LED;

    TimerKernel fadeTimer;
    TimerKernel blinkTimer;

    const int pwmResolution;
    const int maxBrightness;
    const int minBrightness;
    double offDuration;
    double onDuration;
    double duration;
    State ledState;
    int brightness;
    int fadeAmount;

public:
    PhotonCore(int resolution = 255);
    void setPin(int led);

    void turnOff();
    void fadeOff(double offDuration, TimeUnit unit = MILLISECOND);
    bool isOff() const;

    void turnOn(int brightness = -1);
    void fadeOn(double onDuration, TimeUnit unit = MILLISECOND);
    bool isOn(int brightness = 1) const;

    void fade(double duration, TimeUnit unit = MILLISECOND);
    void fade(double onDuration, double offDuration, TimeUnit onUnit = MILLISECOND, TimeUnit offUnit = MILLISECOND);
    void blink(double duration, TimeUnit unit = MILLISECOND);
    void blink(double onDuration, double offDuration, TimeUnit onUnit = MILLISECOND, TimeUnit offUnit = MILLISECOND);

private:
    void updateLedStatusInfo(int brightness);

};

#endif // !PHOTON_CORE_H
