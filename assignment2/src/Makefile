#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# A simple cross-compiling build system for an MSP432 project
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build - Build the target executable and display the size
#      		of the compiled sections (default)
#      compile-all - Compile all object files but do not link
#      clean - Remove all build artifacts
#      <FILE>.i - Generate the preprocessed output of <FILE>
#      <FILE>.asm - Generate the assembly output of <FILE> 
#      <FILE>.o - Generate the object file for <FILE>
#
# Platform Overrides:
#      PLATFORM=HOST - Compile for the host system (default)
#      PLATFORM=MSP432 - Cross-compile for the target system
#
#------------------------------------------------------------------------------
include sources.mk

# Name-stem of executable to build
TARGET = c1m2

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4 
ARCH = armv7e-m
THUMB = thumb
FLOATABI = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs 
MSPFLAGS = -mcpu=$(CPU) -m$(THUMB) -march=$(ARCH) -mfloat-abi=$(FLOATABI) -mfpu=$(FPU) --specs=$(SPECS)

# Compiler Flags and Defines
LDFLAGS = -Wl,-Map=$(TARGET).map 
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(INCLUDES)
CPPFLAGS = 

ifeq ($(PLATFORM),HOST)
	CC = gcc 
	LD = ld
	SIZE = size
else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc 
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	
	CFLAGS += $(MSPFLAGS)
	LDFLAGS += -T $(LINKER_FILE)
endif


# Files
OBJS = $(SOURCES:.c=.o)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^
	$(SIZE) $@

%.i: %.c
	$(CPP) -o $@ $(CPPFLAGS) $(CFLAGS) $^

%.asm: %.c
	$(CC) -S -o $@ $(CFLAGS) $^

$(TARGET).asm: $(TARGET).out
	objdump -d $^ > $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET).out $(TARGET).map $(OBJS:.o=.i) $(OBJS:.o=.asm) $(TARGET).asm
