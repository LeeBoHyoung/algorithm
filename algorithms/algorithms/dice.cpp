#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[4][3];
int dr[4] = { -1, 0, 0, 1 }; // 북 서 동 남
int dc[4] = { 0, -1, 1, 0 };

int diceChange(int dir, int r, int c) {
	int ans; //위에 있는 수는 항상 dice[1][1], 아래 수는 dice[1][3]
	int dice_tmp[4][3];
	memset(dice_tmp, 0, sizeof(dice_tmp));

	if (dir == 1) { //동
		dice_tmp[0][1] = dice[0][1];
		dice_tmp[1][0] = dice[3][1];
		dice_tmp[1][1] = dice[1][0];
		dice_tmp[1][2] = dice[1][1];
		dice_tmp[2][1] = dice[2][1];
		dice_tmp[3][1] = dice[1][2];
	}
	else if (dir == 2) { //서
		dice_tmp[0][1] = dice[0][1];
		dice_tmp[1][0] = dice[1][1];
		dice_tmp[1][1] = dice[1][2];
		dice_tmp[1][2] = dice[3][1];
		dice_tmp[2][1] = dice[2][1];
		dice_tmp[3][1] = dice[1][0];
	}
	else if (dir == 3) { //북
		dice_tmp[0][1] = dice[1][1];
		dice_tmp[1][0] = dice[1][0];
		dice_tmp[1][1] = dice[2][1];
		dice_tmp[1][2] = dice[1][2];
		dice_tmp[2][1] = dice[3][1];
		dice_tmp[3][1] = dice[0][1];
	}
	else { //남
		dice_tmp[0][1] = dice[3][1];
		dice_tmp[1][0] = dice[1][0];
		dice_tmp[1][1] = dice[0][1];
		dice_tmp[1][2] = dice[1][2];
		dice_tmp[2][1] = dice[1][1];
		dice_tmp[3][1] = dice[2][1];
	}
	if (map[r][c] == 0) {
		map[r][c] = dice_tmp[3][1];
	}
	else {
		dice_tmp[3][1] = map[r][c];
		map[r][c] = 0;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			dice[i][j] = dice_tmp[i][j];
		}
	}

	ans = dice[1][1];
	return ans;
}

int main() {
	memset(dice, 0, sizeof(dice));
	cin >> N >> M >> x >> y >> K;
	if (N < 1 || N>20 || M < 1 || M>20 || x < 0 || x > N - 1 || y < 0 || y > M - 1 || K<1 || K>1000) {
		cout << "입력 값의 범위를 벗어났습니다." << "\n";
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] < 0 || map[i][j] > 10) {
				cout << "입력 값의 범위를 벗어났습니다." << "\n";
				exit(0);
			}
		}
	}

	int r=x, c=y;
	if (map[r][c] == 0) {
		map[r][c] = dice[3][1];
	}
	else {
		dice[3][1] = map[r][c];
	}

	int k;
	for (int i = 0; i < K; i++) {
		cin >> k;
		if (k == 1) {
			r = r + dr[2]; c = c + dc[2];
			if ((r >= N || r < 0) || (c >= M || c < 0)) {
				r = r - dr[2]; c = c - dc[2];
				continue;
			}
			else
				cout << diceChange(1, r, c) << "\n";
		}
		else if (k == 2) {
			r = r + dr[1]; c = c + dc[1];
			if ((r >= N || r < 0) || (c >= M || c < 0)) {
				r = r - dr[1]; c = c - dc[1];
				continue;
			}
			else
				cout << diceChange(2, r, c) << "\n";
		}
		else if (k == 3) {
			r = r + dr[0]; c = c + dc[0];
			if ((r >= N || r < 0) || (c >= M || c < 0)) {
				r = r - dr[0]; c = c - dc[0];
				continue;
			}				
			else
				cout << diceChange(3, r, c) << "\n";
		}
		else if (k == 4) {
			r = r + dr[3]; c = c + dc[3];
			if ((r >= N || r < 0) || (c >= M || c < 0)) {
				r = r - dr[3]; c = c - dc[3];
				continue;
			}
			else
				cout << diceChange(4, r, c) << "\n";
		}

	}

	return 0;
}