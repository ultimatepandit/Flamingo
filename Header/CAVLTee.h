#pragma once
#include "CBinaryTree.h"
#include <vector>
template<typename T>
class CAVLTree
{
	using CBinaryTree<T>;
	typedef typename T value_type;
	template<typename T>
	struct CAVLTreeNode : CBTreeNode<T>
	{
	public:
		CAVLTreeNode(T value) :info(value), _ptrLeftNode(NULL), _ptrRightNode(NULL)
		{

		}
	private:
		int m_Height;
	};
private:
	CAVLTree<value_type>* m_rootNode;

public:
	void Insert(value_type value);
	void  Delete(value_type value);
private:
	//rotation
	CAVLTreeNode<value_type>* DeleteNodeRec(CAVLTreeNode<value_type>* node, value_type value);
	void LRRotation(CAVLTreeNode<value_type>* node);
	void RLRotation(CAVLTreeNode<value_type>* node);
	void Rotation(CAVLTreeNode<value_type>* node);
	void InsertNode(CAVLTreeNode<value_type>* node);
	void InsertNodeRecuse(CAVLTreeNode<value_type>* node, CAVLTreeNode<value_type>* Rootnode);
	int getBalance(CAVLTreeNOde<value_type>* node);
	void updateHeight(vector<int> treaverseStatus);
};

template<typename T>
inline void CAVLTree<T>::Insert(value_type value)
{
	//how to check is value_type have comparator opertator overloaded if satisfies do further processing else return debug assertion
	CAVLTreeNode<value_type> *node = new CAVLTreeNode<value_type>(value);
	//InsertNode(node);
	InsertNodeRecuse(node, m_rootNode);
}

template<typename T>
inline bool CAVLTree<T>::Delete(value_type value)
{
	CAVLTreeNode<value_type> * tempNode = m_rootNode;
	DeleteNodeRec(value, tempNode);

}

template<typename T>
inline CAVLTree<T>::CAVLTreeNode<value_type>* CAVLTree<T>::DeleteNodeRec(CAVLTreeNode<value_type>* node, value_type value)
{
	NODESIDE eSIDE;
	if (node == NULL)
	{
		return node;
	}
	else
	{
		CAVLTreeNode<value_type>* returnNode = NULL;
		if (node->_info == value)
		{
			//case 1. if node is complete node
			if (node->_ptrLeftNode != NULL && node->_ptrRightNode != NULL)
			{
				//find succesor of node
				CAVLTreeNode<value_type>* succesorNode = this->Succesor(node);
				//swap value of succesor
				//1. use swap function to swap two object of type T
				swap(succesorNode->info, node->info);
				node->_ptrRightNode = DeleteNodeRec(node->_ptrRightNode, value);
			}
			//case 2. if node is not complete node
			//inherited from base class
			//terminating condition
			else
			{
				returnNode = this->DeleteNode(node);
				return returnNode;
			}

		}
		else
		{
			if (node->info > value)
			{
				node->_ptrLeftNode = DeleteNodeRec(node->_ptrLeftNode, value);
			}
			else
			{

				node->_ptrRightNode = DeleteNodeRec(node->_ptrRightNode, value);
			}
		}
		updateHeight(node);
			//check for height balance
			int nDiff = getBalance(node);
			if (nDiff = -2 || nDiff == 2)
			{
				return Roation(node);
			}
			else
			{
				return node;
			}
	}
}

template<typename T>
inline void CAVLTree<T>::LRRotation(CAVLTreeNode<value_type>* node)
{
}

template<typename T>
inline void CAVLTree<T>::RLRotation(CAVLTreeNode<value_type>* node)
{
}

template<typename T>
inline void CAVLTree<T>::Rotation(CAVLTreeNode<value_type>* node)
{
	
}

template<typename T>
inline void CAVLTree<T>::InsertNode(CAVLTreeNode<value_type>* node)
{
	vector<int> traverseStatuas;
	CAVLTreeNode<value_type>* rotateNode = NULL;

	if (m_rootNode == NULL)
	{
		m_rootNode = node;
	}
	else
	{
		CAVLTreeNode<value_type>* tempNode = m_rootNode;
		CAVLTreeNode<value_type>* reserveNode = tempNode;
		while (tempNode == NULL)
		{
			reserveNode = tempNode;
			int nDiff = getBalance(tempNode);

			if (tempNode->info >= node->info)
			{
				rotateNode = (nDiff == -1) ? NULL && traverseStatuas.clear() : (nDiff == 1 ? tempNode : rotateNode) && (traverseStatuas.push_back(0));
				tempNode = tempNode->_ptrLeftNode;
			}
			else
			{
				rotateNode = (nDiff == 1) ? NULL &&  traverseStatuas.clear() : (nDiff == -1 ? tempNode : rotateNode) && (traverseStatuas.push_back(0);
				tempNode = tempNode->_ptrRightNode;
			}
		}
		if (reserveNode->info > node->info)
		{
			reserveNode->_prtLeftNode = node;
			if (reserveNode->_ptrRightNode == NULL)
			{
				updateHeight(traverseStatuas)
			}
		}
		else
		{
			reserveNode->_ptrRightNode = node;
		}
		Rotation(rotateNode);
	}
}

template<typename T>
inline void CAVLTree<T>::InsertNodeRecuse(CAVLTreeNode<value_type>* node, CAVLTreeNode<value_type>* Rootnode)
{
	CAVLTreeNode<value_type>* tempNode = Rootnode;
	if (tempNode != NULL)
	{
		
	}
	else
	{
		if (tempNode->info > node->info)
		{	InsertNodeRecuse(tempNode->_ptrLeftNode); }
		else
		{	InsertNodeRecuse(tempNode->_ptrRightNode); }
	}
	//check for rotation required
	tempNode->m_Height = tempNode->_ptrLeftNode->m_Height > tempNode->_ptrRightNode->m_Height ? tempNode->_ptrLeftNode->m_Height + 1: tempNode->_ptrRightNode->m_Height + 1
		int nDiff = getBalance(tempNode);
	if (diff == -1)
		Rotation(tempNode);
}
template<typename T>
inline int CAVLTree<T>::getBalance(CAVLTreeNOde<value_type>* node)
{
	return node->_ptrLeftNode->m_Height - node->_ptrRightNode->m_Height;
}

template<typename T>
inline void CAVLTree<T>::updateHeight(vector<int> treaverseStatus)
{

}

