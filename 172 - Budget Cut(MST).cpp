#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1005][1005] = {0};
bool visited[1005];
int node_to_mst[1005];

int max_mst = 0;
int min_edg = 214700000;
int main(){
    //init
    for(int i=0;i<1005;i++){
        visited[i] = false;
        node_to_mst[i] = -214700000;
        for(int j=0;j<1005;j++){
            map[i][j] = 0;
        }
    }
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,dis;
        cin>>a>>b>>dis;
        map[a][b] = dis;
        map[b][a] = dis;
    }
    
    int now = 1;
    node_to_mst[1] = 0;
    visited[1] = true;
    while(true){
        //cout<<"??\n";
        //cout<<"now node = "<<now<<"\n";
        int max = 0;
        int next = -1;
        
        for(int i=1;i<=n;i++){
            if(map[now][i]!=0 && visited[i]==false){
                if(map[now][i] >= node_to_mst[i])
                    node_to_mst[i] = map[now][i];
            }
            if(visited[i]==false){
                if(node_to_mst[i]>max){
                    max = node_to_mst[i];
                    next = i;
                }
            }
        }
        
        if(next == -1) break;
        if(max < min_edg) min_edg = max;
        max_mst += max;
        now = next;
        visited[next] = true;
    }
    
    
   // cout<<"zzz "<<min_edg<<"zzz\n";
    //init
    max_mst = 0;
    
    for(int i=0;i<1005;i++){
        visited[i] = false;
        node_to_mst[i] = 214700000;
    }
    
    now = 1;
    node_to_mst[1] = 0;
    visited[1] = true;
    while(true){
        //cout<<"??\n";
        //cout<<"now node = "<<now<<"\n";
        int max = 214700000;
        int next = -1;
        
        for(int i=1;i<=n;i++){
            if(map[now][i]!=0 && visited[i]==false){
                if(map[now][i] <= node_to_mst[i] && map[now][i] >= min_edg)
                    node_to_mst[i] = map[now][i];
            }
            if(visited[i]==false){
                if(node_to_mst[i]<max && node_to_mst[i] >= min_edg){
                    max = node_to_mst[i];
                    next = i;
                }
            }
        }
        
        if(next == -1) break;
        //cout<<max<<"\n";
        max_mst += max;
        now = next;
        visited[next] = true;
    }
    
    cout<<max_mst<<"\n";
    return 0;
}

