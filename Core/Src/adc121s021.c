

#include "adc121s021.h"

extern SPI_HandleTypeDef hspi2;

//HAL_StatusTypeDef ADC121S021_START(void)
//{
//
//}

//HAL_StatusTypeDef ADC121S021_READ_DMA(uint16_t *buffer)
//{
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
//
//	HAL_StatusTypeDef status = HAL_SPI_Receive_DMA(&hspi2, (uint8_t *)buffer, 12);
//
//	if (status != HAL_OK)
//	{
//	    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
//	    return status;
//	}
//
//	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY)
//	{
//	}
//
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
//
//	return HAL_OK;
//}

HAL_StatusTypeDef ADC121S021_READ(volatile uint16_t *value)
{
        uint16_t rx = 0;

        HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);

        HAL_StatusTypeDef status = HAL_SPI_Receive(&hspi2, (uint8_t *)&rx, 1, 1);

        HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

        if (status != HAL_OK)
        {
        	return status;
        }

        *value = rx & 0x0FFF;

        return HAL_OK;
}
