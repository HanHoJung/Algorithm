#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

vector<int> gen(int i) {
	vector<int> output(5, 0);
	int k = 0;
	while (i != 0) {

		output[k++] = i & 3;
		i = i >> 2;

	}

	return output;
}

int check(vector<vector<int>> MAP, vector<int> direction) {
	vector <vector<pair<int, bool>>> a(n, vector<pair<int, bool>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j].first = MAP[i][j];
		}
	}

	for (int i = 0; i < direction.size(); i++) {
		bool ok = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j].second = false;
			}
		}

		int k = direction[i];

		while (true) {
			ok = false;
			if (k == 0) {//À§

				for (int i = 1; i < n; i++) {

					for (int j = 0; j < n; j++) {

						if (a[i][j].first == 0) {
							continue;
						}
						else if (a[i - 1][j].first == 0) {

							a[i - 1][j].first = a[i][j].first;
							a[i - 1][j].second = a[i][j].second;
							a[i][j].first = 0;
							ok = true;

						}
						else if (a[i - 1][j].first == a[i][j].first) {

							if (a[i - 1][j].second == false && a[i][j].second == false) {
								a[i - 1][j].first = a[i - 1][j].first * 2;
								a[i - 1][j].second = true;
								a[i][j].first = 0;
								ok = true;

							}
						}

					}

				}


			}

			if (k == 1) {//¾Æ·¡
				for (int i = n - 2; i >= 0; i--) {
					for (int j = 0; j < n; j++) {

						if (a[i][j].first == 0) {
							continue;
						}
						else if (a[i + 1][j].first == 0) {
							a[i + 1][j].first = a[i][j].first;
							a[i + 1][j].second = a[i][j].second;
							a[i][j].first = 0;
							ok = true;

						}
						else if (a[i + 1][j].first == a[i][j].first) {

							if (a[i + 1][j].second == false && a[i][j].second == false) {
								a[i + 1][j].first = a[i + 1][j].first * 2;
								a[i + 1][j].second = true;
								a[i][j].first = 0;
								ok = true;

							}
						}

					}

				}
			}

			if (k == 2) {//ÁÂ

				for (int i = 1; i < n; i++) {
					for (int j = 0; j < n; j++) {

						if (a[j][i].first == 0) {
							continue;
						}
						else if (a[j][i - 1].first == 0) {
							a[j][i - 1].first = a[j][i].first;
							a[j][i - 1].second = a[j][i].second;
							a[j][i].first = 0;
							ok = true;

						}
						else if (a[j][i - 1].first == a[j][i].first) {

							if (a[j][i - 1].second == false && a[j][i].second == false) {
								a[j][i - 1].first = a[j][i - 1].first * 2;
								a[j][i - 1].second = true;
								a[j][i].first = 0;
								ok = true;

							}
						}

					}

				}
			}


			if (k == 3) {//¿ì
				for (int i = n - 2; i >= 0; i--) {
					for (int j = 0; j < n; j++) {

						if (a[j][i].first == 0) {
							continue;
						}
						else if (a[j][i + 1].first == 0) {
							a[j][i + 1].first = a[j][i].first;
							a[j][i + 1].second = a[j][i].second;
							a[j][i].first = 0;
							ok = true;

						}
						else if (a[j][i + 1].first == a[j][i].first) {

							if (a[j][i + 1].second == false && a[j][i].second == false) {
								a[j][i + 1].first = a[j][i + 1].first * 2;
								a[j][i + 1].second = true;
								a[j][i].first = 0;
								ok = true;

							}
						}

					}

				}

			}

			if (ok == false) {
				break;
			}

		}


	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < a[i][j].first) {
				ans = a[i][j].first;
			}
		}
	}
	return ans;



}

int main(void) {

	cin >> n;

	vector<vector<int>> MAP(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}



	int ans = -1;
	for (int i = 0; i < (1 << 10); i++) {
		vector<int> direction = gen(i);

		int cnt = check(MAP, direction);

		if (ans < cnt) {
			ans = cnt;
		}

	}
	cout << ans << "\n";

}