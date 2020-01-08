// n= 1 1                                                                                                   1
// n= 2 2        00                                                                                         11
// n= 3 3               100 001                                                                             111
// n= 4 5        0000   0011 1100 1001                                                                      1111
// n= 5 8               00100 00001 10000 11100 00111 10011 11001                                           11111
// n= 6 13       000000 000011 110000 001100 110011 111100 001111 100111 111001 001001 100100 100001        111111

#include <cstdio>
#include <iostream>

using std::fill_n;

int arr[1000001];

//동적프로그래밍으로 짠 피보나치
inline int Fibo(int n)
{
    if ( arr[n] != -1)
        return arr[n];

    if ( arr[n-1] == -1 ){
        Fibo(n-1);
    }
    
    arr[n] = (arr[n-1] + arr[n-2])%15746;

    return arr[n];
}

int main()
{
    int n;

    std::fill_n(arr,1000001,-1);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    scanf("%d", &n);

    printf("%d\n", Fibo(n));

    return 0;
}

// 어떻게 푼거지 ?????????? 주기까지 구한건가..???

// #include <cstdio>
// #define MOD 15746
// #define PERIOD 47244

// int main() {
// 	int n, memo[3] = {1, 1, 2};
// 	scanf("%d", &n);

// 	for (int i = 3; i <= n % PERIOD; ++i)
// 		memo[i % 3] = (memo[(i - 1) % 3] + memo[(i - 2) % 3]) % MOD;

// 	printf("%d\n", memo[n % 3]);
// 	return 0;
// }