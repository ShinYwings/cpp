#include <iostream>

using namespace std;

#define EOF -1

// EOF 뜻은 
// fgetc, getchar 함수가 파일의 끝에 도달하는 경우 반환
// End Of File 의 약자로써, 파일의 끝을 표현하기 위한 상수 (-1)
//콘솔의 경우, Ctrl-Z가 파일의 EOF를 의미

int main()
{

    int A,B;
    while(cin >> A >> B){      // EOF 인 경우 -1 반환후 while 탈출
        cout << A+B << endl;
    }

    return 0;
}