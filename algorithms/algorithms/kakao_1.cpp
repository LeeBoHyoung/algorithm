#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s = "abcabcabcabcdededededede";
	int answer = 0;
	vector<int> ans_list;
	string ans_str = "";
	int cnt = 0;
	int cnt2 = 1;
	for (int i = 2; i <= s.length(); i++) {
		vector<string> a;
		for (int k = 0; k < s.length() / i; k++) {
			a.push_back(s.substr(cnt, i));
			cnt = cnt + i;
		}

		for (int m = 0; m < a.size(); m++) {
			char start = a[m][0];
			string start_str = a[m];
			int flag = 0;
			for (int n = 0; n < i; n++) {
				if (start != a[m][n]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				ans_str.append(to_string(i) + start);
			}
			else {
				int tmp = m;
				for (int n = tmp+1; n < a.size(); n++) {
					if (start_str.compare(a[n]) == 0) {
						cnt2++;
						m = tmp + cnt2 - 1;
					}
					else {
						break;
					}
				}
					if (cnt2 != 1 && cnt2!=0) {
						ans_str.append(to_string(cnt2) + start_str);
					}
					else {
						ans_str.append(start_str);
					}
			}
			cnt2 = 1;
		}
		ans_str.append(s.substr(s.length() - s.length() % i, s.length() % i));
		//cout << ans_str + "\n";
		ans_list.push_back(ans_str.length());
		ans_str.clear();
		a.clear();
		cnt = 0;
		
	}	
	ans_list.push_back(s.length());
	answer = *min_element(ans_list.begin(), ans_list.end());
	return answer;
}