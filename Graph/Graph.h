#pragma once

class CLowNode;


// ���� ���
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


// ���� ���
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