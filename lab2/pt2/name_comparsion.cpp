#include "person_name.h"

#include <ctype.h>

int compare(char* string1, char* string2)
{
	int result = 0;

	char symbol1;// = 0;
	char symbol2; //= 0;

	do {
		symbol1 = tolower(*string1);
		symbol2 = tolower(*string2);

		if (symbol1 > symbol2)
		{
			result = 1;
			break;
		}
		else if (symbol1 < symbol2)
		{
			result = -1;
			break;
		}

		string1++;
		string2++;
	} while (symbol1 != 0 && symbol2 != 0
		&& symbol1 == symbol2);

	return result;
}

int compareNames(PersonName person1, PersonName person2)
{
	int result = compare(person1.m_lastName, person2.m_lastName);

	if (result == 0)
	{
		result = compare(person1.m_initials, person2.m_initials);
	}

	return result;
}