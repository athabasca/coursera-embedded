/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/**
 * @file misc.h 
 * @brief This file is to be used for the c1m2 assesment
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include "misc.h"

#define SOME_VALUE (6)

int g5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/*
The code for func goes in the .text segment of the code section. The parameter f1 goes in register r0, according to the ARM calling convention. Local variables go in registers r4-r11 and the return value goes in r0.
In practice, f3 goes on the stack at sp offset 12. f4 goes on the stack at offset 8. 
f2, being a static local variable, keeps its value across invocations of func. It goes in .bss.
*/
int func(int * f1)
{
  static int f2;
  unsigned int f3 = 0;
  volatile char * f4 = "Hello World!\n";

  f2++;
  *(&g5[0] + f2) = f3;

  for (f3 = 0; f3 < SOME_VALUE; f3++)
  {
    g5[f3] = f4[f3];
    f2++;
  }

  return f2;
}

