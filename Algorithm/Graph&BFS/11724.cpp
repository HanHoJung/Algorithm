#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
int cnt;
int num;
bool visit[20000];
vector<int> edge[20000];

void dfs(int node) {

	visit[node] = true;
	for (int i = 0; i < edge[node].size(); i++) {
		num++;
		int next = edge[node][i];
		if (visit[next] == false) {

			dfs(next);

		}
	}

}

void bfs(int node) {

	queue<int> q;
	q.push(node);
	visit[node] = true;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (int i = 0; i < edge[node].size(); i++) {

			int next = edge[node][i];

			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}

		}

	}

}


int main(void) {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		edge[input1 - 1].push_back(input2 - 1);
		edge[input2 - 1].push_back(input1 - 1);
	}

	for (int i = 0; i < n; i++) {

		if (visit[i] == false) {
			/*dfs(i);*/
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;

}