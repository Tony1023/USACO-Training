/*
  ID: tony1021
  PROG: stamps
  LANG: C++
  */

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 2000001;
int K, N, stamps[50];
int sum[MAX]; //The number of stamps used summing to [j]

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	memset(sum, 0, sizeof(sum));
	cin >> K >> N;
	for (int i = 0; i < N; ++i) {
		cin >> stamps[i];
		sum[stamps[i]] = 1;
	}

	for (int i = 1; i <= MAX; ++i) {
		if (sum[i] == 0) {
			cout << i - 1 << endl;
			return 0;
		}
		for (int j = 0; j < N; ++j) {
			if (sum[i] == K)
				continue;
			if (sum[i + stamps[j]] == 0)
				sum[i + stamps[j]] = sum[i] + 1;
			else
				sum[i + stamps[j]] = min(sum[i + stamps[j]], sum[i] + 1);
		}
	}
	return 0;
}