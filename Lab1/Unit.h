//---------------------------------------------------------------------------

#ifndef UnitH
#define UnitH
#include <string>
struct ThemeUnit {
	ThemeUnit *next;
	std::string themeName;
};
struct BookUnit {
	BookUnit *next;
	ThemeUnit *theme;
	int bookId;
	std::string title;
	std::string authorName;
	int publishYear;
};
//---------------------------------------------------------------------------
#endif
