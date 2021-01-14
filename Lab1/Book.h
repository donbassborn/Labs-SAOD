//---------------------------------------------------------------------------

#ifndef BookH
#define BookH
//---------------------------------------------------------------------------
#include "Node.h"
#include <string>
class List {
	Node<Book>* rootBook;
	int bookSize;
	public:
		List(int bookSize);
		~List();
		void fill();
		void fillNode(Node<Book>* node);
		void fillBooks();
		void fillThemes(Node<Book>* node);
		void print();
		void printBooks();
		void printThemes(Node<std::string>* node);
		void push_back(Node<Book>* insertion);
		void swapRange(int index);
		void deleteElement(std::string author, int year);
		Node<std::string>* findFirst(Node<std::string> * list, Node<std::string> * reg);
		Node<std::string>* createUniqList();
};
#endif
