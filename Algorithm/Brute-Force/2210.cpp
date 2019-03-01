#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool value[1000000];
int MAP[5][5];
bool visit[5][5];
int t;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void go(int x, int y, string str, int cnt) {

	if (cnt == 5) {
		int output = atoi(str.c_str());

		if (value[output] == false) {
			/*cout << output << "\n";*/
			value[output] = true;
			t++;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;

		go(nx, ny, str + to_string(MAP[nx][ny]), cnt + 1);


	}

}




int main(void) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> MAP[i][j];
		}
	}


	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(i, j, to_string(MAP[i][j]), 0);
		}
	}



	cout << t << "\n";


}