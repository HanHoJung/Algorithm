#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;
int n, m;

int dx[] = { 0,0,1,-1};
int dy[] = { 1,-1,0,0};

pair<int, int> simulate(vector<string> &MAP, int &x, int &y, int direction) {
	if (MAP[x][y] == '.') return make_pair(false, false);
	bool moved = false;

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (nx < 0 || nx >= n || ny < 0|| ny >= m)
			return make_pair(moved, false);

		if(MAP[nx][ny]=='#')
			return make_pair(moved, false);

		if(MAP[nx][ny]=='R'|| MAP[nx][ny]=='B')
			return make_pair(moved, false);

		if (MAP[nx][ny] == '.') {
			swap(MAP[nx][ny], MAP[x][y]);
			x = nx;
			y = ny;
			moved = true;
		}

		if (MAP[nx][ny] == 'O') {
			MAP[x][y] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}

}


pair<int, int> go(vector<string> MAP, int &nrx, int &nry, int &nbx, int &nby, int direction) {

	MAP[nrx][nry] = 'R';
	MAP[nbx][nby] = 'B';


	bool holeA=false;
	bool holeB = false;

	while (true) {

		auto A_result = simulate(MAP,nrx,nry,direction);
		auto B_result = simulate(MAP,nbx, nby, direction);

		if (A_result.first == false && B_result.first == false)
			break;

		if (B_result.second==true) {
			holeB = true;
			
		}

		if (A_result.second == true) {
			holeA = true;
			
		}

	}

	return make_pair(holeA, holeB);

}
int main(void) {
	int rx, ry, bx, by, hx, hy;
	cin >> n >> m;
	vector<string> MAP(n);
	int dist[10][10][10][10];
	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 'R') {
				rx = i;
				ry = j;
				MAP[i][j] = '.';
			}

			if (MAP[i][j] == 'B') {
				bx = i;
				by = j;
				MAP[i][j] = '.';
			}

			if (MAP[i][j] == 'O') {
				hx = i;
				hy = j;
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int, int>> q;
	q.emplace(rx, ry, bx, by);
	dist[rx][ry][bx][by] = 0;
	int ans = -1;
	bool decision = false;
	while (!q.empty()) {

		tie(rx, ry, bx, by) = q.front();
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;

			auto check = go(MAP,nrx, nry, nbx, nby, i);

			if (check.second)//파란구슬이 홀에 들어간 경우
				continue;

			if (check.first) {//빨간구슬이 홀에 들어간 경우
				decision = true;
				ans = dist[rx][ry][bx][by] + 1;
				break;

			}


			if (dist[nrx][nry][nbx][nby] == -1) {
				dist[nrx][nry][nbx][nby] = dist[rx][ry][bx][by] + 1;
				q.emplace(nrx, nry, nbx, nby);
			}


		}

		if (decision)
			break;
	}


	
		cout << -1 << "\n";
	
}