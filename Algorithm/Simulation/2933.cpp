
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c;//��� ��
int n; //���븦 ���� Ƚ��
bool check[101][101];//�湮����check
char MAP[101][101];//������ ����
vector<pair<int, int>> group;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {
	if (MAP[x][y] == '.')
		return;

	if (check[x][y])
		return;

	check[x][y] = true;
	group.push_back(make_pair(x, y));

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		
			dfs(nx, ny);
		
	}

}

void simulate() {
	memset(check, false, sizeof(check));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (MAP[i][j] == '.')
				continue;
			if (check[i][j])
				continue;

			group.clear();
			dfs(i, j);
			vector<int> arr(c, -1);
			/*
				���� ���� �ִ� Ŭ����Ʈ�� ���� ���� �ִ� ����
			*/

			for (int i = 0; i < group.size(); i++) {
				
				int row = group[i].first;
				int col = group[i].second;
				arr[col] = max(row,arr[col]);
				MAP[row][col] = '.';
				
			}
			
			int max_dist = r;//�ִ� �� ĭ �̵�����

			for (int i=0,j= 0; i < c; i++) {
				if (arr[i] == -1)
					continue;
				for (j = arr[i]; j < r && MAP[j][i] == '.'; j++);
				max_dist = min(j-arr[i]-1, max_dist);
			}

			for (int i = 0; i < group.size(); i++) {
				int row = group[i].first;
				int col = group[i].second;

				MAP[row + max_dist][col] = 'x';
				check[row + max_dist][col] = true;

			}

		}
	}


}


int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> MAP[i];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;
		int h = r - order;

		if (i % 2 == 0) {//���ʿ��� ����������
			for (int i = 0; i < c; i++) {
				if (MAP[h][i] == 'x') {
					MAP[h][i] = '.';
					break;
				}
			}
		}
		else {//�����ʿ��� ��������
			for (int i = c-1; i>=0; i--) {
				if (MAP[h][i] == 'x') {
					MAP[h][i] = '.';
					break;
				}
			}
		}
		simulate();
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}
}