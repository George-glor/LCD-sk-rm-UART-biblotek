#include "stm32f4xx.h"
#include "UART.h"
#include "LCD.h"

UART_HandleTypeDef huart2; // UART handtag för kommunikation via USART2
LCD_HandleTypeDef hlcd; // LCD handtag för kommunikation via LCD

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_LCD_Init(void);

int main(void)
{
  HAL_Init(); // Initierar HAL biblioteket
  SystemClock_Config(); // Konfigurerar klockan
  MX_GPIO_Init(); // Initierar GPIO
  MX_USART2_UART_Init(); // Initierar UART med USART2
  MX_TIM2_Init(); // Initierar timer 2
  MX_TIM3_Init(); // Initierar timer 3
  MX_LCD_Init(); // Initierar LCD

  while (1)
  {
    // Huvudloopen kod här
  }
}
