/*
 ID: tony1021
 PROG: milk
 LANG: C++
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> Pair;

void Qsort(int a[][2], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first][0];/*用字表的第一个记录作为枢轴*/
    int key2 = a[first][1];
    
    while(first < last)
    {
        while(first < last && a[last][0] >= key)
        {
            --last;
        }
        
        a[first][0] = a[last][0];/*将比第一个小的移到低端*/
        a[first][1] = a[last][1];
        
        while(first < last && a[first][0] <= key)
        {
            ++first;
        }
        
        a[last][0] = a[first][0];
        a[last][1] = a[first][1];
        /*将比第一个大的移到高端*/
    }
    a[first][0] = key;/*枢轴记录到位*/
    a[first][1] = key2;
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int N, M, fm[5000][2];
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        scanf("%d %d", &fm[i][0], &fm[i][1]);
    
    Qsort(fm, 0, M);
    
    int cost = 0, i = 0;
    while (N > fm[i][1]) {
        N -= fm[i][1];
        cost += fm[i][0] * fm[i][1];
        ++i;
    }
    cost += N * fm[i][0];
    cout << cost << "\n";
    
    
    
    return 0;
}
