#include "stdafx.h"
#include "Stack.h"
#include "DoubleList.h"

using namespace std;

CStack::CStack( int _size )
{
	m_pStackList = new CLinkedList();
	if ( m_pStackList == NULL )
	{
		cout << "리스트가 생성되지 않았습니다." << endl;
		return;
	}

	m_dataCount		= 0;
	m_size			= _size;
}

CStack::~CStack()
{
	m_pStackList->DeleteList();
	
	delete m_pStackList;
	m_pStackList = NULL;
}

void CStack::Push( int _data )
{
	if ( IsFull() == true )
	{
		cout << "스택이 꽉 찼습니다." << endl;
		return;
	}

	if ( _data < 0 )
	{
		cout << "0보다 큰 수를 입력하시오." << endl;
		return;
	}


	m_pStackList->Add(_data);
	m_dataCount++;
}

int CStack::Pop()
{
	if ( IsEmpty() == true )
	{
		cout << "스택에 들어온 데이터가 없습니다." << endl;
		return -1;
	}

	m_dataCount--;
	
	return m_pStackList->DeleteNode();
}

bool CStack::IsEmpty()
{
	if ( m_dataCount <= 0 )
		return true;		

	return false;
}

bool CStack::IsFull()
{
	if ( m_dataCount >= m_size )
		return true;

	return false;
}

void CStack::PrintSTack()
{
	if ( IsEmpty() == true )
	{
		cout << "스택에 들어온 데이터가 없습니다." << endl;
		return;
	}
	
	m_pStackList->PrintList();
}