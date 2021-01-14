// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream>
#include <string>
#include <windows.h>
#include "SimpleList.h"
// ---------------------------------------------------------------------------

#pragma argsused

float summarize(float* argum, int index, int count, int& depthSum) {
	if (count > 0) {
		depthSum++;
		return argum[index] + summarize(argum, index + 1, count - 1, depthSum);
	}
	else {

		return 0.0;
    }

}

float productize(float* argum, const int maxLength, int& depthSum, int& depthProd, int index = 0,
	int count = 1) {
	if (count < maxLength) {
        depthProd++;
		return summarize(argum, index, count, depthSum) * productize(argum, maxLength, depthSum, depthProd,
			index + count, count + 1);
	}
	else {

		return 1.0;
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	float* argum = new float[55];
	for (int i = 0; i < 55; i++) {
		argum[i] = (float)i + 1;
	}
	int sumD = 0;
	int prodD = 0;
	std::cout <<
		"Result of X1(X2+X3)(X4+X5+X6)....(X46+X47+...+X55), where Xn = n+1: "
		<< std::endl << productize(argum, 11, sumD, prodD) << std::endl;
	std::cout <<
		"Depth of summarize:" << sumD << std::endl;
		std::cout <<
		"Depth of production:" << prodD << std::endl<< std::endl<< std::endl;

	SimpleList* list = new SimpleList(10);
	delete list;


	system("pause");
	return 0;
}
// ---------------------------------------------------------------------------
