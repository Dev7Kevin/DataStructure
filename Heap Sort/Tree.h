// 노드 선언
class CNode
{
private:
	int		m_data;
	CNode   *m_pRight, *m_pLeft, *m_pParent;

public:
	CNode	() {};
	~CNode	() {};

	friend class CTree;
};



// 링크드 리스트 클래스 선언
class CTree
{
private:
	CNode	*m_pTreeRoot, *m_pCurrnent;

	int m_count;

public:
	CTree();
	~CTree() {};

	void	Add					( int _data );				
	void	TraverseAdd			( CNode* pCurrentNode, CNode* pNewNode );

	void	PrintTree			( );
	void	TraversePreorder	( CNode* pPrintNode );

	void	TraverseInorder		( CNode* pPrintNode );

	void	TraversePostorder	( CNode* pPrintNode );

	void	Delete				( int _searchData);
	void	TraverseDelete		( CNode* pDeleteNode, CNode* pParent ,int _searchData );
	void	TraverseUpRight		( CNode* pDeleteNode, CNode* pParent );

	void	DeleteTree			( );
	void	TraverseDeleteAll	( CNode* pDeleteAll );


	CNode*	GetRoot				( );
};