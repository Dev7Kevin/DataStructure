// Index Sort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "IndexSort.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CIndexSort* pIndexSort = new CIndexSort();
	if ( pIndexSort == NULL )
	{
		cout << "인덱스 정렬 객체 생성 실패." << endl;
		return 0;
	}

	Item Data[MAX_DATA];
	int a[MAX_DATA] = { 0,  };
	int index = 0;

	srand((unsigned int)time( NULL ) );

	for ( index = 0; index < MAX_DATA; index++ )
	{
		Data[index].m_Num	= index;
		a[index]			= index;
	}

	strcpy( Data[0].m_pName, "asdf" );
	strcpy( Data[1].m_pName, "ducjq" );
	strcpy( Data[2].m_pName, "cuqkc" );
	strcpy( Data[3].m_pName, "zock" );
	strcpy( Data[4].m_pName, "vkqul" );

	pIndexSort->Sort( Data, a, MAX_DATA );
	pIndexSort->Print();


	if ( pIndexSort != NULL )
	{
		delete pIndexSort;
		pIndexSort = NULL;
	}

	return 0;
}

