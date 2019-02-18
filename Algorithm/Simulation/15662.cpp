#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;

string right(string rotate) {
	int n = rotate.size();
	char temp = rotate[n - 1];
	for (int i = n - 1; i >= 1; i--) {
		rotate[i] = rotate[i - 1];
	}
	rotate[0] = temp;

	return rotate;
}

string left(string rotate) {
	int n = rotate.size();
	char temp = rotate[0];
	for (int i = 0; i < n - 1; i++) {
		rotate[i] = rotate[i + 1];
	}
	rotate[n - 1] = temp;
	return rotate;
}



void Lrotate(int select, int dir, vector<string> &Tooth, vector<pair<bool, int>> &check) {

	int start = 6;
	int end = 2;

	for (int i = select; i >= 1; i--) {
		if (Tooth[i][start] != Tooth[i - 1][end]) {
			dir = dir * -1;
			check[i - 1] = make_pair(true, dir);
		}
		else {
			break;
		}

	}

}

void Rrotate(int select, int dir, vector<string> &Tooth, vector<pair<bool, int>> &check) {

	int start = 2;
	int end = 6;
	for (int i = select; i < n - 1; i++) {
		if (Tooth[i][start] != Tooth[i + 1][end]) {
			dir = dir * -1;
			check[i + 1] = make_pair(true, dir);
		}
		else {
			break;
		}
	}
}


void rotate(vector<string> &Tooth, int num, int dir) {
	vector<pair<bool, int>> check(n, pair<bool, int>(false, -1));
	int select = num - 1;
	check[select] = make_pair(true, dir);
	Lrotate(select, dir, Tooth, check);
	Rrotate(select, dir, Tooth, check);
	for (int i = 0; i < n; i++) {
		if (check[i].first) {
			if (check[i].second == 1) {//½Ã°è
				Tooth[i] = right(Tooth[i]);
			}
			else {
				Tooth[i] = left(Tooth[i]);
			}
		}

	}


}

int main(void) {
	cin >> n;
	vector<string> Tooth(n);
	for (int i = 0; i < n; i++)
		cin >> Tooth[i];

	int k;
	cin >> k;

	vector<pair<int, int>> order(k);
	for (int i = 0; i < k; i++) {
		cin >> order[i].first;
		cin >> order[i].second;
	}

	

	for (int i = 0; i < k; i++) {
		rotate(Tooth, order[i].first, order[i].second);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (Tooth[i][0] == '1')
			cnt++;
	}
	cout << cnt << "\n";

}