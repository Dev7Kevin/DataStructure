#include "stdafx.h"
#include "List.h"
#include "Queue.h"

using namespace std;

CQueue::CQueue(int _size)
{
	m_pList = new CLinkedList(); 
	if ( m_pList == NULL )
	{
		cout << "����Ʈ ���� ����" << endl;
		return;
	}

	if ( _size <= 0 )
	{
		cout << "������ ť�� ũ�Ⱑ �۽��ϴ�. " << endl;
		return;
	}

	m_size = _size;
}

CQueue::~CQueue()
{
	m_pList->DeleteList();

	delete m_pList;
	m_pList = NULL;
}

void CQueue::Put( int _data )
{
	if( _data < 0 )
	{
		cout << "���� ���� ���� �� �����ϴ�." << endl;
		return;
	}

	if ( IsFull() == true )
	{
		cout << "ť�� �� á���ϴ�." << endl;
		return;
	}		

	m_pList->Add( _data );
}

int CQueue::Get()
{
	if ( IsEmpty() == true )
	{
		cout << "ť�� ���� �����Ͱ� ����." << endl;
		return -1;
	}

	int lastData = m_pList->GetLastData();
	m_pList->DeleteNode(m_pList->GetCount());

	return lastData;
}

void CQueue::PrintQueue()
{
	if ( IsEmpty() == true )
	{
		cout << "ť�� ���� �����Ͱ� ����." << endl;
		return;
	}

	m_pList->PrintList();
}

bool CQueue::IsEmpty()
{
	if ( m_pList->GetCount() < 0 )
		return true;
	
	return false;
}

bool CQueue::IsFull()
{
	if ( m_pList->GetCount() > m_size - 2 )
	{
		return true;
	}

	return false;
}
