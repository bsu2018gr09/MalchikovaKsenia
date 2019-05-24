//Горизонтальный линейный градиент

#include "pch.h"
#include<iostream>
#include<fstream>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;
struct tmp { float r; float g; float b; } t; //tmp  для w


int main() {
    
    ifstream fff("/Users/ksusha/Documents/file1.bmp", ios::binary);
    ofstream ggg("/Users/ksusha/Documents/output.bmp", ios::binary);
    if (!fff) {cout <<"No file /Users/ksusha/Documents/file1.bmp"; exit(1);}
    if (!ggg) {cout <<"file /Users/ksusha/Documents/output.bmp. Can't create\n"; exit(1);}
    
    char buf[30];// куда читать байты
    unsigned char r, g, b;//компоненты цвета
    color c;
    unsigned int w, h;//надеемся. что тут 4 байта
    
    fff.read((char *)&buf, 18);   //чтение 18 байт заголовка bmp
    ggg.write((char *)&buf, 18);    //запись 18 байт заголовка bmp
    fff.read((char *)&w, 4); cout << "w=" << w;   //чтение width из заголовка bmp
    fff.read((char *)&w, 4); cout << ", h=" << w; //чтение height из заголовка bmp
    w = 512; ggg.write((char *)&w, 4);    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
    h = 256; ggg.write((char *)&h, 4);    //запись height в заголовок bmp
    fff.read((char *)&buf, 28);   //чтение 28 байт заголовка bmp
    ggg.write((char *)&buf, 28);    //запись 28 байт заголовка bmp
    
    c.r = 0; //первый цвет градиента
    c.g = 0;
    c.b = 0;
    
    float rr = 255; // второй цвет градиента
    float gg = 255;
    float bb = 255;
    float step = 100; // кол-во шагов
    if (step >= w)
        step = w;
    int newstep = w / step;
    if (step >= w)
        step = w;
    
    newstep = w / (step + 1);
    
    if (!newstep)
        newstep = 1;
    
    float step_r = (rr - c.r) / ((w / newstep) - 1);
    float step_g = (gg - c.g) / ((w / newstep) - 1);
    float step_b = (bb - c.b) / ((w / newstep) - 1);
    
    
    t.r = c.r;
    t.b = c.b;
    t.g = c.g;
    
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (((w - j) >= newstep) && ((j % newstep) == 0))
            {
                c.r += step_r;
                c.g += step_g;
                c.b += step_b;
            }
            c.r = (unsigned char)c.r;
            c.g = (unsigned char)c.g;
            c.b = (unsigned char)c.b;
            ggg.write((char *)&c, 3);
        }
        c.r = t.r;
        c.b = t.b;
        c.g = t.g;
        
    }
    
}
