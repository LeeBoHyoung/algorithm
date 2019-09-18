#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[500][500];
bool visited[500][500];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0. - 1 };
int N, M;
int ans = 0;

void go(int i, int j, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	if (i < 0 || i >= N || j < 0 || j >= N) return;
	if (visited[i][j]) return;
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		go(i + dr[k], j + dc[k], sum + map[i][j], cnt++);
	}
	visited[i][j] = false;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			go(i, j, 0, 0);

			if (j + 2 < M) {
				int temp = map[i][j] + map[i][j + 1] + map[i][j + 1];
				if (i + 1 < N) {
					if (temp + map[i + 1][j + 1] > ans) ans = temp + map[i + 1][j + 1];
				}
				if (i - 1 > 0) {
					if (temp + map[i - 1][j + 1] > ans) ans = temp + map[i - 1][j + 1];
				}
			}

			if (i + 2 < N) {
				int temp = map[i][j] + map[i + 1][j] + map[i + 2][j];
				if (j + 1 < M) {
					if (temp + map[i + 1][j + 1] > ans) ans = temp + map[i + 1][j + 1];
				}
				if (j - 1 > 0) {
					if (temp + map[i + 1][j - 1] > ans) ans = temp + map[i + 1][j - 1];
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}