/*

S[i][j]//�� ���� �����ϴ� �̻��� ��(int)�� ����(int)
	   //���� ������ �̻��� ��(0,0)
=>x���� 0 �Ǵ� n-1 y���� 0 �Ǵ� n-1
=>�ܰ� line�� -1�� �Ѱ�

2���� ���� v(�̻����� ��, ���� ū ����)
=>(8,0) (3,1) (14,2)
=>max���� ã�Ƽ� (���)

=>s[i][j] ����
=>�����ϰ�
=>�̻����� ���� ���ϰ�
1�ܰ�: �Է� �ޱ�(���¿� ������ ���� ����)
2�ܰ�:m�ð� ������ �̵�


*/


#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int convert(int dir) {
	if (dir == 1)//��
		return 2;

	if (dir == 2)//��
		return 1;

	if (dir == 3)//��
		return 4;

	if (dir == 4)//��
		return 3;
}


int dx[] = { 10,-1,1,0,0 };
int dy[] = { 10,0,0,-1,1 };
void simulate(vector<vector<pair<int, int>>> &S, int n) {
	int size = n * n;
	vector<tuple<int, int, bool>> v[100 * 100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int element, dir;
			tie(element, dir) = S[i][j];

			if (element == 0)
				continue;

			int nx = i + dx[dir];
			int ny = j + dy[dir];


			if (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1) {//��ǰ�� ����

				int ndir = convert(dir);
				v[nx*n + ny].push_back(make_tuple(element, ndir, true));
			}
			else {//��ǰ�� ���� ����
				v[nx*n + ny].push_back(make_tuple(element, dir, false));

			}

			S[i][j] = make_pair(0, 0);
		}
	}

	for (int i = 0; i < n*n; i++) {
		int x = i / n;
		int y = i % n;
		int sum = 0;
		int max = 0;
		int select;

		if (v[i].size() == 0)
			continue;





		for (int j = 0; j < v[i].size(); j++) {
			int element, dir;
			bool check;


			tie(element, dir, check) = v[i][j];

			if (check) {
				element = element / 2;
			}

			if (max < element) {
				max = element;
				select = dir;
			}

			sum += element;
		}


		S[x][y] = make_pair(sum, select);
	}


}


void output(vector<vector<pair<int, int>>> S, int n) {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << S[i][j].first << "," << S[i][j].second << " ";
		}
		cout << "\n";
	}


}



void init(vector<vector<pair<int, int>>> S, int n) {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			S[i][j] = make_pair(0, 0);
		}
	}


}
int main(void) {
	ios_base::sync_with_stdio(false);
	
	int t, n, m, k;
	cin >> t;

	while (t--) {
		cin >> n >> m >> k;
		vector<vector<pair<int, int>>> S(n, vector<pair<int, int>>(n, make_pair(0, 0)));//�̻����� ����
		init(S, n);

		for (int i = 0; i < k; i++) {
			int x, y, cnt, dir;
			cin >> x >> y >> cnt >> dir;
			S[x][y] = make_pair(cnt, dir);
		}

		for (int i = 0; i < m; i++) {
			simulate(S, n);
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum += S[i][j].first;

			}
		}
		cout << sum << "\n";

	}


}
