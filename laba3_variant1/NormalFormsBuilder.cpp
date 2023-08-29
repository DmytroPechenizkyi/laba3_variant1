#include "NormalFormsBuilder.h"

// Об'явлення полів та методів класу у cpp файлі

std::vector<std::vector<int>> truthMatrix;
std::vector<int> functionValues;
std::string cdnf;
std::string ccnf;

void NormalFormsBuilder::generateNormalForms() {
	for (int i = 0; i < truthMatrix.size(); ++i) {
		if (functionValues[i] == 1) {

			(cdnf.length() == 0) ? cdnf += "" : cdnf += "||";

			cdnf += "(";
			for (int j = 0; j < truthMatrix[0].size(); ++j) {

				(j == 0) ? cdnf += "" : cdnf += "&&";

				if (truthMatrix[i][j] == 0) {
					cdnf += "!bit[" + std::to_string(j) + "]";
				}

				else {
					cdnf += "bit[" + std::to_string(j) + "]";
				}
			}
			cdnf += ")";
		}
		else {

			(ccnf.length() == 0) ? ccnf += "" : ccnf += "&&";

			ccnf += "(";
			for (int j = 0; j < truthMatrix[0].size(); ++j) {

				(j == 0) ? ccnf += "" : ccnf += "||";

				if (truthMatrix[i][j] == 0) {
					ccnf += "bit[" + std::to_string(j) + "]";
				}

				else {
					ccnf += "!bit[" + std::to_string(j) + "]";
				}
			}
			ccnf += ")";
		}
	}
}


NormalFormsBuilder::NormalFormsBuilder(std::vector<std::vector<int>> _truthMatrix, std::vector<int> _functionValues) {
	truthMatrix = _truthMatrix;
	functionValues = _functionValues;
	generateNormalForms();
}

std::vector<std::vector<int>> NormalFormsBuilder::getTruthMatrix() {
	return truthMatrix;
}

std::string NormalFormsBuilder::getCDNF() {
	if (cdnf.length() == 0) {
		cdnf += "0";
	}

	return "CDNF: " + cdnf;
}

std::string NormalFormsBuilder::getCCNF() {
	if (ccnf.length() == 0) {
		ccnf += "1";
	}
	return "CCNF: " + ccnf;
}

void NormalFormsBuilder::toFile(std::string filename) {
	std::ofstream streamWriter(filename);

	if (streamWriter.is_open()) {
		streamWriter << truthMatrix[0].size() << "\n";
		for (int value : functionValues) {
			streamWriter << value << " ";
		}
		streamWriter << "\n";
		streamWriter << "CDNF: " << cdnf << "\n";
		streamWriter << "CCNF: " << ccnf << "\n";

		streamWriter.close();
		std::cout << "Data has been written to file '" << filename << "'.\n";
	}
	else {
		std::cout << "Unable to open the file.\n";
	}

}
