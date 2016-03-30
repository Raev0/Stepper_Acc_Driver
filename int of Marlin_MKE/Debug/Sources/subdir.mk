################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/Planner.c \
../Sources/Scheduler.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/Planner.o \
./Sources/Scheduler.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/Planner.d \
./Sources/Scheduler.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/System" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/PDD" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Static_Code/IO_Map" -I"D:\Freescale\KDS_3.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Sources" -I"D:/Users/todd/workspace.kds/int of Marlin_MKE/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


