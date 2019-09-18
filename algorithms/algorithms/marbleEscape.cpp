#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char map[10][10];
int v[10][10];

pair<int, int> e;
int ans=99999;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void escape(pair<int,int> r, pair<int,int> b, int cnt) {
	int rr = r.first; int rc = r.second;
	int br = b.first; int bc = b.second;

	queue<pair<int,int>> rq; queue<pair<int,int>> bq;
	rq.push(make_pair(rr, rc));
	bq.push(make_pair(br, bc));

	v[rr][rc] = cnt;

	while (!rq.empty()) {
		rr = rq.front().first; rc = rq.front().second;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}

		rq.pop();
		
		for (int i = 0; i < 4; i++) {
			if (rr + dr[i] >= 0 && rr + dr[i] < n && rc + dc[i] >= 0 && rc + dc[i] < m) {
				if (map[rr + dr[i]][rc + dc[i]] == '.') {
					if (v[rr + dr[i]][rc + dc[i]] == -1) {
						int tmp_dr = dr[i]; int tmp_dc = dc[i];
						while (map[rr + tmp_dr][rc + tmp_dc] == '.') {
							v[rr + tmp_dr][rc + tmp_dc] = cnt + 1;
							tmp_dr += dr[i]; tmp_dc += dc[i];
							
						}
						int tmp_rr = rr + tmp_dr - dr[i]; int tmp_rc = rc + tmp_dc - dc[i];
						
						//v[rr][rc] = cnt + 1;
						cout << tmp_rr + dr[i] << tmp_rc + dc[i];
						if (map[tmp_rr+dr[i]][tmp_rc+dc[i]] == 'O') {
							cout << "answer";
							if (ans > cnt+1) ans = cnt+1;
						}
						rq.push(make_pair(tmp_rr, tmp_rc));
					}
				}
				else {
					if (map[rr + dr[i]][rc + dc[i]] == 'O') {
						if (ans > cnt+1) ans = cnt+1;
					}
				}
			}
		}
		cnt++;
	}

}

int main() {
	memset(v, -1, sizeof(v));
	pair<int, int> r;
	pair<int, int> b;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r.first = i; r.second = j;
			}
			if (map[i][j] == 'B') {
				b.first = i; b.second = j;
			}
			if (map[i][j] == 'O') {
				e.first = i; e.second = j;
			}
		}
	}

	escape(r, b, 0);

	if (ans != 99999)
		cout << ans << endl;
	else
		cout << -1 << endl;
	
	return 0;
}