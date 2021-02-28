#include <iostream>

using namespace std;

int main()
{
    // 첫번째: 변수에 const
    const int a1 = 100;
    int const b1 = 200;
    // int c1 const = 300; 안됨

    // a1=b1; 안됨
    // b1=a1; 안됨

    // (const int a1 = 100) == (int const a1 = 100)
    // 같은 의미!

    //===========================================

    // 두번째: 포인터에 const
    int val1 = 200, val2 = 300;
    int const *a2 = &val1;   // *a2 값 변경 불가
    int *const b2 = &val2;  // b2 값 변경 불가 ( 참조하는 대상 변경 불가)

    // *a2 = 400; *a2 값 변경 불가
    cout << "*a2 "<<*a2 << endl;
    cout << "a2 "<<a2 << endl;
    cout << "&a2 "<<&a2 << endl;
    
    *b2 = 400;

    int w = 999;

    a2 = &w;
    // b2 = &w;  b2값 변경 불가 (참조하는 대상 변경 불가)

    //============================================

    // 세번째: 레퍼런스에 const
    int val3 = 100;
    int val4 = 200;
    int const &a3 = val3;
    //int& const b3 = val3;  const qualifiers cannnot be applied to int&
    
    cout << "val3 " << val3 << endl;
    cout << "&val3 " << &val3 << endl;
    
    cout << "a3 " << a3 << endl;
    cout << "&a3 " << &a3 << endl;
    //cout << "*a3 " << *a3 << endl;
    //a3 = 300;  값 변경 불가
    //&a3 = val4; 참조하는 대상 변경 불가

    //============================================

    // 네번째: 함수에 const




}