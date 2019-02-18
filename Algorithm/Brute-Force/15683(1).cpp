#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;//회사의 크기
int k; //CCTV의 개수

vector<int> possible = { 4,2,4,4,1 };//숫자에 따른 경우의 수
vector<int> num;// 입력받은 CCTV 번호
vector<pair<int, int>> location;//입력받은 CCTV의 위치
int minVal = 100;

//상
void up(pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;

	while (true) {
		if (x < 0)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 1;

		x--;
	}
}

//하
void down(pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;

	while (true) {
		if (x >= n)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 1;

		x++;
	}
}

//우
void right(pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;

	while (true) {
		if (y >= m)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 1;

		y++;
	}
}

//좌
void left(pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;

	while (true) {
		if (y < 0)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 1;

		y--;
	}
}




void first(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int select = i + 1;
	switch (select) {

	case 1:
		up(loc, MAP);
		break;

	case 2:
		down(loc, MAP);
		break;
	case 3:
		right(loc, MAP);
		break;

	case 4:
		left(loc, MAP);
		break;
	}
}

void second(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int select = i + 1;
	switch (select) {

	case 1:
		up(loc, MAP);
		down(loc, MAP);
		break;

	case 2:
		right(loc, MAP);
		left(loc, MAP);
		break;

	}
}

void third(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int select = i + 1;
	switch (select) {

	case 1:
		up(loc, MAP);
		right(loc, MAP);
		break;

	case 2:
		down(loc, MAP);
		right(loc, MAP);
		break;


	case 3:
		down(loc, MAP);
		left(loc, MAP);
		break;


	case 4:
		up(loc, MAP);
		left(loc, MAP);
		break;
	}
}


void fourth(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int select = i + 1;
	switch (select) {

	case 1:
		up(loc, MAP);
		right(loc, MAP);
		left(loc, MAP);
		break;

	case 2:
		up(loc, MAP);
		down(loc, MAP);
		right(loc, MAP);
		break;


	case 3:
		down(loc, MAP);
		right(loc, MAP);
		left(loc, MAP);
		break;


	case 4:
		up(loc, MAP);
		down(loc, MAP);
		left(loc, MAP);
		break;
	}
}


void fifth(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int select = i + 1;
	switch (select) {

	case 1:
		up(loc, MAP);
		down(loc, MAP);
		right(loc, MAP);
		left(loc, MAP);
		break;

	}
}




void go(int select, int cnt, vector<vector<int>> &MAP) {
	if (cnt == k && select == -1) {
		int zero = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] == 0)
					zero++;
			}
		}
		minVal = min(zero, minVal);
		return;
	}


	for (int i = 0; i < possible[select - 1]; i++) {
		vector<vector<int>> temp = MAP;
		switch (select)
		{
		case 1:
			first(i, location[cnt], MAP);
			break;
		case 2:
			second(i, location[cnt], MAP);
			break;
		case 3:
			third(i, location[cnt], MAP);
			break;
		case 4:
			fourth(i, location[cnt], MAP);
			break;

		case 5:
			fifth(i, location[cnt], MAP);
			break;
		}
		go(num[cnt + 1], cnt + 1, MAP);
		MAP = temp;

	}
}


int main(void) {
	cin >> n >> m;
	vector<vector<int>> MAP(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j] != 6 && MAP[i][j] != 0) {
				num.push_back(MAP[i][j]); //CCTV의 번호
				location.push_back(make_pair(i, j));//CCTV위치 값 입력
			}

		}
	}

	k = num.size();
	num.push_back(-1);
	go(num[0], 0, MAP);
	cout << minVal << "\n";
}