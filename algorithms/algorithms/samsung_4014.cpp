//»∞¡÷∑Œ
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int map[21][21];
int load[40][20];
int n, x;
int answer = 0;

void check() {
	bool v[20]; int flag;
	for (int i = 0; i < 2*n; i++) {
		memset(v, false, sizeof(v));
		flag = 0;
		for (int j = 0; j < n-1; j++) {
			if (load[i][j] == load[i][j + 1]) continue;
			if (abs(load[i][j + 1] - load[i][j]) > 1) {
				flag = 1;
				break;
			}
			else if (load[i][j + 1] - load[i][j] == 1) {
				for (int k = j; k > j - x + 1; k--) {
					if (k<1 || v[k] || v[k-1] || load[i][k] != load[i][k - 1]) {
						flag = 1;
						break;
					}
				}
			}
			else if (load[i][j + 1] - load[i][j] == -1) {
				for (int k = j + 1; k < j + x; k++) {
					if (k>=n-1 || load[i][k] != load[i][k + 1]) {
						flag = 1;
						break;
					}
					v[k] = true;
					v[k + 1] = true;
				}
				j = j + x-1;
				
			}
			if (flag == 1) break;
		}
		if (flag == 0) {
			cout << i + 1 << endl;
			answer++;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				load[i][j] = map[i][j];
				load[i + n][j] = map[j][i];
			}
		}
		
		check();

		printf("#%d %d", t, answer);
		answer = 0;
	}
	return 0;
}