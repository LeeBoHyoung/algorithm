#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> ans;
int v[11];
int operation(int a, int b, char oper) {
	if (oper == '+')
		return a + b;
	else if (oper == '-')
		return a - b;
	else if (oper == '*')
		return a * b;
	else
		return a / b;
}

void calc(vector<int> a, vector<char> oper) {
	int res = operation(a[0], a[1], oper[0]);
	int j = 1;
	for (int i = 2; i < a.size(); i++) {
		if (j < oper.size()) {
			res = operation(res, a[i], oper[j++]);
		}
	}
	ans.push_back(res);
}

void brute(vector<int> a, vector<char> oper, vector<char> tmp, int c) {
	if (tmp.size() == c) {
		calc(a, tmp);
		return;
	}
	else {
		for (int i = 0; i < oper.size(); i++) {
			if (v[i] == false) {
				v[i] = true;
				tmp.push_back(oper[i]);
				brute(a, oper, tmp, c);
				v[i] = false;
				tmp.pop_back();
			}
		}
	}
}

int main() {
	memset(v, false, sizeof(v));
	cin >> n;
	vector<int> a(n);
	vector<char> oper;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			if (i == 0)
				oper.push_back('+');
			else if (i == 1)
				oper.push_back('-');
			else if (i == 2)
				oper.push_back('*');
			else
				oper.push_back('/');
		}
	}
	vector<char> tmp;
	brute(a, oper, tmp, n-1);

	int max = *max_element(ans.begin(), ans.end());
	int min = *min_element(ans.begin(), ans.end());

	cout << max << endl;
	cout << min << endl;
}