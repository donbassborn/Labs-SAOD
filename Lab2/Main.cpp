//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream>
#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "ListStack.h"
#include "ListStack.cpp"
#include <stack>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	ArrayStack<int> stack;
	std::cout << "TEST #1 DYNAMIC ARRAY STACK" << std::endl;
	std::cout << "Generate values and pushing to stack:" << std::endl;
	for(int i = 0; i < 10; ++i) {
		int e = rand()%128;
		stack.push(e);
		std::cout << "size: " << stack.getStackSize() << " allocated: " << stack.getStackMaxSize() << " value: " << e <<std::endl;
	}
	std::cout << "\nPop values from stack:" << std::endl;
	for(int i = 0; i < 10; ++i) {
		std::cout << "size: " << stack.getStackSize() << " allocated: " << stack.getStackMaxSize() << " value: ";
		std::cout << stack.pop() <<std::endl;
	}

	std::cout << "Testing the task:" << std::endl;
	std::cout << "Enter the size of int array: ";
	int arrSize;
	std::cin >> arrSize;
	std::cout << "Enter the values of array: ";
	stack.fillWithNumbers(arrSize);

	std::cout << "Enter the index of middle: ";
	int middleIndex;
	std::cin >> middleIndex;
	std::cout << "Printing the values of array:" << std::endl;
	stack.printNumbers();
	std::cout << std::endl;

	stack.findNeighboor(middleIndex);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ListStack<int> stackList;
	std::cout << "TEST #2 SINGLE DIRECTION LIST STACK" << std::endl;
	std::cout << "Generate values and pushing to stack:" << std::endl;
	for(int i = 0; i < 10; ++i) {
		int e = rand()%128;
		stackList.push(e);
		std::cout << "size: " << stackList.getStackSize() << " value: " << e <<std::endl;
	}
	std::cout << "\nPop values from stack:" << std::endl;
	for(int i = 0; i < 10; ++i) {
		std::cout << "size: " << stackList.getStackSize() << " value: ";
		std::cout << stackList.pop() <<std::endl;
	}

	std::cout << "Testing the task:" << std::endl;
	std::cout << "Enter the size of int array: ";
	std::cin >> arrSize;
	std::cout << "Enter the values of array: ";
	stackList.fillWithNumbers(arrSize);

	std::cout << "Enter the index of middle: ";
	std::cin >> middleIndex;
	std::cout << "Printing the values of array:" << std::endl;
	stackList.printNumbers();
	std::cout << std::endl;

	stackList.findNeighboor(middleIndex);


    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "TEST #3 STL STACK" << std::endl;
	std::cout << "Testing the task:" << std::endl;
	std::cout << "Enter the size of int array: ";
	std::cin >> arrSize;
	int* numberArray = new int[arrSize];
	std::cout << "Enter the values of array: ";
	for(int i = 0; i < arrSize; ++i) {
		int r;
		std::cin >> r;
		numberArray[i] = r;
	}
	std::cout << "Enter the index of middle: ";
	std::cin >> middleIndex;
	if(arrSize > 0 && middleIndex <= arrSize && middleIndex >= 0) {
		std::stack<int> left = std::stack<int>();
		std::stack<int> right = std::stack<int>();
		if(middleIndex > 0) {
			for(int i = middleIndex+1; i < arrSize; i++) right.push(numberArray[i]);
		}
		if(middleIndex < arrSize-1) {
			for(int i = middleIndex-1; i >= 0; i--) left.push(numberArray[i]);
		}
		int rightMin = INT_MAX;
		int leftMin = INT_MAX;
		if(right.size() > 0) {
			while(right.size()) {
				rightMin = std::min(rightMin, right.top());
				right.pop();
			}
			std::cout << "Minimum on the right size:" << rightMin << std::endl;
		}
		else {
			std::cout << "No elements on the right size" << std::endl;
		}
		if(left.size() > 0) {
			while(left.size()) {
				leftMin = std::min(leftMin, left.top());
				left.pop();
			}
			std::cout << "Minimum on the left size:" << leftMin << std::endl;
		}
        else {
			std::cout << "No elements on the left size" << std::endl;
		}
	}


	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
