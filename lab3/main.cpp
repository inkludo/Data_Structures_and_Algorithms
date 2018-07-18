#include <iostream>

#include "tree_static.h"


void visitFunct(const Tree & _t, int _nodeIndex)
{
	std::cout << TreeGetLabel(_t, _nodeIndex) << std::endl;
}

int main()
{
	
	Tree* tree = TreeCreate(7);

	TreeSetParentIndex(*tree, 1, 0);
	TreeSetParentIndex(*tree, 2, 0);
	TreeSetParentIndex(*tree, 3, 1);
	TreeSetParentIndex(*tree, 4, 1);
	TreeSetParentIndex(*tree, 5, 2);
	TreeSetParentIndex(*tree, 6, 2);

	TreeSetLabel(*tree, 0, 'r');
	TreeSetLabel(*tree, 1, 'a');
	TreeSetLabel(*tree, 2, 'b');
	TreeSetLabel(*tree, 3, '1');
	TreeSetLabel(*tree, 4, '2');
	TreeSetLabel(*tree, 5, '3');
	TreeSetLabel(*tree, 6, '4');


	
	std::cout << "DIRECT WALK:\n";
	TreeDirectWalk(*tree, &visitFunct);

	
	std::cout << "\nSYMMETRIC WALK:\n";
	TreeSymmetricWalk(*tree, &visitFunct);

	
	std::cout << "\nREVERSE WALK:\n";
	TreeReverseWalk(*tree, &visitFunct);


	
	std::cout << "\nroot label is \'" << TreeGetLabel(*tree, 0) << "\'\n";
	std::cout << "change root label to \'z\'\n";
	TreeSetLabel(*tree, 0, 'z');
	std::cout << "now root label is \'" << TreeGetLabel(*tree, 0) << "\'\n";

	
	std::cout << "\n\'a\' parent is \'" << TreeGetLabel(*tree, TreeGetParentIndex(*tree, 1)) << "\'";
	std::cout << "\n\'z\' lefmost child is \'" << TreeGetLabel(*tree, TreeGetLeftmostChildIndex(*tree, 0)) << "\'";
	std::cout << "\n\'1\' right sibling is \'" << TreeGetLabel(*tree, TreeGetRightSiblingIndex(*tree, 3)) << "\'\n";


	
	TreeDestroy(tree);

	system("pause");
	return 0;
}