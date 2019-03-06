#include <iostream>
using namespace std;

int** newArray(int rows, int cols) {
    int **arr = new int* [rows];
    for (int i=0; i<rows; i++)
        arr[i] = new int [cols];
    if (!arr) cout << "Could not allocate memory" << '\n';
    return arr;
}

void deleteA(int** arr, int rows) {
    for (int i=0; i<rows; i++){
        delete[] arr[i];
    }
    delete[] arr; 
    arr = nullptr;
}

void inputA(int **arr, int rows, int cols)
{
    for (int** i = arr; i < arr + rows ; i++) {
        for (int* j = *i; j < *i + cols; j++){
            cin >> *j;
        }
    }
}

void printA(int** arr, int rows, int cols) {
    for (int** i = arr; i < arr + rows; i++) {
        cout << '\n';
        for (int* j = *i; j < *i + cols; j++)
            cout << *j << " ";
    }
    cout << '\n';
}

void movieRows(int** arr, int rows, int cols){
    int max = **arr, min = **arr;
    long int max_row = 0, min_row = 0;
    int A;
    for (int** i = arr; i< arr + rows; i++){
        for (int* j = *i; j < *i + cols; j++){
            A = *j;
            if (A >= max) {
                max = A;
                max_row = i - arr;
            }
            else if (A <= min){
                min = A;
                min_row = i - arr;
            }
        }
    }
    
    for (int j = 0; j < cols ; j++){
        swap(*(*(arr+max_row)+j), *(*(arr+min_row)+j));
    }
}

int main() {
    
    int rows, cols;
    cout << "Enter the number of rows and columns" << '\n';
    cin >> rows >> cols;
    int** arr = newArray(rows, cols);
    inputA(arr, rows, cols);
    movieRows(arr, rows, cols);
    printA(arr, rows, cols);
    deleteA(arr, rows);
    return 0;
}

