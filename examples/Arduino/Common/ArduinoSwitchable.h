#ifndef _AQUARIUM_CONTROLLER_ARDUINO_COMMON_ARDUINO_SWITCHABLE_H_
#define _AQUARIUM_CONTROLLER_ARDUINO_COMMON_ARDUINO_SWITCHABLE_H_

#include "Enums/Switched.h"
#include "Abstract/AbstractSwitchable.h"
#include "Abstract/AbstractRunnable.h"

class ArduinoSwitchable :
        public AbstractRunnable,
        public AbstractSwitchable {

private:

    uint8_t const mcuPin;

public:

    explicit ArduinoSwitchable(uint8_t const mcuPin) : mcuPin(mcuPin) {}

    void setState(Switched const newState) override {
        if (AbstractSwitchable::state != newState) {

            AbstractSwitchable::state = newState;

            if (newState == Switched::On) {
                digitalWrite(mcuPin, HIGH); /* warn: Arduino specific */
            } else {
                digitalWrite(mcuPin, LOW); /* warn: Arduino specific */
            }
        }
    }

    void setup() override {
        pinMode(mcuPin, OUTPUT); /* warn: Arduino specific */
    };

    void loop() override {
        // pass
    }
};

#endif