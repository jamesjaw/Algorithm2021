#include <iostream>

using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    
    long long arr[100001];
    long long dp[100001];
    for(int i=0;i<100001;i++){
        arr[i] = 0;
        dp[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long totalo = 0;
    long long totalx = 0;
    for(int i=0;i<n;i++){
        long long xtoo = 0;
        for(int j=-d;j<=d;j++){
            if(arr[i]+j>=0 && arr[i]+j<=100000)
            xtoo = (xtoo%1000000007 + dp[arr[i]%1000000007 + j%1000000007])%1000000007;
        }
        long long ooo = (totalo + xtoo)%1000000007;
        long long xxx = ((1 + totalx%1000000007 - xtoo%1000000007)+1000000007)%1000000007;
        
        totalo = (totalo%1000000007 + ooo%1000000007)%1000000007;
        totalx = (totalx%1000000007 + xxx%1000000007)%1000000007;
        dp[arr[i]] = (dp[arr[i]]%1000000007 + xxx%1000000007)%1000000007;
        
    }
    
    cout<<totalo<<"\n";
  
    return 0;
}


