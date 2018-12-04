#include <iostream>
#include <vector>
using namespace std;

int subNum; 
int s; 
int c_count; 
vector<int> arr; 
bool check[20];
vector<int> brr;
void backTrack(int index, int sum, int cnt) {

	if (cnt > subNum)
		return;

	if ((s == sum) && cnt >= 1) {
		c_count++;
	}

	for (int i = index; i < subNum; i++) {
		if (check[i] == false) {
			check[i] = true;
			backTrack(i + 1, sum + arr[i], cnt + 1);
			check[i] = false;
		}
	}

}


int main(void) {

	cin >> subNum >> s;

	for (int i = 0; i < subNum; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}
	backTrack(0, 0, 0);
	cout << c_count;

}