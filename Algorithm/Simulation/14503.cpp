#include <iostream>
#include <vector>
using namespace std;
/*북,동,남,서(왼쪽방향)*/
int dx[] = { -1,0,1,0 };//
int dy[] = { 0,1,0,-1 };


/*
   0:북->서->남->동(0->3->2->1)
   1:동->북->서->남(1->0->3->2)
   2:남->동->북->서(2->1->0->3)
   3:서->남->동->북(3->2->1->0)
*/
int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> MAP(n, vector<int>(m));

	int x, y, dir;

	cin >> x >> y >> dir;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	/*
	   0:청소x
	   1:벽
	   2:청소0
	*/

	while (true) {
		//1.현재 위치를 청소한다.
			MAP[x][y] = 2;
		

		/*
			2.3,2.4 네 방향 모두 청소가 이미 되어있거나 벽인 경우
			
		*/
		if (MAP[x + 1][y] != 0 && MAP[x - 1][y] != 0 && MAP[x][y - 1] != 0 && MAP[x][y + 1] != 0) {
		
			if (MAP[x - dx[dir]][y - dy[dir]] == 1) {
				break;
			}
			else {
				x = x - dx[dir];
				y = y - dy[dir];
			}
			
		}
		else {


			dir = (dir + 3) % 4;
			//2.1 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			if (MAP[x + dx[dir]][y + dy[dir]] == 0) {
				x = x + dx[dir];
				y = y + dy[dir];
			}
			

		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (MAP[i][j] == 2)
				ans++;

		}
	}
	cout << ans << "\n";

	

}