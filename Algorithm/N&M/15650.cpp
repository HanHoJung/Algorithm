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
	}

	for (int i = start; i <= n; i++) {
		if (check[i])continue;
		check[i] = true;
		seq[index] = i;
		solve(i, n, m, index + 1);
		seq[index] = 0;
		check[i] = false;
	}
}

//방법:수를 기준으로 그 기준으로 파악

void solve2(int n, int m, int checked, int index) {

	
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	if (checked > n) {
		return;
	}

	seq[index] = checked;
	solve2(n, m, checked + 1, index + 1);
	seq[index] = 0;
	solve2(n, m, checked + 1, index);


}

int main(void) {
	int n, m;
	cin >> n >> m;
	/*solve(1,n, m, 0);*/
	solve2(n, m, 1, 0);

}