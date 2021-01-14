//---------------------------------------------------------------------------

#ifndef ListStackH
#define ListStackH
#include "../Lab1/Node.h"
//---------------------------------------------------------------------------
template <class A> class ListStack {
	private:
		Node<A>* array;
		int stackSize;
		int* numberArray;
		int numberArrSize;
	public:
		void fillWithNumbers(int size);
		void printNumbers();
		void findNeighboor(int index);
		ListStack();
		~ListStack();
		int getStackSize();
		A pop();
		void push(A& node);
};
#endif

