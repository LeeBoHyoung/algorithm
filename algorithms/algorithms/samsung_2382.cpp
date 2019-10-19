/*
����
1. n*n ũ��, �����ڸ��� ������
2. ������ �����ϸ� ���� �װ� �̵����� �ݴ��
3. �̻��� ���� 0�� �Ǹ� ���� �����
4. �� �� �̻� ������ �� ���� ���̸� ������.
5. ������ ���� �̻��� ���� �̻��� ������ ��
6. ������ ������ ������ �̻����� ���帹�� ������ ����
7. �������� ���� �̻��� �� �� ���� ��� ����
M�ð� �Ŀ� �����ִ� �̻��� ���� ���϶�
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
int dr[4] = { -1,1,0,0 }; //�����¿�
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
		//���� �ڸ� ã��
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