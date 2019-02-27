#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;


bool check[1501][1501];
int main(void) {
	
	int A, B, C;
	cin >> A >> B >> C;
	int n = A + B + C;

	if (n % 3 != 0) {
		cout << "0" << "\n";
		return 0;
	}
	queue<pair<int, int>> q;
	q.push(make_pair(A, B));
	check[A][B] = true;


	while (!q.empty()){
		int x, y, z;
		tie(x, y) = q.front();
		z = n - (x + y);
		q.pop();

		vector<int> arr;
		arr.push_back(x);
		arr.push_back(y);
		arr.push_back(z);

		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (arr[i] > arr[j]) {

					int nx = arr[j] + arr[j];
					int ny = arr[i] - arr[j];
					if (check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}


				}
				else {

					int nx = arr[i] + arr[i];
					int ny = arr[j] - arr[i];
					if (check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}

				}
			}
		}

	}

	if (check[n / 3][n / 3]) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}