#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int count = 0;

    getline(cin, str);

    string::iterator first_char = str.begin();
    string::iterator last_char = str.end()-1;

    for(string::iterator it {first_char}; it < last_char+1; it++){

        if(isspace(*it)) count++;

    }

    if (isspace(*last_char)) count--;
    if (isspace(*first_char)) count--;

    int result = count + 1;

    cout << result << endl;
}