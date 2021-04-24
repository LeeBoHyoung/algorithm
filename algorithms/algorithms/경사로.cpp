#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[101][101];
bool visited[101]; // 경사로 설치 위치
int ans;
int N, L;

void initV() {
	for (int i = 0; i< N; i++) {
		visited[i] = false;
	}
}
bool checkXRoad(int idx) {
	for (int i = 0; i < N-1; i++) {
		if (map[idx][i] == map[idx][i + 1]) continue;
		int diff = map[idx][i] - map[idx][i + 1];
		if (diff > 1 || diff < -1) return false;
		
		if (diff == 1) { // 내리막 경사로 설치
			for (int j = i + 1; j < i + L; j++) {
				if (j >= N) return false;
				if (map[idx][j] != map[idx][j + 1]) return false;
				visited[j] = true; visited[j + 1] = true;
			}
			visited[i+L] = true;
			i = i + L -1;
		}

		else { //오르막 경사로 설치
			for (int j = i; j > i - L; j--) {
				if (j < 0) return false;
				if (visited[j]) return false;
			}
		}
	}
	return true;
}

bool checkYRoad(int idx) {
	for (int i = 0; i < N - 1; i++) {
		if (map[i][idx] == map[i+1][idx]) continue;
		int diff = map[i][idx] - map[i+1][idx];
		if (diff > 1 || diff < -1) return false;

		if (diff == 1) { // 내리막 경사로 설치
			for (int j = i + 1; j < i + L; j++) {
				if (j >= N) return false;
				if (map[j][idx] != map[j+1][idx]) return false;
				visited[j] = true; visited[j + 1] = true;
			}
			visited[i + L] = true;
			i = i + L - 1;
		}
		else { //오르막 경사로 설치
			for (int j = i; j > i - L; j--) {
				if (j < 0) return false;
				if (visited[j]) return false;
				visited[j] = true;
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		initV();
		if (checkXRoad(i)) ans++;//행
		initV();
		if (checkYRoad(i)) ans++;//열
	}

	cout << ans << endl;
	
}