#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string input;

    stack<char> s;

    cin >> input;

    string::iterator input_begin = input.begin();
    string::iterator input_end = input.end();
    
    for(string::iterator iter = input_begin; iter< input_end; ++iter){
        
        if ( *iter == '(' || *iter == ')')  continue;

        s.push(*iter);
    }

    int sum {0};
    int size = 1;
    int num = 0;
    int temp = 0;
    bool previous_plus = false;

    while(!s.empty()){

        char iter = s.top();
        s.pop();

        if( iter != '-' && iter != '+' ){
            
            int n = iter - '0';
            num += n * size;
            size *= 10; 
        
        }else{

            //연산
            if( iter == '+' ){
                temp += num;
                previous_plus = true;
            }

            if( iter == '-' ){

                if ( previous_plus ){
                    
                    if ( temp > 0 ){
                        temp += num;
                        sum -= temp;
                        
                        temp = 0;
                        previous_plus = false;
                    }else{
                        sum -= num;
                    }
                }else{
                    sum -= num;
                }
            }
            size = 1;
            num = 0;
        }
    }
    
    sum = sum + temp + num;

    std::cout << sum << endl;

    return 0;

}