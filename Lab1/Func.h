//---------------------------------------------------------------------------

#ifndef FuncH
#define FuncH
#include "Unit.h"
//---------------------------------------------------------------------------

BookUnit* createBookList(int n);  //

void printList(BookUnit* root);    //

void deleteByAuthorAndYear(BookUnit* list, std::string author, int year);

void swapRange(BookUnit*& list, int pos);

void fillList(BookUnit* list);   //

void fillThemeList(BookUnit* list);  //

void printList(ThemeUnit* root);  //

ThemeUnit* findFirst(ThemeUnit* list, ThemeUnit* reg);

ThemeUnit* createNewUniqList(BookUnit* list);

void pushBack(BookUnit* root, BookUnit* insertion);

void pushBack(BookUnit* root, BookUnit insertion);

#endif
