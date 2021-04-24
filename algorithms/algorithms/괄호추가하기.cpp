#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long ans;
int n;
char v[20];

int calc(int a, int b, char oper) {
	int res = a;
	switch (oper)
	{
	case '+': res += b;
		break;
	case '-': res -= b;
		break;
	case '*': res *= b;
		break;
	}
	
	return res;
}

void recur(int idx, long long cur) {
	//종료조건
	if (idx > n - 1) {
		if (cur > ans) {
			ans = cur;
		}
		return;
	}

	char oper = (idx == 0) ? '+' : v[idx - 1];
	
	//괄호 추가할 때
	if (idx + 2 < n) {
		int val = calc(v[idx]-'0', v[idx + 2]-'0', v[idx + 1]);
		recur(idx + 4, calc(cur, val, oper));
	}

	//괄호 안할 때
	recur(idx + 2, calc(cur, v[idx]-'0', oper));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ans = -9999999;
	recur(0, 0);
	cout << ans;

}