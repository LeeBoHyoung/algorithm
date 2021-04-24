#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while(getline(ss, temp, delimiter)){
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	string input;
	getline(cin, input);
	
	vector<string> order;
	vector<string> sp;
	order = split(input, ',');

	for (int i = 0; i<order.size(); i++) {
		if (i == 0) {
			order[i] = order[i].substr(1, order[i].length() - 2);
		}
		else {
			order[i] = order[i].substr(2, order[i].length() - 3);
		}
	}
	
	vector<vector<string>> cf;
	vector<string> tmp;
	for (int i = 0; i < order.size(); i++) {
		int flag = 0; int idx = -1;
		sp = split(order[i], ' ');
		//주문한 이력이 있는지 확인
		for (int k = 0; k < cf.size(); k++) {
			if (sp[0] == cf[k][0]) {
				flag = 1;
				idx = k;
				break;
			}
		}
		if (flag == 0) {
			for (int k = 0; k < sp.size(); k++) {
				tmp.push_back(sp[k]);
			}
			cf.push_back(tmp);
			tmp.clear();
		}
		else {
			for (int k = 1; k < sp.size(); k++) {
				int f = 0;
				for (int j = 1; j < cf[idx].size(); j++) {
					if (sp[k] == cf[idx][j]) {
						f = 1;
						break;
					}
				}
				if(f==0)
					cf[idx].push_back(sp[k]);
			}
		}
	}
	int max = 0; int aidx = -1;
	vector<string> answer;
	for (int i = 0; i < cf.size(); i++) {
		if (max < cf[i].size()) {
			max = cf[i].size();
			aidx = i;
		}
	}
	answer.push_back(cf[aidx][0]);
	for (int i = 0; i < cf.size(); i++) {
		if (cf[aidx].size() == cf[i].size() && aidx != i) {
			answer.push_back(cf[i][0]);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << "\"" << answer[i] << "\"";
		if (i != answer.size() - 1)
			cout << ", ";
	}
}