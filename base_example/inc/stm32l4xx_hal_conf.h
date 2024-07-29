
#ifndef STM32L4xx_HAL_CONF_H
#define STM32L4xx_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#define HAL_MODULE_ENABLED
#define HAL_PCD_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED

#if !defined(HSE_VALUE)
#define HSE_VALUE ((uint32_t)8000000U) /*!< Value of the External oscillator in Hz */
#endif                                 /* HSE_VALUE */

#if !defined(HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT ((uint32_t)100U) /*!< Time out for HSE start up, in ms */
#endif                                       /* HSE_STARTUP_TIMEOUT */

#if !defined(MSI_VALUE)
#define MSI_VALUE ((uint32_t)4000000U) /*!< Value of the Internal oscillator in Hz*/
#endif                                 /* MSI_VALUE */
#if !defined(HSI_VALUE)
#define HSI_VALUE ((uint32_t)16000000U) /*!< Value of the Internal oscillator in Hz*/
#endif                                  /* HSI_VALUE */

#if !defined(HSI48_VALUE)
#define HSI48_VALUE                                                                                                    \
    ((uint32_t)48000000U) /*!< Value of the Internal High Speed oscillator for USB FS/SDMMC/RNG in Hz.                 \
                           The real value my vary depending on manufacturing process variations.*/
#endif                    /* HSI48_VALUE */

#if !defined(LSI_VALUE)
#define LSI_VALUE 32000U /*!< LSI Typical Value in Hz*/
#endif /* LSI_VALUE */   /*!< Value of the Internal Low Speed oscillator in Hz                                         \
                          The real value may vary depending on the variations                                          \
                          in voltage and temperature.*/

#if !defined(LSE_VALUE)
#define LSE_VALUE 32768U /*!< Value of the External oscillator in Hz*/
#endif                   /* LSE_VALUE */

#if !defined(LSE_STARTUP_TIMEOUT)
#define LSE_STARTUP_TIMEOUT 5000U /*!< Time out for LSE start up, in ms */
#endif                            /* HSE_STARTUP_TIMEOUT */

#if !defined(EXTERNAL_SAI1_CLOCK_VALUE)
#define EXTERNAL_SAI1_CLOCK_VALUE 2097000U /*!< Value of the SAI1 External clock source in Hz*/
#endif                                     /* EXTERNAL_SAI1_CLOCK_VALUE */

#if !defined(EXTERNAL_SAI2_CLOCK_VALUE)
#define EXTERNAL_SAI2_CLOCK_VALUE 2097000U /*!< Value of the SAI2 External clock source in Hz*/
#endif                                     /* EXTERNAL_SAI2_CLOCK_VALUE */

#define VDD_VALUE 3300U       /*!< Value of VDD in mv */
#define TICK_INT_PRIORITY 15U /*!< tick interrupt priority */
#define USE_RTOS 0U
#define PREFETCH_ENABLE 0U
#define INSTRUCTION_CACHE_ENABLE 1U
#define DATA_CACHE_ENABLE 1U

#define USE_HAL_ADC_REGISTER_CALLBACKS 0U
#define USE_HAL_CAN_REGISTER_CALLBACKS 0U
#define USE_HAL_COMP_REGISTER_CALLBACKS 0U
#define USE_HAL_CRYP_REGISTER_CALLBACKS 0U
#define USE_HAL_DAC_REGISTER_CALLBACKS 0U
#define USE_HAL_DCMI_REGISTER_CALLBACKS 0U
#define USE_HAL_DFSDM_REGISTER_CALLBACKS 0U
#define USE_HAL_DMA2D_REGISTER_CALLBACKS 0U
#define USE_HAL_DSI_REGISTER_CALLBACKS 0U
#define USE_HAL_GFXMMU_REGISTER_CALLBACKS 0U
#define USE_HAL_HASH_REGISTER_CALLBACKS 0U
#define USE_HAL_HCD_REGISTER_CALLBACKS 0U
#define USE_HAL_I2C_REGISTER_CALLBACKS 0U
#define USE_HAL_IRDA_REGISTER_CALLBACKS 0U
#define USE_HAL_LPTIM_REGISTER_CALLBACKS 0U
#define USE_HAL_LTDC_REGISTER_CALLBACKS 0U
#define USE_HAL_MMC_REGISTER_CALLBACKS 0U
#define USE_HAL_OPAMP_REGISTER_CALLBACKS 0U
#define USE_HAL_OSPI_REGISTER_CALLBACKS 0U
#define USE_HAL_PCD_REGISTER_CALLBACKS 0U
#define USE_HAL_QSPI_REGISTER_CALLBACKS 0U
#define USE_HAL_RNG_REGISTER_CALLBACKS 0U
#define USE_HAL_RTC_REGISTER_CALLBACKS 0U
#define USE_HAL_SAI_REGISTER_CALLBACKS 0U
#define USE_HAL_SD_REGISTER_CALLBACKS 0U
#define USE_HAL_SMARTCARD_REGISTER_CALLBACKS 0U
#define USE_HAL_SMBUS_REGISTER_CALLBACKS 0U
#define USE_HAL_SPI_REGISTER_CALLBACKS 0U
#define USE_HAL_SWPMI_REGISTER_CALLBACKS 0U
#define USE_HAL_TIM_REGISTER_CALLBACKS 0U
#define USE_HAL_TSC_REGISTER_CALLBACKS 0U
#define USE_HAL_UART_REGISTER_CALLBACKS 0U
#define USE_HAL_USART_REGISTER_CALLBACKS 0U
#define USE_HAL_WWDG_REGISTER_CALLBACKS 0U

