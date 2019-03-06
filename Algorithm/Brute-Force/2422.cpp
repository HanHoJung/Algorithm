#include <iostream>
#include <vector>
using namespace std;
#define MAX 201
int n, m;
vector<vector<bool>> check(MAX, vector<bool>(MAX));
vector<int> arr;
bool visit[201];

int possible;
void go(int cnt, int next) {
	if (cnt == 3) {
		bool output = false;
		for (int i = 0; i < 3; i++) {
			for (int j = i+1; j < 3; j++) {
				if (check[arr[i]][arr[j]]) {
					output = true;
					break;
				}		
			}
		}
		if (output)
			return;
		else
			possible++;
		return;
	}

	for (int i = next; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr.push_back(i);
			go(cnt + 1, i + 1);
			visit[i] = false;
			arr.pop_back();
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		check[s][e] = true;
		check[e][s] = true;
	}
	go(0, 1);
	cout << possible << "\n";
}