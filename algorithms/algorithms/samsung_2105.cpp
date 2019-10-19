/*
//디저트 카페
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
}*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int map[100][100];
bool visit[101];
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,1,-1 };
bool dvisit[4];
int start_x;
int start_y;
int ans = -1;

void go(int x, int y, int dir, int cnt) {
	if (cnt != 0 && x == start_x && y == start_y) {
		if (ans < cnt) ans = cnt;
		cout << "cnt " << cnt << endl;
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
		if (dir == (k + 2) % 4) continue;
		if ((nx != start_x || ny != start_y) && visit[map[nx][ny]]) continue;
		if (dir!=-1 && dvisit[k]) continue;
		if (dir!=-1 && dir != k) dvisit[dir] = true;
		visit[map[nx][ny]] = true;
		cout << "좌표 " << nx << " " << ny << endl;
		cout << "before ";
		for(int i = 0;i <4;i++)
			cout << dvisit[i] << " ";
		cout << endl;
		go(nx, ny, k, cnt + 1);
		cout << "return " << x << " " << y << endl;
		if(dir!=-1)dvisit[dir] = false;
		/*이 부분 때문에 에러..
		시작지점 만나고 리턴된 다음 시작지점 visit도 false로 바꿔줘서 
		이 후로 돌 때 시작지점의 카페 번호도 접근할 수 있게 됨..
		그래서 리턴했을 때 dfs 갔다온 지점이 시작지점이랑 같으면 visit false로 안바꾸도록 하면 통과.
		*/
		if(map[start_x][start_y] != map[nx][ny]) visit[map[nx][ny]] = false;
		cout << "after ";
		for (int i = 0; i < 4; i++)
			cout  << dvisit[i] << " ";
		cout << endl;
	}
	return;
}

int main() {

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
					memset(visit, false, sizeof(visit));
					memset(dvisit, false, sizeof(dvisit));
					start_x = i;
					start_y = j;
					visit[map[i][j]] = true;
					cout << "start " << i << " " << j << endl;
					go(i, j, -1, 0);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		ans = -1;
	}
}