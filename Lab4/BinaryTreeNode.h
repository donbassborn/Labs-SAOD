//---------------------------------------------------------------------------

#ifndef BinaryTreeNodeH
#define BinaryTreeNodeH
//---------------------------------------------------------------------------
template <typename KT, typename DT> class BinaryTreeNode {
public:
	BinaryTreeNode<KT, DT>* left;
	BinaryTreeNode<KT, DT>* right;
	BinaryTreeNode<KT, DT>* parent;
	KT key;
	DT data;

	BinaryTreeNode(BinaryTreeNode<KT, DT>* parent);
	~BinaryTreeNode();
};
#endif
