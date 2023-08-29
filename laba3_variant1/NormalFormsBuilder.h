#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


// Цей клас будує ДДНФ та ДКНФ
class NormalFormsBuilder {
private:

	std::vector<std::vector<int>> truthMatrix;
	std::vector<int> functionValues;
	std::string cdnf;
	std::string ccnf;

	// цей метод генерує дднф та дкнф
	void generateNormalForms();

public:

	NormalFormsBuilder(std::vector<std::vector<int>> _truthMatrix, std::vector<int> _functionValues);
	std::vector<std::vector<int>> getTruthMatrix();
	// у цьому методі також проводиться перевірка на тавтологію
	std::string getCDNF();
	// у цьому методі також проводиться перевірка на суперечність
	std::string getCCNF();
	// записує поля класу у файл
	void toFile(std::string filename);
};