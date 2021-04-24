#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n, m, t;
int map[51][51];
int trans_map[51][51];
bool visited[51][51] = { false, };
bool flag = false;

void change_circle(int x, int d, int k) {
	for (int i = x; i <= n; i++) {
		if (i % x == 0) {
			for (int c = 0; c < k; c++) {
				if (d == 0) {
					int tmp = map[i][m];
					for (int j = m - 1; j >= 1; j--) {
						map[i][j + 1] = map[i][j];
					}
					map[i][1] = tmp;
				}
				else {
					int tmp = map[i][1];
					for (int j = 1; j < m; j++) {
						map[i][j] = map[i][j + 1];
					}
					map[i][m] = tmp;
				}
			}
		}
	}
}

void trans_map_init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			trans_map[i][j] = map[i][j];
			visited[i][j] = false;
		}
	}
}

void map_init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = trans_map[i][j];
		}
	}
}

void bfs(int row, int col) {
	queue<pair<int,int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;
	while (!q.empty()) {
		int r, c;
		tie(r, c) = q.front();
		q.pop();
		
		int dr[4] = { 1,-1,0,0 };
		int dc[4] = { 0,0,1,-1 };

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			if (map[nr][nc] == map[r][c] && visited[nr][nc] == false && map[r][c] != 0) {
				trans_map[r][c] = 0;
				trans_map[nr][nc] = 0;
				q.push(make_pair(nr, nc));
				visited[nr][nc] = true;
				flag = true;
			}
		}
	}
}

void num_change() {
	int sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (trans_map[i][j] != 0) {
				sum += trans_map[i][j];
				cnt++;
			}
		}
	}
	float avg = (float)sum / cnt;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (trans_map[i][j] != 0) {
				if (avg < trans_map[i][j])
					trans_map[i][j]--;
				else if (avg > trans_map[i][j])
					trans_map[i][j]++;
			}
		}
	}
}
int main() {
	int x, d, k;
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < t; i++) {
		flag = false;
		scanf("%d %d %d", &x, &d, &k);
		
		change_circle(x, d, k);	
		trans_map_init();
		
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (visited[j][k] == false) {
					bfs(j, k);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (map[j][1] == map[j][m] && map[j][1] !=0) {
				trans_map[j][1] = 0;
				trans_map[j][m] = 0;
				flag = true;
			}
		}
		
		if (flag == false) {

			num_change();
		}
		map_init();
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ret += map[i][j];
		}
	}

	printf("%d", ret);
}