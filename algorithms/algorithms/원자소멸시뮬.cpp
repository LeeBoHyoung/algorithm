#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

struct Element
{
	//현재위치
	int idx;
	int x;
	int y; 
	int dir; //방향
	int power; //에너지
	bool active; // 생존/파괴 여부
};

tuple<int, int> move(int x, int y, int dir) {
	switch (dir)
	{
		case 0:
			return make_tuple(x, y-1);
		case 1:
			return make_tuple(x, y+1);
		case 2:
			return make_tuple(x - 1, y);
		case 3:
			return make_tuple(x + 1, y);
	}
}

int check(queue<Element> &q, Element e, int x, int y) {
	queue<Element> tmp = q;
	while (!tmp.empty()) {
		int tx, ty;
		Element te = tmp.front();
		tmp.pop();
		tx = te.x; ty = te.y;
		if (tx == x && ty == y) {
			if (te.dir + e.dir == 1 || te.dir + e.dir == 5) {
				return e.idx;
			}
		}
	}
	return 0;
}

int ans = 0;
int main() {
	int T, n;
	int idx = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		//algorithm
		cin >> n;
		queue<Element> elist;
		for (int j = 0; j < n; j++) {
			Element e;
			cin >> e.x >> e.y >> e.dir >> e.power;
			e.active = true; e.idx = idx++;
			elist.push(e);
		}

		vector<int> inactive;

		while (!elist.empty()) {
			inactive.clear();
			int size = elist.size();
			queue<Element> tmplist = elist;
			while (size > 0) {
				Element e = elist.front();
				elist.pop(); tmplist.pop(); size--;
				int nx, ny;
				tie(nx, ny) = move(e.x, e.y, e.dir);
				if (nx < -1000 || nx > 1000 || ny < -1000 || ny > 1000) continue;
				if (int res = check(tmplist, e, nx, ny)) {
					ans += e.power; // 0.5초 때 만나는 지점
					inactive.push_back(res);
					continue;
				}
				if (find(inactive.begin(), inactive.end(), e.idx) == inactive.end()) {
					ans += e.power;
					continue;
				}
				e.x = nx; e.y = ny;
				elist.push(e);
			}
			tmplist = elist;
			vector<tuple<int, int, int>> destory;
			vector<int> idxs;
			while (!tmplist.empty()) {
				Element te = tmplist.front();
				tmplist.pop();
				destory.push_back(make_tuple(te.idx, te.x, te.y));
			}
			for (int j = 0; j < destory.size(); j++) {
				for (int k = j + 1; k < destory.size(); k++) {
					if (get<1>(destory[k]) == get<1>(destory[j]) && get<2>(destory[k]) == get<2>(destory[j])) {
						idxs.push_back(get<0>(destory[k]));
						idxs.push_back(get<0>(destory[j]));
					}
				}
			}
			int s = elist.size();
			for (int j = 0; j < s; j++) {
				Element te = elist.front();
				elist.pop();
				if (find(idxs.begin(), idxs.end(), te.idx) == idxs.end()) {
					elist.push(te);
				}
				else
				{
					ans += te.power;
				}
			}
		}
		cout << "#" << i+1 << " " << ans << endl;
	}
	return 0;
}