#include <iostream>

using namespace std;

//in C
typedef struct { int a,b;} pairs;


//in C++
class point{

    private: 
       double x, y;

    public:
        // double x, y;
        double getx() const { return x;}                // 문법 뒤에 const 붙여야 읽기 전용 함수!!
        double gety() const { return y;}
        void setx(double v){this->x = v;}
        void sety(double w){this->y = w;}
    
    
        point(double x, double y){ this->x= x;          // this: self referential pointer
                                    this->y= y;}

        point(){};

};

point operator+(point& p1, point& p2){
    point sum = { p1.getx()+ p2.getx(), p1.gety()+p2.gety()};
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.getx() << ", " << p.gety() << ")";
    return out;
}


int main()
{
    point a = {3.5, 2.5}, b = {2.5, 4.5}, c;

    cout << "a= " << a << "\tb= " << b << endl;

    cout << "sum = " << a+b << endl;

    return 0;

}