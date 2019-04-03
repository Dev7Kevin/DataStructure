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
		// �о�� Src�� �ش��ϴ� ��带 ã�Ƽ� ��ȯ
        pSrc = this->SearchNode( Src );
		// �ش� ��尡 ������ ��� ����
		if ( pSrc == NULL )
			pSrc = this->CreateUpNode( Src );

		pDest = this->SearchNode( Dest );
		if ( pDest == NULL )
			pDest = this->CreateUpNode( Dest );

		// �� ���� �ο� ��� ��ũ
		this->CreateLowNode( pSrc, pDest );
	}

	CUpNode* pUpPrintNode = m_pUpStart;

	this->PrintUpList( pUpPrintNode );

	// �� �� ����� ���� ��� ���
	while ( pUpPrintNode != NULL )
	{
		this->PrintLowList( pUpPrintNode );

		pUpPrintNode = pUpPrintNode->m_pNext;
	}

	fclose( fin );
}



// �� ��� ����
CUpNode* CGraphManager::CreateUpNode( int Data )
{
	if ( Data < 0 )
	{
		cout << "CreateUpNode() ���� Data ���� ���� �Դϴ�." << endl;
		return NULL;
	}

	CUpNode* pNewUpNode = new CUpNode();
	if ( pNewUpNode == NULL )
	{
		cout << "CreateUpNode() ���ο� ��� ���� ����" << endl;
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


// ���� �θ� �����, ã�ư����� �� ���.
void CGraphManager::CreateLowNode( CUpNode* pUpParent, CUpNode* pUpMyNode )
{
	if ( pUpMyNode == NULL )
	{
		cout << "CreateLowNode() ���� pUpMyNode ���� NULL �Դϴ�." << endl;
		return;
	}

	if ( pUpParent == NULL )
	{
		cout << "CreateLowNode() ���� pUpParent���� NULL �Դϴ�." << endl;
		return;
	}

	// Ʋ�� !!
	CLowNode* pNewLowNode = new CLowNode();
	if ( pNewLowNode == NULL )
	{
		cout << "CreateLowNode() ���ο� ��� ���� ����" << endl;
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


// �� ��� �˻�
CUpNode* CGraphManager::SearchNode( int Data )
{
	if ( Data  < 0 )
	{
		cout << "SearchNode() ���� Data�� ���� �Դϴ�." << endl;
		return NULL;
	}

	if ( m_pUpStart == NULL )
	{
		cout << "SearchNode() �׷����� ������ϴ�." << endl;
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


// �ο� ����� ������ -����- ��带 ����
CLowNode* CGraphManager::GetLowEndNode( CUpNode* pUpParentNode )
{
	if ( m_pUpStart == NULL )
	{
		cout << "GetLowEndNode() �׷����� ������ϴ�." << endl;
		return NULL;
	}

	if ( pUpParentNode == NULL )
	{
		cout << "GetLowEndNode() ���� pUpParentNode�� NULL �Դϴ�." << endl;
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


// �� ��� ���
void CGraphManager::PrintUpList( CUpNode* pUpStartNode )
{
	if ( pUpStartNode ==  NULL )
	{
		cout << "PrintUpList() �׷����� ���� ���� �ʾҽ��ϴ�." << endl;
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


// �ο� ��� ���
void CGraphManager::PrintLowList( CUpNode* pUpStartNode )
{
	if ( pUpStartNode == NULL )
	{
		cout << "PrintLowList() ������ ���� ���� �ʽ��ϴ�." << endl;
		return;
	}

	if ( pUpStartNode->m_pLow == NULL )
	{
		cout << "PrintLowList() ����� ������ �����ϴ�." << endl;
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




















