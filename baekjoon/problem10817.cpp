#include <iostream>
#include <cstdlib>

using namespace std;



int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    int avg = ( A + B + C ) / 3;

    int Aabs = abs(A - avg);
    int Babs = abs(B - avg);
    int Cabs = abs(C - avg);

    int target = Aabs > Babs ? Babs : Aabs;
    target = target > Cabs ? Cabs : target;

    if ( target == Aabs) cout << A;
    else if ( target == Babs) cout << B;
    else if ( target == Cabs) cout << C;
}


/*
#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);
	printf("%d", a > b ? (c > a ? a : (c > b ? c : b)) : (c > b ? b : (a > c ? a : c)));

	return 0;
}
*/