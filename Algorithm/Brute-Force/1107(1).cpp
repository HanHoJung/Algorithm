#include <iostream>
#include <algorithm>
using namespace std;
bool broken[10];
int minButton;
int n;
int possible(int c) {

	if (c == 0) {
		return broken[c] ? 0 : abs(n - c)+1;
	}
	else {
		int length = 0;
		int p = c;
		int q;
		while (p) {
			q = p % 10;//³ª¸ÓÁö
			p = p / 10;//¸ò

			if (broken[q] == true)
				return 0;


			length++;
		}
		return abs(n - c) + length;
	}
	
}



int main(void) {
	int m;
	int input;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		
		scanf("%d", &input);
		broken[input] = true;
	}
	minButton = abs(n - 100);


	for (int i = 0; i <= 1000000; i++) {

		int minVal = possible(i);

		if (minVal != 0) {
			minButton = min(minVal, minButton);
		}
	}

	cout << minButton;

}