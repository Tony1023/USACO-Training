/*
 ID: tony1021
 PROG: dualpal
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> convert(int value, int base) {
    vector<int> ret;
    while (value > 0) {
        ret.push_back(value % base);
        value /= base;
    }
    return ret;
}

bool isPal(const vector<int> &value){
    unsigned long size = value.size();
    if (size == 1)
        return true;
    else if (*(--value.end()) == 0)
        return false;
    
    for (int i = 0; i < size; ++i) {
        if (value.at(i) != value.at(size - 1 - i)) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    
    int N, S;
    cin >> N >> S;
    while (N > 0) {
        ++S;
        for (int count = 0, base = 2; base <= 10; ++base) {
            vector<int> converted = convert(S, base);
            if (isPal(converted))
                ++count;
            if (count == 2) {
                cout << S << endl;
                --N;
                break;
            }
        }
    }
    
    
    
    return 0;
}
