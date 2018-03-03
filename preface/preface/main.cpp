/*
 ID: tony1021
 PROG: preface
 LANG: C++
 */

#include <iostream>
#include <cstdio>

using namespace  std;

int N;
int vis[7];
char c[8]={'I','V','X','L','C','D','M'};
// I   1     L   50   M  1000
// V   5     C  100
// X  10     D  500
// ('','I','II','III','IV','V','VI','VII','VIII','IX'),//个
// ('','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'),//十
// ('','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'),//百
// ('','M','MM','MMM','','','','','',''));//千
void cnt(int x,int digit){
    //个位
    //if(digit==1){
    int var;
    var=2*(digit-1);//对应个、十、百和千数位的数字表相对位移
    if (1<=x&&x<=3){
        vis[0+var]=vis[0+var]+x;}
    else if(x==4){
        vis[0+var]=vis[0+var]+1;
        vis[1+var]=vis[1+var]+1;
    }
    else if(x==5){
        vis[1+var]=vis[1+var]+1;
    }
    else if (6<=x&&x<=8){
        vis[0+var]=vis[0+var]+x-5;
        vis[1+var]=vis[1+var]+1;
    }
    else if (x==9){
        vis[0+var]=vis[0+var]+1;
        vis[2+var]=vis[2+var]+1;
    }
}

void dfs(int N,int digit){
    int num=N%10;
    if (num!=0){ //&& (num%10)!=0
        cnt (num,digit);}
    
    if(N/10!=0){
        N=N/10;
        dfs(N,digit+1);
    }
}

int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int i;
    cin>>N;
    for(i=0;i<=N;i++)
        dfs(i,1);
    
    for (i=0;i<7;i++)
    {   if (vis[i]!=0)
        cout<<c[i]<<" "<<vis[i]<<endl;
    }
    
    return 0;
}
