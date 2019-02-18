#include <iostream>
#include <vector>
using namespace std;
/*��,��,��,��(���ʹ���)*/
int dx[] = { -1,0,1,0 };//
int dy[] = { 0,1,0,-1 };


/*
   0:��->��->��->��(0->3->2->1)
   1:��->��->��->��(1->0->3->2)
   2:��->��->��->��(2->1->0->3)
   3:��->��->��->��(3->2->1->0)
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
	   0:û��x
	   1:��
	   2:û��0
	*/

	while (true) {
		//1.���� ��ġ�� û���Ѵ�.
			MAP[x][y] = 2;
		

		/*
			2.3,2.4 �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
			
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
			//2.1 ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
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