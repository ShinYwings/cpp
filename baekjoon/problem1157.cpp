#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

/*
정렬 장점: 메모리 낭비 덜함
     단점: 느림

알파벳 배열 장점: 빠름
           단점: 안쓰는 배열공간 생김..

*/

using namespace std;

const int ALPHABET_NUM = 26;

int appearance[ALPHABET_NUM];


// void quick_sort(string &str, int start, int end){
//     if(start >= end){
//         return;
//     }

//     int pivot = start;
//     int i = pivot + 1;
//     int j = end;
//     char temp;

//     while( i <= j){

//         while(i <= end && str.at(i) <= str.at(pivot) ){
//             i++;
//         }

//         while(j > start && str.at(j) >= str.at(pivot) ){
//             j--;
//         }

//         if (i > j){
//             temp = str.at(j);
//             str.at(j) = str.at(pivot);
//             str.at(pivot) = temp;
//         }else{
//             temp = str.at(i);
//             str.at(i) = str.at(j);
//             str.at(j) = temp;
//         }
//     }

//     quick_sort(str, start, j-1);
//     quick_sort(str, j+1, end);
// }

// int main()
// {
//     string word;

//     cin >> word;

//     int size = word.size();

//     transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return toupper(c); });   // string lowercase 변환
   

//     // // sorting by order of alphabet 
//     quick_sort(word, 0, size-1);

//     // find max
//     int max= 1;
//     char max_char = word.at(0);

//     int temp=1;
//     char temp_char= word.at(0);
//     bool multiple_max_exists { false };

//     for(int i=1; i< size ; ++i){

//         if(temp_char == word.at(i)){
//             temp++;
//         }else{
//             temp = 1;
//             temp_char = word.at(i);
//         }

//         if( temp > max){
//                 max = temp;
//                 max_char = temp_char;
//                 multiple_max_exists = false;
//                 continue;

//         }

//         if ( max == temp )
//             multiple_max_exists = true;
//     }

//     char result = multiple_max_exists ? '?' : max_char;
    
//     cout << result << endl;

//     return 0;
// }


// count number of appearance for each alphabet
// a(0): appearance[0]
// z(25): appearance[25]

int main() {
    string S;
    cin >> S;
    
    int string_size {static_cast<int>(S.size())};
    string formated_string {S};
    
    // format string to lower case
    for (int i {0}; i < string_size; i++)
        formated_string.at(i) = tolower(S.at(i));
    
    // count appearance of each alphabet
    for (int i {0}; i < string_size; i++) {
        int index = static_cast<int>(formated_string.at(i)) - 97;
        appearance[index]++;
    }
    
    // print alphabet to uppercase that appeared the most
    // if there are multiple alphabets with the same max appearance print '?'
    int max {appearance[0]};
    int index {0};
    bool multiple_max_exists {false};
    
    for (int i {1}; i < ALPHABET_NUM; i++) {
        int appeared = appearance[i];
        
        if (appeared == 0) continue;
        
        if (max < appearance[i]) {
            max = appearance[i];
            index = i;
            multiple_max_exists = false;
            continue;
        }
        
        if (max == appearance[i])
            multiple_max_exists = true;
    }
    
    char result = multiple_max_exists ? '?' : index + 65;

    cout << result << endl;
    
    return 0;
}