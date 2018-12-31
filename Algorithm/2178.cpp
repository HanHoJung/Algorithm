#include <iostream>
#include <queue>
using namespace std;
bool visit[101][101];
int weight[101][101];
int myValue[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1,-1};
int n, m;
bool boundaryCheck(int i, int j) {
	
	
	if ((i <=0) || (i >= (n+1)) || (j <=0) || (j >= (m+1))) {
		cout << "check1" << "\n";
		cout << i << " " << j << "\n";
		return false;
	}
	else {
		cout << "check2" << "\n";
		cout << i << " " << j << "\n";
		
		return true;
	}
}


void bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push(make_pair(start, end));
	visit[start][end] = true;
	myValue[start][end] = 1;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int k = 0; k < 4; k++) {
			int new_x = x + dx[k];
			int new_y = y + dy[k];
			
			

			if (boundaryCheck(new_x, new_y)) {

				if(visit[new_x][new_y] == false && weight[new_x][new_y] ==1){
				
				myValue[new_x][new_y] = myValue[x][y] + 1;
				visit[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
				}


			}


		}

	}

	cout << myValue[n][m];
}


int main(void) {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int input;
			scanf("%1d", &input);
			weight[i][j] = input;
			
		}
	}


	bfs(1, 1);







}