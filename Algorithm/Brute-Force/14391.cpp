#include <iostream>
#include <algorithm>
using namespace std;

int arr[4][4];
int main(void) {
	int n, m;
	int MAX = -1;
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	for (int i = 0; i < (1 << n * m); i++) {
		int r_sum = 0;//행렬의 가로 집합의 모든 합
		
		for (int r = 0; r < n; r++) {
			int ans = 0;
			for (int c = 0; c < m; c++) {
				int k = r * m + c;

				if ((i&(1 << k)) == 0) {
					ans = ans * 10 + arr[r][c];
				}
				else {
					r_sum = ans+ r_sum;
					ans = 0;
				}

			}
			r_sum = r_sum + ans;
		}


		int s_sum = 0; //행렬의 세로 집합의 모든 합

		for (int c = 0; c < m; c++) {
			int ans = 0;
			for (int r = 0; r < n; r++) {
				int k = r * m + c;

				if ((i&(1 << k)) !=0) {
					ans = ans * 10 + arr[r][c];
				}
				else {
					s_sum = ans + s_sum;
					ans = 0;

				}

			}
			s_sum = ans + s_sum;
		}
		
		int total = r_sum + s_sum;

		MAX = max(total, MAX);



	}

	cout <<MAX << "\n";


}