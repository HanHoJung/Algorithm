#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


vector<int> convert(int i) {
	vector<int> dir(10, 0);

	int k = 0;
	while (i / 4 != 0) {
		dir[k++] = i % 4;
		i = i / 4;
	}
	dir[k] = i % 4;

	return dir;
}

bool simulation(vector<string> &a, int &x, int &y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
		a[x][y] = '.';
		x = nx;
		y = ny;
		return true;
	}

	if (a[nx][ny] == '#') {
		return false;
	}

	if (a[nx][ny] == 'o') {
		a[x][y] = '.';
		a[nx][ny] = 'o';
		x = nx;
		y = ny;
		return false;
	}

	if (a[nx][ny] == '.') {
		a[x][y] = '.';
		a[nx][ny] = 'o';
		x = nx;
		y = ny;
		return false;

	}

}

int button(vector<string> MAP, vector<int> dir) {
	int fx, fy;
	int sx, sy;

	bool next = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (MAP[i][j] == 'o' && next == false) {
				fx = i;
				fy = j;
				next = true;
			}
			else if (MAP[i][j] == 'o' && next == true) {
				sx = i;
				sy = j;

			}
		}
	}


	vector<string> temp = MAP;

	bool check1 = false;
	bool check2 = false;
	for (int i = 0; i < dir.size(); i++) {
		check1 = simulation(temp, fx, fy, dir[i]);
		check2 = simulation(temp, sx, sy, dir[i]);

		if (fx == sx && fy == sy)
			return 0;

		if (check1 == true && check2 == true) {//둘 다 떨어진 경우
			return 0;//성립할 수 없음
		}
		if (check1) {//떨어진 경우
			return i + 1;

		}

		if (check2)//떨어진 경우
			return i + 1;
	}

	if (check1 == false && check2 == false)
		return 0;
}


int main(void) {
	vector<string> MAP(21);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> MAP[i];

	int ans = -1;
	for (int i = 0; i < (1 << 20); i++) {

		vector<int> dir = convert(i);

		int check = button(MAP, dir);

		if (check == 0)
			continue;

		if (ans == -1 || ans > check)
			ans = check;
		
	}

	if (ans == -1)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}