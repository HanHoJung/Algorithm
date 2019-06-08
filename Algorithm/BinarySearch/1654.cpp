#include <iostream>
#define START 1
#define END 2147483647
using namespace std;

void init(int &k,int &n, int * arr) {
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
}

bool check(int length, int * arr,int &k,int &n) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt+= arr[i] / length;
	}
	return cnt >= n;
}

int main(void) {
	int k, n;
	int arr[10000];
	long long left = START;
	long long right = END;
	long long mid;
	int result=START;

	init(k, n, arr);
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid, arr, k, n)) {
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