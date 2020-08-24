#include <iostream>
#include <vector>

using namespace std;

// struct inform {
//     int startx;
//     int starty;
//     int sum;
// };

int main(){

    int x=0, y=0;
    cin >> x >> y ;
    vector<string> arr;

    for (int i=0; i<x; i++){
        string a = "";
        cin >> a;
        arr.push_back(a);
    }

    int result = (x*y+1)/2;   // 최대 경우의수 M*N / 2

    int sumA,sumB = 0;

    for (int i=0; i<x-7; i++){
        for(int j=0;j<y-7;j++){
            
            sumA=0 , sumB = 0; // 총 바뀐 갯수

            for(int m=0;m<8;m++){
                for(int n=0;n<8;n++){
                    if((m+n)%2 == 0)
                    {   
                        if(arr[m+i][n+j] == 'W')
                            sumB++;
                        else
                            sumA++;
                    }
                    else
                    {
                        if(arr[m+i][n+j] == 'B')
                            sumB++;
                        else
                            sumA++;
                    }
                }
            }
            if(result > sumA || result > sumB)
                result = sumA<sumB?sumA:sumB;
        }  
    }

    cout << result;

    return 0;
}

 ////////////////////////////////////////////BFS 실패/////////////////////
    // queue<pair<inform, vector<vector<bool>>>> q;

    // struct inform in;
    // in.startx=0;
    // in.starty=0;
    // in.sum=0;

    // int ans = 99999;

    // q.push({in, arr});

    // while(!q.empty()){

    //     int corX = q.front().first.startx;
    //     int corY = q.front().first.starty;
    //     int temp = q.front().first.sum;
    //     vector<vector<bool>> now = q.front().second;

    //     bool start;

    //     q.pop();

    //     if( temp < ans){
    //         ans = temp;
    //     }

    //     for(int n=0; n<2; n++){
    //         if(n == 0){
    //             start = true; // 0 is true

    //             for(int i=corX; i<corX+8; i++){
    //                 for(int j=corY; j<corY+8; j++){

    //                     if ( corX == i && corY == j){
    //                         if( now[corX][corY] == start){
    //                             continue;
    //                         }else{
    //                             now[corX][corY] = start;
    //                             temp++;
    //                         }
    //                     }else{
    //                         if(corX != i) {
    //                             if(now[i][j] == now[i-1][j]){
    //                                 now[i][j] = !now[i][j];
    //                                 temp++;
    //                             }   
    //                         }
    //                         if(corY != j){
    //                             if( now[i][j] == now[i][j-1]){
    //                                 now[i][j] = !now[i][j];
    //                                 temp++;
    //                             }
    //                         }
                            
    //                     }
    //                 }
    //             }

    //             struct inform s;
    //             s.startx = corX+1;
    //             s.starty = corY;
    //             s.sum = temp;

    //             q.push({s, now});

    //             s.startx = corX;
    //             s.starty = corY+1;

    //             q.push({s, now});
                
    //         }else{
    //             start = false;

    //             for(int i=corX; i<corX+8; i++){
    //                 for(int j=corY; j<corY+8; j++){

    //                     if ( corX == i && corY == j){
    //                         if( now[corX][corY] == start){
    //                             continue;
    //                         }else{
    //                             now[corX][corY] = start;
    //                             temp++;
    //                         }
    //                     }else{
    //                         if(corX != i) {
    //                             if(now[i][j] == now[i-1][j]){
    //                                 now[i][j] = !now[i][j];
    //                                 temp++;
    //                             }   
    //                         }
    //                         if(corY != j){
    //                             if( now[i][j] == now[i][j-1]){
    //                                 now[i][j] = !now[i][j];
    //                                 temp++;
    //                             }
    //                         }
                            
    //                     }
    //                 }
    //             }
    //             struct inform s;

    //             if( corX+1 < x-8){
    //                 s.startx = corX+1;
    //                 s.starty = corY;
    //                 s.sum = temp;

    //                 q.push({s, now});
    //             }
                
    //             if( corY+1 < y-8){
    //                 s.startx = corX;
    //                 s.starty = corY+1;

    //                 q.push({s, now});
    //             }
    //         }
    //     }//ROF
    // }

    // cout << ans;

    ///////////////////////////BFS 실패/////////////////////////////////
    
    //실패 이유 : 각 상황에 맞춰서 굳이 arr을 바꿀 필요가 없다. -> 메모리 낭비
