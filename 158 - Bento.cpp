#include <iostream>
#include <string>
using namespace std;

string map[2];
int maxp = 0;
void fun(int pos,int piz, int len){
    /*
    if(pos == len){
        if(piz > maxp) maxp = piz;
        return;
    }
    */
    for(int i=pos;i<len-1;i++){
        if(map[0][i]=='0' && map[1][i]=='0' && map[0][i+1]=='0'){
            map[0][i]='1' ; map[1][i]='1' ; map[0][i+1]='1';
            //fun(pos+1,piz,len);
            maxp++;
            //cout<<"t1\n";
        }
        if(map[0][i]=='0' && map[1][i]=='0' && map[1][i+1]=='0'){
            map[0][i]='1' ; map[1][i]='1' ; map[1][i+1]='1';
            //fun(pos+1,piz,len);
            maxp++;
            //cout<<"t2\n";
        }
        if(map[0][i]=='0' && map[0][i+1]=='0' && map[1][i+1]=='0'){
            map[0][i]='1' ; map[0][i+1]='1' ; map[1][i+1]='1';
            //fun(pos+1,piz,len);
            maxp++;
            //cout<<"t3\n";
        }
        if(map[1][i]=='0' && map[0][i+1]=='0' && map[1][i+1]=='0'){
            map[1][i]='1' ; map[0][i+1]='1' ; map[1][i+1]='1';
            //fun(pos+1,piz,len);
            maxp++;
            //cout<<"t4\n";
        }
    }
    return;
}

int main(){
    cin>>map[0]>>map[1];
    int len = (int)map[0].size();
    //cout<<len;
    fun(0,0,len);
    cout<<maxp<<"\n";
    return 0;
}
