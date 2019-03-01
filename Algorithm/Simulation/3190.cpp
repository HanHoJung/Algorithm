#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n;
int k, order;
int time = 0;
int dir = 1;
deque<pair<int, int>> q;

//상,우,하,좌
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void init(vector<string> & MAP) {
	for (int i = 0; i < n; i++) {
		MAP[0].push_back('X');
	}

	for (int i = 0; i < n; i++) {
		MAP[n - 1].push_back('X');
	}

	for (int i = 1; i <= n - 2; i++) {
		MAP[i].push_back('X');
		for (int j = 1; j <= n - 2; j++) {
			MAP[i].push_back('0');
		}
		MAP[i].push_back('X');
	}

}
void output(vector<string> & MAP) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}
}


bool move(vector<string> &MAP) {
	int x, y;
	tie(x, y) = q.front();

	if (MAP[x + dx[dir]][y + dy[dir]] == 'X')//벽인 경우
		return false;

	if (MAP[x + dx[dir]][y + dy[dir]] == '1')//뱀인 경우
		return false;

	if (MAP[x + dx[dir]][y + dy[dir]] == '0')//빈 공간인 경우
	{
		int nx, ny;
		nx = x + dx[dir];
		ny = y + dy[dir];
		MAP[nx][ny] = '1';
		q.push_front(make_pair(nx, ny));
		tie(nx, ny) = q.back();
		MAP[nx][ny] = '0';
		q.pop_back();
	}
	else if (MAP[x + dx[dir]][y + dy[dir]] == 'A')//사과인 경우
	{
		int nx, ny;
		nx = x + dx[dir];
		ny = y + dy[dir];
		MAP[nx][ny] = '1';
		q.push_front(make_pair(nx, ny));

	}
	return true;

}

int Rrocation() {
	int mod = 4;
	return (dir + 1) % 4;
}

int Lrocation() {
	int mod = 4;
	return (dir - 1 + mod) % 4;
}
int main(void) {
	int cnt = 0;
	cin >> n;
	vector<string> MAP(n + 2);
	vector<pair<int, char>> orders;
	n = n + 2;
	init(MAP);
	cin >> k;
	for (int w = 0; w < k; w++) {
		int i, j;
		cin >> i >> j;
		MAP[i][j] = 'A';

	}
	cin >> order;
	for (int i = 0; i < order;i++) {
		int k;
		char c;
		cin >> k >> c;
		orders.push_back(make_pair(k, c));
	}

	q.push_back(make_pair(1, 1));
	MAP[1][1] = '1';


	while (true) {

		bool check = move(MAP);

		if (check == false)
			break;

		time++;

		if (cnt < order) {
			if (orders[cnt].first == time) {
				if (orders[cnt].second == 'L') {//반시계
					dir = Lrocation();
					cnt++;
				}
				else if (orders[cnt].second == 'D') {//시계
					dir = Rrocation();
					cnt++;
				}
			}
		}
	}

	cout << time+1 << "\n";

}

