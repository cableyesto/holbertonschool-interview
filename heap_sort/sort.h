#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Printing function */
void print_array(const int *array, size_t size);

/* Sorting algorithm */
void heap_sort(int *array, size_t size);

#endif /* SORT_H */