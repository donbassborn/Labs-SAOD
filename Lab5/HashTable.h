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
		char* (*keyToChar)(const KT& key)); // �����������
	HashTable(); // �����������
	~HashTable(); // ����������

	void insert(const KT key, const DT& value); // �������� �������
	DT& find(const KT key); // �������� ������ �� �����
	void remove(const KT key); // �������� �������� �� �����
	void printIndexes(); // ����� ������ � ����� ������ ���� ���������
};
#endif
