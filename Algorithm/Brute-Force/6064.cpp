#include <iostream>
using namespace std;

int n, m;
int x, y;

void x_anchor() {
	bool check = false;
	for (int k = x; k < n*m; k = k + n) {
		if (k%m == y) {
			check = true;
			cout << k + 1 << "\n";
			break;
		}
	}
	if (!check) {
		cout << "-1" << "\n";
	}
}


void y_anchor() {
	bool check = false;
	for (int k = y; k < n*m; k = k + m) {
		if (k%n == x) {
			check = true;
			cout << k + 1 << "\n";
			break;
		}
	}
	if (!check) {
		cout << "-1" << "\n";
	}
}


void x_recursive(int k) {

	if (k < n*m && k%m == y) {
		cout << k + 1 << "\n";
		return;
	}

	if (k >= n * m) {
		cout << -1 << "\n";
		return;
	}

	x_recursive(k + n);
}

void y_recursive(int k) {

	if (k < n*m && k%n == x) {
		cout << k + 1 << "\n";
		return;
	}

	if (k >= n * m) {
		cout << -1 << "\n";
		return;
	}

	y_recursive(k + m);
}

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		bool check = false;
		cin >> n >> m >> x >> y;
		x = x - 1;
		y = y - 1;

		y_recursive(y);
	}
}