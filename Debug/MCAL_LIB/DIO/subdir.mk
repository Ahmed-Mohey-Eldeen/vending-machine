################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_LIB/DIO/DIO_Prog.c 

OBJS += \
./MCAL_LIB/DIO/DIO_Prog.o 

C_DEPS += \
./MCAL_LIB/DIO/DIO_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_LIB/DIO/%.o: ../MCAL_LIB/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


