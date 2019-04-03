#include "stdafx.h"
#include "Stack.h"
#include "DoubleList.h"

using namespace std;

CStack::CStack( int _size )
{
	m_pStackList = new CLinkedList();
	if ( m_pStackList == NULL )
	{
		cout << "����Ʈ�� �������� �ʾҽ��ϴ�." << endl;
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
		cout << "������ �� á���ϴ�." << endl;
		return;
	}

	if ( _data < 0 )
	{
		cout << "0���� ū ���� �Է��Ͻÿ�." << endl;
		return;
	}


	m_pStackList->Add(_data);
	m_dataCount++;
}

int CStack::Pop()
{
	if ( IsEmpty() == true )
	{
		cout << "���ÿ� ���� �����Ͱ� �����ϴ�." << endl;
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
		cout << "���ÿ� ���� �����Ͱ� �����ϴ�." << endl;
		return;
	}
	
	m_pStackList->PrintList();
}