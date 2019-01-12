#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[8];
int cntVal[8];
int cnt[8];
int index[8];



void go2(int count, int next) {
	if (count == m) {
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < index[i]; j++) {
				cout << cntVal[i]<<" ";
			}
		}
		cout << "\n";
		return;

	}

	if (next >= n)
		return;

	for (int i = m - count; i >= 1; i--) {
		if(cnt[next]>0){
			index[next] = i;
			go2(count + i, next + 1);
			index[next] = 0;
		}
		
	}
	go2(count, next + 1);


}


void go(int count, int start) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << index[i] << " ";
		}
		cout << "\n";
		return;

	}

	for (int i = start; i < n; i++) {
		if (cnt[i] > 0) {
			index[count] = cntVal[i];
			go(count + 1, i);
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

	go2(0, 0);
}