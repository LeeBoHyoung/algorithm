//홈 방범 서비스
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;


int n, m;
int map[21][21];
int memo[22];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,1,-1 };
int MAX = -1;
void initMemo() {
	for (int i = 1; i <= 21; i++) {
		memo[i] = i * i + (i - 1) * (i - 1);
	}
}

void bfs(int sr, int sc) {
	bool v[21][21] = { false, };
	queue<tuple<int,int>> q;
	q.emplace(sr, sc);
	v[sr][sc] = true;
	int depth = 1; int qsize;
	int hcount = map[sr][sc] == 1 ? 1 : 0;
	while (!q.empty()) {
		qsize = q.size();

		if (memo[depth] <= hcount * m) {
			if (MAX < hcount) MAX = hcount;
		}


		if (depth == n + 1)
			return;

		while (qsize--) {
			int r, c;
			tie(r, c) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i]; int nc = c + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (v[nr][nc]) continue;
				v[nr][nc] = true;
				if (map[nr][nc] == 1) hcount++;
				q.emplace(nr, nc);
			}
		}
		depth++;
	}
}

int main() {
	initMemo();
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
 			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bfs(i, j);
			}
		}

		cout << "#" << t << " " << MAX << endl;
		MAX = -1;
	}
	
	return 0;
}