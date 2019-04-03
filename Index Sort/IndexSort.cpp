#include "stdafx.h"
#include "Data.h"
#include "IndexSort.h"

using namespace std;

CIndexSort::CIndexSort()
{
}

CIndexSort::~CIndexSort()
{
}


void CIndexSort::Sort( Item* pData, int* pA, int N )
{
	m_pRecord	= pData;
	m_pA		= pA;

	int i, j, k;
	
	for ( i = 0; i < N; i++ )
	{
		Item v = m_pRecord[i];
		for ( k = i; m_pA[k] != i; k = m_pA[j], m_pA[j] = j)
		{
			j = k; m_pRecord[k] = m_pRecord[m_pA[k]];
		}

		m_pRecord[k] = v; m_pA[k] = k;
	}
}


void CIndexSort::Print()
{
	int p = 0;

	for ( p = 0; p < MAX_DATA; p++ )
	{
		cout << m_pRecord[p].m_Num << " ";
	}

	cout << endl;
}