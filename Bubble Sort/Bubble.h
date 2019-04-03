class CBubble
{
private:
	int* m_pData;

public:

	CBubble();
	~CBubble();

	void		Swap	( int* a, int* b );
	void		Sort	( int* pData, int left, int right );

	void		Print	( );
};