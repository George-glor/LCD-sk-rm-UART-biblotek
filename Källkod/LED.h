#ifndef __LCD_H
#define __LCD_H

#include "stm32f4xx_hal.h"

#define LCD_RS_PIN GPIO_PIN_0
#define LCD_RS_GPIO GPIOD
#define LCD_E_PIN GPIO_PIN_1
#define LCD_E_GPIO GPIOD
#define LCD_D4_PIN GPIO_PIN_12
#define LCD_D4_GPIO GPIOD
#define LCD_D5_PIN GPIO_PIN_13
#define LCD_D5_GPIO GPIOD
#define LCD_D6_PIN GPIO_PIN_14
#define LCD_D6_GPIO GPIOD
#define LCD_D7_PIN GPIO_PIN_15
#define LCD_D7_GPIO GPIOD

void LCD_Init(LCD_HandleTypeDef* hlcd); // Funktion för att initiera LCD-skärmen
void LCD_SendCommand(LCD_HandleTypeDef* hlcd, uint8_t command); // Funktion för att skicka en kommando till LCD-skärmen
void LCD_SendData(LCD_HandleTypeDef* hlcd, uint8_t data); // Funktion för att skicka data till LCD-skärmen
void LCD_SendString(LCD_HandleTypeDef* hlcd, char* str); // Funktion för att skicka en sträng till LCD-skärmen

#endif /* __LCD_H */
