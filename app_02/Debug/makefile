################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
app_02.lss \

FLASH_IMAGE += \
app_02.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: app_02.elf secondary-outputs

# Tool invocations
app_02.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,app_02.map -mmcu=atmega32 -o "app_02.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

app_02.lss: app_02.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S app_02.elf  >"app_02.lss"
	@echo 'Finished building: $@'
	@echo ' '

app_02.hex: app_02.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex app_02.elf  "app_02.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: app_02.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 app_02.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: app_02.elf
	@echo 'Invoking: AVRDude'
	E:\ITI 3 Months\04- Microcontroller Interfacing\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -u -Uflash:w:app_02.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) app_02.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
