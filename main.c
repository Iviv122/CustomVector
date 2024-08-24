#include <stdio.h>
#include <stdlib.h>
#include "array.h"
int main(){

array arr;

init_array(&arr);

push_back(&arr,10);

printf("%d\n",get(&arr,0));
printf("%d\n",arr.data[0]);

array_free(&arr);
}
