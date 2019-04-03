// Tree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << "Ʈ�� ���� ����" << endl;
		return 0;
	}

	CQueue* pQueue = new CQueue( 20 );
	if ( pQueue == NULL)
	{
		cout << "���� ���� ����" << endl;
	}

	// Ʈ��
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

	// ť
	
	pQueue->PrintQueue( pTree->GetRoot() );



	// ����
	pTree->DeleteTree();

	delete pTree;
	pTree = NULL;

	delete pQueue;
	pQueue = NULL;

	return 0;
}