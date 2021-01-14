#pragma hdrstop

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "Unit.h"
#include "Book.h"
#include "Func.h"
#include "Node.h"

#pragma argsused

int _tmain(int argc, _TCHAR* argv[]) {
	int command;
	int bookSize = -1;
	List* listHandle;
	BookUnit* _book;

	wchar_t type;
	std::cout <<
		"Choose type of implementation - [1] for functional, [2] for object-oriented:"<< std::endl;
	type = getwchar();
	getwchar();
	if(type != '1' && type != '2') {
		std::cout << "Error with type choosing! Programm will exit" << std::endl;
		system("pause");
		return 0;
	}
    system("cls");
	while (true) {
		std::cout << "Menu:" << std::endl <<
		"Type option index and press Enter"
		<< std::endl << std::endl;
		std::cout << "1: Create book list" << std::endl;
		std::cout << "2: Fill book list" << std::endl;
		std::cout << "3: Print book list" << std::endl;
		std::cout << "4: Push back in book list" << std::endl;
		std::cout << "5: Create new unique list from theme list" << std::endl;
		std::cout << "6: Remove elements from book list by author and year" <<
		std::endl;
		std::cout << "7: Swap range from index with start element" << std::endl;
		std::cout << "8: Exit programm" << std::endl;

		std::cin >> command;
		system("cls");
		if (type == '1') {

			switch(command) {
			case 1:
				std::cout << "Enter size of book list:";
				std::cin >> bookSize;
				if (bookSize > 0) {
					_book = createBookList(bookSize);
					std::cout << "List of books created!" << std::endl << std::endl;
				}
				else {
					std::cout <<
						"You entered negative value or zero size of list!" << std::endl << std::endl;
				}
				break;
			case 2:
				if (bookSize > -1) {
					fillList(_book);
					std::cout << "List of books filled with values!" <<
						std::endl << std::endl;
				}
				else
					std::cout << "List of books wasnt created!" << std::endl << std::endl;
				break;
			case 3:
				if (bookSize > -1) {
					printList(_book);
					std::cout << "List of books printed!" << std::endl << std::endl;
				}
				else
					std::cout << "List of books wasnt created!" << std::endl << std::endl;
				break;
			case 4:
				if (bookSize > -1) {
					BookUnit* newBook = new BookUnit;

					std::cout << "Enter values for new book:" << std::endl <<
						"Enter ID: ";
					std::cin >> newBook->bookId;
					std::cout << "Enter Title: ";
					std::cin >> newBook->title;
					std::cout << "Enter Author: ";
					std::cin >> newBook->authorName;
					std::cout << "Enter Year: ";
					std::cin >> newBook->publishYear;
					std::cout << "Enter themes: ";
					fillThemeList(newBook);

					pushBack(_book, newBook);
					std::cout << "List of books pushed back by new book!" <<
						std::endl << std::endl;
				}
				else
					std::cout << "List of books wasnt created!" << std::endl << std::endl;
				break;
			case 5:
				if (bookSize > -1) {
					ThemeUnit* uniq = createNewUniqList(_book);
					printList(uniq);
					std::cout << "List of themes was uniqualizated!" <<
						std::endl << std::endl;
					delete uniq;
				}
				else
					std::cout << "List of themes wasnt created!" << std::endl << std::endl;
			case 6:
				if (bookSize > -1) {
					int year;
					std::string author;

					std::cout << "Enter the author to delete:";
					std::cin >> author;
					std::cout << "Enter the year to delete:";
					std::cin >> year;

					deleteByAuthorAndYear(_book, author, year);
					std::cout << "List of books was changed!" << std::endl << std::endl;
				}
				else
					std::cout << "List of books wasnt created!" << std::endl << std::endl;
				break;
			case 7:
				if (bookSize > -1) {
					int index;

					std::cout << "Enter the swap index:";
					std::cin >> index;

					swapRange(_book, index);
					std::cout << "List of books was swapped!" << std::endl << std::endl;
				}
				else
					std::cout << "List of books wasnt created!" << std::endl << std::endl;
				break;
			case 8:
				return 0;
				break;
			default:
				std::cout << "Unknown command!" << std::endl << std::endl;

			}

		}
		else if (type == '2') {
			switch(command) {
			case 1:
				std::cout << "Enter size of book list:";
				std::cin >> bookSize;
				if (bookSize > 0) {
					listHandle = new List(bookSize);
					std::cout << "List created!" << std::endl << std::endl;
				}
				else {
					std::cout << "You entered negative value or zero size!" << std::endl << std::endl;
				}
				break;
			case 2:
				if (bookSize > -1) {
					listHandle->fill();
					std::cout << "List filled with values!" << std::endl << std::endl;
				}
				else
					std::cout << "List wasnt created!" << std::endl << std::endl;
				break;
			case 3:
				if (bookSize > -1) {
					listHandle->print();
					std::cout << "List printed!" << std::endl << std::endl;
				}
				else
					std::cout << "List wasnt created!" << std::endl << std::endl;
				break;
			case 4:
				if (bookSize > -1) {
					Node<Book> *newNode = new Node<Book>;
					listHandle->fillNode(newNode);
					newNode->next = NULL;
					listHandle->push_back(newNode);
					std::cout << "New element added to list!" << std::endl << std::endl;
				}
				else
					std::cout << "List wasnt created!" << std::endl << std::endl;
				break;
			case 5:
				if (bookSize > -1) {
					Node<std::string> *newList = listHandle->createUniqList();

					std::cout << "List of themes was uniqualizated!" <<
						std::endl << std::endl;
					listHandle->printThemes(newList);
					// delete newList;
				}
				else
					std::cout << "List wasnt created!" << std::endl << std::endl;
				break;
			case 6:
				if (bookSize > -1) {
					int year;
					std::string author;

					std::cout << "Enter the author to delete:";
					std::cin >> author;
					std::cout << "Enter the year to delete:";
					std::cin >> year;

					listHandle->deleteElement(author, year);
					std::cout << "List of books was changed!" << std::endl << std::endl;
				}
				else
					std::cout << "List wasnt created!" << std::endl;
			case 7:
				if (bookSize > -1) {
					int index;

					std::cout << "Enter the swap index:";
					std::cin >> index;

					listHandle->swapRange(index);
					std::cout << "List of books was swapped!" << std::endl << std::endl;
				}
				else
					std::cout << "List wasnt created!" << std::endl;
				break;
			case 8:
				return 0;
				break;
			default:
				std::cout << "Unknown command!" << std::endl << std::endl;

			}

		}
	}
	system("pause");
}
