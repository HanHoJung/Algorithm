#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int t = 1;
	int col;
	while (cin >> col) {
		int cnt = 0;
		getchar();
		vector<vector<bool>> visit(255, vector<bool>(1000, false));
		vector<int> house;
		for (int i = 0; i < col; i++) {
			int row;
			cin >> row;
			house.push_back(row);
			for (int j = 0; j < row; j++)
				visit[j][i] = true;

		}



		for (int i = 2; i < house.size() - 2; i++) {//가로
			for (int j = 0; j < house[i]; j++) {//세로의 길이
				
				int x = j;
				int y = i;

				if (visit[x][y - 1] == false && visit[x][y - 2] == false && visit[x][y + 1] == false && visit[x][y + 2] == false) {
					cnt++;
				
				}
			}

		}



		printf("#%d %d\n", t, cnt);
		t++;

	}

}