#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int t;
	cin >> t;

	int n, m;
	cin >> n;
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;
	vector<int> B(m);
	for (int j = 0; j < m; j++) {
		cin >> B[j];

	}


	vector<long long> cumA;
	vector<long long> cumB;


	//누적합

	for (int i = 0; i < n; i++) {
		long long sum = 0;

		for (int j = i; j < n; j++) {
			sum = sum + A[j];
			cumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum = sum + B[j];
			cumB.push_back(sum);
		}
	}



	sort(cumA.begin(), cumA.end());
	sort(cumB.begin(), cumB.end());




	n = cumA.size();
	m = cumB.size();




	int left = 0;
	int right = m - 1;
	long long s = 0;//합

	long long cnt = 0;
	while (left < n && right >= 0) {
		s = cumA[left] + cumB[right];

		if (t < s) {
			right--;
		}
		else if (t == s) {

			long long a_count = 1;
			long long b_count = 1;
			while (left < n - 1 && cumA[left] == cumA[left + 1]) {
				left++;
				a_count++;

			}



			while (right >= 1 && cumB[right] == cumB[right - 1]) {
				right--;
				b_count++;


			}

			left++;
			right--;

			cnt = cnt + (a_count * b_count);


		}
		else if (t > s) {
			left++;

		}
	}

	cout << cnt << "\n";

}