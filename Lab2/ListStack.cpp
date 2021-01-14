//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListStack.h"
#include <windows.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include "../Lab1/Node.h"
//---------------------------------------------------------------------------

template <class A> ListStack<A>::ListStack() {
	this->stackSize = 0;
	this->array = NULL;
	this->numberArray = NULL;
	this->numberArrSize = 0;
}
template <class A> ListStack<A>::~ListStack() {
	if (array != NULL) {
		while(array != NULL) {
			Node<A>* tempLink = array->next;
			delete array;
			array = tempLink;
		}
    }
	if (this->numberArray != NULL) delete[] numberArray;
}
template <class A> void ListStack<A>::fillWithNumbers(int size) {
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
template <class A> void ListStack<A>::printNumbers() {
	for (int i = 0; i < numberArrSize; i++) std::cout << numberArray[i] << " ";
	std::cout << std::endl;
}
template <class A> void ListStack<A>::findNeighboor(int index) {
	if(numberArrSize > 0 && index <= numberArrSize && index >= 0 ) {
		ListStack<int> left = ListStack<int>();
		ListStack<int> right = ListStack<int>();
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
template <class A> int ListStack<A>::getStackSize() {
	return this->stackSize;
}
template <class A> A ListStack<A>::pop() {
	if (array != NULL) {
		A temp = array->data;
		Node<A>* tempLink = array->next;
		delete array;
		array = tempLink;
		stackSize--;
		return temp;
	}
	else {
		std::cout << "stackend" << std::endl;
		abort();
	}
}

template <class A> void ListStack<A>::push(A& node) {
	Node<A>* temp = new Node<A>;
	temp->data = node;
	temp->next = array;
	array = temp;
	stackSize++;
}
#pragma package(smart_init)

