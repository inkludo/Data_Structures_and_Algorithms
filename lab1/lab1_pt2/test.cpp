#include "integer_reverse_list.hpp"
#include <cassert>

int main() {
	
	IntegerReverseList l;
	IntegerReverseListInit(l);

	IntegerReverseListPushBack(l, 1);
	IntegerReverseListPushBack(l, 2);
	IntegerReverseListPushBack(l, 3);

	assert(l.m_pFirst->m_value == 1);
	assert(l.m_pLast->m_value == 3);
	assert(l.m_pLast->m_pPrev->m_value == 2);

	IntegerReverseListDestroy(l);
	
}