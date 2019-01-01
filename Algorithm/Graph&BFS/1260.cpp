#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[1001];
bool check[1001];

void dfs(int node) {

	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < edge[node].size();i++) {
		int next = edge[node][i];
		if (check[next] == false) {
			dfs(next);
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