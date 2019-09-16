#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int ans = 0;

void find_road(queue<int> road, queue<int> data, int L) {
	vector<int> tmp;
	for (int i = 0; i < data.size(); i++) {
		tmp.push_back(data.front());
		data.pop();
	}
	for (int i = 0; i < road.size(); i++) {
		int cnt = 0;
		int start = road.front();
		road.pop();
		if (abs(start - road.front()) > 1) {
			return;
		}
		else if (start - road.front() == 1) {
			int tmp_i = i;
			for (int j = tmp_i+1; j <= tmp_i + L; j++) {
				start = road.front();
				road.pop();
				if (start - road.front() != 0) return;
				i++;
			}
			i--;
		}
		else if (start - road.front() == -1) {
			if (i < L) return;
			for (int j = i-1; j >= i - L; j--) {
				if (start - tmp[j] != 0) return;
			}
		}
	}
	ans++;
}

int main() {
	int map[100][100];
	vector<queue<int>> road;
	int N; // 2<=N<=100;
	int L; // 1<=L<=N
	cin >> N;
	cin >> L;
	for (int i = 0; i < N; i++) {
		queue<int> row;
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			row.push(map[i][j]);
		}
		road.push_back(row);
	}
	
	for (int i = 0; i < N; i++) {
		queue<int> row;
		for (int j = 0; j < N; j++) {
			row.push(map[j][i]);
		}
		road.push_back(row);
	}

	for (int i = 0; i < road.size(); i++) {
		find_road(road[i], road[i], L);
	}
	
	cout << ans;
	return 0;
}

