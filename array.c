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

struct arr_diff array_diff(int *array1, int *array2, int array1_Size, int array2_Size) { //function to check the difference between two arrays

	/* 

	 *array1 - pointer to array to be comapared
	 *array2 - pointer to array to compared with

	 return a struct which contains difference array and its size*/

	int i,j,flag=0,count=0;
	struct arr_diff diff; 
	int *data = malloc(array1_Size*sizeof(int));
	for(i=0;i<array1_Size;i++) {
		for(j=0;j<array2_Size;j++) {
			if(array1[i]==array2[j]) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			*(data+count) = array1[i];
			count++;
		}
		flag=0;
	}
	diff.data = data;
	diff.arraySize = count;
	return diff;

}

int in_array(int *array,int arraySize,int val) { //function to check whether value exists in an array or not

	/* 
	 *array - pointer to array
	 arraySize - size of the array
	 val - value to be checked 	

	 return 1 if exists otherwise 0
	 */
	int i;
	for(i=0;i<arraySize;i++) {
		if(array[i]==val) {
			return 1;
		}
		return 0;
	}	


}

int* unset(int *array,int arraySize,int val, int key) { //function to remove the element in an array based on key or value


	/* *array - pointer to array
	   arraySize - size of the array
	   val - value or key to be removed 
	   key - boolean value which tells whether the value that is contained in 
	   val variable is a key or actual value itself.
	   key = (can take 0 or 1) 0 means value in the val variable is actual value itself 
		 1 means value in val variable is the key in the array to be removed

	   returns the pointer to the array of the new array with element removed
	 */

	int i,count=0;
	int *data = calloc(arraySize-1,sizeof(int));
	for(i=0;i<arraySize;i++) {
		if(key==0) { 
			if(array[i]!=val) {
				data[count] = array[i];
				count++;        
			}
		} else {
			if(i!=val) {
				data[count] = array[i];	
				count++; 
			}

		}	

	}

	return data;


}	  
