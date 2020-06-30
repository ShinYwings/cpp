#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void max_heapify(int (&arr) [10], int index, int heap_size){
    
    int l= 2 * index + 1;
    int r= 2 * index + 2;

    int largest {index};

    if( l < heap_size && arr[l] > arr[largest] )
        largest = l;

    if( r < heap_size && arr[r] > arr[largest] )
        largest = r;
    
    if( largest != index ){
        swap(arr[index], arr[largest]);
        max_heapify(arr, largest, heap_size);     // 밑으로 내려감
    }
}

void build_max_heap(int (&arr) [10], int heap_size){

    int size = (heap_size/2) -1;

    for(int i = size; i>=0; i--)   // 자식노드 / 2 => 부모노드라서... 그 이상은 자식노드가 없음
        max_heapify(arr,i, heap_size); //위로 올라감
}

void heap_sort(int (&arr) [10]){

    int size = sizeof(arr)/sizeof(int);
    
    build_max_heap(arr, size);

    cout << "build heap : ";
        for(auto j = 0; j < 10; j++){
            cout << arr[j] << " " ;
        }
    cout << endl;

    for(int i = size-1; i>0; i--){

        swap(arr[0], arr[i]);

        max_heapify(arr, 0, i);

        cout << "unsorted array : ";
        for(auto j = 0; j < 10; j++){
                cout << arr[j] << " " ;
        }
        cout << endl;
    }
}

int main(){

    int data[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    cout << "unsorted array : ";
    for(auto i = 0; i < 10; i++){
            cout << data[i] << " " ;
    }
    cout << endl;

    heap_sort(data);
   
    cout << "sorted array : ";
    for(auto i = 0; i < 10; i++){
            cout << data[i] << " " ;
    }
    cout << endl;

    return 0;
}

