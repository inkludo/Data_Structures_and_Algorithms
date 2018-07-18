#ifndef _INTEGER_REVERSE_LIST_HPP_
#define _INTEGER_REVERSE_LIST_HPP_

#include <iostream>


struct IntegerReverseList
{
	struct Node
	{
		int m_value;
		Node * m_pPrev;
	};

	Node * m_pFirst, *m_pLast;
};


void IntegerReverseListInit(IntegerReverseList & _list);

void IntegerReverseListDestroy(IntegerReverseList & _list);

bool IntegerReverseListIsEmpty(const IntegerReverseList & _list);

int IntegerReverseListSize(const IntegerReverseList & _list);

void IntegerReverseListClear(IntegerReverseList & _list);

void IntegerReverseListPushBack(IntegerReverseList & _list, int _data);

void IntegerReverseListPushFront(IntegerReverseList & _list, int _data);

void IntegerReverseListInsertAfter(IntegerReverseList & _list, IntegerReverseList::Node * _pPrevNode, int _data);

void IntegerReverseListInsertBefore(IntegerReverseList & _list, IntegerReverseList::Node * _pNextNode, int _data);

void IntegerReverseListPopBack(IntegerReverseList & _list);

void IntegerReverseListPopFront(IntegerReverseList & _list);

void IntegerReverseListDeleteAfter(IntegerReverseList & _list, IntegerReverseList::Node * _pPrevNode);

void IntegerReverseListDeleteBefore(IntegerReverseList & _list, IntegerReverseList::Node * _pNextNode);

void IntegerReverseListDeleteNode(IntegerReverseList & _list, IntegerReverseList::Node * _pNode);

void IntegerReverseListRead(IntegerReverseList & _list, std::istream & _i);

void IntegerReverseListReadTillZero(IntegerReverseList & _list, std::istream & _i);

void IntegerReverseListPrint(const IntegerReverseList & _list, std::ostream & _o, char _sep = ' ');



#endif //  _INTEGER_FORWARD_LIST_HPP_