#include "person_name.h"
#include "bubble_sort.h"

#include <iostream>

void printArray(PersonName* names, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << names[i].m_lastName << " " << names[i].m_initials << std::endl;
	}
}

int main()
{
	const int size = 8;
	PersonName names[size] = {
		{"Bond", "JO"},
		{"Frodo", "MA"},
		{"Dumbledore", "AW"},
		{"Pahom", "PO"},
		{"Pahom", "PA"},
		{"Dumbledore", "BD"},
		{"Grey", "SI"},
		{"Qqqq", "SI"}
	};

	std::cout << "Before sorting:\n";
	printArray(names, size);

	bubbleSort(names, size);

	std::cout << "\nAfter sorting:\n";
	printArray(names, size);

	system("pause");

	return 0;
}