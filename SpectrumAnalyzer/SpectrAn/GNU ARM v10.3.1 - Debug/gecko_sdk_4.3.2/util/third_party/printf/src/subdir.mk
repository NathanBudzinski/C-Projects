################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk/util/third_party/printf/src/iostream_printf.c 

OBJS += \
./gecko_sdk_4.3.2/util/third_party/printf/src/iostream_printf.o 

C_DEPS += \
./gecko_sdk_4.3.2/util/third_party/printf/src/iostream_printf.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.3.2/util/third_party/printf/src/iostream_printf.o: C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk/util/third_party/printf/src/iostream_printf.c gecko_sdk_4.3.2/util/third_party/printf/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.2/util/third_party/printf/src/iostream_printf.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


