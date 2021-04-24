#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int map[8][8];
int tmp_map[8][8];
int v_blank[64] = { false, };
int n, m;
int ans=0;
int rdir[4] = { 0,0,-1,1 };
int cdir[4] = { 1,-1,0,0 };

void changeMap(vector<pair<int, int>> addWall) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < addWall.size(); i++) {
		tmp_map[addWall[i].first][addWall[i].second] = 1;
	}
}

void bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int r, c;
		tie(r, c) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + rdir[i];
			int nc = c + cdir[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (tmp_map[nr][nc] == 1 || tmp_map[nr][nc] == 2) continue;
			tmp_map[nr][nc] = 2;
			q.push(make_pair(nr, nc));

			
		}
	}

}

int countBlank() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_map[i][j] == 0) res++;
		}
	}
	return res;
}

void selectWall(vector<pair<int, int>> &blank, queue<pair<int,int>> q, vector<pair<int, int>> addWall, int s) {
	if (addWall.size() == 3) {
		changeMap(addWall);
		bfs(q);
		int cnt = countBlank();
		if (ans < cnt) ans = cnt;
		return;
	}

	for (int i = s; i < blank.size(); i++) {
		if (!v_blank[i]) {
			v_blank[i] = true;
			addWall.push_back(blank[i]);
			selectWall(blank, q, addWall, i);
			addWall.pop_back();
			v_blank[i] = false;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> blank;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) 
				blank.push_back(make_pair(i, j));
			else if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	vector<pair<int, int>> addWall;
	selectWall(blank, q, addWall, 0);
	
	cout << ans << endl;
}