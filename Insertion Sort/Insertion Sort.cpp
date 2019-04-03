/*
	삽입 정렬에서는 평균적으로 N^2번의 비교 연산과 N^2번의 이동연산을 수행한다.
	최악의 경우에는 평균적인 경우보다 비교 연산 및 이동 연산을 두배 더 수행하게 된다.
*/

#include "stdafx.h"
#include "Insertion.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int DataArray[DATA_MAX] = { 0, };
	int n = 0;

	CInsertion* pInsertion = new CInsertion();
	if ( pInsertion == NULL )
	{
		cout << "인설트 객체 생성 실패" << endl;
		return 0;
	}

	srand((unsigned int)time( NULL ) );

	for( n = 0; n < DATA_MAX; n++ )
		DataArray[n] = ( rand() % 14 ) + 1;

	pInsertion->Sort( DataArray, 0, DATA_MAX );
	pInsertion->Print();


	if ( pInsertion != NULL )
	{
		delete pInsertion;
		pInsertion = NULL;
	}


	return 0;
}
