/*
 ID: tony1021
 PROG: ttwo
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
using namespace std;
char sqr[10][10], x[6];
int dx[4][2] = {0,1, 1,0, 0,-1, -1,0};
bool state[10][10][4][10][10][4];

void move() {
    int y = 0;
    do {
        if (x[y] + dx[x[y + 2]][0] < 0 || x[y] + dx[x[y + 2]][0] >= 10 ||
            x[y + 1] + dx[x[y + 2]][1] < 0 || x[y + 1] + dx[x[y + 2]][1] >= 10 ||
            sqr[x[y] + dx[x[y + 2]][0]][x[y + 1] + dx[x[y + 2]][1]] == '*') {
            ++x[y + 2];
            if (x[y + 2] > 3)
                x[y + 2] = 0;
        }
        else {
            x[y] += dx[x[y + 2]][0];
            x[y + 1] += dx[x[y + 2]][1];
        }
        y += 3;
    } while (y == 3);
}

int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    memset(state, false, sizeof(state));
    for (int i = 0; i < 10; ++i)
        scanf("%s", sqr[i]);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) {
            if (sqr[i][j] == 'F') {
                x[0] = i;
                x[1] = j;
                x[2] = 3;
                sqr[i][j] = '.';
            }
            if (sqr[i][j] == 'C') {
                x[3] = i;
                x[4] = j;
                x[5] = 3;
                sqr[i][j] = '.';
            }
        }
    int minute = 0;
    do {
        state[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]] = true;
        ++minute;
        move();
        if (x[0] == x[3] && x[1] == x[4]) {
            cout << minute << endl;
            return 0;
        }
    } while (!state[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]);
//    for (int i = 0; i < 49; ++i) {
//        move();
//        printf("%d %d, %d %d\n", x[0]+1, x[1]+1, x[3]+1, x[4]+1);
//    }
    cout << 0 << endl;
    return 0;
}
