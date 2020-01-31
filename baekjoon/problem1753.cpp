#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

const int MAX_V = 20001;

class Node{
    public:
        int next;
        int dist;
        Node(int n=0, int d=0): next(n), dist(d){};

};

int main()
{
    int V =0; 
    int E =0;
    int K =0;

    cin >> V >> E;

    cin >> K;   // 시작 노드
                  
    // int **arr = new int*[V];    // 한 방향 그래프
    // for(int i {0}; i< V; ++i){  // 2차원으로 하면 arr[200000][200000] => 256MB 초과
    //     arr[i] = new int[V];
    //     fill_n(arr[i], V, 0);
    // }

    vector<Node>* arr = new vector<Node>[V+1];      // next node 와 weight
    // vector<Node> arr[MAX_V];

    //init
    // K--; // 0부터 시작하기 때문에 하나 줄여줌

    for(int i=1; i<E+1; ++i){

        int u=0, v=0, w=0;

        cin >> u >> v >> w;

        arr[u].push_back(Node(v, w));     // u -> v 노드와 가중치 w
    }

    int* closed_set = new int(V+1);                     // K노드로 부터 각 노드의 거리
    for(int j=0; j<V+1; ++j){
        closed_set[j] = -1;
    }
    // int closed_set[MAX_V] = {-1, };


    priority_queue< pair<int ,int>, vector< pair<int, int> > , greater< pair<int, int> > > open_set;  // 노드로 부터 인접한 노드들
    // queue< pair<int ,int> > open_set;  // 노드로 부터 인접한 노드들

    //Dijkstra Shortest Path

    vector<Node>::iterator it;

    open_set.push(make_pair(0, K)); // pair는 첫번째 인수 먼저 비교하니까 weight가 첫번째 인수로 나와야함.
    closed_set[K] = 0;

    while(!open_set.empty()){

        int curr = open_set.top().second;
        int weight = open_set.top().first;
        // int curr = open_set.front().second;
        // int weight = open_set.front().first;
        open_set.pop();

        for(it=arr[curr].begin(); it != arr[curr].end(); ++it){

            int next = it->next;
            int dist = it->dist;
            if( next == curr ) continue;  // i가 현재 노드를 가리키면 pass 

            dist += weight;  // dist에 현재까지의 weight 추가
            
            if(closed_set[next] > dist || closed_set[next] == -1){   // 더 짧은 거리를 찾았을때 || closed_set이 설정 안되어 있을때
                    open_set.push(make_pair(dist, next));
                    closed_set[next] = dist;
            }
        }
    }

    for(int i=1; i<V+1; ++i){
        if(closed_set[i] == -1){
            cout << "INF" << endl;
        }else{
            cout << closed_set[i] << endl;
        }
    }

    delete closed_set;
    delete [] arr;

    return 0;
}