#include <iostream>
#include <vector>

using namespace std;
bool visit[31][12];
int n, m, h;
int minVal = -1;

bool ladder(void) {

	for (int col = 1; col <= n; col++) {
		int s = col;
		for (int row = 1; row <= h; row++) {
			if (visit[row][s]) {
				s = s + 1;
			}
			else if (s > 1 && visit[row][s - 1]) {
				s = s - 1;
			}
		}

		if (s != col)
			return false;
	}

	return true;
}

void go(int row, int cnt) {
	if (cnt <= 3) {
		bool check = ladder();
		if (check) {
			if (minVal > cnt || minVal == -1)
				minVal = cnt;
		}
	}

	if (cnt > 3)
		return;

	for (int i = row; i <= h; i++) {
		for (int j = 1; j < n; j++) {

			if (visit[i][j] == false) {
				if (visit[i][j - 1] == false && visit[i][j + 1] == false) {
					visit[i][j] = true;
					go(i, cnt + 1);
					visit[i][j] = false;
				}
			}
		}

	}

}


int main(void) {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b;
		visit[a][b] = true;
	}

	go(1, 0);
	cout << minVal << "\n";
}