#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std; // 부모노드를 가져옴 

/* find(x): 재귀 이용 */
int find(int root[], int x) {
    // 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
    if (root[x] == x) {
        return x;
    } else {
        // "경로 압축(Path Compression)"
        // find 하면서 만난 모든 값의 부모 노드를 root로 만든다.
        return root[x] = find(root[x]);
    }
}
    
/* union1(x, y): union-by-rank 최적화 */
void mUnion(int x, int y){
   x = find(x);
   y = find(y);

   // 두 값의 root가 같으면(이미 같은 트리) 합치지 않는다.
   if(x == y)
     return;

   // "union-by-rank 최적화"
   // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉, 높이가 더 높은 쪽을 root로 삼음
   if(rank[x] < rank[y]) {
     root[x] = y; // x의 root를 y로 변경
   } else {
     root[y] = x; // y의 root를 x로 변경

     if(rank[x] == rank[y])
       rank[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)
   }
}


int findParent(int parent[], int x, int y)
{ 
    x = find(parent, x); 
    y = find(parent, y); 
    if(x == y){ // 같은 부모 노드 
        return 1; 
    }else{ // 다른 부모 노드 
        return 0; 
    }
} // 간선들의 정보 

class Edge{ 
    public: int node[2]; 
    int distance; 
    Edge(int x, int y, int distance)
    { 
        this->node[0] = x; 
        this->node[1] = y; 
        this->distance = distance; 
    }
    
    bool operator <(Edge &edge){return this->distance < edge.distance; } 
        
}; 

int main(int argc, char* argv[]) 
{ 
    int n = 7; // 노드의 개수 
    int m = 11; // 간선의 개수 
    vector<Edge> v; 
    v.push_back(Edge(1, 7, 12)); // 1 
    v.push_back(Edge(4, 7, 13)); // 2 
    v.push_back(Edge(1, 4, 18)); // 3 
    v.push_back(Edge(1, 2, 67)); // 4 
    v.push_back(Edge(1, 5, 17)); // 5 
    v.push_back(Edge(2, 4, 24)); // 6 
    v.push_back(Edge(2, 5, 62)); // 7 
    v.push_back(Edge(3, 5, 20)); // 8 
    v.push_back(Edge(3, 6, 37)); // 9 
    v.push_back(Edge(5, 6, 45)); // 10 
    v.push_back(Edge(5, 7, 73)); // 11 

    // 거리를 오름차순으로 정렬 
    sort(v.begin(), v.end()); // 초기화 
    
    /* 초기화 */
    int root[n];
    int rank[n]; // 트리의 높이를 저장할 배열
    for (int i = 0; i < n; i++) {
        root[i] = i;
        rank[i] = 0; // 트리의 높이 초기화
    }

    int sum = 0; 
    for(int i=0; i<v.size(); i++){ 
        if(!findParent(root, v[i].node[0]-1, v[i].node[1]-1))
        { // 사이클이 생기지 않는 경우 (다른 부모를 갖는경우) 
        sum += v[i].distance; // 연결을 하고 나면, 같은 부모를 갖게 되므로... 
        mUnion(root, v[i].node[0]-1, v[i].node[1]-1); 
        }// end if
        
    } // end for 

    // 결과 확인
    cout << sum; 
    return 0; 
}
