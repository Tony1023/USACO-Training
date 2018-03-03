/*
 ID: tony1021
 PROG: gift1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;

int main(int argc, const char * argv[]) {
    
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    
    int NP;
    cin >> NP;
    map<string, int> account;
    vector<string> nameList;
    string name;
    
    for (int i = 0; i < NP; ++i) {
        cin >> name;
        account.insert(std::make_pair(name, 0));
        nameList.push_back(name);
    }
    
    int n, balance;
    for (int i = 0; i < NP; ++i) {

        cin >> name;
        cin >> balance >> n;
        
        if (n == 0) {
            continue;
        }
        
        vector<string> receiver;
        string receiverName;
        for (int j = 0; j < n; ++j) {
            cin >> receiverName;
            receiver.push_back(receiverName);
        }
        
        account[name] += ( balance % n - balance );
        
        for (vector<string>::iterator iter = receiver.begin(); iter != receiver.end(); ++iter) {
            account[*iter] += balance / n;
        }
        
    }
    
    for (vector<string>::iterator iter = nameList.begin(); iter != nameList.end(); ++iter) {
        cout << *iter << " " << account[*iter] << "\n";
    }
    
    return 0;
    
}
