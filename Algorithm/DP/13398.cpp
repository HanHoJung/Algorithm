#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> dl(n);
	vector<int> dr(n);
	

	for (int i = 0; i < n; i++) {
		dl[i] = arr[i];

		if (i == 0)
			continue;

		if (dl[i - 1] + arr[i] > arr[i]) {
			dl[i] = dl[i - 1] + arr[i];
		}
		
	}


	for (int i = n-1; i>=0; i--) {
		dr[i] = arr[i];

		if (i == n-1)
			continue;

		if (dr[i+1] + arr[i] > arr[i]) {
			dr[i] = dr[i+1] + arr[i];
		}

	}


	int ans = dl[0];

	for (int i = 1;i < n; i++) {
		if (ans < dl[i])
			ans = dl[i];
	}

	for (int i = 1; i < n - 1; i++) {
		if (ans < dl[i - 1] + dr[i + 1]) {
			ans = dl[i - 1] + dr[i + 1];
		}
	}

	
	
	cout << ans << "\n";
	return 0;
}