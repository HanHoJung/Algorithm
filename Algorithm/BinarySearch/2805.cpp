#include <iostream>
using namespace std;
#define START 0
#define END 1000000000
int arr[1000001];
bool check(long long mid, int n, int m) {
	long long cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			long long diff = arr[i] - mid;
			cnt += diff;
		}
	}

	return cnt >= m;
}
int main(void) {
	int n, m;

	int result = START;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long left, right;
	left = START;
	right = END;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid, n, m)) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << result << "\n";
}