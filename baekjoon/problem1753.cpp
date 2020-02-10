#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdio>

using namespace std;

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

    // cin >> V >> E;
    scanf("%d %d", &V, &E);

    // cin >> K;   // 시작 노드
    scanf("%d", &K);   

    // int **arr = new int*[V];    // 한 방향 그래프
    // for(int i {0}; i< V; ++i){  // 2차원으로 하면 arr[200000][200000] => 256MB 초과
    //     arr[i] = new int[V];
    //     fill_n(arr[i], V, 0);
    // }

    vector<Node>* arr = new vector<Node>[V+1];      // next node 와 weight

    //init

    for(int i=1; i<E+1; ++i){

        int u=0, v=0, w=0;

        // cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);

        arr[u].push_back(Node(v, w));     // u -> v 노드와 가중치 w
    }

    int* closed_set = new int[V+1];     // K노드로 부터 각 노드의 거리
    // int closed_set[20001] = {-1};

    for(int i=0; i<V+1; ++i){
        closed_set[i] = -1;
    }

    priority_queue< pair<int ,int>, vector< pair<int, int> > , greater< pair<int, int> > > open_set;  // 노드로 부터 인접한 노드들
    // queue< pair<int ,int> > open_set;  // 노드로 부터 인접한 노드들

    //Dijkstra Shortest Path

    vector<Node>::iterator it;

    open_set.push(make_pair(0, K)); // pair는 첫번째 인수 먼저 비교하니까 weight가 첫번째 인수로 나와야함.
    closed_set[K] = 0;

    while(!open_set.empty()){

        int curr = open_set.top().second;
        int weight = open_set.top().first;

        open_set.pop();

        for(it=arr[curr].begin(); it != arr[curr].end(); ++it){

            int next = it->next;
            int dist = it->dist;

            dist += weight;  // dist에 현재까지의 weight 추가
            
            if(closed_set[next] > dist || closed_set[next] == -1){   // 더 짧은 거리를 찾았을때 || closed_set이 설정 안되어 있을때
                    open_set.push(make_pair(dist, next));
                    closed_set[next] = dist;
            }
        }
    }

    for(int i=1; i<V+1; ++i){
        if(closed_set[i] == -1){
            // cout << "INF" << endl;
            printf("INF\n");
        }else{
            // cout << closed_set[i] << endl;
            printf("%d\n", closed_set[i]);
        }
    }

    return 0;
}