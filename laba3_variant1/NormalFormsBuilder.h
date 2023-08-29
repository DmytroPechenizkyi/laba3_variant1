#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


// ��� ���� ���� ���� �� ����
class NormalFormsBuilder {
private:

	std::vector<std::vector<int>> truthMatrix;
	std::vector<int> functionValues;
	std::string cdnf;
	std::string ccnf;

	// ��� ����� ������ ���� �� ����
	void generateNormalForms();

public:

	NormalFormsBuilder(std::vector<std::vector<int>> _truthMatrix, std::vector<int> _functionValues);
	std::vector<std::vector<int>> getTruthMatrix();
	// � ����� ����� ����� ����������� �������� �� ���������
	std::string getCDNF();
	// � ����� ����� ����� ����������� �������� �� �����������
	std::string getCCNF();
	// ������ ���� ����� � ����
	void toFile(std::string filename);
};