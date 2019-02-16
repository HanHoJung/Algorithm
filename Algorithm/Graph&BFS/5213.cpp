#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int n;
int Tile[500][500][2];
int dist[500][500];
pair<int,int> from[500][500];
bool check[500][500];

int dx0[] = { -1, 0, 1, 1, 0, -1 };
int dy0[] = { -1, -1, -1, 0, 1, 0 };

int dx1[] = { -1, 0, 1, 1, 0, -1 };
int dy1[] = { 0, -1, 0, 1, 1, 1 };


bool boundCheck(int x, int y) {
	
	if (x < 0 || x >= n) return false;
		
	if (x % 2 == 0) {//È¦¼öÇà
		
		return y >= 0 && y < n;
	}
	else {//Â¦¼öÇà
		
		return y >= 0 && y < n-1;
	}
}


bool next(int x, int y, int nx, int ny) {

	if (x != nx) {//ÇàÀÌ ´Ù¸¥ °æ¿ì

		if (x % 2 == 0) {//È¦¼öÇà

			if (y == ny) {
				return Tile[x][y][1] == Tile[nx][ny][0];
			}
			else {
				return Tile[x][y][0] == Tile[nx][ny][1];
			}

		}
		else {//Â¦¼öÇà
			if (y == ny) {
				return Tile[x][y][0] == Tile[nx][ny][1];
			}
			else {
				return Tile[x][y][1] == Tile[nx][ny][0];
			}
		}

	}
	else {//ÇàÀÌ °°Àº °æ¿ì

		if (y < ny)
			return Tile[x][y][1] == Tile[nx][ny][0];
		else
			return Tile[x][y][0] == Tile[nx][ny][1];

	}

}

int square(int x, int y) {

	int area = x / 2 * (n*2 - 1);

	if (x % 2 != 0)
		area = area + n;

	area = area + y+1;

	return area;

}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> Tile[i][j][0];
			cin >> Tile[i][j][1];
		}
		if (i % 2 == 0) {
			cin >> Tile[i][n - 1][0];
			cin >> Tile[i][n - 1][1];
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;
	from[0][0] = make_pair(0, 0);

	while (!q.empty()) {
		int x, y;
		tie(x,y) = q.front();
		q.pop();
		

		for (int i = 0; i < 6; i++) {
			int nx;
			int ny;
			if (x %2 == 0) {//È¦¼ö
				nx = x + dx0[i];
				ny = y + dy0[i];
			}
			else {//Â¦¼ö
				nx = x + dx1[i];
				ny = y + dy1[i];
			}
			if (boundCheck(nx, ny) == false) continue;	
			if (next(x, y, nx, ny) == false) continue;
			if (check[nx][ny] == false) {
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
				from[nx][ny] = make_pair(x, y);
				check[nx][ny] = true;
			}
			
		}

	}

	int x = n - 1;
	int y = n - 1;

	while (check[x][y] == false) {
		y--;
		if (y < 0) {
			x--;
			y = n - 1;

			if (y % 2 != 0)
				y--;
		}
	}
	
	cout << dist[x][y] << "\n";


	vector<pair<int,int>> result;
	while ((from[x][y].first!=x) || (from[x][y].second!=y)) {
		result.push_back(make_pair(x, y));
		int nx = from[x][y].first;
		int ny = from[x][y].second;
		x = nx;
		y = ny;

	}

	result.push_back(make_pair(x, y));
	reverse(result.begin(), result.end());

	

	for (int i = 0; i < result.size(); i++)
		cout << square(result[i].first, result[i].second) << " ";




}