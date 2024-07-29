
#include "stm32l4xx.h"

#if !defined(HSE_VALUE)
#define HSE_VALUE 8000000U /*!< Value of the External oscillator in Hz */
#endif                     /* HSE_VALUE */

#if !defined(MSI_VALUE)
#define MSI_VALUE 4000000U /*!< Value of the Internal oscillator in Hz*/
#endif                     /* MSI_VALUE */

#if !defined(HSI_VALUE)
#define HSI_VALUE 16000000U /*!< Value of the Internal oscillator in Hz*/
#endif                      /* HSI_VALUE */

#if defined(USER_VECT_TAB_ADDRESS)

#if defined(VECT_TAB_SRAM)
#define VECT_TAB_BASE_ADDRESS                                                                                          \
    SRAM1_BASE /*!< Vector Table base address field.                                                                   \
                    This value must be a multiple of 0x200. */
#define VECT_TAB_OFFSET                                                                                                \
    0x00000000U /*!< Vector Table base offset field.                                                                   \
                     This value must be a multiple of 0x200. */
#else
#define VECT_TAB_BASE_ADDRESS                                                                                          \
    FLASH_BASE /*!< Vector Table base address field.                                                                   \
                    This value must be a multiple of 0x200. */
#define VECT_TAB_OFFSET                                                                                                \
    0x00000000U /*!< Vector Table base offset field.                                                                   \
                     This value must be a multiple of 0x200. */
#endif          /* VECT_TAB_SRAM */
#endif          /* USER_VECT_TAB_ADDRESS */

uint32_t SystemCoreClock = 4000000U;

const uint8_t AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
const uint8_t APBPrescTable[8] = {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
const uint32_t MSIRangeTable[12] = {100000U,  200000U,  400000U,   800000U,   1000000U,  2000000U,
                                    4000000U, 8000000U, 16000000U, 24000000U, 32000000U, 48000000U};

void SystemInit(void) {
#if defined(USER_VECT_TAB_ADDRESS)
    SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;
#endif

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 20U) | (3UL << 22U)); /* set CP10 and CP11 Full Access */
#endif
}

void SystemCoreClockUpdate(void) {
    uint32_t tmp, msirange, pllvco, pllsource, pllm, pllr;

    if ((RCC->CR & RCC_CR_MSIRGSEL) == 0U) { /* MSISRANGE from RCC_CSR applies */
        msirange = (RCC->CSR & RCC_CSR_MSISRANGE) >> 8U;
    } else { /* MSIRANGE from RCC_CR applies */
        msirange = (RCC->CR & RCC_CR_MSIRANGE) >> 4U;
    }
    msirange = MSIRangeTable[msirange];

    switch (RCC->CFGR & RCC_CFGR_SWS) {
    case 0x00: /* MSI used as system clock source */
        SystemCoreClock = msirange;
        break;

    case 0x04: /* HSI used as system clock source */
        SystemCoreClock = HSI_VALUE;
        break;

    case 0x08: /* HSE used as system clock source */
        SystemCoreClock = HSE_VALUE;
        break;

    case 0x0C: /* PLL used as system clock  source */
        pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
        pllm = ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> 4U) + 1U;

        switch (pllsource) {
        case 0x02: /* HSI used as PLL clock source */
            pllvco = (HSI_VALUE / pllm);
            break;

        case 0x03: /* HSE used as PLL clock source */
            pllvco = (HSE_VALUE / pllm);
            break;

        default: /* MSI used as PLL clock source */
            pllvco = (msirange / pllm);
            break;
        }
        pllvco = pllvco * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 8U);
        pllr = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> 25U) + 1U) * 2U;
        SystemCoreClock = pllvco / pllr;
        break;

    default:
        SystemCoreClock = msirange;
        break;
    }
    tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4U)];
    SystemCoreClock >>= tmp;
}
