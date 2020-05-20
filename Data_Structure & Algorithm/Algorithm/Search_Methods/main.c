#include <stdio.h>

#include "Search_Algorithms.h"


int main(void)
{
	
	int arr[]={0,1,2,3,4,5,6,7,8,9,10};

	printf("index = %d\n", Sequential_Search(arr , sizeof(arr)/sizeof(arr[0]) , 7));
	printf("index = %d\n", Binary_Search(arr , sizeof(arr)/sizeof(arr[0]) , 7));

	return 0;
}