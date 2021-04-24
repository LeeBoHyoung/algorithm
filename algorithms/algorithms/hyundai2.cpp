/*
1. �ֽ��� �ι����� ��ų� �� �� �ִ�.
2. �ֽ��� �Ϸ翡 �ѹ��� ��ų� �� ���ִ�.
������ ���� �ʴ� ���, �ѹ��� �絵 �ǰ� �� �絵 ��
���ظ� �ִ� �ܿ� 0 return
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMax(vector<vector<int>> map, vector<vector<bool>> chk, int size, int buy, int sell) {
	int res = map[buy][sell];
	for (int i = 0; i < size; i++) {
		chk[i][sell] = true;
		chk[buy][i] = true;
	}
	int max = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (chk[i][j] == false) {
				if (max < map[i][j]) max = map[i][j];
			}		
		}
	}
	res += max;
	return res;
}

int main() {
	vector<int> input;
	do  {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	} while (getc(stdin) != '\n');
	
	int size = input.size();
	vector<vector<int>> map(size, vector<int>(size, 0));
	vector<vector<bool>> chk(size, vector<bool>(size, false));

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			map[i][j] = input[j] - input[i];
		}
	}

	int max = 0; int res;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			res = findMax(map, chk, size, i, j);
			if (res > max) max = res;
		}
	}
	
	cout << max << endl;
}