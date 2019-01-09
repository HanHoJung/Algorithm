/*
N(0 ≤ N ≤ 100,000)//수빈
K(0 ≤ K ≤ 100,000)//동생

수빈이의 행동
1.걷기(왼쪽-, 오른쪽+)
2.순간이동(2*정점)

가장 빠른 시간

n->n+1
 ->n-1
 ->n*2

가장 빠른 시간(최소비용)
가중치 1(점을 이용)


*/

#include <iostream>
#include <queue>
using namespace std;
bool check[200001];
int dist[200001];

int main(void) {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;

	while (!q.empty()) {

		int node = q.front();
		q.pop();
		if (node == k)
			break;
		
		//+
		int new_x = node + 1;
		if (new_x<=200000 && check[new_x] == false) {
			check[new_x] = true;
			dist[new_x] = dist[node] + 1;
			q.push(new_x);
		}
		
		//-
		new_x = node - 1;
		if (new_x>=0 && check[new_x] == false) {
			check[new_x] = true;
			dist[new_x] = dist[node] + 1;
			q.push(new_x);
		}

		//*
		new_x = node * 2;
		if (new_x <= 200000 && check[new_x] == false) {
			check[new_x] = true;
			dist[new_x] = dist[node] + 1;
			q.push(new_x);
		}


	}

	cout << dist[k];

}