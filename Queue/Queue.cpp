#include "stdafx.h"
#include "List.h"
#include "Queue.h"

using namespace std;

CQueue::CQueue(int _size)
{
	m_pList = new CLinkedList(); 
	if ( m_pList == NULL )
	{
		cout << "리스트 생성 실패" << endl;
		return;
	}

	if ( _size <= 0 )
	{
		cout << "생성될 큐의 크기가 작습니다. " << endl;
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
		cout << "음수 값을 넣을 수 없습니다." << endl;
		return;
	}

	if ( IsFull() == true )
	{
		cout << "큐가 꽉 찼습니다." << endl;
		return;
	}		

	m_pList->Add( _data );
}

int CQueue::Get()
{
	if ( IsEmpty() == true )
	{
		cout << "큐에 들어온 데이터가 없음." << endl;
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
		cout << "큐에 들어온 데이터가 없음." << endl;
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
