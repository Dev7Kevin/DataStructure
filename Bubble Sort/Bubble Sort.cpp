/*
	���� ���Ŀ����� ��������γ� �־��� ��� ��ο��� N^2���� �񱳿��� �� N^2���� ��ȯ ������ ����.
*/

#include "stdafx.h"
#include "Bubble.h"

using namespace std;

#define DATA_MAX 10



int _tmain(int argc, _TCHAR* argv[])
{
	int DataArray[DATA_MAX] = { 0, };
	int n = 0;
	
	CBubble* pBubble = new CBubble();
	if ( pBubble == NULL )
	{
		cout << "���� ��ü ���� ����" << endl;
		return 0;
	}

	srand((unsigned int)time( NULL ) );

	for ( n = 0; n < DATA_MAX; n++ )
		DataArray[n] = ( rand() % 14 ) + 1;

	pBubble->Sort( DataArray, 0, DATA_MAX );
	pBubble->Print();


	if ( pBubble != NULL )
	{
		delete pBubble;
		pBubble = NULL;
	}


	return 0;
}