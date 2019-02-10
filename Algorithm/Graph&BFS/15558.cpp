#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int dist[2][100001];
pair<int, int> before[2][100001];

int main(void) {
	
	int n, k;
	cin >> n >> k;
	vector<string> MAP(2);

	for (int i = 0; i < 2; i++) {
		cin >> MAP[i];
	}

	memset(dist,-1,sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	before[0][0] = make_pair(0, 0);
	dist[0][0] = 1;
	
	bool decision = false;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (y + 1 < n) {
			
			if (y + 1 >= dist[x][y]) {
		
				if (MAP[x][y + 1] != '0' && dist[x][y + 1] == -1) {
					
					dist[x][y + 1] = dist[x][y] + 1;
					before[x][y + 1] = make_pair(x, y);
					q.push(make_pair(x, y + 1));

				}
			}

		}
		else {
			
			decision = true;
			break;
		}

		if (y - 1 >= 0) {

			if (y - 1 >= dist[x][y]) {
				if (MAP[x][y - 1] != '0' && dist[x][y - 1] == -1) {
					dist[x][y - 1] = dist[x][y] + 1;
					before[x][y - 1] = make_pair(x, y);
					q.push(make_pair(x, y - 1));

				}
			}
		}


		if (y + k < n) {
			
			if (y + k >= dist[x][y]) {
			
				if (MAP[!x][y + k] != '0' && dist[!x][y + k] == -1) {
					dist[!x][y + k] = dist[x][y] + 1;
					before[!x][y + k] = make_pair(x, y);
					q.push(make_pair(!x, y + k));
				}
			}
		}
		else {
			decision = true;
			break;
		}
	}

	if (decision == false) {
		cout << 0 << "\n";
	}
	else {
		cout << 1 << "\n";
	}
}