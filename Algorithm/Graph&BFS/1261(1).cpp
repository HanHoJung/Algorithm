/*
 ���� �μ��� �ּҰ�
 ����ġ(�ּҷ� ���ϴ� ��)
 ���� �μ� Ƚ��== ����ġ

 0->0 (����ġ0)4��
 0->1 (����ġ1)4��
  ���� �ּ������� �ν����ϱ⶧���� ���� �ִٸ� ���
  ���� �����ֵ��� ���־���Ѵ�.

��,��,��,�� 0->0 ����ġ 0
��,��,��,�� 1->1 ����ġ 1

*/

#include <iostream>
#include <queue>
using namespace std;

int miro[101][101];
bool check[101][101];
int dist[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main(void) {
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &miro[i][j]);

		}
	}


	deque<pair<int, int>> q;
	q.push_front(make_pair(1, 1));
	check[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > m)
				continue;



			if (miro[new_x][new_y] == 0 && check[new_x][new_y] == false) {
				check[new_x][new_y] = true;
				q.push_front(make_pair(new_x, new_y));
				dist[new_x][new_y] = dist[x][y];

			}

			if (miro[new_x][new_y] == 1 && check[new_x][new_y] == false) {
				check[new_x][new_y] = true;
				q.push_back(make_pair(new_x, new_y));
				dist[new_x][new_y] = dist[x][y] + 1;
			}


		}


	}

	cout << dist[n][m] << "\n";


}
