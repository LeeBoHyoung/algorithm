#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int map[8][8];
int d[8][8];
int ans = 100;


void watch(int r, int c, int dir) {
	if (dir == 0) { //위
		for (int i = r; i >= 0; i--) {
			if (map[i][c] == 6)
				break;
			else
				d[i][c] = 1;
		}
	}
	else if (dir == 1) { //오
		for (int i = c; i < m; i++) {
			if (map[r][i] == 6)
				break;
			else
				d[r][i] = 1;
		}
	}
	else if (dir == 2) { //아
		for (int i = r; i < n; i++) {
			if (map[i][c] == 6)
				break;
			else
				d[i][c] = 1;
		}
	}
	else if (dir == 3) { //왼
		for (int i = c; i >= 0; i--) {
			if (map[r][i] == 6)
				break;
			else
				d[r][i] = 1;
		}
	}
}

void find(vector<pair<int, pair<int, int>>> cctv, int idx, vector<int> dirs) {
	if (idx == cctv.size()) {
		for (int i = 0; i < cctv.size(); i++) {
			int what, x, y;
			what = cctv[i].first; x = cctv[i].second.first; y = cctv[i].second.second;
			if (what == 1) {
				watch(x, y, dirs[i]);
			}
			else if (what == 2) {
				watch(x, y, dirs[i]);
				watch(x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 3) {
				watch(x, y, dirs[i]);
				watch(x, y, (dirs[i] + 1) % 4);
			}
			else if (what == 4) {
				watch(x, y, dirs[i]);
				watch(x, y, (dirs[i] + 1) % 4);
				watch(x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 5) {
				watch(x, y, dirs[i]);
				watch(x, y, (dirs[i] + 1) % 4);
				watch(x, y, (dirs[i] + 2) % 4);
				watch(x, y, (dirs[i] + 3) % 4);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (d[i][j] == 0)
					cnt++;
			}
		}
		if (ans > cnt) ans = cnt;
		
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 6) {
					d[i][j] = 2;
				}
			}
		}

		return;
	}

	
	for (int i = 0; i < 4; i++) {
		dirs[idx] = i;
		find(cctv, idx + 1, dirs);
	}
}

int main() {
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> cctv;
	vector<int> dirs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back(make_pair(map[i][j], make_pair(i, j))); // cctv 번호와 좌표를 저장
				dirs.push_back(0);
			}
			else if (map[i][j] == 6)
				d[i][j] = 2;
		}
	}

	find(cctv, 0, dirs);
	cout << ans << endl;
	return 0;
}