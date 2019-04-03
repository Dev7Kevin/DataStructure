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
		cout << "����Ʈ ���� ����" << endl;
		return;
	}

	if ( _size <= 0 )
	{
		cout << "������ ť�� ũ�Ⱑ �۽��ϴ�. " << endl;
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
		cout << "���� ���� ���� �� �����ϴ�." << endl;
		return;
	}

	if ( IsFull() == true )
	{
		cout << "ť�� �� á���ϴ�." << endl;
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
		cout << "PrintQueue() ���� ���� NULL." << endl;
		return;
	}

	Traverse( pRoot );
	//m_pList->PrintList();
}

CNode* CQueue::Get( CNode* pGetNode )
{
	if ( IsEmpty() == true )
	{
		cout << "ť�� ���� �����Ͱ� ����." << endl;
		return NULL;
	}

	m_pHead = m_pList->GetHead();

	if ( m_pHead == NULL )
	{
		cout << endl <<"Get() ��尡 NULL �Դϴ�." << endl;
		return NULL;
	}

	// ���� ���� ť�� ��� ���� ����
	*(pGetNode) = *(m_pHead->m_pData);

	// ť���� ��尡 ������
	m_pList->DeleteHead();
	
	return pGetNode;
}


void CQueue::Traverse( CNode* pTreeNode )
{
	if ( pTreeNode == NULL )
	{
		cout << "Traverse() ���� ���� NULL." << endl;
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


















