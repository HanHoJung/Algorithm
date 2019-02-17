#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int r, c;
bool check[251][251];
int sheep = 0;
int wolf = 0;
void fill(int cnt, int i, int j, vector<string> &COPY, vector<string> &MAP) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	COPY[i][j] = cnt + '0';

	int s = 0;
	int w = 0;

	if (MAP[i][j] == 'v') {
		w = w + 1;

	}
	else if(MAP[i][j]=='o'){
		s = s + 1;

	}

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			if (check[nx][ny] == false && COPY[nx][ny] == '.') {
				COPY[nx][ny] = cnt + '0';
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				if (MAP[nx][ny] == 'v') {
					w = w + 1;
					
				}
				else if (MAP[nx][ny] == 'o') {
					s = s + 1;

				}
			}
		}
	}


	if (w >= s) {
		wolf = w + wolf;
	}
	else {
		sheep = s + sheep;
	}
}

int main(void) {
	cin >> r >> c;
	vector<string> MAP(r);
	vector<string> COPY(r);

	for (int i = 0; i < r; i++) {
		cin >> MAP[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (MAP[i][j] == 'v' || MAP[i][j] == 'o') {
				COPY[i].push_back('.');
			}
			else {
				COPY[i].push_back(MAP[i][j]);
			}
		}
	}
	int cnt = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (COPY[i][j] == '.' && check[i][j] == false) {
				fill(cnt, i, j, COPY, MAP);
				cnt++;
			}
		}
	}

	cout << sheep << " " << wolf << "\n";
	return 0;
}