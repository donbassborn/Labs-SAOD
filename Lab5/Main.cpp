// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <string>
#include "HashTable.cpp"

// ---------------------------------------------------------------------------

#pragma argsused

int _tmain(int argc, _TCHAR* argv[]) {

	HashTable<unsigned int, std::string> *table = new HashTable<unsigned int,
	std::string>();
	int command;
	unsigned int specCode;
	std::string universityName;

	while (true) {
		std::cout << "Menu:" << std::endl <<
		"Type option index and press Enter"
		<< std::endl << std::endl;
		std::cout << "1: Add new entry" << std::endl;
		std::cout << "2: Find by key" << std::endl;
		std::cout << "3: Delete by key" << std::endl;
		std::cout << "4: Mass test" << std::endl;
		std::cout << "5: Print indexes" << std::endl;
		std::cout << "6: Exit programm" << std::endl;

		std::cin >> command;
		system("cls");
		switch(command) {
		case 1:

			std::cout << "Type code of specialization:";
			std::cin >> specCode;
			std::cout << "Type university name:";
			std::cin >> universityName;

			table->insert(specCode, universityName);
			std::cout << std::endl << "New entry added!" << std::endl;

			break;
		case 2:
			std::cout << "Type code of specialization:";
			std::cin >> specCode;

			try {
				std::cout << table->find(specCode) << std::endl;
			}
			catch(const std::range_error & ex) {
				std::cout << ex.what() << std::endl;
			}

			break;
		case 3:
			std::cout << "Type code of specialization:";
			std::cin >> specCode;

			try {
				table->remove(specCode);
			}
			catch(const std::range_error & ex) {
				std::cout << ex.what() << std::endl;
			}

			break;
		case 4:
			std::cout << "Table update with 64 new random values!" << std::endl;
			char buf[64];
			for (int i = 0; i < 64; i++) {
				itoa(i, buf, 10);
				table->insert(i, std::string("kekekeke").append(buf));
			}
			break;
		case 5:
			table->printIndexes();
			break;
		case 6:
			delete table;
			return 0;

		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
// ---------------------------------------------------------------------------
