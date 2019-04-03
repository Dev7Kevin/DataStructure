/*
	버블 정렬에서는 평균적으로나 최악의 경우 모두에서 N^2번의 비교연산 및 N^2번의 교환 연산을 수행.
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
		cout << "버블 객체 생성 실패" << endl;
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