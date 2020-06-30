#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <string>

using namespace std;

typedef enum directions{N, NW, W, SW, S, SE, E, NE} directions;

inline directions operator++(directions d){

    int temp = static_cast<int>(d+1) % 8;

    if( temp == 8) temp = 0;

    directions setDir = static_cast<directions>(temp);

    return setDir;

}

pair<int, int> goToNextCoordinate(int x, int y, directions direction_of_shark){
    
    if( direction_of_shark == N){
        //North
        return {x-1, y};
    }
    else if(direction_of_shark == NW){
        //NorthWest
        return {x-1, y-1};  
    }
    else if( direction_of_shark == W){
        //West
        return {x, y-1};   
    }
    else if( direction_of_shark == SW){
        //SouthWest
        return {x+1, y-1};   
    }
    else if( direction_of_shark == S){
        //South
        return {x+1, y};   
    }
    else if( direction_of_shark == SE){
        //SouthEast
        return {x+1, y+1};    
    }
    else if( direction_of_shark == E){
        //East
        return {x, y+1};   
    }
    else if( direction_of_shark == NE){
        //NorthEast
        return {x-1, y+1};
    }else{
        cout << "@@@@@@@@@@@@@ERROR@@@@@@@@@@@@@@" << endl;
    }
};

string showArrow(directions direction){
   
    if(direction == N) return "↑";
    else if(direction == NW) return "↖";
    else if(direction == W) return "←";
    else if(direction == SW) return "↙";
    else if(direction == S) return "↓";
    else if(direction == SE) return "↘";
    else if(direction == E) return "→";
    else if(direction == NE) return "↗";
    else return "error";
}

// 1~ 16 의 물고기 , 8 direction ++반시계 
class fish_info{
    public:
        pair<int,int> coordinate;
        directions direction;
        bool die;

        fish_info(){};

        fish_info(pair<int,int> coord, directions direct){
            coordinate = coord;
            direction = direct;
            die = false;
        }    

        void setDie(bool di){
            die=di;
        }

    // ~fish_info(){

        
    // }
};

//현재위치, 상어방향, 현재상태, 합계
class shark_info{
    public:
        pair<int, int> current_location;
        directions direction_shark;
        array<array<int, 4>, 4> map_current;
        int total_score;

    shark_info(pair<int, int> cur_loc, directions direct_shark, array<array<int,4>,4> map_cur, int tot_score){

        current_location = cur_loc;
        direction_shark = direct_shark;
        map_current= map_cur ;
        total_score = tot_score;
    }

};

