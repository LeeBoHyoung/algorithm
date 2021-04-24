#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int num) {
	int i = 1;
	int res = 1;
	vector<int> ret = {};
	while(res < num) {
		res = 1 + (i * (i + 1)) / 2;
		i++;
	}
	cout << res << endl;
	cout << i << endl;
	if(num-res != 0 && num-res != i-1){
		int diff = num - res;
		int b_res = 1 + ((i - 1) * i)/2;
		int f_res = 1 + ((i + 1) * (i + 2))/2;
		ret.push_back(res + diff - 1);
		ret.push_back(res + diff + 1);
		ret.push_back(b_res + diff - 1);
		ret.push_back(b_res + diff);
		ret.push_back(f_res + diff);
		ret.push_back(f_res + diff + 1);
	}
	return ret;
}


int main() {
	vector<int> ans;
	ans = solution(5);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}