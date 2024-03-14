/*
 * flash_store_data.c
 *
 *  Created on: Mar 14, 2024
 *      Author: qwert
 */

#include "flash_store_data.h"
#include "stm32l4xx.h"
//#include "stm32l412xx.h"


typedef uint64_t flash_datatype;

#define DATA_SIZE sizeof(flash_datatype)

void store_flash_memory(uint32_t memory_address, uint8_t* data, uint16_t data_length)
{
	uint8_t double_word_data[DATA_SIZE];
	FLASH_EraseInitTypeDef flash_erase_struct = {0};

	HAL_FLASH_Unlock();

	flash_erase_struct.TypeErase = FLASH_TYPEERASE_PAGES;
	flash_erase_struct.Page = (memory_address - FLASH_BASE)/ FLASH_PAGE_SIZE;
	flash_erase_struct.NbPages = 1 + data_length / FLASH_PAGE_SIZE;

	if(memory_address > FLASH_BASE && memory_address < FLASH_BANK1_END)
	{
		flash_erase_struct.Banks = FLASH_BANK_1;
	}
	else
	{
		//printf("illegal memory address \n");
		//UsageFault_Handler();
	}

	uint32_t error_status = 0;

	HAL_FLASHEx_Erase(&flash_erase_struct, &error_status);
	int i = 0;

	while(i<=data_length)
	{
		double_word_data[i % DATA_SIZE] = data[i];
		i++;
		if(i % DATA_SIZE == 0)
		{
			HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, memory_address + i - DATA_SIZE, *((uint64_t * )double_word_data));
		}
	}

	if(i % DATA_SIZE != 0)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, memory_address + i - i % DATA_SIZE, *((flash_datatype*)double_word_data));
	}

	HAL_FLASH_Lock();

}

void read_flash_memory(uint32_t memory_address, uint8_t* data, uint16_t data_length)
{
	for(int i = 0; i < data_length; i++)
	{
		*(data+i) = (*(uint8_t * )(memory_address + i));
	}
}
