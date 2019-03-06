#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long d[100001];
int main(void) {
	int n, sum;
	cin >> n >> sum;

	vector<int> coin(n);

	for (int i = 0; i < n; i++)
		cin >> coin[i];
	
	for (int i = 1; i <= sum; i++)
		d[i] = -1;


	sort(coin.begin(), coin.end());
	for (int k = 0; k < coin.size(); k++) {
		for (int i = 1; i <= sum; i++) {
			if (i - coin[k] >= 0 && d[i - coin[k]] != -1) {
				if (d[i]==-1|| d[i - coin[k]] + 1 < d[i])
					d[i] = d[i - coin[k]] + 1;
			}


		}
	}
	
	cout << d[sum] << "\n";
}
