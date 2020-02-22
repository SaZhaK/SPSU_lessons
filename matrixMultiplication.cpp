#include <iostream>

using namespace std;

int** createMatrix(int rows, int columns) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
    return matrix;
}

void setElements(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool checkSize(int matrix1Columns, int matrix2Rows) {
    if (matrix1Columns == matrix2Rows) return true;
    else return false;
}

int** multiplyMatrixes (int** matrix1, int matrix1Rows, int matrix1Columns,
                      int** matrix2, int matrix2Columns) {
    int** newMatrix = createMatrix(matrix1Rows, matrix2Columns);
    double curElement;

    for (int i = 0; i < matrix1Rows; ++i) {
        for (int j = 0; j < matrix2Columns; ++j) {
            for (int k = 0; k < matrix1Columns; ++k) {
                curElement += matrix1[i][k] * matrix2[k][j];
            }
            newMatrix[i][j] = curElement;
            curElement = 0;
        }
    }
    return newMatrix;
}

void printMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char* argv[]) {
    int matrix1Rows, matrix1Columns;
    int matrix2Rows, matrix2Columns;

    // Creation of first matrix
    cout << "Hello" << endl << "Please enter, size of first matrix:" << endl;
    do {
    cout << "Rows: ";
    cin >> matrix1Rows;
    cout << "Columns: ";
    cin >> matrix1Columns;
    } while (!(matrix1Rows > 0 && matrix1Columns> 0));
    int** matrix1 = createMatrix(matrix1Rows, matrix1Columns);
    cout << "Please, enter first matrix elements: " << endl;
    setElements(matrix1, matrix1Rows, matrix1Columns);

    // Creation of second matrix
    cout << "Please enter, size of second matrix:" << endl;
    do {
    cout << "Rows: ";
    cin >> matrix2Rows;
    cout << "Columns: ";
    cin >> matrix2Columns;
    } while (!(matrix2Rows > 0 && matrix2Columns> 0));
    int** matrix2 = createMatrix(matrix2Rows, matrix2Columns);
    cout << "Please, enter second matrix elements: " << endl;
    setElements(matrix2, matrix2Rows, matrix2Columns);

    // Checking if matrixes can be multiplied
    if(!checkSize(matrix1Columns, matrix2Rows)) {
        cout << "Sorry, incompatible sizes!" << endl;
        return 0;
    }

    int** resultMatrix = multiplyMatrixes(matrix1, matrix1Rows, matrix1Columns, matrix2, matrix2Columns);

    cout << "The result is:" << endl;
    printMatrix(resultMatrix, matrix1Rows,matrix2Columns );

    deleteMatrix(matrix1, matrix1Rows);
    deleteMatrix(matrix2, matrix2Rows);
    deleteMatrix(resultMatrix, matrix1Rows);

    return 0;
}
