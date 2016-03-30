################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd10.c \
../Generated_Code/BitIoLdd11.c \
../Generated_Code/BitIoLdd12.c \
../Generated_Code/BitIoLdd13.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/BitIoLdd5.c \
../Generated_Code/BitIoLdd6.c \
../Generated_Code/BitIoLdd7.c \
../Generated_Code/BitIoLdd8.c \
../Generated_Code/BitIoLdd9.c \
../Generated_Code/Cpu.c \
../Generated_Code/DA1.c \
../Generated_Code/E0_DIR.c \
../Generated_Code/E0_EN_INVERSE.c \
../Generated_Code/E0_STE.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/RELAY.c \
../Generated_Code/ST_PULSE_TI.c \
../Generated_Code/TU1.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/X_DIR.c \
../Generated_Code/X_EN_INVERSE.c \
../Generated_Code/X_STE.c \
../Generated_Code/Y_DIR.c \
../Generated_Code/Y_EN_INVERSE.c \
../Generated_Code/Y_STE.c \
../Generated_Code/Z_DIR.c \
../Generated_Code/Z_EN_INVERSE.c \
../Generated_Code/Z_STE.c 

OBJS += \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd10.o \
./Generated_Code/BitIoLdd11.o \
./Generated_Code/BitIoLdd12.o \
./Generated_Code/BitIoLdd13.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/BitIoLdd5.o \
./Generated_Code/BitIoLdd6.o \
./Generated_Code/BitIoLdd7.o \
./Generated_Code/BitIoLdd8.o \
./Generated_Code/BitIoLdd9.o \
./Generated_Code/Cpu.o \
./Generated_Code/DA1.o \
./Generated_Code/E0_DIR.o \
./Generated_Code/E0_EN_INVERSE.o \
./Generated_Code/E0_STE.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/RELAY.o \
./Generated_Code/ST_PULSE_TI.o \
./Generated_Code/TU1.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/X_DIR.o \
./Generated_Code/X_EN_INVERSE.o \
./Generated_Code/X_STE.o \
./Generated_Code/Y_DIR.o \
./Generated_Code/Y_EN_INVERSE.o \
./Generated_Code/Y_STE.o \
./Generated_Code/Z_DIR.o \
./Generated_Code/Z_EN_INVERSE.o \
./Generated_Code/Z_STE.o 

C_DEPS += \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd10.d \
./Generated_Code/BitIoLdd11.d \
./Generated_Code/BitIoLdd12.d \
./Generated_Code/BitIoLdd13.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/BitIoLdd5.d \
./Generated_Code/BitIoLdd6.d \
./Generated_Code/BitIoLdd7.d \
./Generated_Code/BitIoLdd8.d \
./Generated_Code/BitIoLdd9.d \
./Generated_Code/Cpu.d \
./Generated_Code/DA1.d \
./Generated_Code/E0_DIR.d \
./Generated_Code/E0_EN_INVERSE.d \
./Generated_Code/E0_STE.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/RELAY.d \
./Generated_Code/ST_PULSE_TI.d \
./Generated_Code/TU1.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/X_DIR.d \
./Generated_Code/X_EN_INVERSE.d \
./Generated_Code/X_STE.d \
./Generated_Code/Y_DIR.d \
./Generated_Code/Y_EN_INVERSE.d \
./Generated_Code/Y_STE.d \
./Generated_Code/Z_DIR.d \
./Generated_Code/Z_EN_INVERSE.d \
./Generated_Code/Z_STE.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/System" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/PDD" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/IO_Map" -I"D:\Freescale\KDS_3.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Sources" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


