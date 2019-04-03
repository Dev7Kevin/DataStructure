#pragma once

class CLowNode;


// 상위 노드
class CUpNode
{
private:
	int			m_VertexData;
	CUpNode*	m_pNext;
	CLowNode*	m_pLow;

public:
	CUpNode() {};
	~CUpNode() {};

	friend class CGraphManager;
};


// 하위 노드
class CLowNode
{
private:
	CUpNode*	m_pUpMyNode;
	CLowNode*	m_pNext;

public:
	CLowNode() {};
	~CLowNode() {};

	friend class CGraphManager;
};