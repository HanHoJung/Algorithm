#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<string> arr);
vector<string> tooth(4);

string right(string arr) {//시계

	int temp = arr[7];

	for (int i = 6; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = temp;

	return arr;
}

string left(string arr) {//반시계
	int temp = arr[0];

	for (int i = 1; i <= 7; i++) {
		arr[i - 1] = arr[i];
	}

	arr[7] = temp;

	return arr;
}


//1이 시계(right)
//2가 반시계(left)


void first(int rotate) {
	vector<pair<bool, bool>> check(4, make_pair(false, false));

	int start = 2;
	int end = 6;
	check[0] = make_pair(true, rotate);

	for (int i = 0; i <= 2; i++) {

		if (check[i].first) {

			if (tooth[i][start] != tooth[i + 1][end]) {
				rotate = !rotate;
				check[i + 1] = make_pair(true, rotate);
			}
		}
		else {
			break;
		}

	}



	for (int i = 0; i < 4; i++) {

		if (check[i].first) {
			int direction = check[i].second;
			if (direction)
				tooth[i] = right(tooth[i]);
			else
				tooth[i] = left(tooth[i]);
		}
	}


}


void second(int rotate) {
	vector<pair<bool, bool>> check(4, make_pair(false, false));


	check[1] = make_pair(true, rotate);

	if (tooth[1][6] != tooth[0][2])
		check[0] = make_pair(true, !rotate);


	int start = 2;
	int end = 6;

	for (int i = 1; i <= 2; i++) {

		if (check[i].first) {

			if (tooth[i][start] != tooth[i + 1][end]) {
				rotate = !rotate;
				check[i + 1] = make_pair(true, rotate);
			}
		}
		else {
			break;
		}

	}



	for (int i = 0; i < 4; i++) {

		if (check[i].first) {
			int direction = check[i].second;
			if (direction)
				tooth[i] = right(tooth[i]);
			else
				tooth[i] = left(tooth[i]);
		}
	}


}



void third(int rotate) {
	vector<pair<bool, bool>> check(4, make_pair(false, false));

	int start = 6;
	int end = 2;
	check[2] = make_pair(true, rotate);

	if (tooth[2][2] != tooth[3][6])
		check[3] = make_pair(true, !rotate);

	for (int i = 2; i >= 1; i--) {

		if (check[i].first) {

			if (tooth[i][start] != tooth[i - 1][end]) {
				rotate = !rotate;
				check[i - 1] = make_pair(true, rotate);
			}
		}
		else {
			break;
		}

	}



	for (int i = 0; i < 4; i++) {

		if (check[i].first) {
			int direction = check[i].second;
			if (direction)
				tooth[i] = right(tooth[i]);
			else
				tooth[i] = left(tooth[i]);
		}
	}

}


void fourth(int rotate) {
	vector<pair<bool, bool>> check(4, make_pair(false, false));

	int start = 6;
	int end = 2;
	check[3] = make_pair(true, rotate);

	for (int i = 3; i >= 1; i--) {

		if (check[i].first) {

			if (tooth[i][start] != tooth[i - 1][end]) {
				rotate = !rotate;
				check[i - 1] = make_pair(true, rotate);
			}
		}
		else {
			break;
		}

	}



	for (int i = 0; i < 4; i++) {

		if (check[i].first) {
			int direction = check[i].second;
			if (direction)
				tooth[i] = right(tooth[i]);
			else
				tooth[i] = left(tooth[i]);
		}
	}
}
void sum(void) {

	int total = 0;

	int k = 1;

	for (int i = 0; i < 4; i++) {

		if (tooth[i][0] == '1')
			total = total + k;

		k = k * 2;
	}



	cout << total << "\n";

}


void print(vector<string> arr) {

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}


}




int main(void) {
	int k;

	for (int i = 0; i < 4; i++) {
		cin >> tooth[i];
	}
	scanf("%d", &k);
	vector<pair<int, int>> order(k);
	for (int i = 0; i < k; i++) {
		int first;
		int second;

		scanf("%d", &first);
		scanf("%d", &second);

		if (second == -1)
			second = 0;

		order[i].first = first;
		order[i].second = second;

	}


	for (int i = 0; i < k; i++) {
		int select = select = order[i].first;//톱니바퀴 선택
		int circle = circle = order[i].second;//회전

		switch (select)
		{

		case 1:
			first(circle);
			break;

		case 2:
			second(circle);
			break;
		case 3:
			third(circle);
			break;

		case 4:
			fourth(circle);
			break;

		}

	}
	sum();

}