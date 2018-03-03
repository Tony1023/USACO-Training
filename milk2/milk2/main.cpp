/*
 ID: tony1021
 PROG: milk2
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>  //for memset()
using namespace std;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    
    int N;
    bool isWorking[1000000];
    
    memset(isWorking, sizeof(isWorking), false);
    
    cin >> N;
    
    int start, end, terminate = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &start, &end);
        terminate = max(terminate, end);
        for (int j = start; j < end; ++j) {
            isWorking[j] = true;
        }
    }

    bool hasMilked = false;
    int maxMilking = 0, maxNotMilking = 0;
    start = 0;
    for (int i = 0; i <= terminate; ++i) {
        if (!hasMilked && !isWorking[i]) {  //has not started milking
            continue;
        }
        
        if (isWorking[i]) {
            if (isWorking[i - 1]) {  //has previously been milking, continue
                continue;
            } else {  //started milking
                if (hasMilked) {  //from not milking to milking
                    maxNotMilking = max(maxNotMilking, i - start);
                } else {  //first time to milk
                    hasMilked = true;
                }
                start = i;
            }
        } else {
            if (!isWorking[i - 1]) {  //has not been milking, continue
                continue;
            } else {  //just stop milking
                maxMilking = max(maxMilking, i - start);
                start = i;
            }
        }
    }
    
    cout << maxMilking << " " << maxNotMilking << endl;
    
    
    return 0;
}
