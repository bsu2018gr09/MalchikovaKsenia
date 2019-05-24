// Определить длину первого и последнего слова в строке. Если длины совпадают, то заменить их заданной подстрокой, например ”**”..

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <clocale>
#include <Windows.h>
using namespace std;

const int MAX = 1000;

void delStr (char *s, int begin, int kol) //Удаляет из строки  s,  начиная с символа begin,  kol символов.
{
    char *dest = s + begin, *from = s + begin + kol;
    memmove(dest, from, s + strlen(s) + 1 - from);
}

void insStr (char* s, int begin, char* sub) //Вставить в строку s с адреса begin подстроку sub.
{
    strcat(sub, s + begin);
    strcpy(s + begin, sub);
}

void subStr (char *s, char *rez, int begin, int end) //Выделяет из строки s, начиная с символа begin, и заканчивая символом end
{
    int kol = end - begin;
    s = s + begin;
    strncpy(rez, s, kol);
    rez[kol] = '\0';
}

char* createSTR (unsigned long n)
{
    char* str = new (nothrow) char[n];
    if (!str)
    {
        cout << "Could not allocate memory";
        exit(EXIT_FAILURE);
    }
    return str;
}

void inputSTR (char* &str)
{
    char buf[MAX];
    cin.getline(buf, MAX);
    str = createSTR(strlen(buf) + 1);
    strcpy(str, buf);
}

char* f (char* str)
{
    char *subst=createSTR(3);
    strcpy(subst, "**");
    char signs[] = " ,.!?):;";
    int n = strlen(str);
    bool flag{ 0 };
    int lenFirst{ 0 }, lenLast{ 0 };
    int tmp;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < strlen(signs); ++j)
        {
            if ((str[i] == signs[j]) && flag)
            {
                lenFirst = i - tmp;
                break;
            }
            else if (isalpha(str[i])&&!flag)
            {
                flag = 1;
                tmp = i;
            }
        }
        if (lenFirst) break;
    }
    
    int infirstWord = tmp;
    cout << lenFirst << " ";
    
    int inLastWord{ 0 };
    flag = 0;
    
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < strlen(signs); ++j)
        {
            if ((str[i] == signs[j]) && flag)
            {
                lenLast = tmp - i;
                break;
            }
            else if (isalpha(str[i])&&!flag)
            {
                flag = 1;
                tmp = i;
            }
        }
        if (lenLast)
        {
            inLastWord = i; break;
        }
    }
    
    int lastword = strlen(str) - inLastWord;
    cout << lenLast << " ";
    
    char* newstr = nullptr;
    
    if (lenFirst != 0 && lenFirst == lenLast)
    {
        newstr = createSTR(n - lenFirst - lenLast + strlen(subst) * 2);
        newstr[0]='\0';
        
        char* sf= createSTR(1000);
        
        subStr(str, sf, 0, infirstWord);
        strcat(newstr,sf);
        strcat(newstr, subst);
        //insStr(newstr, infirstWord, subst);
        subStr(str, sf, infirstWord + lenFirst, inLastWord+1);
        strcat(newstr, sf);
        strcat(newstr, subst);
        subStr(str, sf, inLastWord+lenLast,strlen(str));
        strcat(str, sf);
    }
    else
    {
        newstr = createSTR(n);
        strcpy(newstr, str);
    }
    
    return newstr;
}


int main() {
    
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* str = nullptr;
    
    cout << "Enter text" << '\n';
    inputSTR(str);
    
    char* newstr = f(str);
    
    for (unsigned long i = 0; i < strlen(newstr); ++i) {
        cout << newstr[i];
    }
    
    delete[] str;
    str = nullptr;
    
    delete[] newstr;
    newstr = nullptr;
    
    return 0;
}
