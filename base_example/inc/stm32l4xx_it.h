
#ifndef __STM32L4xx_IT_H
#define __STM32L4xx_IT_H

#ifdef __cplusplus
extern "C" {
#endif

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void DebugMon_Handler(void);
void TIM1_UP_TIM16_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void LPUART1_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32L4xx_IT_H */
