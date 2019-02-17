#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[1001];
int dp2[1001];

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];



	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			
			if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1)
				dp1[i] = dp1[j] + 1;
		}
	}


	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if(max<dp1[i]+dp2[i]-1)
			max = dp1[i] + dp2[i] - 1;
	}

	cout << max << "\n";
}