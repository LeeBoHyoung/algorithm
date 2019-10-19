//Å»ÁÖ¹ü °Ë°Å
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int map[51][51];
bool v[51][51] = { false, };
int n, m;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 }; //ºÏ µ¿ ³² ¼­

void bfs(int r, int c, int l) {
	int k = 0;
	queue<tuple<int, int, int>> q;
	q.emplace(r, c, k);
	while (!q.empty()) {
		int nr, nc, nk;
		tie(nr, nc, nk) = q.front();
		q.pop();
		if (nr < 0 || nr >= n || nc < 0 || nc >= m || nk == l)
			continue;
		if (v[nr][nc] || map[nr][nc] == 0) continue;
		v[nr][nc] = true;

		if (map[nr][nc] == 1) {
			for (int i = 0; i < 4; i++) {
				int offset = map[nr + dr[i]][nc + dc[i]];
				if (i == 0) {
					if(offset == 1 || offset == 2 || offset == 5 || offset == 6)
						q.emplace(nr + dr[i], nc + dc[i], nk + 1);
				}
				else if (i == 1) {
					if (offset == 1 || offset == 3 || offset == 6 || offset == 7)
						q.emplace(nr + dr[i], nc + dc[i], nk + 1);
				}
				else if (i == 2) {
					if (offset == 1 || offset == 2 || offset == 4 || offset == 7)
						q.emplace(nr + dr[i], nc + dc[i], nk + 1);
				}
				else if (i == 3) {
					if (offset == 1 || offset == 3 || offset == 4 || offset == 5)
						q.emplace(nr + dr[i], nc + dc[i], nk + 1);
				}
				
			}
		}
		else if (map[nr][nc] == 2) {
			int offset = map[nr + dr[0]][nc + dc[0]];
			if(offset == 1 || offset == 2 || offset == 5 || offset == 6)
				q.emplace(nr + dr[0], nc + dc[0], nk + 1);
			offset = map[nr + dr[2]][nc + dc[2]];
			if (offset == 1 || offset == 2 || offset == 4 || offset == 7)
				q.emplace(nr + dr[2], nc + dc[2], nk + 1);
		}

		else if (map[nr][nc] == 3) {
			int offset = map[nr + dr[1]][nc + dc[1]];
			if (offset == 1 || offset == 3 || offset == 6 || offset == 7)
				q.emplace(nr + dr[1], nc + dc[1], nk + 1);
			offset = map[nr + dr[3]][nc + dc[3]];
			if (offset == 1 || offset == 3 || offset == 4 || offset == 5)
				q.emplace(nr + dr[3], nc + dc[3], nk + 1);
		}
		else if (map[nr][nc] == 4) {
			int offset = map[nr + dr[0]][nc + dc[0]];
			if (offset == 1 || offset == 2 || offset == 5 || offset == 6)
				q.emplace(nr + dr[0], nc + dc[0], nk + 1);
			offset = map[nr + dr[1]][nc + dc[1]];
			if (offset == 1 || offset == 3 || offset == 6 || offset == 7)
				q.emplace(nr + dr[1], nc + dc[1], nk + 1);
		}
		else if (map[nr][nc] == 5) {
			int offset = map[nr + dr[1]][nc + dc[1]];
			if (offset == 1 || offset == 3 || offset == 6 || offset == 7)
				q.emplace(nr + dr[1], nc + dc[1], nk + 1);
			offset = map[nr + dr[2]][nc + dc[2]];
			if (offset == 1 || offset == 2 || offset == 4 || offset == 7)
				q.emplace(nr + dr[2], nc + dc[2], nk + 1);
		}
		else if (map[nr][nc] == 6) {
			int offset = map[nr + dr[3]][nc + dc[3]];
			if (offset == 1 || offset == 3 || offset == 4 || offset == 5)
				q.emplace(nr + dr[3], nc + dc[3], nk + 1);
			offset = map[nr + dr[2]][nc + dc[2]];
			if (offset == 1 || offset == 2 || offset == 4 || offset == 7)
				q.emplace(nr + dr[2], nc + dc[2], nk + 1);
		}
		else if (map[nr][nc] == 7) {
			int offset = map[nr + dr[0]][nc + dc[0]];
			if (offset == 1 || offset == 2 || offset == 5 || offset == 6)
				q.emplace(nr + dr[0], nc + dc[0], nk + 1);
			offset = map[nr + dr[3]][nc + dc[3]];
			if (offset == 1 || offset == 3 || offset == 4 || offset == 5)
				q.emplace(nr + dr[3], nc + dc[3], nk + 1);
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int ans = 0;
		cin >> n >> m;
		int r, c, l;
		cin >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}

		bfs(r, c, l);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] != 0)
					ans++;
			}
		}
		
		cout << "#" << k << " " << ans << endl;
		memset(v, false, sizeof(v));
	}
	return 0;
}

/*
#include <iostream>
#include <queue>
#include<string.h>

using namespace std;
int N, M, R, C, L;
int board[50][50];
int dist[50][50];
int pipe[8][4] = {
	{0,0,0,0},
	{1,1,1,1},
	{0,1,0,1},
	{1,0,1,0},
	{1,1,0,0},
	{1,0,0,1},
	{0,0,1,1},
	{0,1,1,0},
};
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans;
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
				dist[i][j] = -1;
			}
		}
		queue<pair<int, int> > q;
		q.push(make_pair(R, C));
		dist[R][C] = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
				if (dist[nx][ny] == -1 && pipe[board[x][y]][k] && pipe[board[nx][ny]][(k + 2) % 4]) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dist[i][j]!=-1 && dist[i][j] <= L)ans += 1;
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}
*/