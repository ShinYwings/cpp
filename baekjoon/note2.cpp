#include <iostream>
#include <stdio.h>

using namespace std;



void func1(int* input){
	
    printf("in func1...\n");
    input++;
 
}

void func2(int* input){

    printf("in func2...\n");
    input--;

}

int inner_func()
{
    int input=0;
    int output =0;  
	
	while (input < 3)
	{
        int choice {};
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                func1(&input);
                printf("input++ and now %d\n", input);
                break;
            
            case 2:
                func2(&input);
                printf("input-- and now %d\n", input);
                break;
        }
        
	}
return output;
}

int main()
{
    int result {};

    result = inner_func();

    printf("result is %d\n", result);

    return 0;
}

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int d(int a){

// 	string num = to_string(a);
// 	int next = a;

// 	for(int i=0; i<num.size(); ++i){
// 		next += num.at(i) - '0';
// 	}
// 	return next;
// }

// int main()
// {
// 	int i =1;
// 	while(i <= 10000){

// 		d(i);
// 	}
//     return 0;
// }


/*
숏코딩

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	int n, x, num;
	char * arr = NULL;
	char inp[100000];
	char sp[] = " ";
	scanf("%d %d", &n, &x);
	getchar();
	gets(inp);
	arr = strtok(inp, sp);
	while (arr != NULL) {
		num = atoi(arr);
		if (num < x) {
			printf("%s ", arr);
		}
		arr = strtok(NULL, sp);
	}
	return 0;
}
*/