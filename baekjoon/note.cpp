#include <iostream>
#include <stdio.h>

using namespace std;

int get_swing_result(){
	// ?
}

void count_function(int* ball_count, int* strike_count, int* out_count, int* first_base, int*second_base, int*third_base, int result, int* score){

}

void base_function(int* ball_count, int* strike_count, int* out_count, int* first_base, int*second_base, int*third_base, int result, int* score){
	
}

int start_inning(int inning, int* score_first, int* score_second, int* score_third, int* final_score)
{
	int ball_count, strike_count, out_count;
	int first_base, second_base, third_base;
	int score, choice, result;
	
	ball_count = 0, strike_count = 0, out_count = 0, first_base = 0, second_base = 0, third_base = 0, score = 0, choice = 0;
	
	while (out_count < 3)
	{
		printf("1. 스윙 2. 거르기\n");
		printf("입력: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			result = get_swing_result();
			count_function(&ball_count, &strike_count, &out_count, &first_base, &second_base, &third_base, result, &score);
			base_function(&ball_count, &strike_count, &out_count, &first_base, &second_base, &third_base, result, &score);
			print_score(inning, &score_first, &score_second, &score_third, score);
			print_count(&ball_count, &strike_count, &out_count);
			print_base(&first_base, &second_base, &third_base);
			break;

		case 2:
			system("cls");
			result = get_pass_result();
			count_function(&ball_count, &strike_count, &out_count, &first_base, &second_base, &third_base, result, &score);
			base_function(&ball_count, &strike_count, &out_count, &first_base, &second_base, &third_base, result, &score);
			print_score(inning, &score_first, &score_second, &score_third, score);
			print_count(&ball_count, &strike_count, &out_count);
			print_base(&first_base, &second_base, &third_base);
			break;
		}
	}

return score;

}

int main()
{
	int score_first = 0;
	int score_second = 0;
	int score_third = 0;
	int final_score = 0;

	start_inning(1, )

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