//---------------------------------------------------------------------------

#ifndef ArrayStackH
#define ArrayStackH
//---------------------------------------------------------------------------
template <typename A> class ArrayStack {
	private:
        A* array;
        int nodeSize;
		int stackSize;
		int* numberArray;
		int numberArrSize;
		int stackIndex;
	public:
		void fillWithNumbers(int size);
		void printNumbers();
		void findNeighboor(int index);
		ArrayStack();
		~ArrayStack();
		int getStackSize();
		int getStackMaxSize();
		A& pop();
		void push(A node);
};
#endif
