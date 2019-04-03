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
        cout << "Swap() 인자 a의 값이 NULL입니다." << endl;
		return; 
	}

	if ( b == NULL ) 
	{
        cout << "Swap 인자 b의 값이 NULL입니다." << endl;
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
		cout << "Sort() pData값이 NULL 입니다." << endl;
		return;
	}

	if ( left < 0  )
	{
		cout << "Sort() left값이 음수 입니다." << endl;
		return;
	}

	if ( right < 0 )
	{
		cout << "Sort() right값이 음수 입니다." << endl;
		return;
	}

	if ( left > right )
	{
		cout << "Sort() left값이 right값보다 큽니다." << endl;
		return;
	}

	if ( left > DATA_MAX )
	{
		cout << "Sort() left값이 DATA_MAX값 보다 큽니다." << endl;
		return;
	}

	if ( right > DATA_MAX )
	{
		cout << "Sort() right값이 DATA_MAX값 보다 큽니다." << endl;
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