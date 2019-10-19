//줄기세포 배양
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ACTIVE 1
#define INACTIVE 0
#define DEAD -1

struct cell {
	int r, c;
	int time;
	int state;
	int original_time;
	int dead_time;
};
int n, m, k;
vector<cell> v;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
int tmp_r=0, tmp_c=0;
cell map[1000][1000];
bool visit[1000][1000] = { false, };

bool comp2(cell a, cell b) {
	return a.original_time < b.original_time;
}
void spread(){
	vector<cell> nonDead;
	for (int i = 1; i <= k; i++) {
		int size = v.size();
		for (int j = 0; j < size; j++) {
			if (v[j].state != DEAD) nonDead.push_back(v[j]);
		}
		v.clear();
		v = nonDead; size = v.size(); nonDead.clear();
		sort(v.begin(), v.end(), comp2);

		while (size--) {
			cell cl = v[size];
			if (cl.time == i && cl.state == INACTIVE) {
				v[size].time += 1; v[size].state = ACTIVE;
			}
			else {
				if (visit[cl.r][cl.c] == false && cl.state == ACTIVE) {
					visit[cl.r][cl.c] = true;
					for (int d = 0; d < 4; d++) {
						int nr = cl.r + dr[d]; int nc = cl.c + dc[d];
						if (map[nr][nc].original_time != 0) continue;
						
						cell cl2;
						cl2.r = nr; cl2.c = nc;
						cl2.state = INACTIVE;
						cl2.original_time = cl.original_time;
						cl2.time = cl2.original_time + i;
						cl2.dead_time = i + cl.original_time * 2;
						map[nr][nc] = cl2;

						v.push_back(cl2);
					}
				}
			}
			if (cl.dead_time == i && cl.state == ACTIVE) {
				v[size].state = DEAD;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	int ans;
	for (int t = 1; t <= tc; t++) {
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		scanf("%d%d%d", &n, &m, &k);
		cell cl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int hp;
				scanf("%d", &hp);
				if (hp != 0) {
					cl.r = 500 - n/2 + i; cl.c = 500 - n/2 + j; cl.state = INACTIVE; cl.time = hp; cl.original_time = hp; cl.dead_time = hp*2;
					v.push_back(cl);
					map[cl.r][cl.c] = cl;
				}
			}
		}
		spread();
		for (int i = 0; i < v.size(); i++) {
			if (v[i].state != DEAD) ans++;
		}
		printf("#%d %d\n", t, ans);
		v.clear(); 
	}
	return 0;
}