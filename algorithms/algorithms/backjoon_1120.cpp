#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int cnt = 0;
	int idx = 0;
	int min = 51;
	int diff = b.length() - a.length();
	for (int i = 0; i <= diff; i++) {
		for (int j = i; j < a.length()+i; j++) {
			if (a[idx++] != b[j]) cnt++;
		}
		if (min > cnt) min = cnt;
		cnt = 0; idx = 0;
	}

	cout << min << endl;
	return 0;
}