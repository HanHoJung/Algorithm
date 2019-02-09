#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);


	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> one;
	vector<int> two;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			one.push_back(a[i] + b[j]);
			two.push_back(c[i] + d[j]);
		}
	}


	sort(two.begin(), two.end());
	long long cnt = 0;
	for (int i = 0; i < one.size(); i++) {

		auto p = equal_range(two.begin(), two.end(), -one[i]);
		cnt = p.second - p.first + cnt;
	}

	cout << cnt << "\n";
}