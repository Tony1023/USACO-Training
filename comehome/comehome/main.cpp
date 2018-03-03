/*
 ID: tony1021
 PROG: comehome
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define INF 8388608
int P;
int paths[52][52];
bool hasCow[52], visited[52];
int dist[52];
int parent[52];

void Dijkstra() { //Starting with node 25, which is Z
    bool allVisited = false;
    while (!allVisited) {
        allVisited = true;
        int nearest, mwt = INF;
        for (int i = 0; i < 52; ++i) {
            if (!visited[i]) {
                if (dist[i] != -1 && dist[i] <= mwt) {
                    mwt = dist[i];
                    nearest = i;
                    allVisited = false;
                }
                else if (dist[i] == -1 && mwt == INF) {
                    nearest = i;
                    allVisited = false;
                }
            }
        }
        
//        Update all neighbors of #nearest
        for (int j = 0; j < 52; ++j) {
            if (!visited[j] && paths[nearest][j] != 0) {
                if (dist[nearest] + paths[nearest][j] < dist[j] || dist[j] == -1)
                    dist[j] = dist[nearest] + paths[nearest][j];
            }
            
        }
        visited[nearest] = true;
    }
    
}

int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    memset(paths, 0, sizeof(paths));
    memset(hasCow, false, sizeof(hasCow));
    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));
    cin >> P;
    char ver1, ver2;
    int wt;
    for (int i = 0; i < P; ++i) {
        cin >> ver1 >> ver2 >> wt;
        if (ver1 <= 90) { //capitalized
            hasCow[ver1 - 65] = true;
            ver1  -= 65;
        } else {
            ver1 -= 71;
        }
        if (ver2 <= 90) {
            hasCow[ver2 - 65] = true;
            ver2 -= 65;
        } else {
            ver2 -= 71;
        }
        if (paths[ver1][ver2] == 0)
            paths[ver1][ver2] = paths[ver2][ver1] = wt;
        else
            paths[ver1][ver2] = paths[ver2][ver1] = min(wt, paths[ver1][ver2]);
    }
    
//    for (int i = 0; i < 52; ++i) {
//        cout << paths[i][25] << endl;
//    }
    
//    cout << "  ";
//    for (int i = 0; i < 26; ++i)
//        cout << char(i + 65) << " ";
//    cout << endl;
//    for (int i = 0; i < 52; ++i) {
//        i < 26 ? (cout << char(i+65)) : (cout << char(i+71));
//        cout << " ";
//        for (int j = 0; j < 52; ++j)
//            cout << paths[i][j] << " ";
//        cout << "\n";
//    }
    
    dist[25] = 0;
    Dijkstra();
    
//    int i = 0;
//    while (i < 26) {
//        cout << char(i + 65) << ": " << dist[i] << endl;
//        ++i;
//    }
//    while (i < 52) {
//        cout << char(i + 71) << ": " << dist[i] << endl;
//        ++i;
//    }
//    cout << "\n";
    
    bool isLarger = true;
    while (isLarger) {
        isLarger = false;
        int node, mwt = 65536;
        for (int i = 0; i < 52; ++i) {
            if (dist[i] != 0 && dist[i] <= mwt) {
                mwt = dist[i];
                node = i;
                isLarger = true;
            }
        }
        if (isLarger && hasCow[node]) {
            cout << char(node + 65) << " " << dist[node] << endl;
            return 0;
        }
        dist[node] = 0;
    }
    return 0;
}
