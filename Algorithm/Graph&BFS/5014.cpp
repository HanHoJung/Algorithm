#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dist[1000001];
int main(void) {

	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(S);
	dist[S] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		if (node + U <= F && dist[node + U] == -1) {
			q.push(node + U);
			dist[node + U] = dist[node]+1;
		}


		if (node -D>=0 && dist[node - D] == -1) {
			q.push(node - D);
			dist[node - D] = dist[node] + 1;
		}

	}
	
	if (dist[G] == -1)
		cout << "use the stairs"<<"\n";
	else
		cout << dist[G]<<"\n";


}