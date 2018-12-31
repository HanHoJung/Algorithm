#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
bool check[MAX];
int prime[MAX];
int pn;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i * 2; j <= MAX; j = j + i) {
				check[j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		
		for (int i = 1; i < pn; i++) {//i�� 1���� ������ ������ �Ҽ� 2�� ���� ���ؼ��̴�.
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
		

	}
}