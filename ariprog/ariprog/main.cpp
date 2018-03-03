/*
 ID: tony1021
 PROG: ariprog
 LANG: C++
 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int N, M, MAX_a;
bool isBisquare2[125001];
bool found = false;
void searchIt(int, int);
void generateBisquare();

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    cin >> N >> M;
    MAX_a = M*M * 2;
    memset(isBisquare2, false, sizeof(isBisquare2));
    generateBisquare();
    searchIt(0, 1);
    if (!found)
        cout << "NONE\n";
    return 0;
}

void generateBisquare() {
    for (int p = 0; p <= M; ++p)
        for (int q = p; q <= M; ++q) {
            isBisquare2[p*p + q*q] = true;
        }
}
void searchIt(int a, int b) {
    if ( a + b * (N-1) > MAX_a)
        return;
    bool qualifier = true;
    for (int n = 0; n < N; ++n) {
        if (!isBisquare2[a + n*b]) {
            qualifier = false;
            break;
        }
    }
    if (qualifier){
        cout << a << " " << b << endl;
        found = true;
    }
    if ( (a+1) + b * (N-1) <= MAX_a)
        searchIt(a + 1, b);
    else if ( b * (N-1) <= MAX_a)
        searchIt(0, b + 1);
}
