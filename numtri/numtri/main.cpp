/*
 ID: tony1021
 PROG: numtri
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int sumTo(int,int);
int numtri[1000][1000], R;
int maxSum[1000][1000];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    cin >> R;
    for (int r = 0; r < R; ++r)
        for (int i = 0; i <= r; ++i)
            cin >> numtri[r][i];
    memset(maxSum, -1, sizeof(maxSum));
    
    cout << sumTo(0, 0) << endl;
    
    return 0;
}

int sumTo(int r,int i) {
    if (maxSum[r][i] != -1)
        return maxSum[r][i];
    if (r < R - 1)
        maxSum[r][i] = numtri[r][i] + max(sumTo(r+1, i), sumTo(r+1, i+1));
    else
        maxSum[r][i] = numtri[r][i];
    return maxSum[r][i];
}
