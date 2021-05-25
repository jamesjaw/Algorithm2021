#include <iostream>
#include <vector>


using namespace std;
int map[3005][3005] = {0};


int visted[3005] = {0};
vector<int> anw;
bool bfs(int start,int n,int step,int d){
    if(step>d) return false;
    anw.push_back(start);
    visted[start] = 1;
    for(int i=1;i<=n;i++){
        if(map[start][i] != 0 && visted[i] == 0){
            visted[i] = 1;
            if(bfs(i, n, step+1, d)==false) return false;;
        }
    }
    return true;
}

int main(){
    int n,d;
    cin>>n>>d;

    for(int i=0;i<n-1;i++){
        //cout<<"!\n";
        int a,b;
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    bool find_it = false;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++) visted[i] = 0;
        anw.clear();
        if(bfs(i, n, 0, d)){
            for(int i=0;i<n;i++){
                cout<<anw[i];
                if(i!=n-1) cout<<" ";
            }
            cout<<"\n";
            find_it = true;
            break;
        }
    }
    if(find_it == false) cout<<"-1\n";
    return 0;
}
