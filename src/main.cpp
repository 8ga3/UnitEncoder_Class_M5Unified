// M5 Unit Encoder Class for M5Unified
// Copyright (c) @8ga3 All rights reserved.
// 2023/10/21

#include <M5Unified.h>
#include <UnitEncoder_Class.hpp>

m5::UnitEncoder_Class UnitEncoder;
signed short int last_value = 0;
bool btn_up = true;

void setup()
{
  auto cfg = M5.config();
  cfg.serial_baudrate = 115200;
  M5.begin(cfg);

  UnitEncoder.begin();
}

void loop()
{
  signed short int encoder_value = UnitEncoder.getEncoderValue();
  bool btn_stauts                = UnitEncoder.getButtonStatus();

  if (last_value != encoder_value) {
    if (last_value > encoder_value) {
      UnitEncoder.setLEDColor(1, 0x000011);
    }
    else {
      UnitEncoder.setLEDColor(2, 0x111100);
    }
    last_value = encoder_value;
    Serial.printf("value: %d\n", encoder_value);
  }
  else {
    UnitEncoder.setLEDColor(0, 0x001100);
  }

  if (!btn_stauts) {
    UnitEncoder.setLEDColor(0, 0xC800FF);

    if (btn_up) {
      Serial.printf("push button\n");
    }
    btn_up = false;
  }
  else {
    btn_up = true;
  }

  M5.delay(30);
}
