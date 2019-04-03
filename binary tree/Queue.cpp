#include "stdafx.h"
#include "List.h"
#include "Tree.h"
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

	m_size	= _size;
	m_count = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}

CQueue::~CQueue()
{
	m_pList->DeleteList();

	delete m_pList;
	m_pList = NULL;
}

void CQueue::Put( CNode* pPutNode )
{
	if( pPutNode->m_data < 0 )
	{
		cout << "음수 값을 넣을 수 없습니다." << endl;
		return;
	}

	if ( IsFull() == true )
	{
		cout << "큐가 꽉 찼습니다." << endl;
		return;
	}		

	m_pList->Add( pPutNode );
	m_pHead = m_pList->GetHead();

	m_count++;
}



bool CQueue::IsEmpty()
{
	if ( m_pHead == NULL )
		return true;
	
	return false;
}

bool CQueue::IsFull()
{
	if ( m_pList->GetCount() >= m_size )
	{
		return true;
	}

	return false;
}

void CQueue::PrintQueue( CNode* pRoot )
{
	if ( pRoot == NULL )
	{
		cout << "PrintQueue() 인자 값이 NULL." << endl;
		return;
	}

	Traverse( pRoot );
	//m_pList->PrintList();
}

CNode* CQueue::Get( CNode* pGetNode )
{
	if ( IsEmpty() == true )
	{
		cout << "큐에 들어온 데이터가 없음." << endl;
		return NULL;
	}

	m_pHead = m_pList->GetHead();

	if ( m_pHead == NULL )
	{
		cout << endl <<"Get() 헤드가 NULL 입니다." << endl;
		return NULL;
	}

	// 인자 값에 큐의 헤드 값을 설정
	*(pGetNode) = *(m_pHead->m_pData);

	// 큐에서 헤드가 지워짐
	m_pList->DeleteHead();
	
	return pGetNode;
}


void CQueue::Traverse( CNode* pTreeNode )
{
	if ( pTreeNode == NULL )
	{
		cout << "Traverse() 인자 값이 NULL." << endl;
		return;
	}

	Put( pTreeNode );

	CNode* pTraverse = pTreeNode;

	while ( Get( pTraverse ) != NULL )
	{
		cout << pTraverse->m_data << " ";

		if ( pTreeNode->m_pLeft != NULL )
		{
			Put( pTraverse->m_pLeft );
		}


		if ( pTraverse->m_pRight != NULL )
		{
			Put( pTraverse->m_pRight );
		}
	}
}


















