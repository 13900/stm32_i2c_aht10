/*
 * aht10.c
 *
 *  Created on: Jun 12, 2022
 *
 */


#include "aht10.h"

uint8_t INIT_ORDER[] = {0xe1,0x08,0x00};
uint8_t SOFT_RESET[] = {0xba};
uint8_t MEASURE_ORDER[] = {0xAC, 0x33, 0x00};

float huml;
float temp;
uint32_t h;
uint32_t t;

void aht10_init()
{
	HAL_Delay(40);
	HAL_I2C_Master_Transmit(&hi2c1,AHT10_ADDRESS_WRITE, INIT_ORDER, 3,0x00ff);
	HAL_Delay(40);
	HAL_I2C_Master_Transmit(&hi2c1,AHT10_ADDRESS_WRITE, SOFT_RESET, 1,0x00ff);
	HAL_Delay(20);
}

void aht10_read_data()
{
	uint8_t data[6];
	HAL_I2C_Master_Transmit(&hi2c1, AHT10_ADDRESS_WRITE, MEASURE_ORDER, 3, 0x00ff);
	HAL_Delay(80);
	HAL_I2C_Master_Receive(&hi2c1, AHT10_ADDRESS_READ, data, 6, 0x00ff);
	if((data[0] & 0x08) == 0)	aht10_init();


	h = (data[1]<<12)+(data[2]<<4)+(data[3]>>4);
	t = ((data[3]&0X0f)<<16)+(data[4]<<8)+(data[5]);

	huml = (float)h /1048575*200-50;
	temp = (float)t /1048575*100;

	printf("ÎÂ¶È£º%f\r\n", temp);
	printf("Êª¶È£º%f\r\n", huml);
}







