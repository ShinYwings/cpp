#include <cstdio>

//시간초과 뜸
// inline int Fibonachi(int n)
// {
//     if( n == 0 ) return 0;
//     if( n == 1 ) return 1;
//     return Fibonachi(n-1) + Fibonachi(n-2);
// }

//동적프로그래밍으로 짠 피보나치
inline void Fibonachi2(long n, long arr[])
{
    if ( arr[n-1] == -1 ){
        Fibonachi2(n-1, arr);
    }

    arr[n] = arr[n-1] + arr[n-2];
}

int main()
{
    long n;
    long arr[91];
    std::fill_n(arr,91,-1);

    arr[0] = 0;
    arr[1] = 1;

    scanf("%ld", &n);
    
    Fibonachi2(n, arr);

    printf("%ld\n", arr[n]);

    return 0;
}