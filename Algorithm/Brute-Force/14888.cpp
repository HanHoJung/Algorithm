#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> arr;
	vector<int> brr;
	vector<int> oper;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		int input;
		cin >> input;
		oper.push_back(input);
	}



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < oper[i]; j++) {
			brr.push_back(i);
		}
	}


	int maxVal = -1000000000;
	int minVal = 1000000000;

	do {

		int sum = arr[0];

		for (int i = 1; i < arr.size(); i++) {

			if (brr[i - 1] == 0) {
				sum = sum + arr[i];

			}
			if (brr[i - 1] == 1) {
				sum = sum - arr[i];

			}
			if (brr[i - 1] == 2) {
				sum = sum * arr[i];

			}


			if (brr[i - 1] == 3) {
				sum = sum / arr[i];

			}

		}

		maxVal = max(maxVal, sum);
		minVal = min(minVal, sum);
	} while (next_permutation(brr.begin(), brr.end()));

	cout << maxVal << "\n";
	cout << minVal << "\n";

}