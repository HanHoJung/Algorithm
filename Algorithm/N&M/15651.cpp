#include <iostream>
#define INDEX 8
using namespace std;

//���:�ڸ��� ���س��� ���̰� M�� ������ ��� ���
int seq[INDEX];
bool check[INDEX];

void solve(int n, int m, int index) {

	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		seq[index] = i;
		solve(n, m, index + 1);
		seq[index] = 0;
	}
}



int main(void) {
	int n, m;
	cin >> n >> m;
	solve(n, m, 0);
	

}