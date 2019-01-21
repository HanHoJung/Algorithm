#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool check[21];
int weight[21][21];
vector<int> s;

int n;


int minVal=50000;
void go(int start, int cnt) {


	if (n / 2 == cnt) {	

		vector<int> l;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false)
				l.push_back(i);
		 }

		int sum1 = 0;
		for (int i = 0; i < s.size(); i++) {
			int s_point=s[i];
			for (int j = 0; j < s.size(); j++) {
				int d_point = s[j];

				if (s_point != d_point) {
					sum1 = sum1 + weight[s_point][d_point];
				}

			}
		}

		int sum2 = 0;
		for (int i = 0; i < l.size(); i++) {
			int s_point = l[i];
			for (int j = 0; j < l.size(); j++) {
				int d_point = l[j];

				if (s_point != d_point) {
					sum2 = sum2 + weight[s_point][d_point];
				}

			}
		}

		minVal = min(abs(sum1 - sum2), minVal);

		return;

	}


	for (int i = start; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			s.push_back(i);
			go(i+ 1, cnt + 1);
			s.pop_back();
			check[i] = false;
		}

	}

}

int main(void) {

	cin >> n;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			int input;
			cin >> input;
			weight[i][j] = input;
		}
	}

	go(1, 0);
	cout << minVal << "\n";
}