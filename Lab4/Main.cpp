// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <math.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
// ---------------------------------------------------------------------------

#pragma argsused

bool comp_less(__int64& l, __int64& r) {
	return l < r;
}

bool comp_more(__int64& l, __int64& r) {
	return l > r;
}

int _tmain(int argc, _TCHAR* argv[]) {
	BinaryTree<__int64, std::string> *tree = new BinaryTree<__int64,
	std::string>(comp_less, comp_more);
	int command;
	bool r = true;
	std::string name;
	std::string assist;
	long phone;
	while (r) {
		std::cout << "Menu:" << std::endl <<
		"Type option index and press Enter"
		<< std::endl << std::endl;
		std::cout << "1: Add new entry" << std::endl;
		std::cout << "2: Print as tree" << std::endl;
		std::cout << "3: Print as ordered list" << std::endl;
		std::cout << "4: Find by phone" << std::endl;
		std::cout << "5: Exit programm" << std::endl;

		std::cin >> command;
		system("cls");
		switch(command) {
		case 1:

			std::cout << "Type name:";
			std::cin >> name;
			std::cout << "Type phone:";
			std::cin >> phone;
			if (tree->operator[](phone) != "" && tree->operator[](phone)
				!= name) {
				std::cout << "There is binded username for phone number " <<
					phone << ": " << tree->operator[](phone) <<
					". Do you want to update username for this phone number? [y/anything else]:";

				std::cin >> assist;
				if (assist == "y") {
					tree->operator[](phone) = name;
					std::cout << "Updated: " << phone << " = " << name <<
						std::endl;
				}
				else {
					std::cout << "Task skipped." << std::endl;
				}
			}
			else if (tree->operator[](phone) == name) {
				std::cout << "The binded username for phone number " <<
					phone << "is exactly typed by you: " << tree->operator[]
					(phone) << ". Task skipped." << std::endl;
			}
			else {
				tree->operator[](phone) = name;
				std::cout << std::endl << "New entry added!" << std::endl;
			}

			break;
		case 2:
			tree->print();
			break;
		case 3:
			tree->orderedPrint();
			break;
		case 4:
			std::cout << "Type phone:";
			std::cin >> phone;
			std::cout << std::endl << phone << " is " << tree->operator[]
				(phone) << std::endl;
			break;
		case 5:
			delete tree;
			r = false;
			break;

		}
		system("pause");
	}
	system("pause");
	return 0;
}
// ---------------------------------------------------------------------------
