/*
 ID: tony1021
 PROG: castle
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int castle[50][50], M, N, subsetN = 0, subsets[50][50], wallSerial[4] = {1,2,4,8};
int subsetSize[2500], maxSum[4]; //0 for row, 1 for col, 2 for max combination, 3 is 0 or 1 for N or E
void findSubsets(int, const int, const int);
void collectSubsets();
void breakWall();

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> M >> N;
    maxSum[0] = N - 2; maxSum[1] = M - 2; maxSum[2] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> castle[i][j];
    memset(subsets, -1, sizeof(subsets));
    memset(subsetSize, 0, sizeof(subsetSize));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (subsets[i][j] == -1) {
                findSubsets(subsetN, i, j);
                ++subsetN;
            }
    cout << subsetN << "\n";
    collectSubsets();
    breakWall();
    cout << maxSum[2] << "\n" << maxSum[0]+1 << " " << maxSum[1]+1 << " ";
    if (maxSum[3] == 0)
        cout << "N\n";
    else
        cout << "E\n";
    return 0;
}

void breakWall() {
    int sum;
    int sub, subUp, subRight;
    for (int j = 0; j < M; ++j)
        for (int i = N - 1; i >= 0; --i){
            sub = subsets[i][j];
            subUp = i == 0 ? -1 : subsets[i - 1][j];
            subRight = j == M - 1 ? -1 : subsets[i][j + 1];
            if (subUp != -1 && sub != subUp) {
                sum = subsetSize[sub] + subsetSize[subUp];
                if (sum > maxSum[2]) {
                    maxSum[0] = i;
                    maxSum[1] = j;
                    maxSum[2] = sum;
                    maxSum[3] = 0;
                }
            }
            if (subRight != -1 && sub != subRight) {
                sum = subsetSize[sub] + subsetSize[subRight];
                if (sum > maxSum[2]) {
                    maxSum[0] = i;
                    maxSum[1] = j;
                    maxSum[2] = sum;
                    maxSum[3] = 1;
                }
            }
        }
}
void collectSubsets() {
    for (int i = 0; i < N; ++i) //getting each subset's size
        for (int j = 0; j < M; ++j)
            ++subsetSize[subsets[i][j]];
    int maxN = 0;
    for (int i = 0; i < subsetN; ++i)
        maxN = max(subsetSize[i], maxN);
    cout << maxN << "\n";
}
void findSubsets(int subsetNum, const int x, const int y) {
    subsets[x][y] = subsetNum;
    int gate = 15 - castle[x][y]; //to find where there isn't a wall, if gate = 10 = 2+8, that means 1+4 has wall.
    for (int i = 3; gate != 0 && i >= 0; --i) {
        int dx = x, dy = y;
        if (gate - wallSerial[i] < 0)
            continue;
        gate -= wallSerial[i];
        switch (i) {
            case 0:
                dy = y - 1;
                break;
            case 1:
                dx = x - 1;
                break;
            case 2:
                dy = y + 1;
                break;
            case 3:
                dx = x + 1;
                break;
            default:
                break;
        }
        if (subsets[dx][dy] == -1)
            findSubsets(subsetNum, dx, dy);
    }
}
