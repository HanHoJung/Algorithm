#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int index[8];
int num[8];
int check[8];



void solve(int n, int m, int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[index[i]] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {

		if (check[i] == false) {
			check[i] = true;
			index[cnt] = i;
			solve(n, m, cnt + 1);
			check[i] = false;
		}
	}

}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve(n, m,0);
	return 0;
}