// Stack.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Stack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	CStack* pStack = new CStack(10);
	if( pStack == NULL )
	{
		cout << "���� ���� ����" << endl;
		return 0;
	}

	pStack->Push(3);
	pStack->Push(1);
	pStack->Push(2);
	pStack->Push(5);
	pStack->PrintSTack();

	pStack->Pop();
	pStack->Pop();
	pStack->PrintSTack();

	return 0;
}

