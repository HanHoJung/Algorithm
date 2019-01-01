#include <iostream>
#include <vector>

using namespace std;

bool check[2001];//간선 방문 check배열
vector<int> edge[2001];//인접리스트

int n, m;//정점 개수:n, edge 개수:m

bool dfs(int node, int depth) {
	bool decision = false;


	if (depth == 4)
		return true;

	for (int i = 0; i < edge[node].size(); i++) {
		int next = edge[node][i];
		if (check[next] == false) {
			check[next] = true;
			decision = dfs(next, depth + 1);
			check[next] = false;
		}
		if (decision)
			return decision;
	}

	return decision;

}


int main(void) {

	bool decision;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		edge[start].push_back(end);
		edge[end].push_back(start);
	}

	for (int i = 0; i < n; i++) {
		
		check[i] = true;
		decision = dfs(i, 0);
		check[i] = false;

		if (decision)
			break;
	}

	if (decision)
		cout << '1';
	else
		cout << '0';

}
