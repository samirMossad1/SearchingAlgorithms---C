

#include "searchingAlgorithms.h"







sint32 linearSearch(sint32* genericList, uint16 genericListLength, sint32 element, sint32* (*getIndexRef)(sint32*,uint16))
{

	sint32 returnIndex = -1 ; 	/*Initialization value as not found*/
	uint16 counter;

	/*Iterate over all the list to search sequentially*/
	for(counter = 0 ; counter < genericListLength ; counter++)
	{
		/*Check if the selected element is equal to the required element*/
		if( *(getIndexRef(genericList,counter)) == element )
		{
			/*Get the index*/
			returnIndex = counter;
			break; /*element is found*/
		}
	}


	return returnIndex;
}



sint32 linearSearch_sortedList(sint32* genericList, uint16 genericListLength, sint32 element, sint32* (*getIndexRef)(sint32*,uint16))
{

	sint32 returnIndex = -1 ; 	/*Initialization value as not found*/
	uint16 counter;

	/*Iterate over all the list to search sequentially*/
	for(counter = 0 ; counter < genericListLength ; counter++)
	{
		/*Check if the selected element is equal to the required element*/
		if( *(getIndexRef(genericList,counter)) == element )
		{
			/*Get the index*/
			returnIndex = counter;
			break; /*element is found*/
		}
		/*Check if the selected element is bigger than the required element in a sorted list ==> element not found*/
		else if ( *(getIndexRef(genericList,counter)) > element )
		{
			break;
		}
	}


	return returnIndex;
}




sint32 linearSearch_SelfOrganized_TRN(sint32* genericList, uint16 genericListLength, sint32 element,
								  sint32* (*getIndexRef)(sint32*,uint16),void(*swapFunction)(sint32*,sint32*))
{

	sint32 *selectedElementRef, returnIndex = -1 ; 	/*Initialization value as not found*/
	uint16 counter;

	/*Iterate over all the list to search sequentially*/
	for(counter = 0 ; counter < genericListLength ; counter++)
	{
		/*Get the reference of counter selected element*/
		selectedElementRef = getIndexRef(genericList,counter);

		/*Check if the selected element is equal to the required element*/
		if( *selectedElementRef == element )
		{
			/*Get the index*/
			returnIndex = counter;

			/*Transpose Methodology with one step ahead*/
			if (counter != 0)
				swapFunction(getIndexRef(genericList,counter-1),selectedElementRef);

			break; /*element is found*/
		}
	}

	return returnIndex;
}


sint32 linearSearch_SelfOrganized_MTF(sint32* genericList, uint16 genericListLength, sint32 element,
								  sint32* (*getIndexRef)(sint32*,uint16),void(*swapFunction)(sint32*,sint32*))
{

	sint32 *selectedElementRef, returnIndex = -1 ; 	/*Initialization value as not found*/
	uint16 counter;

	/*Iterate over all the list to search sequentially*/
	for(counter = 0 ; counter < genericListLength ; counter++)
	{
		/*Get the reference of counter selected element*/
		selectedElementRef = getIndexRef(genericList,counter);

		/*Check if the selected element is equal to the required element*/
		if( *selectedElementRef == element )
		{
			/*Get the index*/
			returnIndex = counter;

			/*Move to front*/
			if (counter != 0)
				swapFunction(getIndexRef(genericList,0),selectedElementRef);

			break; /*element is found*/
		}
	}

	return returnIndex;
}



sint32 binarySearch_iterative(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
							  sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;


	while(startElement <= endElement)
	{

		/*Get the reference of the selected middle element*/
		middleElementRef = getIndexRef(genericList,middleRef);

		if(*middleElementRef == element)
		{
			/*Element is found*/
			returnIndex = middleRef;
			break;
		}
		else if( *middleElementRef < element)
		{

			/*Start from the start of the right list*/
			startElement = middleRef + 1 ;
		}
		else
		{

			/*Change the end to be the end of the left list*/
			if (middleRef == 0 )
				break;

			endElement = middleRef - 1 ;

		}

		/*Divide the new array*/
		middleRef = (startElement+endElement) /2;

	}


	/*return the element index found or not found*/
	return returnIndex;

}



sint32 binarySearch_recursive(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
							  sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;

	/*Get the reference of the selected middle element*/
	middleElementRef = getIndexRef(genericList,middleRef);

	/*Base condition, Element is not found*/
	if(startElement > endElement)
		return returnIndex;

	if(*middleElementRef == element)
	{
		/*Element is found*/
		returnIndex = middleRef;

	}
	else if( *middleElementRef < element)
	{

		/*Go Right*/
		/*Recursive call with a new start = start of the right list and the same end*/
		returnIndex = binarySearch_recursive(genericList,middleRef+1,endElement,element,getIndexRef);
	}
	else
	{
		/*Go Left*/
		/*Recursive call to with the same start and new end = the end of the left list*/
		if (middleRef != 0)
			returnIndex = binarySearch_recursive(genericList,startElement,middleRef-1,element,getIndexRef);

	}


	/*return the element index found or not found*/
	return returnIndex;

}



