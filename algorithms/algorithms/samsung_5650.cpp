//«…∫º∞‘¿”
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
int dr[4] = { -1,0,1,0 }; //ªÛøÏ«œ¡¬
int dc[4] = { 0,1,0,-1 };

vector<vector<pair<int, int>>> worm(5);
int map[100][100];
int n;
int MAX = 0;

void go(int r, int c, int dir) {
	int d;
	int sr = r; int sc = c; int res = 0;
	while (1) {
		r += dr[dir]; c += dc[dir];
		if (r < 0 || r >= n || c < 0 || c >= n) {
			dir = (dir + 2) % 4;
			r += dr[dir]; c += dc[dir];
			res++;
		}
		if (r == sr && c == sc) {
			if (MAX < res) MAX = res;
			break;
		}
		if (map[r][c] == -1) {
			if (MAX < res) MAX = res;
			break;
		}
		else if (map[r][c] == 0) continue;
		else if (map[r][c] >= 6 && map[r][c] <= 10) {
			for (int i = 0; i < 2; i++) {
				if (worm[map[r][c] - 6][i].first != r || worm[map[r][c] - 6][i].second != c) {
					int wr; int wc;
					wr = worm[map[r][c] - 6][i].first;
					wc = worm[map[r][c] - 6][i].second;
					r = wr; c = wc;
					break;
				}
			}
		}
		else {
			dir = changeDir[dir][map[r][c] - 1];
			res++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc; int answer;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
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
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						go(i, j, k);
					}
				}
			}
		}

		cout << "#" << t << " " << MAX << endl;
		MAX = 0;
		for (int i = 0; i < 5; i++)
			worm[i].clear();
	}
	return 0;
}