#include <iostream>
#include <queue>
using namespace std;

//參考ntnu神奇土色演算法網站！！！
int network[210][210] = {0};
int re_cap[210][210] = {0};
int re_bf[210][210] = {0};
int max_flow = 0;

bool visited[210];
int flow_path[210] = {0};


int n,k,s,t;

int bfs(int s,int t){
    //learn new init way!
    //memset(visited, false, sizeof(visited));
    //memset(flow_path, 0, sizeof(flow_path));
    
    for(int i=0;i<210;i++){
        visited[i] = false;
        flow_path[i] = 0;
    }
    
    queue<int> QQ;
    QQ.push(s);
    visited[s] = true;
    flow_path[s] = s;
    
    
    while(!QQ.empty()){
        int now = QQ.front();
        QQ.pop();
        for(int i=0 ; i<=n+k+1 ; i++){
            if(visited[i] == false && re_cap[now][i] != 0){
                QQ.push(i);
                visited[i] = true;
                flow_path[i] = now;
                if(i==n+k+1){
                    //find a path
                    max_flow++;
                    return 1;
                }
            }
        }
    }
    //can not find path
    return 0;
}


int main(){
    
    cin>>n>>k;
    s = 0;
    t = n + k + 1;
    //init
    for(int i=0;i<210;i++){
        for(int j=0;j<210;j++){
            network[i][j] = 0;
            re_cap[i][j] = 0;
            re_bf[i][j] = 0;
        }
    }
    //read data
    //super_start to plug
    for(int i=1;i<=n;i++){
        network[s][i] = 1;
        re_cap[s][i] = 1;
    }
    //stock to super_end
    for(int i=n+1;i<=n+k;i++){
        network[i][t] = 2;
        re_cap[i][t] = 2;
    }
    // plug to stock
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int stock;
            cin>>stock;
            network[i][n + stock] = 1;
            re_cap[i][n + stock] = 1;
        }
    }
    
    //cout<<"!!\n";
    
    while (bfs(s,t)) {
        //cout<<"?\n";
        int now = t;
        while(now != s){
            int pre = flow_path[now];
            re_cap[pre][now] -= 1;
            re_cap[now][pre] += 1;
            now = pre;
        }
    }
    
    
    
    cout<<max_flow<<"\n";
    return 0;
}
