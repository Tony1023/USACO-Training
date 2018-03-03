/*
 ID: tony1021
 PROG: agrinet
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;
int N;
bool inTree[101];
int dist[101];
int map[101][101];

int span() {
    int treeSize = 1, treeCost = 0;
    inTree[0] = true;
    for (int i = 0; i < N; ++i) {
        if (map[0][i] > 0)
            dist[i] = map[0][i];
    }
    while (treeSize < N) {
        int max = 100001, nextNode = -1;
        //find the next node
        for (int i = 0; i < N; ++i) {
            if (inTree[i] || dist[i] == -1)
                continue;
            if (dist[i] < max) {
                nextNode = i;
                max = dist[i];
            }
        }
        inTree[nextNode] = true;
        ++treeSize;
        treeCost += max;
        for (int i = 0; i < N; ++i) {
            if (map[nextNode][i] > 0) {
                if (dist[i] == -1)
                    dist[i] = map[nextNode][i];
                else
                    dist[i] = min(dist[i], map[nextNode][i]);
            }
        }
    }
    return treeCost;
}

int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    memset(inTree, false, sizeof(inTree));
    memset(map, 0, sizeof(map));
    memset(dist, -1, sizeof(dist));
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &map[i][j]);
    
    cout << span() << endl;
    return 0;
}
