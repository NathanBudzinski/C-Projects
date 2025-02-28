################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../app.c \
../hardware.c \
../main.c \
../mcp4162.c \
../ssd1306.c 

OBJS += \
./adc.o \
./app.o \
./hardware.o \
./main.o \
./mcp4162.o \
./ssd1306.o 

C_DEPS += \
./adc.d \
./app.d \
./hardware.d \
./main.d \
./mcp4162.d \
./ssd1306.d 


# Each subdirectory must supply rules for building sources it contributes
adc.o: ../adc.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"adc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app.o: ../app.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

hardware.o: ../hardware.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"hardware.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mcp4162.o: ../mcp4162.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"mcp4162.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ssd1306.o: ../ssd1306.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32BG22C224F512IM40=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4108A"' '-DSL_BOARD_REV="A03"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\config" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn\autogen" -I"C:\Users\nateb\SimplicityStudio\v5_workspace\SpectrAn" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/cmsis_dsp/DSP/Include/dsp" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/nateb/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"ssd1306.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


