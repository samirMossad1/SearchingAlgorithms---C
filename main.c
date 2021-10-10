


#include <stdio.h>
#include "searchingAlgorithms.h"
#include "std_types.h"


void inputIntArray(sint32*,uint16);
void printIntArray(sint32*,uint16);
void swapTwoElements(sint32*,sint32*);
sint32* getIndexReference(sint32*,uint16);
uint8 compareTwoElements(sint32*,sint32*);
uint8 heapCompare(sint32*,sint32*);
void copyArray(sint32*,sint32*,uint16);


int main(void)
{

//	sint32 returnIndex, array[10],arrayCopy[10];
//	inputIntArray(array,10);


#if 0

	copyArray(arrayCopy,array,5);
	returnIndex = linearSearch(arrayCopy,5,0,getIndexReference);
	printf("Linear Search Index: %d\n",returnIndex);
	returnIndex = linearSearch(arrayCopy,5,1,getIndexReference);
	printf("Linear Search Index: %d\n",returnIndex);


	printf("\n\n");

	copyArray(arrayCopy,array,5);
	returnIndex = linearSearch_sortedList(arrayCopy,5,0,getIndexReference);
	printf("Linear Search _Sorted List_ Index: %d\n",returnIndex);
	returnIndex = linearSearch_sortedList(arrayCopy,5,1,getIndexReference);
	printf("Linear Search _Sorted List_ Index: %d\n",returnIndex);
	returnIndex = linearSearch_sortedList(arrayCopy,5,3,getIndexReference);
	printf("Linear Search _Sorted List_ Index: %d\n",returnIndex);


	printf("\n\n");




	copyArray(arrayCopy,array,5);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,0,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Transpose: %d\n",returnIndex);


	printf("\n\n");


	copyArray(arrayCopy,array,5);
	returnIndex = linearSearch_SelfOrganized_TRN(arrayCopy,5,0,getIndexReference,swapTwoElements);
	printf("Linear Search Index Move To Front: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_MTF(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Move To Front: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_MTF(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Move To Front: %d\n",returnIndex);
	returnIndex = linearSearch_SelfOrganized_MTF(arrayCopy,5,1,getIndexReference,swapTwoElements);
	printf("Linear Search Index Move To Front: %d\n",returnIndex);

#endif



#if 0

	copyArray(arrayCopy,array,5);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,0,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,1,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,2,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,3,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,4,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterative(arrayCopy,0,4,5,getIndexReference);
	printf("Binary Search Iterative Index: %d\n",returnIndex);


	printf("\n\n");


	copyArray(arrayCopy,array,6);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,0,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,1,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,2,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,3,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,4,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,5,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursive(arrayCopy,0,5,6,getIndexReference);
	printf("Binary Search Recursive Index: %d\n",returnIndex);

#endif

#if 0

	printf("\n\n");

	copyArray(arrayCopy,array,5);
	returnIndex = binarySearch_iterativeFirstMatch(arrayCopy,0,4,4,getIndexReference);
	printf("Binary Search Iterative First Match Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterativeFirstMatch(arrayCopy,0,4,2,getIndexReference);
	printf("Binary Search Iterative First Match Index: %d\n",returnIndex);


	printf("\n\n");

	copyArray(arrayCopy,array,5);
	returnIndex = binarySearch_recursiveFirstMatch(arrayCopy,0,4,4,getIndexReference);
	printf("Binary Search Recursive First Match Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursiveFirstMatch(arrayCopy,0,4,2,getIndexReference);
	printf("Binary Search Recursive First Match Index: %d\n",returnIndex);


	printf("\n\n");

	copyArray(arrayCopy,array,5);
	returnIndex = binarySearch_iterativeLastMatch(arrayCopy,0,4,4,getIndexReference);
	printf("Binary Search Iterative Last Match Index: %d\n",returnIndex);
	returnIndex = binarySearch_iterativeLastMatch(arrayCopy,0,4,2,getIndexReference);
	printf("Binary Search Iterative Last Match Index: %d\n",returnIndex);

	printf("\n\n");

	copyArray(arrayCopy,array,5);
	returnIndex = binarySearch_recursiveLastMatch(arrayCopy,0,4,4,getIndexReference);
	printf("Binary Search Recursive Last Match Index: %d\n",returnIndex);
	returnIndex = binarySearch_recursiveLastMatch(arrayCopy,0,4,2,getIndexReference);
	printf("Binary Search Recursive Last Match Index: %d\n",returnIndex);
	printf("\n\n");
#endif

#if 0

	printf("\n\n");

	copyArray(arrayCopy,array,10);
	returnIndex = binarySearch_iterativeAbsMax(arrayCopy,0,3,getIndexReference);
	printf("Binary Search Iterative Abs Max Index: %d\n",returnIndex);


	printf("\n\n");

	copyArray(arrayCopy,array,10);
	returnIndex = binarySearch_iterativeAbsMini(arrayCopy,0,1,getIndexReference);
	printf("Binary Search Iterative Abs Mini Index: %d\n",returnIndex);
#endif


	return 0;
}






void inputIntArray(sint32* array , uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
	{
		scanf("%d",&array[counter]);
	}
}

void printIntArray(sint32* array , uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
	{
		printf("%d\t",array[counter]);
	}
}



void swapTwoElements(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 swapTempValue = *ptrFirstElement;
	*ptrFirstElement = *ptrSecondElement;
	*ptrSecondElement = swapTempValue;

}


uint8 compareTwoElements(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 returnElement = FALSE;

	if( *ptrFirstElement < *ptrSecondElement)
		returnElement = TRUE;

	return returnElement;

}


uint8 heapCompare(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 returnElement = FALSE;

	if( *ptrFirstElement > *ptrSecondElement)
		returnElement = TRUE;

	return returnElement;

}

sint32* getIndexReference(sint32* genericList , uint16 index)
{
	return &genericList[index];
}




void copyArray(sint32* arrayCopy,sint32* array,uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
		arrayCopy [counter] = array [counter];
}

