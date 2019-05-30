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

void sortA(int* pA, int n){
    int m = 0;
    int* pB = newArray(n);
    for (int i=0; i < n; i++) {
        int k = *(pA+i);
        bool prime = true;
        if (k <= 1) {
            prime = false;
        } else {
            for (int j=2; j <= k/2; j++) {
                if (k%j == 0) {
                    prime = false;
                    break;
                }
            }
        }
        if (prime) {
            *(pB+m) = i;
            m++;
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<m-i-1; j++) {
          if (*(pA+*(pB+j+1)) < *(pA+*(pB+j))) swap(*(pA+*(pB+j+1)), *(pA+*(pB+j)));
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
    sortA(pA, n);
    deleteA(pA, n);//что это??? Зачем???
    return 0;//а где очистка памяти????
}
