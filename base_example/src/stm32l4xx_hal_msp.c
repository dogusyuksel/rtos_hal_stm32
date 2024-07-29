
#include "main.h"

void HAL_MspInit(void) {

    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
    if (huart->Instance == LPUART1) {

        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPUART1;
        PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
            Error_Handler();
        }

        __HAL_RCC_LPUART1_CLK_ENABLE();

        __HAL_RCC_GPIOG_CLK_ENABLE();
        HAL_PWREx_EnableVddIO2();
        GPIO_InitStruct.Pin = STLK_RX_Pin | STLK_TX_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
        HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        HAL_NVIC_SetPriority(LPUART1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(LPUART1_IRQn);
    }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {
    if (huart->Instance == LPUART1) {

        __HAL_RCC_LPUART1_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOG, STLK_RX_Pin | STLK_TX_Pin);

        HAL_NVIC_DisableIRQ(LPUART1_IRQn);
    }
}

void HAL_PCD_MspInit(PCD_HandleTypeDef *hpcd) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
    if (hpcd->Instance == USB_OTG_FS) {

        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
        PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
        PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
        PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
        PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
        PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV2;
        PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
        PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
        PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
            Error_Handler();
        }

        __HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitStruct.Pin = USB_SOF_Pin | USB_ID_Pin | USB_DM_Pin | USB_DP_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = USB_VBUS_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

        __HAL_RCC_USB_OTG_FS_CLK_ENABLE();

        if (__HAL_RCC_PWR_IS_CLK_DISABLED()) {
            __HAL_RCC_PWR_CLK_ENABLE();
            HAL_PWREx_EnableVddUSB();
            __HAL_RCC_PWR_CLK_DISABLE();
        } else {
            HAL_PWREx_EnableVddUSB();
        }
    }
}

void HAL_PCD_MspDeInit(PCD_HandleTypeDef *hpcd) {
    if (hpcd->Instance == USB_OTG_FS) {

        __HAL_RCC_USB_OTG_FS_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOA, USB_SOF_Pin | USB_VBUS_Pin | USB_ID_Pin | USB_DM_Pin | USB_DP_Pin);

        if (__HAL_RCC_PWR_IS_CLK_DISABLED()) {
            __HAL_RCC_PWR_CLK_ENABLE();
            HAL_PWREx_DisableVddUSB();
            __HAL_RCC_PWR_CLK_DISABLE();
        } else {
            HAL_PWREx_DisableVddUSB();
        }
    }
}
