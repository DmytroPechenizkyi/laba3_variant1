#include "TruthMatrix.h"

std::vector<std::vector<int>> generateTruthMatrix(int n) {
	int m = 1 << n;

	std::vector<std::vector<int>> truthMatrix;
	truthMatrix.resize(m, std::vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			truthMatrix[i][j] = (i >> j) & 1;
		}
	}

	return truthMatrix;
}
