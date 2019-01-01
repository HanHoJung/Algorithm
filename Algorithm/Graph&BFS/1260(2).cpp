#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m, v;
struct Edge {
	int from;
	int to;
};
Edge edge[20001];//10,000*2
int cnt[1001];
bool check[1001];
bool cmp(const Edge &e1, const Edge &e2) {
	if (e1.from == e2.from)
		return e1.to < e2.to;
	else
		return e1.from < e2.from;

}

void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = cnt[node - 1]; i < cnt[node]; i++) {
		int next = edge[i].to;
		if (check[next] == false) {
			dfs(next);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = cnt[node - 1]; i < cnt[node]; i++) {
			int next = edge[i].to;
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		//start=>end
		edge[i].from = start;
		edge[i].to = end;

		//end=>start
		edge[i + m].from = edge[i].to;
		edge[i + m].to = edge[i].from;

	}
	m = 2 * m;
	sort(edge, edge + m, cmp);

	for (int i = 0; i < m; i++) {
		cnt[edge[i].from]++;
	}

	//´©ÀûÇÕ
	for (int i = 1; i <= n;i++) {
		cnt[i] = cnt[i - 1] + cnt[i];

	}
	dfs(v);
	memset(check, false, sizeof(check));
	cout << "\n";
	bfs(v);
	cout << "\n";
	return 0;

}

