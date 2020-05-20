#include "Sort_Algorithms.h"
#include <stdio.h>
#include <stdlib.h>


/* Static Prototypes */
void Swap(int *first , int *Second);
void Merge(int *arr , int *Left_Section , int *right_Section , int Left_Section_size , int Right_Section_size);



/* APIs */

/* this function used to sort array using the selection sort alogrithm */
/* BIG O-Notation :  O(N^2) */
void Selection_Sort(int *arr , int size)
{
	int iteration_index_i ;
	int iteration_index_j ;
	int smallest_value_index;
	
	for(iteration_index_i = 0 ; iteration_index_i <size ; iteration_index_i++)
	{
		smallest_value_index = iteration_index_i;
		
		for(iteration_index_j = iteration_index_i ; iteration_index_j < size ; iteration_index_j++)
		{
			if( arr[iteration_index_j] < arr[smallest_value_index] )
			{
				smallest_value_index = iteration_index_j;
			}
		}
		
		if(smallest_value_index != iteration_index_i )
		{
			Swap(&arr[smallest_value_index] , &arr[iteration_index_i]);
		}
	}
}

/* this function used to sort array using the selection sort alogrithm */
/* BIG O-Notation :  O(N^2) */
void Bubble_Sort(int *arr , int size)
{
	int iteration_index_i ;
	int iteration_index_j ;
	
	for(iteration_index_i = 0 ; iteration_index_i <size-1 ; iteration_index_i++)
	{
		for(iteration_index_j = 0 ; iteration_index_j < (size-iteration_index_i-1) ; iteration_index_j++)
		{
			if(arr[iteration_index_j] > arr[iteration_index_j+1])
			{
				Swap(&arr[iteration_index_j] , &arr[iteration_index_j+1]);
			}
		}
	}
}


/* this function used to sort array using the selection sort alogrithm */
/* BIG O-Notation :  O(N Log N) */
void Merge_Sort(int *arr , int size)
{
	if(size < 2)
	{
		return;
	}
	else
	{
		int Left_Section_Size  = size/2;
		int Right_Section_Size = size-Left_Section_Size;
		
		int* Left_Section  = (int *) malloc( Left_Section_Size  * sizeof(int));
		int* Right_Section = (int *) malloc( Right_Section_Size * sizeof(int));
		
		int iteration_index;
		
		for(iteration_index = 0 ;  iteration_index <Left_Section_Size ; iteration_index++)
		{
			Left_Section[iteration_index] = arr[iteration_index];
		}
		
		for(iteration_index = Left_Section_Size ;  iteration_index <size ; iteration_index++)
		{
			Right_Section[iteration_index-Left_Section_Size] = arr[iteration_index];
		}
		
		Merge_Sort(Left_Section  , Left_Section_Size);
		Merge_Sort(Right_Section , Right_Section_Size);
		Merge(arr , Left_Section , Right_Section , Left_Section_Size , Right_Section_Size);
		
		free(Left_Section);
		free(Right_Section);
	}

	
	
	
}





/* Static Functions */
void Swap(int *First , int *Second)
{
	*First  = *First  ^ *Second;
	*Second = *Second ^ *First;
	*First  = *First  ^ *Second;
}


void Merge(int *arr , int *Left_Section , int *right_Section , int Left_Section_size , int Right_Section_size)
{
	int left_index  = 0;
	int Right_index = 0;
	int main_index  = 0;
	
	while( (left_index < Left_Section_size) && (Right_index < Right_Section_size) )
	{
		if( Left_Section[left_index] <= right_Section[Right_index])
		{
			arr[main_index] = Left_Section[left_index];
			left_index++;
		}
		else if( right_Section[Right_index] < Left_Section[left_index] )
		{
			arr[main_index] = right_Section[Right_index];
			Right_index++;
		}
		main_index++;
	}
	
	while( left_index < Left_Section_size )
	{
		arr[main_index] = Left_Section[left_index];
		left_index++;
		main_index++;
	}
	
	while( Right_index < Right_Section_size )
	{
		arr[main_index] = right_Section[Right_index];
		Right_index++;
		main_index++;
	}
}