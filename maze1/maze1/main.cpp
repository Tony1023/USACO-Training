/*
 ID: tony1021
 PROG: maze1
 LANG: C++
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
const int MAX = 65535;
using namespace std;
int W,H;
string maze[205];
int value[105][40];
int d[4][2] = {1,0,
    -1,0,
    0,1,
    0,-1};

void fill(int x, int y, int step) {
//    cout << x << " " << y << " " << step << endl;
    if (value[x][y] != -1 && value[x][y] <= step) {
//        cout << endl;
        return;
    }
    value[x][y] = step;
//    cout << value[x][y] << endl;
    int ret = -1;
    for (int i = 0; i < 4; ++i) {
        int dx = d[i][0], dy = d[i][1];
//        cout << maze[x*2+1 + dx][y*2+1 + dy] << endl;
        if (maze[x*2+1 + dx][y*2+1 + dy] == 32 &&
            x + dx >= 0 && x + dx < H && y + dy >= 0 && y + dy < W)
            if (value[x + dx][y + dy] == -1 || value[x + dx][y + dy] > step)
                fill(x + dx, y + dy , step + 1);
    }
    
}

int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    cin >> W >> H;
    for (int i = 0; i < H*2 + 2; ++i) {
        string s;
        getline(cin, s);
        if (i > 0)
            maze[i - 1] = s;
    }
    for (int i = 0; i < H*2 + 1; ++i)
        if (maze[i].size() < W * 2 + 1)
            maze[i].append(W * 2 + 1 - maze[i].size(), ' ');
    
    memset(value, -1, sizeof(value));
    int ans = -1;
    //looking for entrance
    for (int i = 1; i < H * 2; i += 2) {
        if (maze[i][0] == 32)
            fill( (i - 1) / 2, 0, 1);
        if (maze[i][W * 2] == 32)
            fill( (i - 1) / 2, W - 1, 1);
    }
    for (int j = 1; j < W * 2; j += 2) {
        if (maze[0][j] == 32)
            fill(0, (j - 1) / 2, 1);
        if (maze[H * 2][j] == 32)
            fill(H - 1, (j - 1) / 2, 1);
    }
//    cout << ans << endl;
    
    ans = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j){
            ans = max(value[i][j], ans);
//            cout << value[i][j] << " ";
        }
//        cout << endl;
    }
    cout << ans << endl;
    
    return 0;
}
