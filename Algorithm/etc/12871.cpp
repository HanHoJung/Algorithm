/*
길이가 다르면 다른 문자열
*/

#include <iostream>
#include <string>
using namespace std;

int gcd(int n, int m) {
	if (m == 0)
		return n;

	return gcd(m, n%m);


}


int main(void) {
	
		string str1, str2;
		cin >> str1 >> str2;

		int n = str1.size();
		int m = str2.size();

		int lcd;
		if (n > m) {
			lcd = (n*m) / gcd(n, m);
		}
		else {
			lcd = (n*m) / gcd(m, n);
		}


		int c1 = lcd/n;
		int c2 = lcd/m;

		string t1 = "";

		for (int i = 0; i < c1; i++)
			t1 = t1 + str1;

		string t2 = "";
		for (int i = 0; i < c2; i++)
			t2 = t2 + str2;

		if (t1.compare(t2) == 0) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}

	
}