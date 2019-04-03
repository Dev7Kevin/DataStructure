class CUpNode;
class CLowNode;


class CGraphManager
{
private:
	CUpNode		*m_pUpStart, *m_pUpEnd;

public:
	CGraphManager();
	~CGraphManager();

	void		ReadData			( );
	CUpNode*	CreateUpNode		( int Data );
	void		CreateLowNode		( CUpNode* pUpParent, CUpNode* pUpMyNode );

	CUpNode*	SearchNode			( int Data );

	CLowNode*	GetLowEndNode		( CUpNode* pUpParentNode );

	void		PrintUpList			( CUpNode* pUpStartNode );
	void		PrintLowList		( CUpNode* pUpStartNode );
};