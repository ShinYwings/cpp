#include <iostream>

// cin, cout, endl은 printf scanf \n 보다 느리다. 그래서 프로그래밍 대회에서 아래 3개 함수를 통해 시간초과를 방지한다. 
//C++을 사용하고 있고 cin/cout을 사용하고자 한다면, 
//cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고, endl 대신 개행문자(\n)를 쓰자.
//단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

using namespace std;

int main()
{
    int A = 2;

    cout << A/2 << endl;

    return 0;
}