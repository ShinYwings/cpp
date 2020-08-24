#include <iostream>

using namespace std;

int main(){

    int x=0, y=0, w=0, h=0;

    cin >> x >> y >> w >> h;

    int a = w-x>=x?x:w-x;
    int b = h-y>=y?y:h-y;

    int ans = a>=b? b:a;
    cout << ans << endl;

}