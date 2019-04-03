#include "stdafx.h"
#include "Heap.h"

using namespace std;

CHeap::CHeap(int _Size)
{
	m_Size		= _Size;
	m_Current	= 0;
}

CHeap::~CHeap()
{
}

void CHeap::Insert( int Value )
{
	if ( m_Data == NULL )
	{
		cout << "Insert() m_Data값이 NULL 입니다." << endl;
		return;
	}

	// Value 값 0 이상으로 제한
	if ( Value < 0 )
	{
		cout << "Insert() Value값이 음수 입니다." << endl;
		return;
	}

	if ( m_Current >= m_Size )
	{
		cout << "Insert() 배열이 꽉 찼습니다." << endl;
		return;
	}

	m_Data[m_Current] = Value;

	this->GoUp( m_Current );

	m_Current++;
}

void CHeap::GoUp( int Index )
{
	if ( m_Data == NULL )
	{
		cout << "GoUp() pData값이 NULL 입니다." << endl;
		return;
	}

	if ( Index < 0 )
	{
		cout << "GoUp() Index값이 음수 입니다." << endl;
		return;
	}

	if ( m_Current >= m_Size )
	{
		cout << "GoUp() 배열이 꽉 찼습니다." << endl;
		return;
	}

	while ( Index > 0 )
	{
		if ( m_Data[ (Index - 1) / 2 ] < m_Data[Index] )
			this->Swap( &m_Data[ ( Index - 1 ) / 2 ], &m_Data[Index] );

		Index = (Index - 1) / 2;
	}
}

int CHeap::Delete()
{
	if ( m_Data == NULL )
	{
		cout << "Delete() m_Data값이 NULL 입니다." << endl;
		return -1;
	}

	if ( m_Current <= 0 )
	{
		cout << "Delete() 배열에 값이 없습니다." << endl;
		return -1;
	}

	int temp = m_Data[0];
	m_Current--;

	this->Swap( &m_Data[0] , ( &m_Data[m_Current]) );
	m_Data[m_Current] = -1;
	this->GoDown( m_Data, 0, m_Current );
	
	
	return temp;
}


void CHeap::GoDown( int* pData, int Index, int n )
{
	if ( pData == NULL )
	{
		cout << "GoDown() pData값이 NULL 입니다." << endl;
		return;
	}

	if ( Index < 0 )
	{
		cout << "GoDown() k값이 음수 입니다." << endl;
		return;
	}

	if ( n < 0 )
	{
		cout << "GoDown() n값이 음수 입니다." << endl;
		return;
	}

	int child;

	while ( (2 * Index) + 1  < n )
	{
		child = (2 * Index) + 1;
		if ( child < n )
		{
			if ( *( pData + child ) < *( pData + child + 1 ) )
				child++;

			if ( *( pData + Index ) >= *( pData + child ) )
				break;

			this->Swap( ( pData + Index ), ( pData + child ) );

			Index = child;
		}
	};
}


void CHeap::Swap( int* a, int* b )
{
	if ( a == NULL )
	{
		cout << "Swap() a값이 NULL 입니다." << endl;
		return;
	}

	if ( b == NULL )
	{
		cout << "Swap() b값이 NULL 입니다." << endl;
		return;
	}

	int temp = 0;

	temp = *a;
	*a	 = *b;
	*b	 = temp;
}



void CHeap::Print()
{
	if ( m_Data == NULL )
	{
		cout << "Print() 들어온 값이 없습니다." << endl;
		return;
	}

	if ( m_Current <= 0 )
	{
		cout << "Print() 배열에 값이 없습니다." << endl;
		return;
	}


	int i;

	for ( i = 0; i < m_Current; i++ )
		cout << m_Data[i] << " ";

	cout << endl;
}
















