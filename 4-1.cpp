//В тексте выбрать все слова-палиндромы и расположить в порядке возрастания их длин

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
#include <Windows.h>
using namespace std;

bool isPalindrome(const char* word)
{
    unsigned long i, j;
    unsigned long len = strlen(word);
    for (i = 0, j = len - 1; i < j; ++i, --j)
    {
        if (memcmp(word+i, word+j, 1))
        {
            return false;
        }
    }
    return true;
}

int searchWords(const char* path, char** arr)
{
    ifstream fin(path);
    
    if (!fin)
    {
        cout << "Can't open file " << path << "\n";
        exit(1);
    }
    
    int n{8192};
    char *buff = new (nothrow) char [n];
    
    if (!buff)
    {
        cout << "Could not allocate memory\n";
        exit(EXIT_FAILURE);
    }
    
    char *word;
    int cnt{0};
    
    while (1)
    {
        fin.getline(buff, n);
        if (fin.fail()) fin.clear();
        word = strtok(buff, " ,.!?–:;");
        while (word)
        {
            if (isPalindrome(word))
            {
                strcpy(*(arr+cnt), word);//я тестила на "Война и мир" и устанавливала размеры, используя данные оттуда, и соответственно ничего не вылетало
                cnt++;
            }
            word = strtok(NULL, " ,.!?");
        }
        if (fin.eof()) break;
    }
    
    fin.close();
    
    delete[] buff;
    delete[] word;
    
    return cnt;
}

void sortArr(char **arr, int cnt)
{
    bool flag;
    for (int i = 0; i < cnt; i++)
    {
        flag = true;
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (strlen(*(arr + j)) > strlen(*(arr + j + 1)))
            {
                flag = false;
                swap(*(arr + j), *(arr + j + 1));
            }
        }
        if (flag)
            break;
    }
}

void saveToFile(const char* path, char** arr, int cnt)
{
    ofstream fout(path);
    if (!fout)
    {
        cout << "Can't create file " << path << "\n";
        exit(1);
    }
    
    for (unsigned long i = 0; i < cnt; i++)
    {
        for (unsigned long j = 0; j < strlen(*(arr+i)); j++)
        {
            fout << *(*(arr+i)+j);
        }
        fout << "\n";
    }
    
    fout.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* ifpath = "/Users/ksusha/Documents/file.txt";
    const char* ofpath = "/Users/ksusha/Documents/result.txt";
    
    int m {1024};
    char **arr = new (nothrow) char* [m];
    
    if (!arr)
    {
        cout << "Could not allocate memory\n";
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < m; i++)
    {
        *(arr + i) = new (nothrow) char [m];// такого большого размера строки, т.к. не указано какого размера они могут быть
        
        if (!*(arr+i))
        {
            cout << "Could not allocate memory\n";
            exit(EXIT_FAILURE);
        }
    }
    
    int cnt = searchWords(ifpath, arr);
    
    if (cnt > 0)
    {
        sortArr(arr, cnt);
        
        saveToFile(ofpath, arr, cnt);
    } else
    {
        cout << "No palindromes found\n";
    }
    
    return 0;
}
