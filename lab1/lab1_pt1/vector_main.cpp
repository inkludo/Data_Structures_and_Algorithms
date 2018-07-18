#include "integer_vector.hpp"

int main()
{
	
	IntegerVector v;
	IntegerVectorInit(v);

	std::cout << "Input integers, stop with zero or minus: ";
	IntegerVectorReadTillZeroOrMinus(v, std::cin);

	std::cout << "Input position to delete: ";
	int position2Delete;
	std::cin >> position2Delete;

	
	if (position2Delete < 0 || position2Delete > v.m_nUsed/2)
		std::cout << "Error: invalid position specified." << std::endl;

	else

	{
			
		int first_index = position2Delete;

		IntegerVectorDeleteAt(v, first_index);
		int second_index = v.m_nUsed - (position2Delete + 1);
		
		if(position2Delete == (v.m_nUsed + 1) / 2) {
			second_index++;
		}

		IntegerVectorDeleteAt(v, second_index);
		

       
		
		std::cout << "Result: ";
		IntegerVectorPrint(v, std::cout);
		std::cout << std::endl;
	}

	IntegerVectorDestroy(v);


	system("pause");
}

