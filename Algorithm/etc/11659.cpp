#include <cstdio>
int d[100001];
int arr[100001];
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		d[i] = d[i - 1] + arr[i];
	}


	while (m--) {

		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", d[e] - d[s - 1]);


	}

}