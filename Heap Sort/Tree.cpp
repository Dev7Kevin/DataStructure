#include "stdafx.h"
#include "Tree.h"

using namespace std;

CTree::CTree( )
{
	m_pTreeRoot = NULL;
	m_pCurrnent = NULL;
	
	m_count = -1;
}

// ����Ʈ�� ���� ��带 ����
void CTree::Add( int _data )
{
	// ���ο� ��� �ʱ�ȭ
	CNode* pNewNode = new CNode( );
	if ( pNewNode == NULL )
	{
		cout << "���Ե� ��尡 ���� ���� �ʾҽ��ϴ�." << endl;
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


// ��� ���� Ž��
void CTree::TraverseAdd( CNode* pCurrentNode, CNode* pNewNode )
{
	if ( pNewNode == NULL )
	{
		cout << "TraverseAdd() ���ο� ��� ���� NULL�Դϴ�." << endl;
		return;
	}

	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseAdd() Ʈ���� ����ֽ��ϴ�." << endl;
		return;
	}

	if ( pCurrentNode == NULL )
	{
		cout << "TraverseAdd() pCurrentNode���� NULL �Դϴ�." << endl;
		return;
	}



	// �������� ����
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
	// ���������� ����
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

// ����Ʈ�� ���
void CTree::PrintTree( )
{
	//TraversePreorder( m_pTreeRoot );
	//cout << endl;

	TraverseInorder( m_pTreeRoot );
	cout << endl;

	//TraversePostorder( m_pTreeRoot );
	//cout << endl;
}

// ���� ��ȸ
void CTree::TraversePreorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraversePrint() Ʈ���� �����ϴ�." << endl;
		return;
	}

	if ( pPrintNode == NULL )
		return;

	cout << pPrintNode->m_data << " " ;

	TraversePreorder( pPrintNode->m_pLeft );
	TraversePreorder( pPrintNode->m_pRight );
}

// ���� ��ȸ
void CTree::TraverseInorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseInorder() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	if ( pPrintNode == NULL )
	{
		cout << "TraverseInorder() ���� ���� NULL �Դϴ�." << endl;
		return ;
	}

	if ( pPrintNode->m_pLeft != NULL )
		TraverseInorder(pPrintNode->m_pLeft);     

	cout << pPrintNode->m_data << " ";

	if ( pPrintNode->m_pRight != NULL )
		TraverseInorder(pPrintNode->m_pRight);

}

// ���� ��ȸ
void CTree::TraversePostorder( CNode* pPrintNode )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseInorder() ������ ��尡 �����ϴ�." << endl;
		return;
	}

	if ( pPrintNode == NULL )
	{
		cout << "TraverseInorder() ���� ���� NULL �Դϴ�." << endl;
		return ;
	}    

	if ( pPrintNode->m_pLeft != NULL )
		TraversePostorder(pPrintNode->m_pLeft); 

	if ( pPrintNode->m_pRight != NULL )
		TraversePostorder(pPrintNode->m_pRight);

	cout << pPrintNode->m_data << " ";
}

// Ư�� ���� �����.
void CTree::Delete( int _searchData )
{
	TraverseDelete( m_pTreeRoot, m_pTreeRoot->m_pParent, _searchData );
}

// ����� ���
void CTree::TraverseDelete( CNode* pDeleteNode, CNode* pParent, int _searchData )
{
	if ( m_pTreeRoot == NULL )
	{
		cout << "TraverseDelete() Ʈ���� �����ϴ�." << endl;
		return;
	}

	if ( _searchData < 0 )
	{
		cout << "TraverseDelete() 0���� ū ���� �Է��ϼ���." << endl;
		return;
	}

	if ( pDeleteNode == NULL )
	{
		cout << "TraverseDelete() �� ����" << endl;
		return;
	}




	CNode* pDel = NULL;

	// �������� �̵�
	if ( pDeleteNode->m_data > _searchData )
		TraverseDelete( pDeleteNode->m_pLeft, pDeleteNode, _searchData );
	else if ( pDeleteNode->m_data < _searchData )
		TraverseDelete( pDeleteNode->m_pRight, pDeleteNode, _searchData );
	else	// ��ǥ ���� ã��
	{
		pDel = pDeleteNode;

		// ���� �ڽ��� ���� ���
		if ( pDeleteNode->m_pLeft == NULL && pDeleteNode->m_pRight == NULL )
		{
			if ( pParent->m_pLeft == pDeleteNode )
				pParent->m_pLeft = NULL;
			else
				pParent->m_pRight = NULL;
		}
		else
		{
			// ������ �� �ִ� ���
			if ( pDeleteNode->m_pLeft != NULL && pDeleteNode->m_pRight != NULL )
			{
				// �θ� ����� ���� �������� �Ǻ�.
				// �θ� ����� ������.
				//(������ �ڽ� ��带 �ø���)
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
			else // �ڽ��� �ϳ��� �ִ� ���
			{
				CNode* pTemp = NULL;

				// ���ʿ� ���� ���� ���
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
		cout << "TraverseDeleteAll() ������ ��尡 �����ϴ�." << endl;
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