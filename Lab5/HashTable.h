// ---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
#include "NodeList.h"

// ---------------------------------------------------------------------------
template<typename KT, typename DT>
class HashTable {
private:
	NodeList<KT, DT> *root;
	int empty;
	int size;

	unsigned long hash(const KT key);
	void resize(int newsize);
	bool(*keyCompare)(const KT & a, const KT & b);
	static bool basic_keyCompare(const KT& a, const KT& b);
	char* (*keyToHash)(const KT & key);
	static char* basic_keyToHash(const KT& key);

public:
	HashTable(bool(*compareFunc)(const KT& a, const KT& b),
		char* (*keyToChar)(const KT& key)); // конструктор
	HashTable(); // конструктор
	~HashTable(); // деструктор

	void insert(const KT key, const DT& value); // операция вставки
	DT& find(const KT key); // операция поиска по ключу
	void remove(const KT key); // операция удаления по ключу
	void printIndexes(); // вывод ключей и хешей ключей всех элементов
};
#endif
