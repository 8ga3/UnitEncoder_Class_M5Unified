# M5StackのUnit EncoderをM5Unifiedと共に使うClass

Unit EncoderにFirmware V1.1を書き込むと、すべてのファンクションが使えます。
詳しくは[こちら](https://qiita.com/8ga3/items/ed60578a1d55e32bfc2b)

## I2Cレジスタマップ (Factory)

| OPERATION     | REG MAP | 0 | 1 | 2 | 3 |
|:--------------|:-------:|:--------|:--------|:-------|:--------|
| COUNTER (R)   | 0x01    | COUNTER VALUE<br>L | <br>H | |
| SWITCH (R)    | 0x02    | SWITCH<br>0 or 1 | | | |
| RGB (W)       | 0x03    | LED NUM<br>0, 1, 2 | R | G | B |

## I2Cレジスタマップ (Firmware V1.1)

| OPERATION     | REG MAP | 0 | 1 | 2 | 3 |
|:--------------|:-------:|:--------|:--------|:-------|:--------|
| MODE (W)      | 0x00    | 0=PULSE<br>1=AB | | | |
| COUNTER (R/W) | 0x01    | COUNTER VALUE<br>L | <br>H | |
| SWITCH (R)    | 0x02    | SWITCH<br>0 or 1 | | | |
| RGB (W)       | 0x03    | LED NUM<br>0, 1, 2 | R | G | B |
| RESET         | 0x04    | 1 >= RESET<br>COUNTER | | | |

RGBのLED NUMを0にすると、２つのLEDをまとめてセットできます。