sint32 binarySearch_iterativeFirstMatch(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
										sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;


	while(startElement <= endElement)
	{

		/*Get the reference of the selected middle element*/
		middleElementRef = getIndexRef(genericList,middleRef);

		if(*middleElementRef == element)
		{
			/*Element is found*/
			/*Check if there is no element before*/
			if ( middleRef != 0)
			{
				/*Check if the element before is equal to the found element*/
				if (*getIndexRef(genericList,middleRef-1) == *middleElementRef )
				{
					/*Go left*/
					startElement = 0;
					endElement = middleRef - 1;
				}
				else
				{
					/*First Match Found*/
					returnIndex = middleRef;
					break;
				}
			}
			else
			{
				/*First Match Found*/
				returnIndex = 0;
				break;
			}
		}
		else if( *middleElementRef < element)
		{

			/*Start from the start of the right list*/
			if (middleRef == endElement)
				break;
			startElement = middleRef + 1 ;
		}
		else
		{

			/*Change the end to be the end of the left list*/
			if (middleRef == 0)
				break;
			endElement = middleRef - 1 ;
		}

		/*Divide the new array*/
		middleRef = (startElement+endElement) /2;

	}


	/*return the element index found or not found*/
	return returnIndex;

}


sint32 binarySearch_recursiveFirstMatch(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
							  	  	  	sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;

	/*Get the reference of the selected middle element*/
	middleElementRef = getIndexRef(genericList,middleRef);

	/*Base condition, Element is not found*/
	if(startElement > endElement)
		return returnIndex;

	if(*middleElementRef == element)
	{
		/*Element is found*/
		/*Check if there is no element before*/
		if ( middleRef != 0)
		{
			/*Check if the element before is equal to the found element*/
			if (*getIndexRef(genericList,middleRef-1) == *middleElementRef )
			{
				/*Go left*/
				returnIndex = binarySearch_recursiveFirstMatch(genericList,startElement,middleRef-1,element,getIndexRef);
			}
			else
			{
				/*First Match Found*/
				returnIndex = middleRef;
			}
		}
		else
		{
			/*First Match Found*/
			returnIndex = middleRef;
		}
	}
	else if( *middleElementRef < element)
	{

		/*Go Right*/
		/*Recursive call with a new start = start of the right list and the same end*/
		returnIndex = binarySearch_recursiveFirstMatch(genericList,middleRef+1,endElement,element,getIndexRef);
	}
	else
	{
		/*Go Left*/
		/*Recursive call to with the same start and new end = the end of the left list*/
		if (middleRef != 0)
			returnIndex = binarySearch_recursiveFirstMatch(genericList,startElement,middleRef-1,element,getIndexRef);

	}


	/*return the element index found or not found*/
	return returnIndex;

}

sint32 binarySearch_iterativeLastMatch(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
										sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;


	while(startElement <= endElement)
	{

		/*Get the reference of the selected middle element*/
		middleElementRef = getIndexRef(genericList,middleRef);

		if(*middleElementRef == element)
		{
			/*Element is found*/
			/*Check if there is no element after*/
			if ( middleRef != endElement)
			{
				/*Check if the element before is equal to the found element*/
				if (*getIndexRef(genericList,middleRef+1) == *middleElementRef )
				{
					/*Go right*/
					startElement = middleRef + 1;
				}
				else
				{
					/*Last Match Found*/
					returnIndex = middleRef;
					break;
				}
			}
			else
			{
				/*Last Match Found*/
				returnIndex = middleRef;
				break;
			}
		}
		else if( *middleElementRef < element)
		{

			/*Start from the start of the right list*/
			if (middleRef == endElement)
				break;
			startElement = middleRef + 1 ;
		}
		else
		{

			/*Change the end to be the end of the left list*/
			if (middleRef == 0)
				break;
			endElement = middleRef - 1 ;
		}

		/*Divide the new array*/
		middleRef = (startElement+endElement) /2;

	}


	/*return the element index found or not found*/
	return returnIndex;

}

