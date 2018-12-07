#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
bool visit[1000];
vector<int> edge[1000];
void dfs(int node) {

	visit[node] = true;
	cout << node + 1 << " ";

	for (int i = 0; i < edge[node].size(); i++) {
		int next = edge[node][i];

		if (visit[next] == false) {
			visit[node] = true;
			dfs(next);
		}
	}

}

void bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node+1 << " ";

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
	int n;
	int m;
	int start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		edge[input1 - 1].push_back(input2 - 1);
		edge[input2 - 1].push_back(input1 - 1);
	}

	for (int i = 0; i <n ; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	
	
	dfs(start - 1);
	memset(visit, false, sizeof(visit));
	cout << "\n";
	bfs(start - 1);


}
