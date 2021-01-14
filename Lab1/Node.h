//---------------------------------------------------------------------------

#ifndef NodeH
#define NodeH
#include <string>
//---------------------------------------------------------------------------

template <typename A> struct Node {
	Node<A>* next;
	A data;
};
struct Book {
	Node<std::string>* theme;
	int bookId;
	std::string title;
	std::string authorName;
	int publishYear;
};
#endif
