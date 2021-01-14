// ---------------------------------------------------------------------------

#pragma hdrstop

#include "BinaryTree.h"
#include <deque>
#include <iostream>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

template<typename KT, typename DT>
bool BinaryTree<KT, DT>::basic_compare_less(KT& _left, KT& _right) {
	return _left < _right;
}

template<typename KT, typename DT>
bool BinaryTree<KT, DT>::basic_compare_more(KT& _left, KT& _right) {
	return _left > _right;
}

template<typename KT, typename DT>
BinaryTree<KT, DT>::BinaryTree(bool(*compare_less)(KT& _left, KT& _right),
	bool(*compare_more)(KT& _left, KT& _right)) {
	this->root = NULL;
	this->compare_less = compare_less;
	this->compare_more = compare_more;
}

template<typename KT, typename DT>
BinaryTree<KT, DT>::BinaryTree() {
	this->root = NULL;
	this->compare_less = basic_compare_less;
	this->compare_more = basic_compare_more;
}

template<typename KT, typename DT>
BinaryTree<KT, DT>::BinaryTree(BinaryTree<KT, DT>& cl) {
	this->compare_more = cl.basic_compare_more;
	this->compare_less = cl.basic_compare_less;
	this->root = copyNode(cl.root, NULL);
}

template<typename KT, typename DT>
BinaryTreeNode<KT, DT> * BinaryTree<KT,
DT>::copyNode(BinaryTreeNode<KT, DT> * node, BinaryTreeNode<KT, DT> * _root) {
	if (node != NULL) {
		BinaryTreeNode<KT, DT> *newNode = new BinaryTreeNode<KT, DT>(_root);
		if (node->left != NULL)
			copyNode(node->left, newNode);
		if (node->right != NULL)
			copyNode(node->right, newNode);
		newNode->data = node->data;
		newNode->key = node->key;
		return newNode;
	}
	else
		return NULL;
}

template<typename KT, typename DT>
BinaryTree<KT, DT>::~BinaryTree() {
	delete root;
}

template<typename KT, typename DT>
DT& BinaryTree<KT, DT>:: operator[](KT key) {
	if (root != NULL) {
		BinaryTreeNode<KT, DT> *loop = this->root;
		while (true) {
			if (compare_more(loop->key, key)) {
				// std::cout << "gonna right: " << loop->key << " > " << key << std::endl;
				if (loop->right != NULL)
					loop = loop->right;
				else {
					// std::cout << "make new" << std::endl;
					loop->right = new BinaryTreeNode<KT, DT>(loop);
					loop->right->key = key;
					return loop->right->data;
				}
			}
			else if (compare_less(loop->key, key)) {
				// std::cout << "gonna left: " << loop->key << " < " << key << std::endl;
				if (loop->left != NULL)
					loop = loop->left;
				else {
					// std::cout << "make new" << std::endl;
					loop->left = new BinaryTreeNode<KT, DT>(loop);
					loop->left->key = key;
					return loop->left->data;
				}
			}
			else {
				// std::cout << "gotcha: " << loop->key << " = " << key << std::endl;
				return loop->data;
			}
		}
	}
	else {
		root = new BinaryTreeNode<KT, DT>(NULL);
		root->key = key;
		return root->data;
	}

}

template<typename KT, typename DT>
int BinaryTree<KT, DT>::drown(BinaryTreeNode<KT, DT> * node, int deep,
	bool tabulate) {
	std::cout << ">" << std::endl;
	if (node->left != NULL)
		drown(node->left, deep + 1, tabulate);
	std::string tab = ">";
	for (int i = 0; deep > i; i++) {
		tab += "\t";
	}
	if (tabulate)
		std::cout << tab;
	std::cout << " " << node->key << "=" << node->data << std::endl;
	if (node->right != NULL)
		drown(node->right, deep + 1, tabulate);
	std::cout << ">" << std::endl;
}

template<typename KT, typename DT>
void BinaryTree<KT, DT>::print() {
	drown(root, 0, true);
}

template<typename KT, typename DT>
void BinaryTree<KT, DT>::orderedPrint() {
	drown(root, 0, false);
}
