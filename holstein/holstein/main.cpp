/*
 ID: tony1021
 PROG: holstein
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;
int V, G;
int rq[25], fd[15][25], solution[15];
bool feed(int,int,int);

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> V;
    for (int i = 0; i < V; ++i)
        cin >> rq[i];
    cin >> G;
    for (int i = 0; i < G; ++i)
        for (int j = 0; j < V; ++j)
            cin >> fd[i][j];
    for (int scoopNum = 1; scoopNum <= G; ++scoopNum) {
//        cout << scoopNum << ":\n";
        for (int first = 0; first <= G - scoopNum; ++first) {
            if (feed(scoopNum, scoopNum, first)) {
                cout << scoopNum;
                for (int i = 0; i < scoopNum; ++i)
                    cout << " " << solution[i] + 1;
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
bool feed(int scoopLeft, int scoopNum, int first) {
    if (scoopLeft == 0) {
        int vsum;
        for (int type = 0; type < V; ++type) {
            vsum = 0;
            for (int i = 0; i < scoopNum; ++i)
                vsum += fd[solution[i]][type];
//            cout << vsum << " ";
            if (vsum < rq[type]) {
//                cout << endl;
                return false;
            }
        }
//        cout << endl;
        return true;
    }
    //note down the scoop that is selected
    solution[scoopNum - scoopLeft] = first;
    for (int i = first; i < G; ++i)
        if (feed(scoopLeft - 1, scoopNum, i + 1))
            return true;
    return false;
}
