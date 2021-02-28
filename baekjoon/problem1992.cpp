#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string twoD_Array(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);
bool area_is_white(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);
bool area_is_black(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);

int main()
{
    int high;
    int low = 0;
    string input;
 
    cin >> high;
    
    // 동적 할당
    // int *result = new int[4]; 
    
    // 2차원 배열 선언 방법 (1)
    // int **arr = new int*[size];
    // for(int i = 0; i< size; ++i)
    //     arr[i] = new int[size];

    // 2차원 배열 선언 방법 (2)
    // int arr[size][size];
    // int arrSize = sizeof(arr)/sizeof(arr[0][0]);
    // std::fill(arr[0], arr[0]+arrSize, -1);

    // 2차원 배열 선언 방법 (3) (강추!)
    vector<vector<int> > arr(high, vector<int>(high, -1));  // vector로 선언하면 2차원 배열 함수 매개변수로 사용 가능

    for(int i=0; i<high; ++i){

        cin >> input;

        for(int j=0; j<high; ++j){

            arr[i][j] = input[j] - '0';

        }
    }
    
    string result;

    result = twoD_Array(arr, low, high, low, high);

    cout<< result << endl;

    return 0;
}


bool area_is_white(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    for(int i=row_low; i<row_high; ++i){
        for(int j=column_low; j<column_high; ++j){
            if (arr[i][j] == 1) return false;
        }
    }
    return true;
}

bool area_is_black(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    for(int i=row_low; i<row_high; ++i){
        for(int j=column_low; j<column_high; ++j){
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

string twoD_Array(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    if (area_is_black(arr, row_low, row_high, column_low, column_high)){
        return "1";
    }
    if (area_is_white(arr, row_low, row_high, column_low, column_high)){
        return "0";
    }

    int row_mid = (row_high + row_low)/2;
    int column_mid = (column_high + column_low) /2;

    return "(" + twoD_Array(arr, row_low, row_mid, column_low, column_mid) + twoD_Array(arr, row_low, row_mid, column_mid, column_high) 
                + twoD_Array(arr, row_mid, row_high, column_low, column_mid)+ twoD_Array(arr, row_mid, row_high, column_mid, column_high) + ")";
        
}