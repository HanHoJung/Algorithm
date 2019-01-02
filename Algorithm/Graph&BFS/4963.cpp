#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool visit[50][50];
int weight[50][50];
int w, h;
int dx[] = { 1,-1,0,0,-1,-1,1,1 };
int dy[] = { 0,0,1,-1,-1,1,-1,1 };

bool boundaryCheck(int new_x, int new_y) {

	if (new_x >= h || new_x < 0 || new_y >= w || new_y < 0||weight[new_x][new_y]==0)
		return false;
	else
		return true;


}
void bfs(int start, int end) {

	queue<pair<int, int>> q;
	q.push(make_pair(start, end));
	visit[start][end] = true;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int new_x = i + dx[k];
			int new_y = j + dy[k];
			if (boundaryCheck(new_x, new_y) && visit[new_x][new_y] == false) {
				q.push(make_pair(new_x, new_y));
				visit[new_x][new_y] = true;
			}
		}
	}
}

void dfs(int x, int y) {

	visit[x][y] = true;

	for (int k = 0; k < 8; k++) {
		int new_x = x + dx[k];
		int new_y = y + dy[k];

		if (boundaryCheck(new_x, new_y) && visit[new_x][new_y] == false) {
			
			dfs(new_x, new_y);
		}
	}



}


int main(void) {

	while (true) {

		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		memset(visit, false, sizeof(visit));
		memset(weight, 0, sizeof(weight));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int input;
				cin >> input;
				weight[i][j] = input;

			}
		}

		int result = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				
				if (weight[i][j] == 1 &&visit[i][j]==false) {
					
					/*bfs(i, j);*/
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << "\n";

	}





}