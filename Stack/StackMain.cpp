// Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Stack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	CStack* pStack = new CStack(10);
	if( pStack == NULL )
	{
		cout << "스택 생성 실패" << endl;
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

