//Класс точка в N-мерном пространстве. N задается как глобальная константа.

#include <iostream>
#include <cstring>

using namespace std;

const int n {4};

class Point {
private:
    double coord[n];
    
public:
    string name;
    
    Point(const Point &other)
    {
        for (int i = 0; i < n; ++i) coord[i] = other.coord[i];
        
    }
    
    Point() : coord{0}{};
    
    Point(double k)
    {
        for (int i = 0; i < n; ++i) coord[i] = k;
    };
    
    void Print()
    {
        cout << "(";
        for (int i = 0; i < n-1; ++i)
            cout << coord[i] << ",";
        cout << coord[n-1];
        cout << ")";
        cout << endl;
    };
    
    ~Point()
    {
        cout << "Destructor is working.";
    };
    
    const Point& operator = (const Point& point1)
    {
        for (int i = 0; i < n; ++i)
            coord[i] = point1.coord[i];
        return *this;
    };
    
    const Point operator + (const Point point1)
    {
        Point sum;
        for (int i = 0; i < n; ++i)
            sum.coord[i] = point1.coord[i] + coord[i];
        return (sum);
    };
    
    const Point operator - (const Point point1)
    {
        Point diff;
        for (int i = 0; i < n; ++i)
            diff.coord[i] = point1.coord[i] - coord[i];
        return (diff);
    };
    
    const Point operator * (const double num)
    {
        Point mlt;
        for (int i = 0; i < n; ++i)
            mlt.coord[i] = coord[i] * num;
        return (mlt);
    };
    
    friend ostream& operator << (ostream& os, Point& point1)
    {
        for (int i = 0; i < n-1; ++i)
            os << point1.coord[i] << ",";
        os << point1.coord[n-1];
        return os;
    }
    
    friend istream& operator >> (istream& is, Point& point1)
    {
        cout << "Enter coordinates of point: " << endl;
        for (int i = 0; i < n; ++i)
            is >> point1.coord[i];
        return is;
    }
    
    bool operator == (Point point1)
    {
        bool tmp;
        for (int i = 0; i < n; ++i)
        {
            if (point1.coord[i] == coord[i])
                tmp = true;
            else
            {
                return false;
            }
        }
        return true;
    }
};



int main() {
    
    Point* coord = new(nothrow) Point[n];
    if (!coord) {
        cout << "Memory could not allocate";
        exit(1);
    }
    
    //int a[n] = {1,2,3,4};
    
    Point point1(3);
    point1.name = "a";
    cout << point1.name <<" = ";
    point1.Print();
    
    //int b[n] = {6,-1,4,3};
    
    Point *point2;
    point2 = &point1;
    point2->name = "b";
    cout << point2->name <<" = "<<*point2;
    //point2->Print();
    
    Point point3[2]
    {
        Point(5),
        Point(6),
    };
    point3[0].name = "a1";
    cout << point3[0].name <<" = ";
    point3[0].Print();
    point3[1].name = "b1";
    cout << point3[1].name <<" = ";
    point3[1].Print();
    
    Point* point4 = new Point(3);
    point4->name = "a2";
    cout << point4->name << " = ";
    point4->Print();
    
    
    Point point6;
    point6 = point1 + *point2;
    cout << endl << "The sum of the coordinates of point1 and point2: ";
    point6.Print();
    
    Point point7;
    point7 = point1 - *point2;
    cout << endl << "The division of the coordinates of point1 and point2: ";
    point7.Print();
    
    Point point8;
    point8 = *point3;
    cout << "point8 = point3 = (";
    cout << point8 << ")" << endl;
    
    Point point9;
    point9 = point1 * 5;
    cout << endl << "The multiplication of the coordinates of point1 and 5: ";
    point9.Print();
    
    Point point10;
    cin >> point10;
    cout << "(" << point10 << ")" << endl;
    
    if (point8 == point7) cout << endl << "Point7 is equal point8" << endl;
    else cout << endl << "Point7 is not equal point8" << endl;
    
    delete point4;
    delete[] coord;
    coord = nullptr;
    
    return 0;
}

