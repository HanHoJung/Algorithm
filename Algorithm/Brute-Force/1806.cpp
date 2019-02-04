#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int left = 0;
	int right = 0;
	int  total = arr[0];
	int length = -1;
	while (left <= right && right < n) {

		if (total < s) {
			right++;
			if (right < n) {
				total = total + arr[right];
			}

		}
		else if (total == s) {
			int cnt = (right - left) + 1;
			if (length == -1 || cnt < length) {
				length = cnt;

			}

			right++;
			if (right < n) {
				total = total + arr[right];
			}


		}
		else if (total > s) {
			int cnt = (right - left) + 1;
			if (length == -1 || cnt < length) {
				length = cnt;
			}


			total = total - arr[left];
			left++;
			if (left > right && left < n) {

				right = left;
				total = arr[left];
			}

		}


	}

	if (length == -1) {
		cout << 0 << "\n";
	}
	else {
		cout << length << "\n";
	}

}