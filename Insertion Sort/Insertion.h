class CInsertion
{
private:
	int* m_pData;

public:

	CInsertion();
	~CInsertion();

	void		Swap	( int* a, int* b );
	void		Sort	( int* pData, int left, int right );

	void		Print	( );
};