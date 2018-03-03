/*
 ID: tony1021
 PROG: zerosum
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N, sign[10]; //the sign after the number [i] 0 thru N-1 only
char op[4] = {' ', '+', '-', '\n'};
void solve(int);
bool zeroSum();
void print();
typedef vector<int> V;
int quickPow[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin >> N;
    sign[N] = 3;
    solve(2);
    return 0;
}

void print() {
    for (int i = 1; i <= N; ++i)
        cout << i << op[sign[i]];
}
bool zeroSum() {
    V operands, operators;
    int startFig = 1;
    for (int i = 1; i <= N; ++i){
        if (sign[i] == 0)
            continue;
        else { // if a plus or minus is detected
            int operand = 0;
            for (int j = startFig; j <= i; ++j) {
                operand += j * quickPow[i - j];
            }
            operands.push_back(operand);
            operators.push_back(sign[i]);
            startFig = i + 1;
//            cout << operand << op[sign[i]];
        }
    }
    int firstFig = operands[0], size = operands.size();
    for (int i = 1; i < size; ++i) {
        switch (operators.at(i - 1)) {
            case 1:
                firstFig += operands.at(i);
                break;
            case 2:
                firstFig -= operands.at(i);
                break;
        }
    }
    return (firstFig == 0);
}
void solve(int num) {
    if (num == N + 1) {
        if (zeroSum())
            print();
        return;
    }
    for (int i = 0; i < 3; ++i) {
        sign[num - 1] = i;
        solve(num + 1);
    }
}
