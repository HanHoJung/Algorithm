#include <iostream>
#define INDEX 8
using namespace std;

//방법:자리를 정해놓고 길이가 M인 수열을 모두 출력
int seq[INDEX];
bool check[INDEX];

void solve(int start, int n, int m, int index) {

	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++) {
		seq[index] = i;
		solve(i, n, m, index + 1);
		seq[index] = 0;
	}
}

int cnt[INDEX];
void solve2(int n, int m, int checked, int index) {

	if (index == m) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt[i]; j++) {
				cout << i << " ";

			}
		}
		cout << "\n";
		return;
	}

	if (checked > n) {
		return;
	}

	for (int i = m - index; i >= 1; i--) {
		cnt[checked] = i;
		solve2(n, m, checked +1, index + i);

	}
	cnt[checked] = 0;
	solve2(n, m, checked + 1, index);

}


int main(void) {
	int n, m;
	cin >> n >> m;
	solve(1,n, m, 0);
	/*solve2(n, m, 1, 0);*/


}