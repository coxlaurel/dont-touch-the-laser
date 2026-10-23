

#include "adc121s021.h"

extern SPI_HandleTypeDef hspi2;

HAL_StatusTypeDef ADC121S021_READ(void)
{
	uint8_t rx[2] = {0};

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);

	HAL_StatusTypeDef status = HAL_SPI_Receive(&hspi2, rx, 2, 100);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

	if (status != HAL_OK)
	{
		return status;
	}

	uint16_t value = ((uint16_t)rx[1] << 4) | rx[0];

	return HAL_OK;
}
