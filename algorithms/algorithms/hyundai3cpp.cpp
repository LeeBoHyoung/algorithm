#include <iostream>
#include <vector>
#include <algorithms>
using namespace std;

int map[4][4];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0,0,1,-1 };
int res = 0;

void dfs(int[][4] v, int r, int c, int cnt) {
	int nr, nc;
	v[r][c] = true;
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i]; nc = c + dc[i];
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
		if (v[nr][nc]) continue;
		dfs(nr, nc, cnt + 1);
	}
	if (res < cnt) res = cnt;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
	}

	int max = -1;
	bool v[4][4] = { false, };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dfs(v, i, j, 1);
			if (max < res) max = res;
			res = 0; 
		}
	}
	if (max == 1) max = -1;
	cout << max << endl;
}