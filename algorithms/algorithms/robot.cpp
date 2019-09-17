#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct robot {
	int dir;
	int r;
	int c;
};


int n, m;
int map[50][50];
bool visited[50][50];
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 }; //ºÏ ¼­ ³² µ¿
int ans = 1;

pair<int, int> route(int dir, int r, int c) {
	int nr, nc;
	if (dir == 0) { // ºÏ
		nr = r + dr[1];
		nc = c + dc[1];
	}
	else if (dir == 1) { // µ¿
		nr = r + dr[0];
		nc = c + dc[0];
	}
	else if (dir == 2) { // ³²
		nr = r + dr[2];
		nc = c + dc[2];
	}
	else if (dir == 3) { // ¼­
		nr = r + dr[3];
		nc = c + dc[3];
	}
	return make_pair(nr, nc);
}

pair<int, int> direct(int dir, int r, int c) {
	if (dir == 0)
		return make_pair(r - 1, c);
	else if (dir == 1)
		return make_pair(r, c + 1);
	else if (dir == 2)
		return make_pair(r + 1, c);
	else if (dir == 3)
		return make_pair(r, c - 1);
}

int nr, nc;
void dfs(int r, int c, int dir) {
	visited[r][c] = true;
	pair<int, int> next;
	int check = 0;

	for (int i = 0; i < 4; i++) {
		//dir = (dir + i) % 4;
		next = route(dir, r, c);
		dir = (dir + 3) % 4;
		nr = next.first; nc = next.second;
		if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
			if (visited[nr][nc] == false && map[nr][nc] == 0) {
				check = 1;
				ans++;
				dfs(nr, nc, dir);
				return;
			}
		}
	}
	if (check == 0) {
		pair<int, int> back = direct((dir + 2) % 4, r, c);
		if (map[back.first][back.second] == 1 || !(back.first >= 0 && back.first < n && back.second >= 0 && back.second < m))
			return;
		else {
			dfs(back.first, back.second, dir);
		}
	}
}

int main() {
	robot init;
	cin >> n >> m;
	cin >> init.r;
	cin >> init.c;
	cin >> init.dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(init.r, init.c, init.dir);
	cout << ans;
}