#!/bin/bash

update_repo () {
   cd $1
   git clean -fd
   git checkout *
   git pull
   cd -
}

if [ ! -d "thirdparty" ]; then
    mkdir thirdparty
fi

if [ ! -d "thirdparty/STM32L4XX_HAL" ];
then
    git clone https://github.com/STMicroelectronics/stm32l4xx_hal_driver.git thirdparty/STM32L4XX_HAL
else
    update_repo "thirdparty/STM32L4XX_HAL"
fi

if [ ! -d "thirdparty/cmsis-header-stm32" ];
then
    git clone https://github.com/modm-io/cmsis-header-stm32.git thirdparty/cmsis-header-stm32
else
    update_repo "thirdparty/cmsis-header-stm32"
fi

if [ ! -d "thirdparty/CMSIS_5" ]; then
    git clone https://github.com/ARM-software/CMSIS_5.git thirdparty/CMSIS_5
else
    update_repo "thirdparty/CMSIS_5"
fi

if [ ! -d "thirdparty/FreeRTOS-Kernel" ]; then
    git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git thirdparty/FreeRTOS-Kernel
else
    update_repo "thirdparty/FreeRTOS-Kernel"
fi

if [ ! -d "docker" ]; then
    git clone https://github.com/dogusyuksel/embedded_docker.git docker
else
    update_repo "docker"
fi

exit 0