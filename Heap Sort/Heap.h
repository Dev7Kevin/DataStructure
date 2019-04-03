class CHeap
{
private:
	int m_Data[DATA_MAX];
	int m_Size;
	int m_Current;

public:
	CHeap(int Size);
	~CHeap();

	void GoUp		( int Index );
	void GoDown		( int* pData, int k, int n );
	void Swap		( int* a, int* b );

	void Insert		( int Value );
	int	 Delete		( );

	void Print		( );
};