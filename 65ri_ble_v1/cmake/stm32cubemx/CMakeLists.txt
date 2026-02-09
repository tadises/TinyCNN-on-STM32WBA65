cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)
# STM32CubeMX generated symbols (macros)
set(MX_Defines_Syms 
	USE_FULL_LL_DRIVER 
	BLE 
	USE_NUCLEO_64 
	USE_HAL_DRIVER 
	STM32WBA65xx
    $<$<CONFIG:Debug>:DEBUG>
)

# STM32CubeMX generated include paths
set(MX_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Modules
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/Log
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/LowPower
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/Debug_GPIO
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/Flash
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/ADC_Ctrl
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/CRC_Ctrl
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/App
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Inc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/trace/adv_trace
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/BasicAES
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Flash
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/MemoryManager
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/RTDebug
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/SerialCmdInterpreter
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Log
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/misc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/sequencer
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/tim_serv
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/lpm/tiny_lpm
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/svc/Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/BSP/STM32WBAxx_Nucleo
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/CMSIS/Device/ST/STM32WBAxx/Include
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/ot_inc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/stack/include
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/stack/include/auto
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/svc/Inc
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/CMSIS/Include
)

# STM32CubeMX generated application sources
set(MX_Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/bleplat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/power_table.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/linklayer_plat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/bpka.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/ll_sys_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/Target/host_stack_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/App/app_ble.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/App/app_bsp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/App/p2p_server.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STM32_WPAN/App/p2p_server_app.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Modules/ble_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Interfaces/stm32_lpm_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/Debug_GPIO/app_debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/LowPower/user_low_power_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/LowPower/peripheral_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/ADC_Ctrl/adc_ctrl_conf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/CRC_Ctrl/crc_ctrl_conf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../System/Config/Flash/simple_nvm_arbiter_conf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/app_entry.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/stm32wbaxx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/stm32wbaxx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/sysmem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/syscalls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../startup_stm32wba65xx.s
    #E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Startup/stm32wbaxx_ResetHandler_GCC.s
)

# STM32 HAL/LL Drivers
set(STM32_Drivers_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/system_stm32wbaxx.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_adc.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_adc_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_dma.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_dma_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rcc.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rcc_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_cortex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_flash.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_flash_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_gpio.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_exti.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_pwr.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_pwr_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_exti.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_crc.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_crc_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_icache.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_gpio.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_ramcfg.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rng.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rng_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rtc.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_rtc_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_tim.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_dma.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_uart.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_uart_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_ll_adc.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_usart.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/STM32WBAxx_HAL_Driver/Src/stm32wbaxx_hal_usart_ex.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Drivers/BSP/STM32WBAxx_Nucleo/stm32wbaxx_nucleo.c
)

# Drivers Midllewares


set(Log_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Log/log_module.c
)
set(Modules_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/adc_ctrl.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/app_sys.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/crc_ctrl.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/otp.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/scm.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/stm_list.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/stm_queue.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/temp_measurement.c
)
set(STM32_WPAN_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/svc/Src/svc_ctl.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_sys/src/ll_sys_cs.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_sys/src/ll_sys_dp_slp.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_sys/src/ll_sys_intf.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_sys/src/ll_sys_startup.c
)
set(SerialCmdInterpreter_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/SerialCmdInterpreter/serial_cmd_interpreter.c
)
set(MemoryManager_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/MemoryManager/advanced_memory_manager.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/MemoryManager/stm32_mm.c
)
set(RTDebug_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/RTDebug/RTDebug.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/RTDebug/RTDebug_dtb.c
)
set(Utilities_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/trace/adv_trace/stm32_adv_trace.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/misc/stm32_mem.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/misc/stm32_systime.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/misc/stm32_tiny_sscanf.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/misc/stm32_tiny_vsnprintf.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/sequencer/stm32_seq.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/tim_serv/stm32_timer.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Utilities/lpm/tiny_lpm/stm32_lpm.c
)
set(Flash_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Flash/flash_driver.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Flash/flash_manager.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Flash/rf_timing_synchro.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/Flash/simple_nvm_arbiter.c
)
set(BasicAES_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/BasicAES/baes_cmac.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/BasicAES/baes_ccm.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Modules/BasicAES/baes_ecb.c
)
set(Interface_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/adv_trace_usart_if.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/hw_aes.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/hw_otp.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/hw_pka.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/hw_pka_p256.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/hw_rng.c
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Interfaces/timer_if.c
)
set(Startup_Src
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Projects/Common/WPAN/Startup/stm32wbaxx_ResetHandler_GCC.s
)

