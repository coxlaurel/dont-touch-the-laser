#ifndef ADC121S021_H
#define ADC121S021_H

#include "main.h"

//HAL_StatusTypeDef ADC121S021_READ_DMA(uint16_t *buffer);

HAL_StatusTypeDef ADC121S021_READ(volatile uint16_t *value);

#endif
