#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, H;
int graph[31][11][11] = { 0, };
bool visited[4000] = { false, };
bool res;
int ans=0;

void checkGraph(int n, int h, int s) {
	if (h > H) {
		if (n == s) res=true;
		return;
	}

	if (graph[h][n][n + 1] == 1) checkGraph(n + 1, h+1, s);
	else if (graph[h][n - 1][n] == 1) checkGraph(n - 1, h+1, s);
	else checkGraph(n, h + 1, s);
	
	
}

void selectLine(vector<pair<int, int>> line, vector<pair<int, int>> v, int s, int cnt) {
	if (v.size() == cnt) {
		int flag;
		for (int i = 0; i < cnt; i++) {
			graph[v[i].first][v[i].second][v[i].second + 1] = 1;
		}
		for (int i = 1; i <= N; i++) {
			res = false; flag = 0;
			checkGraph(i, 1, i);
			if (res) flag = 1;
			else break;
		}
		if (flag) ans = cnt;
		for (int i = 0; i < cnt; i++) {
			graph[v[i].first][v[i].second][v[i].second + 1] = 0;
		}
		return;
	}

	for (int i = s; i < line.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(make_pair(line[i].first, line[i].second));
			if (ans == cnt) return;
			selectLine(line, v, i, cnt);
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main() {
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b][b + 1] = 1;
	}
	
	vector<pair<int, int>> line;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (graph[i][j][j + 1] != 1 && graph[i][j-1][j] != 1 && graph[i][j+1][j + 2] != 1) {
				line.push_back(make_pair(i, j));
			}
		}
	}

	//더 안그려도 될 때
	int flag;
	for (int i = 1; i <= N; i++) {
		res = false; flag = 0;
		checkGraph(i, 1, i);
		if (res) flag = 1;
		else break;
	}
	if (flag){
		cout << ans << endl;
		return 0;
	}
	else {
		vector<pair<int, int>> tmp;
		for (int i = 1; i <= 3; i++) {
			selectLine(line, tmp, 0, i);
			if (ans != 0) break;
		}
	}
	if(ans==0) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}