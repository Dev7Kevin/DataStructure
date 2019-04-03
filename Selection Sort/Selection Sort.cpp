/*
	선택 정렬은 대략 N^2 번의 비교 연산과 N번의 교환 연산을 수행한다.
*/

#include "stdafx.h"
#include "Selection.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int DataArray[ DATA_MAX ] = { 0, };
	int n = 0;

	CSelection* pSelectionSort = new CSelection();
	if ( pSelectionSort == NULL )
	{
		cout << "셀력션 객체 생성 실패" << endl;
		return 0;
	}

	srand( (unsigned int) time( NULL ) );

	for( n = 0; n < DATA_MAX; n++ )
		DataArray[n] = ( rand()  % 14 ) + 1;

	pSelectionSort->Sort( DataArray, 0, DATA_MAX );
	pSelectionSort->Print();

	if ( pSelectionSort != NULL )
	{
		delete pSelectionSort;
		pSelectionSort = NULL;
	}


	return 0;
}