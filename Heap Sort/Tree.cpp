#include "stdafx.h"
#include "Tree.h"

using namespace std;

CTree::CTree( )
{
	m_pTreeRoot = NULL;
	m_pCurrnent = NULL;
	
	m_count = -1;
}

// 리스트의 끝에 노드를 생성
void CTree::Add( int _data )
{
	// 새로운 노드 초기화
	CNode* pNewNode = new CNode( );
	if ( pNewNode == NULL )
	{
		cout << "삽입될 노드가 생성 되지 않았습니다." << endl;
		return;
	}

	pNewNode->m_data	= _data;
	pNewNode->m_pLeft	= NULL;
	pNewNode->m_pRight	= NULL;
	pNewNode->m_pParent	= NULL;
	
	if ( m_pTreeRoot == NULL )
	{
		m_pTreeRoot = pNewNode;
		m_count++;

		return;
	}

	TraverseAdd( m_pTreeRoot, pNewNode );
}


// 노드 순차 탐색
void CTree::TraverseAdd( CNode* pCurrentNode, CNode* pNewNode )
{
	if ( pNewNode == NULL )
	{
		cout << "TraverseAdd() 새로운 노드 값이 NULL입니다." << endl;
		return;
	}

	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseAdd() 트리가 비어있습니다." << endl;
		return;
	}

	if ( pCurrentNode == NULL )
	{
		cout << "TraverseAdd() pCurrentNode값이 NULL 입니다." << endl;
		return;
	}



	// 왼쪽으로 간다
	if ( pCurrentNode->m_data > pNewNode->m_data )
	{
		if ( pCurrentNode->m_pLeft == NULL )
		{
			pNewNode->m_pParent		= pCurrentNode;
			pCurrentNode->m_pLeft	= pNewNode;
			m_count++;

			return;
		}
		else
			TraverseAdd( pCurrentNode->m_pLeft, pNewNode );
	}
	// 오른쪽으로 간다
	else
	{
		if ( pCurrentNode->m_pRight == NULL )
		{
			pNewNode->m_pParent		= pCurrentNode;
			pCurrentNode->m_pRight	= pNewNode;
			m_count++;

			return;
		}
		else
			TraverseAdd( pCurrentNode->m_pRight, pNewNode );
	}
}

// 리스트를 출력
void CTree::PrintTree( )
{
	//TraversePreorder( m_pTreeRoot );
	//cout << endl;

	TraverseInorder( m_pTreeRoot );
	cout << endl;

	//TraversePostorder( m_pTreeRoot );
	//cout << endl;
}

// 전위 순회
void CTree::TraversePreorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraversePrint() 트리가 없습니다." << endl;
		return;
	}

	if ( pPrintNode == NULL )
		return;

	cout << pPrintNode->m_data << " " ;

	TraversePreorder( pPrintNode->m_pLeft );
	TraversePreorder( pPrintNode->m_pRight );
}

// 중위 순회
void CTree::TraverseInorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseInorder() 생성된 노드가 없습니다." << endl;
		return;
	}

	if ( pPrintNode == NULL )
	{
		cout << "TraverseInorder() 인자 값이 NULL 입니다." << endl;
		return ;
	}

	if ( pPrintNode->m_pLeft != NULL )
		TraverseInorder(pPrintNode->m_pLeft);     

	cout << pPrintNode->m_data << " ";

	if ( pPrintNode->m_pRight != NULL )
		TraverseInorder(pPrintNode->m_pRight);

}

// 후위 순회
void CTree::TraversePostorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseInorder() 생성된 노드가 없습니다." << endl;
		return;
	}

	if ( pPrintNode == NULL )
	{
		cout << "TraverseInorder() 인자 값이 NULL 입니다." << endl;
		return ;
	}    

	if ( pPrintNode->m_pLeft != NULL )
		TraversePostorder(pPrintNode->m_pLeft); 

	if ( pPrintNode->m_pRight != NULL )
		TraversePostorder(pPrintNode->m_pRight);

	cout << pPrintNode->m_data << " ";
}

