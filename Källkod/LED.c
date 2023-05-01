#include "LCD.h"

void LCD_Init(LCD_HandleTypeDef* hlcd)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOD_CLK_ENABLE(); // Aktiverar klockan för GPIO Port D

  GPIO_InitStruct.Pin = LCD_RS_PIN | LCD_E_PIN | LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Sätter porten som output
  GPIO_InitStruct.Pull = GPIO_NOPULL; // Inget pull-up eller pull-down
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Låg hastighet
  HAL_GPIO_Init(LCD_RS_GPIO, &GPIO_InitStruct); // Initierar GPIO porten

  HAL_Delay(50); // Väntar på att LCD-skärmen ska starta upp

  // Skickar initialiseringskommandon till LCD-skärmen
  LCD_SendCommand(hlcd, 0x02); // Sätter tillbaka cursorn till början av första raden
  LCD_SendCommand(hlcd, 0x28); // Sätter 4-bitars läge, 2 rader, 5x8 tecken
  LCD_SendCommand(hlcd, 0x0C); // Slår på skärmen och döljer cursorn
  LCD_SendCommand(hlcd, 0x06); // Skiftar cursorn till höger efter varje inskrivna tecken
  LCD_SendCommand(hlcd, 0x01); // Rensar skärmen och sätter cursorn tillbaka till början

  HAL_Delay(5); // Väntar på att LCD-skärmen ska uppdatera sig
}

void LCD_SendCommand(LCD_HandleTypeDef* hlcd, uint8_t command)
{
  HAL_GPIO_WritePin(LCD_RS_GPIO, LCD_RS_PIN, GPIO_PIN_RESET); // Sätter RS-pinnen till låg för att skicka en kommando
  HAL_GPIO_WritePin(LCD_E_GPIO, LCD_E_PIN, GPIO_PIN_RESET); // Sätter E
