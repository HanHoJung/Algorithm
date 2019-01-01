#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> edge[1001];
bool check[1001];


void dfs(int start) {
	stack<pair<int, int>> stack;
	stack.push(make_pair(start,0));
	check[start] = true;
	printf("%d ", start);
	
	while (!stack.empty()) {
		int node = stack.top().first;
		int index = stack.top().second;
		stack.pop();
		for (int i = index; i < edge[node].size();i++) {
			int next = edge[node][i];
			if (check[next] == false) {
				printf("%d ", next);
				check[next] = true;
				stack.push(make_pair(node, index + 1));
				stack.push(make_pair(next, 0));
				break;
			}
		}
	}

}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty()) {
		int node = q.front();
		printf("%d ", node);
		q.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}

	}


}


int main(void) {


	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);

	for (int i = 1; i <= m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		edge[u].push_back(v);
		edge[v].push_back(u);

	}

	for (int i = 1; i <= n;i++) {
		sort(edge[i].begin(), edge[i].end());
	}

	dfs(start);
	printf("\n");
	memset(check, false, sizeof(check));
	bfs(start);
	printf("\n");
}