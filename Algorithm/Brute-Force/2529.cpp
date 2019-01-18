#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k;
int arr[10];
bool check[10];
char sign[10];

long long minVal=9876543210;
long long  maxVal=0;
vector<string> str;

bool possible() {
	
	for (int i = 0; i < k; i++) {
		if (sign[i] == '<') {
			if (arr[i] < arr[i + 1])
				continue;
			else
				return false;

		}
		else if (sign[i] == '>') {
			if (arr[i] > arr[i + 1])
				continue;
			else
				return false;
		}

	}
	return true;

}

void go(int cnt, long long sum) {


	if ((cnt == k + 1) && possible()) {
		
		minVal = min(sum, minVal);
		maxVal = max(sum, maxVal);

		return;

	}


	for (int i = 0; i < 10; i++) {

		if (check[i] == false) {

			check[i] = true;
			arr[cnt] = i;
			go(cnt + 1, sum*10+i);
			check[i] = false;

		}

	}
}





int main(void) {

	cin >> k;

	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		sign[i] = c;
	}


	go(0, 0);
	

	
	string str = to_string(maxVal);
	string str2 = to_string(minVal);

	if (str.length() == k) {
		str = "0" + str;
		cout << str << "\n";
	}
	else {
		cout << str << "\n";
	}


	if (str2.length() == k) {
		str2 = "0" + str2;
		cout << str2;
	}
	else {
		cout << str2;
	}


}
