#include <iostream>
using namespace std;

int d[10001];
int main(void) {


	d[0] = 1;

	for (int i = 1; i <= 10000; i++) {
		if (i - 1 >= 0)
			d[i] += d[i - 1];

	}

	for (int i = 1; i <= 10000; i++) {
		if (i - 2 >= 0)
			d[i] += d[i - 2];

	}

	for (int i = 1; i <= 10000; i++) {
		if (i - 3 >= 0)
			d[i] += d[i - 3];

	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}
}
