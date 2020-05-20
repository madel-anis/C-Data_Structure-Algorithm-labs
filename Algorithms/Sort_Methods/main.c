#include <stdio.h>

#include "Sort_Algorithms.h"


int main(void)
{
	int index;
	int arr[]={4,2,8,5,9,6,3,1,7,5,2,6,7};

	//Selection_Sort(arr , sizeof(arr)/sizeof(arr[0]));
	//Bubble_Sort( arr , sizeof(arr)/sizeof(arr[0]) );
	Merge_Sort(arr , sizeof(arr)/sizeof(arr[0]) );
	for(index = 0 ; index < (sizeof(arr)/sizeof(arr[0])) ; index++ )
	{
		printf("element %d = %d\n",index,arr[index] );
	}
	//printf("index = %d\n", Binary_Search(arr , sizeof(arr)/sizeof(arr[0])));

	return 0;
}