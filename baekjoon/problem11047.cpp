#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N {0};
    int money {0};

    vector<int> coin;

    cin >> N >> money;

    for(int i {0}; i<N; ++i){
        
        int input;

        cin >> input;

        coin.push_back(input);

    }

    sort(coin.begin(), coin.end(), greater<int>());

    int count {0};
    int total {0};
    int min {100000001};

    int i =0 ;
    
    while(money != 0){

        int temp = money/coin.at(i);

        if ( temp != 0 ){
            count += temp;
            money = money % coin.at(i);
        }
        i++;
    }

    cout << count << endl;

    return 0;


}