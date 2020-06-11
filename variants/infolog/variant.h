#pragma once

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

#include <WVariant.h>

// General definitions
// -------------------

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (48000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (28u)
#define NUM_ANALOG_INPUTS    (4u)
#define NUM_ANALOG_OUTPUTS   (0u)

// Low-level pin register query macros
// -----------------------------------
#define digitalPinToPort(P)      (&(PORT->Group[g_APinDescription[P].ulPort]))
#define digitalPinToBitMask(P)   (1 << g_APinDescription[P].ulPin)
//#define analogInPinToBit(P)    ()
#define portOutputRegister(port) (&(port->OUT.reg))
#define portInputRegister(port)  (&(port->IN.reg))
#define portModeRegister(port)   (&(port->DIR.reg))
#define digitalPinHasPWM(P)      (g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER)


//Infolog opin numbering
static const uint8_t XIN32                     = (0u);  //PA00 XIN32 
static const uint8_t XOUT32                    = (1u);  //PA01 XOUT32
static const uint8_t VOLTAGE_3V3_IN            = (2u);  //PA03 VOLTAGE_3V3_IN
static const uint8_t VOLTAGE_4V2_IN            = (3u);  //PA11 VOLTAGE_4V2_IN
static const uint8_t VOLTAGE_12V_AFTER_FUSE    = (4u);  //PA02 VOLTAGE_12V_AFTER_FUSE
static const uint8_t VOLTAGE_12V_BEFORE_FUSE   = (5u);  //PB09 VOLTAGE_12V_BEFORE_FUSE
static const uint8_t MODEM_POWER_KEY_OUT       = (6u);  ///PA10  MODEM_POWER_KEY_OUT
static const uint8_t MODEM_RTS_OUT             = (7u);  //PB11 MODEM_RTS_OUT
static const uint8_t ACC_CS_OUT                = (8u);  //PA20 ACC_CS_OUT
static const uint8_t ACC_VDD_OUT               = (9u);  //PA22 ACC_VDD_OUT
static const uint8_t MODEM_DTR_OUT             = (10u);  //PA15 MODEM_DTR_OUT
static const uint8_t BUZZER_OUT                = (11u);  //PA27 BUZZER_OUT
static const uint8_t CPU_LED_OUT               = (12u);  //PA28 CPU_LED_OUT
static const uint8_t MODEM_CTS_IN              = (13u);  //PB10 MODEM_CTS_IN
static const uint8_t GPS_1PPS_IN               = (14u);  //PA08 GPS_1PPS_IN
static const uint8_t MODEM_NET_LIGHT_IN        = (15u);  //PA09 MODEM_NET_LIGHT_IN
static const uint8_t POWER_AC_OK_IN            = (16u);  //PB23 POWER_AC_OK_IN
static const uint8_t POWER_CHG_OK_IN           = (17u);  //PB22 POWER_CHG_OK_IN
static const uint8_t MODEM_STATUS_IN           = (18u);  //PB08 MODEM_STATUS_IN
static const uint8_t MODEM_DCD_IN              = (19u);  //PA05 MODEM_DCD_IN
static const uint8_t ACC_INT2_IN               = (20u);  //PA21 ACC_INT2_IN
static const uint8_t ACC_INT1_IN               = (21u);  //PA04 ACC_INT1_IN
static const uint8_t MAGNETIS_SW_IN            = (22u);  //PA07 MAGNETIS_SW_IN
static const uint8_t MODEM_RI_IN               = (23u);  //PA14 MODEM_RI_IN
static const uint8_t MODEM_TX                  = (24u);  //PA12 MODEM_TX CPU TX
static const uint8_t MODEM_RX                  = (25u);  //PA13 MODEM_RX CPU RX
static const uint8_t MOSI                      = (26u);  //PA16 ACC_SPI_MOSI
static const uint8_t SCK                       = (27u);  //PA17 ACC_SPI_SCL
static const uint8_t MISO                      = (28u);  //PA19 ACC_SPI_MISO
static const uint8_t PIN_USB_DM                = (29u);  //PA24 PIN_USB_DM
static const uint8_t PIN_USB_DP                = (30u);  //PA25 PIN_USB_DP
static const uint8_t PIN_USB_HOST_ENABLE       = (31u);  //PA18 PIN_USB_HOST_ENABLE
static const uint8_t PIN_NOT_USED_1            = (32u);  //PA06PIN_NOT_USED_1
static const uint8_t PIN_NOT_USED_2            = (33u);  //PA23 PIN_NOT_USED_2
static const uint8_t PIN_NOT_USED_3            = (34u);  //PB02 PIN_NOT_USED_3
static const uint8_t PIN_NOT_USED_4            = (35u);  //PB03PPIN_NOT_USED_4

// Analog pins
// -----------
#define PIN_A0 (2u)
#define PIN_A1 (3u)
#define PIN_A2 (4u)
#define PIN_A3 (5u)
static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
#define ADC_RESOLUTION 12

// LEDs
#define PIN_LED     CPU_LED_OUT
#define LED_BUILTIN PIN_LED

// SPI Interfaces
// --------------
#define SPI_INTERFACES_COUNT 1
 
// SPI
#define PERIPH_SPI     sercom1
#define PAD_SPI_TX     SPI_PAD_0_SCK_1
#define PAD_SPI_RX     SERCOM_RX_PAD_3
#define PIN_SPI_MISO   MISO
#define PIN_SPI_SCK    SCK
#define PIN_SPI_MOSI   MOSI
//static const uint8_t MOSI = (8u);
//static const uint8_t MISO = (10u);
//static const uint8_t SCK  = (9u);

// Serial ports
// ------------
#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"


// Instances of SERCOM
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

// Serial1
extern Uart Serial1;
#define PIN_SERIAL1_RX MODEM_RX_OUT
#define PIN_SERIAL1_TX MODEM_TX_IN
#define PAD_SERIAL1_TX (UART_TX_PAD_2)
#define PAD_SERIAL1_RX (SERCOM_RX_PAD_3)
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

// Alias Serial to SerialUSB
#define Serial                      SerialUSB

