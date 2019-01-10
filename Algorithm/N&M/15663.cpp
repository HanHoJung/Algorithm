#include <iostream>
#include <algorithm>
using namespace std;
int a[8];
int cVal[8];
int cnt[8];

void solve(int n, int m, int index) {

	if (index == m) {

		for (int i = 0; i < m; i++) {
			cout << cVal[a[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {

		if (cnt[i] > 0) {
			cnt[i]--;
			a[index] = i;
			solve(n, m, index + 1);
			cnt[i]++;
		}

	}

}

int main(void) {
	int n, m;
	int value[8];
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}
	sort(value, value + n);

	int index = 0;
	int c = 1;
	int x = value[0];
	

	for (int i = 1; i < n; i++) {

		if (x == value[i]) {
			c++;
		}
		else {
			cVal[index] = x;
			cnt[index] = c;
			c = 1;
			index++;
			x = value[i];

		}
	}

	cVal[index] = x;
	cnt[index] = c;


	/*for (int i = 0; i < index+1; i++) {
		cout << cVal[i] << ":" << cnt[i] << "\n";
	}*/

	solve(n, m, 0);
	return 0;
}