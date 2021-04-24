#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[20][20];
bool visited[20] = { false, };
int N;
int ans = 987654321;
int t = 0;

int countAblity(vector<int> v) {
	int start = 0, link = 0;
	vector<int> tmp;

	for (int i = 0; i < N; i++) {
		if (find(v.begin(), v.end(), i) == v.end()) {
			tmp.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i] == v[j]) continue;
			start += map[v[i]][v[j]];
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[i] == tmp[j]) continue;
			link += map[tmp[i]][tmp[j]];
		}
	}
	
	return abs(start - link);
}

void dfs(vector<int> v, vector<int> idx, int s, int comb) {
	if (t == comb / 2) return;
	if (v.size() == N / 2) {
		int cnt = countAblity(v);
		if (cnt < ans) ans = cnt;
		t++;
		return;
	}
	for (int i = s; i < idx.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(idx[i]);
			dfs(v, idx, i,comb);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	vector<int> idx;
	for (int i = 0; i < N; i++) {
		idx.push_back(i);
	}
	int x=1, y=1, comb;
	for (int i = 1; i <= N; i++) {
		x = x * i;
	}
	for (int i = 1; i <= N / 2; i++) {
		y = y * i;
	}
	y = y * y;
	comb = x / y;
	
	vector<int> v;
	dfs(v,idx, 0, comb);

	cout << ans << endl;
}