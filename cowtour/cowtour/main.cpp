/*
 ID: tony1021
 PROG: cowtour
 LANG: C++
 */


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
int N;
double loc[150][2]; // (x,y) = (loc[i][0],loc[i][1])
char connection[150][150];
double optDist[150][150];
double far[150];

int main() {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> loc[i][0] >> loc[i][1];
    for (int i = 0; i < N; ++i) {
        scanf("%s", connection[i]);
        for (int j = 0; j < N; ++j) {
            if (connection[i][j] == '1')
                optDist[i][j] = optDist[j][i] = sqrt( (loc[i][0] - loc[j][0]) * (loc[i][0] - loc[j][0])
                    + (loc[i][1] - loc[j][1]) * (loc[i][1] - loc[j][1]) );
            else
                optDist[i][j] = -1;
        }
    }
    for (int i = 0; i < N; ++i)
        optDist[i][i] = 0;
    

    //Floyd algorithm
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (optDist[i][k] > -0.5 && optDist[k][j] > -0.5)
                    if (optDist[i][j] < -0.5 || optDist[i][j] > optDist[i][k] + optDist[k][j])
                        optDist[i][j] = optDist[i][k] + optDist[k][j];
            }
        }
    }
    
    //Finding the distance of the farthest reacheable pasture from particular pasture
    for (int i = 0; i < N; ++i) {
        double mDist = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j)
                continue;
            mDist = max(mDist, optDist[i][j]);
        }
        far[i] = mDist;
    }
    
    
    //Connecting pastures
    double md = 1e20;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (optDist[i][j] > -0.5 || i == j)
                continue;
            double newDiameter = far[i] + far[j]
                +sqrt( (loc[i][0] - loc[j][0]) * (loc[i][0] - loc[j][0])
                      + (loc[i][1] - loc[j][1]) * (loc[i][1] - loc[j][1]) );
            md = min(newDiameter, md);
        }
    }
    
    for (int i = 0; i < N; ++i)
        md = max(far[i], md);
    
    printf("%.6lf\n", md);
    
    return 0;
}

