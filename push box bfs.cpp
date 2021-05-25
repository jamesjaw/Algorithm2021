#include <iostream>
#include <queue>
using namespace std;
int row,col;
struct stat{
    int recod[4] = {0};
};

struct pos{
    int row = 0;
    int col = 0;
    int step = 0;
};

//方便走上下左右用 0=右 1=左 2=下 3=上
int g1[4] = {0,0,1,-1};
int g2[4] = {1,-1,0,0};


stat box_stat[31][31];
char map[31][31];
pos man_pos,box_pos,exit_pos;

bool can_go(pos man_pos , pos can ,pos box){
    if((can.row < 0 || can.row >= row) && (can.col < 0 || can.col >= col)) return false;
    if(map[can.row][can.col] != '.') return false;
    
    map[box.row][box.col] = 'B';
    
    queue<pos> wait_list;
    int used[31][31] = {0};
    used[man_pos.row][man_pos.col] = 1;
    wait_list.push(man_pos);
    while(!wait_list.empty()){
        //cout<<"ho\n";
        pos this_step = wait_list.front();
        pos t;
        wait_list.pop();
        for(int i=0;i<4;i++){
            if(map[this_step.row + g1[i]][this_step.col + g2[i]] == '.' && used[this_step.row + g1[i]][this_step.col + g2[i]] == 0){
                //cout<<"jo\n";
                used[this_step.row + g1[i]][this_step.col + g2[i]] = 1;
                t.row = this_step.row + g1[i];
                t.col = this_step.col + g2[i];
                if(t.col == can.col && t.row==can.row){
                    map[box.row][box.col] = '.';
                    return true;
                }
                    
                wait_list.push(t);
            }
        }
    }
    map[box.row][box.col] = '.';
    return false;
}


int min_push(pos man_pos,pos box_pos){
    pos box;
    box.row = box_pos.row;
    box.col = box_pos.col;
    queue<pos> wait_list;
    stat map_stat[31][31];
    wait_list.push(box_pos);
    while(!wait_list.empty()){
        //cout<<"hi\n";
        pos this_box = wait_list.front();
        wait_list.pop();
        for(int i=0;i<4;i++){
            //cout<<"i = "<<i<<"\n";
            //cout<<this_box.row + g1[i]<<"/"<<this_box.col + g2[i]<<"/"<<map[this_box.row + g1[i]][this_box.col + g2[i]]<<"\n";
            if(map[this_box.row + g1[i]][this_box.col + g2[i]] == '.'){
                //cout<<"1\n";
                if(map_stat[this_box.row][this_box.col].recod[i] == 0){
                    //cout<<"2\n";
                    map_stat[this_box.row][this_box.col].recod[i] = 1;
                    pos z;
                    z.row = this_box.row - g1[i];
                    z.col = this_box.col - g2[i];
                    //cout<<"i = "<<i<<"\n";
                    //cout<<man_pos.row<<"/"<<man_pos.col<<"\n";
                    //cout<<z.row<<"/"<<z.col<<"\n";
                    box.row = this_box.row;
                    box.col = this_box.col;
                    if(can_go(man_pos, z, box)){
                        //cout<<"3\n";
                        pos s;
                        s.row = this_box.row + g1[i];
                        s.col = this_box.col + g2[i];
                        s.step = this_box.step + 1;
                        if(s.row == exit_pos.row && s.col == exit_pos.col) return s.step;
                        wait_list.push(s);
                    }
                }
            }
        }
    }
    return -1;
}



int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            char c;
            cin>>c;
            if(c=='S'){
                man_pos.row = i;
                man_pos.col = j;
                map[i][j] = '.';
            }
            else if(c=='B'){
                box_pos.row = i;
                box_pos.col = j;
                map[i][j] = '.';
            }
            else if(c=='T'){
                exit_pos.row = i;
                exit_pos.col = j;
                map[i][j] = '.';
            }
            else{
                map[i][j] = c;
            }
        }
    }
    //minpushbox
    //if(can_go(man_pos, exit_pos ,box_pos)) cout<<"can go to\n";
    //else cout<<" can not go\n";
    
    int anw = min_push(man_pos, box_pos);
    cout<<anw<<"\n";
    return 0;
}
