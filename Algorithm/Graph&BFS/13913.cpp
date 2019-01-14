#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
pair<int, int> dist[100001];//first 가중치 second 이전 노드
bool check[100001];
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	queue<int> q;
	q.push(n);
	check[n] = true;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		if (x == k)
			break;

		if (x + 1 <= 100000 && check[x + 1] == false) {
			dist[x + 1] = make_pair(dist[x].first+1, x);
			check[x + 1] = true;
			q.push(x + 1);
		}


		if (x * 2 <= 100000 && check[x * 2] == false) {
			dist[x * 2] = make_pair(dist[x].first+1, x);
			check[x * 2] = true;
			q.push(x * 2);
		}


		if (x - 1 >= 0 && check[x - 1] == false) {
			dist[x -1] = make_pair(dist[x].first + 1, x);
			check[x - 1] = true;
			q.push(x - 1);
		}
	}

	vector<int> temp;
	cout << dist[k].first << "\n";
	temp.push_back(k);
	while (k != n) {
		k = dist[k].second;
		temp.push_back(k);

	}
	

	for (int i = temp.size() - 1; i >= 0; i--) {
		cout << temp[i] << " ";
	}

}