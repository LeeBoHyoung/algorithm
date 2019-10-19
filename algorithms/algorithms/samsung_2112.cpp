//보호필름 - 완전탐색으로 풀 때
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define A 0
#define B 1

int d, w, k;
int ans = 98765432;
int f = 0;
int tk;

bool isRight(int map[][20]) {
	int cnt = 1; int flag;
	for (int i = 0; i < w; i++) {
		flag = 0;
		for (int j = 0; j < d-1; j++) {
			cnt = 1;
			for (int l = j + 1; l < d; l++) {
				if (map[j][i] == map[l][i]) cnt++;
				else break;
			}
			if (cnt >= k) {
				flag = 1;
				break;
			}
			else j += cnt-1;
		}
		if (flag == 0) {
			return false;
		}
	}
	return true;
}

void copyMap(int map1[][20], int map2[][20]) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			map1[i][j] = map2[i][j];
		}
	}
}

void change(int map[][20], int row, int m) {
	for (int i = 0; i < w; i++) {
		map[row][i] = m;
	}
}

void dfs(int map[][20], int row, int cnt) {
	int tmp_map[13][20];
	if (isRight(map)) {
		if (cnt < ans) ans = cnt;
		if (cnt == 0 || cnt == 1) f = 1;
		tk = cnt-1;
		return;
	}

	if (cnt >= tk) return;

	copyMap(tmp_map, map);
	for (int j = 0; j < 2; j++) {
		for (int i = row; i < d; i++) {
			change(map, i, j);
			dfs(map, row+1, cnt + 1);
			if (cnt > tk) return;
			if (f == 1) return;
			copyMap(map, tmp_map);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
    int map[13][20]; int tmp_map[13][20];
	for (int t = 1; t <= tc; t++) {
		cin >> d >> w >> k;
		tk = k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		if (k == 1 || isRight(map)) ans = 0;
		else dfs(map, 0, 0);
		
		cout << "#" << t << " " << ans << endl;
		f = 0; ans = 98765432;
	}

	return 0;
}