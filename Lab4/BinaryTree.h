// ---------------------------------------------------------------------------

#ifndef BinaryTreeH
#define BinaryTreeH
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"

// ---------------------------------------------------------------------------
template<typename KT, typename DT>class BinaryTree {
private:
	BinaryTreeNode<KT, DT> *root;

	int drown(BinaryTreeNode<KT, DT> * node, int deep, bool tabulate);
	bool(*compare_more)(KT & _left, KT & _right);
	bool(*compare_less)(KT & _left, KT & _right);
	bool basic_compare_more(KT& _left, KT& _right);
	bool basic_compare_less(KT& _left, KT& _right);
	BinaryTreeNode<KT, DT> * copyNode(BinaryTreeNode<KT, DT> * node,
		BinaryTreeNode<KT, DT> * _root);

public:
	BinaryTree(BinaryTree<KT, DT>& cl);
	BinaryTree();
	BinaryTree(bool(*compare_less)(KT& _left, KT& _right),
		bool(*compare_more)(KT& _left, KT& _right));
	~BinaryTree();
	DT& operator[](KT key);
	void print();
	void orderedPrint();

};
#endif
