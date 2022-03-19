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
 * @file main.c
 * @brief This file is to be used for the c1m3 assessment.
 *
 * This file provides various memory allocations. The learner will need
 * to analyze the code's memory footprint for this assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "misc.h"

/*
From 'nm c1m3.out':
2000088c b g1
00000d50 R g2
20000004 D g3
20000890 B g4
20000008 D g5

b and B mean the symbol is in .bss. According to man nm, lowercase means local and uppercase means global; since g1 and g4 are both globals, I assume the difference comes from the static storage class of g1 or the zero-initialization of g4. R means read-only data, D means initialized data.

Thus, g1 and g4 are in the .bss segment of the data section, which has RW permissions.
g2, being constant, is in the .rodata segment of the code section, with RX permissions.
g3 and g5 are in the .data segment of the data section, again with RW permissions.

All of these symbols have global scope and program lifetime.
*/
static int g1;
const int g2 = 45;
char g3 = 12;
char g4 = 0;
extern char g5[N];

/*
main is in the .text segment of the code section, with RX permissions. It has global scope and program lifetime.

Local variables l1, l2, and l3 have local scope and function lifetime, though the dynamically allocated memory pointed to by l2 lives until it is freed. It is never freed (causing a memory leak), so its lifetime ends when the program does. Local variables go in registers r4-r11 in the ARM calling convention. However, from reading the assembly, it appears that some local variables still go on the stack: l3 at sp offset 0 and l2 at sp offset 4. l1 (with register type qualifier) is in r4.

The register keyword suggests to the compiler that l1 go in a register rather than on the stack.

The volatile keyword says that the value of a variable l3 may be modified in ways unknown to the surrounding code. For example, hardware may change the value of a variable correspondng to a memory-mapped I/O port. The compiler should not optimize statements using volatile variables.
*/
int main()
{
  register int l1;
  int * l2;
  volatile int l3 = 12;
  
  l2 = (int *) malloc( N * g2 * sizeof(char) );

  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  {
    g1 = func(l2);
  }

  return 0;
}

