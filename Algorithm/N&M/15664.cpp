#include <iostream>
#include <algorithm>
using namespace std;
int a[8];
int cnt[8];
int cVal[8];

void solve(int n, int m, int start, int index) {
	
	if (m == index) {
		for(int i = 0; i < m; i++) {
			cout << cVal[a[i]] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = start; i < n; i++) {
		
		if (cnt[i] > 0) {
			a[index] = i;
			cnt[i]--;
			solve(n, m, i, index + 1);
			cnt[i]++;
		}
		
	
	}
}


void solve2(int n, int m, int selected, int next) {

	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << cVal[a[i]] << " ";
		}
		cout << "\n";
		return;
	}

	if (next >=n)
		return;


	if (cnt[selected] > 0) {
		a[selected] = next;
		cnt[selected]--;
		solve2(n, m, selected + 1, next);
		cnt[selected]++;
		
	}

	solve2(n, m, selected, next+1);


}
int main(void) {
	int n, m;
	int temp[8];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp[i]);
	}
	sort(temp, temp + n);
	int index = 0;
	int c = 1;
	int x = temp[0];


	for (int i = 1; i < n; i++) {

		if (x == temp[i]) {
			c++;
		}
		else {
			cVal[index] = x;
			cnt[index] = c;
			c = 1;
			index++;
			x = temp[i];
		}
	}

	cVal[index] = x;
	cnt[index] = c;



	solve(n, m, 0, 0);




}