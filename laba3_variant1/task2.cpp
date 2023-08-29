#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "NormalFormsBuilder.h"
#include "TruthMatrix.h"

// додає строки з файлу у масив
std::vector<std::string> fromFile(std::string filename) {
	std::vector<std::string> lines;
	std::ifstream streamReader(filename);

	if (streamReader.is_open()) {
		std::string line;

		while (std::getline(streamReader, line)) {
			lines.push_back(line);
		}
		streamReader.close();
	}
	else {
		std::cout << "Unable to open the file.\n";
	}
	
	return lines;
}

int getArgumentsNumber(std::vector<std::string> lines) {
	return std::stoi(lines[0]);
}

// додає значення функції у масив
std::vector<int> valuesFromLine(std::vector<std::string> lines, char delimeter) {
	std::vector<int> functionValues;
	std::istringstream ss(lines[1]);
	std::string value;

	while (std::getline(ss, value, delimeter)) {
		functionValues.push_back(std::stoi(value));
	}

	return functionValues;
}



int main() {
	std::vector<std::string> lines = fromFile("output.txt");
	int argumentsNumber = getArgumentsNumber(lines);

	std::vector<std::vector<int>> truthMatrix = generateTruthMatrix(argumentsNumber);
	std::vector<int> functionValues = valuesFromLine(lines, ' ');
	
	NormalFormsBuilder task2(truthMatrix, functionValues);
	std::cout << task2.getCDNF() << "\n";
	std::cout << task2.getCCNF() << "\n";

	// Вертає 0, якщо строки рівні, -1 - якщо перша строка менша за другу та 1 - якщо друга менша за першу
	std::cout << "Comparing CDNF: " << task2.getCDNF().compare(lines[2]) << "\n";
	std::cout << "Comparing CCNF: " << task2.getCCNF().compare(lines[3]) << "\n";
}