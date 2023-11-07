// M5 Unit Encoder Class for M5Unified
// Copyright (c) @8ga3 All rights reserved.

#ifndef __M5_UNIT_ENCODER_CLASS_H__
#define __M5_UNIT_ENCODER_CLASS_H__

#include "utility/I2C_Class.hpp"

namespace m5
{
  class UnitEncoder_Class : public I2C_Device
  {
    public:

      enum encoder_mode_t
      { mode_pulse = 0,
        mode_ab = 1,
      };

      static constexpr std::uint8_t DEFAULT_ADDRESS = 0x40;

      UnitEncoder_Class(std::uint8_t i2c_addr = DEFAULT_ADDRESS, std::uint32_t freq = 200000, I2C_Class* i2c = &Ex_I2C)
      : I2C_Device ( i2c_addr, freq, i2c )
      {}

      bool begin(void);

      void setEncoderMode(encoder_mode_t mode);
      signed short int getEncoderValue();
      bool setEncoderValue(signed short int value);
      bool getButtonStatus();
      void setLEDColor(uint8_t index, uint32_t color);
      bool resetCounter();
  };
}

#endif
