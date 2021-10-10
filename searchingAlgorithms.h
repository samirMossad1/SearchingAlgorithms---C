
#ifndef SEARCHINGALGORITHMS_H_
#define SEARCHINGALGORITHMS_H_

#include "std_types.h"

sint32 linearSearch(sint32*,uint16,sint32,sint32*(*)(sint32*,uint16));
sint32 linearSearch_sortedList(sint32*,uint16,sint32,sint32*(*)(sint32*,uint16));
sint32 linearSearch_SelfOrganized_TRN(sint32*,uint16,sint32,sint32* (*)(sint32*,uint16),void(*)(sint32*,sint32*));
sint32 linearSearch_SelfOrganized_MTF(sint32*,uint16,sint32,sint32* (*)(sint32*,uint16),void(*)(sint32*,sint32*));

sint32 binarySearch_iterative(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_recursive(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_iterativeFirstMatch(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_recursiveFirstMatch(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_iterativeLastMatch(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_recursiveLastMatch(sint32*,uint16,uint16,sint32,sint32* (*)(sint32*,uint16));
sint32 binarySearch_iterativeAbsMax(sint32*,uint16,uint16,sint32* (*)(sint32*,uint16));
sint32 binarySearch_iterativeAbsMini(sint32*,uint16,uint16,sint32* (*)(sint32*,uint16));




#endif /* SEARCHINGALGORITHMS_H_ */


