#include "integer_reverse_list.hpp"
#include <cassert>

void IntegerReverseListInit(IntegerReverseList & _list)
{
	_list.m_pFirst = _list.m_pLast = 0; 
}


void IntegerReverseListDestroy(IntegerReverseList & _list)
{
	IntegerReverseListClear(_list);    
}


void IntegerReverseListClear(IntegerReverseList & _list)
{
	IntegerReverseList::Node * pCurrent = _list.m_pLast;
	while (pCurrent)
	{
		IntegerReverseList::Node * pTemp = pCurrent->m_pPrev;   
		delete pCurrent;
		pCurrent = pTemp;
	}

	_list.m_pFirst = _list.m_pLast = 0;
}


bool IntegerReverseListIsEmpty(const IntegerReverseList & _list)
{
	return _list.m_pLast == 0;
}


int IntegerReverseListSize(const IntegerReverseList & _list)
{
	int nElements = 0;
	const IntegerReverseList::Node * pNode = _list.m_pLast;
	while (pNode)
	{
		++nElements;
		pNode = pNode->m_pPrev;
	}

	return nElements;
}


void IntegerReverseListPushBack(IntegerReverseList & _list, int _data)
{
	IntegerReverseList::Node * pNewNode = new IntegerReverseList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_pPrev = 0;

	if (!_list.m_pFirst)
	{
		assert(!_list.m_pLast);                                    
		_list.m_pFirst = pNewNode;
	}
	else
		pNewNode->m_pPrev = _list.m_pLast;

	_list.m_pLast = pNewNode;
}


void IntegerReverseListPushFront(IntegerReverseList & _list, int _data)
{
	IntegerReverseList::Node * pNewNode = new IntegerReverseList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_pPrev = 0;
     
     if (!_list.m_pLast)
		_list.m_pLast = _list.m_pFirst = pNewNode;
	else {
		_list.m_pFirst->m_pPrev = pNewNode;
	    _list.m_pFirst = pNewNode;  
	}
                                   

}


void IntegerReverseListInsertAfter(IntegerReverseList & _list, IntegerReverseList::Node * _pPrevNode, int _data)
{	
	assert(!IntegerReverseListIsEmpty(_list));
		
	if (_pPrevNode == _list.m_pLast)
		IntegerReverseListPushBack(_list, _data);
	else
	{
		IntegerReverseList::Node * pCurrent = _list.m_pLast;
		while (pCurrent && pCurrent->m_pPrev != _pPrevNode)
			pCurrent = pCurrent->m_pPrev;

		assert(pCurrent);

		IntegerReverseList::Node * pNewNode = new IntegerReverseList::Node;
		pNewNode->m_value = _data;

		pNewNode->m_pPrev = _pPrevNode;

		pCurrent->m_pPrev = pNewNode;

	}
}


void IntegerReverseListInsertBefore(IntegerReverseList & _list, IntegerReverseList::Node * _pNextNode, int _data)
{
	assert(!IntegerReverseListIsEmpty(_list));

	if (_pNextNode == _list.m_pFirst)
		IntegerReverseListPushFront(_list, _data);
	else
	{
		IntegerReverseList::Node * pNewNode = new IntegerReverseList::Node;
		pNewNode->m_value = _data;

		pNewNode->m_pPrev = _pNextNode->m_pPrev;

		_pNextNode->m_pPrev = pNewNode;
	}
}


void IntegerReverseListPopFront(IntegerReverseList & _list)
{
	assert(!IntegerReverseListIsEmpty(_list));
	
	IntegerReverseList::Node * pFirst = _list.m_pFirst;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = 0;

	else
	{
		IntegerReverseList::Node * pCurrent = _list.m_pLast;
		while (pCurrent->m_pPrev != _list.m_pFirst)
			pCurrent = pCurrent->m_pPrev;

		_list.m_pFirst = pCurrent;
		pCurrent->m_pPrev = 0;
	}

	delete pFirst;
}


void IntegerReverseListPopBack(IntegerReverseList & _list)
{
	assert(!IntegerReverseListIsEmpty(_list));

	IntegerReverseList::Node * pLast = _list.m_pLast;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = 0;

	else
		_list.m_pLast = pLast->m_pPrev;

	delete pLast;
}


void IntegerReverseListDeleteAfter(IntegerReverseList & _list, IntegerReverseList::Node * _pPrevNode)
{
	assert(!IntegerReverseListIsEmpty(_list));	
	
	assert(_list.m_pLast != _pPrevNode);

	IntegerReverseList::Node * pPrevNode = _list.m_pLast, *pCurrentNode = _list.m_pLast->m_pPrev;
	if (pCurrentNode == _pPrevNode)
	{
		delete _list.m_pLast;
		_list.m_pLast = _pPrevNode;
	}
	else
	{
		while (pCurrentNode->m_pPrev != _pPrevNode)
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->m_pPrev;
		}
		pPrevNode->m_pPrev = _pPrevNode;
		delete pCurrentNode;
	}
}


void IntegerReverseListDeleteBefore(IntegerReverseList & _list, IntegerReverseList::Node * _pNextNode)
{
	assert(!IntegerReverseListIsEmpty(_list));

	assert(_list.m_pFirst != _pNextNode);

	IntegerReverseList::Node * pDyingNode = _pNextNode->m_pPrev;
	_pNextNode->m_pPrev = pDyingNode->m_pPrev;

	if (_list.m_pFirst == pDyingNode)
		_list.m_pFirst = _pNextNode;

	delete pDyingNode;
}


void IntegerReverseListDeleteNode(IntegerReverseList & _list, IntegerReverseList::Node * _pNode)
{
	if (_list.m_pFirst == _pNode)
		IntegerReverseListPopFront(_list);

	else if (_list.m_pLast == _pNode)
		IntegerReverseListPopBack(_list);

	else
		IntegerReverseListDeleteAfter(_list, _pNode->m_pPrev);
}


void IntegerReverseListPrint(const IntegerReverseList & _list, std::ostream & _stream, char _sep)
{
	const IntegerReverseList::Node * pCurrent = _list.m_pLast;
	while (pCurrent)
	{
		_stream << pCurrent->m_value << _sep;
		pCurrent = pCurrent->m_pPrev;
	}
}


void IntegerReverseListRead(IntegerReverseList & _list, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
			IntegerReverseListPushBack(_list, temp);
		else
			break;
	}
}


void IntegerReverseListReadTillZero(IntegerReverseList & _list, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp != 0)
			IntegerReverseListPushBack(_list, temp);
		else
			break;
	}
}
