
#ifndef BOARD_H_
#define BOARD_H_

#include "at91sam7x512/AT91SAM7X512.h"

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7X-EK - Board Description"
/// This page lists several definition related to the board description
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME			"Netduino"
/// Family definition.
#define at91sam7x
/// Board definition
#define netduino
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7X-EK - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
///
/// !Definitions
/// - BOARD_MAINOSC
/// - BOARD_MCK

/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           18432000
/// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               48000000
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ADC
//------------------------------------------------------------------------------
/// ADC clock frequency, at 10-bit resolution (in Hz)
#define ADC_MAX_CK_10BIT		5000000
/// ADC clock frequency, at 8-bit resolution (in Hz)
#define ADC_MAX_CK_8BIT			8000000
/// Startup time max, return from Idle mode (in �s)
#define ADC_STARTUP_TIME_MAX	20
/// Track and hold Acquisition Time min (in ns)
#define ADC_TRACK_HOLD_TIME_MIN	600
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7X-EK - USB device"
/// This page lists constants describing several characteristics (controller
/// type, D+ pull-up type, etc.) of the USB device controller of the chip/board.
///
/// !Constants
/// - BOARD_USB_UDP
/// - BOARD_USB_PULLUP_ALWAYSON
/// - BOARD_USB_NUMENDPOINTS
/// - BOARD_USB_ENDPOINTS_MAXPACKETSIZE
/// - BOARD_USB_ENDPOINTS_BANKS
/// - BOARD_USB_BMATTRIBUTES

/// Chip has a UDP controller.
#define BOARD_USB_UDP
/// Indicates the D+ pull-up is always connected.
#define BOARD_USB_PULLUP_ALWAYSON
/// Number of endpoints in the USB controller.
#define BOARD_USB_NUMENDPOINTS                  6
/// Returns the maximum packet size of the given endpoint.
#define BOARD_USB_ENDPOINTS_MAXPACKETSIZE(i)    ((((i) == 4) || ((i) == 5)) ? 256 : (((i) == 0) ? 8 : 64))
/// Returns the number of FIFO banks for the given endpoint.
#define BOARD_USB_ENDPOINTS_BANKS(i)            ((((i) == 0) || ((i) == 3)) ? 1 : 2)
/// USB attributes configuration descriptor (bus or self powered, remote wakeup)
#define BOARD_USB_BMATTRIBUTES                  USBConfigurationDescriptor_BUSPOWERED_NORWAKEUP
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7X-EK - PIO definitions"
/// This pages lists all the pio definitions contained in board.h. The constants
/// are named using the following convention: PIN_* for a constant which defines
/// a single Pin instance (but may include several PIOs sharing the same
/// controller), and PINS_* for a list of Pin instances.
///
/// !DBGU
/// - PINS_DBGU
///
/// !LEDs
/// - BOARD_LED
/// - PINS_LEDS
///
/// !Push buttons
/// - BOARD_BUTTON
/// - PINS_PUSHBUTTONS
///
/// !USART0
/// - PIN_USART0_RXD
/// - PIN_USART0_TXD
/// - PIN_USART0_SCK
///
/// !SPI0
/// - PIN_SPI0_MISO
/// - PIN_SPI0_MOSI
/// - PIN_SPI0_SPCK
/// - PINS_SPI0
/// - PIN_SPI0_NPCS0
/// - PIN_SPI0_NPCS1
///
/// !PWMC
/// - PIN_PWMC_PWM0
/// - PIN_PWMC_PWM1
/// - PIN_PWMC_PWM2
/// - PIN_PWMC_PWM3
/// - PIN_PWM_LED0
/// - PIN_PWM_LED1
/// - CHANNEL_PWM_LED0
/// - CHANNEL_PWM_LED1
///
/// !ADC
/// - PIN_ADC_ADC0
/// - PIN_ADC_ADC1
/// - PIN_ADC_ADC2
/// - PIN_ADC_ADC3
/// - PINS_ADC
///
/// !TWI
/// - PINS_TWI

/// List of all DBGU pin definitions.
#define PINS_DBGU			{ 0x18000000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }

/// LED #0 pin definition.
#define BOARD_LED			{ 1 << 23, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT }
/// List of all LEDs pin definitions.
#define PINS_LEDS			BOARD_LED

