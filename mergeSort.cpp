#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right){
    
    vector<int> result;

    while( (left.size() > 0) || (right.size() > 0) ){

        if( left.size() > 0 && right.size() > 0){
            if( left.at(0) <= right.at(0) ){
                result.push_back(left.at(0));
                left.erase(left.begin());
            }else{
                result.push_back(right.at(0));
                right.erase(right.begin());
            }
        }else if( left.size() > 0 ){
            result.push_back(left.at(0));
            left.erase(left.begin());
        }else if( right.size() > 0 ){
             result.push_back(right.at(0));
                right.erase(right.begin());
        }
    }

    return result;
}

vector<int> merge_sort(vector<int> list){

    if (list.size() <= 1){
        return list;
    }

    int mid = list.size() / 2;
    vector<int> leftList(list.begin(), list.begin() + mid);
    vector<int> rightList(list.begin()+mid, list.end());
    leftList= merge_sort(leftList);
    rightList= merge_sort(rightList);
    return merge(leftList, rightList);
    
}

int main(){

    vector<int> mList;

    mList.push_back(14);
    mList.push_back(7);
    mList.push_back(3);
    mList.push_back(12);
    mList.push_back(9);
    mList.push_back(11);
    mList.push_back(6);
    mList.push_back(2);

    cout << "unsorted array : ";
    for(auto i = mList.begin(); i < mList.end() ; i++){
            cout << *i << " " ;
        }

    cout << endl;

    mList = merge_sort(mList);

    for(auto i = mList.begin(); i < mList.end() ; i++){
        cout << *i << " " ;
    }

    return 0;
}

