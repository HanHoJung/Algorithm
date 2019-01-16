#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	
	int n = str.length();
	int k = 1;

	int value = 0;

	for (int i = 0; i < n; i++) {
		value = value * 10 + (str[i] - '0');
	}

	int sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		sum = 9 * k*i + sum;
		k = k * 10;
	}

	sum = sum + (value - k + 1)*n;

	cout << sum;
	return 0;
}