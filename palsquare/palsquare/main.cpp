/*
 ID: tony1021
 PROG: palsquare
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> convert(int, int);
bool isPal(const vector<int> &);

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int B;
    cin >> B;
    
    for (int N = 1; N <= 300; ++N) {
        vector<int> s = convert(N*N, B);
        if (isPal(s)) {
            vector<int> n = convert(N, B);
            for (int i = n.size() - 1; i >= 0; --i) {
                if (n.at(i) < 10)
                    cout << n.at(i);
                else {
                    char temp = n.at(i) + 55;
                    cout << temp;
                }
            }
            cout << " ";
            for (vector<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
                if (*iter < 10)
                    cout << *iter;
                else {
                    char temp = *iter + 55;
                    cout << temp;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}

vector<int> convert(int value, int base) {
    vector<int> ret;
    while (value > 0) {
        ret.push_back(value % base);
        value /= base;
    }
    return ret;
}
bool isPal(const vector<int> &value){
    int size = value.size();
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
