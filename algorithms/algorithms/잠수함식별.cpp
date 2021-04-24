/*
1) ������ 100 �� ��
- 100���� �����ϸ� 1�� ��
- 1 �ڿ�  0�� ���� �� 00 ���� 01 ���� Ȯ��

2) ������ 01 �� ��
- �� ������ 0���� 1���� Ȯ��
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