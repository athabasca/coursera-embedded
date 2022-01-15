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
 * @file stats.c
 * @brief Test program to calculate stats
 *
 * This program sorts and calculates several statistics about an array 
 * of 8-bit integers. It prints the array, sorted from largest to smallest
 * value, then prints the min, max, mean, and median values, rounded down.
 *
 * @author Athabasca
 * @date January 2022 
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  sort_array(test, SIZE);
  print_array(test, SIZE);
  print_statistics(test, SIZE);
}


void print_statistics(unsigned char * array, unsigned int length) {
  unsigned char min = 0, max = 0, mean = 0, median = 0;
  min = find_minimum(array, length);
  max = find_maximum(array, length);
  mean = find_mean(array, length);
  median = find_median(array, length);

  printf("Minimum: %u  Maximum: %u  Mean: %u  Median: %u\n", min, max, mean, median);
}

void print_array(unsigned char * array, unsigned int length) {
  for(unsigned int ii = 0; ii < length; ii++) {
    printf("%u", array[ii]);
    if(ii % 10 == 9) {
      printf("\n");
    }
    else {
      printf("  ");
    }
  }
}

unsigned char find_minimum(unsigned char * array, unsigned int length) {
  if(0 == length) {
    return 0;
  }
  unsigned char min = 255;
  for(unsigned int ii = 0; ii < length; ii++) {
	  if(array[ii] < min) { min = array[ii]; }
  }
  return min;
}

unsigned char find_maximum(unsigned char * array, unsigned int length) {
  if(0 == length) {
    return 0;
  }
  unsigned char max = 0;
  for(unsigned int ii = 0; ii < length; ii++) {
	  if(array[ii] > max) { max = array[ii]; }
  }
  return max;
}

unsigned char find_mean(unsigned char * array, unsigned int length) {
  if(0 == length) {
    return 0;
  }
  unsigned int sum = 0;
  for(unsigned int ii = 0; ii < length; ii++) {
    sum += array[ii];
    // Does not account for overflow
  }
  return (unsigned char)(sum / length); // Integer division discards the fractional part
}

unsigned char find_median(unsigned char * array, unsigned int length) {
  return 0;
}

void sort_array(unsigned char * array, unsigned int length) {
  // This function implements quicksort to sort array in place
  // in descending order.

  // If the list has 0 or 1 elements, it doesn't need to be sorted.
  if(length <= 1) { return; }

  // The first element of the array is the pivot.
  unsigned int ii = 1, jj = length - 1, temp = 0;
  /*while(ii <= jj && ii < length - 1 && jj > 0) {
    if(array[ii] <= array[0] && array[jj] >= array[0]) {
	    // Swap elements ii and jj.
      temp = array[ii]; array[ii] = array[jj]; array[jj] = temp;
    }
    if(array[ii] > array[0]) { ii++; }
    if(array[jj] <= array[0]) { jj--; }
  }*/
  
  while(1) {
    while(array[ii] > array[0] && ii < length - 1) {
      ii++;
    }

    while(array[jj] <= array[0] && jj > 0) {
      jj--;
    }

    if(ii >= jj) {
      break;
    }

    temp = array[ii];
    array[ii] = array[jj];
    array[jj] = temp;
  }
  // Swap the pivot and final unpartitioned element.
  temp = array[0]; array[0] = array[jj]; array[jj] = temp;

  // Recursively sort the partitioned sublists.
  sort_array(array, jj);
  sort_array(&array[ii], length - ii);
  return;
}

