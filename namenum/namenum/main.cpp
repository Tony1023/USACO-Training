/*
 ID: tony1021
 PROG: namenum
 LANG: C++11
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;
string serials;

void generateCd(string serial, const char dict[][3], vector<string> *ret) {
    if (serial.empty()) {
        return;
    }
    char lastChar = serial.at(serial.size() - 1);
    serial = serial.substr(0, serial.size() - 1);
    int num = lastChar - 48;
    generateCd(serial, dict, ret);
    vector<string> base(*ret);
    ret->clear();
    if (!base.empty()) {
        for (vector<string>::iterator it = base.begin(); it != base.end(); ++it) {
            for (int i = 0; i < 3; ++i) {
                ret->push_back( *it + dict[num][i] );
            }
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            string nextLett (1,dict[num][i]);
            ret->push_back(string(1, dict[num][i]));
        }
    }
    return;
}

bool binarySearch(const string target, const string dictionary[], const int size) {
    int lo = 0, hi = size, mid, cmp;
    while (lo < hi) {
        mid = ( lo + hi ) / 2;
        cmp = target.compare(dictionary[mid]);
        if (lo == mid || !cmp) {
            return !cmp;
        } else if (cmp < 0) {
            hi = mid;
        } else if (cmp > 0) {
            lo = mid;
        }
    }
    return false;
}

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    
    fstream loadDictionary;
    string *dictionary = new string[5000];
    loadDictionary.open("dict.txt");
    int i;
    for (i = 0; !loadDictionary.eof(); ++i)
        loadDictionary >> dictionary[i];
    --i;
    const char dict[10][3] = {' ',' ',' ',' ',' ',' ',
        'A','B','C',
        'D','E','F',
        'G','H','I',
        'J','K','L',
        'M','N','O',
        'P','R','S',
        'T','U','V',
        'W','X','Y'};
    char tmp[12];
    scanf("%s", tmp);
    serials = tmp;
    vector<string> candidate;
    generateCd(serials, dict, &candidate);
//    if(serial == "463373633623") cout << "out";
    bool exist = false;
    for (vector<string>::iterator it = candidate.begin(); it != candidate.end(); ++it) {
        if (binarySearch(*it, dictionary, i)) {
            cout << *it << "\n";
            exist = true;
        }
    }
    if (!exist) {
        cout << "NONE\n";
    }
    delete[] dictionary;
    return 0;
}
