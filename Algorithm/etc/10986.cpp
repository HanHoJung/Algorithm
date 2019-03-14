#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<long long> arr(n);
	long long sum = 0;
	vector<long long> cnt(m);
	cnt[0] = 1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		sum %= m;
		cnt[sum]++;
	}


	long long output = 0;
	for (int i = 0; i < m; i++) {
		long long k = (cnt[i])*(cnt[i] - 1) / 2;
		output = k + output;
	}
	cout << output << "\n";
}