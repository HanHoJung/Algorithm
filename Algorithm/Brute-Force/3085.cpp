
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> MAP(51);
bool visit[51][51];
int candy;
int n;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool next(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return false;
	
	return true;
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}
}

int search(char color, int x, int y) {
	int up = 1;
	int down = 1;

	for (int i = x + 1; i < n; i++) {
		if (MAP[i][y] != color)
			break;

		up++;
	}

	for (int i = y + 1; i < n; i++) {
		if (MAP[x][i] != color)
			break;

		down++;
	}

	if (up > down)
		return up;
	else
		return down;

}





void go(int cnt) {

	if (cnt == 1) {
		int val;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				val = search(MAP[i][j], i, j);
				candy = max(val, candy);

				if (candy == n) {
					cout << n << "\n";
					exit(0);
				}

			}
		}
		return;
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (!next(nx, ny))
					continue;

				if (MAP[x][y] == MAP[nx][ny])
					continue;

				swap(MAP[x][y], MAP[nx][ny]);
				go(cnt + 1);
				swap(MAP[x][y], MAP[nx][ny]);
				
			}

		}
	}
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> MAP[i];

	go(0);
	cout << candy << "\n";
}