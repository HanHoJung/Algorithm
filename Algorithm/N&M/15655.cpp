#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int index[8];
int num[8];
int check[8];


void solve(int n, int m, int start, int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[index[i]] << " ";
		}
		cout << "\n";
	}

	for (int i = start; i < n; i++) {

		if (check[i] == false) {
			check[i] = true;
			index[cnt] = i;
			solve(n, m,i+1,cnt+1);
			check[i] = false;
		}
	}

}



void solve2(int n, int m, int selected, int next) {

	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << num[index[i]] << " ";
		}
		cout << "\n";
		return;
	}

	if (next >=n) {
		return;
	}

	index[selected] = next;
	solve2(n, m, selected + 1, next + 1);
	index[selected] = 0;
	solve2(n, m, selected, next + 1);


}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	/*solve(n, m, 0,0);*/
	solve2(n, m, 0, 0);
	return 0;
}