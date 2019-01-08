#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int edge[1001][1001];
int dist[1001][1001];
bool check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m, n;


int main(void) {
	cin >> m >> n;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &edge[i][j]);

			if (edge[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = true;
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

			if (new_x<0 || new_x>=n || new_y<0 || new_y>=m)
				continue;

			if (edge[new_x][new_y] ==0 && check[new_x][new_y] == false) {
				check[new_x][new_y] = true;
				dist[new_x][new_y] = dist[x][y] + 1;
				edge[new_x][new_y] = dist[new_x][new_y];
				q.push(make_pair(new_x, new_y));
			}
		}


	}


	int dayMax = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
	
			int value = edge[i][j];
			dayMax = max(dayMax, value);
			if (value == 0) {
				//�丶�䰡 ��� ���� ���� ��Ȳ
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	if (dayMax == 1) {
		//����� ������ ��� �丶�䰡 �;��ִ� ����
		cout << dayMax-1 << "\n";
		return 0;
	}
	else {
		//�ϼ� �丶��^^
		cout << dayMax << "\n";
		return 0;
	}
	

}