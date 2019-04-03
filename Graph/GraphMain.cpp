// Graph.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "iostream"
#include "GraphManager.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	CGraphManager* pGraph = new CGraphManager();
	if ( pGraph == NULL )	
	{
		cout << "그래프 객체 싱성 실패" << endl;
		return 0;
	}

	pGraph->ReadData();

	delete pGraph;
	pGraph = NULL;

	return 0;
}

