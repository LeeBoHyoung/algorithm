/*
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> 
//
//const int board[33][6] =
//{ {0,1,2,3,4,5}, {2,2,3,4,5,6}, {4,3,4,5,6,7}, {6,4,5,6,7,8}, {8,5,6,7,8,9}, {10,21,22,23,24,25}, {12,7,8,9,10,11}, {14,8,9,10,11,12}, {16,9,10,11,12,13}, {18,10,11,12,13,14}, {20,27,28,24,25,26}, {22,12,13,14,15,16}, {24,13,14,15,16,17}, {26,14,15,16,17,18}, {28,15,16,17,18,19}, {30,29,30,31,24,25}, {32,17,18,19,20,32}, {34,18,19,20,32,32}, {36,19,20,32,32,32}, {38,20,32,32,32,32}, {40,32,32,32,32,32}, {13,22,23,24,25,26}, {16,23,24,25,26,20}, {19,24,25,26,20,32}, {25,25,26,20,32,32}, {30,26,20,32,32,32}, {35,20,32,32,32,32}, {22,28,24,25,26,20}, {24,24,25,26,20,32}, {28,30,31,24,25,26}, {27,31,24,25,26,20}, {26,24,25,26,20,32}, {0,32,32,32,32,32} };
//
//int in[10];
//int get_score(int state) { int ret = 0; bool visited[33] = { false, }; int pos[4] = { 0, }; for (int turn = 0; turn < 10; ++turn) { int move = in[turn]; int horse = (state >> (turn * 2)) & 0x03; int cur_pos = pos[horse]; int next_pos = board[cur_pos][move]; int add_score = board[next_pos][0]; if (visited[next_pos] && next_pos != 32) { return -1; } ret += add_score; visited[cur_pos] = false; visited[next_pos] = true; cur_pos = next_pos; pos[horse] = next_pos; } return ret; } int main() { for (int i = 0; i < 10; ++i) { scanf("%d", &in[i]); } int result = 0; for (int state = 0; state < (1 << 20); ++state) { int candi = get_score(state); if (result < candi) { result = candi; } } printf("%d\n", result); return 0; }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int scores[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
						20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
						40, 13, 16, 19, 22, 24, 25, 26, 27, 28,
						30, 35, 0 };

int commands[10];
vector<int> links[33];
int maxScore;

void initLink() {
	for (int i = 0; i < 20; ++i)
		links[i].push_back(i + 1);
	links[5].push_back(21);
	links[21].push_back(22);
	links[22].push_back(23);
	links[23].push_back(26);
	links[10].push_back(24);
	links[24].push_back(25);
	links[25].push_back(26);
	links[15].push_back(29);
	links[29].push_back(28);
	links[28].push_back(27);
	links[27].push_back(26);
	links[26].push_back(30);
	links[30].push_back(31);
	links[31].push_back(20);
	links[20].push_back(32);
	links[32].push_back(32);
}

bool isBlue(int pos) {
	return links[pos].size() == 2;
}

int move(int here, int num) {
	int there = here;
	for (int i = 0; i < num; ++i) {
		there = links[there][0];
	}
	return there;
}

bool notDuplicate(int piece, int here, vector<int>& pos) {
	for (int i = 0; i < 4; ++i) {
		if (i != piece && pos[i] == here)
			return false;
	}
	return true;
}

void dfs(int count, vector<int> pos, int score) {
	if (count == 10) {
		maxScore = max(maxScore, score);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int here = pos[i];
		int there;
		if (isBlue(here)) {
			there = links[here][1];
			there = move(there, commands[count] - 1);
		}
		else {
			there = move(here, commands[count]);
		}
		if (there == 32 || notDuplicate(i, there, pos)) {
			pos[i] = there;
			dfs(count + 1, pos, score + scores[there]);
			pos[i] = here;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; ++i)
		cin >> commands[i];
	initLink();
	vector<int> pos(4);
	maxScore = 0;
	dfs(0, pos, 0);
	cout << maxScore << endl;
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	map<string, int> m;


	if (m["leo"] == NULL) {
		printf("ok");
	}
}