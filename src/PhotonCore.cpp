
#include "PhotonCore.h"
#include <TimerKernel.h>
#include <Arduino.h>

PhotonCore::PhotonCore(int resolution) :
    maxBrightness(resolution),
    minBrightness(0),
    offDuration(0),
    onDuration(0),
    duration(0),
    ledState(INACTIVE),
    brightness(minBrightness),
    fadeAmount(1) {}


void PhotonCore::setPin(int LED) {
    this->LED = LED;
    pinMode(LED, OUTPUT);
}


void PhotonCore::updateLedStatusInfo(int brightness) {
    this->brightness = brightness;
    this->ledState = (brightness != minBrightness && brightness <= maxBrightness) ? ACTIVE : INACTIVE;
}

void PhotonCore::turnOff() {
    analogWrite(LED, minBrightness);
    updateLedStatusInfo(minBrightness);
}


void PhotonCore::turnOn(int brightness) {
    if (brightness == -1) brightness = maxBrightness;
    brightness = constrain(brightness, minBrightness, maxBrightness);
    analogWrite(LED, brightness);
    updateLedStatusInfo(brightness);
}


bool PhotonCore::isOff() const {
    return (this->ledState == INACTIVE);
}

bool PhotonCore::isOn(int brightness) const {
    return (this->brightness >= brightness && brightness != 0 && this->ledState == ACTIVE);
}


void PhotonCore::fadeOff(double offDuration, TimeUnit unit) {
    this->offDuration = offDuration;

    if (this->brightness > minBrightness && fadeTimer.hasExpired(offDuration, unit)) {
        this->brightness -= this->fadeAmount;

        if (this->brightness <= minBrightness) updateLedStatusInfo(minBrightness);

        analogWrite(LED, this->brightness);
    }
}


void PhotonCore::fadeOn(double onDuration, TimeUnit unit) {
    this->onDuration = onDuration;

    if (this->brightness < maxBrightness && fadeTimer.hasExpired(onDuration, unit)) {
        this->brightness += this->fadeAmount;

        if (this->brightness >= maxBrightness) updateLedStatusInfo(maxBrightness);

        analogWrite(LED, this->brightness);
    }
}


void PhotonCore::fade(double onDuration, double offDuration, TimeUnit onUnit, TimeUnit offUnit) {
    this->onDuration = onDuration;
    this->offDuration = offDuration;

    if (ledState == INACTIVE) {
        fadeOn(onDuration, onUnit);
    }

    if (ledState == ACTIVE) {
        fadeOff(offDuration, offUnit);
    }
}


void PhotonCore::fade(double duration, TimeUnit unit) {
    this->duration = duration;

    fade(duration, duration, unit);
}


void PhotonCore::blink(double duration, TimeUnit unit) {
    this->duration = this->onDuration = this->offDuration = duration;

    int toggleState = blinkTimer.toggleState(duration, unit);

    digitalWrite(LED, toggleState);
    updateLedStatusInfo((toggleState == HIGH) ? maxBrightness : minBrightness);
}


void PhotonCore::blink(double onDuration, double offDuration, TimeUnit onUnit, TimeUnit offUnit) {
    this->onDuration = onDuration;
    this->offDuration = offDuration;

    if (onDuration == offDuration && onUnit == offUnit) {
        this->duration = onDuration;
        blink(onDuration, onUnit);
        return;
    }

    if (ledState == INACTIVE && blinkTimer.hasExpired(onDuration, onUnit)) {
        digitalWrite(LED, HIGH);
        updateLedStatusInfo(maxBrightness);
    }

    if (ledState == ACTIVE && blinkTimer.hasExpired(offDuration, offUnit)) {
        digitalWrite(LED, LOW);
        updateLedStatusInfo(minBrightness);
    }
}

