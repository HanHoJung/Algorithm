#include <iostream>
#include <vector>
using namespace std;
int n, m;//지도의 크기
int x, y;//주사위의 좌표
vector<int> dice(6);//왼위 위 오위 바닥 왼 오

//동쪽:1
int east(vector<vector<int>> &MAP) {

	int nx = x;
	int ny = y + 1;
	int nVal = -1;
	if (ny <m) {
		nVal = MAP[nx][ny];
		swap(dice[1], dice[3]);
		swap(dice[1], dice[4]);
		swap(dice[3], dice[5]);


		if (nVal == 0) {
			MAP[nx][ny] = dice[3];
		}
		else {
			dice[3] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		return dice[1];

	}

	return -1;
}



//서쪽:2
int west(vector<vector<int>> &MAP) {

	int nx = x;
	int ny = y-1;
	int nVal = -1;
	if (ny >= 0) {
		nVal = MAP[nx][ny];

		
		swap(dice[4], dice[5]);
		swap(dice[1], dice[4]);
		swap(dice[3], dice[5]);
		



		if (nVal == 0) {
			MAP[nx][ny] = dice[3];
		}
		else {
			dice[3] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		return dice[1];

	}

	return -1;

}


//북쪽:3(왼쪽 shift)
int north(vector <vector<int>> &MAP) {
	int nx = x - 1;
	int ny = y;
	int nVal = -1;
	if (nx >= 0) {
		nVal = MAP[nx][ny];

		int temp = dice[0];

		for (int i = 1; i <=3; i++) {
			dice[i-1] = dice[i];
		}

		dice[3] = temp;



		if (nVal == 0) {
			MAP[nx][ny] = dice[3];
		}
		else {
			dice[3] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		return dice[1];

	}

	return -1;

}



//남쪽:4(오른쪽 shift)
int south(vector <vector<int>> &MAP) {
	int nx = x + 1;
	int ny = y;
	int nVal=-1;
	if (nx < n) {
		nVal = MAP[nx][ny];

		int temp = dice[3];

		for (int i= 2; i>=0; i--) {
			dice[i+1] = dice[i];
		}
		
		dice[0] = temp;


		if (nVal == 0) {
			MAP[nx][ny] = dice[3];
		}
		else {
			dice[3] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		return dice[1];

	}
	
	return -1;

}






int main(void) {
	
	int k;///명령어의 개수
	cin >> n >> m;
	cin >> x >> y;
	cin >> k;
	vector <vector<int>> MAP(n, vector<int>(m, 0));
	vector<int> order(k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}

	for (int i = 0; i < k; i++) {

		int select = order[i];
		int decision;
		switch (select)
		{
		case 1:
			decision = east(MAP);
			if (decision != -1)
				cout << decision << "\n";
			break;
		case 2:
			decision = west(MAP);

			if (decision != -1)
				cout << decision << "\n";
			break;
			
		case 3:
			decision = north(MAP);
			
			if (decision != -1)
				cout << decision << "\n";	
			break;

		case 4:
			decision = south(MAP);
				if (decision != -1)
					cout << decision << "\n";
			break;


		}
	
	}




}