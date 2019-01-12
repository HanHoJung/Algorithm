#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[7];
int cntVal[7];
int cnt[7];
int index[7];



void go(int count) {

	if (count == m) {

		for (int i = 0; i < m; i++) {
			cout << index[i] << " ";
		}

		cout << "\n";
		return;

	}

	for (int i = 0; i < n; i++) {

		if (cnt[i] > 0) {
			index[count] = cntVal[i];
			go(count + 1);
		}
	}
}


int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int k = 0;
	int c = 1;
	int x = arr[0];

	for (int i = 1; i < n; i++) {
		if (x == arr[i]) {
			c++;
		}
		else {
			cntVal[k] = x;
			cnt[k] = c;
			k++;
			c = 1;
			x = arr[i];
		}
	}
	cntVal[k] = x;
	cnt[k] = c;

	go(0);
}