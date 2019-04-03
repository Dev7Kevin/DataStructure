/*
	���� ���Ŀ����� ��������� N^2���� �� ����� N^2���� �̵������� �����Ѵ�.
	�־��� ��쿡�� ������� ��캸�� �� ���� �� �̵� ������ �ι� �� �����ϰ� �ȴ�.
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
		cout << "�μ�Ʈ ��ü ���� ����" << endl;
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
