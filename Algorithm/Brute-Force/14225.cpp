#include <iostream>
#include <vector>
using namespace std;

bool check[2000001];

int main(void) {
	int s;
	cin >> s;
	vector<int> arr(s);
	for (int i = 0; i < s; i++)
		cin >> arr[i];

	for (int i = 0; i < (1<<s); i++) {
		int sum = 0;
		for (int j = 0; j < s; j++) {
			if (i&(1 << j))
				sum += arr[j];
		}
		check[sum] = true;
	}

	for (int i = 1; i <= 2000000; i++) {
		if (check[i]==false) {
			cout << i << "\n";
			return 0;
		}
	}
}
