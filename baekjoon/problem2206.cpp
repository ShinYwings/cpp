#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int map[1001][1001] = {0};  //전역변수로 선언하면 메모리는 차지하지만 속도는 빠름..

//  아래, 오른, 왼,  위 ( 우선순위 순서대로)
const int dx[] = { 1, 0, 0, -1};
const int dy[] = { 0, 1, -1, 0};

int N, M = 0;  // 맵 크기

queue< pair<pair<int, int>, pair<int, bool> > > q;
           //현재 좌표                //chance

inline int bfs(int start_x, int start_y){

    q.push(make_pair( make_pair(start_x, start_y), make_pair(1, false)));
                        //first                   //second
    bool visited[1001][1001][2] = {false}; // 방문함?   벽부수고 온거랑 안부수고 온거랑 두가지
    visited[0][0][0] = true;
    
    while(!q.empty()){

        int x = q.front().first.first;
        int y = q.front().first.second;
        int distance = q.front().second.first; // 최단경로의 좌표 저장
        bool chance_used = q.front().second.second;
    
        q.pop();

        if(x == N-1 && y == M-1){
            return distance;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {

                if ( map[nx][ny] == 0 && !visited[nx][ny][0] && !chance_used){ // 찬스를 아직 안썼고 갈 수 있는 길이면...  

                    visited[nx][ny][0] = true;
                    int temp = distance + 1;
                    q.push(make_pair(make_pair(nx,ny), make_pair(temp, chance_used)));
                }

                if ( map[nx][ny] == 0 && !visited[nx][ny][1] && chance_used){ // 찬스를 썼고 갈 수 있는 길이면...  

                    visited[nx][ny][1] = true;
                    int temp = distance + 1;
                    q.push(make_pair(make_pair(nx,ny), make_pair(temp, chance_used)));
                }

                if ( map[nx][ny] == 1 && !chance_used){ // 벽

                    visited[nx][ny][1] = true;
                    int temp = distance + 1;
                    q.push(make_pair(make_pair(nx,ny), make_pair(temp, true)));
                }
            }
        }
    }

    return -1; // 끝을 못찾는 경우
}

int main()
{
    cin >> N >> M;

    // create a map
    for (int i=0; i<N; ++i){

        string input;

        cin >> input;

        for(int j=0; j< M; ++j){
            
            map[i][j] = input[j] - '0';

        }
    }

    int result = 0;

    result = bfs(0,0);

    cout << result <<endl;

    return 0;
}