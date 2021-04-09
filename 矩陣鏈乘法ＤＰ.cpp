#include <iostream>

using namespace std;

int b1[300][300];
int b2[300][300];
int z[300];
int main(){
    int s;
    cin>>s;
    for(int i=1;i<=s;i++){
        cin>>z[i];
        b2[i][i] = z[i];
        b1[i][i] = 0;
    }
    for(int i=1;i<s;i++){
        for(int j=i+1;j<=s;j++){
            b2[i][j] = b2[i][j-1] + z[j];
        }
    }
    for(int i=1;i<s;i++){
        for(int j=1;j<s;j++){
            if(i+j>s) break;
            int min = 214700000;
            
            for(int k=j;k<j+i;k++){
                int temp = b1[j][k]+b2[j][k]+b1[k+1][j+i]+b2[k+1][j+i];
                if(temp<min) min = temp;
            }
            b1[j][j+i] = min;
        }
    }
    cout<<b1[1][s]<<"\n";
    /*
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s;j++){
            cout<<b1[i][j];
        }
        cout<<"\n";
    }
    */
    return 0;
}
