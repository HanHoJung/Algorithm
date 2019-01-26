#include <iostream>
#include <vector>
using namespace std;
int n = 9;
bool c1[9][9];
bool c2[9][9];
bool c3[9][9];
int sdocu[9][9];


void go(int cnt) {

	if (cnt == 81) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdocu[i][j] << " ";

			}
			cout << "\n";
		}
		exit(0);
	}
	int x = cnt / n;
	int y = cnt % n;

	if (sdocu[x][y] != 0) {
		go(cnt + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {

			if (c1[x][i] == 0 && c2[y][i] == 0 && c3[(x / 3) * 3 + (y / 3)][i] == 0) {
				c1[x][i] = c2[y][i] = c3[(x / 3) * 3 + (y / 3)][i] = true;
				sdocu[x][y] = i;
				go(cnt + 1);
				sdocu[x][y] = 0;
				c1[x][i] = c2[y][i] = c3[(x / 3) * 3 + (y / 3)][i] = false;

			}


		}
	}



}







int main(void) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int input = 0;
			scanf("%d", &input);
			sdocu[i][j] = input;
			if (input != 0) {
				c1[i][input] = true;
				c2[j][input] = true;
				c3[(i / 3) * 3 + j / 3][input] = true;
			}
		}
	}


	go(0);



}