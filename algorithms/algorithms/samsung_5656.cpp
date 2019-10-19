#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n, w, h;
int res = 999;
int dr[4] = { 1,-1,0,0 }; //남 북 동 서
int dc[4] = { 0,0,1,-1 };
bool v[20][20] = { false, };
bool flag = false;

void eraseBlock(int map[20][20]) {
	vector<int> tmp;
	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < h; j++) {
			if (map[j][i] != 0) tmp.push_back(map[j][i]);
			map[j][i] = 0;
		}
		int size = tmp.size();
		if (size == 0) continue;
		for (int j = h - 1; j >= (h - size); j--) {
			map[j][i] = tmp.back(); tmp.pop_back();
		}
		tmp.clear();
	}
}

void bfs(int map[20][20], int r, int c) {

	queue<tuple<int, int>> q;
	q.emplace(r, c);
	while (!q.empty()) {
		int cr, cc;
		tie(cr, cc) = q.front();
		v[cr][cc] = true;
		q.pop();
		if (map[cr][cc] == 0 || map[cr][cc] == 1) {
			map[cr][cc] = 0; continue;
		}
		for (int k = 1; k < map[cr][cc]; k++) {
			for (int i = 0; i < 4; i++) {
				int nr = cr + dr[i] * k; int nc = cc + dc[i] * k;
				if (nr < 0 || nr >= h || nc < 1 || nc > w) continue;
				if (v[nr][nc]) continue;
				if (map[nr][nc] != 0) q.emplace(nr, nc);
			}
		}
		map[cr][cc] = 0;
	}
	memset(v, false, sizeof(v));
	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] != 0) {
				flag = true;
				break;
			}
		}
	}
}

void dfs(int map[20][20], int d, int count) {
	int tmp_m[20][20] = { 0, };

	if (count == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] != 0) cnt++;
			}
		}
		if (res > cnt) res = cnt;
		return;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= w; j++) {
			tmp_m[i][j] = map[i][j];
		}
	}

	for (int i = 1; i <= w; i++) {
		int r = -1, c = i;
		for (int j = 0; j < h; j++) {
			if (map[j][c] != 0) {
				r = j;
				break;
			}
		}
		if (r == -1) continue;
		bfs(map, r, c);

		if (flag == false) { //남은 벽돌 없을 떄
			res = 0;
			return;
		}

		eraseBlock(map);
		dfs(map, i, count + 1);
		if (flag == false) return;
		for (int j = 0; j < h; j++) {
			for (int k = 1; k <= w; k++) {
				map[j][k] = tmp_m[j][k];
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	int map[20][20] = { 0, }; int tmp[20][20] = { 0, };
	for (int t = 0; t < tc; t++) {
		memset(tmp, 0, sizeof(tmp));
		memset(map, 0, sizeof(map));
		cin >> n >> w >> h;
		int answer = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0) answer++;
			}
		}

		memset(v, false, sizeof(v));
		dfs(map, 0, 0);
		answer = res;

		cout << "#" << t + 1 << " " << answer << endl;
		res = 999; flag = false;
	}

	return 0;
}