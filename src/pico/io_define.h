#include <stdint.h>
#include <hardware/spi.h>
#include <hardware/i2c.h>
#define NUM_TOTAL_PINS 29
#define DIGITAL_BITMASK_TYPE uint16_t
#define PIN_A0 26
#define TWI_0 i2c0
#define TWI_1 i2c1
#define SPI_0 spi0
#define SPI_1 spi1
#define TWI_BLOCK i2c_inst_t*
#define SPI_BLOCK spi_inst_t*