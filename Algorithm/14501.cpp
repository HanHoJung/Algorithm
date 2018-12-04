#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> Ti;
vector<int> Pi;
bool check[15];
int MAX = 0;

void solve(int index, int sum) {

	if (index > N)
		return;

	if (index <= N)
	{
		MAX = max(MAX, sum);

	}

	for (int day = index; day < N; day++) {
		if (check[day] == false) {
			check[day] = true;
			solve(day + Ti[day], sum + Pi[day]);
			check[day] = false;
		}
	}

}


int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		Ti.push_back(input1);
		Pi.push_back(input2);
	}
	solve(0, 0);
	cout << MAX;
}
