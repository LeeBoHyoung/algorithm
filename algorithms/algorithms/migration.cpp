#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int map[50][50];
int map2[50][50];
int team[50][50];
int n;
int dir_r[4] = { -1, 0, 0, 1 };
int dir_c[4] = { 0, -1, 1, 0 };

void migration(int, int);
int main() {
	int l, r;
	cin >> n >> l >> r;
	if (!(n >= 1 && n <= 50 && l >= 1 && r >= 1 && l <= 100 && r <= 100)) {
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] < 1 && map[i][j] > 100) {
				cout << "1~100 사이의 값을 입력해주세요\n";
				exit(0);
			}
		}
	}

	
	int ans = 0;
	while (1) {
		int flag = 0;
		memset(team, 0, sizeof(team));
		migration(l, r);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << team[i][j];
			}
			cout << "\n";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (team[i][j] != 0)
					flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		else
			ans++;
	}
	cout << ans;
	return 0;
}

void migration(int l, int r) {

	int row = 0, col = 0;
	int flag = 0;
	vector<vector<pair<int, int>>> list;
	vector<pair<int, int>> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queue<pair<int,int>> xy;
			row = i, col = j;
			xy.push(make_pair(row, col));
			while (!xy.empty()) {
				row = xy.front().first;
				col = xy.front().second;
				xy.pop();
				for (int k = 0; k < 4; k++) {
					if (row + dir_r[k] >= 0 && row + dir_r[k] < n && col + dir_c[k] >= 0 && col + dir_c[k] < n) {
						if (abs(map[row][col] - map[row + dir_r[k]][col + dir_c[k]]) >= l && abs(map[row][col] - map[row + dir_r[k]][col + dir_c[k]]) <= r) {
							if (team[row + dir_r[k]][col + dir_c[k]] == 0) {
								//cout << row + dir_r[k] << "," << col + dir_c[k] << "\n";
								team[row+dir_r[k]][col+dir_c[k]] = 1;
								xy.push(make_pair(row + dir_r[k], col + dir_c[k]));
								tmp.push_back(make_pair(row + dir_r[k], col + dir_c[k]));
							}
						}
					}
				}
			}
			list.push_back(tmp);
			tmp.clear();
		}
	}

	int sum = 0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].size() > 0) {
			for (int j = 0; j < list[i].size(); j++) {
				sum += map[list[i][j].first][list[i][j].second];
			}
			sum = sum / list[i].size();
			for (int j = 0; j < list[i].size(); j++) {
				map[list[i][j].first][list[i][j].second] = sum;
			}
		}
		sum = 0;
	}
}