#include <iostream>
#include <vector>
using namespace std;



int main(void) {
	int n, s;
	int cnt = 0;
	cin >> n >> s;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}

	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum = sum + arr[j];

			if (sum > s) {
				break;
			}

			if (sum == s) {
				cnt++;
				break;
			}
		}

	}

	cout << cnt << "\n";
}