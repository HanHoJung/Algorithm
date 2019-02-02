#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
pair<bool, bool> simulate(vector<string> &MAP, int &x, int &y, int k);
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<int> gen(int i) {
	vector<int> arr(10);
	int input = i;
	int k = 0;
	while (i != 0) {
		arr[k++] = i & 3;//0~3사이의 수만 나오게됨
		i = i >> 2;//%2 연산

	}
	return arr;

}

bool valid(vector<int> direction) {

	int n = direction.size();
	for (int i = 0; i + 1 < n; i++) {
		if (direction[i] == 0 && direction[i + 1] == 1)
			return false;
		if (direction[i] == 1 && direction[i + 1] == 0)
			return false;
		if (direction[i] == 2 && direction[i + 1] == 3)
			return false;
		if (direction[i] == 3 && direction[i + 1] == 2)
			return false;
		if (direction[i] == direction[i + 1])
			return false;
	}
	return true;

}


int check(vector<string> MAP, vector<int> direction) {

	int n = MAP.size();
	int m = MAP[0].size();

	int hx, hy, rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 'O') {
				hx = i; hy = j;
			}
			else if (MAP[i][j] == 'R') {
				rx = i; ry = j;
			}
			else if (MAP[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}



	int cnt = 0;
	for (int k = 0; k < direction.size(); k++) {
		cnt = cnt + 1;
		bool r_hole = false;
		bool b_hole = false;

		while (true) {

			pair<bool, bool> p1 = simulate(MAP, rx, ry, direction[k]);//방문여부,hole
			pair<bool, bool> p2 = simulate(MAP, bx, by, direction[k]);

			if (p1.first == false && p2.first == false)
				break;
			if (p1.second)
				r_hole = true;
			if (p2.second)
				b_hole = true;
		}
		if (b_hole)
			return -1;

		if (r_hole)
			return cnt;
	}
	return -1;
}


pair<bool, bool> simulate(vector<string> &MAP, int &x, int &y, int k) {

	if (MAP[x][y] == '.')
		return make_pair(false, false);
	int n = MAP.size();
	int m = MAP[0].size();
	bool moved = false;
	while (true) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			return make_pair(moved, false);
		}

		if (MAP[nx][ny] == '#') {
			return make_pair(moved, false);
		}
		else if (MAP[nx][ny] == 'O') {
			MAP[x][y] = '.';
			moved = true;
			return make_pair(moved, true);
		}
		else if (MAP[nx][ny] == '.') {
			swap(MAP[nx][ny], MAP[x][y]);
			x = nx;
			y = ny;
			moved = true;
		}
		else if (MAP[nx][ny] == 'R' || MAP[nx][ny] == 'B') {
			return make_pair(moved, false);
		}

	}
	return make_pair(false, false);

}


int main(void) {
	cout <<  (1 << 20) << "\n";
	

	int n, m;
	cin >> n >> m;
	vector<string> MAP(n);

	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}

	int ans = -1;
	for (int i = 0; i < (1 << 20); i++) {
		auto direction = gen(i);
		if (!valid(direction))
			continue;
		int cnt = check(MAP, direction);
		if (cnt == -1)
			continue;
		if (ans == -1 || cnt < ans) {
			ans = cnt;
		}
	}
	cout << ans << "\n";

}