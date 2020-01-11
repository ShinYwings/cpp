#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class quadNode {
    private:
            int data;
            quadNode* topLeft;
            quadNode* topRight;
            quadNode* bottomLeft;
            quadNode* bottomRight;
    
    public:
            quadNode(int val = 0, quadNode* tl = NULL, quadNode* tr  = NULL, quadNode* bl  = NULL, quadNode* br  = NULL) :
                data(val), topLeft(tl), topRight(tr), bottomLeft(bl), bottomRight(br) {} 
            void setData(int val) { data = val; }
            void setTopLeft(quadNode* tl) { topLeft = tl; }
            void setTopRight(quadNode* tr) { topRight = tr; }
            void setBottomLeft(quadNode* bl) { bottomLeft = bl; }
            void setBottomRight(quadNode* br) { bottomRight = br; }
            int getData() { return data; }
            quadNode* getTopLeft() { return topLeft; }
            quadNode* getTopRight() { return topRight; }
            quadNode* getBottomLeft() { return bottomLeft; }
            quadNode* getBottomRight() { return bottomRight; }
};

class quadTree {

    private:
            quadNode* root;

    public:
            quadTree() : root(NULL) {}
            void setRoot(quadNode* node) { root = node; }
            quadNode* getRoot() { return root; }
            bool isEmpty() { return root = NULL; }

            void preOrder()
            {
                printf("\n");
                preOrder(root);
            }
            void preOrder(quadNode* node)
            {
                if ( node != NULL ){
                    printf("(");
                    printf("%d", node->getData());
                    preOrder(node->getTopLeft());
                    preOrder(node->getTopRight());
                    preOrder(node->getBottomLeft());
                    preOrder(node->getBottomRight());
                    printf(")");
                }   
            }
            
            // int getCount()
            // {
            //     return isEmpty() ? 0 : getCount(root);
            // }
            // int getCount(quadNode* node)
            // {
            //     if ( node == NULL ) return 0;
            //     return 1 + getCount(node->getTopLeft()) + getCount(node->getTopRight()) + getCount(node->getBottomLeft()) + getCount(node->getBottomRight());
            // }
};

string twoD_Array(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);
bool area_is_white(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);
bool area_is_black(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high);

int main()
{
    int high;
    int low = 0;
    string input;
 
    cin >> high;
    
    // 동적 할당
    // int *result = new int[4]; 
    
    // 2차원 배열 선언 방법 (1)
    // int **arr = new int*[size];
    // for(int i = 0; i< size; ++i)
    //     arr[i] = new int[size];

    // 2차원 배열 선언 방법 (2)
    // int arr[size][size];
    // int arrSize = sizeof(arr)/sizeof(arr[0][0]);
    // std::fill(arr[0], arr[0]+arrSize, -1);

    // 2차원 배열 선언 방법 (3) (강추!)
    vector<vector<int> > arr(high, vector<int>(high, -1));  // vector로 선언하면 2차원 배열 함수 매개변수로 사용 가능

    for(int i=0; i<high; ++i){

        cin >> input;

        for(int j=0; j<high; ++j){

            arr[i][j] = input[j] - '0';

        }
    }
    
    string result;

    result = twoD_Array(arr, low, high, low, high);

    cout<< result << endl;

    return 0;
}


bool area_is_white(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    for(int i=row_low; i<row_high; ++i){
        for(int j=column_low; j<column_high; ++j){
            if (arr[i][j] == 1) return false;
        }
    }
    return true;
}

bool area_is_black(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    for(int i=row_low; i<row_high; ++i){
        for(int j=column_low; j<column_high; ++j){
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

string twoD_Array(vector< vector <int> > &arr, int row_low, int row_high, int column_low, int column_high)
{
    if (area_is_black(arr, row_low, row_high, column_low, column_high)){
        return "1";
    }
    if (area_is_white(arr, row_low, row_high, column_low, column_high)){
        return "0";
    }

    int row_mid = (row_high + row_low)/2;
    int column_mid = (column_high + column_low) /2;

    return "(" + twoD_Array(arr, row_low, row_mid, column_low, column_mid) + twoD_Array(arr, row_low, row_mid, column_mid, column_high) 
                + twoD_Array(arr, row_mid, row_high, column_low, column_mid)+ twoD_Array(arr, row_mid, row_high, column_mid, column_high) + ")";
        
}