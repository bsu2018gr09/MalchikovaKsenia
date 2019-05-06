// Определить длину первого и последнего слова в строке. Если длины совпадают, то заменить их заданной подстрокой, например ”**”..

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

char* createSTR(unsigned long n) {
    char* str = new (nothrow) char[n];
    if (!str) {
        cout << "Could not allocate memory";
        exit(EXIT_FAILURE);
    }
    return str;
}

void inputSTR(char* &str) {
    char buf[MAX];
    cin.getline(buf, MAX);
    str = createSTR(strlen(buf) + 1);
    strcpy(str, buf);
}

char* f(char* str) {
    char substr[] = "**";
    char signs[] = " ,.!?):;"; 
    
    unsigned long n = strlen(str);
    
    unsigned long lenF{0}, lenL{0};
    
    for (unsigned long i = 0; i < n; ++i) {
        for (unsigned long j = 0; j < strlen(signs); ++j) {
            if (str[i] == signs[j]) {
                lenF = i;
                break;
            }
        }
        if (lenF) break;
    }
    cout << lenF << " ";
    
    for (unsigned long i = 0; i < n; ++i) {
        for (unsigned long j = 0; j < strlen(signs); ++j) {
            if (str[n-1-i] == signs[j]) {
                lenL = i;
                break;
            }
            
        }
        if (lenL) break;
    }
    cout << lenL << " ";
    
    char* newstr = nullptr;
    
    if (lenF != 0 && lenF == lenL) {
        newstr = createSTR(n - lenF - lenL + strlen(substr) * 2);
        
        strcpy(newstr, substr);
        for (unsigned long i = lenF, j = strlen(newstr); i < n - lenL; ++i, ++j) {
            newstr[j] = str[i];
        }
        strcat(newstr, substr);
    } else {
        newstr = createSTR(n);
        
        strcpy(newstr, str);
    }
    
    return newstr;
}
                
                
int main() {
    
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
