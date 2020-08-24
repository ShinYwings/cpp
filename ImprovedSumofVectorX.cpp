#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
 
double Improved_X_Summation(const vector<int> x){
  
    int n = x.size();
    int sum = 0;
    for ( int i=0; i<n; i++){
        sum += x[i];
    }

    return sum;
}

int main(){

    vector<int> x;

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);    

    double ans = Improved_X_Summation(x);

    return 0;
}