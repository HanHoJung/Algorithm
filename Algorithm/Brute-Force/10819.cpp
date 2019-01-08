#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	int maxVal=0;
	do {
		
		int value=0;
		for (int i = 0; i < n-1; i++) {
			value = abs(arr[i] - arr[i + 1])+value;
		}


		maxVal = max(value, maxVal);

	} while (next_permutation(arr, arr + n));

	cout << maxVal << "\n";
}