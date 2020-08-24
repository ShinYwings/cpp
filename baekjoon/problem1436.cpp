#include <iostream>
#include <cstring>

using namespace std;

//666 1666 2666 3666 4666 5666 6660 
//6661 6662 6663 6664 6665 6666 6667 
//6668 6669 7666 8666 9666 10666 
//11666 12666 13666 14666 15666 16660 16661 16662 ...이런 식으로 간다는거다.


//232ms
int main(){

    int count;

    cin >> count;

    int n = 665;

    while(count > 0){

        n++;

        string value = to_string(n); 

        if(value.find("666") != string::npos){
            
            count--;
        }
    }    
    
    cout << n;

 
    return 0;
}

// 0ms 시간
// #include <stdio.h>

// int main(void)
// {
// 	int N, title, count = 0, head = 0;
// 	scanf("%d", &N);
	
// 	while(count != N) {
// 		if (head % 10 == 6) {
// 			if (head % 100 == 66) {
// 				if (head % 1000 == 666) {		//_666___
// 					for (int i = count, j = 0; count != i + 1000; j++, count++) {
// 						if (count == N) break;
// 						title = head * 1000 + j;
// 					}
// 				}
// 				else {							//__66___
// 					for (int i = count, j = 0; count != i + 100; j++, count++) {
// 						if (count == N) break;
// 						title = head * 1000 + 600 + j;
// 					}
// 				}
// 			}									//___6___
// 			else {
// 				for (int i = count, j = 0; count != i + 10; j++, count++) {
// 					if (count == N) break;
// 					title = head * 1000 + 660 + j;
// 				}
// 			}
// 		}
// 		else {									//______
// 			title = head * 1000 + 666;
// 			count++;
// 		}
// 		head++;
// 	}
// 	printf("%d", title);
// }