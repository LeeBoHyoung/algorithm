#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<bool> visited;
vector<int> v;
void dfs(vector<int> arr) {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				v.push_back(arr[i]);
				dfs(arr);
				visited[i] = false;
				v.pop_back();
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<int> arr;

	visited = vector<bool>(n + 1, false);
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	dfs(arr);
}
