#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxVal = 0;
vector<pair<int, int>> timeTable;

void go(int day, int sum) {

	if (day ==n) {
		maxVal = max(maxVal, sum);
		return;
	}
	if (day > n)
		return;
	
	go(day + timeTable[day].first, sum + timeTable[day].second);
	go(day + 1, sum);

}

int main(void) {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		timeTable.push_back(make_pair(t, p));
	}

	go(0, 0);

	cout << maxVal << "\n";
}