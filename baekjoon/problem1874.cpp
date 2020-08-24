#include <iostream> 
#include <vector> 
#include <stack>

using namespace std;

int main(){

    cin.sync_with_stdio(false);

    int n = 0;
    vector<int> ans;
    vector<char> result;
    stack<int> seq;
    cin >> n;

    for(int i=0;i<n; i++){
        int m =0;
        cin >> m;
        ans.push_back(m);
    }
    
    int cnt=0, now =0;

    while(true){

        if(now == n){
            break;
        }

        if(seq.empty()){
            seq.push(++cnt);
            result.push_back('+');
        }

        if(seq.top() > ans[now]){
            cout << "NO\n";
            return 0;
        }

        if(seq.top() != ans[now]){
            seq.push(++cnt);
            result.push_back('+');
        }else{
            result.push_back('-');
            seq.pop();
            now++;
        }

    }

    for(auto j = result.begin(); j!=result.end(); j++){
        cout << *j << "\n";
    }

    return 0;
}