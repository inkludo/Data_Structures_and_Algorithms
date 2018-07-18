#include "block.h"
#include "integer_map.h"

#include <iostream>

int main()
{
	const int numberOfApartments = 100;
	const int maxNumberOfResidents = 4; //for rand and etc.

	IntegerMap* residentsInfo = IntegerMapCreate();
	IntegerMap* residents = IntegerMapCreate();

	prepareApartmentInformation(*residentsInfo, numberOfApartments, maxNumberOfResidents);

	char command;
	int parameter;

	do { 
		std::cout << "command: ";

		const char enter_command = 'E';
		const char exit_command = 'L';
		const char print_command = 'S';

		std::cin >> command;
		if (!std::cin.good())
		{
			break;
		}

		std::cin >> parameter;

		if (!(command == enter_command 
			|| command == exit_command 
			|| command == print_command))
		{
			std::cout << "error: wrong command\n";
			continue;
		}

		if (parameter <= 0 || parameter > numberOfApartments)
		{
			std::cout << "error: wrong apartment number\n";
			continue;
		}

		switch (command)
		{
		case enter_command:
			if (enterApartment(parameter, *residents, *residentsInfo))
			{
				std::cout << "success" << std::endl;
			}
			else
			{
				std::cout << "error: the apartment is full\n";
			}
			break;
		case exit_command:
			if (exitApartment(parameter, *residents))
			{
				std::cout << "success" << std::endl;
			}
			else
			{
				std::cout << "error: the apartment is empty\n";
			}
			break;
		case print_command:
			std::cout << "total number of keys: " << IntegerMapGet(*residentsInfo, parameter) << std::endl;
			std::cout << "residents in the apartment: " << 
				getResidentsAtHome(parameter, *residents) << std::endl;
		
		}
		
	} while (true);

	IntegerMapDestroy(residents);
	IntegerMapDestroy(residentsInfo);

	return 0;
}