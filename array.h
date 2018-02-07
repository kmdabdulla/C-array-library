//array.h header file
#ifndef _array__h
#define _array__h
 
struct arr_diff {

        int *data;
        int arraySize;

};

int** array_chunk(int*, int, int); 
struct arr_diff array_diff(int*, int*,int,int);
#endif
