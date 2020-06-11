/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

const PinDescription g_APinDescription[] = {

/*
 +------------+-----------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  INFOLOG Board pin    |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                       |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                       |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-----------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | 32768Hz Crystal       |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 0          |                       |  PA00  | XIN32           |   00   |     |     |     |     |         |   1/00  | TCC2/0 |        |          |          |
 | 1          |                       |  PA01  | XOUT32          |   01   |     |     |     |     |         |   1/01  | TCC2/1 |        |          |          |
 +------------+-----------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA,  0, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //0 PA00 XIN32 
  { PORTA,  1, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //1 PA01 XOUT32
/*
ANALOQUE INPITS
 +------------+-------------------------+--------+------------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |  INFOLOG Board pin      |  PIN   | Notes                  | Peri.A  |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                        |   EIC   | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                        |(EXTINT) |(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+------------------------+------- -+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 4          | VOLTAGE_3V3_IN          |  PA03  | ADC INPUT              | 3       | 1   |     | Y1  |     |         |         |        |        |          |          |
 | 16         | VOLTAGE_4V2_IN          |  PA11  | ADC INPUT              | 11      | 19  |     | X3  |     | 0/03    | 2/03    | TCC1/1 | TCC0/3 | I2S/FS0  | GCLK_IO5 |
 | 3          | VOLTAGE_12V_AFTER_FUSE  |  PA02  | ADC INPUT              | 2       | 0   |     | Y0  | VOUT|         |         |        |        |          |          |
 | 8          | VOLTAGE_12V_BEFORE_FUSE |  PB09  | ADC INPUT              | 9       | 3   |     | Y15 |     |         | 4/01    | TCC4/1 |        |          |          |
 |            |                         |        |                        |         |     |     |     |     |         |         |        |        |          |          |
 +------------+-------------------------+--------+------------------------+------- -+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA,  3, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel1,    NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //2 PA03 VOLTAGE_3V3_IN
  { PORTA, 11, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel19,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //3 PA11 VOLTAGE_4V2_IN
  { PORTA,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel0,    NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //4 PA02 VOLTAGE_12V_AFTER_FUSE
  { PORTB,  9, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel3,    NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //5 PB09 VOLTAGE_12V_BEFORE_FUSE
/*
DIGITAL OUTPUTS
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |     10     |  MODEM_POWER_KEY_OUT    |  PA10  |  DIGITAL OUTPUT     |   10   |  18 |     |  X2 |     |  0/02   |   2/02  | TCC1/0 | TCC0/2 | I2S/SCK0 | GCLK_IO4 |
 |     20     |  MODEM_RTS_OUT          |  PB11  |  DIGITAL OUTPUT     |   11   |     |     |     |     |         |   4/03  | TCC5/1 | TCC0/5 | I2S/SCK1 | GCLK_IO5 |
 |     29     |  ACC_CS_OUT             |  PA20  |  DIGITAL OUTPUT     |    4   |     |     |  X8 |     |  5/02   |   3/02  | TC7/0  | TCC0/6 | I2S/SCK0 | GCLK_IO4 |
 |     31     |  ACC_VDD_OUT            |  PA22  |  DIGITAL OUTPUT     |    6   |     |     | X10 |     |  3/00   |   5/00  | TC4/0  | TCC0/4 |          | GCLK_IO6 |
 |     24     |  MODEM_DTR_OUT          |  PA15  |  DIGITAL OUTPUT     |   15   |     |     |     |     |  2/03   |   4/03  | TC3/1  | TCC0/5 |          | GCLK_IO1 |
 |     39     |  BUZZER_OUT             |  PA27  |  DIGITAL OUTPUT     |  *15   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 |     41     |  CPU_LED_OUT            |  PA28  |  DIGITAL OUTPUT     |    8   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
  { PORTA, 10, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE  },  //6 PA10  MODEM_POWER_KEY_OUT
  { PORTB, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE  },  //7 PB11 MODEM_RTS_OUT
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE   },  //8 PA20 ACC_CS_OUT
  { PORTA, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE   },  //9 PA22 ACC_VDD_OUT
  { PORTA, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE  },  //10 PA15 MODEM_DTR_OUT
  { PORTA, 27, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE  },  //11 PA27 BUZZER_OUT
  { PORTA, 28, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE   },  //12 PA28 CPU_LED_OUT
/*
DIGITAL INPUTS
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |     19     | MODEM_CTS_IN            |  PB10  |  DIGITAL INPUT      |   10   |     |     |     |     |         |   4/02  |  TC5/0 | TCC0/4 | I2S/MCK1 | GCLK_IO4 |
 |     13     | GPS_1PPS_IN             |  PA08  |  DIGITAL INPUT      |  NMI   |  16 |     |  X0 |     |   0/00  |   2/00  | TCC0/0 | TCC1/2 | 12S/SD1  |          |
 |     14     | MODEM_NET_LIGHT_IN      |  PA09  |  DIGITAL INPUT      |    9   |  17 |     |  X1 |     |   0/01  |   2/01  | TCC0/1 | TCC1/3 | I2S/MCK0 |          |
 |     38     | POWER_AC_OK_IN          |  PB23  |  DIGITAL INPUT      |    7   |     |     |     |     |         |   5/03  |  TC7/1 |        |          | GCLK_IO1 |
 |     37     | POWER_CHG_OK_IN         |  PB22  |  DIGITAL INPUT      |        |     |     |     |     |         |   5/02  |  TC7/0 |        |          | GCLK_IO0 |
 |      7     | MODEM_STATUS_IN         |  PB08  |  DIGITAL INPUT      |    8   |   2 |     | Y14 |     |         |   4/00  |  TC4/0 |        |          |          |
 |     10     | MODEM_DCD_IN            |  PA05  |  DIGITAL INPUT      |    5   |   5 |  1  |  Y3 |     |         |   0/01  | TCC0/1 |        |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTB, 10, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //13 PB10 MODEM_CTS_IN
  { PORTA,  8, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //14 PA08 GPS_1PPS_IN
  { PORTA,  9, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //15 PA09 MODEM_NET_LIGHT_IN
  { PORTB, 23, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //16 PB23 POWER_AC_OK_IN
  { PORTB, 22, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //17 PB22 POWER_CHG_OK_IN
  { PORTB,  8, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //18 PB08 MODEM_STATUS_IN
  { PORTA,  5, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10    }, //19 PA05 MODEM_DCD_IN
/*
INTERUPT INPUTS
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |    30      |   ACC_INT2_IN           |  PA21  |  DIGITAL INTERRUPT  |    5   |     |     |  X9 |     |  5/03   |   3/03  |  TC7/1 | TCC0/7 |  I2S/FS0 | GCLK_IO5 |
 |     9      |   ACC_INT1_IN           |  PA04  |  DIGITAL INTERRUPT  |    4   |   4 |   0 |  Y2 |     |         |   0/00  | TCC0/0 |        |          |          |
 |    12      |   MAGNETIS_SW_IN        |  PA07  |  DIGITAL INTERRUPT  |    7   |   7 |   3 |  Y5 |     |         |   0/03  | TCC1/1 |        |  I2S/SD0 |          |
 |    23      |   MODEM_RI_IN           |  PA14  |  DIGITAL INTERRUPT  |   14   |     |     |     |     |  2/02   |   4/02  |  TC3/0 | TCC0/4 |          | GCLK_IO0 |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA,  21, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5    }, //20 PA21 ACC_INT2_IN
  { PORTA,   4, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4    }, //21 PA04 ACC_INT1_IN
  { PORTA,   7, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7    }, //22 PA07 MAGNETIS_SW_IN
  { PORTA,  14, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14   }, //23 PA14 MODEM_RI_IN
/*
MODEM SERIAL
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |    21      |   MODEM_TX              |  PA12  |  SERIAL COM CPU TX  |   12   |     |     |     |     |  2/00   |   4/00  | TCC2/0 | TCC0/6 |          |  AC/CMP0 |
 |    22      |   MODEM_RX              |  PA13  |  SERIAL COM CPU RX  |   13   |     |     |     |     |  2/01   |   4/01  | TCC2/1 | TCC0/7 |          |  AC/CMP1 |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 }, //24 PA12 MODEM_TX CPU TX
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, //25 PA13 MODEM_RX CPU RX
/*
SPI
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |     25     |   MOSI                  |  PA16  |    PIN_SPI_MOSI     |   0    |     |     | X4  |     |  1/00   |  3/00   | TCC2/0 | TCC0/6 |          | GCLK_IO2 |
 |     26     |   SCL                   |  PA17  |    PIN_SPI_SCL      |   1    |     |     | X5  |     |  1/01   |  3/01   | TCC2/1 | TCC0/7 |          | GCLK_IO3 |
 |     28     |   MISO                  |  PA19  |    PIN_SPI_MISO     |   3    |     |     | X7  |     |  1/03   |  3/03   |  TC3/1 | TCC0/3 |  I2S/SD0 | AC/CMP1  |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA, 16, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //26 PA16 MOSI
  { PORTA, 17, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //27 PA17 SCL
  { PORTA, 19, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //28 PA19 MISO
/*
EXTRAS
 +------------+-------------------------+--------+---------------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | CPU Pin    |INFOLOG Board pin        |  PIN   | Notes               | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                         |        |                     |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                         |        |                     |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |    33      |   PIN_USB_DM            |  PA24  |     USB DM          |   12   |     |     |     |     |  3/02   |   5/02  | TC5/0  | TCC1/2 |  USB/DM  |          |
 |    34      |   PIN_USB_DP            |  PA25  |     USB DP          |   13   |     |     |     |     |  3/03   |   5/03  | TC5/1  | TCC1/3 |  USB/DP  |          |
 |    27      |   PIN_USB_HOST_ENABLE   |  PA18  |     USB ID          |    2   |     |     |  X6 |     |  1/02   |   3/02  | TC3/0  | TCC0/2 |          | AC/CMP0  |
 |     1      |   XIN32                 |  PA00  |     32K XTL IN      |    0   |     |     |     |     |         |   1/00  | TCC2/0 |        |          |          |
 |     2      |   XOUT32                |  PA01  |     32K XTL OUT     |    1   |     |     |     |     |         |   1/01  | TCC2/1 |        |          |          |
 +------------+-------------------------+--------+---------------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA, 24, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //29 PA24 PIN_USB_DM
  { PORTA, 25, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //30 PA25 PIN_USB_DP
  { PORTA, 18, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //31 PA18 PIN_USB_HOST_ENABLE

  { PORTA,  6, PIO_DIGITAL, (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //32 PA06 NOT USED 1
  { PORTA, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //33 PA23 NOT USED 2
  { PORTB,  2, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //34 PB02 NOT USED 3
  { PORTB,  3, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //35 PB03 NOT USED 4
};

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM + TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 };

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);
SERCOM sercom4(SERCOM4);
SERCOM sercom5(SERCOM5);

// Serial1
Uart Serial1(&sercom2, MODEM_RX, MODEM_TX, SERCOM_RX_PAD_1, UART_TX_PAD_0);

void SERCOM5_Handler()
  {
  Serial1.IrqHandler();
  }