/// Push button #0 definition. /SWITCH1
#define BOARD_BUTTON		{ 1 << 29, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP }
/// List of all push button definitions.
#define PINS_PUSHBUTTONS    BOARD_BUTTON

/// USART0 RXD pin definition.
#define PIN_USART0_RXD		{ 1 << 0, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D2				PIN_USART0_RXD
#define PIN_USART0_DRXD		{ 1 << 27, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D0				PIN_USART0_DRXD
/// USART0 TXD pin definition.
#define PIN_USART0_TXD		{ 1 << 1, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D3				PIN_USART0_TXD
#define PIN_USART0_DTXD		{ 1 << 28, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D1				PIN_USART0_DTXD
/// USART0 SCK pin definition.
#define PIN_USART0_SCK		{ 1 << 2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
/// USART0 RTS pin definition
#define PIN_USART0_RTS		{ 1 << 3, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D7				PIN_USART0_RTS
/// USART0 CTS pin definition
#define PIN_USART0_CTS		{ 1 << 4, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D8				PIN_USART0_CTS

/// SPI0 MISO pin definition.
#define PIN_SPI0_MISO		{ 1 << 16, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D12				PIN_SPI0_MISO
/// SPI0 MOSI pin definition.
#define PIN_SPI0_MOSI		{ 1 << 17, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP }
#define PIN_D11				PIN_SPI0_MOSI
/// SPI0 SPCK pin definition.
#define PIN_SPI0_SPCK		{ 1 << 18, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP }
#define PIN_D13				PIN_SPI0_SPCK
/// List of SPI0 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI0			PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK
/// SPI0 chip select 0 pin definition.
#define PIN_SPI0_NPCS0		{ 1 << 12, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP }
#define PIN_D4				PIN_SPI0_NPCS0

/// PWMC PWM0 pin definition.
#define PIN_PWMC_PWM0		{ 1 << 19, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D5				PIN_PWMC_PWM0
/// PWMC PWM1 pin definition.
#define PIN_PWMC_PWM1		{ 1 << 20, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D6				PIN_PWMC_PWM1
/// PWMC PWM2 pin definition.
#define PIN_PWMC_PWM2		{ 1 << 21, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D9				PIN_PWMC_PWM2
/// PWMC PWM3 pin definition.
#define PIN_PWMC_PWM3		{ 1 << 22, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_D10				PIN_PWMC_PWM3

/// ADC_AD0 pin definition.
#define PIN_ADC0_ADC0		{ 1 << 27, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT }
#define PIN_A0				PIN_ADC0_ADC0
/// ADC_AD1 pin definition.
#define PIN_ADC0_ADC1		{ 1 << 28, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT }
#define PIN_A1				PIN_ADC0_ADC1
/// ADC_AD2 pin definition.
#define PIN_ADC0_ADC2		{ 1 << 29, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT }
#define PIN_A3				PIN_ADC0_ADC2
/// ADC_AD3 pin definition.
#define PIN_ADC0_ADC3		{ 1 << 30, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT }
#define PIN_A4				PIN_ADC0_ADC3
/// Pins ADC
#define PINS_ADC			PIN_ADC0_ADC0, PIN_ADC0_ADC1, PIN_ADC0_ADC2, PIN_ADC0_ADC3

/// TWI Two-wire Serial Data
#define PIN_TWI_TWD			{ 1 << 10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_A5				PIN_TWI_TWD
/// TWI Two-wire Serial Clock
#define PIN_TWI_TWCK		{ 1 << 11, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_A6				PIN_TWI_TWCK
/// TWI pins definition.
#define PINS_TWI			{ 0x00000C00, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7X-EK - Memories"
/// This page lists definitions related to internal & external on-board memories.
///
/// !Embedded Flash
/// - BOARD_FLASH_EFC
/// - BOARD_FLASH_IAP_ADDRESS

/// Indicates chip has an EFC.
#define BOARD_FLASH_EFC
/// Address of the IAP function in ROM.
#define BOARD_FLASH_IAP_ADDRESS					0x300008
//------------------------------------------------------------------------------

#endif /* BOARD_H_ */
