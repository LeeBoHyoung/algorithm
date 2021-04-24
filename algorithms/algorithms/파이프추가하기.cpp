#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[17][17]; //1 = 벽, 2 = 가로, 3 = 대각, 4 = 세로

int ans = 0;
int n;
int rdir[3] = { 0,1,1 };
int cdir[3] = { 1,1,0 };

void recur(int r, int c, int map[][17], bool visited[][17]) {
	if (map[r][c] == 3) {
		if (map[r - 1][c] == 1 || map[r][c - 1] == 1) return;
	}

	if (r == n && c == n) {
		ans++;
		return;
	}

	if (map[r][c] == 2) {
		for (int i = 0; i <= 1; i++) {
			if (r + rdir[i] > n || c + cdir[i] > n || map[r + rdir[i]][c + cdir[i]] == 1) continue;
			map[r + rdir[i]][c + cdir[i]] = i + 2;
			visited[r + rdir[i]][c + cdir[i]] = true;
			recur(r + rdir[i], c + cdir[i], map, visited);
			visited[r + rdir[i]][c + cdir[i]] = false;
			map[r + rdir[i]][c + cdir[i]] = 0;
		}
	}

	if (map[r][c] == 3) {
		for (int i = 0; i <= 2; i++) {
			if (r + rdir[i] > n || c + cdir[i] > n || map[r + rdir[i]][c + cdir[i]] == 1) continue;
			map[r + rdir[i]][c + cdir[i]] = i + 2;
			visited[r + rdir[i]][c + cdir[i]] = true;
			recur(r + rdir[i], c + cdir[i], map, visited);
			visited[r + rdir[i]][c + cdir[i]] = false;
			map[r + rdir[i]][c + cdir[i]] = 0;
		}
	}
	
	if (map[r][c] == 4) {
		for (int i = 1; i <= 2; i++) {
			if (r + rdir[i] > n || c + cdir[i] > n || map[r + rdir[i]][c + cdir[i]] == 1) continue;
			map[r + rdir[i]][c + cdir[i]] = i + 2;
			visited[r + rdir[i]][c + cdir[i]] = true;
			recur(r + rdir[i], c + cdir[i], map, visited);
			visited[r + rdir[i]][c + cdir[i]] = false;
			map[r + rdir[i]][c + cdir[i]] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	}
	
	bool visited[17][17] = { false, };
	visited[1][1] = true;
	visited[1][2] = true;
	map[1][2] = 2;

	recur(1, 2, map, visited);
	
	cout << ans;
}