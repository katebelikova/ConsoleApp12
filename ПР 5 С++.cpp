#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <windows.h> 

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;

    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int zeroCount = 0; 
    int sumInRange = 0; 

    int A, B;
    cout << "Введіть діапазон [A, B]:" << endl;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
            if (matrix[i][j] >= A && matrix[i][j] <= B) {
                sumInRange += matrix[i][j];
            }
        }
    }

    cout << "Кількість елементів рівних нулю: " << zeroCount << endl;
    cout << "Сума елементів в діапазоні від " << A << " до " << B << ": " << sumInRange << endl;

    vector<int> allElements;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            allElements.push_back(matrix[i][j]);
        }
    }

    sort(allElements.begin(), allElements.end(), [](int a, int b) {
        return abs(a) > abs(b); 
        });

    cout << "Елементи матриці, впорядковані за спаданням модулів:" << endl;
    for (int i = 0; i < allElements.size(); i++) {
        cout << allElements[i] << " ";
    }
    cout << endl;

    return 0;
}
