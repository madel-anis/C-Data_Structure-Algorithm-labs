#include "Search_Algorithms.h"
#include <stdio.h>


/* this function used to search specific memeber in an array of numbers */
/* BIG O-Notation :  O(N) */

int Sequential_Search(int *arr , int size , int match_Number)
{
	int iteration_index;
	int matched_index = -1;
	
	for(iteration_index = 0 ; iteration_index< size ; iteration_index++)
	{
		if( arr[iteration_index] == match_Number )
		{
			matched_index = iteration_index;
			break;
		}
		else
		{
			/* Do Nothing */
		}
	}
	
	return matched_index;
}

/* This function used to search specific memeber in an array of numbers with Binary search without recursive */
/* The Array needs to be sorted */
/* BIG O-Notation :  O(N LOG N) */
int Binary_Search(int *arr , int size , int match_Number)
{
	int Start_index    = 0;
	int End_Index      = size-1;
	int Mid_index      = 0;
	int Exit_Flag      = 0;
	int matched_index  = -1;
	
	while(Start_index <= End_Index && Exit_Flag == 0)
	{
		Mid_index = (Start_index + End_Index)/2;
		
		if( arr[Mid_index] == match_Number )
		{
			matched_index = Mid_index;
			Exit_Flag     = 1;
		}
		else if(arr[Mid_index] < match_Number)
		{
			Start_index = Mid_index;
		}
		else if(arr[Mid_index] > match_Number)
		{
			End_Index = Mid_index;
		}
	}
	return matched_index;
}