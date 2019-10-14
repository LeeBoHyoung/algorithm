#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long toDecimal(string s) {
	long long res = 0; int exp = 0; int o;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9') {
			o = s[i] - '0';
			res += pow(16, exp) * o;
		}
		else {
			o = s[i] - 'A' + 10;
			res += pow(16, exp) * o;
		}
		exp++;
	}
	return res;
}

bool compare(string a, string b) {
	return a > b;
}

int main() {
	int t;
	int n, k;
	cin >> t;
	for (int c = 0; c < t; c++) {
		long long answer;
		cin >> n >> k;
		vector<string> ans;
		string s;
		cin >> s;
		int len = s.length() / 4;
		cout << s << endl;
		for (int i = 0; i < len; i++) {
			int idx = 0; string tmp;
			for (int j = 0; j < len; j++) {
				ans.push_back(s.substr(idx, len));
				idx += len;
			}
			tmp = s.back();
			s.pop_back();
			s = tmp + s;
			
		}
		sort(ans.begin(), ans.end(), compare);
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
		answer = toDecimal(ans[k-1]);
		
		cout << "#" << c + 1 << " " << answer << endl;
		ans.clear();
	}

	return 0;
}