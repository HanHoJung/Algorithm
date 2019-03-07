#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	long long commander;
	int A, B;
	cin >> n;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> A >> B;

	for (int i = 0; i < n; i++)
		arr[i] -= A;

	commander = n;

	for (int i = 0; i < n; i++) {

		if (arr[i] <= 0)
			continue;


		int k = arr[i] % B;
		int t = arr[i] / B;
		if (k == 0)
			commander += t;
		else
			commander += t + 1;
			
	}

	cout<<commander<<"\n";



}