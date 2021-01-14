// ---------------------------------------------------------------------------

#pragma hdrstop

#include "SimpleList.h"
#include <iostream>
// ---------------------------------------------------------------------------

SimpleList::SimpleList(int size) {
	root = new Node;
	root->next = NULL;
	Node* loop = root;
	for (int i = 0; i < size; ++i) {
		loop->next = new Node;
		loop = loop->next;
		loop->data = i + 1;
		loop->next = NULL;
	}

}

SimpleList::~SimpleList() {
	destroy(root);
}

void SimpleList::destroy(Node* list) {
	if (list->next != NULL)
		destroy(list->next);
	std::cout << "Deleting element with data: " << list->data << std::endl;
	delete list;
}
#pragma package(smart_init)
