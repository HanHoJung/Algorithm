#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w[21][21];
int main(void) {

	int n;
	cin >> n;

	


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);

		}
	}


	vector<int> arr(n);

	for (int i = 0; i < n / 2; i++) {
		arr[i] = 1;

	}
	sort(arr.begin(), arr.end());

	

	
	int sum = n * 100;

	do {

		vector<int> group1;
		vector<int> group2;


		for (int i = 0; i < n; i++) {
			
			if (arr[i] == 0) {
				group1.push_back(i);
			}
			else {
				group2.push_back(i);
			}
		
		}
		
		
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n/2; i++) {
			
			for (int j = 0; j < n/2; j++) {
				if (i == j)
					continue;
				
				sum1 = sum1 + w[group1[i]][group1[j]];
				sum2 = sum2 + w[group2[i]][group2[j]];
				
			}
		}
		int total = abs(sum1 - sum2);
		sum = min(total, sum);

	} while (next_permutation(arr.begin(), arr.end()));
	
	cout << sum << "\n";
}