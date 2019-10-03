//등산로 조정
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int map[8][8];
int map_tmp[8][8];
bool v[8][8];
int n, k;
int ans = 0;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
int rk = -1, ck=-1; //조정된 좌표

void dfs(int r, int c, int pr, int pc, int res) {
	int temp;
	if (r < 0 || r >= n || c < 0 || c >= n)
		return;
	if (res != 0) {
		if (map_tmp[pr][pc] <= map_tmp[r][c]) { //큰 값을 만났을 때
			if (rk == -1 && ck == -1) { // 조정 사용 여부
				rk = pr; ck = pc;
				if (k >= map_tmp[r][c] - map_tmp[pr][pc] + 1)
					temp = map_tmp[r][c] - (map_tmp[r][c] - map_tmp[pr][pc] + 1);
				else
					temp = map_tmp[r][c] - k;
				map_tmp[r][c] = temp;
				if (map_tmp[pr][pc] <= temp) {
					if (ans < res) ans = res;
					return;
				}
			}
			else {
				if (ans < res) ans = res;
				return;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (v[r][c] == false) {
			v[r][c] = true;
			dfs(r + dr[i], c + dc[i], r, c, res + 1);
			v[r][c] = false;
			if (r == rk && c == ck) {
				rk = -1; ck = -1;
				map_tmp[r + dr[i]][c + dc[i]] = map[r + dr[i]][c + dc[i]];
			}
		}
	}
	
}
int main() {
	int t;
	cin >> t;
	memset(v, false, sizeof(v));
	for(int p = 1;p<=t;p++) {
		cin >> n >> k;
		int max = 0;
		vector<pair<int, int>> top;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				map_tmp[i][j] = map[i][j];
				if (map[i][j] > max) max = map[i][j];
			}
		}

		//산봉우리 좌표 찾기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max == map[i][j]) {
					top.push_back(make_pair(i,j));
				}
			}
		}

		for (int i = 0; i < top.size(); i++) {
			dfs(top[i].first, top[i].second, 0,0,0);
			memset(v, false, sizeof(v));
			memcpy(map_tmp, map, sizeof(map));
			rk = -1; ck = -1;
		}

		cout << "#" << p << " " << ans << endl;
		ans = 0;
		top.clear();
	}
}