# Link directories setup
set(MX_LINK_DIRS

    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/lib
    E:/STM32/Repository/STM32Cube_FW_WBA_V1.7.0/Middlewares/ST/STM32_WPAN/ble/stack/lib
)
# Project static libraries
set(MX_LINK_LIBS  
	:WBA6_LinkLayer_BLE_Basic_lib.a 
	:stm32wba_ble_stack_basic.a
    STM32_Drivers
    ${TOOLCHAIN_LINK_LIBRARIES}
    Log
	Modules
	STM32_WPAN
	SerialCmdInterpreter
	MemoryManager
	RTDebug
	Utilities
	Flash
	BasicAES
	Interface
	Startup
	
)
# Interface library for includes and symbols
add_library(stm32cubemx INTERFACE)
target_include_directories(stm32cubemx INTERFACE ${MX_Include_Dirs})
target_compile_definitions(stm32cubemx INTERFACE ${MX_Defines_Syms})

# Create STM32_Drivers static library
add_library(STM32_Drivers OBJECT)
target_sources(STM32_Drivers PRIVATE ${STM32_Drivers_Src})
target_link_libraries(STM32_Drivers PUBLIC stm32cubemx)


# Create Log static library
add_library(Log OBJECT)
target_sources(Log PRIVATE ${Log_Src})
target_link_libraries(Log PUBLIC stm32cubemx)

# Create Modules static library
add_library(Modules OBJECT)
target_sources(Modules PRIVATE ${Modules_Src})
target_link_libraries(Modules PUBLIC stm32cubemx)

# Create STM32_WPAN static library
add_library(STM32_WPAN OBJECT)
target_sources(STM32_WPAN PRIVATE ${STM32_WPAN_Src})
target_link_libraries(STM32_WPAN PUBLIC stm32cubemx)

# Create SerialCmdInterpreter static library
add_library(SerialCmdInterpreter OBJECT)
target_sources(SerialCmdInterpreter PRIVATE ${SerialCmdInterpreter_Src})
target_link_libraries(SerialCmdInterpreter PUBLIC stm32cubemx)

# Create MemoryManager static library
add_library(MemoryManager OBJECT)
target_sources(MemoryManager PRIVATE ${MemoryManager_Src})
target_link_libraries(MemoryManager PUBLIC stm32cubemx)

# Create RTDebug static library
add_library(RTDebug OBJECT)
target_sources(RTDebug PRIVATE ${RTDebug_Src})
target_link_libraries(RTDebug PUBLIC stm32cubemx)

# Create Utilities static library
add_library(Utilities OBJECT)
target_sources(Utilities PRIVATE ${Utilities_Src})
target_link_libraries(Utilities PUBLIC stm32cubemx)

# Create Flash static library
add_library(Flash OBJECT)
target_sources(Flash PRIVATE ${Flash_Src})
target_link_libraries(Flash PUBLIC stm32cubemx)

# Create BasicAES static library
add_library(BasicAES OBJECT)
target_sources(BasicAES PRIVATE ${BasicAES_Src})
target_link_libraries(BasicAES PUBLIC stm32cubemx)

# Create Interface static library
add_library(Interface OBJECT)
target_sources(Interface PRIVATE ${Interface_Src})
target_link_libraries(Interface PUBLIC stm32cubemx)

# Create Startup static library
add_library(Startup OBJECT)
target_sources(Startup PRIVATE ${Startup_Src})
target_link_libraries(Startup PUBLIC stm32cubemx)

# Add STM32CubeMX generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MX_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MX_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${MX_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)

# Validate that STM32CubeMX code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()
