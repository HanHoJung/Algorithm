#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> possible;

bool check[13];
int n, m;
int minVal = -1;
void go(int cnt,int index,int k) {
	if (cnt == m) {
		int dist[51][51];
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < possible.size(); i++) {
			int r1 = chicken[possible[i]].first;
			int c1 = chicken[possible[i]].second;

			for (int j = 0; j < house.size(); j++) {
				int r2 = house[j].first;
				int c2 = house[j].second;
				
				
				int d = abs(r1 - r2) + abs(c1 - c2);

				if (dist[r2][c2] == -1 || dist[r2][c2] > d) {
					dist[r2][c2] = d;
				}	
			}
		}

		int city = 0;
		for (int i = 0; i < house.size(); i++) {
			city = city + dist[house[i].first][house[i].second];
		}

		if (minVal == -1 || minVal> city) {
			minVal = city;

		}
		
		return;
	}

	for (int i = index; i < k; i++) {
		if (check[i] == false) {
			check[i] = true;
			possible.push_back(i);
			go(cnt + 1, i + 1, k);
			possible.pop_back();
			check[i] = false;
		}

	}

}



int main(void) {
	cin >> n >> m;
	vector<vector<int>> MAP(n,vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			if (MAP[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	go(0, 0, chicken.size());
	cout << minVal << "\n";

}






