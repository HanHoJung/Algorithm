#include<iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int sum = arr[0];
	int cnt = 0;
	while (left <= right && right < n) {
		
		if (sum < m) {
			right++;
			if (right < n)
				sum = sum + arr[right];

		}
		else if (sum == m) {
			cnt++;
			right++;
			if (right < n) 
				sum = sum + arr[right];
				
			
		}
		else if (sum > m) {
			sum = sum - arr[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = arr[left];
			}
			
		}

		
	}
	cout << cnt << "\n";
}

