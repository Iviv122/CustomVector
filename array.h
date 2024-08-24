#include <stdio.h>
#include <stdlib.h>

typedef struct{

int* data;
size_t size;
size_t capacity;

} array;

void init_array(array *arr){

arr->size =0;
arr->capacity =4;
arr->data = (int*)calloc(arr->capacity,sizeof(int));
if(arr->data == NULL){
 fprintf(stderr,"Memory allocation failed \n");
 exit(1);
}
}

void push_back(array *arr, int value){

if(arr->size>=arr->capacity){
	arr->capacity +=1;  // but generally should be *=2, less reallocations,better perfomance
	arr->data = (int*)realloc(arr->data,arr->capacity*sizeof(int));
	if(!arr->data){
	fprintf(stderr,"Memory reallocation failed");
	}	
}
arr->data[arr->size] = value;
arr->size++; 
}

int get(array *arr, size_t index){

if(index >= arr->size){
 fprintf(stderr,"Index out of array");
 exit(1);
}
 return arr->data[index];
}

void array_free(array *arr){
free(arr->data);
arr->data = NULL;
arr->size = 0;
arr->capacity = 0;
}
