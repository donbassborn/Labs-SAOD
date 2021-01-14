//---------------------------------------------------------------------------

#ifndef SimpleListH
#define SimpleListH
//---------------------------------------------------------------------------

struct Node {
	int data;
	Node* next;

};
class SimpleList {
	Node* root;
	void destroy(Node* list);
	public:
	SimpleList(int size);
	~SimpleList();


};
#endif
