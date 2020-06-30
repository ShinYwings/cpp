#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

#define endl "\n"
#define fastIO() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastIO();
    int T = 0;  // 테스트 데이터 사이즈
    cin >> T;

    // string result[T][2];
    
    for(int j=0; j<T; j++){

        multiset<int> q; // 작은 순서대로     *** 이거 for문 밖에다 선언해서 여러번 틀림 *****
        int k = 0;  // 연산 횟수
        cin >> k;

        for(int i=0; i < k; i++){

            char oper {};
            int data = 0;

            cin >> oper >> data;

            if( oper == 'I'){
                q.insert(data);
            }
            else if( oper == 'D' && !q.empty() ){

                if( data == 1){
                    // 최대값 제거
                    q.erase(--q.end());
                }

                if( data == -1){
                    // 최소값 제거
                    q.erase(q.begin());
                }
            }
        }

        // if(q.empty()){
        //     result[j][0] = "";
        //     result[j][1] = "";
        // }else{
        //     string max = to_string(*--q.end());
        //     string min = to_string(*q.begin());
        //     result[j][0] = max;
        //     result[j][1] = min;
        // }
        if(q.empty()){
            cout << "EMPTY" << endl;
        }else{
            int max = *(--q.end());
            int min = *q.begin();

            cout << max << " " << min << endl;
        }
    }

    // for(int n=0; n<T; n++){

    //     if(result[n][0] == "" && result[n][1] == ""){
    //         cout << "EMPTY" << endl;
    //     }else{
    //         cout << stoi(result[n][0]) << " " << stoi(result[n][1]) << endl;
    //     }
    // }

    return 0;
}