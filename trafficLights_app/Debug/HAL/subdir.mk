################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HKeyPad_program.c \
../HAL/HLCD_program.c \
../HAL/HLED_program.c \
../HAL/HNPN_program.c \
../HAL/HSevenSegments_program.c 

OBJS += \
./HAL/HKeyPad_program.o \
./HAL/HLCD_program.o \
./HAL/HLED_program.o \
./HAL/HNPN_program.o \
./HAL/HSevenSegments_program.o 

C_DEPS += \
./HAL/HKeyPad_program.d \
./HAL/HLCD_program.d \
./HAL/HLED_program.d \
./HAL/HNPN_program.d \
./HAL/HSevenSegments_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


