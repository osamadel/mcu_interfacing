################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
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
MDIO_app.lss \

FLASH_IMAGE += \
MDIO_app.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: MDIO_app.elf secondary-outputs

# Tool invocations
MDIO_app.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MDIO_app.map -mmcu=atmega32 -o "MDIO_app.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MDIO_app.lss: MDIO_app.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MDIO_app.elf  >"MDIO_app.lss"
	@echo 'Finished building: $@'
	@echo ' '

MDIO_app.hex: MDIO_app.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MDIO_app.elf  "MDIO_app.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MDIO_app.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MDIO_app.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: MDIO_app.elf
	@echo 'Invoking: AVRDude'
	E:\ITI 3 Months\04- Microcontroller Interfacing\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -u -Uflash:w:MDIO_app.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MDIO_app.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
