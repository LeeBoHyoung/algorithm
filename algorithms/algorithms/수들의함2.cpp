#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ret(vector<int> arr, int s) {
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		int sum = 0;
		for (int j = i; j < arr.size(); j++) {
			sum += arr[j];
			if (sum == s) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

int main() {
	int n, m;
	int k;
	cin >> n >> m;
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		cin >> k;
		tmp.push_back(k);
	}
	int ans = ret(tmp, m);
	cout << ans;
}