int main(){

    array<array<int, 4>, 4> space;

    //(좌표, 방향)..   0일경우 죽은거
    array<fish_info, 17> fish_index;

    int ans = 0;

    for(int i=0; i<4; i++){
        
        int num, dir;

        for(int j=0; j<4; j++){

            cin >>num >> dir;

            space[i][j] = num;
            fish_index[num] = fish_info({i,j}, static_cast<directions>(dir-1));
        }
    }

    // cout << endl;
    // for(int i=0; i<4; i++){
    //     for(int j =0; j<4; j++){
    //         cout<< space[i][j] << " ";
    //         cout << showArrow(fish_index[space[i][j]].direction) << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "123물고기 방향:  " ;
    //     for(int i=1; i< 17; i++){
    //          cout << fish_index[i].direction+1 << " " ;
    //     }
    // cout << endl << "----------------" << endl;

    queue<pair<shark_info, array<fish_info, 17> > > q;

    int fish_first_victimed = space[0][0];
    directions shark_first_direction = fish_index[fish_first_victimed].direction;
    
    //물고기 죽음 표시
    space[0][0] = 0;
    fish_index[fish_first_victimed].setDie(true);
    ////////////

    //현재위치, 상어방향, 현재상태, 합계
    shark_info first_trial_fish = shark_info({0,0}, shark_first_direction, space, fish_first_victimed);
    q.push({first_trial_fish, fish_index});

    while(!q.empty()){

        //상어 현재 위치
        pair<int, int> current_shark_coordinate =  q.front().first.current_location;
        directions current_shark_direction = q.front().first.direction_shark;
        //현재 맵 상태
        array<array<int, 4>, 4> current_map_statement = q.front().first.map_current;
        //Find Max Num of direction
        int current_score = q.front().first.total_score;
        
        //물고기 좌표, 물고기 방향
        array<fish_info, 17> current_fish_index = q.front().second;   

        q.pop();

        // cout << endl << "물고기 이동 전!!" << endl; 
        //     for(int i=0; i<4; i++){
        //         for(int j =0; j<4; j++){
        //             int a = current_map_statement[i][j];
        //             cout<< a ;                
        //             if( a== 0 ){
        //                 if(i == current_shark_coordinate.first && j == current_shark_coordinate.second){
        //                         cout << "*" << " "; 
        //                     }else
        //                 cout << "죽" << " ";
        //             }
        //             else{
        //                 string b = showArrow(current_fish_index[a].direction);
        //                 cout << b <<  " " ;
        //             }
        //         }
        //         cout << endl;
        //     }

        // cout << "123물고기 방향:  " ;
        // for(int i=1; i< 17; i++){
        //      cout << current_fish_index[i].direction+1 << " " ;
        // }
        // cout << endl << "----------------" << endl;     

        //물고기 턴
        for(int n=1; n<17; n++){

            bool isFirst = true;

            if(current_fish_index[n].die) continue;

            if(!current_fish_index[n].die){

                directions original_direction = current_fish_index[n].direction; 
            
                while(original_direction != current_fish_index[n].direction || isFirst){ 

                    isFirst = false;
                    int fish_x = current_fish_index[n].coordinate.first;
                    int fish_y = current_fish_index[n].coordinate.second;

                    pair<int,int> next_fish_coordinate = goToNextCoordinate(fish_x, fish_y, current_fish_index[n].direction);

                    int fish_nx = next_fish_coordinate.first;
                    int fish_ny = next_fish_coordinate.second;

                    if(0 <= fish_nx && fish_nx < 4 && 0 <= fish_ny && fish_ny < 4 && !(fish_nx == current_shark_coordinate.first && fish_ny == current_shark_coordinate.second)){
                        int fishNum = current_map_statement[fish_nx][fish_ny];   //이것이 문제였음 ...!
                        int fishNum2 = 0;

                        for(int t=1; t<17; t++){
                            
                            if (current_fish_index[t].coordinate.first == fish_nx && current_fish_index[t].coordinate.second == fish_ny)
                                fishNum2 = t;
                            }
    
                            // cout <<"n :" << n << "/swap {" << current_fish_index[n].coordinate.first << ", " << current_fish_index[n].coordinate.second << "} <->";
                            // cout << "to {" << current_fish_index[fishNum].coordinate.first << ", " << current_fish_index[fishNum].coordinate.second << "} " << endl;
                            // cout << "swap number {" << current_map_statement[fish_x][fish_y] << " <-> " << current_map_statement[fish_nx][fish_ny] << "} " << endl;

                            // cout << "fish index:  " ;
                            // for(int i=1; i< 17; i++){
                            //      cout << i<< "/" <<showArrow(current_fish_index[i].direction)<<"/{" << current_fish_index[i].coordinate.first <<","<< current_fish_index[i].coordinate.second<< "}" ;
                            //     if(current_fish_index[i].die)
                            //         cout << "X ";
                            //         else cout << "O ";
                            // }
                            // cout << endl;
                            swap(current_fish_index[n].coordinate, current_fish_index[fishNum2].coordinate);        //여기서 fishNum의 좌표를 스왑하니까 좌표가 겹쳤었음 ㅠ
                            swap(current_map_statement[fish_x][fish_y], current_map_statement[fish_nx][fish_ny]);
                        break;
                    }
                    //45도 회전
                    else{
                        current_fish_index[n].direction = ++current_fish_index[n].direction; 

                    }//fi   
                }//elihw
            }//fi
        }//rof

        //  cout << endl << "물고기 다 이동한 상태!!" << endl; 
        //     for(int i=0; i<4; i++){
        //         for(int j =0; j<4; j++){
        //             int a = current_map_statement[i][j];
        //             cout<< a ;                
        //             if( a== 0 ){
        //                 if(i == current_shark_coordinate.first && j == current_shark_coordinate.second){
        //                         cout << "*" << " "; 
        //                     }else
        //                 cout << "죽" << " ";
        //             }
        //             else{
        //                 string b = showArrow(current_fish_index[a].direction);
        //                 cout << b <<  " " ;
        //             }
        //         }
        //         cout << endl;
        //     }

        //상어 이동할 칸에 들어옴
        // cout << "current_shark location : " << current_shark_coordinate.first << ",  " << current_shark_coordinate.second << endl;
        // cout << "current_shark_direction : " << showArrow(current_shark_direction) << endl;

        //최초 이동
        pair<int, int> next_shark_coordinate = goToNextCoordinate(current_shark_coordinate.first, current_shark_coordinate.second, current_shark_direction);

        //상어 턴   다음칸이 0이여도 그 다음칸으로 이동할 수 있음   경우의 수 만들기작업
        while(0 <= next_shark_coordinate.first && next_shark_coordinate.first < 4 && 0 <= next_shark_coordinate.second && next_shark_coordinate.second < 4){

            if(current_map_statement[next_shark_coordinate.first][next_shark_coordinate.second] != 0){

                array<fish_info, 17> temp_fish_index = current_fish_index;
                array<array<int, 4>,4> temp_map = current_map_statement;
                int temp_score = current_score;
                
                // cout << "상어 이동함 : " << next_shark_coordinate.first << ", " << next_shark_coordinate.second <<endl;

                //상어가 물고기 먹음
                int number_of_fish_victimed = temp_map[next_shark_coordinate.first][next_shark_coordinate.second];
               
                temp_score += number_of_fish_victimed;
                // cout << "score :" << temp_score << endl;

                // 상어의 방향성 가짐
                directions shark_towards = temp_fish_index[number_of_fish_victimed].direction;
                
                // cout << "shark_towards : " << showArrow(shark_towards) <<endl;
                // 물고기 죽음 (0)
                temp_map[next_shark_coordinate.first][next_shark_coordinate.second] = 0;
                temp_fish_index[number_of_fish_victimed].setDie(true);
                // temp_fish_index[number_of_fish_victimed].coordinate = {-1,-1};

                //현재위치, 상어방향, 현재상태, 합계
                shark_info next = shark_info(next_shark_coordinate, shark_towards, temp_map, temp_score);
                
                q.push({next, temp_fish_index});

                // cout << endl;
                // for(int i=0; i<4; i++){
                //     for(int j =0; j<4; j++){
                //         int a = temp_map[i][j];
                //         cout<< a ;                
                //         if( a== 0 ){

                //             if(i == next_shark_coordinate.first && j == next_shark_coordinate.second){
                //                 cout << "*" << " "; 
                //             }else
                //                 cout << "죽" << " ";
                //         }
                //         else{
                //             string b = showArrow(temp_fish_index[a].direction);
                //             cout << b <<  " " ;
                //         }
                //     }
                //     cout << endl;
                // }

                // cout << "물고기 방향:  " ;
                // for(int i=1; i< 17; i++){
                //     cout << i << showArrow(temp_fish_index[i].direction) << " " ;
                // }
                // cout << endl << "-=---------------------===" << endl;            

            }
            //다음칸 전진
            next_shark_coordinate = goToNextCoordinate(next_shark_coordinate.first, next_shark_coordinate.second, current_shark_direction);    

        }//elihw

        if( current_score > ans ){
                    ans = current_score;
        }

    }//큐 끝

    cout << ans ;

    return 0;

}