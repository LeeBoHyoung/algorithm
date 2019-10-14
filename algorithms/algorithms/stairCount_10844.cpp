#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long ans = 0;
	vector<long long> d(N+1);
	long long s[101][10] = { 0, };
	s[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		s[1][i] = 1;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j > 0) {
				s[i][j] += s[i - 1][j - 1];
			}
			if (j < 9) {
				s[i][j] += s[i - 1][j + 1];
			}
			s[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++) {
		ans += s[N][i];
	}
	ans %= 1000000000;
	cout << ans << endl;
}


