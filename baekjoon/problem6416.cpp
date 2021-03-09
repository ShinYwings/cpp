#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 트리인가?

// 참고한 아이디어 : Disjoint Set & union-find
// Disjoint : 집합 A와 집합 B의 교집합이 전혀 없다.
/*
class disjointSet
{
    unordered_map<int ,int> parent;

    public:
        //perform MakeSet operation
        void makeSet(vector<int> const &universe)
        {
            // create 'n' disjoint sets (one for each item)
            for (int i : universe){
                parent[i] = i;
            }
        }

        //Find the root of the set in which element 'k' belongs
        int Find(int k)
        {
            // if 'k' is root
            if (parent[k] == k){
                return k;
            }

            return Find(parent[k]);
        }
        //Perform Union of two subsets
        void Union (int a, int b)
        {
            // find the root of the sets in which elements
            // 'x' and 'y' belongs
            int x = Find(a);
            int y = Find(b);

            parent[x] = y;
        }
};
*/

// cycle 찾기
// int isCycle(unordered_map<int,int> parent, int k, int size)
// {
//     if (size == -1){
//         return true;
//     }

//     // if 'k' is root
//     if (parent[k] == k){
//         return false;
//     }

//     size--;

//     return isCycle(parent, parent[k], size);
// }
                

int main(){

    for(int k=1; true; k++){
        int u,v = {0};
        bool isTree = true;
        int isRoot = -1;
        unordered_map<int,int> tree;  // vertex, parent

        while(cin >> u >> v){

            if(u == -1 && v == -1) exit(0);
            else if(u == 0 && v == 0){
                
                //root 찾기
                for(pair<int, int> iter : tree){
                    int key = iter.first;
                    int value = iter.second;

                    if (key == value){
                        if(isRoot== -1){ // 루트를 찾음
                            isRoot = key;
                        }else{  // 루트를 찾았는데 이미 루트가 있는 경우
                            isTree = false;
                        }
                    }

                    // if(isCycle(tree, value, tree.size())){
                    //     isTree = false;
                    // }
                }
                // root가 없는 경우
                if( isRoot == -1 && !tree.empty()){
                    isTree = false;
                }

                cout << "Case " << k;
                cout << (isTree ? " is a" : " is not a");
                cout << " tree." << endl;

                break;

            }else{
                
                tree.insert({u,u}); // u는 누군가의 parent임, 초기화는 자기자신

                // 들어오는 간선 2개 이상 찾기, 중복되는 u v 가 안들어온다고 가정
                if(tree.find(v) != tree.end()) // v의 parent가 존재했을 때
                {
                    if(tree[v] == v){ // 자기 자신이면 parent를 바꿔줌
                        tree[v] = u;
                    }else{
                        isTree = false; // 자기 자신이 아니면 들어오는 간선이 2개이므로 tree가 아님
                    }
                }
                else{// v의 parent가 존재하지 않으면 없는 노드임, 새로 생성
                    tree.insert({v,u});
                }
            }
        } 
    }
    return 0;
}
