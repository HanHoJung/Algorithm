#include <iostream>
#include <algorithm>
using namespace std;

int a[500][500];
int main(void) {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			/*
			   - - - -
			*/
			if (j + 3 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				sum = max(ans, sum);
			}

			/*
				-
				-
				-
				-
			*/

			if (i + 3 < n) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				sum = max(ans, sum);
			}

			/*
				  -
				  - - -

			*/
			if (i + 1 < n&&j + 2 < m) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				sum = max(ans, sum);
			}

			/*
				  - -
				  -
				  -

			*/
			if (i + 2 < n &&j + 1 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j];
				sum = max(ans, sum);
			}


			/*
				- - -
					-
			*/
			if (i + 1 < n && j + 2 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
				sum = max(ans, sum);
			}

			/*
				   -
				   -
				 - -
			*/
			if (i + 2 < n && j - 1 >= 0) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
				sum = max(ans, sum);
			}

			/*
				   -
			   - - -

			*/

			if (i - 1 >= 0 && j + 2 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
				sum = max(ans, sum);
			}


			/*
				-
				-
				- -
			*/

			if (i + 2 < n && j + 1 < m) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				sum = max(ans, sum);
			}

			/*
				- - -
				-
			*/

			if (i + 1 < n && j + 2 < m) {

				int ans = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
				sum = max(ans, sum);

			}


			/*
				- -
				  -
				  -

			*/

			if (i + 2 < n && j + 1 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				sum = max(ans, sum);
			}


			/*

				- -
				- -
			*/

			if (i + 1 < n && j + 1 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				sum = max(ans, sum);
			}

			/*    - -
				- -
			*/
			if (i - 1 >= 0 && j + 2 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
				sum = max(ans, sum);
			}

			/*
				-
				- -
				  -

			*/

			if (i + 2 < n&&j + 1 < m) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				sum = max(ans, sum);
			}

			/*
				- -
				  - -

			*/

			if (i + 1 < n && j + 2 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				sum = max(ans, sum);

			}

			/*
				  -
				- -
				-
			*/

			if (i + 2 < n && j + 1 < m) {
				int ans = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
				sum = max(ans, sum);
			}


			/*    -
				- - -


				- - -
				  -
			*/

			if (j + 2 < m) {
				int ans = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int ans2 = ans + a[i - 1][j + 1];
					sum = max(ans2, sum);
				}

				if (i + 1 < n) {
					int ans2 = ans + a[i + 1][j + 1];
					sum = max(ans2, sum);
				}

			}

			/*    -
				- -
				  -

				  -
				  - -
				  -

			*/

			if (i + 2 < n) {

				int ans = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j - 1 >= 0) {
					int ans2 = ans + a[i + 1][j - 1];
					sum = max(ans2, sum);

				}

				if (j + 1 < m) {
					int ans2 = ans + a[i + 1][j + 1];
					sum = max(ans2, sum);
				}

			}





		}
	}

	cout << sum << '\n';

	return 0;


}