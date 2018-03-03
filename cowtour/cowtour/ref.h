/*
 ID: tony1021
 PROG: cowtour
 LANG: C++
 */
#include<iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include<math.h>
#include<memory.h>
using namespace std;
struct Point
{
    int x,y;
};
Point p[160];
double map[160][160];
double maxDis[160];
double getDistance(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main() {
    freopen("cowtour.out", "w", stdout);
    freopen("cowtour.in", "r", stdin);
    memset(map,0,sizeof(map));
    memset(maxDis,0,sizeof(maxDis));
    int N;
    char a;
    double temp,minDis=100000;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>p[i].x>>p[i].y;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        {
            cin>>a;
            if(i!=j)
            {
                if(a=='0')
                    map[i][j]=100000;
                else
                    map[i][j]=getDistance(p[i],p[j]);
            }
        }
    
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(map[i][k]+map[k][j]<map[i][j])
                    map[i][j]=map[i][k]+map[k][j];
    
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(map[i][j]>maxDis[i]&&map[i][j]!=100000)
                maxDis[i]=map[i][j];
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(map[i][j]==100000)
            {
                temp=getDistance(p[i],p[j])+maxDis[i]+maxDis[j];
                if(temp<minDis)
                    minDis=temp;
            }
    
    for(int i=1;i<=N;i++)
        if(maxDis[i]>minDis)
            minDis=maxDis[i];
    cout<<setprecision(6)<<setiosflags(ios::fixed)<<minDis<<endl;
    return 0;
}
