//#include "Data.h"

class CIndexSort
{
private:
	Item*	m_pRecord;
	int*	m_pA;

public:
	CIndexSort();
	~CIndexSort();

	void Sort	( Item* pData, int* pA, int N );
	void Print	( );
};