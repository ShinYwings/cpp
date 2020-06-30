#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int partition(int* arr, int start, int end){
    int x = arr[end];
    cout << "x is " << x << endl;
    int i = start -1;
    cout << "i is " << i << endl;

    for(int j=start; j<end; j++){
        if( arr[j] <= x ){
            i++;
            swap(arr[i], arr[j]);

            for(int k=0; k<7; k++){
                cout << arr[k] << " ";
            }
            cout <<endl;
        }
    }

    swap(arr[i+1],arr[end]);

    return i+1;
}

int* quick_sort(int* arr, int start, int end){

    if( start < end ){

        int pivot = partition(arr, start, end);
        cout << "pivot is " << pivot << endl;
        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}

int main(){
    
    int arr[7] = {5,3,7,6,2,1,4};

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    quick_sort(arr, 0, 6);

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
    
}