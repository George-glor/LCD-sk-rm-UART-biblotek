#ifndef __UART_H
#define __UART_H

#include "stm32f4xx_hal.h"

#define UART_TX_PIN GPIO_PIN_2
#define UART_RX_PIN GPIO_PIN_3
#define UART_GPIO GPIOA
#define UART_BAUDRATE 9600

void UART_Init(UART_HandleTypeDef* huart);

#endif /* __UART_H */