sint32 binarySearch_recursiveLastMatch(sint32* genericList,uint16 startElement ,uint16 endElement, sint32 element,
							  	  	  	sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2;

	/*Get the reference of the selected middle element*/
	middleElementRef = getIndexRef(genericList,middleRef);

	/*Base condition, Element is not found*/
	if(startElement > endElement)
		return returnIndex;

	if(*middleElementRef == element)
	{
		/*Element is found*/
		/*Check if there is no element before*/
		if ( middleRef != endElement )
		{
			/*Check if the element after is equal to the found element*/
			if (*getIndexRef(genericList,middleRef+1) == *middleElementRef )
			{
				/*Go right*/
				returnIndex = binarySearch_recursiveLastMatch(genericList,middleRef+1,endElement,element,getIndexRef);
			}
			else
			{
				/*Last Match Found*/
				returnIndex = middleRef;
			}
		}
		else
		{
			/*Last Match Found*/
			returnIndex = middleRef;
		}
	}
	else if( *middleElementRef < element)
	{

		/*Go Right*/
		/*Recursive call with a new start = start of the right list and the same end*/
		returnIndex = binarySearch_recursiveLastMatch(genericList,middleRef+1,endElement,element,getIndexRef);
	}
	else
	{
		/*Go Left*/
		/*Recursive call to with the same start and new end = the end of the left list*/
		if (middleRef != 0)
			returnIndex = binarySearch_recursiveLastMatch(genericList,startElement,middleRef-1,element,getIndexRef);

	}


	/*return the element index found or not found*/
	return returnIndex;

}

sint32 binarySearch_iterativeAbsMax(sint32* genericList,uint16 startElement ,uint16 endElement,
							  	  	 sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2 , largerThanBeforeFlag, largerThanAfterFlag;


	while(startElement <= endElement)
	{
		largerThanBeforeFlag = FALSE;
		largerThanAfterFlag  = FALSE;

		/*Get the reference of the selected middle element*/
		middleElementRef = getIndexRef(genericList,middleRef);

		if ( middleRef != 0 )
		{
			/*Last element check*/
			if (middleRef == endElement)
			{
				returnIndex = middleRef;
				break;
			}

			/*Check the mode*/
			if( *middleElementRef >= *getIndexRef(genericList, middleRef-1) )
				largerThanBeforeFlag = TRUE;

			/*Check the mode*/
			if( *middleElementRef >= *getIndexRef(genericList, middleRef+1) )
				largerThanAfterFlag = TRUE;

			if ( largerThanBeforeFlag && largerThanAfterFlag)
			{
				/*Abs Max is found*/
				returnIndex = middleRef;
				break;
			}
			else if (largerThanBeforeFlag && largerThanAfterFlag == FALSE)
			{
				/*Go right*/
				startElement = middleRef + 1;

			}
			else if (largerThanBeforeFlag == FALSE && largerThanAfterFlag)
			{
				/*Go Left*/
				endElement = middleRef - 1;
			}

		}
		else
		{

			if( *middleElementRef >= *getIndexRef(genericList, middleRef+1) )
			{
				/*Abs Max is found*/
				returnIndex = middleRef;
				break;
			}
			else
			{
				/*Go right*/
				startElement = middleRef + 1;
			}
		}

		/*Divide the new array*/
		middleRef = (startElement+endElement) /2;

	}


	/*return the element index found or not found*/
	return returnIndex;

}

sint32 binarySearch_iterativeAbsMini(sint32* genericList,uint16 startElement ,uint16 endElement,
							  	  	 sint32* (*getIndexRef)(sint32*,uint16))
{

	/*Initialize the return index with not found*/
	sint32 returnIndex = -1 , *middleElementRef;

	/*Middle element calculation (A+B)/2*/
	uint16  middleRef = (startElement + endElement )/2 , smallerThanBeforeFlag, smallerThanAfterFlag;


	while(startElement <= endElement)
	{
		smallerThanBeforeFlag = FALSE;
		smallerThanAfterFlag  = FALSE;

		/*Get the reference of the selected middle element*/
		middleElementRef = getIndexRef(genericList,middleRef);

		if ( middleRef != 0 )
		{
			/*Last element check*/
			if (middleRef == endElement)
			{
				returnIndex = middleRef;
				break;
			}

			/*Check the mode*/
			if( *middleElementRef <= *getIndexRef(genericList, middleRef-1) )
				smallerThanBeforeFlag = TRUE;

			/*Check the mode*/
			if( *middleElementRef <= *getIndexRef(genericList, middleRef+1) )
				smallerThanAfterFlag = TRUE;

			if ( smallerThanBeforeFlag && smallerThanAfterFlag)
			{
				/*Abs Max is found*/
				returnIndex = middleRef;
				break;
			}
			else if (smallerThanBeforeFlag && smallerThanAfterFlag == FALSE)
			{
				/*Go right*/
				startElement = middleRef + 1;

			}
			else if (smallerThanBeforeFlag == FALSE && smallerThanAfterFlag)
			{
				/*Go Left*/
				endElement = middleRef - 1;
			}

		}
		else
		{

			if( *middleElementRef <= *getIndexRef(genericList, middleRef+1) )
			{
				/*Abs Max is found*/
				returnIndex = middleRef;
				break;
			}
			else
			{
				/*Go right*/
				startElement = middleRef + 1;
			}
		}

		/*Divide the new array*/
		middleRef = (startElement+endElement) /2;

	}


	/*return the element index found or not found*/
	return returnIndex;

}
