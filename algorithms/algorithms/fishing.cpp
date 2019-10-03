//시간 초과

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int a[101][101];
int rs, cs; //행,열 사이즈
int ans = 0;

tuple<int, int, int, int, int> move(int r, int c, int s, int d, int z) {
	tuple<int, int, int, int, int> tmp;
	if (d == 1 || d == 2) {
		s %= (2 * (rs-1));
		for (int i = 0; i < s; i++) {
			if (r > 1 && r < rs) {
				if (d == 1)
					r--;
				else
					r++;
			}
			else if (r == 1) {
				r++;
				d = 2;
			}
			else if (r == rs) {
				r--;
				d = 1;
			}
		}
	}
	else if (d == 3 || d == 4) {
		s %= (2 * (cs-1));
		for (int i = 0; i < s; i++) {
			if (c > 1 && c < cs) {
				if (d == 4)
					c--;
				else
					c++;
			}
			else if (c == 1) {
				c++;
				d = 3;
			}
			else if (c == cs) {
				c--;
				d = 4;
			}
		}
	}
	return make_tuple(r, c, s, d, z);
}

void fishing(vector<tuple<int, int, int, int, int>> shark, int p) {
	int cr = 0, cc = 0; //잡은 위치

	if (shark.size() == 0)
		return;
	if (p == cs + 1) //낚시꾼이 끝 땅에 도착
		return;
	for (int i = 1; i <= rs; i++) { //가장 가까운 상어 잡기
		if (a[i][p] != 0) {
			ans = ans + a[i][p];
			cr = i; cc = p;
			break;
		}
	}

	//상어 이동
	int r, c, s, d, z;
	int size = shark.size();
	vector<tuple<int, int, int, int, int>> next;
	for (int i = 0; i < size; i++) {
		int flag = 0;
		tie(r, c, s, d, z) = shark[i];
		if (r == cr && c == cc)
			continue;
		tuple<int, int, int, int, int> input = move(r, c, s, d, z);
		for (int j = 0; j < next.size(); j++) {
			if (get<0>(input) == get<0>(next[j]) && get<1>(input) == get<1>(next[j])) {
				flag = 1;
				if (get<4>(input) > get<4>(next[j]))
					next[j] = input;
				break;
			}
		}
		if (flag == 0) {
			next.push_back(input);
		}
		next.push_back(input);
	}

	memset(a, 0, sizeof(a));
	for (int i = 0; i < next.size(); i++) {
		int r = get<0>(next[i]), c = get<1>(next[i]), z = get<4>(next[i]);
		a[r][c] = z;
	}
	fishing(next, p + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(a, 0, sizeof(a));
	int r, c, s, d, z, m; //행,열,속도,방향,크기
	cin >> rs >> cs >> m;
	vector<tuple<int, int, int, int, int>> shark;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> s >> d >> z;
		shark.emplace_back(r, c, s, d, z);
		a[r][c] = z; //상어가 있는 위치에 상어의 크기 입력
	}

	fishing(shark, 1); // 상어, 낚시꾼 위치
	cout << ans;
	return 0;
}
