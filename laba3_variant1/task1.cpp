//#include <iostream>
//#include <vector>
//#include <string>
//#include <fstream>
//#include "NormalFormsBuilder.h"
//#include "TruthMatrix.h"
//
//// вводяться значення функції для кожного рядка таблиці
//std::vector<int> inputFunctionValues(std::vector<std::vector<int>> truthMatrix) {
//	std::vector<int> functionValues;
//	for (int i = 0; i < truthMatrix.size(); ++i) {
//		for (int j = 0; j < truthMatrix[0].size(); ++j) {
//			std::cout << truthMatrix[i][j] << " ";
//		}
//		int value;
//
//		std::cout << "== ";
//		std::cin >> value;
//		functionValues.push_back(value);
//	}
//
//	return functionValues;
//}
//
//int main()
//{
//	int argumentsNumber;
//
//	std::cout << "Constructing the CDNF and CCNF from a given truth table\n\nEnter the number of function arguments (min - 2, max - 16) : ";
//	std::cin >> argumentsNumber;
//
//	if (2 <= argumentsNumber <= 16) {
//		std::cout << "\n\nEnter the value of the function for all values of the function arguments\n\n";
//
//		std::vector<std::vector<int>> truthMatrix = generateTruthMatrix(argumentsNumber);
//		std::vector<int> functionValues = inputFunctionValues(truthMatrix);
//
//
//		NormalFormsBuilder task(truthMatrix, functionValues);
//		std::cout << task.getCDNF() << "\n";
//		std::cout << task.getCCNF() << "\n";
//		task.toFile("output.txt");
//	}
//	else {
//		std::cout << "Number of function arguments is out of range: " << argumentsNumber << ".Should be from 2 to 16.";
//	}
//	return 0;
//}
