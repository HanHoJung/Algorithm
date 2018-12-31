#include <iostream>
using namespace std;

int GCD(int A, int B) {

	int gcd = 1;//모든 수는 1을 약수로 가지기 때문에 최소값이 된다.
	int min = (A > B) ? B : A;
	for (int i = 2; i <= min; i++) {
		if (A%i == 0 && B%i == 0) {
			gcd = i;
		}
	}
	return gcd;
}


int EUCLID(int A, int B) {

	if (B == 0) {
		return A;
	}

	if (A > B) {
		int r = A % B;
		return EUCLID(B, r);
	}
	else {
		int r = B % A;
		return EUCLID(A, r);
	}

}

int LCD(int A, int B) {

	return A * B / GCD(A, B);
}

int main(void) {

	int A, B;

	cin >> A >> B;

	/*cout << GCD(A, B) << "\n";*/
	cout << EUCLID(A,B) << "\n";
	cout << LCD(A, B);
}

