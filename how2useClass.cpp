#include <iostream>

using namespace std;

/*
    new / delete

    class / constructor / destructor

    operator syntax

    의 설명이 포함되어 있음.
*/

//in C
typedef struct { int a,b;} pairs;


//in C++
class point{

    private: 
       double x;
       double y;
       point *ptr;

    public:
        // double x, y;
        double getx() const { return x;}                // 문법 뒤에 const 붙여야 읽기 전용 함수!!
        double gety() const { return y;}
        void setx(double v){this->x = v;}
        void sety(double w){this->y = w;}
    
    
        //old style: 대입해야 하기 때문에 const 멤버 변수 초기화를 못함
        point(double x, double y){ this->x= x;          // this: self referential pointer
                                    this->y= y;}

        //prefered style: 대입이 필요 없어서 const 멤버변수도 초기화 가능!
        point():x(0.0),y(0.0){}

        ~point(){
            cout << "destructor called" << endl; // 좋은 습관
            delete ptr;
        }

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