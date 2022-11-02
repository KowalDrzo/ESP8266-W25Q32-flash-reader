#include <Arduino.h>
#include <SPIFlash.h>

uint16_t expectedDeviceID=0xEF30;
SPIFlash flash(15, 0xEF30);

#define BUFF_SIZE 32768

uint8_t buff[BUFF_SIZE];

void setup() {

    delay(2000);

    Serial.begin(74880);
    Serial.println("Start");

    if (flash.initialize()) {
        Serial.println("Init OK!");
    }

    Serial.println(flash.readDeviceId(), HEX);

    for (int32_t i = 0; i < 4194304; i += BUFF_SIZE) {
        flash.readBytes(i, buff, BUFF_SIZE);
        Serial.write(buff, BUFF_SIZE);
        delay(100);
    }
}

void loop() {

    delay(1000);
    Serial.println("Kupa");
}