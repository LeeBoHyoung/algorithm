#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int p, q, k, ans;
int a[1000][1000];
int arr[101][101] = { 0, };

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void dfs(int r, int c, int res) {
	int len = 0; int max = 0;
	vector<pair<int, int>> v;//정렬할 페어
	
	if (a[p-1][q-1] == k) { //정답 찾기
		ans = res;
		return;
	}
	if (res > 100) { // 시간이 100을 넘어가면 -1 반환
		ans = -1;
		return;
	}
	if (r > 100 || c > 100) { // 열과 행이 100을 넘어가면 100까지만 자르고 다시 작동
		if (r > 100 && c <= 100)
			dfs(100, c, res + 1);
		else if (r <= 100 && c > 100)
			dfs(r, 100, res + 1);
		else if (r > 100 && c > 100)
			dfs(100, 100, res + 1);
		return;
	}

	if (r >= c) { // 행 개수가 열보다 클 때
		for (int i = 0; i < r; i++) { // 숫자 카운트
			for (int j = 0; j < c; j++) {
				arr[i][a[i][j]]++;
			}
		}
		memset(a, 0, sizeof(a));
		for(int i = 0;i<r;i++){ //(숫자, 개수) vector pair 저장
			for (int j = 1; j <= 100; j++) {
				if (arr[i][j] != 0) {
					v.push_back(make_pair(j, arr[i][j]));
				}
			}
			sort(v.begin(), v.end(), compare); // 정렬
			for (int j = 0; j < v.size(); j++) { // 정렬된 배열 삽입
				a[i][len] = v[j].first;
				a[i][len+1] = v[j].second;
				len = len + 2;
			}
			if (max < len) max = len;
			v.clear();
			len = 0;
		}
		memset(arr, 0, sizeof(arr));
		dfs(r, max, res + 1);
	}
	else { //열 개수가 행 개수보다 클 때
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				arr[i][a[j][i]]++;
			}
		}

		memset(a, 0, sizeof(a));
		for(int i = 0;i<c;i++){
			for (int j = 1; j <= 100; j++) {
				if (arr[i][j] != 0) {
					v.push_back(make_pair(j, arr[i][j]));
				}
			}
			sort(v.begin(), v.end(), compare);
			for (int j = 0; j < v.size(); j++) {
				a[len][i] = v[j].first;
				a[len+1][i] = v[j].second;
				len = len + 2;
			}
			if (max < len) max = len;
			v.clear();
			len = 0;
		}
		memset(arr, 0, sizeof(arr));
		dfs(max, c, res + 1);
	}
}

int main() {
	cin >> p >> q >> k;
	if (k < 1 || k>100 || p < 1 || p > 100 || q < 1 || q > 100)
		return 0;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	dfs(3, 3, 0);

	cout << ans;
	return 0;
}