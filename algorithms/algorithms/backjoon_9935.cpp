#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string bomb;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> bomb;
	int bsize = bomb.length();
	int idx = s.find(bomb);
	while (idx != -1) {
		s.erase(idx, bsize);
		if (idx - bsize > 0) idx = s.find(bomb, idx - bsize);
		else idx = s.find(bomb);
	}
	if (s == "") s = "FRULA";
	cout << s << endl;

	return 0;
}