

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int D(int n) {
	
	if (2 * n >= 10000)
		return (2 * n) % 10000;
	else
		return 2 * n;
}

int S(int n) {
	if (n - 1 < 0)
		return 9999;
	else
		return n - 1;
}

int L(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		int p = n / 1000;
		int q = (n % 1000)*10 + p;
		return q;
	}
}

int R(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		
		int p = n % 10;
		int q = (n / 10)+ p*1000;
		return q;
	}
	
}

int main(void) {

	int t;
	cin >> t;

	while (t--) {
		queue<int> q;
		pair<int, char> from[10001];
		bool check[10001];
		memset(check, false, sizeof(check));

		int A, B;
		cin >> A >> B;

		q.push(A);
		check[A] = true;
		from[A] = make_pair(A, '-1');

		while (!q.empty()) {

			int x = q.front();
			q.pop();
			if (x == B)
				break;

			int new_x = D(x);
			if (check[new_x] == false) {
				check[new_x] = true;
				from[new_x] = make_pair(x,'D');
				q.push(new_x);
			}

			new_x = S(x);
			if (check[new_x] == false) {
				check[new_x] = true;
				from[new_x] = make_pair(x, 'S');
				q.push(new_x);
			}

			new_x = L(x);
			if (check[new_x] == false) {
				check[new_x] = true;
				from[new_x] = make_pair(x, 'L');
				q.push(new_x);
			}

			new_x = R(x);
			if (check[new_x] == false) {
				check[new_x] = true;
				from[new_x] = make_pair(x, 'R');
				q.push(new_x);
			}

		}
	
		
		int k = B;
		vector<char> arr;
		  
		while (k!=A) {
			arr.push_back(from[k].second);
			k = from[k].first;
			
		}

		for (int i = arr.size() - 1; i >= 0; i--) {
			cout << arr[i];

		}
		cout << "\n";
	
	}
	return 0;

}