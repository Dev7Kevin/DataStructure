#include "stdafx.h"
#include "Tree.h"
#include "List.h"

using namespace std;

CLinkedList::CLinkedList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	
	m_count = -1;
}

// ����Ʈ�� ���� ��带 ����
void CLinkedList::Add( CNode* pAddNode )
{
	// ���ο� ��� �ʱ�ȭ
	CQNode* pNewNode = new CQNode();
	if ( pNewNode == NULL )
	{
		cout << "���Ե� ��尡 ���� ���� �ʾҽ��ϴ�." << endl;
		return;
	}

	pNewNode->m_pData	= pAddNode;
	pNewNode->m_pPre	= NULL;
	pNewNode->m_pNext	= NULL;

	// ��ũ�� ����Ʈ�� ��� �߰�
	if ( m_pHead == NULL )
		m_pHead = pNewNode;
	else 
	{
		m_pTail->m_pNext = pNewNode;
		pNewNode->m_pPre = m_pTail;
	}

	m_pTail = pNewNode;

	m_count++;

}



// ��� ����
void CLinkedList::DeleteHead()
{
	CQNode newHead = *m_pHead;

	delete m_pHead;

	m_pHead = newHead.m_pNext;

	/*if ( m_pHead == NULL )
	{
		cout << endl <<"DeleteHead() ����� ���Դϴ�. " << endl;
		return;
	}*/

	m_count--;
}

// ����Ʈ�� ��带 ��� ����
void CLinkedList::DeleteList()
{
	if(m_pHead == NULL)
	{
		cout << "DeleteList() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	CQNode* pDelete;

	// ����� NULL�� �ɶ����� ����
	while( m_pHead != NULL )
	{
		pDelete = m_pHead;

		m_pHead = m_pHead->m_pNext;

		delete pDelete;
		pDelete = NULL;
	}

	m_pTail = NULL;
}



// ����Ʈ�� ���
void CLinkedList::PrintList()
{
	if ( m_pHead == NULL )
	{
		cout << "ť�� ���� �����Ͱ� ����." << endl;
		return;
	}

	CQNode* pPrintNode = m_pHead;

	do
	{
		cout << pPrintNode->m_pData->m_data << "  ";
		pPrintNode = pPrintNode->m_pNext;
	} while( pPrintNode != NULL );

	cout << endl;
}


// ����Ʈ�� ��� ���� ����
int CLinkedList::GetCount()
{
	return m_count;
}

// ����Ʈ�� ������ ����� ���� ����
int CLinkedList::GetLastData( )
{
	if ( m_pHead == NULL )
	{
		cout << "GetLastData( ) ������ ��尡 �����ϴ�." << endl;
		return 0;
	}

	return m_pTail->m_pData->m_data;
}

CQNode* CLinkedList::GetHead()
{
	if ( m_pHead ==  NULL )
	{
		cout << endl <<"GetHead() ��尡 NULL �Դϴ�." << endl;
		return NULL;
	}

	return m_pHead;
}

CQNode* CLinkedList::GetTail()
{
	if ( m_pTail ==  NULL )
	{
		cout << "GetTail() ������ NULL �Դϴ�." << endl;
		return NULL;
	}

	return m_pTail;
}



















