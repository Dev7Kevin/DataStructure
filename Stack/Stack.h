class CLinkedList;

class CStack
{
private:
	CLinkedList* m_pStackList;

	int		m_size, m_dataCount;

	bool IsEmpty	( );
	bool IsFull		( );

public:
	int	Pop			( );
	void Push		( int _data );

	void PrintSTack	( );

	CStack(int _size);
	~CStack();
};