#include <iostream>
#include <vector>
using namespace std;

long long d[100001];
int main(void) {
	int n, sum;
	cin >> n >> sum;

	vector<int> coin(n);

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	d[0] = 1;


	for (int k = 0; k < coin.size(); k++) {

		for (int i = 1; i <= sum; i++) {
			if (i - coin[k] >= 0)
				d[i] += d[i - coin[k]];
		}
	}
	cout << d[sum] << "\n";
}

