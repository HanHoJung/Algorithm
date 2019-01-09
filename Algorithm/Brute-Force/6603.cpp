#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

	while (true) {
		int k;
		cin >> k;
		if (k == 0)
			break;

		vector<int> arr;
		vector<int> brr;

		for (int i = 0; i < k; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		for (int i = 0; i < k - 6; i++) {
			brr.push_back(0);
		}

		for (int i = 0; i < 6; i++) {
			brr.push_back(1);
		}

		vector<vector<int>> result;
		do {
			vector<int> crr;


			for (int i = 0; i < k; i++) {
				if (brr[i] == 1) {
					crr.push_back(arr[i]);
				}
			}

			result.push_back(crr);


		} while (next_permutation(brr.begin(), brr.end()));


		sort(result.begin(), result.end());

		for (int i = 0; i < result.size(); i++) {

			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}