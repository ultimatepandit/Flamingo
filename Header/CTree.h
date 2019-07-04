#pragma once
#include <stdlib.h>
template<typename T>
class CTree
{
	typedef typename T value_type;
	template<typename T>
	struct TreeNode
	{
	protected:
		TreeNode *childNode;
		value_type info;
		int nChildCount;
	public:
		TreeNode* child(int &childCount)
		{
		
		}
		TreeNode* parent()
		{
		
		}
		TreeNode* sibling(int &siblingCount)
		{
		
		}
		bool isAncestor(TreeNode* nodeOne, TreeNode* node2)
		{
		
		}
		TreeNode* CommonAncestor(TreeNode* nodeOne, TreeNode* node2)
		{
		
		}
		bool isDecendent(TreeNode* nodeOne, TreeNode* node2)
		{
		
		}
	};
	//private member
private:
	TreeNode<value_type>* SentinalNode;
	TreeNode<value_type>* rootNode;
	
public:
	//default constructor & operator
	CTree();
	~CTree();
	CTree(const CTree<value_type>& tree);
	CTree<value_type>& operator=(const CTree<value_type>& tree);
public:
	//interfaces
	void Insertion(value_type info);
	void Deletion(value_type info);
	void DepthTraversal(TreeNode<value_type>* node);
	void LevelOrderTraversal(TreeNode<value_type>* node);
	TreeNode<value_type>* root();
	bool isInternalNode(TreeNode<value_type>* node);
	bool isExternalNode(TreeNode<value_type>* node);
	int level(TreeNode<value_type>* node);
	int depth(TreeNode<value_type>* node);
	int height(TreeNode<value_type>* node);
	value_type NearestCommonAncesstor(TreeNode<value_type>* node);
	void ClearAndDestroy();

private:
	void InsertNode(TreeNode<value_type>* node);
};

template<typename T>
inline CTree<T>::CTree()
{
	SentinalNode = new TreeNode<value_type>();
	SentinalNode->childNode = NULL;
	SentinalNode->info = -9999;
	rootNode = SentinalNode;
}

template<typename T>
inline CTree<T>::~CTree()
{
	ClearAndDestroy();
}

template<typename T>
inline CTree<T>::CTree(const CTree<value_type>& tree)
{
}

template<typename T>
typename CTree<T>& CTree<T>::operator=(const CTree<value_type>& tree)
{
	// TODO: insert return statement here
}

template<typename T>
inline void CTree<T>::Insertion(value_type info)
{
	
}

template<typename T>
inline void CTree<T>::Deletion(value_type info)
{
}

template<typename T>
inline void CTree<T>::DepthTraversal(TreeNode<value_type>* node)
{
}

template<typename T>
inline void CTree<T>::LevelOrderTraversal(TreeNode<value_type>* node)
{

}
template<typename T>
typename  CTree<T>::TreeNode<value_type>* CTree<T>::root()
{
	return NULL;
}

template<typename T>
inline bool CTree<T>::isInternalNode(TreeNode<value_type>* node)
{
	return false;
}

template<typename T>
inline bool CTree<T>::isExternalNode(TreeNode<value_type>* node)
{
	return false;
}

template<typename T>
inline int CTree<T>::level(TreeNode<value_type>* node)
{
	return 0;
}

template<typename T>
inline int CTree<T>::depth(TreeNode<value_type>* node)
{
	return 0;
}

template<typename T>
inline int CTree<T>::height(TreeNode<value_type>* node)
{
	return 0;
}

template<typename T>
typename T& CTree<T>::NearestCommonAncesstor(TreeNode<value_type>* node)
{
	return value_type();
}

template<typename T>
inline void CTree<T>::ClearAndDestroy()
{
	
}

template<typename T>
inline void CTree<T>::InsertNode(TreeNode<value_type>* node)
{

	bool bChildFlag = rand() % 2 ? true : false;
	//adding new node to same node as a new child
	if (bChildFlag)
	{
		int nChildNum = rand() % node->nChildCount;
		node->child(nChildNum);
	}
	//adding new node by moving downword
	else
	{
		InsertNode
	}
}
