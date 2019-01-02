#include <iostream>
using namespace std;

int main(void) {
	int E = 15;
	int S = 28;
	int M = 19;
	int y = 0, m = 0, d = 0;
	int s1, s2, s3;


	cin >> s1 >> s2 >> s3;

	int cnt = 0;
	while (true) {

		y = (y + 1) % E;
		m = (m + 1) % S;
		d = (d + 1) % M;

		if (y == 0)
			y = E;
		if (m == 0)
			m = S;
		if (d == 0)
			d = M;

		cnt++;
		if (y == s1 && m == s2 && d == s3)
			break;



	}
	cout << cnt << "\n";
}