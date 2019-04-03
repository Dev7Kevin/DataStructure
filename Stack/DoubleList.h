// 노드 선언
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



// 링크드 리스트 클래스 선언
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
	void Insert				( int _targetIndex, int _insertData );	// 특정 노드 다음에 노드를 삽입(수정)

	void DeleteNode			( int _deleteIndex );					// 특정 노드를 제거
	int	 DeleteNode			( );									// 마지막 노드를 제거
	void DeleteList			( );									// 리스트의 노드를 모두 제거

	CNode* SearchNode		( int _search );

	void PrintList			( );
	void ReversePrintList	( );									

	int GetCount			( );
	int GetLastData			( );
};