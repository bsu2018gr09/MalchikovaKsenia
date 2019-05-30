// Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include <iostream>

using namespace std;
void initArray(int *arr, int n, int min, int max)
{
    srand(time(0));
    max++;
    int tmp = max - min;
    for (int i = 0; i < n; i++,++arr)
    {
        *(arr) = rand() % tmp + min;
    }
}

void sort(int *array, int n) {
    int tmp;
    int* a1 = nullptr;
    int* a2 = nullptr;
    char f{1};
    char f_min{0};
    for (int i = 0; i < n; i++) {
        f_min = 0;
        a2 = array + n;
        a1 = array + n-1;
        f = 1;
        for (int j = n; j > -1; j--)
        {
            if ((!f_min) && (*a1 < 0))
            {
                a2 = a1;
                f_min = 1;
            }
            else if (((*a1 >= 0) && f_min) )
            {
                tmp = *a2;
                *a2 = *a1;
                *a1 = tmp;
                f_min = 0;
                f = 0;
            }
            
            a1--;
            
        }
        if (f)
            break;
    }
    int cnt{1};
    int *arr = array;
    while (*(arr+1) < 0)
    {
        if (*arr < *(arr + 1))
        {
            tmp = *arr;
            *arr = *(arr + 1);
            *(arr + 1) = tmp;
        }
        ++cnt;
        ++arr;
    }
    for (int i = 0; i < cnt ; i++)
    {
        f = 1;
        arr = array;
        for (int j = 0; j < cnt -1; j++)
        {
            if (*arr < *(arr + 1))
            {
                tmp = *arr;
                *arr = *(arr + 1);
                *(arr + 1) = tmp;
                f = 0;
            }
            ++arr;
        }
        if (f)
            break;
    }
    
}



void printArr(int*  arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << *(arr++) << "   ";
    }
    cout << '\n';
}

int *giveMemory( int n)
{
    int *a = new(nothrow) int[n];
    if (!a)
    {
        cout << "Couldn't allocate memory";
        exit;
    }
    return a;
}

void freeMemory(int *a)
{
    delete[] a;
    a = nullptr;
    
}


int main()
{
    int n;
    cin >> n;
    int *array = giveMemory(n);
    initArray(array, n, -5, 5);
    printArr(array, n);
    sort(array, n);
    printArr(array, n);
    freeMemory(array);
}
