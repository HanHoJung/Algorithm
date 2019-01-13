#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
char MAP[50][50];//오리지널 지도

int WMAP[50][50];//물이 차는 시간 지도
int dist[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int main(void) {
	int n, m;
	int startX, startY;
	int destX, destY;
	queue<pair<int, int>> q;
	scanf("%d %d", &n, &m);

	memset(WMAP, -1, sizeof(WMAP));
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			MAP[i][j] = c;
			if (c == 'S') {
				startX = i;
				startY = j;

			}
			else if (c == 'D') {
				destX = i;
				destY = j;

			}
			else if (c == '*') {
				q.push(make_pair(i, j));
				WMAP[i][j] = 0;

			}
			
		}
	}



	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
				continue;

			if (WMAP[new_x][new_y] != -1)
				continue;
			if (MAP[new_x][new_y] == 'X')
				continue;
			if (MAP[new_x][new_y] == 'D')
				continue;

			WMAP[new_x][new_y] = WMAP[x][y] + 1;
			q.push(make_pair(new_x, new_y));

		}
	}

	
	
	
	q.push(make_pair(startX, startY));
	dist[startX][startY] = 0;
	

	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		/*cout <<"("<< x << "," << y <<")"<<" //"<<dist[x][y]<< "\n";*/
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
				continue;

			if (dist[new_x][new_y] != -1)
				continue;

			if (MAP[new_x][new_y] == 'X')
				continue;

			if (dist[x][y] + 1 >= WMAP[new_x][new_y] && WMAP[new_x][new_y] != -1)
				continue;

			dist[new_x][new_y] = dist[x][y] + 1;
			q.push(make_pair(new_x, new_y));
		}


	}
	

	if (dist[destX][destY]!=-1) {
		cout << dist[destX][destY];
		
	}
	else {
		cout << "KAKTUS";
	}

}