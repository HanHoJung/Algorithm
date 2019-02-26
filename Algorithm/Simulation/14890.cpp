#include <iostream>
#include <vector>
using namespace std;
int n, r;
int cnt;

bool check(vector<pair<int, bool>> &arr) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].first < arr[i + 1].first) {
			if (arr[i].second == false && i - r + 1 >= 0 && (arr[i + 1].first == (arr[i].first + 1))) {
				int k = i;
				int temp = r - 1;
				while (temp--) {
					if (arr[k].first == arr[k - 1].first && arr[k].second == false && arr[k - 1].second == false) {
						arr[k].second = true;
					}
					else {
						return false;
					}
					k--;
				}
				arr[k].second = true;
			}
			else {
				return false;
			}

		}
		else if (arr[i].first > arr[i + 1].first) {
			if (arr[i + 1].second == false && i + r < n && (arr[i].first == (arr[i + 1].first + 1))) {
				int k = i + 1;
				int temp = r - 1;
				while (temp--) {

					if (arr[k].first == arr[k + 1].first && arr[k].second == false && arr[k + 1].second == false) {
						arr[k].second = true;

					}
					else {
						return false;
					}
					k++;
				}
				arr[k].second = true;
			}
			else {
				return false;
			}

		}
	}
	return true;
}


int main(void) {

	cin >> n >> r;

	vector<vector<int>> MAP(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}


	//가로 parsing
	for (int i = 0; i < n; i++) {
		vector<pair<int, bool>> arr;
		for (int j = 0; j < n; j++) {
			arr.push_back(make_pair(MAP[i][j], false));
		}
		bool c = check(arr);
		if (c) {
			cnt++;
		}
	}

	//세로 parsing
	for (int i = 0; i < n; i++) {
		vector<pair<int, bool>> arr;
		for (int j = 0; j < n; j++) {
			arr.push_back(make_pair(MAP[j][i], false));
		}
		bool c = check(arr);
		if (c) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}