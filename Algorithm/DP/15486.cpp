#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[1500000+51];
int main(void) {
	int n;
	cin >> n;
	vector<int> Ti(n + 1);
	vector<int> Pi(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> Ti[i];
		cin >> Pi[i];
	}


	for (int i = 1; i <= n; i++) {
		d[i + Ti[i]] = max(d[i + Ti[i]], d[i] + Pi[i]);
		d[i + 1] = max(d[i + 1], d[i]);
	}
	
	cout << d[n + 1] << "\n";
}