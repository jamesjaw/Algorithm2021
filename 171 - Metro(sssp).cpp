#include <iostream>
#define maxx 214700000;
using namespace std;

int map[105][105];
int min_c = maxx;
bool vis[105];
bool check[105];
int n,m;

struct edg{
    int s;
    int t;
    int dis;
};


int my_function(int s,int t ,int dis){
    //cout<<"\ns = "<<s<<" t = "<<t<<" \n";
    
    int cyc = maxx;
    int node_to_s[105];
    bool node_vis[105];
    for(int i=0;i<105;i++){
        node_to_s[i] = maxx;
        node_vis[i] = false;
    }
    int now = s;
    node_vis[now] = true;
    node_to_s[now] = 0;
    int min_edg = maxx;
    
    
    while(true){
        min_edg = maxx;
        
        for(int i=1;i<=n;i++){
            if(map[now][i] != 0 && node_vis[i] == false){
                if(node_to_s[i] == 0) node_to_s[i] = node_to_s[now] + map[now][i];
                else if(node_to_s[i] != 0){
                    if(node_to_s[now] + map[now][i] < node_to_s[i]){
                        node_to_s[i] = node_to_s[now] + map[now][i];
                    }
                }
            }
        }
        /*
        cout<<"now = "<<now<<"\n";
        for(int i=1;i<=n;i++){
            cout<<node_to_s[i]<<" ";
        }
        cout<<"\n";
        */
        for(int i=1;i<=n;i++){
            if(map[now][i] != 0 && node_to_s[i] < min_edg && node_vis[i] == false){
                min_edg = node_to_s[i];
                now = i;
            }
        }
        node_vis[now] = true;
        if(min_edg == 214700000) break;
        
        
        if(now == t){
            cyc = node_to_s[now] + dis;
            //cout<<"dis = "<<dis<<"\n";
            //cout<<"t = "<<node_to_s[now]<<"\n";
            break;
        }
        
    }
    
    //cout<<"cyc is"<<cyc<<"\n";
    return cyc;
}

int main(){
    for(int i=0;i<105;i++){
        vis[i] = false;
        check[i] = false;
        for(int j=0;j<105;j++){
            map[i][j] = 0;
        }
    }
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        if(map[a][b] == 0){
            
            map[a][b] = c;
            
        }
        else if(map[a][b] != 0){
            
            if(c<map[a][b]) map[a][b] = c;
        }
        
        if(map[b][a] == 0){
            
            map[b][a] = c;
        }
        else if(map[b][a] != 0){
            
            if(c<map[b][a]) map[b][a] = c;
        }
    }
    /*
    cout<<"map is like \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j && map[i][j]!=0){
                int temp = map[i][j];
                map[i][j] = 0;
                map[j][i] = 0;
                //my function
                int find = my_function(i, j, temp);
                if(find < min_c) min_c = find;
                //
                map[i][j] = temp;
                map[j][i] = temp;
            }
        }
        check[i] = true;
    }
    
    
    if(min_c == 214700000) cout<<"-1\n";
    else
        cout<<min_c<<"\n";
    return 0;
}
