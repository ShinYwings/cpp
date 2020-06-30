#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10;


/* 초기화 */
int root[MAX_SIZE];
int rank[MAX_SIZE]; // 트리의 높이를 저장할 배열
for(int i = 0; i < MAX_SIZE; i++) {
  root[i] = i;
  rank[i] = 0; // 트리의 높이 초기화
}

/* find(x): 재귀 이용 */
int find(int x) {
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
void union(int x, int y){
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
