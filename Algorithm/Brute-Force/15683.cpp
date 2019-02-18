#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int k;

vector<int> possible = { 4,2,4,4,1 };//숫자에 따른 경우의 수
vector<int> num;
vector<pair<int, int>> location;
int minVal = 100;

void first(int i, pair<int, int> loc, vector<vector<int>> &MAP) {

	int x = loc.first;
	int y = loc.second;


	if (i == 0) { //상
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
	else if (i == 1) {//하

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
	else if (i == 2) {//좌

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
	else if (i == 3) {//우

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




}


void second(int i, pair<int, int> loc, vector<vector<int>> &MAP) {

	int x = loc.first;
	int y = loc.second;



	if (i == 0) {
		int nx = x;
		int ny = y;

		while (true) {
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x--;
		}

		x = nx;
		y = ny;


		while (true) {
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x++;
		}

	}
	else if (i == 1) {

		int nx = x;
		int ny = y;

		while (true) {
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y--;
		}

		x = nx;
		y = ny;

		while (true) {
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y++;
		}

	}


}


void third(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;

	int nx = x;
	int ny = y;

	if (i == 0) {
		int nx = x;
		int ny = y;

		while (true) {
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x--;
		}

		x = nx;
		y = ny;

		while (true) {
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y++;
		}




	}
	else if (i == 1) {
		int nx = x;
		int ny = y;
		while (true) {
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x++;
		}

		x = nx;
		y = ny;


		while (true) {
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y++;
		}


	}
	else if (i == 2) {
		int nx = x;
		int ny = y;
		while (true) {
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x++;
		}

		x = nx;
		y = ny;


		while (true) {
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y--;
		}


	}
	else if (i == 3) {
		int nx = x;
		int ny = y;

		while (true) {
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			x--;
		}

		x = nx;
		y = ny;


		while (true) {
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 2;

			y--;
		}

	}


}




void fourth(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;


	int nx = x;
	int ny = y;

	if (i == 0) {

		while (true) {//상
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x--;
		}

		x = nx;
		y = ny;


		while (true) {//좌
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y--;
		}

		x = nx;
		y = ny;

		while (true) {//우
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y++;
		}

	}
	else if (i == 1) {

		while (true) {//상
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x--;
		}

		x = nx;
		y = ny;


		while (true) {//하
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x++;
		}

		x = nx;
		y = ny;

		while (true) {//우
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y++;
		}

	}
	else if (i == 2) {
		while (true) {//좌
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y--;
		}

		x = nx;
		y = ny;

		while (true) {//우
			if (y >= m)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y++;
		}

		x = nx;
		y = ny;

		while (true) {//하
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x++;
		}



	}
	else if (i == 3) {
		while (true) {//상
			if (x < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x--;
		}

		x = nx;
		y = ny;


		while (true) {//하
			if (x >= n)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			x++;
		}

		x = nx;
		y = ny;

		while (true) {//좌
			if (y < 0)
				break;

			if (MAP[x][y] == 6)
				break;


			if (MAP[x][y] == 0)
				MAP[x][y] = 5;

			y--;
		}
	}





}
void fifth(int i, pair<int, int> loc, vector<vector<int>> &MAP) {
	int x = loc.first;
	int y = loc.second;


	int nx = x;
	int ny = y;

	while (true) {//상
		if (x < 0)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 5;

		x--;
	}

	x = nx;
	y = ny;


	while (true) {//하
		if (x >= n)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 5;

		x++;
	}

	x = nx;
	y = ny;


	while (true) {//좌
		if (y < 0)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 5;

		y--;
	}

	x = nx;
	y = ny;

	while (true) {//우
		if (y >= m)
			break;

		if (MAP[x][y] == 6)
			break;


		if (MAP[x][y] == 0)
			MAP[x][y] = 5;

		y++;
	}
}

void go(int select, int cnt, vector<vector<int>> &MAP) {

	if (cnt == k && select == -1) {
		int zero = 0;

		//cout << "\n";
		//cout << "\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {

		//		cout << MAP[i][j]<<" ";

		//	}
		//	cout << "\n";
		//}

		//_getch();


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


		if (select == 1) {

			vector<vector<int>> temp = MAP;
			first(i, location[cnt], MAP);
			go(num[cnt + 1], cnt + 1, MAP);
			MAP = temp;
			continue;
		}
		else if (select == 2) {

			vector<vector<int>> temp = MAP;
			second(i, location[cnt], MAP);
			go(num[cnt + 1], cnt + 1, MAP);
			MAP = temp;
			continue;

		}
		else if (select == 3) {
			vector<vector<int>> temp = MAP;
			third(i, location[cnt], MAP);
			go(num[cnt + 1], cnt + 1, MAP);
			MAP = temp;
			continue;

		}
		else if (select == 4) {
			vector<vector<int>> temp = MAP;
			fourth(i, location[cnt], MAP);
			go(num[cnt + 1], cnt + 1, MAP);
			MAP = temp;
			continue;

		}
		else if (select == 5) {

			vector<vector<int>> temp = MAP;
			fifth(i, location[cnt], MAP);
			go(num[cnt + 1], cnt + 1, MAP);
			MAP = temp;
			continue;

		}



	}


}


int main(void) {


	cin >> n >> m;
	vector<vector<int>> MAP(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j] != 6 && MAP[i][j] != 0) {
				num.push_back(MAP[i][j]);
				location.push_back(make_pair(i, j));
			}

		}
	}

	k = num.size();

	num.push_back(-1);

	go(num[0], 0, MAP);
	cout << minVal << "\n";

}