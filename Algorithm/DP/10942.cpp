#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[2001][2001];
int a[2001];

int top_down(int i, int j) {
	if (i == j) {//길이1
		return 1;
	}
	else if (i + 1 == j) {//길이2
		if (a[i] == a[j]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (d[i][j] != -1) {
		return d[i][j];
	}
	if (a[i] != a[j]) {
		return d[i][j] = 0;
	}
	else {//a[i]==a[j]
		return d[i][j] = top_down(i + 1, j - 1);
	}

}

int main(void) {
	int n,m;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;

	memset(d, -1, sizeof(d));
	
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << top_down(i-1, j-1) << "\n";
	}

	
}