#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main(void) {
	int n;
	cin >> n;
	vector<string> MAP(n);
	vector<pair<int, int>> label;
	for (int i = 0; i < n; i++)
		cin >> MAP[i];

	//1단계 모델링(번호 매기기)
	int num = 0;
	int start = -1, end = -1;//벽의 시작과 끝 번호


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == '#') {
				if (start == -1) {
					start = label.size();
					label.push_back(make_pair(i, j));
				}
				else {
					end = label.size();
					label.push_back(make_pair(i, j));
				}
			}
			else if (MAP[i][j] == '!') {
				label.push_back(make_pair(i, j));

			}
		}
	}

	int m = label.size();
	//2단계 정점 연결
	vector<vector<bool>> edge(m, vector<bool>(m));

	for (int i = 0; i < m; i++) {
		int x, y;
		tie(x, y) = label[i];

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (MAP[nx][ny] == '*')
					break;

				if (MAP[nx][ny] == '!' || MAP[nx][ny]=='#') {
					for (int j = 0; j < label.size(); j++) {
						int x1, y1;
						tie(x1, y1) = label[j];

						if (nx == x1 && ny == y1) {
							edge[i][j] = true;
						}
						
					}
				}
				nx = nx + dx[k];
				ny = ny + dy[k];
			}
		}
	}

	vector<int> dist(m,-1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < m; i++) {
			
			if (edge[x][i]) {
				int next = i;
				if (dist[next] == -1) {
					dist[next] = dist[x] + 1;
					q.push(next);
				}
			}
		}
	}
	

	cout << dist[end] - 1 << "\n";

}