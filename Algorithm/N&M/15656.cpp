#include <iostream>
#include <algorithm>
using namespace std;


int digit[7];
int a[7];
bool check[7];


void go(int n, int m, int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", digit[a[i]]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {

		a[cnt] = i;
		go(n, m, cnt + 1);
	}

}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &digit[i]);
	}
	sort(digit, digit + n);

	go(n, m, 0);


}