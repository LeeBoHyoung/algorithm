#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
void quickSort(int* quick, int i, int j)
{
	if (i >= j) return;
	int pivot = quick[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--;
		if (left <= right)
		{
			swap(quick[left], quick[right]);
			left++; right--;
		}
	}
	quickSort(quick, i, right);
	quickSort(quick, left, j);
}


bool bsearch(int* arr, int num, int s, int e) {
	if (s > e) return false;
	
	int m = (s + e) / 2;
	if (num < arr[m])
		return bsearch(arr, num, s, m - 1);
	else if (num > arr[m]) {
		return bsearch(arr, num, m + 1, e);
	}
	else
		return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int num;
	int arr1[100000];
	int arr2[100000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	
	quickSort(arr1, 0, n-1);

	for (int i = 0; i < m; i++) {
		printf("%d\n", bsearch(arr1, arr2[i], 0, n - 1));
	}

}
*/

int main() {
	string a = "a";
	string b = a + '1';
	cout << b << endl;
}