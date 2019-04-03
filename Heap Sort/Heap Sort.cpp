// Heap Sort.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Heap.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CHeap* pHeap = new CHeap( DATA_MAX );
	if ( pHeap == NULL )
	{
		cout << "�� ��ü ���� ����" << endl;
		return 0;
	}

	pHeap->Insert( 3 );
	pHeap->Insert( 10 );
	pHeap->Insert( 2 );
	pHeap->Insert( 8 );
	pHeap->Insert( 29 );
	pHeap->Insert( 1 );
	pHeap->Insert( 30 );
	pHeap->Print();

	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;
	cout << pHeap->Delete() << endl;

	pHeap->Print();

	delete pHeap;
	pHeap = NULL;

	return 0;
}

