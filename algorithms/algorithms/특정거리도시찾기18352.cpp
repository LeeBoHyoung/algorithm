#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct NODE {
	int num;
	int dist;
};

int n, m, k, x;
vector<int> answer;
vector<vector<NODE>> city;
vector<bool> visited;
vector<int> dist;

void bfs() {
	queue<NODE> q;
	q.push(city[x][0]);
	
	while (!q.empty()) {

		NODE a = q.front();
		q.pop();
		visited[a.num] = true;

		for (int i = 0; i < city[a.num].size(); i++) {
			if (visited[city[a.num][i].num] == true) {
				continue;
			}

			visited[city[a.num][i].num] = true;
			dist[city[a.num][i].num] = dist[a.num] + 1;
			q.push(city[a.num][i]);
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &x);

	city.assign(n + 1, vector<NODE>(0));
	visited.assign(n+1, 0);
	dist.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		NODE node;
		node.num = i;
		node.dist = 0;
		city[i].push_back(node);
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		NODE node;
		node.num = b; node.dist = 0;

		city[a].push_back(node);
	
	}

	bfs();

	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		if (k == dist[i]) {
			printf("%d\n", i);
			flag = 0;
		}
	}
	if (flag == 1)
		printf("%d\n", -1);

}

