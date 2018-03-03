/*
 ID: tony1021
 PROG: concom
 LANG: C++
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int a,b;
}h,k;
int n,i,j,p,x,y,mar[110][110],ans[110][110];
bool own[105][105],add[105][105];
queue<node> myqueue;
int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    memset(mar,0,sizeof(mar));
    memset(own,false,sizeof(own));
    memset(add,false,sizeof(add));
    memset(ans,0,sizeof(ans));
    while (!myqueue.empty()) myqueue.pop();
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d%d%d",&i,&j,&p);
        if (i==j) continue;
        ans[i][j]=mar[i][j]=p;
        if (p>50)
        {
            h.a=i; h.b=j;
            own[i][j]=true;
            myqueue.push(h);
        }
    }
    while (!myqueue.empty())
    {
        h=myqueue.front();
        myqueue.pop();
        for (i=1;i<=100;i++)
            if (!own[h.a][i])
            {
                if (!add[h.a][h.b]) ans[h.a][i]+=mar[h.b][i];
                if (ans[h.a][i]>50)
                {
                    k.a=h.a; k.b=i;
                    own[h.a][i]=true;
                    myqueue.push(k);
                }
            }
        add[h.a][h.b]=true;
        for (i=1;i<=100;i++)
            if (own[i][h.a] && !add[i][h.b])
            {
                add[i][h.b]=true;
                for (j=1;j<=100;j++)
                    if (!own[i][j])
                    {
                        add[i][h.b]=true;
                        ans[i][j]+=mar[h.b][j];
                        if (ans[i][j]>50)
                        {
                            k.a=i; k.b=j;
                            own[i][j]=true;
                            myqueue.push(k);
                        }
                    }
            }
    }
    for (i=1;i<=100;i++)
        for (j=1;j<=100;j++)
            if (own[i][j] && i!=j) printf("%d %d\n",i,j);
    return 0;
}
