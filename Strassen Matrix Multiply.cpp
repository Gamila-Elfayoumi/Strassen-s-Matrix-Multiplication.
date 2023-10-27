#include <iostream>
#include<vector>
using namespace std;
//matrix addition
vector<vector<int>> matrix_add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	vector<vector<int>>result(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = A[i][j] + B[i][j];
		}
	}
	return result;
}
//matrix subtruction
vector<vector<int>>matrix_subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	vector<vector<int>>result(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = A[i][j] - B[i][j];
		}
	}
	return result;
}
//strassen matrix multiplication
vector<vector<int>>Strassen_matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	if (n == 1) {
		vector<vector<int>> result(1, vector<int>(1));
		result[0][0] = A[0][0] * B[0][0];
		return result;
	}
	int m = n / 2;
	vector<vector<int>>A11(m, vector<int>(m));
	vector<vector<int>>A12(m, vector<int>(m));
	vector<vector<int>>A21(m, vector<int>(m));
	vector<vector<int>>A22(m, vector<int>(m));
	vector<vector<int>>B11(m, vector<int>(m));
	vector<vector<int>>B12(m, vector<int>(m));
	vector<vector<int>>B21(m, vector<int>(m));
	vector<vector<int>>B22(m, vector<int>(m));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + m];
			A21[i][j] = A[i + m][j];
			A22[i][j] = A[i + m][j + m];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + m];
			B21[i][j] = B[i + m][j];
			B22[i][j] = B[i + m][j + m];
		}
	}
	vector<vector<int>> M1 = Strassen_matrix_multiply(matrix_add(A11, A22), matrix_add(B11, B22));
	vector<vector<int>> M2 = Strassen_matrix_multiply(matrix_subtract(B21, B11), A22);
	vector<vector<int>> M3 = Strassen_matrix_multiply(matrix_add(A11, A12), B22);
	vector<vector<int>> M4 = Strassen_matrix_multiply(matrix_subtract(A12, A22), matrix_add(B21, B22));
	vector<vector<int>> M5 = Strassen_matrix_multiply(A11, matrix_subtract(B12, B22));
	vector<vector<int>> M6 = Strassen_matrix_multiply(B11, matrix_add(A21, A22));
	vector<vector<int>> M7 = Strassen_matrix_multiply(matrix_subtract(A11, A21), matrix_add(B11, B12));

	vector<vector<int>> C11 = matrix_subtract(matrix_add(matrix_add(M1, M2), M4), M3);
	vector<vector<int>> C12 = matrix_add(M3, M5);
	vector<vector<int>> C21 = matrix_add(M2, M6);
	vector<vector<int>> C22 = matrix_subtract(matrix_subtract(matrix_add(M1, M5), M6), M7);

	vector<vector<int>>result(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = C11[i][j];
			result[i][j + m] = C12[i][j];
			result[i + m][j] = C21[i][j];
			result[i + m][j + m] = C22[i][j];
			return result;
		}
	}
}
//main function to print matrix
int main() {
	vector<vector<int>>A = { {1,3},{7,5} };//first matix 
	vector<vector<int>>B = { {6,8},{4,2} };//second matrix
	cout << "The first matrix is " << endl;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "The second matrix is" << endl;
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < B[i].size(); j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	vector<vector<int>>result = Strassen_matrix_multiply(A, B);
	cout << "The Result of the matrix multiplication" << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");	
}