// Tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Tree.h"
#include "Queue.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CTree* pTree = new CTree();
	if ( pTree == NULL )
	{
		cout << "트리 생성 실패" << endl;
		return 0;
	}

	CQueue* pQueue = new CQueue( 20 );
	if ( pQueue == NULL)
	{
		cout << "스택 생성 실패" << endl;
	}

	// 트리
	pTree->Add(20);
	pTree->Add(10);
	pTree->Add(30);
	pTree->Add(7);
	pTree->Add(14);
	pTree->Add(25);
	pTree->Add(35);
	pTree->Add(3);
	pTree->Add(9);
	pTree->Add(11);
	pTree->Add(26);
	//pTree->PrintTree();

	// 큐
	
	pQueue->PrintQueue( pTree->GetRoot() );



	// 제거
	pTree->DeleteTree();

	delete pTree;
	pTree = NULL;

	delete pQueue;
	pQueue = NULL;

	return 0;
}