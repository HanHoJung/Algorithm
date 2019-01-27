#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> board(20);
bool check[27];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int MAX = -1;
int n, m;
int go(int x, int y, int cnt) {


	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;


		if (check[board[nx][ny] - 'A'] == false) {

			check[board[nx][ny] - 'A'] = true;
			int result = go(nx, ny, cnt + 1);
			MAX = max(result, MAX);
			check[board[nx][ny] - 'A'] = false;

		}

	}
	return cnt;

}


int main(void) {




	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> board[i];

	}


	char start = board[0][0];
	check[start - 'A'] = true;


	go(0, 0, 1);

	if (MAX == -1) {
		cout << 1 << "\n";
	}
	else {
		cout << MAX << "\n";
	}






}