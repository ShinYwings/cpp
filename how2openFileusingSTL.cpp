#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//in data.txt file
//  => 1111111

int main()
{
    ifstream data_file("data.txt");
    istream_iterator<char> start(data_file), end;
    vector<char> data(start, end);

    int wtf {0};

    // while ( data_file >> wtf){

    //     cout << wtf;
    // }

    for(auto it = data.begin(); it != data.end(); ++it ){

        wtf = *it;
        cout << wtf;

    }

    int dataa[4] = {1,2,3,4};

    cout << accumulate(dataa, dataa+4, 5);

    // int sum {0};
    // for ( auto &it : data){
    //     cout << &it << endl;
    //     sum += it;
    // }

    // cout << sum;

    return 0;
}