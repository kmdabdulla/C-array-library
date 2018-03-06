//array.h header file
#ifndef _array__h
#define _array__h

struct new_array {

	int *data;
	int arraySize;

};


int** array_chunk(int*, int, int); 
struct new_array array_diff(int*, int*,int,int);
int in_array(int*,int,int);
int* unset(int*,int,int,int);
struct new_array remove_duplicates_by_value(int*,int,int);
struct new_array array_pop(int*,int);
struct new_array array_push(int*,int,int);
struct new_array array_slice(int*,int, int, int);
int array_sum(int*,int);
int array_product(int*,int);
int* array_reverse(int*,int);
int array_search(int *array, int arraySize,int val)
#endif
