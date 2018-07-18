#include "integer_map.h"

#include <ctime>
#include <cstdlib>

void prepareApartmentInformation(IntegerMap& residentsInfo, int size, int maxNumberOfResidents)
{
	srand(time(NULL));
	for (int i = 1; i <= size; i++)
	{
		IntegerMapInsertKey(residentsInfo, i, std::rand() % maxNumberOfResidents + 1);
	}
}

bool enterApartment(int aptNumber, IntegerMap& residents, IntegerMap& residentsInfo)
{
	int numberOfResidents = IntegerMapGet(residents, aptNumber);
	int maxNumberOfResidents = IntegerMapGet(residentsInfo, aptNumber);

	if (numberOfResidents == maxNumberOfResidents)
	{
		return false;
	}
	else 
	{
		if (numberOfResidents == -1)
		{
			numberOfResidents++;
		}
		IntegerMapInsertKey(residents, aptNumber, ++numberOfResidents);
		return true;
	}
}

bool exitApartment(int aptNumber, IntegerMap& residents)
{
	int numberOfResidents = IntegerMapGet(residents, aptNumber);

	if (numberOfResidents == -1 || numberOfResidents == 0)
	{
		return false;
	}
	else
	{
		IntegerMapInsertKey(residents, aptNumber, --numberOfResidents);
		return true;
	}
}


int getResidentsAtHome(int aptNumber, IntegerMap& residents)
{
	int numberOfResidents = IntegerMapGet(residents, aptNumber);

	if (numberOfResidents == -1)
	{
		return 0;
	}

	return numberOfResidents;
}