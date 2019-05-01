#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;
int dx[] = { 1,-1 };
int dy[] = { 1,-1 };
int main(void) {
	int n, m,t;
	cin >> n >> m >> t;

	vector<vector<int>> M(n+1, vector<int>(m+1, 0));
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			cin >> M[i][j];
		}
	}




	while (t--) {
		vector<vector<int>> copy = M;
		int cnt = min(n, m) / 2;
		
		int sx, sy, k1, k2;
		int cur;
		sx = sy = 1;
		
	
		for(int k=0; k<cnt; k++){
			int x = sx;
			int y = sy;
			cur = k1 = k2 = 0;
			while (true) {
				
				if (cur == 0) {//За
					if (x + dx[k1] <= n-k&& x + dx[k1] >= 1+k) {
						M[x + dx[k1]][y] = copy[x][y];
						x = x + dx[k1];
					}
					else {
						k1 = (k1 + 1) % 2;
						cur = (cur + 1) % 2;
					}
				}
				else {//ї­
					if (y + dy[k2] <= m-k && y + dy[k2] >= 1+k) {
						M[x][y + dy[k2]] = copy[x][y];
						y = y + dy[k2];
					}
					else {
						k2 = (k2 + 1) % 2;
						cur = (cur + 1) % 2;
					}
				}

				if (x == sx && y == sy)
					break;
			}

			sx++;
			sy++;
			
		
		}

	
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}

	

}