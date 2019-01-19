#include <iostream>
#include <queue>
using namespace std;
int dist[100001];
bool check[100001];
int dp[100001];
int main(void) {

	int n, m;
	cin >> n >> m;

	queue<int> q;
	q.push(n);
	check[n] = true;
	dp[n] = 1;

	while (!q.empty()) {
		int node = q.front();//ÇöÀç node
		q.pop();

		for (int new_node : {node - 1, node + 1, node * 2}) {
			if (new_node >= 0 && new_node <= 100000) {
				if (check[new_node] == false) {
					check[new_node] = true;
					dist[new_node] = dist[node] + 1;
					dp[new_node] = dp[node];
					q.push(new_node);

				}
				else if (dist[node] < dist[new_node]) {//dist[node]+1==dist[new_node]
					dp[new_node] = dp[new_node] + dp[node];
				}
			}
		}

	}

	cout << dist[m] << "\n";
	cout << dp[m] << "\n";


}