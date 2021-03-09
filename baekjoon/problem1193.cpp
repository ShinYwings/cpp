#include <iostream>

using namespace std;

int main()
{
    int x;

    cin >> x;

    int row =1 , column =1, T = 1;

    while(T!=x){

        if( (row+column)%2 == 0 && row == 1){ //합이 짝이고 1행 일때
            column++;    //오른칸 이동
        }
        else if( (row+column)%2 == 0 && row != 1){ //합이 짝일때
            row--;
            column++;
        }else if( (row + column)%2 == 1 && column == 1){ // 합이 홀이고 1열 일때
            row++;
        }
        else if( (row + column)%2 == 1 && column != 1){ // 합이 홀이고 1열 일때
            row++;
            column--;
        }

        T++;
    }

    cout << row << "/" << column << endl;

    return 0;
}