#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
//int d[1000000];

long long min(int student, int b, int c) {
	if (student - b < 0)
		return 1;
	if ((student - b) % c == 0) {
		return (student - b) / c + 1;
	}
	else
		return (student - b) / c + 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int b, c;
	long long ans = 0;
	cin >> n;
	vector<int> student(n);
	for (int i = 0; i < n; i++) {
		cin >> student[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		long long res = min(student[i], b, c);
		ans += res;
	}
	cout << ans << endl;
	return 0;
	string a = "dmse";
	a.siz
}

