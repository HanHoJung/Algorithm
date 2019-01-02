#include <queue>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
bool visit[20001];
bool color[20001];
vector<int> edge[20001];

void dfs2(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}

void dfs(int node, bool setColor) {
	visit[node] = true;
	color[node] = setColor;

	for (int i = 0; i < edge[node].size(); i++) {

		int next = edge[node][i];
		if (visit[next] == false) {
			color[next] = !setColor;
			dfs(next, !setColor);
		}

	}
}


void bfs(int start, bool setColor) {
	queue<int> q;
	visit[start] = true;
	color[start] = setColor;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		setColor = !color[node];
		q.pop();
		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i];
			if (visit[next] == false) {
				visit[next] = true;
				color[next] = setColor;
				q.push(next);
			}

		}

	}

}


int main(void) {
	int k;//testÀÇ °³¼ö
	scanf("%d", &k);

	while (k--) {

		int v, e;
		scanf("%d %d", &v, &e);

		memset(edge, 0, sizeof(edge));
		memset(visit, false, sizeof(visit));
		memset(color, false, sizeof(color));

		for (int i = 0; i < e; i++) {
			int start, end;
			scanf("%d %d", &start, &end);

			edge[start].push_back(end);
			edge[end].push_back(start);
		}


		for (int i = 1;i <= v; i++) {

			if (visit[i] == false)
				bfs(i, true);
			/*dfs(i, true);*/


		}

		bool output = true;

		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (color[i] == color[edge[i][j]]) {
					output = false;
					break;
				}

			}
		}

		if (output == true) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";

		}

	}

}
