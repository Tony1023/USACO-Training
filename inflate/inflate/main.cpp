/*
 ID: tony1021
 PROG: inflate
 LANG: C++
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
using namespace std;

int M, N, score[10001], Time[10001];
int f[10001];

int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    memset(f, 0, sizeof(f));
    cin >> M >> N;
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &score[i], &Time[i]);
    
    for (int i = 0; i < N; ++i) {
        for (int j = Time[i] - 1; j < M; ++j) {
            f[j] = max(f[j], f[j - Time[i]] + score[i]);
        }
    }
    
    int solution = 0;
    for (int i = 0; i < M; ++i) {
        solution = max(solution, f[i]);
    }
    cout << solution << endl;
    
    return 0;
}
