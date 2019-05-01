#include <iostream>
using namespace std;
bool visit[17][17];
int MAP[17][17];
int n;
int cnt;

int gx[] = { 0,1 };
int gy[] = { 1,1 };

int sx[] = { 1,1 };
int sy[] = { 0,1 };

int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

bool bound(int x, int y) {
	if (x <= 0 || x > n || y <= 0 || y > n)
		return false;

	else
		if (visit[x][y]==true || MAP[x][y] == 1)
			return false;
		else
			return true; 
}

bool cross(int x, int y) {
	if (MAP[x][y]==0 && visit[x][y]==false&&MAP[x - 1][y] == 0 && visit[x][y - 1] == 0 && visit[x - 1][y] == false && visit[x][y - 1] == false)
		return true;
	else
		return false;
}

void output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}
void go(int dir, int x, int y) {
	if (x == n && y == n) {
		cnt++;
	/*	output();
		_getch();
		cout << "\n";*/
		return;
	}

	
	
	if (dir == 0) {
		for (int k = 0; k < 2; k++) {
			if (k == 0) {//가로
				int nx = x + gx[k];
				int ny = y + gy[k];
				if (bound(nx, ny)) {
					visit[nx][ny] = true;
					go(0, nx, ny);
					visit[nx][ny] = false;

				}

				
			}
			else {//대각선
				int nx = x + gx[k];
				int ny = y + gy[k];

				if (bound(nx, ny)) {

					if (cross(nx, ny)) {
						visit[nx][ny] = true;
						go(2, nx, ny);
						visit[nx][ny] = false;

					}

				}
			}

		}
		return;
	}

	if (dir == 1) {
		for (int k = 0; k < 2; k++) {
			if (k == 0) {//세로
				int nx = x + sx[k];
				int ny = y + sy[k];
				if (bound(nx, ny)) {
					visit[nx][ny] = true;
					go(1, nx, ny);
					visit[nx][ny] = false;

				}


			}
			else {//대각선
				int nx = x + sx[k];
				int ny = y + sy[k];

				if (bound(nx, ny)) {
					
					if (cross(nx, ny)) {
						visit[nx][ny] = true;
						go(2, nx, ny);
						visit[nx][ny] = false;

					}
				}
			}

		}
		return;
	}


	if (dir == 2) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {//가로
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (bound(nx, ny)) {
					visit[nx][ny] = true;
					go(0, nx, ny);
					visit[nx][ny] = false;

				}


			}
			else if(k==1) {//세로

				int nx = x + dx[k];
				int ny = y + dy[k];
				if (bound(nx, ny)) {
					visit[nx][ny] = true;
					go(1, nx, ny);
					visit[nx][ny] = false;

				}
				
			}
			else {//대각선

				int nx = x + dx[k];
				int ny = y + dy[k];

				if (bound(nx, ny)) {

					if (cross(nx, ny)) {
						visit[nx][ny] = true;
						go(2, nx, ny);
						visit[nx][ny] = false;
						
					}

				}
			}

		}

		return;
	}

}
int main(void) {
	cin >> n;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j<= n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				visit[i][j] = true;
		}
	}

	visit[1][1] = true;
	visit[1][2] = true;
	go(0, 1, 2);
	cout << cnt << "\n";

}