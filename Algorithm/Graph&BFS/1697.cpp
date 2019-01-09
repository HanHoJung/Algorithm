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