#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
int map[50][50];
int d[50][50];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int ans = 9999999;
bool visited[10];
bool check[50][50];
vector<vector<pair<int, int>>> cases;


void activeVirus(vector<pair<int,int>> virus, vector<pair<int, int>> active, int m, int s) {
	if (active.size() == m) {
		cases.push_back(active);
		return;
	}
	else {
		for (int i = s; i < virus.size(); i++) {
			if (!visited[i]) {
				visited[i] = true;
				active.push_back(virus[i]);
				activeVirus(virus, active, m, i);
				visited[i] = false;
				active.pop_back();
			}
		}
	}
}

int bfs(vector<pair<int, int>> virus) {
	int ans = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		check[virus[i].first][virus[i].second] = true;
	}
	
	while (!q.empty()) {
		int r, c;
		tie(r, c) = q.front();
		check[r][c] = true;
		//cout << r << "," << c << endl;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k], nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (check[nr][nc] == true) continue;
			if (map[nr][nc] == 2) {
				int flag = 0;
				for (int i = 0; i < 4; i++) {
					if (!check[nr + dr[i]][nc + dc[i]] && (nr + dr[i] >= 0 && nr + dr[i] < n && nc + dc[i] >= 0 && nc + dc[i] < n))
						flag = 1;
				}
				if (flag == 0) {
					check[nr][nc] = true;
					continue;
				}
				d[nr][nc] = d[r][c] + 1;
				check[nr][nc] = true;
				q.push(make_pair(nr, nc));
				continue;
			}
			d[nr][nc] = d[r][c] + 1;
			check[nr][nc] = true;
			q.push(make_pair(nr, nc));


		}
	}
	/*for (int i = 0; i < virus.size(); i++) {
		cout << virus[i].first << virus[i].second << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				ans = -1;
				return ans;
			}

			if (d[i][j] > ans) {
				ans = d[i][j];
			}
		}
	}

	return ans;
}

int main() {
	memset(check, false, sizeof(check));
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			if (map[i][j] == 1) {
				check[i][j] = true;
			}
		}
	}
	
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		ans = 0;
		cout << ans << endl;
		return 0;
	}

	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> active;
	activeVirus(virus, active, m, 0);
	flag = 0;
	for (int i = 0; i < cases.size(); i++) {
		int res = bfs(cases[i]);
		if (res != -1) {
			flag = 1;
			if (ans == -1) ans = res;
			else {
				if (ans > res) ans = res;
			}
		}
		else
			if(flag == 0)
				ans = -1;

		memset(d, 0, sizeof(d));
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					check[i][j] = true;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}