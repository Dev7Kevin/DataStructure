class CLinkedList;
class CQNode;
class CNode;


class CQueue
{
private:
	CLinkedList*	m_pList;
	CQNode			*m_pTail,*m_pHead;
	int				m_size, m_count;

public:

	CQueue(int _size);
	~CQueue();

	void	Put			( CNode* pPutNode );
	CNode*	Get			( CNode* pGetNode );

	bool	IsEmpty		( );
	bool	IsFull		( );

	void	PrintQueue	( CNode* pRoot );
	void	Traverse	( CNode* pNode );
};