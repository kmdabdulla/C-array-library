#include "math.h"
#include "stdlib.h"
#include "string.h"
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

struct new_array array_diff(int *array1, int *array2, int array1_Size, int array2_Size) { //function to check the difference between two arrays

	/* 

	 *array1 - pointer to array to be comapared
	 *array2 - pointer to array to compared with

	 return a struct which contains difference array and its size*/

	int i,j,flag=0,count=0;
	struct new_array diff; 
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

	   returns the pointer to the new array with element removed
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

struct new_array remove_duplicates_by_value(int *array, int arraySize, int val) { //function to remove the duplicates of passed value

	/*	
	*array - pointer to array
           arraySize - size of the array
           val - value to be found for duplicates

	 return a struct which contains mentioned duplicate elements removed array and its size
	*/
	int i,count=0,val_count=0;
	struct new_array duplicate_removed;
	int *data = calloc(arraySize,sizeof(int));
	for(i=0;i<arraySize;i++) {
		if(array[i]==val) {
		   val_count++;	
		  if(val_count>1) {
			continue;
		     }
		 }
		  data[count] = array[i];	
		  count++;	 
	}
	
	duplicate_removed.arraySize = count;
	duplicate_removed.data = data;
	return duplicate_removed;


}


struct new_array array_pop(int *array,int arraySize) { //function to remove the last element from the array and return it

	/*
        *array - pointer to array
	arraySize - size of the array
	
	return a struct which contains the last element and the pointer to new array.*/
	struct new_array arraypop;
	int *data = calloc(arraySize-1,sizeof(int));
	memcpy(data,array,((arraySize-1)*sizeof(int)));
	arraypop.arraySize = array[arraySize-1];
	arraypop.data = data;
	return arraypop;
}


struct new_array array_push(int *array, int arraySize, int val) { //function to push an element to an array

    /*
     *array - pointer to array
     arraySize - size of the array
     
     return a struct which contains the pointer to the new array and count of the array*/
        struct new_array arraypush;
        int *data = calloc(arraySize+1,sizeof(int));
        memcpy(data,array,((arraySize)*sizeof(int)));
	data[arraySize] = val;
        arraypush.arraySize = arraySize+1;
        arraypush.data = data;
        return arraypush;		


}	

struct new_array array_slice(int *array,int arraySize, int startIndex, int length) { //array to return an slice of an array


	/* 
	*array - pointer to the array
	arraySize - size of the array
	startIndex - starting point for slicing
	Length - Length of the slice
	
	return a struct which contains new sliced array and its count*/
	int i,count=0;
	struct new_array arraySlice;
	int *data = calloc((startIndex+length-1),sizeof(int));
	for(i=startIndex;i<length-1;i++) {
		data[count]= array[i];
		count++;
	}
	arraySlice.arraySize = count;
	arraySlice.data = data;
	return arraySlice;

}

int array_sum(int *array,int arraySize) { //function to add all elements of an array

  	/*
	 *array - pointer to an array
	 arraySize -  size of an array
	
	 return the sum of all elements of an array*/
	
	 int i,sum=0;
	 for(i=0;i<arraySize;i++) {
		sum+=array[i];

	 }
		
	 return sum;

}

int array_product(int *array,int arraySize) { //function to multiply all elements of an array

        /*
         *array - pointer to an array
         arraySize -  size of an array
        
         return the product of all elements of an array*/
        
         int i,product=0;
         for(i=0;i<arraySize;i++) {
		if(array[i]==0) {
		  return 0;	
		}
                product*=array[i];

         }
         return product;

}

int* array_reverse(int *array, int arraySize) { //function to return elements in reverse order

	/*
	*array - pointer to the array
	arraySize - size of the array

	return the pointer to the new array which contains the elements in reverse order*/
	
	int i,count=0;
	int *data = calloc(arraySize,sizeof(int));
	for(i=arraySize-1;i>=0;i--) {
	   data[count] = array[i];
	   count++;	
	}
	return *data;

}
