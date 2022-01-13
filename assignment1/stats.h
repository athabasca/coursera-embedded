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
 * @file stats.h
 * @brief Statistical function library 
 *
 * <Add Extended Description Here>
 *
 * @author Athabasca
 * @date January 2022 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints statistics of an array.
 *
 * print_statistics() prints the minimum, maximum,
 * mean, and median of an unsigned char array.
 * Statistics are rounded down to the nearest integer.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return void
 */
void print_statistics(unsigned char * array, unsigned int length);


/**
 * @brief Prints an array.
 *
 * print_array() prints an unsigned char array
 * with nice formatting.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return void
 */
void print_array(unsigned char * array, unsigned int length);

/**
 * @brief Calculates the minimum value
 *
 * find_minimum() takes an array of unsigned chars and returns
 * the minimum value in the array. The length of the array must
 * be passed in as well.
 * Statistics are rounded down to the nearest integer.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return An unsigned char containing the minimum value
 */
unsigned char find_minimum(unsigned char * array, unsigned int length);


/**
 * @brief Calculates the maximum value
 *
 * find_maximum() takes an array of unsigned chars and returns
 * the maximum value in the array. The length of the array must
 * be passed in as well.
 * Statistics are rounded down to the nearest integer.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return An unsigned char containing the maximum value
 */
unsigned char find_maximum(unsigned char * array, unsigned int length);


/**
 * @brief Calculates the mean value
 *
 * find_mean() takes an array of unsigned chars and returns
 * the mean value in the array. The length of the array must
 * be passed in as well.
 * Statistics are rounded down to the nearest integer.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return An unsigned char containing the mean value
 */
unsigned char find_mean(unsigned char * array, unsigned int length);


/**
 * @brief Calculates the median value
 *
 * find_median() takes an array of unsigned chars and returns
 * the median value in the array. The length of the array must
 * be passed in as well.
 * Statistics are rounded down to the nearest integer.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return An unsigned char containing the median value
 */
unsigned char find_median(unsigned char * array, unsigned int length);

/**
 * @brief Sorts an array
 *
 * sort_array() takes an array of unsigned chars and sorts it in place.
 * The length of the array must be passed in.
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return void
 */
void sort_array(unsigned char * array, unsigned int length);



#endif /* __STATS_H__ */
