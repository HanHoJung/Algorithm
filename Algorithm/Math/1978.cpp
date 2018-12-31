#include <iostream>
using namespace std;

bool prime(int input) {
	if (input < 2) {
		return false;
	}
	for (int i = 2; i*i <= input; i++) {
		if (input%i == 0)
			return false;
	}
	return true;
}

int main(void) {

	int n;
	int cnt = 0;//소수의 수 세기
	cin >> n;

	while (n--) {
		int input;
		cin >> input;
		bool check = prime(input);
		if (check)
			cnt++;
	}

	cout << cnt << "\n";
}