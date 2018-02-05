#include "math.h"
#include "stdlib.h"
#include "array.h"

int** array_chunk(int *array, int arraySize, int chunkSize) { //function to chunk the array with the given chunk size 
	/*
            *array - pointer to array to be chunked
            arraySize - number of elements in the array
            chunkSize - number of elements to be in each array chunk
           
            return a pointer to the two dimensional array which contains the chunked arrays 
	*/
	int i,j;         
	float arrSize = (float)arraySize;
	int row = (int)ceil(arrSize/chunkSize);
	int **data = calloc(row,sizeof(int*));
	for(i=0;i<row;i++) {
		data[i] = calloc(chunkSize,sizeof(int));
		for(j=0;j<chunkSize;j++) {
			data[i][j] = array[(i*chunkSize)+j];
		}
	}
	return data;
}


