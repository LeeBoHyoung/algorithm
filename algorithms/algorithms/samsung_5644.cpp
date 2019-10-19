//무선충전
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int map[9][11][11] = { 0, };
int dr[5] = { 0,-1,0,1,0 };
int dc[5] = { 0,0,1,0,-1 };
int m, bc; // 이동시간, bc 개수
int answer = 0;

void check(int ar, int ac, int br, int bcc) {
	int flag = 0; bool v[2] = { false, };
	for (int i = 0; i < bc; i++) {
		if (v[0] == true && v[1] == true) break;
		if (map[i][ar][ac] != 0 && map[i][br][bcc] != 0 && flag == 0) {
			int tmp = 0; int F = 0;
			for (int j = i + 1; j < bc; j++) {
				if (map[j][ar][ac] != 0) {
					tmp = map[j][ar][ac];
					F = 1; break;
				}
			}
			for (int j = i + 1; j < bc; j++) {
				if (map[j][br][bcc] > tmp) {
					tmp = map[j][br][bcc];
					F = 2; break;
				}
			}
			if (F == 0) answer += map[i][ar][ac];
			else if (F == 1) answer += tmp + map[i][br][bcc];
			else if (F == 2) answer += tmp + map[i][ar][ac];
			v[0] = true; v[1] = true;
		}
		else if (map[i][ar][ac] != 0 && v[0] == false) {
			answer += map[i][ar][ac]; v[0] = true;
			flag = 1;
		}
		else if (map[i][br][bcc] != 0 && v[1] == false) {
			answer += map[i][br][bcc]; v[1] = true;
			flag = 2;
		}
	}
}

void route(vector<int> a, vector<int> b) {
	int ar = 0, ac = 0, br = 9, bc = 9;
	check(ar, ac, br, bc);
	for (int i = 0; i < m; i++) {
		ar += dr[a[i]]; ac += dc[a[i]]; br += dr[b[i]]; bc += dc[b[i]];
		check(ar, ac, br, bc);
	}
}

void coverRange(vector<tuple<int, int, int, int>> input) {
	for (int n = 0; n < input.size(); n++) {
		int r = get<0>(input[n]); int c = get<1>(input[n]); int cover = get<2>(input[n]); int p = get<3>(input[n]);
		bool v[11][11] = { false, };
		queue<pair<int, int>> q;
		int cnt = 0;
		q.push(make_pair(r, c));
		v[r][c] = true;
		map[n][r][c] = p;
		while (!q.empty()) {
			int qsize = q.size();
			if (cnt == cover) break;
			while (qsize--) {
				int sr = q.front().first; int sc = q.front().second;
				q.pop();
				for (int i = 1; i <= 4; i++) {
					int nr = sr + dr[i]; int nc = sc + dc[i];
					if (nr < 0 || nr >= 10 || nc < 0 || nc >= 10) continue;
					if (v[nr][nc]) continue;
					v[nr][nc] = true;
					map[n][nr][nc] = p;
					q.push(make_pair(nr, nc));
				}
			}
			cnt++;
		}
	}
}

bool comp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<3>(a) > get<3>(b);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> m >> bc;
		vector<int> a(m);
		vector<int> b(m);
		vector<tuple<int, int, int, int>> input;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < bc; i++) {
			int r, c, cover, p;
			cin >> r >> c >> cover >> p;
			input.emplace_back(c - 1, r - 1, cover, p);
		}
		sort(input.begin(), input.end(), comp);
		coverRange(input);
		route(a, b);
		cout << "#" << t << " " << answer << endl;
		answer = 0;
		memset(map, 0, sizeof(map));
		a.clear(); b.clear(); input.clear();
	}

	return 0;
}