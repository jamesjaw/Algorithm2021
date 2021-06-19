#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <list>
using namespace std;

pair<string, int> path[305];

vector<int> map_list[305];
vector<pair<int,int>> back_list[305];

int map[305][305];
int back[305][305];
int max_flow = 0;
/*
int find_a_path(int s,int t){
    bool vis[t+1];
    for(int i=0;i<=t;i++){
        vis[i] = false;
    }
    
    queue<int> QQ;
    QQ.push(s);
    int min_edg = 214700000;
    vis[s] = true;
    
    while(!QQ.empty()){
        int now = QQ.front();
        QQ.pop();
        //cout<<now<<"\n";
        
        
        for(int i=t;i>=0;i--){
            if(map[now][i] != 0 && vis[i] == false){
                QQ.push(i);
                if(map[now][i] < min_edg) min_edg = map[now][i];
                path[i] = pair<string,int>("map",now);
                vis[i] = true;
                if(i == t){
                    return min_edg;
                }
            }
            else if(back[now][i] != 0 && vis[i] == false){
                QQ.push(i);
                if(back[now][i] < min_edg) min_edg = back[now][i];
                path[i] = pair<string, int>("back",now);
                vis[i] = true;
                if(i == t){
                    return min_edg;
                }
            }
            
        }

    }
    return 0;
}
*/
int find_a_path(int s,int t){
    int min_edg = 214700000;
    bool vis[t+1];
    for(int i=0;i<=t;i++){
        vis[i] = false;
    }
    stack<int> SS;
    SS.push(s);
    vis[s] = true;
    while(!SS.empty()){
        int now = SS.top();
        int flag = 0;
        for(auto i:map_list[now]){
            if(vis[i] == false && map[now][i] !=0){
                SS.push(i);
                if(map[now][i] < min_edg) min_edg = map[now][i];
                path[i] = pair<string,int>("map",now);
                vis[i] = true;
                flag = 1;
                
                if(i == t){
                    return min_edg;
                }
                
                break;
            }
            else if(vis[i] == false && back[now][i] !=0){
                SS.push(i);
                if(back[now][i] < min_edg) min_edg = back[now][i];
                path[i] = pair<string, int>("back",now);
                vis[i] = true;
                flag = 1;
                
                if(i == t){
                    return min_edg;
                }
                
                break;
            }
        }
        if(flag == 0){
            SS.pop();
        }
    }
    return 0;
}

int main(){
    /*
    for(int i=0;i<305;i++){
        for(int j=0;j<305;j++){
            map[i][j] = 0;
            back[i][j] = 0;
        }
    }
    */
    int n,m;
    cin>>n>>m;
    const int s = 0;
    const int t = n+1;
    for(int i=1;i<=n;i++){
        int z;
        cin>>z;
        map_list[s].push_back(i);
        map[s][i] = z;
    }
    for(int i=1;i<=n;i++){
        int z;
        cin>>z;
        map_list[i].push_back(t);
        map[i][t] = z;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map_list[a].push_back(b);
        map_list[b].push_back(a);
        map[a][b] = c;
        map[b][a] = c;
    }
    
    //cout<<"!!\n";
    
    int neck = find_a_path(s, t);
    //cout<<neck<<"\n";
    //cout<<"??\n";
    
    while(neck){
        //cout<<neck<<"\n";
        //cout<<"zzz\n";
        max_flow += neck;
        int now = t;
        while(now != s){
            if(path[now].first == "map"){
                map[path[now].second][now] -= neck;
                back[now][path[now].second] += neck;
            }
            else if(path[now].first == "back"){
                back[path[now].second][now] -= neck;
                map[now][path[now].second] += neck;
            }
            now = path[now].second;
        }
        
        neck = find_a_path(s, t);
    }
    cout<<max_flow<<"\n";
    return 0;
}
