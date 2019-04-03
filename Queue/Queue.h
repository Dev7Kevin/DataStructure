class CLinkedList;

class CQueue
{
private:
	CLinkedList*	m_pList;
	int				m_size;

public:

	CQueue(int _size);
	~CQueue();

	void	Put			( int _data );
	int		Get			( );

	void	PrintQueue	( );

	bool	IsEmpty		( );
	bool	IsFull		( );
};