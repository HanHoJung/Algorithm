#include <iostream>
#include <queue>;
using namespace std;
int dist[101][101];
bool edge[101][101];
bool check[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1};

int n, m;


int main(void) {

	cin >> n >> m;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			scanf("%1d", &edge[i][j]);
		
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	check[1][1] = true;


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > m)
				continue;

			if (check[new_x][new_y] == false && edge[new_x][new_y] == 1) {
				check[new_x][new_y] = true;
				dist[new_x][new_y] = dist[x][y] + 1;
				q.push(make_pair(new_x, new_y));
			}
		}

	}


	cout << dist[n][m] + 1 << "\n";


}