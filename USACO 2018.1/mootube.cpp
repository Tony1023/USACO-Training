/*
	Author: Zhehao (Tony) Lu
	*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>
using namespace std;
#define num 100000
int N, Q;
int conn[num][num];
int rel[num][num];

void find(int start) {
	deque<int> next;
	memset(val, 0, sizeof(val));
	int visited = 0;
	int cur = start;
	while (visited < N) {
		for (int i = 0; i < N; ++i) {
			if (conn[cur][i] != 0) {
				
			}
		}
	}
}

int main() {
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");

	fin >> N >> Q;
	memset(conn, 0, sizeof(con));
	memset(rel, 0 ,sizeof(rel));
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		fin >> a >> b >> c;
		rel[a][b] = rel[b][a] = c;
	}
}