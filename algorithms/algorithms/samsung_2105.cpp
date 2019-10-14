#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int map[21][21];
bool v[101];
int sr, sc;
int ans = 0;

int dr[4] = { -1, 1, 1, -1 };
int dc[4] = { 1,1,-1,-1 };
bool check_dir[4];
/*bool isSquare(vector<int> route) {
	int size = route.size(); int cnt = 0;
	for (int i = 0; i < size-1; i++) {
		if (route[i] != route[i + 1]) cnt++;
	}
	
	if (cnt == 4 || cnt == 3) {
		return true;
	}
	else 
		return false;
}*/

void dfs(int r, int c, int dir, int cnt) {
	
	if (dir != -1 && r == sr && c == sc) {
		if (ans < cnt) {
			ans = cnt;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (dir != -1 && check_dir[dir]) continue;

		if (dir == (i + 2) % 4) continue;

		int nr = r + dr[i]; int nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

		if (v[map[r][c]]) continue;

		v[map[r][c]] = true;
		if (dir != -1 && dir != i) check_dir[dir] = true;
		dfs(nr, nc, i, cnt+1);
		if(dir!=-1)check_dir[dir] = false;
		v[map[r][c]] = false;
	}
}

int main() {
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				memset(v, false, sizeof(v));
				memset(check_dir, false, sizeof(check_dir));
				sr = i; sc = j;
				dfs(sr, sc, -1, 0);
			}
		}
		
		if (ans == 0) ans = -1;
		cout << "#" << k + 1 << " " << ans << endl;
		ans = 0;
	}
	return 0;
}