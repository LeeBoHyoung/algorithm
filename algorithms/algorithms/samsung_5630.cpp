#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int changeDir[4][5] = {
	2,1,3,2,2,
	3,3,2,0,3,
	1,0,0,3,0,
	0,2,1,1,1
};
int dr[4] = { -1,0,1,0 }; //»ó¿ìÇÏÁÂ
int dc[4] = { 0,1,0,-1 };

vector<vector<pair<int, int>>> worm(5);
int map[100][100];
int n;
int max = 0;

void go(int r, int c, int dir) {
	if (map[r][c] == -1) return;
	int sr = r; int sc = c; int res = 0;
	while (1) {
		r += dr[dir]; c += dc[dir];
		if (r == sr && c == sc) {
			if (max < res) = max = res;
			break;
		}
		if (map[r][c] == -1) {
			if (max < res) max = res;
			break;
		}
		else if (map[r][c] >= 6 && map[r][c] <= 10) {
			for (int i = 0; i < 2; i++) {
				if (worm[map[r][c] - 6][i].first != r || worm[map[r][c] - 6][i].second != c) {
					r = worm[map[r][c] - 6][i].first;
					c = worm[map[r][c] - 6][i].second;
					break;
				}
			}
		}
		else {
			dir = cdir[dir][map[i][j]];
			res++;
		}

	}
}

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc; int answer;
	for (int t = 1; t < tc; t++) {
		answer = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10)
					worm[map[i][j] - 6].push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					go(i, j, k);
				}
			}
		}

		cout << "#" << t << " " << max << endl;
		max = 0;
	}*/
	return 0;
}