################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AdresseTesteur.cpp \
../CandidatTesteur.cpp \
../CirconscriptionTesteur.cpp \
../DateTesteur.cpp \
../ElecteurTesteur.cpp \
../PersonneTesteur.cpp 

OBJS += \
./AdresseTesteur.o \
./CandidatTesteur.o \
./CirconscriptionTesteur.o \
./DateTesteur.o \
./ElecteurTesteur.o \
./PersonneTesteur.o 

CPP_DEPS += \
./AdresseTesteur.d \
./CandidatTesteur.d \
./CirconscriptionTesteur.d \
./DateTesteur.d \
./ElecteurTesteur.d \
./PersonneTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++03 -I"/home/etudiant/workspace/TP4/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