// 특정 수를 지운다.
void CTree::Delete( int _searchData )
{
	TraverseDelete( m_pTreeRoot, m_pTreeRoot->m_pParent, _searchData );
}

// 지우기 재귀
void CTree::TraverseDelete( CNode* pDeleteNode, CNode* pParent, int _searchData )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseDelete() 트리가 없습니다." << endl;
		return;
	}

	if ( _searchData < 0 )
	{
		cout << "TraverseDelete() 0보다 큰 수를 입력하세요." << endl;
		return;
	}

	if ( pDeleteNode == NULL )
	{
		cout << "TraverseDelete() 값 없음" << endl;
		return;
	}




	CNode* pDel = NULL;

	// 왼쪽으로 이동
	if ( pDeleteNode->m_data > _searchData )
		TraverseDelete( pDeleteNode->m_pLeft, pDeleteNode, _searchData );
	else if ( pDeleteNode->m_data < _searchData )
		TraverseDelete( pDeleteNode->m_pRight, pDeleteNode, _searchData );
	else	// 목표 값을 찾음
	{
		pDel = pDeleteNode;

		// 양쪽 자식이 없는 경우
		if ( pDeleteNode->m_pLeft == NULL && pDeleteNode->m_pRight == NULL )
		{
			if ( pParent->m_pLeft == pDeleteNode )
				pParent->m_pLeft = NULL;
			else
				pParent->m_pRight = NULL;
		}
		else
		{
			// 양쪽이 다 있는 경우
			if ( pDeleteNode->m_pLeft != NULL && pDeleteNode->m_pRight != NULL )
			{
				// 부모 노드의 왼쪽 오른쪽을 판별.
				// 부모 노드의 오른쪽.
				//(오른쪽 자식 노드를 올린다)
				if ( pParent->m_pRight == pDeleteNode )
					pParent->m_pRight = pDeleteNode->m_pRight;
				else
					pParent->m_pLeft = pDeleteNode->m_pRight;

				CNode* pLinkTemp = pDeleteNode->m_pRight->m_pLeft;

				pDeleteNode->m_pLeft->m_pParent		= pDeleteNode->m_pRight;
				pDeleteNode->m_pRight->m_pLeft		= pDeleteNode->m_pLeft;
				pDeleteNode->m_pRight->m_pParent	= pParent;

				pLinkTemp->m_pParent = pDeleteNode->m_pRight->m_pRight;

				TraverseUpRight( pDeleteNode, pParent );

			}
			else // 자식이 하나만 있는 경우
			{
				CNode* pTemp = NULL;

				// 왼쪽에 값이 있을 경우
				if ( pDeleteNode->m_pLeft != NULL )
					pTemp = pDeleteNode->m_pLeft;
				else
					pTemp = pDeleteNode->m_pRight;

				if ( pParent->m_pLeft == pDeleteNode )
					pParent->m_pLeft = pTemp;
				else
					pParent->m_pRight = pTemp;
			}
		}
	}

	delete pDel;
	pDel = NULL;

	m_count--;
}

void CTree::TraverseUpRight	( CNode* pDeleteNode, CNode* pParent )
{
	if ( pDeleteNode == NULL )
	{
		cout << "TraverseUpRight()  pDeleteNode == NULL" << endl;
		return;
	}

	if ( pDeleteNode->m_pRight == NULL )
	{
		cout << "TraverseUpRight() pDeleteNode->m_pRight == NULL" << endl;
		return;
	}

	

	TraverseUpRight ( pDeleteNode->m_pRight, pDeleteNode->m_pRight );

}


void CTree::DeleteTree( )
{
	TraverseDeleteAll( m_pTreeRoot );
}

void CTree::TraverseDeleteAll( CNode* pDeleteAll )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseDeleteAll() 생성된 노드가 없습니다." << endl;
		return;
	}

	if ( pDeleteAll != NULL )
	{
		TraverseDeleteAll( pDeleteAll->m_pLeft );
		TraverseDeleteAll( pDeleteAll->m_pRight );

		delete pDeleteAll;
		pDeleteAll = NULL;
	}
}

CNode* CTree::GetRoot ( )
{
	return m_pTreeRoot;
}