#define USE_SPI_CRC 0U

#ifdef HAL_RCC_MODULE_ENABLED
#include "stm32l4xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32l4xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
#include "stm32l4xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_DFSDM_MODULE_ENABLED
#include "stm32l4xx_hal_dfsdm.h"
#endif /* HAL_DFSDM_MODULE_ENABLED */

#ifdef HAL_CORTEX_MODULE_ENABLED
#include "stm32l4xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
#include "stm32l4xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_CAN_MODULE_ENABLED
#include "stm32l4xx_hal_can.h"
#endif /* HAL_CAN_MODULE_ENABLED */

#ifdef HAL_CAN_LEGACY_MODULE_ENABLED
#include "Legacy/stm32l4xx_hal_can_legacy.h"
#endif /* HAL_CAN_LEGACY_MODULE_ENABLED */

#ifdef HAL_COMP_MODULE_ENABLED
#include "stm32l4xx_hal_comp.h"
#endif /* HAL_COMP_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
#include "stm32l4xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
#include "stm32l4xx_hal_cryp.h"
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_DAC_MODULE_ENABLED
#include "stm32l4xx_hal_dac.h"
#endif /* HAL_DAC_MODULE_ENABLED */

#ifdef HAL_DCMI_MODULE_ENABLED
#include "stm32l4xx_hal_dcmi.h"
#endif /* HAL_DCMI_MODULE_ENABLED */

#ifdef HAL_DMA2D_MODULE_ENABLED
#include "stm32l4xx_hal_dma2d.h"
#endif /* HAL_DMA2D_MODULE_ENABLED */

#ifdef HAL_DSI_MODULE_ENABLED
#include "stm32l4xx_hal_dsi.h"
#endif /* HAL_DSI_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
#include "stm32l4xx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_GFXMMU_MODULE_ENABLED
#include "stm32l4xx_hal_gfxmmu.h"
#endif /* HAL_GFXMMU_MODULE_ENABLED */

#ifdef HAL_FIREWALL_MODULE_ENABLED
#include "stm32l4xx_hal_firewall.h"
#endif /* HAL_FIREWALL_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
#include "stm32l4xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_HASH_MODULE_ENABLED
#include "stm32l4xx_hal_hash.h"
#endif /* HAL_HASH_MODULE_ENABLED */

#ifdef HAL_HCD_MODULE_ENABLED
#include "stm32l4xx_hal_hcd.h"
#endif /* HAL_HCD_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32l4xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
#include "stm32l4xx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
#include "stm32l4xx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_LCD_MODULE_ENABLED
#include "stm32l4xx_hal_lcd.h"
#endif /* HAL_LCD_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32l4xx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_LTDC_MODULE_ENABLED
#include "stm32l4xx_hal_ltdc.h"
#endif /* HAL_LTDC_MODULE_ENABLED */

#ifdef HAL_MMC_MODULE_ENABLED
#include "stm32l4xx_hal_mmc.h"
#endif /* HAL_MMC_MODULE_ENABLED */

#ifdef HAL_NAND_MODULE_ENABLED
#include "stm32l4xx_hal_nand.h"
#endif /* HAL_NAND_MODULE_ENABLED */

#ifdef HAL_NOR_MODULE_ENABLED
#include "stm32l4xx_hal_nor.h"
#endif /* HAL_NOR_MODULE_ENABLED */

#ifdef HAL_OPAMP_MODULE_ENABLED
#include "stm32l4xx_hal_opamp.h"
#endif /* HAL_OPAMP_MODULE_ENABLED */

#ifdef HAL_OSPI_MODULE_ENABLED
#include "stm32l4xx_hal_ospi.h"
#endif /* HAL_OSPI_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
#include "stm32l4xx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_PKA_MODULE_ENABLED
#include "stm32l4xx_hal_pka.h"
#endif /* HAL_PKA_MODULE_ENABLED */

#ifdef HAL_PSSI_MODULE_ENABLED
#include "stm32l4xx_hal_pssi.h"
#endif /* HAL_PSSI_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
#include "stm32l4xx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_QSPI_MODULE_ENABLED
#include "stm32l4xx_hal_qspi.h"
#endif /* HAL_QSPI_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
#include "stm32l4xx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
#include "stm32l4xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
#include "stm32l4xx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SD_MODULE_ENABLED
#include "stm32l4xx_hal_sd.h"
#endif /* HAL_SD_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
#include "stm32l4xx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
#include "stm32l4xx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32l4xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_SRAM_MODULE_ENABLED
#include "stm32l4xx_hal_sram.h"
#endif /* HAL_SRAM_MODULE_ENABLED */

#ifdef HAL_SWPMI_MODULE_ENABLED
#include "stm32l4xx_hal_swpmi.h"
#endif /* HAL_SWPMI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "stm32l4xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_TSC_MODULE_ENABLED
#include "stm32l4xx_hal_tsc.h"
#endif /* HAL_TSC_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "stm32l4xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
#include "stm32l4xx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
#include "stm32l4xx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

#ifdef USE_FULL_ASSERT
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* STM32L4xx_HAL_CONF_H */
