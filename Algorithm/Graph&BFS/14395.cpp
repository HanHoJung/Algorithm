#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
const long long MAX = 1000000000;
int main() {
	long long s, t;
	cin >> s >> t;
	
	queue<pair<long long, string>> q;
	map<long long, bool> check;
	q.push(make_pair(s,""));
	check[s] = true;

	while (!q.empty()) {

		long long x;
		string str;
		tie(x, str) = q.front();
		q.pop();
		
		
		if (x == t) {
			if (str.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				for (int i = 0; i < str.size(); i++)
					cout << str[i] << "";
			}

			return 0;
		}

		// *
		if (x * x <= MAX) {
			long long nx = x * x;
			if (check[nx] == false) {
				q.push(make_pair(nx, str + "*"));
				check[nx] = true;
			}
		}
		// +
		if (x + x <= MAX) {
			long long nx = x + x;
			if (check[nx] == false) {
				q.push(make_pair(nx, str + "+"));
				check[nx] = true;
			}
		}

		//-
		if (x - x <= MAX) {
			long long nx = x - x;
			if (check[nx] == false) {
				q.push(make_pair(nx, str + "-"));
				check[nx] = true;
			}
		}

		// /

		if (x!=0 && x/x <= MAX) {
			long long nx = x /x;
			if (check[nx] == false) {
				q.push(make_pair(nx, str + "/"));
				check[nx] = true;
			}
		}

	}
	cout <<-1<<"\n";
}