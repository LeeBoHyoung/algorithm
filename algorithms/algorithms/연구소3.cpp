#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct VIR {
	int r, c, time;
};

int n, m, ret;
int map[50][50];
int vir_size;
VIR vir[10];

int bfs(int pick[]) {
	queue<VIR> q;
	bool visited[50][50] = { false, };
	for (int i = 0; i < m; i++) {
		q.push(vir[pick[i]]);
		visited[vir[pick[i]].r][vir[pick[i]].c] = true;
	}
	
	int empty_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0)
				empty_cnt++;
		}
	}

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0,0,1,-1 };
	while(!q.empty()) {
		VIR cur = q.front();
		q.pop();

		if (map[cur.r][cur.c] == 0) {
			empty_cnt--;
		}
		if (empty_cnt == 0)
			return cur.time;

		for (int d = 0; d < 4; d++) {
			VIR next;
			next.r = cur.r + dr[d];
			next.c = cur.c + dc[d];
			next.time = cur.time + 1;

			if (next.r < 0 || next.r >= n || next.c < 0 || next.c >= n)
				continue;
			if (visited[next.r][next.c] == false && map[next.r][next.c] != 1) {
				q.push(next);
				visited[next.r][next.c] = true;
			}
		}
	}

	return 0x7ffffff;
}

void dfs(int last, int pick_cnt, int pick[]) {
	if (pick_cnt == m) {
		int candi = bfs(pick);
		if (ret > candi)
			ret = candi;
		return;
	}
	else {
		for (int i = last + 1; i < vir_size; i++) {
			pick[pick_cnt] = i;
			dfs(i, pick_cnt + 1, pick);
		}
	}
}
int main() {
	vir_size = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				vir[vir_size].r = i;
				vir[vir_size].c = j;
				vir[vir_size].time = 0;
				vir_size++;
			}
		}
	}

	int pick[10] = { 0, };

	ret = 0x7ffffff; // int maximum
	dfs(-1, 0, pick);
	if (ret == 0x7ffffff)
		printf("-1");
	else
		printf("%d", ret);

}
