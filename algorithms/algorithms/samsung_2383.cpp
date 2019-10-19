//점심 식사시간
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ans = 987654321;
vector<vector<int>> dist;
int stairVal[2];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int cal(vector<int> v, int k) {
	vector<pair<int, int>> s1; vector<pair<int, int>> s2;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			s1.push_back(make_pair(i, dist[0][i]));
		}
		else {
			s2.push_back(make_pair(i, dist[1][i]));
		}
	}
	sort(s1.begin(), s1.end(), comp);
	sort(s2.begin(), s2.end(), comp);

	queue<int> fs; queue<int> ss; int max = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (fs.size() >= 3) {
			int diff = fs.front() - dist[0][s1[i].first] <= 0 ? 1 : fs.front() - dist[0][s1[i].first];
			max = dist[0][s1[i].first] + stairVal[0] + diff;
			fs.push(max);
			int front = fs.front();
			fs.pop();
		}
		else 
			fs.push(dist[0][s1[i].first] + stairVal[0] + 1 );
	}

	max = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (ss.size() >= 3) {
			int diff = ss.front() - dist[1][s2[i].first] <= 0 ? 1 : ss.front() - dist[1][s2[i].first];
			max = dist[1][s2[i].first] + stairVal[1] + diff;
			ss.push(max);
			int front = ss.front();
			ss.pop(); 
		}
		else
			ss.push(dist[1][s2[i].first] + stairVal[1] + 1);
	}
	if (fs.empty()) return ss.back();
	else if (ss.empty()) return fs.back();
	else
		return fs.back() > ss.back() ? fs.back() : ss.back();
}

void comb(vector<int> a, vector<int> t, int k) {
	if (t.size() == k) {
		int res = cal(t,k);
		if (res < ans) ans = res;
		return;
	}
	for (int i = 0; i < a.size(); i++) {
		t.push_back(a[i]);
		comb(a, t, k);
		t.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc; int n; int cnt; int idx;
	vector<pair<int, int>> person;
	vector<pair<int, int>> stair;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		cnt = 0; idx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int input;
				cin >> input;
				if (input == 1) {
					person.push_back(make_pair(i, j));
					cnt++;
				}
				else if (input >= 2) {
					stairVal[idx++]= input;
					stair.push_back(make_pair(i, j));
				}
			}
		}
		vector<int> tmp; int d;
		for (int i = 0; i < stair.size(); i++) {
			for (int j = 0; j < person.size(); j++) {
				d = abs(person[j].first - stair[i].first) + abs(person[j].second - stair[i].second);
				tmp.push_back(d);
			}
			dist.push_back(tmp);
			tmp.clear();
		}

		vector<int> a; a.push_back(0); a.push_back(1);
		comb(a, tmp, cnt);
		cout << "#" << t << " " << ans << endl;
	}
}