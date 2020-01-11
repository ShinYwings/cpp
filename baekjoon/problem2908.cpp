#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    string A,B;

    cin >> A >> B;

    char temp;

    /*
    temp = A[0];

    A[0] = A[2];

    A[2] = temp;
    */
    reverse(A.begin(), A.end()); // 대체

    temp = B[0];

    B[0] = B[2];

    B[2] = temp;

    // string result = atoi(A.c_str()) >= atoi(B.c_str()) ? A : B; 
    string result = stoi(A) > stoi(B) ? A: B;   // stoi

    cout << result << endl;
}