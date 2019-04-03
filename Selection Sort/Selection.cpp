#include "stdafx.h"
#include "Selection.h"

using namespace std;

CSelection::CSelection()
{
	m_pData = NULL;
}

CSelection::~CSelection()
{
}


void CSelection::Swap( int* a, int* b )
{
	if ( a == NULL ) 
	{
        cout << "Swap() ���� a�� ���� NULL�Դϴ�." << endl;
		return; 
	}

	if ( b == NULL ) 
	{
        cout << "Swap ���� b�� ���� NULL�Դϴ�." << endl;
		return; 
	}

	int temp = 0;

	temp = *a;
	*a	 = *b;
	*b	 = temp;
}

void CSelection::Sort( int* pData, int left, int right )
{
	if ( pData == NULL )
	{
		cout << "Sort() pData���� NULL �Դϴ�." << endl;
		return;
	}

	if ( left < 0  )
	{
		cout << "Sort() left���� ���� �Դϴ�." << endl;
		return;
	}

	if ( right < 0 )
	{
		cout << "Sort() right���� ���� �Դϴ�." << endl;
		return;
	}

	if ( left > right )
	{
		cout << "Sort() left���� right������ Ů�ϴ�." << endl;
		return;
	}

	if ( left > DATA_MAX )
	{
		cout << "Sort() left���� DATA_MAX�� ���� Ů�ϴ�." << endl;
		return;
	}

	if ( right > DATA_MAX )
	{
		cout << "Sort() right���� DATA_MAX�� ���� Ů�ϴ�." << endl;
		return;
	}



	m_pData = pData;

	for( int pivot = 0; pivot < DATA_MAX - 1; pivot++ )
	{
		for ( int compare = pivot + 1; compare < DATA_MAX; compare++ )
		{
			if ( m_pData[pivot] > m_pData[compare] )
				Swap( &m_pData[pivot], &m_pData[compare] );
		}
	}
}

void CSelection::Print()
{
	int n = 0;

	for( n = 0; n < DATA_MAX; n++ )
		cout << m_pData[n] << " ";

	cout << endl;
}