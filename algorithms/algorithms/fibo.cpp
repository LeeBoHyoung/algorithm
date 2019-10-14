#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long answer = 0;
	vector<long long> d(N);
	d[0] = 1; d[1] = 1;
	for (int i = 2; i < N; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}
	cout << d[N - 1] << endl;
	answer = d[N - 1] * 2 + (d[N - 1] + d[N - 2]) * 2;
	cout << answer << endl;;
}