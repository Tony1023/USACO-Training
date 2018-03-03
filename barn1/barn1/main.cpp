/*
 ID: tony1021
 PROG: barn1
 LANG: C++
 */

#include <iostream>
#include <stdio.h>
using namespace std;
void Heapfy(int A[],int idx,int max);
void buildHeap(int A[],int ll);



int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int M, S, C, stall[200], gap[200];
    scanf("%d %d %d", &M, &S, &C);
    if (M >= C) {
        cout << C << endl;
        return 0;
    }
    cin >> stall[0];
    gap[0] = -1;
    for (int i = 1; i < C; ++i)
        scanf("%d", &stall[i]);
    buildHeap(stall, C);
    for (int i = 1; i < C; ++i)
        gap[i] = stall[i] - stall[i-1] - 1;
    buildHeap(gap, C);
    
    int originalL = stall[C - 1] - stall[0] + 1;
    int slice = 0;
    for (int i = 0; i < M - 1; ++i) {
        slice += gap[C - 1 - i];
    }
    cout << originalL - slice << "\n";
    
    
    return 0;
}

void Heapfy(int A[],int idx,int max)      //建立最大堆
{
    int left=idx*2+1;
    int right=left+1;
    
    int largest=idx;
    
    if(left<max&&A[left]>A[idx]){largest=left;}
    
    if(right<max&&A[largest]<A[right]){largest=right;}
    
    if(largest!=idx)
    {
        int temp=A[largest];   //较大的节点值将交换到其所在节点的父节点
        A[largest]=A[idx];
        A[idx]=temp;
        
        Heapfy(A,largest,max); //递归遍历
        
    }
}

void buildHeap(int A[],int ll)
{
    int len=ll;
    
    
    for(int i=len/2-1;i>=0;--i)
    {
        Heapfy(A,i,len);     //建立最大堆，将堆中最大的值交换到根节点
    }
    
    for(int i=len-1;i>=1;--i)
    {
        int temp=A[0];   //将当前堆的根节点交换到堆尾的指定位置
        A[0]=A[i];
        A[i]=temp;
        
        Heapfy(A,0,i);  //建立下一次的最大堆
    }  
}
