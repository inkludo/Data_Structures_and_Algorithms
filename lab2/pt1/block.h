#ifndef  BLOCK_H
#define BLOCK_H

#include "integer_map.h"

void prepareApartmentInformation(IntegerMap& residentsInfo, int size, int maxNumberOfResidents);
bool enterApartment(int aptNumber, IntegerMap& residents, IntegerMap& residentsInfo);
bool exitApartment(int aptNumber, IntegerMap& residents);
int getResidentsAtHome(int aptNumber, IntegerMap& residents);

#endif // ! BLOCK_H

