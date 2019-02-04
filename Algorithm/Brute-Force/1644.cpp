#include <iostream>
#include <vector>
using namespace std;
bool check[4000001];


vector<int> prime(int n) {
	vector<int> arr;
	
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			arr.push_back(i);
			
			for (int j = i * 2; j <= n; j = j + i) {  //i*i 할 경우 n이 100만 인 경우 int 범위 초과나기때문에
				check[j] = true;
			}
		}
	}
	
	return arr;
}





int main(void) {

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	vector<int> arr = prime(n);

	
	int left = 0;
	int right = 0;
	int total = arr[0];
	int size = arr.size();
	int cnt = 0;
	while (left <= right && right <size) {

		if (total > n) {
			total = total - arr[left];
			left++;
			if (left > right && left < size) {
				right = left;
				total = arr[left];
			}
		}
		else if (total == n) {
			right++;
			cnt++;
			if (right < size)
				total += arr[right];
		}
		else if (total < n) {
			right++;
			if (right < size)
				total += arr[right];
		}


	}
	cout << cnt << "\n";


}