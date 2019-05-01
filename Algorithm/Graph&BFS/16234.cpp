#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visit[51][51];
int n, L, R;
bool out = true;
int flag[51][51];

bool bfs(vector<vector<int>> &MAP,int sx, int sy, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	flag[sx][sy] = num;
	int cnt = 1;
	int sum=0;
	bool go = false;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		sum = sum + MAP[x][y];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (visit[nx][ny])
				continue;

			int diff = abs(MAP[nx][ny] - MAP[x][y]);
			if (diff >= L && diff <= R) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
				flag[nx][ny] = num;
				cnt++;
				go = true;
			}

		}
	}
	
	if (go==false)
		return false;

	sum = sum / cnt;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (num == flag[i][j]) {
				MAP[i][j] = sum;
			}
		}

	}


	return true;

}
int main(void) {
	int cnt = 0;
	cin >> n >> L >> R;
	vector<vector<int>> MAP(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	while (out) {
		out = false;
		int num = 1;
		memset(visit, false,sizeof(visit));
		memset(flag, 0,sizeof(flag));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == false) {
					visit[i][j] = true;
					bool check = bfs(MAP,i, j, num);
					num++;
					
					if (check)
						out = true;
				}

			}
		}
		if(out)
		cnt++;
	}
	cout << cnt << "\n";
}