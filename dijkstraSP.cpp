#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 7;

const float DENSITY = 0.19;
    // DENSITY is the prob an edge exists   
    // RANGE (0, 1)   
    // 0 means "I'm never going to put in an edge"
    // 1 means "every edges" ( complete )

float prob(){
    float randnum = static_cast<float>(rand() % 100) / 100;
    return randnum;
}

bool is_connected(bool *graph[], int size)  // still going to the open set each time as long as there are entries in the open set
{
    int old_size = 0, c_size = 0;
    bool* close = new bool[size];       // close_set      init: Nothing
    bool* open = new bool[size];        // open_set       init: possibly many or not
    for(int i = 0; i < size; ++i)      // each iteration will add one node to the closed set
        open[i] = close[i] = false;
    open[0] = true;                     // open set has node 0 on it

    //Add to close
    while(c_size < size){   // keeping track of c_size(=the size of a closed set)
        for (int i = 0; i < size; ++i){

                old_size = c_size;
            
                if(open[i] && (close[i] == false)){
                    close[i] = true; c_size++;

                //Add to open
                for(int j = 0; j< size; ++j)
                    open[j] = open[j] || graph[i][j];   // this is true if there is an edge (i,j)    graph[i][j]는 원래 닿지 않던 곳
            }
        }

        // 끝났는지 확인
        if ( c_size == size ) return true;          // connected
        if ( old_size == c_size ) return false;     // unconnected
    }
    
}

int main()
{
    //heap created 2D array of Bool
    bool** graph;
    srand(time(0)); // seed rand()
    graph = new bool*[SIZE];
    for(int i=0; i<SIZE; ++i)
        graph[i] = new bool[SIZE];

    //Draw edges
    for(int i = 0; i< SIZE; ++i)
        for(int j = i; j<SIZE; ++j)
            if(i == j) graph[i][j] = false; // no loops
                else graph[i][j] = graph[j][i] = (prob() < DENSITY);   // symmetric 

    for(int i =0; i<SIZE; ++i){
        for(int j = 0; j< SIZE; j++){

            if(graph[i][j]) cout << "1 ";
            else cout << "0 ";
        }

        cout << endl;
    }

    return 0;
}





    
