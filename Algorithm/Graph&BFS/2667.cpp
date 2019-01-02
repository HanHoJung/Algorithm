#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visit[26][26];
int weight[26][26];
vector<int> arr;
int n;
int call;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << '\n';
	}
	
}


bool isboundary(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n)
		return true;
	else
		return false;
}



int dfs(int i, int j, int cnt) {

	for (int k = 0; k < 4; k++) {
		int next_i = dx[k] + i;
		int next_j = dy[k] + j;

		if (isboundary(next_i, next_j))
			continue;

		if (weight[next_i][next_j] == 1 && visit[next_i][next_j] == false) {
			visit[next_i][next_j] = true;
			/*Print();*/
			cnt = dfs(next_i, next_j, cnt + 1);
		}
	}
	return cnt;
}



int bfs(int i, int j,int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = true;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (isboundary(new_x, new_y))
				continue;	
			if (weight[new_x][new_y] == 1 && visit[new_x][new_y] == false) {
				visit[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
				cnt++;
			}


		}

	}
	return cnt;

}


int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;

		for (int j = 0; j < n; j++) {
			scanf("%1d", &input);
			weight[i][j] = input;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false && weight[i][j] == 1) {
				visit[i][j] = true;
				call++;
				/*arr.push_back(dfs(i, j, 1));*/
				arr.push_back(bfs(i, j,1));
			
			}
		}

	}
	sort(arr.begin(), arr.end());
	cout << call << "\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}



}
