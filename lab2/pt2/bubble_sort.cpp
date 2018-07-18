#include "name_comparsion.h"

#include <algorithm>

void bubbleSort(PersonName* _pData, int _N)
{
	for (int i = 0; i < _N - 1; i++)
		for (int j = _N - 1; j > i; j--)
			if (compareNames(_pData[j - 1], _pData[j]) > 0)
				std::swap(_pData[j], _pData[j - 1]);
}