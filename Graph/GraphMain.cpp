// Graph.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << "�׷��� ��ü �̼� ����" << endl;
		return 0;
	}

	pGraph->ReadData();

	delete pGraph;
	pGraph = NULL;

	return 0;
}

