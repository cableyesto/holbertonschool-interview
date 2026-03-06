#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);

int get_max(int *array, size_t size);
void counting_sort_digit(int *array, size_t size, int exp, int *output);
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
