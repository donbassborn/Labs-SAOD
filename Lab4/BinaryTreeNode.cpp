//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinaryTreeNode.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
template <typename KT, typename DT> BinaryTreeNode<KT, DT>::BinaryTreeNode(BinaryTreeNode<KT, DT>* parent) {
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
}
template <typename KT, typename DT> BinaryTreeNode<KT, DT>::~BinaryTreeNode() {
	if(this->left != NULL) delete this->left;
	if(this->right != NULL) delete this->right;
	//std::cout << this->key << std::endl;
}

