#include "CBinaryTree.h"
template<typename T>
class CRBTree
{
	//typedef typename U arg_type;
	typedef typename T value_type;
public:
	enum COLOR
	{
		eRED,
		eBLACK
	};
	template<typename value_type>
	class CRBTreeNode :CBTreeNode<value_type>
	{
	private:
		CRBTree<value_type>* m_CBTree;
	protected:
		using CBTreeNode<value_type>::info;
		using CBTreeNode<value_type>::_ptrLeftNode;
		using CBTreeNode<value_type>::_ptrRightNode;
	protected:
		COLOR m_eColor;
		CRBTreeNode<value_type>* _ptrParentNode;
	public:
		CRBTreeNode() :info(NULL)
		{

		}
		CRBTreeNode(value_type value) :info(value)
		{

		}

	};
private:
	CRBTreeNode<value_type>* sentinalNode;
public:
	CRBTree()
	{
		sentinalNode = new CRBTreeNode<value_type>();
		sentinalNode->_ptrLeftNode = sentinalNode;
		sentinalNode->_ptrLeftNode = sentinalNode;
		//creation of empty root node as sentinal node
	}
	template<typename value_type>
	CRBTree<value_type>(const CRBTree& obj)
	{

	}
	template<typename value_type>
	const CRBTree<value_type>& operator=(const CRBTree<value_type>& obj)
	{
		
	}
	//interface
public:
	void Insert(value_type value);
	void Delete(value_type value);
	void InsertNode(CRBTreeNode<value_type> * node, CRBTreeNode<value_type>* root);
	value_type& succesor(const value_type& value);
	value_type& predessor(const value_type& value);


};

template<typename T>
inline void CRBTree<T>::Insert(value_type value)
{
	CRBTreeNode<value_type> * node = new CRBTreeNode<value_type>(value);
	InsertNode(node,m_rootNode);
}

template<typename T>
inline void CRBTree<T>::Delete(value_type value)
{

}

template<typename T>
inline void CRBTree<T>::InsertNode(CRBTreeNode<value_type>* node, CRBTreeNode<value_type>* treeNode)
{
	while (treeNode != sentinalNode)
	{
		if (treeNode->info < node->info)
			InsertNode(node, treeNode->_ptrLeftNode);
		else
			InsertNode(node, treeNode->_ptrRightNode);
	}	
}



