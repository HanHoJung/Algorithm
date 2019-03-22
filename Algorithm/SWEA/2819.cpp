#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

char MAP[4][4];
bool check[4][4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
map<string, bool> output;
int length = 0;

void go(int cnt, int x, int y, string temp) {
	if (cnt == 7) {
		if (output[temp] == false) {
			output[temp] = true;
			length++;
		}
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
			continue;

		go(cnt + 1, nx, ny, temp + MAP[nx][ny]);

	}
}


int main(void) {


	int t;
	int cnt = 1;
	cin >> t;
	while(t--){
		length = 0;
		output.clear();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> MAP[i][j];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string str = "";
				str = str + MAP[i][j];
				go(1, i, j, str);

			}
		}

		printf("#%d %d\n", cnt, length);
		cnt++;
		
	}
}