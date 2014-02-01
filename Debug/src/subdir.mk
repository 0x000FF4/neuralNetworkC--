################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/file_reader.cpp \
../src/hiddenLayer.cpp \
../src/inputLayer.cpp \
../src/layer.cpp \
../src/main.cpp \
../src/main_network.cpp \
../src/neuronData.cpp \
../src/neuron_linker.cpp \
../src/outputLayer.cpp \
../src/parallel.cpp 

OBJS += \
./src/file_reader.o \
./src/hiddenLayer.o \
./src/inputLayer.o \
./src/layer.o \
./src/main.o \
./src/main_network.o \
./src/neuronData.o \
./src/neuron_linker.o \
./src/outputLayer.o \
./src/parallel.o 

CPP_DEPS += \
./src/file_reader.d \
./src/hiddenLayer.d \
./src/inputLayer.d \
./src/layer.d \
./src/main.d \
./src/main_network.d \
./src/neuronData.d \
./src/neuron_linker.d \
./src/outputLayer.d \
./src/parallel.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DQT_CC_GNU=1 -DQT_CORE_LIB=1 -DQT_GUI_LIB=1 -DQT_NO_DEBUG=1 -DQT_SHARED=1 -DQT_TESTLIB_LIB=1 -DQT_WEBKIT=1 -I/home/x000ff4/Свалени/boost_1_55_0/ -I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


