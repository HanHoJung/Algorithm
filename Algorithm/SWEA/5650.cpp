#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int matrix[103][103];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int max1 = 0;

void init(int &n, map<int, vector< pair< int, int > > > &warm) {
	n = n + 2;
	for (int i = 0; i < n; i++) {
		matrix[0][i] = 5;
		matrix[n - 1][i] = 5;
		matrix[i][0] = 5;
		matrix[i][n - 1] = 5;
	}

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 2; j++) {
			int val;
			cin >> val;
			matrix[i][j] = val;

			if (val >= 6 && val <= 10) {
				warm.insert(make_pair(val,vector< pair<int,int > >()));
				warm[val].push_back(make_pair(i, j));
			}
		}
	}

}
int convert(int x, int y, int dir) {
	int block = matrix[x][y];

	if (block == 1) {
		switch (dir)
		{
		case 0:
			dir = 1;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 0;
			break;
		case 3:
			dir = 2;
			break;
		}
	}
	else if (block == 2) {
		switch (dir)
		{
		case 0:
			dir = 3;
			break;
		case 1:
			dir = 0;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 2;
			break;
		}

	}
	else if (block == 3) {
		switch (dir)
		{
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 0;
			break;
		case 2:
			dir = 3;
			break;
		case 3:
			dir = 1;
			break;
		}
	}
	else if (block == 4) {
		switch (dir)
		{
		case 0:
			dir = 1;
			break;
		case 1:
			dir = 2;
			break;
		case 2:
			dir = 3;
			break;
		case 3:
			dir = 0;
			break;
		}
	}
	else {
		switch (dir)
		{
		case 0:
			dir = 1;
			break;
		case 1:
			dir = 0;
			break;
		case 2:
			dir = 3;
			break;
		case 3:
			dir = 2;
			break;
		}
	}

	return dir;
}
int outblock(int dir) {
	switch (dir)
	{
	case 0:
		dir = 1;
		break;
	case 1:
		dir = 0;
		break;
	case 2:
		dir = 3;
		break;
	case 3:
		dir = 2;
		break;
	}
	return dir;
}

void go(int x, int y, int dir, int n, map<int, vector<pair<int, int> > > &warm) {

	int cnt = 0;
	int tx = x;
	int ty = y;
	while (true) {
		int nx = tx + dx[dir];
		int ny = ty + dy[dir];

		if (nx == x && ny == y || matrix[nx][ny] == -1) {


			break;
		}


		if (matrix[nx][ny] >= 1 && matrix[nx][ny] <= 5) {
			dir = convert(nx, ny, dir);
			cnt++;

		}
		else if (matrix[nx][ny] >= 6 && matrix[nx][ny] <= 10) {
			int key = matrix[nx][ny];

			for (int i = 0; i < 2;i++) {
				int s1, s2;
				s1 = warm[key][i].first;
				s2 = warm[key][i].second;

				if (nx == s1 && ny == s2)
					continue;

				tx = s1;
				ty = s2;
				break;

			}
			continue;
		}
		tx = nx;
		ty = ny;

	}

	if (max1 < cnt)
		max1 = cnt;



}


int main(void) {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		max1 = 0;
		map<int, vector<pair<int, int> > > warm;
		int n;;
		cin >> n;
		init(n, warm);

		for (int x = 1; x <=n - 2; x++) {
			for (int y = 1; y <= n - 2; y++) {
				if (matrix[x][y] == 0) {
					for (int k = 0; k < 4; k++) {
						go(x, y, k, n, warm);

					}
				}
			}
		}

		printf("#%d %d\n", i, max1);
	}
}