class CNode;

// 노드 선언
class CQNode
{
private:
	CNode*	m_pData;
	CQNode	*m_pNext, *m_pPre;

public:
	CQNode	() {};
	~CQNode	() {};

	friend class CLinkedList;
	friend class CQueue;
};



// 링크드 리스트 클래스 선언
class CLinkedList
{
private:
	CQNode *m_pHead, *m_pTail;

	int m_count;

public:
	CLinkedList();
	~CLinkedList() {};

	void	Add					( CNode* pAddNode );							

	void	DeleteList			( );									// 리스트의 노드를 모두 제거
	void	DeleteHead			( );


	void	PrintList			( );
									

	int		GetCount			( );
	int		GetLastData			( );

	CQNode*	GetHead				( );
	CQNode*	GetTail				( );
};