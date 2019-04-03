#include "stdafx.h"
#include "DoubleList.h"

using namespace std;

CLinkedList::CLinkedList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	
	m_count = -1;
}

// ����Ʈ�� ���� ��带 ����
void CLinkedList::Add(int _data)
{
	// ���ο� ��� �ʱ�ȭ
	CNode* pNewNode = new CNode();
	if ( pNewNode == NULL )
	{
		cout << "���Ե� ��尡 ���� ���� �ʾҽ��ϴ�." << endl;
		return;
	}

	pNewNode->m_data	= _data;
	pNewNode->m_pPre	= NULL;
	pNewNode->m_pNext	= NULL;

	// ��ũ�� ����Ʈ�� ��� �߰�
	if ( m_pHead == NULL )
		m_pHead = pNewNode;
	else if ( m_pTail != NULL )
	{
		m_pTail->m_pNext = pNewNode;
		pNewNode->m_pPre = m_pTail;
	}

	m_pTail = pNewNode;

	m_count++;
}

// Ư�� ��带 ����
void CLinkedList::DeleteNode( int _deleteIndex )
{
	if( _deleteIndex < 0 )
	{
		cout << "��ǥ ��� ���� �ʹ� �۽��ϴ�." << endl;
		return;
	}

	if( m_count < 0 )
	{
		cout << "DeleteNode() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	if( m_count < _deleteIndex )
	{
		cout << "������ ��庸�� ū �ε��� ��." << endl;
		return;
	}

	CNode* pDeleteNode =  SearchNode( _deleteIndex );
	if( pDeleteNode == NULL )
	{
		cout << "������ ��带 ã�� ���߽��ϴ�" << endl;
		return;
	}

	if( pDeleteNode == m_pHead )
	{
		if ( m_pHead->m_pNext != NULL )
		{
			m_pHead			= pDeleteNode->m_pNext;
			m_pHead->m_pPre	= NULL;
		}
		else
		// ��� �ϳ��� ���Ҵ�.
		{
			delete m_pHead;
			m_pHead = NULL;
			m_count--;

			return;
		}
	}
	else if( pDeleteNode->m_pNext == NULL )
	{
		m_pTail				= pDeleteNode->m_pPre;
		m_pTail->m_pNext	= NULL;
		
	}
	else
	{
		pDeleteNode->m_pPre->m_pNext = pDeleteNode->m_pNext;
		pDeleteNode->m_pNext->m_pPre = pDeleteNode->m_pPre;
	}

	delete pDeleteNode;
	pDeleteNode = NULL;

	m_count--;
}

// ������ ��带 ����
int CLinkedList::DeleteNode( )
{
	CNode* pDeleteNode = m_pTail;
	int deleteData = pDeleteNode->m_data;
	
	if( pDeleteNode == m_pHead )
	{
		if ( m_pHead->m_pNext != NULL )
		{
			m_pHead			= pDeleteNode->m_pNext;
			m_pHead->m_pPre	= NULL;
		}
		else
		// ��� �ϳ��� ���Ҵ�.
		{
			delete m_pHead;
			m_pHead = NULL;
			m_count--;

			return deleteData;
		}
	}
	else if( pDeleteNode->m_pNext == NULL )
	{
		m_pTail				= pDeleteNode->m_pPre;
		m_pTail->m_pNext	= NULL;
		
	}
	else
	{
		pDeleteNode->m_pPre->m_pNext = pDeleteNode->m_pNext;
		pDeleteNode->m_pNext->m_pPre = pDeleteNode->m_pPre;
	}

	delete pDeleteNode;
	pDeleteNode = NULL;

	m_count--;

	return deleteData;
}

// ����Ʈ�� ��带 ��� ����
void CLinkedList::DeleteList()
{
	if(m_pHead == NULL)
	{
		cout << "DeleteList() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	CNode* pDelete;

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

// Ư�� ��� ������ ��带 ����
void CLinkedList::Insert(int _targetIndex, int _insertData)
{
	// ����ó�� ����
	if ( _targetIndex < 0 )
	{
		cout << "��ǥ ��� ���� �ʹ� �۽��ϴ�." << endl;
		return;
	}

	if ( m_count < 0 )
	{
		cout << "Insert() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	if ( m_count < _targetIndex )
	{
		cout << "������ ��庸�� ū �ε��� ��." << endl;
		return;
	}

	if ( m_count == _targetIndex )
	{
		cout << "����Ʈ�� ���� �߰� �ϹǷ� Add�� ȣ��" << endl;
		this->Add( _targetIndex );
		return;
	}

	// Ư����� ����
	CNode* pTargetNode		= SearchNode( _targetIndex );
	if( pTargetNode == NULL )
	{
		cout << "������ ����� ��ġ�� ã�� ���߽��ϴ�." << endl;
		return;
	}

	// ���Ե� ��� ����
	CNode* pNewNode			= new CNode();
	if ( pNewNode == NULL )
	{
		cout << "���Ե� ��尡 ���� ���� �ʾҽ��ϴ�." << endl;
		return;
	}

	// �߰��� ��� ����
	pNewNode->m_data	= _insertData;
	pNewNode->m_pPre	= pTargetNode;
	pNewNode->m_pNext	= pTargetNode->m_pNext;

	// ���� ��� ����
	pTargetNode->m_pNext = pNewNode;

	// ���� ��� ����
	pNewNode->m_pNext->m_pPre = pNewNode;

	m_count++;
}

// ��� Ž��
CNode* CLinkedList::SearchNode(int _search)
{
	// ���� ����� �ε���
	int index = 0;
	// Ž�� ���
	CNode* pSearchNode = m_pHead;

	// ���� �ε����� �� -> �ε����� ��ȭ
	while( index < _search )
	{
		pSearchNode = pSearchNode->m_pNext;
		index++;
	}

	return pSearchNode;
}

// ����Ʈ�� ���
void CLinkedList::PrintList()
{
	if ( m_pHead == NULL )
	{
		cout << "ť�� ���� �����Ͱ� ����." << endl;
		return;
	}

	CNode* pPrintNode = m_pHead;

	do
	{
		cout << pPrintNode->m_data << "  ";
		pPrintNode = pPrintNode->m_pNext;
	} while( pPrintNode != NULL );

	cout << endl;
}



// ����Ʈ�� ���� �Ųٷ� ���
void CLinkedList::ReversePrintList( )
{
	if(m_pTail == NULL)
	{
		cout << "ReversePrintList( ) ������ ��尡 �����ϴ�." << endl;
		return;
	}

	CNode* pReverse = m_pTail;

	do
	{
		cout << pReverse->m_data << "  ";
		pReverse = pReverse->m_pPre;
	} while( pReverse != NULL );

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

	return m_pTail->m_data;
}