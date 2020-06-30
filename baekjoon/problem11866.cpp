#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N {}, K {};
    cin >> N >> K;

    int increNum {0};

    vector<int> sequence;

    for(int i {1}; i<=N; i++){
        sequence.push_back(i);
    }

    cout << "<" ; // Start

    while(!sequence.empty()){

        if(N == 1){
            int temp = sequence.at(0);
            cout << temp << ">"; // finish
            break;
        }

        increNum = ((increNum + K) % N ) -1;

        N--;

        if(increNum == -1) increNum = N;

        

        int temp = sequence.at(increNum);

        cout << temp << ", ";

        sequence.erase(sequence.begin()+increNum);

    }
    



    return 0;
}