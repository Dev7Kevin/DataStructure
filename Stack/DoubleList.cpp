#include "stdafx.h"
#include "DoubleList.h"

using namespace std;

CLinkedList::CLinkedList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	
	m_count = -1;
}

// 리스트의 끝에 노드를 생성
void CLinkedList::Add(int _data)
{
	// 새로운 노드 초기화
	CNode* pNewNode = new CNode();
	if ( pNewNode == NULL )
	{
		cout << "삽입될 노드가 생성 되지 않았습니다." << endl;
		return;
	}

	pNewNode->m_data	= _data;
	pNewNode->m_pPre	= NULL;
	pNewNode->m_pNext	= NULL;

	// 링크드 리스트에 노드 추가
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

// 특정 노드를 제거
void CLinkedList::DeleteNode( int _deleteIndex )
{
	if( _deleteIndex < 0 )
	{
		cout << "목표 노드 값이 너무 작습니다." << endl;
		return;
	}

	if( m_count < 0 )
	{
		cout << "DeleteNode() 생성된 노드가 없습니다." << endl;
		return;
	}

	if( m_count < _deleteIndex )
	{
		cout << "생성된 노드보다 큰 인덱스 값." << endl;
		return;
	}

	CNode* pDeleteNode =  SearchNode( _deleteIndex );
	if( pDeleteNode == NULL )
	{
		cout << "삭제할 노드를 찾지 못했습니다" << endl;
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
		// 헤더 하나만 남았다.
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

// 마지막 노드를 제거
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
		// 헤더 하나만 남았다.
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

// 리스트의 노드를 모두 제거
void CLinkedList::DeleteList()
{
	if(m_pHead == NULL)
	{
		cout << "DeleteList() 생성된 노드가 없습니다." << endl;
		return;
	}

	CNode* pDelete;

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

// 특정 노드 다음에 노드를 삽입
void CLinkedList::Insert(int _targetIndex, int _insertData)
{
	// 예외처리 구역
	if ( _targetIndex < 0 )
	{
		cout << "목표 노드 값이 너무 작습니다." << endl;
		return;
	}

	if ( m_count < 0 )
	{
		cout << "Insert() 생성된 노드가 없습니다." << endl;
		return;
	}

	if ( m_count < _targetIndex )
	{
		cout << "생성된 노드보다 큰 인덱스 값." << endl;
		return;
	}

	if ( m_count == _targetIndex )
	{
		cout << "리스트의 끝에 추가 하므로 Add를 호출" << endl;
		this->Add( _targetIndex );
		return;
	}

	// 특정노드 설정
	CNode* pTargetNode		= SearchNode( _targetIndex );
	if( pTargetNode == NULL )
	{
		cout << "삽입할 노드의 위치를 찾지 못했습니다." << endl;
		return;
	}

	// 삽입될 노드 설정
	CNode* pNewNode			= new CNode();
	if ( pNewNode == NULL )
	{
		cout << "삽입될 노드가 생성 되지 않았습니다." << endl;
		return;
	}

	// 추가될 노드 설정
	pNewNode->m_data	= _insertData;
	pNewNode->m_pPre	= pTargetNode;
	pNewNode->m_pNext	= pTargetNode->m_pNext;

	// 이전 노드 설정
	pTargetNode->m_pNext = pNewNode;

	// 다음 노드 설정
	pNewNode->m_pNext->m_pPre = pNewNode;

	m_count++;
}

// 노드 탐색
CNode* CLinkedList::SearchNode(int _search)
{
	// 현재 노드의 인덱스
	int index = 0;
	// 탐색 노드
	CNode* pSearchNode = m_pHead;

	// 현재 인덱스와 비교 -> 인덱스를 변화
	while( index < _search )
	{
		pSearchNode = pSearchNode->m_pNext;
		index++;
	}

	return pSearchNode;
}

// 리스트를 출력
void CLinkedList::PrintList()
{
	if ( m_pHead == NULL )
	{
		cout << "큐에 들어온 데이터가 없음." << endl;
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



// 리스트의 값을 거꾸로 출력
void CLinkedList::ReversePrintList( )
{
	if(m_pTail == NULL)
	{
		cout << "ReversePrintList( ) 생성된 노드가 없습니다." << endl;
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

	return m_pTail->m_data;
}