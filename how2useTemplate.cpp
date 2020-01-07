#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
const 위치에 따른 구문의 의미
https://blog.codingcat.kr/24
*/

template <class T> // T is generic type
T sum(const T data[], int size, T s=0)  
// any data sitting in that array is not mutable!
// data 변환 못시키게 함으로써 실수 방지하는 좋은 습관
// s will default to 0
{
    for( int i = 0; i < size; ++i)
    // 지금은 컴파일러가 알아서 바꿔주지만 예전에는
    // ++i는 i를 바로 증가시켜서 반환하지만
    // i++은 임시변수를 만들어서 i를 대입하고 i를 증가시키고 임시변수를 반환하는 형식이었어요.

        s += data[i]; // += must work for T

    return s;
}

// for exercise
template <class T2>
T2 sub(const T2 data[], int size, T2 s=0)
{ 
    for(int i = 0; i < size; ++i){
        s -= data[i];
        cout << "i is " << i << endl;
    }
    return s;
}

const int size = 92;

int main()
{
    int scores[size];
    
    srand((unsigned)time(0));
    
    for(int i=0; i<size; i++){
        scores[i] = (rand()%100)+1;
    }

    cout << sum(scores, size) <<endl; // no parameter with s, so s started at 0 by default value.

    cout << sum(scores, size, 58) <<endl; // 58 -> actual parameter would mean s started at 58.
    

    // exercise: 아래 문장을 substract로 바꾸기
    
    cout << endl << "예제" <<endl;

    cout << "template for sum()" << endl;
    int a[] = {1,2,3};
    double b[]= {2.1, 2.2, 2.3};
    cout << sum(a,3) << endl;
    cout << sum(b,3) << endl;

    // answer:

    cout << "template for sub()" << endl;
    int c[] = {1,2,3};
    double d[]= {2.1, 2.2, 2.3};
    cout << sub(c,3) << endl;
    cout << sub(d,3) << endl;

}