#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool check[1001][1001][2];
int dist[1001][1001][2];
int edge[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main(void) {
	
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &edge[i][j]);
		}
	}


	queue<pair<pair<int, int>, bool>> q;
	q.push(make_pair(make_pair(1, 1), false));
	dist[1][1][0] = 1;
	check[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool destory = q.front().second;
		q.pop();

		/*cout << "(" << x << "," << y << "," << destory << ")  ";
		cout << "//°¡ÁßÄ¡:" << dist[x][y][destory] << "\n";
*/
		if (x == n && y == m)
			break;
		
		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			
			if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > m)
				continue;
			
			if (destory) {
				if (edge[new_x][new_y] == 0 && check[new_x][new_y][destory] == false) {
					
					check[new_x][new_y][destory] = true;
					dist[new_x][new_y][destory] = dist[x][y][destory] + 1;
					q.push(make_pair(make_pair(new_x, new_y), destory));
				}
			}
			else {

				if (edge[new_x][new_y] == 0 && check[new_x][new_y][destory] == false) {
					check[new_x][new_y][destory] = true;
					dist[new_x][new_y][destory] = dist[x][y][destory] + 1;
					q.push(make_pair(make_pair(new_x, new_y), destory));
				}

				if (edge[new_x][new_y] == 1 && check[new_x][new_y][1] == false) {
					check[new_x][new_y][1] = true;
					dist[new_x][new_y][1] = dist[x][y][destory] + 1;
					q.push(make_pair(make_pair(new_x, new_y), true));
				}


			}

		}

	}
	
	int maxVal = max(dist[n][m][0], dist[n][m][1]);

	if (dist[n][m][0] || dist[n][m][1]) {
		cout << maxVal << "\n";
	}
	else {
		cout << "-1" << "\n";
	}
}