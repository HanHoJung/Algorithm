#include <iostream>
using namespace std;

int n;
int sign[10][10];
int arr[10];

bool check(int index) {

	int sum = 0;
	for (int i = index; i >= 0; i--) {
		sum = sum +arr[i];

		if (sign[i][index] > 0) {
			if (sum <= 0)
				return false;
		}
		else if (sign[i][index] == 0) {

			if (sum != 0)
				return false;

		}
		else if (sign[i][index] < 0) {
			if(sum>=0)
				return false;

		}
	}

	return true;
}

void go(int cnt) {

	if (cnt == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		exit(0);
	}



	for (int i = 1; i <= 10; i++) {
		arr[cnt] = i * sign[cnt][cnt];

		if (check(cnt)) {
			go(cnt + 1);
		}
	}


}


int main(void) {

	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = i;j < n; j++) {
			char c;
			cin >> c;
			if (c == '+') {
				sign[i][j] = 1;

			}
			else if (c == '0') {
				sign[i][j] = 0;
			}
			else {
				sign[i][j] = -1;
			}
		}
	}
	go(0);


}