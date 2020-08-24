#include <iostream> 
#include <vector>

using namespace std;


// 이분 탐색 문제
// 처음에 brute force로 풀었다가 시간초과 엄청남...........

long long ans;
vector<long long> lans;
int N, K;

void calc(long long minslice, long long maxslice){
      
    if( minslice > maxslice){
        return;
    }

    long long slice = (minslice + maxslice) / 2;

    long long result = 0;

    for(auto k=lans.begin(); k!=lans.end(); k++){

        result+= (*k)/slice;
    }

    if(result >= K){
        if(ans < slice) ans = slice;
        if(slice != maxslice -1)
            calc(slice, maxslice);
    }else{
        if(slice != minslice+1){
            calc(minslice, slice);
        }
    }    
}

int main(){

    cin >> N >> K;

    for(int i=0; i<N; i++){
        long long lan;
        cin >> lan;
        lans.push_back(lan);
    }

    long long sum=0;
    for(auto k=lans.begin(); k!=lans.end(); k++){

        sum+= *k;
    }

    long long avg = sum/K; // 평균부터 시작

    calc(1, avg+1);

    cout << ans;

    return 0;
}