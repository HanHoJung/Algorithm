#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;//이동하고 싶은 채널
bool brokenCheck[10];//고장난 채널 check
int length;//채널의 길이
vector<int> chanel;
int minClick;
bool tick;
void solve(int cnt) {


	if (cnt == length+1) {

		int sum = 0;
		for (int i = 0; i < chanel.size(); i++) {
			sum = sum * 10 + chanel[i];
		}
	
		sum = abs(sum - n) + chanel.size();
		minClick = min(sum, minClick);
		return;
	}

	if (cnt >= 1) {

		int sum = 0;
		for (int i = 0; i < chanel.size(); i++) {
			sum = sum * 10 + chanel[i];
		}
		
		sum = abs(sum - n) + chanel.size();
		minClick = min(sum, minClick);
	}


	for (int i = 0; i < 10; i++) {


		if (cnt == 0 && brokenCheck[0] == false && tick == false) {
			tick = true;
			continue;
		}

		if (brokenCheck[i] == false) {
			chanel.push_back(i);
			solve(cnt + 1);
			chanel.pop_back();
		}


	}

}


int main(void) {

	int m;

	cin >> n >> m;

	minClick = abs(n - 100);

	

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		brokenCheck[input] = true;
	}

	if (brokenCheck[0] == false) {
		minClick = min(n + 1, minClick);
	}


	int temp = n;

	while (temp) {
		temp = temp / 10;
		length++;
	}
	

	if (n == 0)
		length++;

	solve(0);


	cout << min(abs(n - 100), minClick);




}

