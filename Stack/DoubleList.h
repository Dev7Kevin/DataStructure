// ��� ����
class CNode
{
private:
	int		m_data;
	CNode  *m_pNext, *m_pPre;

public:
	CNode	() {};
	~CNode	() {};

	friend class CLinkedList;
};



// ��ũ�� ����Ʈ Ŭ���� ����
class CLinkedList
{
private:
	CNode* m_pHead;
	CNode* m_pTail;

	int m_count;

public:
	CLinkedList();
	~CLinkedList() {};

	void Add				( int _data );							
	void Insert				( int _targetIndex, int _insertData );	// Ư�� ��� ������ ��带 ����(����)

	void DeleteNode			( int _deleteIndex );					// Ư�� ��带 ����
	int	 DeleteNode			( );									// ������ ��带 ����
	void DeleteList			( );									// ����Ʈ�� ��带 ��� ����

	CNode* SearchNode		( int _search );

	void PrintList			( );
	void ReversePrintList	( );									

	int GetCount			( );
	int GetLastData			( );
};