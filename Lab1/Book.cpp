// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Book.h"
#include "Node.h"
#include <string>
#include <windows.h>
#include <iostream>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

List::List(int bookSize) {

	this->bookSize = bookSize;
	if (bookSize > 0) {
		this->rootBook = new Node<Book>;
		ZeroMemory(rootBook, sizeof(Node<Book>));
		Node<Book> *loop = rootBook;
		for (int i = 1; i < bookSize; i++) {
			loop->next = new Node<Book>;
			loop = loop->next;
			ZeroMemory(loop, sizeof(Node<Book>));
		}
		loop->next = NULL;
	}
	else
		std::cout << "Size of books list is not correct!";
}

List::~List() {
   Node<Book>* tempBook;
   Node<std::string>* tempTheme;
	while(rootBook != NULL) {
		tempBook = rootBook->next;
		while(rootBook->data.theme != NULL) {
			tempTheme = rootBook->data.theme->next;
			delete rootBook->data.theme;
			rootBook->data.theme = tempTheme;
		}
		delete rootBook;
		rootBook = tempBook;
    }
}

void List::fill() {
	this->fillBooks();
}

void List::print() {
	this->printBooks();
}

void List::fillBooks() {
	std::cout << "*****Fill list of books*****" << std::endl;
	Node<Book> *list = rootBook;
	while (list != NULL) {
		fillNode(list);
		list = list->next;
	}
	std::cout << std::endl << std::endl;
}

void List::fillNode(Node<Book> * node) {
	std::cout << "Enter ID: ";
	std::cin >> node->data.bookId;
	std::cout << "Enter Title: ";
	std::cin >> node->data.title;
	std::cout << "Enter Author: ";
	std::cin >> node->data.authorName;
	std::cout << "Enter Year: ";
	std::cin >> node->data.publishYear;
	std::cout << "Enter themes: ";
	fillThemes(node); //
}

void List::fillThemes(Node<Book>* node) {
	std::cout << "\t***Fill list of themes***" << std::endl << "\tType \stop to exit theme input" << std::endl;
	Node<std::string>* list = NULL;
	std::string themeName = "";
	while (true) {
		std::cout << "\tEnter theme name: ";
		std::cin >> themeName;

		if(themeName == "\\stop") {
			break;
		}
		else {
			if(list == NULL) {
				list = new Node<std::string>;
				node->data.theme = list;
			}
			else {
				list->next = new Node<std::string>;
				list = list->next;
			}
			list->data = themeName;
			list->next = NULL;
		}
	}
	std::cout << std::endl << std::endl;
}

void List::printBooks() {
	std::cout << "*****Print list of books*****" << std::endl;
	Node<Book> *list = rootBook;
	while (list != NULL) {
		std::cout << "ID: " << list->data.bookId << std::endl;
		std::cout << "Title: " << list->data.title << std::endl;
		std::cout << "Author: " << list->data.authorName << std::endl;
		std::cout << "Year: " << list->data.publishYear << std::endl;
		std::cout << "Themes: " << std::endl;
		printThemes(list->data.theme);
		std::cout << std::endl;
		list = list->next;
	}
	std::cout << std::endl << std::endl;
}

void List::printThemes(Node<std::string>* list) {
	while (list != NULL) {
		std::cout << "\t" << list->data << std::endl;
		list = list->next;
	}
	std::cout << std::endl << std::endl;
}

void List::push_back(Node<Book> * insertion) {
	Node<Book> *list = rootBook;
	while (list->next != NULL) {
		list = list->next;
	}
	list->next = insertion;
}

void List::swapRange(int index) {
	std::cout << "*****Swap range*****" << std::endl;
	if (index > 0) {
		Node<Book> *list = rootBook;
		Node<Book> *root = rootBook;
		Node<Book> *prev;
		for (int i = 0; i < index - 1; i++) {
			list = list->next;
		}
		prev = list;
		root = list->next;
		while (list->next != NULL) {
			list = list->next;
		}
		list->next = prev;
		while (list->next != root) {
			list = list->next;
		}
		list->next = NULL;

		rootBook = root;

	}
}

void List::deleteElement(std::string author, int year) {
	std::cout << "*****Deleting some units*****" << std::endl;
	Node<Book> *list = rootBook;
	Node<Book> *root = list;
	Node<Book> *prev = NULL;
	while (list != NULL) {
		if (list->data.authorName == author && list->data.publishYear > year) {
			if (root == list) {
				root = list->next;
				delete list;
			}
			else {
				prev->next = list->next;
				delete list;
				list = prev->next;
			}
		}
		else {
			prev = list;
			list = list->next;
		}
	}
}

Node<std::string> * List::findFirst(Node<std::string> * list,
	Node<std::string> * reg) {

	while (list != NULL) {
		if (list->data == reg->data)
			return list;
		else
			list = list->next;
	}
	return NULL;
}

Node<std::string> * List::createUniqList() {
	std::cout << "*****Creating unique list*****" << std::endl;
	Node<Book> *listBook = rootBook;
	Node<std::string>* templateTheme = NULL;
	Node<std::string>* templateRoot = NULL;

	while (listBook != NULL) {
		Node<std::string>* theme = listBook->data.theme;
		while(theme != NULL) {
			if(findFirst(templateRoot, theme) == NULL) {
				if(templateTheme == NULL) {
					templateTheme = new Node<std::string>;
					templateRoot = templateTheme;
				}
				else {
					templateTheme->next = new Node<std::string>;
					templateTheme = templateTheme->next;

				}
				templateTheme->next = NULL;
				templateTheme->data = theme->data;
			}
			theme = theme->next;
		}
		listBook = listBook->next;
	}
	return templateRoot;
}
