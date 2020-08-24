#include <iostream>
#include <queue>

using namespace std;

int main(){

    auto cmp = [](string &left, string &right) {
        
        // if (left.length() < right.length())
        //     return 0;
        if(left.length() == right.length()){
            for(int i=0;i<left.length();i++){
                    if(left.at(i)==right.at(i)) continue;
                    if(left.at(i)<right.at(i)) return 0;
                    if(left.at(i)>right.at(i)) return 1;
            }
        }
        return static_cast<int>(left.length() > right.length());
        // }else return 1;
    };

    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
   
    int n;
    cin >> n;
    string str ="";

    for(int i=0;i<n;i++){

        cin >> str;

        pq.push(str);
    }   

    string prev="";
    while(!pq.empty()){
        
        if(prev == pq.top()){
            pq.pop();
            continue;
        }else{
            cout << pq.top() << endl;
            prev = pq.top();
        }
        pq.pop();
    }

    return 0;
}

// pq 는 
// 구조체 + sort in algorithm package  + strcmp + 배열  조합
// 보다 50배 느림....