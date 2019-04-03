#include "stdafx.h"
#include "Insertion.h"

using namespace std;

CInsertion::CInsertion()
{
	m_pData = NULL;
}

CInsertion::~CInsertion()
{
}

void CInsertion::Swap( int* a, int* b )
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

void CInsertion::Sort( int* pData, int left, int right )
{
	if ( pData == NULL )
	{
		cout << "Sort() pData값이 NULL 입니다." << endl;
		return;
	}

	if ( left < 0 )
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
	int index = 0;

	// 가장 작은 값
	for( index = right, index > left; index--; )
		if ( m_pData[index - 1] > m_pData[index] )
			Swap( &m_pData[index - 1], &m_pData[index] );


	// 0 번 인덱스 이후 정렬
	for( index = left + 2; index < right; index++ )
	{
		int insertIndex = index; 
		int nextValue = pData[index];

		while( m_pData[insertIndex - 1] > nextValue )  
		{
			m_pData[insertIndex] = m_pData[insertIndex - 1];  
			insertIndex--;
			m_pData[insertIndex] = nextValue;
		}
	}
}

void CInsertion::Print()
{
	int n = 0;

	for( n = 0; n < DATA_MAX; n++ )
		cout << m_pData[n] << " ";

	cout << endl;
}