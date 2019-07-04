#pragma once
#include "CTree.h"

template<typename T>
class CBinaryTree:CTree<T>
{
	enum TreeOrder
	{
		BALANCE,
		DEFAULT,
		COMPLETE
	};
	using CTree<T>;
	template<typename T>
	struct CBTreeNode :TreeNode<T>
	{
	public:
		CBTreeNode(T value, CBTreeNode<T> *ptrLeftNode,CBTreeNode<T> *ptrRightNode)
		{
			info = value;
			_ptrLeftNode = ptrLeftNode;
			_ptrRightNode = ptrRightNode;

		}
	protected:
		CBTreeNode<T> *_ptrLeftNode;
		CBTreeNode<T> *_ptrRightNode;
	};
private:
	TreeOrder m_eOrder;
	CBTreeNode *m_rootNode;
public:
	typedef typename T value_type;
	void Insert(const value_type value);
	void SetOrder(TreeOrder eOrder);
	void delete(const value_type value);
private:
	void InsertNode(CBTreeNode<value_type>* node,TreeOrder eOrder);
	void DeleteNode(CBTreeNode<value_type> node);
};

template<typename T>
inline void CBinaryTree<T>::Insert(const value_type value)
{
	CBTreeNode<T> *node = new CBTreeNode<value_type>(value, NULL, NULL);
	InsertNode(node, m_eOrder);
}

template<typename T>
inline void CBinaryTree<T>::InsertNode(CBTreeNode<value_type> * node, TreeOrder eOrder)
{
	if (eOrder == DEFAULT)
	{
		if (m_rootNode == NULL)
		{
			m_rootNode = node;
		}
		else
		{
			CBTreeNode<value_type> *tempNode = m_rootNode;
			while (m_rootNode != NULL)
			{
				if()
			}
		}
	}
}
