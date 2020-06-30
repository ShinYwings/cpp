#include <iostream>
#include <vector>

using namespace std;

void gapInsertionSort(vector<int> &alist, int start, int gap){

    
    for(int i = start+gap; i<alist.size(); i=i+gap){

        cout << "(i): "<< i << endl;
        int currentvalue = alist[i];
        int position = i;

        cout << "current value: " << currentvalue << endl;
        cout << "position: " << position << endl;
        while( (position >= gap) && (alist.at(position - gap) > currentvalue) ){
            alist.at(position) = alist.at(position-gap);
            position = position - gap;
        }

        alist.at(position) = currentvalue;
    }
}

void shellSort(vector<int> &alist){
    int sublistcount = alist.size() / 2;

    cout << "sublist count: " << sublistcount <<endl;
    while (sublistcount > 0){

        for (int startposition=0; startposition < sublistcount; startposition++){

            cout << "IN gapInsertionSort..." <<endl;
            gapInsertionSort(alist, startposition, sublistcount);
            cout << "OUT gapInsertionSort..." <<endl;
        }

        cout << "After increments of size " << sublistcount  << " The list is ";
        for(auto i = alist.begin(); i < alist.end() ; i++){
            cout << *i << " " ;
        }
        cout << endl;

        sublistcount = sublistcount / 2 ;

    }
}

int main(){

    vector<int> mList;

    mList.push_back(5);
    mList.push_back(9);
    mList.push_back(11);
    mList.push_back(1);
    mList.push_back(4);
    mList.push_back(7);

    cout << "unsorted array : ";
    for(auto i = mList.begin(); i < mList.end() ; i++){
            cout << *i << " " ;
        }

    cout << endl;

    shellSort(mList);

    for(auto i = mList.begin(); i < mList.end() ; i++){
        cout << *i << " " ;
    }

    return 0;
}

