#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int dist1[500001];
int dist2[2][500001];
int dx[] = { 1,-1,2 };
int main(void) {
	int n, k;//수빈이의 위치(n), 동생의 위치(k)
	cin >> n >> k;

	if (n > 500000 || k > 500000) {
		cout << -1 << "\n";
		return 0;
	}
	vector<int> time;
	memset(dist1, -1, sizeof(dist1));
	memset(dist2, -1, sizeof(dist2));
	queue<int> q;
	q.push(k);
	dist1[k] = 0;

	while (!q.empty()) {
		int x = q.front();
		time.push_back(x);
		q.pop();
		int nx = x + (dist1[x] + 1);
		if (nx <= 500000) {
			dist1[nx] = dist1[x] + 1;
			q.push(nx);

		}
	}

	queue<pair<int, int>> q1;
	q1.push(make_pair(0, n));
	dist2[0][n] = 0;

	while (!q1.empty()) {
		int x, t;
		tie(t,x) =  q1.front();
		q1.pop();

		for (int k = 0; k < 3; k++) {
			int nx = x;
			int nt = (t + 1)%2;
			if (k == 2) {
				nx = x * dx[k];
			}
			else {
				nx = x + dx[k];
			}

			if (nx < 0 || nx>500000)
				continue;

			if (dist2[nt][nx] != -1)
				continue;

			q1.push(make_pair(nt,nx));
			dist2[nt][nx] = dist2[t][x] + 1;
		}
	}


	int ans = -1;
	bool check = false;
	for (int i = 0; i < time.size(); i++) {
		int val = time[i];

		if (dist2[i%2][val] == -1)
			continue;
		

		if (dist2[i % 2][val] <= i) {
			ans = i;
			break;
		}
	

	}
	cout << ans << "\n";
}


