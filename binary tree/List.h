class CNode;

// ��� ����
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



// ��ũ�� ����Ʈ Ŭ���� ����
class CLinkedList
{
private:
	CQNode *m_pHead, *m_pTail;

	int m_count;

public:
	CLinkedList();
	~CLinkedList() {};

	void	Add					( CNode* pAddNode );							

	void	DeleteList			( );									// ����Ʈ�� ��带 ��� ����
	void	DeleteHead			( );


	void	PrintList			( );
									

	int		GetCount			( );
	int		GetLastData			( );

	CQNode*	GetHead				( );
	CQNode*	GetTail				( );
};