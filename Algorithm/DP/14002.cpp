#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void go(vector<int> arr,int before[],int value) {
	if (before[value] == value) {
		cout << arr[value] << " ";
		return;
	}
	
	go(arr,before, before[value]);
	cout << arr[value] << " ";
}

int dp[1001];
int before[1001];
int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int last;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		int last = i;
		for (int j = i - 1; j >= 0; j--) {

			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				last = j;

			}
		}

		before[i] = last;
	}

	int maxVal = 0;
	int k = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxVal) {
			maxVal = dp[i];
			k = i;
		}
	}
	cout << maxVal << "\n";
	vector<int> output;

	go(arr,before, k);
	/*int index = k;


	while (index != before[index]) {
		output.push_back(arr[index]);
		index = before[index];
	}

	output.push_back(arr[index]);

	reverse(output.begin(), output.end());

	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << "\n";*/
}