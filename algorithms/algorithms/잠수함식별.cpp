/*
1) 시작이 100 일 때
- 100으로 시작하면 1로 끝
- 1 뒤에  0이 나올 때 00 인지 01 인지 확인

2) 시작이 01 일 때
- 그 다음이 0인지 1인지 확인
*/


#include <iostream>
#include <string>
using namespace std;

string identify(string num) {
	int size;
	while (1) {
		int idx = 0;
		size = num.length();
		if (num.substr(0, 3) == "100") {
			for (int i = 3; i < size; i++) {
				if (num[i] == '1') {
					idx = i;
					break;
				}
			}
			if (idx >= size) return "SUBMARINE";
			for (int i = idx; idx < size; idx++) {
				if (num[i] == '0') {
					idx = i;
					break;
				}
			}
			if (idx + 1 >= size) return "NOISE";
			else if (num[idx + 1] == '0') {
				num = num.substr(idx - 1, (size - idx - 1));
			}
			else if (num[idx + 1] == '1') {
				num = num.substr(idx, (size - idx));
			}
		}
		else if (num.substr(0, 2) == "01") {
			idx = 1;
			if (idx + 1 >= size) return "SUBMARINE";
			if (num[idx + 1] == '0' || num[idx + 1] == '1')
				num = num.substr(idx + 1, size - idx + 1);
		}
		else {
			return "NOISE";
		}
	}
	return "SUBMARINE";
}

int main() {
	string s;
	cin >> s;
	string ans = identify(s);
	cout << ans;
}