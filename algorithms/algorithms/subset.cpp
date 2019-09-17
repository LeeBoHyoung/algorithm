#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> set;
vector<int> flag;
vector<int> answer;

void getSubset(int n, int depth, vector<int> subset) {
	if (n == depth) {
		int sum = 0; int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (flag[i]) { sum += subset[i]; cnt++; }
		}
		if (sum == 0) {
			answer.push_back(cnt);
		}
		return;
	}
	flag[depth] = 0;
	getSubset(n, depth + 1, subset);
	flag[depth] = 1;
	getSubset(n, depth + 1, subset);
}
int main() {
	cin >> N; int k;
	for (int i = 0; i < N; i++) {
		cin >> k;
		set.push_back(k);
	}

	int M,a,b;
	cin >> M; vector<int> subset;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = a - 1; j < b; j++) {
			subset.push_back(set[j]);
			flag.push_back(0);
		}
		getSubset(subset.size(), 0, subset);
		flag.clear(); subset.clear();

		cout << *max_element(answer.begin(), answer.end()) << endl;
		answer.clear();
	}
	

	return 0;
}