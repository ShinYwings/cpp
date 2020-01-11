#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    string OX;
    
    cin >> n;

    for( int i = 0; i<n; ++i){
        
        int score = 0;
        int tmp = 0;
        cin >> OX;

        for ( int j = 0; j<OX.size(); ++j){
            
            if( OX.at(j) == 'O'){
                tmp++;
                score += tmp;
            }

            if( OX.at(j) == 'X'){
                tmp = 0;
            }
        }

        cout << score << endl;

    }
}