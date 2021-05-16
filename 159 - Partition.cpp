#include <iostream>
using namespace std;

int num[17];
int used[17];

int cal(int pos,int n,int k,int sum,int avg){
    if(k==1) return 1;
    if(sum==avg){
        return cal(0,n,k-1,0,avg);
    }
    else{
        for(int i=pos;i<n;i++){
            if(used[i]==0 && sum+num[i]<=avg){
                used[i] = 1;
                if(cal(pos+1,n,k,sum+num[i],avg)==1){
                    return 1;
                }
                used[i] = 0;
            }
        }
        return 0;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int avg = 0;
   
    for(int i=0;i<n;i++){
        cin>>num[i];
        used[i] = 0;
        avg += num[i];
    }
    avg /= 3;
    
    if(cal(0,n,3,0,avg)==1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
