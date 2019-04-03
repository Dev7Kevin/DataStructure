/*
	���� ������ �뷫 N^2 ���� �� ����� N���� ��ȯ ������ �����Ѵ�.
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
		cout << "���¼� ��ü ���� ����" << endl;
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