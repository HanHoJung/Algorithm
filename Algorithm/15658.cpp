#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; //배열의 갯수
int MAX;
int MIN;
bool check;
vector<int> oper;//연산자 개수 배열 +,-,*,/
vector<int> arr;//원소의 값
vector<int> brr;//연산자 배열
int count1;
int calculate() {


	int result = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		switch (brr[i - 1])
		{
		case 0://+
			result = result + arr[i];
			break;

		case 1://-
			result = result - arr[i];
			break;

		case 2://*
			result = result * arr[i];
			break;

		case 3:// /
			result = result / arr[i];
			break;

		}
	}
	count1++;
	return result;

}
void solve(int cnt) {


	if (cnt > n) {
		return;
	}

	if (cnt == n-1) {
		int val = calculate();
		if (check == false) {
			MAX = MIN = val;
			check = true;
		}
		else {
			MAX = max(val, MAX);
			MIN = min(val, MIN);
		}
	}

	for (int i = 0; i < 4; i++) {

		if (oper[i] != 0) {
			oper[i]--;
			brr.push_back(i);
			
			solve(cnt + 1);
			brr.pop_back();
			oper[i]++;
		}


	}


}



int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.push_back(input);

	}

	for (int i = 0; i < 4; i++) {
		int input;
		cin >> input;
		oper.push_back(input);
	}

	solve(0);
	cout << count1 << "\n";
	cout << MAX << "\n";
	cout << MIN << "\n";



}