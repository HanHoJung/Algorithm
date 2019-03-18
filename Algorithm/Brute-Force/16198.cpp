#include <iostream>
#include <vector>
using namespace std;
int n;
bool check[11];
long long m = -1;
void go(vector<long long> arr,int size, long long mul) {
	if (size == 2) {
		if (m < mul)
			m = mul;
		return;
	}

	for (int i = 1; i < arr.size() - 1; i++) {

		int value = arr[i - 1] * arr[i + 1];
		int temp = arr[i];
		arr.erase(arr.begin() + i, arr.begin() + i + 1);
		go(arr, size - 1, mul + value);
		arr.insert(arr.begin() + i, temp);
		
	}
}
int main(void) {
	cin >> n;
	vector<long long> arr(n);

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	go(arr,n,0);
	cout << m << "\n";

}