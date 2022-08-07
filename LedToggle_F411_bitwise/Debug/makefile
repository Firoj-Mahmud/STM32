################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := LedToggle_F411_bitwise
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LedToggle_F411_bitwise.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LedToggle_F411_bitwise.list \

OBJCOPY_BIN += \
LedToggle_F411_bitwise.bin \


# All Target
all: main-build

# Main-build Target
main-build: LedToggle_F411_bitwise.elf secondary-outputs

# Tool invocations
LedToggle_F411_bitwise.elf: $(OBJS) $(USER_OBJS) F:\Embedded\EmbedMasterCourse\Embedded-C\My_workspace\target\LedToggle_F411_bitwise\STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "LedToggle_F411_bitwise.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\Embedded\EmbedMasterCourse\Embedded-C\My_workspace\target\LedToggle_F411_bitwise\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LedToggle_F411_bitwise.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LedToggle_F411_bitwise.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LedToggle_F411_bitwise.list"
	@echo 'Finished building: $@'
	@echo ' '

LedToggle_F411_bitwise.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LedToggle_F411_bitwise.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
