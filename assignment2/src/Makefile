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
#      build - Compile all object files and link into a final executable
#      compile-all - Compile all object files but do not link
#      clean - Remove all build artifacts
#      <FILE>.i - Generate the preprocessed output of <FILE>
#      <FILE>.asm - Generate the assembly output and final executable of <FILE> 
#      <FILE>.o - Generate the object file for <FILE>
#
# Platform Overrides:
#      PLATFORM=HOST - Compile for the host system
#      PLATFORM=MSP432 - Cross-compile for the target system
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = 
LD = 
LDFLAGS = 
CFLAGS = 
CPPFLAGS = 

