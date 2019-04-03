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

// 리스트의 끝에 노드를 생성
void CLinkedList::Add( CNode* pAddNode )
{
	// 새로운 노드 초기화
	CQNode* pNewNode = new CQNode();
	if ( pNewNode == NULL )
	{
		cout << "삽입될 노드가 생성 되지 않았습니다." << endl;
		return;
	}

	pNewNode->m_pData	= pAddNode;
	pNewNode->m_pPre	= NULL;
	pNewNode->m_pNext	= NULL;

	// 링크드 리스트에 노드 추가
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



// 헤드 제거
void CLinkedList::DeleteHead()
{
	CQNode newHead = *m_pHead;

	delete m_pHead;

	m_pHead = newHead.m_pNext;

	/*if ( m_pHead == NULL )
	{
		cout << endl <<"DeleteHead() 헤더가 널입니다. " << endl;
		return;
	}*/

	m_count--;
}

// 리스트의 노드를 모두 제거
void CLinkedList::DeleteList()
{
	if(m_pHead == NULL)
	{
		cout << "DeleteList() 생성된 노드가 없습니다." << endl;
		return;
	}

	CQNode* pDelete;

	// 헤더가 NULL이 될때까지 삭제
	while( m_pHead != NULL )
	{
		pDelete = m_pHead;

		m_pHead = m_pHead->m_pNext;

		delete pDelete;
		pDelete = NULL;
	}

	m_pTail = NULL;
}



// 리스트를 출력
void CLinkedList::PrintList()
{
	if ( m_pHead == NULL )
	{
		cout << "큐에 들어온 데이터가 없음." << endl;
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


// 리스트의 노드 수를 리턴
int CLinkedList::GetCount()
{
	return m_count;
}

// 리스트의 마지막 노드의 값을 리턴
int CLinkedList::GetLastData( )
{
	if ( m_pHead == NULL )
	{
		cout << "GetLastData( ) 생성된 노드가 없습니다." << endl;
		return 0;
	}

	return m_pTail->m_pData->m_data;
}

CQNode* CLinkedList::GetHead()
{
	if ( m_pHead ==  NULL )
	{
		cout << endl <<"GetHead() 헤드가 NULL 입니다." << endl;
		return NULL;
	}

	return m_pHead;
}

CQNode* CLinkedList::GetTail()
{
	if ( m_pTail ==  NULL )
	{
		cout << "GetTail() 테일이 NULL 입니다." << endl;
		return NULL;
	}

	return m_pTail;
}



















