#include "stdafx.h"
#include "Bubble.h"

using namespace std;

CBubble::CBubble()
{
	m_pData = NULL;
}

CBubble::~CBubble()
{
}

void CBubble::Swap( int* a, int* b )
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

void CBubble::Sort( int* pData, int left, int right )
{
	if ( pData == NULL )
	{
		cout << "Sort() pData���� NULL �Դϴ�." << endl;
		return;
	}

	if ( left < 0 )
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
	int i, index;

	for ( i = left; i < right; i++ )
		for ( index = right-1; index > i; index-- )
			if ( m_pData[index - 1] > m_pData[index] )
				Swap( &m_pData[index - 1], &m_pData[index] );	
}

void CBubble::Print()
{
	int n = 0;

	for( n = 0; n < DATA_MAX; n++ )
		cout << m_pData[n] << " ";

	cout << endl;
}