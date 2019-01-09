#include <iostream>
#include <algorithm>
using namespace std;

int a[8];
int seq[8];
bool check[8];

void go(int n, int m, int cnt, int start) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[a[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < n; i++) {
		a[cnt] = i;
		go(n, m, cnt + 1, i);
	}

}


void go2(int n, int m, int selected, int index) {
	if (selected == m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i]; j++) {
				cout << seq[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	if (index >=n)
		return;


	for (int i = m - selected; i >= 1; i--) {
		a[index] = i;
		go2(n, m, selected+i, index + 1);
	}

	a[index] = 0;
	go2(n, m, selected, index + 1);

}


int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	sort(seq, seq + n);
	/*go(n, m, 0,0);*/
	go2(n, m, 0, 0);
}
