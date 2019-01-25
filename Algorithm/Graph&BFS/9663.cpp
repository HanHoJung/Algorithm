#include <iostream>
#include <vector>

using namespace std;

int n;
int sum;
bool visit[15][15];


bool check(int x, int y) {//true면 통과 false미통과

	//위 탐색
	int new_x = x;
	int new_y = y;
	while (true) {

		if (new_x == x && new_y == y) {
			new_x = new_x - 1;
			continue;
		}

		if (new_x < 0)
			break;

		if (visit[new_x][new_y])
			return false;


		new_x = new_x - 1;


	}

	//왼쪽 대각선

	new_x = x;
	new_y = y;
	while (true) {

		if (new_x == x && new_y == y) {
			new_x = new_x - 1;
			new_y = new_y - 1;
			continue;
		}

		if (new_x < 0 || new_y < 0)
			break;

		if (visit[new_x][new_y])
			return false;


		new_x = new_x - 1;
		new_y = new_y - 1;

	}

	//오른쪽 대각선

	new_x = x;
	new_y = y;
	while (true) {

		if (new_x == x && new_y == y) {
			new_x = new_x - 1;
			new_y = new_y + 1;
			continue;
		}

		if (new_x < 0 || new_y >= n)
			break;

		if (visit[new_x][new_y])
			return false;


		new_x = new_x - 1;
		new_y = new_y + 1;

	}
	return true;

}




void go(int x) {


	

	if (x == n) {
		sum++;
		return;
	}

	


	for (int y= 0; y < n; y++) {

		if (visit[x][y] == false) {
			visit[x][y] = true;
			if (check(x, y)) {
				go(x+1);
			}
			

			visit[x][y] = false;

		}

	}
}



int main(void) {


	cin >> n;
	go(0);

	cout << sum << "\n";


}