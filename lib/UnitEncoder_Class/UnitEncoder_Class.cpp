// M5 Unit Encoder Class for M5Unified
// Copyright (c) @8ga3 All rights reserved.
// 2023/10/21

#include "UnitEncoder_Class.hpp"

#if __has_include(<esp_log.h>)
#include <esp_log.h>
#endif

namespace m5
{
  static constexpr std::uint8_t REG_MODE    = 0x00;
  static constexpr std::uint8_t REG_ENCODER = 0x10;
  static constexpr std::uint8_t REG_BUTTON  = 0x20;
  static constexpr std::uint8_t REG_RGB_LED = 0x30;
  static constexpr std::uint8_t REG_RESET   = 0x40;

  bool UnitEncoder_Class::begin(void)
  {
    // std::uint8_t data;
    // _init = readRegister(REG_BUTTON, &data, 1);
    _init = resetCounter();
    if (_init)
    {
#if defined (ESP_LOGV)
      ESP_LOGV("Unit_Encoder", "found");
#endif
    }
    return _init;
  }

  // note: firmware v1.1 or lator
  void UnitEncoder_Class::setEncoderMode(encoder_mode_t mode)
  {
    writeRegister8(REG_MODE, (std::uint8_t)mode);
  }

  signed short int UnitEncoder_Class::getEncoderValue()
  {
    std::uint8_t data[2];
    readRegister(REG_ENCODER, data, 2);
    signed short int value = (signed short int)((data[0]) | (data[1]) << 8);
    return value;
  }

  // note: firmware v1.1 or lator
  bool UnitEncoder_Class::setEncoderValue(signed short int value)
  {
    std::uint8_t data[2];
    data[0] = (std::uint8_t)(value & 0xff);
    data[1] = (std::uint8_t)((value >> 8) & 0xff);
    return writeRegister(REG_ENCODER, data, 2);
  }

  bool UnitEncoder_Class::getButtonStatus()
  {
    std::uint8_t data;
    readRegister(REG_BUTTON, &data, 1);
    return data;
  }

  void UnitEncoder_Class::setLEDColor(std::uint8_t index, std::uint32_t color)
  {
    std::uint8_t data[4];
    data[3] = color & 0xff;
    data[2] = (color >> 8) & 0xff;
    data[1] = (color >> 16) & 0xff;
    data[0] = index;
    writeRegister(REG_RGB_LED, data, 4);
  }

  // note: firmware v1.1 or lator
  bool UnitEncoder_Class::resetCounter()
  {
    return writeRegister8(REG_RESET, 1);
  }
}
