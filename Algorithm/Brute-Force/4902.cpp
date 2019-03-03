#include <iostream>
#include <algorithm>
using namespace std;
int a[401][800];
int s[401][800];
int n;
int m;

void go(int row, int left, int right, int total) {

	if (row<1 || row>n)
		return;

	if ((left < 1) || (right > (2 * row - 1)))
		return;

	int sum = total + s[row][right] - s[row][left - 1];
	m = max(sum, m);

	if (left % 2 == 0) {//礎熱檣 唳辦
		go(row - 1, left - 2, right, sum);
	}
	else {//�汝鶺帡瞈�
		go(row + 1, left, right + 2, sum);
	}

}


int main(void) {
	int tc = 1;
	while (true) {
		m = -100000;
		cin >> n;
		if (n == 0)
			break;


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				cin >> a[i][j];
				s[i][j] = s[i][j - 1] + a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				go(i, j, j, 0);
			}
		}

		cout << tc << ". " << m << '\n';

		tc++;

	}

	return 0;
}

