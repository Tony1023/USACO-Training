/*
 ID: tony1021
 PROG: lamps
 LANG: C++
 */

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000+10;
int n,c,x,tmp;
int data[maxn];
int cnt1,cnt2;
int light[9][7]=
{
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,  //push 1
    0,0,0,1,1,1,0,  //push 1 and 4
    0,0,1,0,1,0,1,  //push 3
    0,0,1,1,0,1,1,  //push 1 and 4
    0,1,0,0,1,0,0,  //push 4
    0,1,0,1,0,1,0,  //push 2
    0,1,1,0,0,0,1,  //push 2 and 4
    0,1,1,1,1,1,1,  //no push
};
int minmum[9]={0,1,2,1,2,1,1,2,0};
int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    cin>>n>>c;
    memset(data,-1,sizeof(data));
    while(cin>>x&&x!=-1)
        data[x]=1,cnt1++;
    while(cin>>x&&x!=-1)
        data[x]=0,cnt2++;
    if(c==0)
    {
        if(cnt1==n)
        {
            while(n--)
                cout<<0;
            cout<<endl;
            return 0;
        }
        if(cnt2==0)
        {
            while(n--)
                cout<<1;
            cout<<endl;
            return 0;
        }
        if(cnt2!=0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    if(cnt1==n)
    {
        while(n--)
            cout<<0;
        cout<<endl;
        return 0;
    }
    bool flag1=false;
    for(int i=1;i<=8;i++)
    {
        bool flag2=true;
        for(int j=1;j<=n;j++)
        {
            if(data[j]==-1)
                continue;
            tmp=j%6;
            if(tmp==0)
                tmp=6;
            if(data[j]!=light[i][tmp])
            {
                flag2=false;
                break;
            }
        }
        if(flag2==true&&c>minmum[i])
        {
            //				  cout<<1<<endl;
            flag1=true;
            for(int j=1;j<=n;j++)
            {
                tmp=j%6;
                if(tmp==0)
                    tmp=6;
                cout<<light[i][tmp];
            }
            cout<<endl;
        }
    }
    if(flag1==false)
        cout<<"IMPOSSIBLE"<<endl;  
    return 0;
}
