#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> bfs(vector<string> &MAP, int x, int y) {

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	int n = MAP.size();
	int m = MAP[0].size();

	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(m, -1));
	q.push(make_pair(x, y));
	dist[x][y] = 0;

	while (!q.empty()) {

		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
				continue;

			if (dist[new_x][new_y] != -1)
				continue;


			if (MAP[new_x][new_y] == 'x')
				continue;


			dist[new_x][new_y] = dist[x][y] + 1;
			q.push(make_pair(new_x, new_y));


		}
	}





	return dist;


}

int main(void) {

	while (true) {
		int n, m;
		cin >> m >> n;//세로,가로 길이
		vector<string> MAP(n);


		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> MAP[i];
		}

		vector<pair<int, int>> sp(1);//search point(시작과 청소 좌표)

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (MAP[i][j] == 'o') {
					sp[0] = make_pair(i, j);

				}
				else if (MAP[i][j] == '*') {
					sp.push_back(make_pair(i, j));
				}

			}
		}


		int length = sp.size();
		vector<vector<int>> result(length, vector<int>(length, 0));
		bool check = false;
		for (int i = 0; i < length; i++) {

			auto dist = bfs(MAP, sp[i].first, sp[i].second);

			for (int j = 0; j < length; j++) {
				result[i][j] = dist[sp[j].first][sp[j].second];
				if (result[i][j] == -1) {
					check = true;
				}

			}
		}

		if (check) {
			cout << -1 << "\n";
			continue;
		}


		vector<int> permutation;

		for (int i = 0; i < length - 1; i++) {
			permutation.push_back(i + 1);
		}


		
		
		int ans = -1;
		do {

			int now = result[0][permutation[0]];
			

			for (int i = 0; i < length - 2; i++) {
				now = now + result[permutation[i]][permutation[i + 1]];
			}

			if (ans == -1 || ans > now)
				ans = now;


		} while (next_permutation(permutation.begin(), permutation.end()));
		cout << ans << "\n";
	}


}