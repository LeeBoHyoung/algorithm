#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321;

int map[13][20]; //�ִ� ũ��
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

	//�๰ ����X
	dfs(r + 1, cnt);

	//�๰����A
	int tmp[20];
	copyLine(tmp, map[r]);
	changeLine(r, 0);
	dfs(r + 1, cnt + 1);
	copyLine(map[r], tmp);

	//�๰ ����B
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