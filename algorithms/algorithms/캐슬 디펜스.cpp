#include <iostream>
#include <vector>
using namespace std;

int n, m, d;
int map[16][16];
bool visited[15][15];
vector<vector<int>> arch; // 掙熱 唳辦曖 熱
int ans = 0;

void comb(int* arr, bool* v, vector<int> tmp, int s) {

	if (tmp.size() == 3) {
		for (int i = 0; i < 3; i++) {
			map[n + 1][tmp[i]] = 2; //2朝 掙熱
		}
		//int kill = attack();
		//if (kill > ans) ans = kill;
		for (int i = 0; i < 3; i++) {
			cout << tmp[i];
		}
		cout << "\n\n";
		return;
	}
	else {
		for (int i = s; i < n; i++) {
			if (!v[i]) {
				tmp.push_back(arr[i]);
				v[i] = true;
				comb(arr, v, tmp, i);
				v[i] = false;
				tmp.pop_back();
			}
		}
	}
}
int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//掙熱 濠葬
	int arr[15];
	for (int i = 0; i < m; i++) {
		arr[i] = i;
	}

	vector<int> tmp;
	bool v[15] = { false, };
	comb(arr, v, tmp, 0);
	
	

}