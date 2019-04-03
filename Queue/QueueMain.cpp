// Queue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Queue.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue* pQueue = new CQueue( 5 );
	if ( pQueue == NULL )
	{
		cout << "ť ���� ����." << endl;
		return 0;
	}

	pQueue->Put(1);
	pQueue->Put(2);
	pQueue->Put(3);
	pQueue->Put(4);
	pQueue->Put(5);
	pQueue->Put(6);

	pQueue->PrintQueue();

	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;
	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;
	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;
	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;
	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;
	cout << "ť�� �� ������ ��: " << pQueue->Get() << endl;

	pQueue->Put(4);
	pQueue->PrintQueue();
	pQueue->Get();
	pQueue->PrintQueue();

	delete pQueue;
	pQueue = NULL;

	return 0;
}

