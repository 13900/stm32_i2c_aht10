/*
 * aht10.h
 *
 *  Created on: Jun 12, 2022
 *
 */

#ifndef  _AHT10_H
#define  _AHT10_H

#include "i2c.h"    //iic 1  PB6------> I2C1_SCL   PB7------> I2C1_SDA
#include "stdio.h"

#define AHT10_ADDRESS_WRITE	0x70
#define AHT10_ADDRESS_READ	0x71

void aht10_init();
void aht10_read_data();

#endif /* INC_AHT10_H_ */
