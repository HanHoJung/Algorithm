#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int weight[21][21];
bool check[21];
vector<int> t;
int minVal = 100 * 20;
void go(int index, int cnt) {


	if (index > n)
		return;

	if (cnt >=n)
		return;
	

	if (cnt <=n-1 && cnt >= 1) {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < n; i++) {
			if (check[i])
				start.push_back(i);
			else
				link.push_back(i);
		}
		int s_total = 0;
		int l_total = 0;

		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				s_total = weight[start[i]][start[j]]+s_total;

			}
		}

		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				l_total = weight[link[i]][link[j]] + l_total;

			}
		}



		minVal = min(abs(s_total - l_total), minVal);
		
	}

	t.push_back(index);
	check[index] = true;
	go(index + 1, cnt + 1);

	t.pop_back();
	check[index] = false;
	go(index+1, cnt);

}



int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight[i][j];
		}
	}

	go(0, 0);
	cout << minVal << "\n";
}