cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME "${NAME}-${VER}")

# Include toolchain file
include("../gcc-arm-none-eabi.cmake")
message("LINKER_FILE     :       " ${LINKER_FILE})
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -T \"${LINKER_FILE}\"")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("CMAKE_BUILD_TYPE:       " ${CMAKE_BUILD_TYPE})


message("CMAKE_BINARY_DIR:       " ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
message("EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH})

message("SOURCE_FILES_PATH:      " ${SOURCE_FILES_PATH})
file(GLOB files_under_src
     "${SOURCE_FILES_PATH}/*.c"
)
message("files_under_src:        " ${files_under_src})

file(GLOB free_rtos_all
     "../thirdparty/FreeRTOS-Kernel/*.c"
)

add_executable(${CMAKE_PROJECT_NAME}
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_uart.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_uart_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_rcc.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_rcc_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_flash.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_flash_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_flash_ramfunc.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_gpio.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_i2c.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_i2c_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_dma.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_dma_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_pwr.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_pwr_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_cortex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_exti.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_tim.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_tim_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_pcd.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_hal_pcd_ex.c
    ../thirdparty/STM32L4XX_HAL/Src/stm32l4xx_ll_usb.c
    ${files_under_src}
    ../startup_stm32l4a6xx.s
    ${free_rtos_all}
    ../thirdparty/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c
    ../thirdparty/FreeRTOS-Kernel/portable/MemMang/heap_3.c
)

message("INCLUDES_PATHS:         " ${INCLUDES_PATHS})
string(REPLACE ":" ";" INCLUDES_PATHS_EDITED ${INCLUDES_PATHS})
foreach(file ${INCLUDES_PATHS_EDITED})
    message("file: ${file}")
endforeach()
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC SYSTEM
    ${INCLUDES_PATHS_EDITED}
    ../thirdparty/FreeRTOS-Kernel/include
    ../thirdparty/FreeRTOS-Kernel/portable/GCC/ARM_CM4F
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC SYSTEM
	USE_HAL_DRIVER 
	STM32L4A6xx
    $<$<CONFIG:Debug>:DEBUG>
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()
