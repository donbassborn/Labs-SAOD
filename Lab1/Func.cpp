// ---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <windows.h>
#include "Func.h"
#include "Unit.h"

// ---------------------------------------------------------------------------
BookUnit* createBookList(int n) {
	if (n > 0) {
		BookUnit* root = new BookUnit;
		ZeroMemory(root, sizeof(BookUnit));
		BookUnit* loop = root;
		for (int i = 1; i < n; i++) {
			loop->next = new BookUnit;
			loop = loop->next;
			ZeroMemory(loop, sizeof(BookUnit));
			loop->theme = NULL;
		}
		loop->next = NULL;
		return root;
	}
	else
		return NULL;
}

void fillList(BookUnit* list) {
	std::cout << "*****Fill list*****" << std::endl;
	while (list != NULL) {
		std::cout << "Enter ID: ";
		std::cin >> list->bookId;
		std::cout << "Enter Title: ";
		std::cin >> list->title;
		std::cout << "Enter Author: ";
		std::cin >> list->authorName;
		std::cout << "Enter Year: ";
		std::cin >> list->publishYear;
		std::cout << "Enter themes: ";
		fillThemeList(list);
		list = list->next;
	}
	std::cout << std::endl << std::endl;
}

void printList(BookUnit* root) {
	std::cout << "*****Print list*****" << std::endl;
	while (root != NULL) {
		std::cout << "ID: " << root->bookId << std::endl;
		std::cout << "Title: " << root->title << std::endl;
		std::cout << "Author: " << root->authorName << std::endl;
		std::cout << "Year: " << root->publishYear << std::endl;
		std::cout << "Theme: " << root->theme->themeName << std::endl <<
			std::endl;
		root = root->next;
	}
	std::cout << std::endl << std::endl;
}

void fillThemeList(BookUnit* book) {
	std::cout << "\t***Fill list of themes***" << std::endl << "\tType \stop to exit theme input" << std::endl;
	ThemeUnit* list = NULL;
	std::string themeName = "";
	while (true) {
		std::cout << "\tEnter theme name: ";
		std::cin >> themeName;

		if(themeName == "\\stop") {
			break;
		}
		else {
			if(list == NULL) {
				list = new ThemeUnit;
				book->theme = list;
			}
			else {
				list->next = new ThemeUnit;
				list = list->next;
			}
			list->themeName = themeName;
			list->next = NULL;
		}
	}
	std::cout << std::endl << std::endl;
}

void printList(ThemeUnit* root) {
	std::cout << "*****Print theme list*****" << std::endl;
	while (root != NULL) {
		std::cout << "Theme name: " << root->themeName << std::endl;
		root = root->next;
	}
	std::cout << std::endl << std::endl;
}

void deleteByAuthorAndYear(BookUnit* list, std::string author, int year) {
	std::cout << "*****Deleting some units*****" << std::endl;
	BookUnit* root = list;
	BookUnit* prev = NULL;
	while (list != NULL) {
		if (list->authorName == author && list->publishYear > year) {
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

void swapRange(BookUnit*& list, int pos) {
	std::cout << "*****Swap range*****" << std::endl;
	if (pos > 0) {
		BookUnit* root = list;
		BookUnit* prev;
		for (int i = 0; i < pos - 1; i++) {
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

		list = root;
	}
}



ThemeUnit* findFirst(ThemeUnit* list, ThemeUnit* reg) {
	//std::cout << list->themeName << " "  << reg->themeName;
	while (list != NULL) {
		if (list->themeName == reg->themeName)
			return list;
		else
			list = list->next;
	}
	return NULL;
}

ThemeUnit* createNewUniqList(BookUnit* listBook) {
	std::cout << "*****Creating unique list*****" << std::endl;
	ThemeUnit* templateTheme = NULL;
	ThemeUnit* templateRoot = NULL;

	while (listBook != NULL) {
		ThemeUnit* theme = listBook->theme;
		while(theme != NULL) {
			if(findFirst(templateRoot, theme) == NULL) {
				if(templateTheme == NULL) {
					templateTheme = new ThemeUnit;
					templateRoot = templateTheme;
				}
				else {
					templateTheme->next = new ThemeUnit;
					templateTheme = templateTheme->next;

				}
				templateTheme->next = NULL;
				templateTheme->themeName = theme->themeName;
			}
			theme = theme->next;
		}
		listBook = listBook->next;
	}
	return templateRoot;
}

/*
void printList(ThemeUnit* root) {
while (root != NULL) {
std::cout << "Theme: " << root->themeName << std::endl << std::endl;
root = root->next;
}
}
 */

void pushBack(BookUnit* root, BookUnit* insertion) {
	while (root->next != NULL) {
		root = root->next;
	}
	root->next = insertion;
}

void pushBack(BookUnit* root, BookUnit insertion) {
	while (root->next != NULL) {
		root = root->next;
	}
	root->next = &insertion;
	root->next->next = NULL;
}

#pragma package(smart_init)
