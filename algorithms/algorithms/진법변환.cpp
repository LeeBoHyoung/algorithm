/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main() {
	long long int n; int b;
	scanf("%lld %d", &n, &b);
	vector<char> hex (26, 0);
	for (int i = 0; i < 26; i++) {
		hex[i] = 'A' + i;
	}
	vector<char> ans;
	vector<int> num = { 48,49,50,51,52,53,54,55,56,57 };
	while (1) {
		if (n % b == n) {
			if (n >= 10) {
				ans.push_back(hex[n - 10]);
			}
			else {
				ans.push_back(num[n]);
			}
			break;
		}
		long long int val = n%b;
	
		if (val >= 10) {
			ans.push_back(hex[val-10]);
		}
		else {
			ans.push_back(num[val]);
		}

		n = n/b;
	}
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
}
*/

#include<cstdio>
int N, X;
void DtoX(int n) {
	if (n) DtoX(n / X), printf("%c", n % X > 9 ? ('A' + n % X - 10) : ('0' + n % X));
}
int main() {
	scanf("%d%d", &N, &X);
	DtoX(N);
}