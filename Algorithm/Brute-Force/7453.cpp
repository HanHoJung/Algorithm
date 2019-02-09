/*
  A+B+C+D=0
  A+B = -(C+D)

  1.A+B의 합, C+D의 합 구하기
  2.정렬하기
  3.middle 알고리즘
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);


	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	vector<int> one;
	vector<int> two;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			one.push_back(a[i] + b[j]);
			two.push_back(c[i] + d[j]);
		}
	}



	
	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	int left = 0;
	int right = two.size()-1;
	long long total = 0;
	long long cnt = 0;
	n = one.size();

	while (left<n && right>=0) {
		
		total = one[left] + two[right];
		if(total>0){
			right--;
		}
		else if (total == 0) {
	
			long long one_count = 1;
			long long two_count = 1;

			while (left < n - 1 && one[left] == one[left + 1]) {
				one_count++;
				left++;
			}

			while (right >=1 && two[right] == two[right- 1]) {
				two_count++;
				right--;
			}
			left++;
			right--;
			cnt = cnt + (one_count * two_count);

		}
		else if (total < 0) {

			left++;
			
		}



	}
	cout << cnt << "\n";
}