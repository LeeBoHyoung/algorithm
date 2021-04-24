#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321;

int map[13][20]; //최대 크기
int ans;
int d, w, k;
bool checkMap() {
	int cnt;
	for (int i = 0; i < w; i++) {
		cnt = 1;
		for (int j = 1; j < d; j++) {
			if (map[j][i] == map[j - 1][i]) cnt++;
			else cnt = 1;
			if (cnt >= k) break;
		}
		if (cnt < k) return false;
	}
	return true;
}

void copyLine(int *a, int *b) {
	for (int i = 0; i < w; i++) {
		a[i] = b[i];
	}
}

void changeLine(int r, int med) {
	for(int i = 0; i < w; i++) {
		map[r][i] = med;
	}
}

void dfs(int r, int cnt) {
	if (cnt > ans) return;
	if (r >= d) {
		if (checkMap()) {
			ans = cnt;
		}
		return;
	}

	//약물 투여X
	dfs(r + 1, cnt);

	//약물투여A
	int tmp[20];
	copyLine(tmp, map[r]);
	changeLine(r, 0);
	dfs(r + 1, cnt + 1);
	copyLine(map[r], tmp);

	//약물 투여B
	copyLine(tmp, map[r]);
	changeLine(r, 1);
	dfs(r + 1, cnt + 1);
	copyLine(map[r], tmp);
}

int main() {
	int T;
	int testcase = 0;
	cin >> T;
	for (testcase = 0; testcase < T; testcase++) {
		ans = INF;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		dfs(0, 0);
		cout << "#" << testcase + 1 << " " << ans << endl;
	}
}