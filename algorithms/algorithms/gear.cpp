#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int gear[4][8];

void clock(int i) {
	int tmp = gear[i][7];
	for (int k = 6; k >= 0; k--) {
		gear[i][k+1] = gear[i][k];
	}
	gear[i][0] = tmp;
}

void clockwise(int i) {
	int tmp = gear[i][0];
	for (int k = 1; k < 8; k++) {
		gear[i][k-1] = gear[i][k];
	}
	gear[i][7] = tmp;
}

void gearChange(int num, int change) {
	if (num == 1) {
		if (gear[0][2] == gear[1][6]) {
			if (change == 1)
				clock(0);
			else
				clockwise(0);
			return;
		}
		else {
			if (change == 1) {
				clock(0);
			}
			else {
				clockwise(0);
			}

			if (gear[1][2] == gear[2][6]) {
				if (change == 1) {
					clockwise(1);
					change = -1;
				}
				else {
					clock(1);
					change = 1;
				}
				return;
			}
			else {
				if (change == 1) {
					clockwise(1);
					change = -1;
				}
				else {
					clock(1);
					change = 1;
				}
				
				if (gear[2][2] == gear[3][6]) {
					if (change == 1) {
						clockwise(2);
						change = -1;
					}
					else {
						clock(2);
						change = 1;
					}
					return;
				}
				else {
					if (change == 1) {
						clockwise(2);
						change = -1;
					}
					else {
						clock(2);
						change = 1;
					}

					if (change == 1)
						clockwise(3);
					else
						clock(3);
				}
			}
		}
	}

	if (num == 2) {
		if (gear[1][6] != gear[0][2]) {
			if (change == 1)
				clockwise(0);
			else
				clock(0);
		}

		if (gear[1][2] == gear[2][6]) {
			if (change == 1)
				clock(1);
			else
				clockwise(1);
			return;
		}
		else {
			if (change == 1)
				clock(1);
			else
				clockwise(1);

			if (gear[2][2] == gear[3][6]) {
				if (change == 1) {
					clockwise(2);
					change = -1;
				}
				else {
					clock(2);
					change = 1;
				}
				return;
			}
			else {
				if (change == 1) {
					clockwise(2);
					change = -1;
				}
				else {
					clock(2);
					change = 1;
				}

				if (change == 1)
					clockwise(3);
				else
					clock(3);
			}
		}
	}

	if (num == 3) {
		if (gear[2][2] != gear[3][6]) {
			if (change == 1)
				clockwise(3);
			else
				clock(3);
		}

		if (gear[2][6] == gear[1][2]) {
			if (change == 1)
				clock(2);
			else
				clockwise(2);
			return;
		}
		else {
			if (change == 1)
				clock(2);
			else
				clockwise(2);

			if (gear[1][6] == gear[0][2]) {
				if (change == 1) {
					clockwise(1);
					change = -1;
				}
				else {
					clock(1);
					change = 1;
				}
				return;
			}
			else {
				if (change == 1) {
					clockwise(1);
					change = -1;
				}
				else {
					clock(1);
					change = 1;
				}

				if (change == 1)
					clockwise(0);
				else
					clock(0);
			}
		}
	}

	if (num == 4) {
		if (gear[3][6] == gear[2][2]) {
			if (change == 1)
				clock(3);
			else
				clockwise(3);
			return;
		}
		else {
			if (change == 1)
				clock(3);
			else
				clockwise(3);
			if (gear[2][6] == gear[1][2]) {
				if (change == 1) {
					clockwise(2);
					change = -1;
				}
				else {
					clock(2);
					change = 1;
				}
				return;
			}
			else {
				if (change == 1) {
					clockwise(2);
					change = -1;
				}
				else {
					clock(2);
					change = 1;
				}
				if (gear[1][6] == gear[0][2]) {
					if (change == 1) {
						clockwise(1);
						change = -1;
					}
					else {
						clock(1);
						change = 1;
					}
					return;
				}
				else {
					if (change == 1) {
						clockwise(1);
						change = -1;
					}
					else {
						clock(1);
						change = 1;
					}
					if (change == 1)
						clockwise(0);
					else
						clock(0);
				}
			}
		}
	}
}
int main() {
	char temp[4][8];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> temp[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			gear[i][j] = temp[i][j] - 48;
		}
	}

	int num, change, k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num >> change;
		gearChange(num, change);

		/*for (int j = 0; j < 4; j++) {
			for (int n = 0; n < 8; n++) {
				cout << gear[j][n] << " ";
			}
			cout << endl;
		}*/
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			sum = sum + pow(2, i);
		}
	}

	cout << sum;
	return 0;
}