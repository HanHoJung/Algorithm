#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n, m;
	int s;
	long long cnt = 0;
	cin >> n >> s;

	m = n / 2;
	n = n - m;



	vector<int> arr(n);
	vector<int> brr(m);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
		cin >> brr[i];

	


	vector<int> temp(1 << n, 0);
	for (int i = 0; i < (1 << n); i++) {

		for (int k = 0; k < n; k++) {

			if (i&(1 << k)) {
				temp[i] = temp[i] + arr[k];
			}
		}
	}

	arr = temp;

	vector<int> temp2(1 << m, 0);
	for (int i = 0; i < (1 << m); i++) {
		for (int k = 0; k < m; k++) {
			if (i&(1 << k)) {
				temp2[i] = temp2[i] + brr[k];
			}
		}
	}

	brr = temp2;
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	reverse(brr.begin(), brr.end());

	n = 1 << n;
	m = 1 << m;

	int left = 0;
	int right = 0;
	int sum=0;



	while (left < n && right < m) {

		sum = arr[left] + brr[right];

		if (sum > s) {
			right++;

		}
		else if (sum == s) {
			long long l_count = 0;
			long long r_count = 0;
			int temp = arr[left];


			while (left < n && temp == arr[left]) {
				l_count++;
				left++;
			}

			temp = brr[right];
			while (right < m && temp == brr[right]) {
				r_count++;
				right++;
			}

			cnt = cnt + l_count * r_count;


		}
		else if (sum < s) {
			left++;
		}


	}

	if (s == 0)
		cnt = cnt - 1;
	cout << cnt << "\n";
}

