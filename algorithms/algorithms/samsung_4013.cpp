//Åé´Ï¹ÙÄû
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define C 1
#define CW -1

int gear[4][8];

void rotate(int* ch) {
	for (int i = 0; i < 4; i++) {
		if (ch[i] == C) {
			int tmp = gear[i][7];
			for (int j = 7; j > 0; j--) {
				gear[i][j] = gear[i][j-1];
			}
			gear[i][0] = tmp;
		}
		else if (ch[i] == CW) {
			int tmp = gear[i][0];
			for (int j = 0; j < 7; j++) {
				gear[i][j] = gear[i][j+1];
			}
			gear[i][7] = tmp;
		}
	}
}

void change(int n, int d) {
	int ch[4] = { 0, };
	ch[n] = d; int dir = d;
	for (int i = n; i < 3; i++) {
		if (gear[i][2] != gear[i + 1][6]) {
			ch[i + 1] = -dir;
			dir = -dir;
		}
		else 
			break;
	}
	for (int i = n; i > 0; i--) {
		if (gear[i][6] != gear[i - 1][2]) {
			ch[i - 1] = -d;
			d = -d;
		}
		else
			break;
	}
	rotate(ch);
}

int main() {
	int tc;
	scanf("%d", &tc);
	int k, n, d;
	int answer = 0;
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &k); int i;
		for (i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &gear[i][j]);
			}
		}
		for (i = 0; i < k; i++) {
			scanf("%d%d", &n, &d);
			change(n-1, d);
		}

		for (i = 0; i < 4; i++) {
			answer += gear[i][0]*pow(2,i);
		}

		printf("#%d %d\n", t, answer);
		answer = 0;
	}

	return 0;
}
