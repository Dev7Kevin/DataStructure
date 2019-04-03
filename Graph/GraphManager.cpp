#include "stdafx.h"
#include "Graph.h"
#include "GraphManager.h"
#include "fstream"
#include "iostream"

using namespace std;

CGraphManager::CGraphManager()
{
	m_pUpStart		= NULL;
	m_pUpEnd		= NULL;
}


CGraphManager::~CGraphManager()
{
}


void CGraphManager::ReadData()
{
	FILE* fin;
	fin = fopen( "GraphRead.txt", "r");

	int	 Src, Dest;
	CUpNode *pSrc, *pDest;

	while( fscanf( fin, "%d %d", &Src, &Dest ) > 0 )
	{
		// 읽어온 Src에 해당하는 노드를 찾아서 반환
        pSrc = this->SearchNode( Src );
		// 해당 노드가 없으면 노드 생성
		if ( pSrc == NULL )
			pSrc = this->CreateUpNode( Src );

		pDest = this->SearchNode( Dest );
		if ( pDest == NULL )
			pDest = this->CreateUpNode( Dest );

		// 업 노드와 로우 노드 링크
		this->CreateLowNode( pSrc, pDest );
	}

	CUpNode* pUpPrintNode = m_pUpStart;

	this->PrintUpList( pUpPrintNode );

	// 각 업 노드의 하위 노드 출력
	while ( pUpPrintNode != NULL )
	{
		this->PrintLowList( pUpPrintNode );

		pUpPrintNode = pUpPrintNode->m_pNext;
	}

	fclose( fin );
}



// 업 노드 생성
CUpNode* CGraphManager::CreateUpNode( int Data )
{
	if ( Data < 0 )
	{
		cout << "CreateUpNode() 인자 Data 값이 음수 입니다." << endl;
		return NULL;
	}

	CUpNode* pNewUpNode = new CUpNode();
	if ( pNewUpNode == NULL )
	{
		cout << "CreateUpNode() 새로운 노드 생성 실패" << endl;
		return NULL;
	}

	
	pNewUpNode->m_VertexData	= Data;
	pNewUpNode->m_pNext			= NULL;
	pNewUpNode->m_pLow			= NULL;

	if ( m_pUpStart == NULL )
		m_pUpStart = pNewUpNode;
	else
		m_pUpEnd->m_pNext = pNewUpNode;

	m_pUpEnd = pNewUpNode;

	return m_pUpEnd;
}


// 나의 부모 업노드, 찾아가야할 내 노드.
void CGraphManager::CreateLowNode( CUpNode* pUpParent, CUpNode* pUpMyNode )
{
	if ( pUpMyNode == NULL )
	{
		cout << "CreateLowNode() 인자 pUpMyNode 값이 NULL 입니다." << endl;
		return;
	}

	if ( pUpParent == NULL )
	{
		cout << "CreateLowNode() 인자 pUpParent값이 NULL 입니다." << endl;
		return;
	}

	// 틀림 !!
	CLowNode* pNewLowNode = new CLowNode();
	if ( pNewLowNode == NULL )
	{
		cout << "CreateLowNode() 새로운 노드 생성 실패" << endl;
		return;
	}


	pNewLowNode->m_pUpMyNode	= pUpMyNode;
	pNewLowNode->m_pNext		= NULL;

	if ( pUpParent->m_pLow == NULL )
		pUpParent->m_pLow = pNewLowNode;
	else
	{
		CLowNode* pLowPreEndNode = this->GetLowEndNode( pUpParent );
		pLowPreEndNode->m_pNext = pNewLowNode;
	}

}


// 업 노드 검색
CUpNode* CGraphManager::SearchNode( int Data )
{
	if ( Data  < 0 )
	{
		cout << "SearchNode() 인자 Data가 음수 입니다." << endl;
		return NULL;
	}

	if ( m_pUpStart == NULL )
	{
		cout << "SearchNode() 그래프가 비었습니다." << endl;
		return NULL;
	}


	CUpNode* pSearchNode = m_pUpStart;

	while ( pSearchNode != NULL )
	{
		if ( pSearchNode->m_VertexData == Data )
			break;

		pSearchNode = pSearchNode->m_pNext;
	}


	return pSearchNode;
}


// 로우 노드의 마지막 -이전- 노드를 리턴
CLowNode* CGraphManager::GetLowEndNode( CUpNode* pUpParentNode )
{
	if ( m_pUpStart == NULL )
	{
		cout << "GetLowEndNode() 그래프가 비었습니다." << endl;
		return NULL;
	}

	if ( pUpParentNode == NULL )
	{
		cout << "GetLowEndNode() 인자 pUpParentNode가 NULL 입니다." << endl;
		return NULL;
	}

	CLowNode* pLowEndNode = pUpParentNode->m_pLow;

	if ( pLowEndNode != NULL )
	{
		while ( pLowEndNode->m_pNext != NULL )
			pLowEndNode = pLowEndNode->m_pNext;
	}

    
	return pLowEndNode;
}


// 업 노드 출력
void CGraphManager::PrintUpList( CUpNode* pUpStartNode )
{
	if ( pUpStartNode ==  NULL )
	{
		cout << "PrintUpList() 그래프가 생성 되지 않았습니다." << endl;
		return;
	}

	CUpNode* pPrintUpNode = pUpStartNode;

	while ( pPrintUpNode != NULL )
	{
		cout << pPrintUpNode->m_VertexData << " ";

		pPrintUpNode = pPrintUpNode->m_pNext;
	}

	cout << endl;
}


// 로우 노드 출력
void CGraphManager::PrintLowList( CUpNode* pUpStartNode )
{
	if ( pUpStartNode == NULL )
	{
		cout << "PrintLowList() 정점이 존재 하지 않습니다." << endl;
		return;
	}

	if ( pUpStartNode->m_pLow == NULL )
	{
		cout << "PrintLowList() 연결된 정점이 없습니다." << endl;
		return;
	}

	CLowNode* pPrintLowNode = pUpStartNode->m_pLow;

	while ( pPrintLowNode != NULL )
	{
		cout << pPrintLowNode->m_pUpMyNode->m_VertexData << " ";

		pPrintLowNode = pPrintLowNode->m_pNext;
	}

	cout << endl;
}




















