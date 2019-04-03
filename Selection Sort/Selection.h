class CSelection
{
private:

	int* m_pData;

public:

	CSelection		();
	~CSelection		();

	void		Swap	( int* a, int* b );
	void		Sort	( int* pData, int left, int right );

	void		Print	( );
};