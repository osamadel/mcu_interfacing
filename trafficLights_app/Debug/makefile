################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

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
libtrafficLights_app.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libtrafficLights_app.a secondary-outputs

# Tool invocations
libtrafficLights_app.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libtrafficLights_app.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libtrafficLights_app.lss: libtrafficLights_app.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libtrafficLights_app.a  >"libtrafficLights_app.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libtrafficLights_app.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 libtrafficLights_app.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) libtrafficLights_app.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
