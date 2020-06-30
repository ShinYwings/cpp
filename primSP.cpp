#include<iostream>
#include<queue>

using namespace std;

//참조: https://makefortune2.tistory.com/37

class Graph{
    public:
        int V;
        int E;
        int **adj;
};

class Edge{
    public:
        int v1;
        int v2;
        int weight;
};

class comp{
    bool operator()(Edge E1, Edge E2){
        return E1.weight > E2.weight;
    }
};

int* distance;  //거리 배열(distance[i]는 이전 노드와 i까지의 거리)
int* path;      //경로 배열(path[i]는 i의 이전 노드)
int* visit;     //방문 배열(중복 검사를 피하기 위함)

class Graph* createGraph();
void Prims(Graph* G, int start);
void resultPrims(int V);

int main(){

    Graph* G = createGraph();

    int start;
    cout << "set the start point: "; cin >> start;
    Prims(G, start);
    resultPrims(G->V);

    return 0;
}

Graph* createGraph(){
    Graph G;

    distance = new int(10);

    G.V = 1;

    // TODO distance 선언 & 간선 추가

}

void resultPrims(int V){
    // TODO result 보이기
}

void Prims(Graph* G, int start){

    priority_queue<Edge, vector<Edge>, comp> pq;
    Edge S;
    S.v1 = start; S.v2 = start; S.weight = 0;
    pq.push(S);
    distance[start] = 0;

    while (!pq.empty()){

        int from = pq.top().v1;
        int before = pq.top().v2;
        int weight = pq.top().weight;
        pq.pop();

        if(visit[from] == 1){
            continue;
        }

        visit[from] = 1;
        distance[from] = weight;
        path[from] = before;

        for (int to = 0; to < G->V; to++){
            if (G->adj[from][to] != 0){
                if(visit[to == -1]){
                    Edge E;
                    E.v1 = to; E.v2 = from; E.weight= G.
                    pq.push(E);
                }
            }
        }
    }
}