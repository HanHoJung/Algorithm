#include <iostream>
#include <algorithm>
using namespace std;
int n=9;
int dwaf[9];

int main(void) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &dwaf[i]);
		sum = sum + dwaf[i];
	}

	sort(dwaf, dwaf+n);

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			
			if (sum - dwaf[i] - dwaf[j] == 100) {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)
						continue;
					cout << dwaf[k] << "\n";
				}

				return 0;
			}

		}
	}
}