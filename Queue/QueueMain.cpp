// Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Queue.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue* pQueue = new CQueue( 5 );
	if ( pQueue == NULL )
	{
		cout << "큐 생성 실패." << endl;
		return 0;
	}

	pQueue->Put(1);
	pQueue->Put(2);
	pQueue->Put(3);
	pQueue->Put(4);
	pQueue->Put(5);
	pQueue->Put(6);

	pQueue->PrintQueue();

	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;
	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;
	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;
	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;
	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;
	cout << "큐의 맨 마지막 값: " << pQueue->Get() << endl;

	pQueue->Put(4);
	pQueue->PrintQueue();
	pQueue->Get();
	pQueue->PrintQueue();

	delete pQueue;
	pQueue = NULL;

	return 0;
}

