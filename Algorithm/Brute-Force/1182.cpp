#include <iostream>
using namespace std;

int n, m;
int cnt;
int arr[21];

void go(int index, int sum) {

	if (index == n) {
		if (sum == m)
			cnt++;
		return;
	}

	go(index + 1, sum + arr[index]);
	go(index + 1, sum);
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	go(0, 0);
	if (m == 0)
		cnt--;

	cout << cnt << "\n";
}