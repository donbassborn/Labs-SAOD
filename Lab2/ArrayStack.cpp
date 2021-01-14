//---------------------------------------------------------------------------

#pragma hdrstop

#include "ArrayStack.h"
#include <windows.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define AS_STACK_SIZE 128
//---------------------------------------------------------------------------

template <typename A> ArrayStack<A>::ArrayStack() {
	this->stackIndex = 0;
	this->stackSize = 0;
	this->nodeSize = sizeof(A);
	this->array = NULL;
	this->numberArray = NULL;
	this->numberArrSize = 0;
}
template <typename A> ArrayStack<A>::~ArrayStack() {
	if (this->array != NULL) free(array);
	if (this->numberArray != NULL) delete[] numberArray;
}
template <typename A> void ArrayStack<A>::fillWithNumbers(int size) {
	if(size > 0) {
		if(numberArray != NULL) delete numberArray;
		numberArray = new int[size];
		numberArrSize = size;
		for (int i = 0; i < size; i++) std::cin >> numberArray[i];
	}
	else if(size == 0) {
		delete numberArray;
		numberArray = NULL;
		numberArrSize = 0;
	}
}
template <typename A> void ArrayStack<A>::printNumbers() {
	for (int i = 0; i < numberArrSize; i++) std::cout << numberArray[i] << " ";
	std::cout << std::endl;
}
template <typename A> void ArrayStack<A>::findNeighboor(int index) {
	if(numberArrSize > 0 && index <= numberArrSize && index >= 0 ) {
		ArrayStack<int> left = ArrayStack<int>();
		ArrayStack<int> right = ArrayStack<int>();
		if(index > 0) {
			for(int i = index+1; i < numberArrSize; i++) right.push(numberArray[i]);
		}
		if(index < numberArrSize-1) {
			for(int i = index-1; i >= 0; i--) left.push(numberArray[i]);
		}
		int rightMin = INT_MAX;
		int leftMin = INT_MAX;
		if(right.getStackSize() > 0) {
			while(right.getStackSize()) rightMin = std::min(rightMin, right.pop());
			std::cout << "Minimum on the right size:" << rightMin << std::endl;
		}
		else {
			std::cout << "No elements on the right size" << std::endl;
		}
		if(left.getStackSize() > 0) {
			while(left.getStackSize()) leftMin = std::min(leftMin, left.pop());
			std::cout << "Minimum on the left size:" << leftMin << std::endl;
		}
        else {
			std::cout << "No elements on the left size" << std::endl;
		}
    }
}
template <typename A> int ArrayStack<A>::getStackSize() {
	return this->stackIndex;
}
template <typename A> int ArrayStack<A>::getStackMaxSize() {
	return this->stackSize;
}
template <typename A> A& ArrayStack<A>::pop() {
	if (stackIndex > 0) {
		if(stackSize / stackIndex >= 2) {
			stackSize /= 2;
			array = (A*) realloc(array, nodeSize*stackSize);
		}
		stackIndex--;
		return array[stackIndex];

	}
	else {
		std::cout << "stackend" << std::endl;
		abort();
	}
}

template <typename A> void ArrayStack<A>::push(A node) {
	if(stackIndex < AS_STACK_SIZE) {
		if(stackIndex == stackSize) {
			if(stackSize == 0) stackSize++;
			else stackSize *= 2;
			array = (A*) realloc(array, nodeSize*stackSize);
		}
		array[stackIndex] = node;
		stackIndex++;
	}
	else {
		std::cout << "stackoverflow" << std::endl;
        //stackoverflow
    }
}
#pragma package(smart_init)
