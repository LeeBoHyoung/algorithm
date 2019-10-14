#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string s;
	int len = 0;
	getline(cin, s);
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) flag = true;
		if (i == 0 && s[i] == ' ') continue;
		if (i == s.length() - 1 && s[i] == ' ') break;
		if (s[i] == ' ' && isalpha(s[i+1]))
			cnt++;
	}
	if(flag) cnt++;
	cout << cnt << endl;

	return 0;
}