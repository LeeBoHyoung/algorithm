/*
조건
1. n*n 크기, 가장자리는 빨간셀
2. 빨간셀 도착하면 절반 죽고 이동방향 반대로
3. 미생물 수가 0이 되면 군집 사라짐
4. 두 개 이상 군집이 한 셀에 모이면 합쳐짐.
5. 합쳐진 군집 미생물 수는 미생물 수들의 합
6. 합쳐진 군집의 방향은 미생물이 가장많은 군집의 방향
7. 합쳐지는 군집 미생물 수 가 같은 경우 없음
M시간 후에 남아있는 미생물 수를 구하라
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

struct cluster
{
	int r, c;
	int num;
	int dir;
};
int n, m, k;
int dr[4] = { -1,1,0,0 }; //상하좌우
int dc[4] = { 0,0, -1, 1 };
int answer = 0;
int map[100][100] = { 0, };

bool comp2(cluster c1, cluster c2) {
	return c1.num > c2.num;
}
void bfs(vector<cluster> cts) {
	int time = 0;
	while (!cts.empty()) {
		memset(map, 0, sizeof(map));
		int size = cts.size();
		if (time == m) {
			for (int i = 0; i < size; i++) {
				answer += cts[i].num;
			}
			break;
		}
		while (size--) {
			int r = cts.back().r;
			int c = cts.back().c;
			int num = cts.back().num;
			int dir = cts.back().dir;
			cts.pop_back();
			cluster ct;
			int nr = r + dr[dir]; int nc = c + dc[dir];
			if (nr < 1 || nr >= n - 1 || nc < 1 || nc >= n - 1) {
				ct.r = nr; ct.c = nc; ct.num = num / 2;
				if (dir == 0) ct.dir = 1;
				else if (dir == 1) ct.dir = 0;
				else if (dir == 2) ct.dir = 3;
				else if (dir == 3) ct.dir = 2;
				if (ct.num == 0) continue;
			}
			else {
				ct.r = nr; ct.c = nc; ct.num = num; ct.dir = dir;
			}
			cts.insert(cts.begin(), 1, ct);
		}
		//같은 자리 찾기
		vector<cluster> tmp;
		sort(cts.begin(), cts.end(), comp2);
		for (int i = 0; i < cts.size(); i++) {
			if (map[cts[i].r][cts[i].c] != 0) {
				map[cts[i].r][cts[i].c] += cts[i].num;
				continue;
			}
			tmp.push_back(cts[i]);
			map[cts[i].r][cts[i].c] = cts[i].num;
		}
		for (int i = 0; i < tmp.size(); i++) {
			tmp[i].num = map[tmp[i].r][tmp[i].c];
		}

		cts.clear();
		cts.assign(tmp.begin(), tmp.end());
		time++;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		vector<cluster> cts;
		cin >> n >> m >> k;
		cluster ct;
		for (int i = 0; i < k; i++) {
			cin >> ct.r >> ct.c >> ct.num >> ct.dir;
			--ct.dir;
			cts.push_back(ct);
		}
		bfs(cts);

		cout << "#" << t << " " << answer << endl;
		answer = 0;
		cts.clear(); memset(map, 0, sizeof(map));
	}
	return 0;
}