#include <iostream>

using namespace std;

int fastSum(int n){
    if ( n == 1) return 1;
    if (n%2 == 1) return fastSum(n-1) + n; // 홀수인 경우
    return 2*fastSum(n/2) + (n/2)*(n/2);
}

int main()
{
    int n;
    int sum = 0;

    cin >> n;
    
    sum = fastSum(n);

    cout << sum;
    
    return 0;
}

