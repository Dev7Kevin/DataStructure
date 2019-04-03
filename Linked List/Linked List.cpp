// Linked List.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "List.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CLinkedList* pList = new CLinkedList();

	if(pList == NULL)
		return 0;

	cout << "Add 테스트" << endl;	
	pList->Add(0);
	pList->Add(1);
	pList->Add(2);
	pList->Add(3);
	pList->Add(4);
	pList->PrintList();

	cout << "DeleteNode 테스트" << endl;
	pList->DeleteNode(1);
	pList->PrintList();

	cout << "InsertNode 테스트" << endl;
	pList->Insert(4, 1);
	pList->PrintList();

	pList->ReversePrintList();

	pList->DeleteList();

	if(pList != NULL)
		delete pList;

	pList = NULL;

	return 0;
}

