#include <iostream>

using namespace std;

int* newArray(int n) {
    int* pA = new (nothrow) int[n];
    if (!pA) cout << "Could not allocate memory" << '\n';
    return pA;
}

int* deleteA(int* pA) {
    delete[] pA;
    pA=nullptr;
    return pA;
}

void inputA(int *pA, int n)
{
    for (int* i = pA; i < pA+n ; i++) {
        cout << "Enter " << i-pA+1 << " number" <<endl;
        cin >> *i;
    }
    
    //второй вариант ввода
    /*for (int i = 0; i < n ; i++) {
       cout << "" << i+1 << "" << endl;
       cin >> *(pA+i);
    }*/
}

void initA (int* pA, int n) {
    for (int* i = pA; i < pA+n; i++) {
        *(i) = 1;
        cout << *(i) << " ";
    }
}

void printA (int *pA, int n) {
    for (int* i = pA; i < pA+n; i++) {
        cout << *i << " ";
    }
    cout << '\n';
}

void orderA(int* pA, int n) {
    int j = -1;
    for (int i = n-1; i >= 0; i--){
        if (*(pA+i) >= 0 && j == -1) continue;
        if (j == -1) {
            j = i;
            continue;
        }
        if (*(pA+i)<0) continue;
        for (int k = i; k<j; k++)
            swap(*(pA+k), *(pA+k+1));
        j = j-1;
    }
    j=-1;
    for (int i=0; i<n; i++) {
        if (*(pA+i) > 0) {
            j=i;
            break;
        }
    }
    if (j == -1) {
        j = n;
    }
    if (j != 0) {
        for (int i=0; i<j; i++){
            for (int k=0; k<j-i-1; k++){
                if (*(pA+i+1) > *(pA+i)) swap(*(pA+i+1), *(pA+i));
            }
        }
    }
    for (int i=0; i<n; i++)
        cout << *(pA+i) << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n" << '\n';
    cin >> n;
    int* pA = newArray(n);
    inputA(pA, n);
    printA(pA, n);
    orderA(pA, n);
    initA(pA, n);
    return 0;
}
