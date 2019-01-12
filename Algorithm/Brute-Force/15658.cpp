#include <iostream>
#include <algorithm>
using namespace std;

int n;
int express[11];
int oper[11];
int arr[11];

int minVal = 1000000000;
int maxVal = -1000000000;
void go(int cnt) {

	if (cnt == n - 1) {

		int sum = express[0];
		int k = 1;
		for (int i = 0; i < cnt; i++) {

			if (arr[i] == 0)
				sum = sum + express[k++];

			if (arr[i] == 1)
				sum = sum - express[k++];

			if (arr[i] == 2)
				sum = sum * express[k++];

			if (arr[i] == 3)
				sum = sum / express[k++];

		}

		maxVal = max(sum, maxVal);
		minVal = min(sum, minVal);
		return;


	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			arr[cnt] = i;
			go(cnt + 1);
			oper[i]++;
		}
	}
}


int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &express[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}


	go(0);
	cout << maxVal << "\n";
	cout << minVal << "\n";
}