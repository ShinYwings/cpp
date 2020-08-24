#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double epsilon = 0.000002;

double Improved_X_NormSquared(const vector<int> x){
  
    double maxElement = epsilon;
    double normSquared =0;
    int n = x.size();

    for( int i =0; i< n; i++){
        maxElement = max(maxElement, fabs(x[i]));
    }

    for ( int i=0; i<n; i++){
        double scaled = x[i] / maxElement;
        normSquared += scaled*scaled;
    }

    return sqrt(normSquared) * maxElement;
}

int main(){

    vector<int> x;

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);    

    double ans = Improved_X_NormSquared(x);

    return 0;
}