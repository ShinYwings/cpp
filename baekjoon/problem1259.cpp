#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std;

int main(){

    string n;

    while(true){

        cin >> n;

        if(n == "0") break;

        int split = n.length()/2;

        if(n.length() %2 == 0){

            string left = n.substr(0, split);
            string right = n.substr(split, n.length());

            reverse(right.begin(), right.end());
            
            if( left == right ){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }

        }else{

            string left = n.substr(0, split);
            string right = n.substr(split+1, n.length());

            reverse(right.begin(), right.end());
            
            if( left == right ){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}